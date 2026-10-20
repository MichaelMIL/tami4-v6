#!/usr/bin/env python3
"""Tkinter GUI for the PIC18F8621 water-dispenser service console (EUSART2, 8N1, CR-terminated).

Supports both firmware versions:
  T6 3.47V   9600 baud, hashed 2-3 letter commands (GPL, SP, ST, ...).
  T6 3.5.13  38400 baud, lowercase text shell (ver, temp, input, output=n,v, ...); see ../v3.5.13/README.md.

Usage:  python3 serial_gui.py [--port /dev/ttyUSB0] [--fw auto|3.47|3.5.13] [--demo]

  --fw     firmware / protocol. "auto" (default) probes 9600 baud first, then 38400.
  --demo   run against a simulated unit (v3.47: built from write_tests/baseline_*.txt; v3.5.13: values from the
           first read-only shell session). No hardware needed; nothing is sent anywhere.

Safety: anything that writes EEPROM or actuates hardware asks for confirmation first.
  v3.47:   EEPROM SP SMN SMX RP RPL RC RCL g; hardware DCW DHW CP0 CP1 EH1 EH0 NM SM PD RS XC. RPL / RCL need the
           command typed back. STP (stop dispensing) is never blocked. Free-typed console commands are classified by
           the firmware's command *hash*, not by spelling, because any word with the same hash runs the same handler.
  v3.5.13: EEPROM restore_factory_settings set_language set_shipping_mode set_production_mode; hardware output=n,v
           hot cold mix manual_press testing_mode reset ex. restore_factory_settings needs the name typed back.
           The STOP button (output=n,0 for the three valves) is never blocked.
Every exchange is appended to serial_gui_log.txt next to this script.
"""
import argparse, datetime, json, os, queue, re, threading, time
import tkinter as tk
from tkinter import ttk, messagebox, simpledialog, filedialog

try:
    import serial, serial.tools.list_ports
except ImportError:  # demo mode still works
    serial = None

HERE = os.path.dirname(os.path.abspath(__file__))
BASELINE_GPL = os.path.join(HERE, "write_tests", "baseline_GPL.txt")
BASELINE_GCL = os.path.join(HERE, "write_tests", "baseline_GCL.txt")
INFO_PATH = os.path.join(HERE, "parameter_info.json")
ROM_TXT = os.path.join(HERE, "eeprom_parameters.txt")
LOG_PATH = os.path.join(HERE, "serial_gui_log.txt")
MAX_LINE = 11

FW_347, FW_35 = "3.47", "3.5.13"
FIRMWARES = {
    FW_347: dict(baud=9600, max_line=11, title="T6 3.47V", ver="VER"),
    FW_35: dict(baud=38400, max_line=29, title="T6 3.5.13", ver="ver"),
}
FW_CHOICES = {"Auto-detect": None, "v3.47 (9600, hashed commands)": FW_347, "v3.5.13 (38400, text shell)": FW_35}

# ---------------------------------------------------------------- protocol knowledge (v3.47)

FAULTS = {
    0x81: "unknown command", 0x82: "rejected / UV lamp removed", 0x83: "compressor restart delay",
    0x84: "output on too long", 0x85: "bad argument", 0x87: "ADC near full scale",
    0x8A: "hot tank over-temperature", 0x8B: "UV lamp did not light", 0x8D: "sensor open",
    0x8F: "sensor short", 0x90: "UV fault / cold water abnormally warm",
}


READ_CMDS = {"VER", "ST", "GHT", "GCT", "GDT", "COT", "GHS", "GCS", "HTS", "UVS", "IVS", "CVS", "HVS",
             "CWC", "LCL", "GP", "GPL", "GC", "GCL", "GCH", "TC", "AC"}
EEPROM_CMDS = {"SP", "SMN", "SMX", "RP", "RPL", "RC", "RCL", "g"}
HW_CMDS = {"DCW", "DHW", "STP", "CP0", "CP1", "EH1", "EH0", "NM", "SM", "PD", "RS", "XC"}
BULK_CMDS = {"RPL", "RCL"}
UNTESTED = {"SMN", "SMX", "RC", "RPL", "RCL", "XC", "g"}
LONG_CMDS = {"GPL", "GCL", "LCL", "RPL", "RCL"}


def cmd_hash(line):
    """Effective command hash as computed by the firmware (see serial_commands.md)."""
    if line.startswith("g"):
        return 0x67
    word = line.split(" ")[0][:3]
    h = 0
    for i, c in enumerate(word):
        h ^= (ord(c) << i) & 0xFF
    first = word[:1]
    for raw, mapped, keep in ((0xD4, 0xD3, "R"), (0xFB, 0xFA, "S"), (0xF1, 0xF0, "G"),
                              (0xA9, 0xA7, "S"), (0xE1, 0xE0, "G"), (0x8D, 0x8C, "G")):
        if h == raw and first != keep:
            h = mapped
    return h


HASH_TO_CMD = {}
for _c in sorted(READ_CMDS | EEPROM_CMDS | HW_CMDS):
    HASH_TO_CMD.setdefault(cmd_hash(_c), _c)


def classify(line):
    """Return (effective command name or None, category) for a console line."""
    name = HASH_TO_CMD.get(cmd_hash(line))
    if name is None:
        return None, "unknown"
    if name in EEPROM_CMDS:
        return name, "eeprom"
    if name in HW_CMDS:
        return name, "hardware"
    return name, "read"


def u8(v):
    return v & 0xFF if v < 0 else v


def fault_text(v):
    b = u8(v)
    if b == 0:
        return "OK"
    return f"0x{b:02X} {FAULTS.get(b, 'fault')}"


def parse_gpl(lines):
    rows = []
    for l in lines:
        p = l.split(",")
        if len(p) == 6 and p[0].strip().isdigit():
            i, name, mn, mx, val, d = p
            rows.append(dict(i=int(i), name=name, min=u8(int(mn)), max=u8(int(mx)),
                             value=u8(int(val)), default=u8(int(d))))
    return rows


def parse_gcl(lines):
    rows = []
    for l in lines:
        p = l.split(",")
        if len(p) == 3 and p[0].strip().isdigit():
            rows.append(dict(i=int(p[0]), name=p[1], value=int(p[2])))
    return rows


def read_lines(path):
    try:
        with open(path) as f:
            return [l.strip() for l in f if l.strip()]
    except OSError:
        return []


def load_info():
    """Parameter / counter explanations (parameter_info.json, the master copy)."""
    try:
        with open(INFO_PATH, encoding="utf-8") as f:
            return json.load(f)
    except (OSError, ValueError):
        return {"units": {}, "params": {}, "counters": {}}


def fmt_duration(sec):
    if sec < 1:
        return f"{sec * 1000:.0f} ms"
    if sec < 60:
        return f"{sec:g} s"
    if sec < 3600:
        m, s = divmod(round(sec), 60)
        return f"{m} min" + (f" {s} s" if s else "")
    if sec < 86400:
        h, m = divmod(round(sec / 60), 60)
        return f"{h} h" + (f" {m} min" if m else "")
    return f"{sec / 86400:.1f} days"


DURATION_SCALE = {"10ms": 0.01, "100ms": 0.1, "s": 1, "10s": 10, "min": 60, "10min": 600}


def fmt_value(unit, v):
    """Raw value -> human-readable value for a parameter_info.json unit."""
    if unit in DURATION_SCALE:
        return fmt_duration(v * DURATION_SCALE[unit])
    return {
        "C": f"{v} °C", "dC": f"{v} °C", "h": f"{v} h", "ml10": f"{v * 10} ml",
        "ml100": f"{v * 100 / 1000:g} L", "flow": f"{v / 10:g} L/min", "flag": "on" if v else "off",
        "bits": f"0x{v:02X}", "hour": f"{v:02d} h", "minute": f"{v:02d} min", "days": f"{v} days",
    }.get(unit, str(v))


def decode_bits(bits, v):
    """['0x38', 'Language...'] pairs -> one line per field with its current value."""
    out = []
    for mask, label in bits:
        m = int(mask, 16)
        field = (v & m) >> ((m & -m).bit_length() - 1)
        state = ("on" if field else "off") if m & (m - 1) == 0 else str(field)
        out.append(f"  {mask}  {state:>3}  {label}")
    return "\n".join(out)


def rom_table(info, fw):
    """ROM parameter table (index, name, default, min, max) for a firmware version.

    v3.47 comes from eeprom_parameters.txt (ROM columns), falling back to the baseline GPL; later versions apply
    parameter_info.json's 'versions' changes on top."""
    rows = {p["i"]: dict(i=p["i"], name=p["name"], default=p["default"], min=p["min"], max=p["max"])
            for p in parse_gpl(read_lines(BASELINE_GPL))}
    for l in read_lines(ROM_TXT):
        m = re.match(r"0x([0-9a-f]+)\s+(\w+)\s+\d+\s+\d+\s+\d+\s+\|\s+(\d+)\s+(\d+)\s+(\d+)", l)
        if m:
            i = int(m[1], 16) - 1
            rows[i] = dict(i=i, name=m[2], default=int(m[3]), min=int(m[4]), max=int(m[5]))
    ver = info.get("versions", {}).get(fw)
    if ver:
        byname = {r["name"]: r for r in rows.values()}
        for name, (i, d, mn, mx) in ver.get("rom", {}).items():
            r = byname.get(name) or rows.setdefault(i, dict(i=i, name=name))
            r.update(default=d, min=mn, max=mx)
    return [rows[i] for i in sorted(rows)]

# ---------------------------------------------------------------- protocol knowledge (v3.5.13 text shell)

# Command table at ROM 0xFE1C, in table order. (category, accepted argument counts or None = not checked, help).
# Argument checks come from the shell task (0x79B0); a wrong count / out-of-range value gives ERROR -127.
SHELL_CMDS = {
    "ls": ("read", None, "List all commands"),
    "temp": ("read", None, "Temperatures HT, HB, CB in °C (-1 = open sensor)"),
    "input": ("read", None, "Raw A2D, buttons, inputs UV_POS / UV_READY / HEATER_FEEDBACK, output states"),
    "output": ("read", None, "List outputs; output=n,v switches output n on (1) / off (0)"),
    "hot": ("hardware", (1, 2), "Dispense hot water (argument required; its meaning is not decoded)"),
    "cold": ("hardware", (1, 2), "Dispense cold water (argument required; its meaning is not decoded)"),
    "mix": ("hardware", (1, 2), "Dispense mixed water (argument required; its meaning is not decoded)"),
    "ex": ("hardware", None, "Calls two unidentified routines (0xA322, 0xABFC); effect unknown"),
    "ver": ("read", None, "Firmware version and build date"),
    "get_hwt_type": ("read", None, "Hot tank type: Plastic / Stainless"),
    "get_errors_bitmap": ("read", None, "Active error numbers (bits 1-27 of a 32-bit error word)"),
    "get_wu": ("read", None, "Water usage counter"),
    "restore_factory_settings": ("eeprom", None, "Reset all settings to factory defaults"),
    "set_language": ("eeprom", (1,), "Set the display language n = 0-7 (SYSTEMCONFIG2 bits 0x38)"),
    "set_shipping_mode": ("eeprom", (1,), "Shipping mode on/off (SYSTEMCONFIG4 bit 0), then resets the controller"),
    "set_production_mode": ("eeprom", (1,), "Production mode on/off (SYSTEMCONFIG3 bit 0x02), then resets the controller"),
    "manual_press": ("hardware", (2,), "Simulate key k (0-6) held for t (> 0, unit not decoded)"),
    "testing_mode": ("hardware", (1,), "Enter (1) / leave (0) testing mode"),
    "reset": ("hardware", None, "Print OK, then reset the controller"),
    # Added by the parameter-edit patch (../v3.5.13/PARAM_SHELL_PATCH.md). Not present in stock v3.5.13.
    "par": ("eeprom", (1, 2), "Read parameter i (par=i) / write parameter i to v with min<=v<=max (par=i,v)"),
}
# Commands added by patches, absent from a stock unit (used only to warn in the editor tab).
SHELL_PATCHED = {"par"}
SHELL_BULK = {"restore_factory_settings"}
SHELL_RESETS = {"set_shipping_mode", "set_production_mode", "reset"}
SHELL_ERRORS = {-123: "unknown command", -127: "wrong number of arguments or value out of range"}
SHELL_OUTPUTS = ["UV_DRIVE", "FAN", "COMPRESSOR", "HEATER", "COLD_VALVE", "HOT_VALVE", "INLET_VALVE", "LCDBKLT"]
SHELL_VALVES = (5, 4, 6)  # hot, cold, inlet: closed by the STOP button
LANGUAGES = {0: "English", 4: "Russian", 5: "Hebrew"}  # other numbers 1-7 not decoded
END_RE = re.compile(r"\n(?:OK|ERROR -?\d+)[ \t]*\n")
ERR_RE = re.compile(r"^ERROR (-?\d+)")


def split_shell(line):
    """'cmd=a,b' -> ('cmd', argument count), as the shell splits at '=' and then ','."""
    word, eq, rest = line.partition("=")
    return word, (2 if "," in rest else 1) if eq else 0


def classify_shell(line):
    word, nargs = split_shell(line)
    if word not in SHELL_CMDS:
        return None, "unknown"
    cat = SHELL_CMDS[word][0]
    if word == "output":
        cat = "hardware" if nargs == 2 else "read"
    elif word == "par":
        cat = "eeprom" if nargs == 2 else "read"  # par=i reads, par=i,v writes EEPROM
    return word, cat


def shell_arg_problem(line):
    word, nargs = split_shell(line)
    need = SHELL_CMDS.get(word, (None, None))[1]
    if need and nargs not in need:
        return f"{word} takes {' or '.join(map(str, need))} argument(s); the shell would answer ERROR -127"
    return ""


def parse_kv(lines):
    """'HT= -1, HB= -1' -> {'HT': -1, 'HB': -1}"""
    return {k: int(v) for l in lines for k, v in re.findall(r"(\w+)=\s*(-?\d+)", l)}


def parse_outputs(lines):
    """'Outputs: 0,   UV_DRIVE,0' / ' 1,        FAN,0' -> {0: ('UV_DRIVE', 0), ...}"""
    out = {}
    for l in lines:
        m = re.match(r"^(?:Outputs:)?\s*(\d+),\s*(\w+),\s*(\d+)\s*$", l)
        if m:
            out[int(m[1])] = (m[2], int(m[3]))
    return out

# ---------------------------------------------------------------- simulated unit (--demo)


class FakeSerial:
    """Answers like the real console, using the baseline dumps as initial state."""

    def __init__(self):
        self.params = parse_gpl(read_lines(BASELINE_GPL)) or [
            dict(i=i, name=f"P{i}", min=0, max=255, value=0, default=0) for i in range(75)]
        self.counters = parse_gcl(read_lines(BASELINE_GCL)) or [
            dict(i=i, name=f"C{i}", value=0) for i in range(18)]
        self.child = False
        self.out = b""

    def s8(self, v):
        return v - 256 if v > 127 else v

    def reply(self, line):
        name, _ = classify(line)
        arg = line[3:].strip() if len(line) > 3 else ""
        if line.startswith("g"):
            arg = line[1:]
        try:
            nums = [int(x) for x in arg.replace(" ", ",").split(",") if x.strip()] if arg else []
        except ValueError:
            nums = []
        out = []
        if name == "VER":
            out = ["T6", "3.47V"]
        elif name == "ST":
            out = ["HEATER -115", "COMPRESSOR -115", "UVLAMP -117", "INLET VALVE 0", "HOT WATER VALVE 0",
                   "COLD WATER VALVE 0", "HOT SENSORS -115", "COLD SENSORS -115"]
        elif name in ("GHT", "GCT"):
            out = ["-1", "-1"]
        elif name in ("GDT", "COT"):
            out = ["-1"]
        elif name == "GHS":
            out = ["Heating System - Normal"]
        elif name == "GCS":
            out = ["Cooling System - Delay"]
        elif name == "HTS":
            out = ["Heater OFF"]
        elif name == "UVS":
            out = ["UV lamp - OFF"]
        elif name == "IVS":
            out = ["Inlet valve - OFF"]
        elif name == "CVS":
            out = ["CW valve - OFF"]
        elif name == "HVS":
            out = ["HW valve - OFF"]
        elif name == "CWC":
            out = ["Child Protection Mode - " + ("Active" if self.child else "Not-Active")]
        elif name == "LCL":
            cmds = "PD RS NM SM ST GHT GCT DCW DHW STP CP0 CP1 EH1 EH0 TC AC GCS GHS CWC HTS UVS IVS CVS HVS GCH GDT COT g".split()
            out = [str(len(cmds))] + [f"{i},{c}" for i, c in enumerate(cmds)]
        elif name == "GPL":
            out = [str(len(self.params))] + [
                f"{p['i']},{p['name']},{self.s8(p['min'])},{self.s8(p['max'])},{self.s8(p['value'])},{self.s8(p['default'])}"
                for p in self.params]
        elif name == "GCL":
            out = [str(len(self.counters))] + [f"{c['i']},{c['name']},{c['value']}" for c in self.counters]
        elif name in ("GP", "SP", "RP", "SMN", "SMX") and nums and 0 <= nums[0] < len(self.params):
            p = self.params[nums[0]]
            if name == "GP":
                out = [str(p["value"])]
            elif name == "RP":
                p["value"] = p["default"]
            elif len(nums) < 2:
                return "\x85\r\n"
            elif name == "SP":
                if not p["min"] <= nums[1] <= p["max"]:
                    return "\x85\r\n"
                p["value"] = nums[1]
            else:
                p["min" if name == "SMN" else "max"] = nums[1] & 0xFF
        elif name in ("GC", "RC") and nums and 0 <= nums[0] < len(self.counters):
            if name == "GC":
                out = [str(self.counters[nums[0]]["value"])]
            else:
                self.counters[nums[0]]["value"] = 0
        elif name == "g" and len(line) >= 3 and line[1:3].isdigit() and int(line[1:3]) < len(self.counters):
            try:
                self.counters[int(line[1:3])]["value"] = int(line[3:].strip())
            except ValueError:
                return "\x85\r\n"
        elif name == "RPL":
            for p in self.params:
                p["value"] = p["default"]
        elif name == "RCL":
            for c in self.counters:
                c["value"] = 0
        elif name in ("CP0", "CP1"):
            self.child = name == "CP1"
        elif name in ("GCH", "TC", "AC"):
            return "\x82\r\n"
        elif name in HW_CMDS:
            pass
        elif name is None:
            return "\x81\r\n"
        else:
            return "\x85\r\n"
        return "".join(l + "\r\n" for l in out + ["OK"])

    # serial.Serial-like interface
    def write(self, data):
        line = data.decode("latin1").rstrip("\r")
        self.out += (line + "\r\r\n" + self.reply(line)).encode("latin1")

    def read(self, n):
        time.sleep(0.02)
        chunk, self.out = self.out[:n], self.out[n:]
        return chunk

    def reset_input_buffer(self):
        self.out = b""

    def close(self):
        pass


class FakeShell(FakeSerial):
    """Answers like the v3.5.13 text shell, starting from the values of the first read-only session."""

    def __init__(self):
        self.outputs = [0] * 8
        self.testing = False
        self.out = b""
        # Parameter store for the `par` patch: start from the ROM defaults/limits (0..76).
        self.pvals = {r["i"]: dict(value=r["default"], min=r["min"], max=r["max"])
                      for r in rom_table(load_info(), FW_35)}

    def reply(self, line):
        word, nargs = split_shell(line)
        rest = line.partition("=")[2]
        nums = []
        for x in rest.split(",")[:2] if nargs else []:
            m = re.match(r"\s*(-?\d+)", x)
            nums.append(int(m[1]) if m else 0)  # atoi
        if word not in SHELL_CMDS:
            return "ERROR -123\r\n"
        if shell_arg_problem(line):
            return "ERROR -127\r\n"
        outs = ["Outputs: " + "\r\n".join(f"{i:2d},{n:>11},{v}" for i, (n, v) in
                                          enumerate(zip(SHELL_OUTPUTS, self.outputs))).lstrip()]
        out = []
        if word == "ls":
            out = [str(len(SHELL_CMDS))] + [f"{i:2d},{c:>25}" for i, c in enumerate(SHELL_CMDS)]
        elif word == "temp":
            out = ["HT= -1, HB= -1, CB= -1"]
        elif word == "input":
            out = ["A2D: HT=1023, HB=1023, CT=1023, CB=1023", "Buttons:  110",
                   "Inputs: UV_POS=0, UV_READY=0, HEATER_FEEDBACK=1"] + outs
        elif word == "output" and nargs == 2:
            if not 0 <= nums[0] < 8:
                return "ERROR -127\r\n"
            self.outputs[nums[0]] = nums[1] & 1
        elif word == "output":
            out = outs
        elif word == "ver":
            out = ["T6", "3.5.13 Feb 07 2019 17:37:44"]
        elif word == "get_hwt_type":
            out = ["Hot Tank Plastic  "]
        elif word == "get_errors_bitmap":
            out = [" 6,21,"]
        elif word == "get_wu":
            out = ["Water Usage        10667"]
        elif word == "set_language" and not 0 <= nums[0] <= 7:
            return "ERROR -127\r\n"
        elif word == "manual_press" and not (0 <= nums[0] <= 6 and nums[1] > 0):
            return "ERROR -127\r\n"
        elif word == "testing_mode":
            self.testing = bool(nums[0])
        elif word == "par":
            i = nums[0]
            if i not in self.pvals:
                return "ERROR -127\r\n"
            p = self.pvals[i]
            if nargs == 2:
                v = nums[1]
                if not (0 <= v <= 255 and p["min"] <= v <= p["max"]):
                    return "ERROR -127\r\n"
                p["value"] = v
            else:
                out = [str(p["value"])]
        return "".join(l + "\r\n" for l in out + ["OK"])

    def write(self, data):
        line = data.decode("latin1").rstrip("\r")
        self.out += (line + "\r\n" + (self.reply(line) if line else "")).encode("latin1")

# ---------------------------------------------------------------- serial worker


class Link:
    """Owns the port; runs one command at a time on a background thread."""

    def __init__(self, on_result):
        self.port = None
        self.fw = FW_347
        self.lock = threading.Lock()
        self.jobs = queue.PriorityQueue()  # (priority, seq, line, callback); STOP jumps the queue
        self.seq = 0
        self.on_result = on_result
        self.log = open(LOG_PATH, "a")
        threading.Thread(target=self._run, daemon=True).start()

    def open(self, port, demo=False, fw=FW_347):
        self.close()
        baud = FIRMWARES[fw]["baud"]
        if demo:
            self.port = FakeShell() if fw == FW_35 else FakeSerial()
        else:
            self.port = serial.Serial(port, baud, bytesize=8, parity="N", stopbits=1, timeout=0.15)
        self.fw = fw
        self.log.write(f"\n[{datetime.datetime.now():%Y-%m-%d %H:%M:%S}] --- opened {'DEMO' if demo else port} "
                       f"{baud} baud (firmware {fw})\n")
        self.log.flush()
        if fw == FW_35:  # a bare CR clears any noise in the shell's line buffer
            self.port.write(b"\r")
            time.sleep(0.3)
            self.port.reset_input_buffer()

    def detect(self, port, demo=False):
        """Find the firmware: probe 9600 (v3.47 'VER') first, then 38400 (v3.5.13 'ver').

        This order is deliberate. At 9600 a v3.5.13 shell only receives garbage, which can never equal a command
        name (exact strcmp). Probing a v3.47 unit at 38400 instead could leave garbage in its line buffer that the
        next CR would run through the command *hash*, which can match a real (even destructive) command.
        Returns (fw, version lines) or (None, [])."""
        with self.lock:
            for fw in (FW_347, FW_35):
                self.open(port, demo, fw)
                status, body, _ = self._exchange(FIRMWARES[fw]["ver"])
                if status == "OK" and any("T6" in b for b in body):
                    return fw, body
            self.close()
        return None, []

    def close(self):
        if self.port:
            try:
                self.port.close()
            except Exception:
                pass
        self.port = None

    def send(self, line, callback=None, urgent=False):
        self.seq += 1
        self.jobs.put((0 if urgent else 1, self.seq, line, callback))

    def pending(self):
        return self.jobs.qsize()

    def _exchange(self, line):
        p = self.port
        p.reset_input_buffer()
        p.write((line + "\r").encode("latin1"))
        out, quiet, done = b"", 0, False
        deadline = time.time() + (8 if line in LONG_CMDS else 2.5)
        while time.time() < deadline:
            chunk = p.read(512)
            if chunk:
                out += chunk
                quiet = 0
                # reply ends with an OK line (both versions) or, on v3.5.13, an "ERROR -nnn" line
                done = bool(END_RE.search("\n" + out.decode("latin1").replace("\r\n", "\n").replace("\r", "\n")))
            else:
                quiet += 1
                if (done and quiet >= 1) or quiet >= 6:
                    break
        # v3.47 ends lines with \r\r\n / \r\n; accept bare \r or \n too
        text = out.decode("latin1").replace("\r\n", "\n").replace("\r", "\n")
        self.log.write(f"[{datetime.datetime.now():%H:%M:%S}] >>> {line}\n{text}\n")
        self.log.flush()
        lines = [l for l in text.split("\n") if l.strip(" \t")]  # not strip(): it eats the 0x85 fault byte
        self.echo_bad = bool(lines) and lines[0].strip() != line.strip()
        if lines and not self.echo_bad:
            lines = lines[1:]
        status = "OK" if lines and lines[-1].strip() == "OK" else "ERR"
        body = lines[:-1] if status == "OK" else lines
        if status == "ERR" and not body:
            body = ["(no reply)"]
        body = [describe_raw(l) for l in body]
        for k, l in enumerate(body):
            m = ERR_RE.match(l.strip())
            if m and int(m[1]) in SHELL_ERRORS:
                body[k] = f"{l.strip()}  ({SHELL_ERRORS[int(m[1])]})"
        if status == "ERR" and self.echo_bad and self.fw == FW_35:
            body[0] = f"(echo was '{lines[0].strip()}' — characters were lost on the line)"
        return status, body, text

    def _run(self):
        while True:
            _, _, line, cb = self.jobs.get()
            with self.lock:
                if not self.port:
                    res = ("ERR", ["not connected"], "")
                else:
                    try:
                        res = self._exchange(line)
                        # v3.5.13 at 38400 sometimes drops a character ("ge_wu"); resend reads once
                        if (res[0] == "ERR" and self.echo_bad and self.fw == FW_35
                                and classify_shell(line)[1] == "read"):
                            res = self._exchange(line)
                    except Exception as e:
                        res = ("ERR", [f"serial error: {e}"], "")
            self.on_result(line, res, cb)


def describe_raw(l):
    """Show non-printable fault bytes (0x81/0x82/0x85...) readably."""
    if any(ord(c) >= 0x80 or ord(c) < 0x20 for c in l):
        parts = []
        for c in l:
            b = ord(c)
            parts.append(f"<0x{b:02X} {FAULTS.get(b, '?')}>" if b >= 0x80 or b < 0x20 else c)
        return "".join(parts)
    return l

# ---------------------------------------------------------------- GUI


class App(tk.Tk):
    STATUS_ROWS = [("VER", "Firmware"), ("GHT", "Hot tank temp"), ("GCT", "Cold tank temp"),
                   ("GDT", "Device temp (AN6)"), ("COT", "Dryer/condenser temp (AN7)"),
                   ("GHS", "Heating system"), ("GCS", "Cooling system"), ("HTS", "Heater"),
                   ("UVS", "UV lamp"), ("IVS", "Inlet valve"), ("CVS", "Cold valve"),
                   ("HVS", "Hot valve"), ("CWC", "Child protection")]

    STATUS35_ROWS = [("ver", "Firmware", "ver"), ("hwt", "Hot tank type", "get_hwt_type"),
                     ("HT", "Hot tank top (HT)", "temp"), ("HB", "Hot tank bottom (HB)", "temp"),
                     ("CB", "Cold tank bottom (CB)", "temp"), ("A2D", "Raw A2D (1023 = open)", "input"),
                     ("Buttons", "Buttons", "input"), ("UV_POS", "UV lamp present (UV_POS, RJ0)", "input"),
                     ("UV_READY", "UV lamp lit (UV_READY, RJ1)", "input"),
                     ("HEATER_FEEDBACK", "Heater feedback", "input"),
                     ("errors", "Active errors", "get_errors_bitmap"), ("wu", "Water usage", "get_wu")]

    def __init__(self, args):
        super().__init__()
        self.fw = FW_347
        self.tabs = []  # (frame, title, firmware versions it belongs to)
        self.title("PIC18F8621 Service Console")
        self.geometry("1050x720")
        self.minsize(820, 560)
        self.results = queue.Queue()
        self.link = Link(lambda line, res, cb: self.results.put((line, res, cb)))
        self.params, self.counters = [], []
        self.baseline_p = {p["i"]: p for p in parse_gpl(read_lines(BASELINE_GPL))}
        self.baseline_c = {c["i"]: c for c in parse_gcl(read_lines(BASELINE_GCL))}
        self.info = load_info()
        self.auto_job = None

        style = ttk.Style(self)
        if "clam" in style.theme_names():
            style.theme_use("clam")
        style.configure("Danger.TButton", foreground="#b00020")
        style.configure("Stop.TButton", foreground="white", background="#c62828", font=("TkDefaultFont", 12, "bold"))
        style.map("Stop.TButton", background=[("active", "#e53935")])

        self._build_topbar(args)
        self.nb = nb = ttk.Notebook(self)
        nb.pack(fill="both", expand=True, padx=6, pady=(0, 6))
        self._build_status(nb)
        self._build_status35(nb)
        self._build_params(nb)
        self._build_counters(nb)
        self._build_controls(nb)
        self._build_controls35(nb)
        self._build_setup35(nb)
        self._build_params_edit(nb)
        self._build_params_ref(nb)
        self._build_console(nb)

        self.statusbar = ttk.Label(self, text="Not connected", anchor="w", relief="sunken")
        self.statusbar.pack(fill="x", side="bottom")
        self.apply_fw(FW_CHOICES[self.fw_var.get()] or FW_35)
        self.after(50, self._poll_results)
        self.protocol("WM_DELETE_WINDOW", self._quit)
        if args.demo:
            self.demo_var.set(True)
            self.connect()

    # ---------- top bar
    def _build_topbar(self, args):
        bar = ttk.Frame(self, padding=6)
        bar.pack(fill="x")
        ttk.Label(bar, text="Port:").pack(side="left")
        self.port_var = tk.StringVar(value=args.port)
        self.port_box = ttk.Combobox(bar, textvariable=self.port_var, width=18)
        self.port_box.pack(side="left", padx=4)
        ttk.Button(bar, text="↻", width=3, command=self.refresh_ports).pack(side="left")
        ttk.Label(bar, text="Firmware:").pack(side="left", padx=(10, 2))
        inv = {v: k for k, v in FW_CHOICES.items()}
        self.fw_var = tk.StringVar(value=inv.get(None if args.fw == "auto" else args.fw, "Auto-detect"))
        fw_box = ttk.Combobox(bar, textvariable=self.fw_var, values=list(FW_CHOICES), state="readonly", width=27)
        fw_box.pack(side="left")
        fw_box.bind("<<ComboboxSelected>>", self._fw_selected)
        self.demo_var = tk.BooleanVar(value=False)
        ttk.Checkbutton(bar, text="Demo", variable=self.demo_var).pack(side="left", padx=8)
        self.conn_btn = ttk.Button(bar, text="Connect", command=self.toggle_connect)
        self.conn_btn.pack(side="left", padx=4)
        self.stop_btn = ttk.Button(bar, text="STOP", style="Stop.TButton", command=self.stop)
        self.stop_btn.pack(side="right")
        self.refresh_ports()

    def _fw_selected(self, _e=None):
        fw = FW_CHOICES[self.fw_var.get()]
        if fw and not self.link.port:
            self.apply_fw(fw)

    def _tab(self, frame, text, fws):
        self.tabs.append((frame, text, fws))

    def apply_fw(self, fw):
        """Show the tabs that belong to this firmware's protocol."""
        self.fw = fw
        for t in self.nb.tabs():
            self.nb.forget(t)
        for frame, text, fws in self.tabs:
            if fw in fws:
                self.nb.add(frame, text=text)
        self.title(f"PIC18F8621 Service Console — {FIRMWARES[fw]['title']}")
        self.stop_btn.config(text="STOP dispensing (STP)" if fw == FW_347 else "STOP: close valves")
        self._cmd_preview()

    def stop(self):
        """Never blocked, and sent ahead of anything queued."""
        if self.fw == FW_35:  # v3.5.13 has no stop command: switch the valves off directly
            for n in SHELL_VALVES:
                self.send(f"output={n},0", urgent=True)
        else:
            self.send("STP", urgent=True)

    def refresh_ports(self):
        # USB adapters only (skips the 32 built-in /dev/ttyS*); fall back to everything if none are present
        found = serial.tools.list_ports.comports() if serial else []
        ports = sorted(p.device for p in found if p.vid) or sorted(p.device for p in found)
        self.port_box["values"] = ports
        if ports and self.port_var.get() not in ports:
            self.port_var.set(ports[0])

    def toggle_connect(self):
        if self.link.port:
            self.link.close()
            self.conn_btn.config(text="Connect")
            self.set_status("Disconnected")
        else:
            self.connect()

    def connect(self):
        demo = self.demo_var.get()
        if not demo and serial is None:
            messagebox.showerror("pyserial missing", "Install pyserial: pip install pyserial")
            return
        choice, port = FW_CHOICES[self.fw_var.get()], self.port_var.get()
        try:
            if demo:
                fw = choice or FW_35  # auto in demo mode: simulate the unit's current firmware
                self.link.open(port, True, fw)
            else:
                # always probe (safe order, see Link.detect); the selection is only a fallback if nothing answers
                self.set_status(f"Detecting firmware on {port} (VER at 9600, then ver at 38400)…")
                self.update_idletasks()
                fw, ver = self.link.detect(port)
                if fw is None and choice is None:
                    messagebox.showerror("No reply", f"Nothing on {port} answered VER at 9600 or ver at 38400.\n\n"
                                         "Check wiring and power, or select the firmware explicitly.")
                    self.set_status("Not connected")
                    return
                if fw is None:
                    fw = choice
                    self.link.open(port, False, fw)
                    messagebox.showwarning("No reply", f"No version reply; opened anyway as v{fw} "
                                                       f"({FIRMWARES[fw]['baud']} baud).")
                elif choice and fw != choice:
                    messagebox.showinfo("Firmware", f"The unit answered as {' '.join(ver)} (v{fw}), "
                                                    f"not v{choice}; using v{fw}.")
        except Exception as e:
            messagebox.showerror("Connect failed", str(e))
            return
        self.apply_fw(fw)
        self.conn_btn.config(text="Disconnect")
        self.set_status(f"Connected to {'DEMO unit' if demo else port} — {FIRMWARES[fw]['baud']} 8N1, "
                        f"firmware {FIRMWARES[fw]['title']}")
        self.refresh_status()

    def set_status(self, text):
        self.statusbar.config(text=text)

    # ---------- sending
    def send(self, line, cb=None, urgent=False):
        if not self.link.port:
            self.set_status("Not connected")
            return
        max_line = FIRMWARES[self.fw]["max_line"]
        if len(line) > max_line:
            messagebox.showerror("Line too long", f"'{line}' is {len(line)} chars; the console accepts {max_line}.")
            return
        self.link.send(line, cb, urgent)
        self.set_status(f"Sent {line}  ({self.link.pending()} queued)")

    def confirm(self, line, why=""):
        """Ask before EEPROM writes / hardware actions. Returns True if allowed."""
        if self.fw == FW_35:
            return self.confirm_shell(line, why)
        name, cat = classify(line)
        if cat == "read" or name == "STP":
            return True
        if name in BULK_CMDS:
            msg = (f"{line} is a BULK-DESTRUCTIVE EEPROM command"
                   f"{' (reconstructed, never tested on the unit)' if name in UNTESTED else ''}.\n{why}\n\n"
                   f"Type {name} to confirm:")
            return simpledialog.askstring("Confirm bulk command", msg, parent=self) == name
        if cat == "unknown":
            text = (f"'{line}' does not hash to any known command (hash 0x{cmd_hash(line):02X}).\n"
                    "The firmware will most likely reply 0x81. Send anyway?")
        else:
            kind = "writes EEPROM" if cat == "eeprom" else "actuates hardware"
            alias = f" (hashes to {name})" if not line.startswith(name) else ""
            text = f"'{line}'{alias} {kind}."
            if name in UNTESTED:
                text += "\nThis command is reconstructed and has NOT been verified on the unit."
            if why:
                text += "\n\n" + why
            text += "\n\nSend it?"
        return messagebox.askyesno("Confirm", text, icon="warning", parent=self)

    def confirm_shell(self, line, why=""):
        """v3.5.13: names are compared exactly, so unknown words and wrong argument counts run nothing
        (ERROR -123 / -127) and need no confirmation."""
        name, cat = classify_shell(line)
        if cat in ("read", "unknown") or shell_arg_problem(line):
            return True
        if name in SHELL_BULK:
            msg = (f"{line} resets ALL settings to factory defaults (EEPROM). Never tested on the unit.\n{why}\n\n"
                   f"Type {name} to confirm:")
            return simpledialog.askstring("Confirm bulk command", msg, parent=self) == name
        kind = "writes EEPROM" if cat == "eeprom" else "actuates hardware / changes the operating mode"
        text = f"'{line}' {kind}.\n{SHELL_CMDS[name][2]}."
        if name in SHELL_RESETS:
            text += "\nThe controller resets afterwards."
        text += "\nNot yet tested on the unit (only the read commands have been)."
        if why:
            text += "\n\n" + why
        return messagebox.askyesno("Confirm", text + "\n\nSend it?", icon="warning", parent=self)

    def guarded(self, line, cb=None, why=""):
        if self.confirm(line, why):
            self.send(line, cb)

    def _poll_results(self):
        try:
            while True:
                line, (status, body, raw), cb = self.results.get_nowait()
                self.console_append(line, status, body)
                self.set_status(f"{line}: {status}" + (f"  ({self.link.pending()} queued)" if self.link.pending() else ""))
                if cb:
                    cb(status, body)
        except queue.Empty:
            pass
        self.after(50, self._poll_results)

    # ---------- Status tab
    def _build_status(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Status", (FW_347,))
        top = ttk.Frame(f)
        top.pack(fill="x")
        ttk.Button(top, text="Refresh all", command=self.refresh_status).pack(side="left")
        self.auto_var = tk.BooleanVar(value=False)
        ttk.Checkbutton(top, text="Auto-refresh every", variable=self.auto_var,
                        command=self._auto_toggle).pack(side="left", padx=(12, 2))
        self.auto_sec = tk.IntVar(value=10)
        ttk.Spinbox(top, from_=5, to=300, width=5, textvariable=self.auto_sec).pack(side="left")
        ttk.Label(top, text="s").pack(side="left")

        body = ttk.Frame(f)
        body.pack(fill="both", expand=True, pady=8)
        left = ttk.LabelFrame(body, text="Readings", padding=8)
        left.pack(side="left", fill="both", expand=True, padx=(0, 4))
        self.status_vals = {}
        for r, (cmd, label) in enumerate(self.STATUS_ROWS):
            ttk.Label(left, text=label).grid(row=r, column=0, sticky="w", pady=2)
            ttk.Label(left, text=cmd, foreground="#777").grid(row=r, column=1, sticky="w", padx=6)
            v = ttk.Label(left, text="—", font=("TkDefaultFont", 10, "bold"))
            v.grid(row=r, column=2, sticky="w")
            self.status_vals[cmd] = v
            ttk.Button(left, text="↻", width=3,
                       command=lambda c=cmd: self.send(c, lambda s, b, c=c: self._show_reading(c, s, b))
                       ).grid(row=r, column=3, padx=4)
        left.columnconfigure(2, weight=1)

        right = ttk.LabelFrame(body, text="Component faults (ST)", padding=8)
        right.pack(side="left", fill="both", expand=True, padx=(4, 0))
        self.st_tree = ttk.Treeview(right, columns=("comp", "raw", "meaning"), show="headings", height=10)
        for c, w, t in (("comp", 170, "Component"), ("raw", 60, "Raw"), ("meaning", 260, "Meaning")):
            self.st_tree.heading(c, text=t)
            self.st_tree.column(c, width=w, anchor="w")
        self.st_tree.tag_configure("fault", foreground="#b00020")
        self.st_tree.pack(fill="both", expand=True)
        ttk.Label(right, text="Bench note: with no NTC sensors / UV lamp attached, 0x8D and 0x8B are expected.",
                  foreground="#777", wraplength=420).pack(anchor="w", pady=(6, 0))

    def refresh_status(self):
        if self.fw == FW_35:
            self.refresh_status35()
            return
        self.send("ST", self._show_st)
        for cmd, _ in self.STATUS_ROWS:
            self.send(cmd, lambda s, b, c=cmd: self._show_reading(c, s, b))

    def _show_reading(self, cmd, status, body):
        if status != "OK":
            text = "error: " + " ".join(body)
        elif cmd in ("GHT", "GCT", "GDT", "COT"):
            text = " / ".join(("open sensor (-1)" if b.strip() == "-1" else f"{b} °C") for b in body)
        else:
            text = " ".join(body)
        self.status_vals[cmd].config(text=text, foreground="#b00020" if status != "OK" else "")

    def _show_st(self, status, body):
        self.st_tree.delete(*self.st_tree.get_children())
        for l in body:
            name, _, val = l.rpartition(" ")
            try:
                v = int(val)
                self.st_tree.insert("", "end", values=(name, v, fault_text(v)), tags=("fault",) if v else ())
            except ValueError:
                self.st_tree.insert("", "end", values=(l, "", ""))

    def _auto_toggle(self):
        if self.auto_job:
            self.after_cancel(self.auto_job)
            self.auto_job = None
        if self.auto_var.get():
            def tick():
                if self.link.port and self.link.pending() == 0:
                    self.refresh_status()
                self.auto_job = self.after(max(5, self.auto_sec.get()) * 1000, tick)
            tick()

    # ---------- Parameters tab
    def _build_params(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Parameters", (FW_347,))
        top = ttk.Frame(f)
        top.pack(fill="x")
        ttk.Button(top, text="Read all (GPL)", command=self.read_params).pack(side="left")
        ttk.Button(top, text="Export CSV…", command=lambda: self.export_csv(self.params, "params")).pack(side="left", padx=4)
        ttk.Button(top, text="Restore values from baseline…", command=self.restore_params_baseline).pack(side="left", padx=4)
        ttk.Button(top, text="Reset ALL to defaults (RPL)", style="Danger.TButton",
                   command=lambda: self.guarded("RPL", lambda s, b: self.read_params(),
                                                "Restores all 75 parameters to ROM defaults. "
                                                "Use 'Restore values from baseline' afterwards to undo.")
                   ).pack(side="right")
        ttk.Label(f, text="Highlighted: differs from ROM default (yellow) / differs from pre-test baseline (orange). "
                          "Values shown unsigned (GPL prints signed bytes).",
                  foreground="#777").pack(anchor="w", pady=(4, 2))

        cols = ("i", "name", "group", "value", "real", "min", "max", "default", "baseline")
        self.p_tree = self._tree(f, cols, (40, 230, 90, 55, 110, 50, 50, 60, 65))
        self.p_tree.heading("real", text="Meaning")
        self.p_tree.tag_configure("changed", background="#fff6c2")
        self.p_tree.tag_configure("drift", background="#ffd9b0")
        self.p_tree.bind("<<TreeviewSelect>>", self._param_selected)

        ed = ttk.LabelFrame(f, text="Edit selected parameter", padding=6)
        ed.pack(fill="x", pady=(6, 0))
        self.p_sel = ttk.Label(ed, text="(select a row)", width=34)
        self.p_sel.grid(row=0, column=0, rowspan=2, sticky="w")
        self.p_entry = {}
        for col, (key, label, cmd) in enumerate((("value", "Value", "SP"), ("min", "Min", "SMN"), ("max", "Max", "SMX"))):
            ttk.Label(ed, text=label).grid(row=0, column=1 + col * 2, sticky="e", padx=(10, 2))
            e = ttk.Entry(ed, width=6)
            e.grid(row=0, column=2 + col * 2, sticky="w")
            self.p_entry[key] = e
            ttk.Button(ed, text=f"Set ({cmd})" + (" *" if cmd in UNTESTED else ""),
                       command=lambda k=key, c=cmd: self.set_param(k, c)).grid(row=1, column=1 + col * 2, columnspan=2, pady=2)
        ttk.Button(ed, text="Read (GP)", command=self.get_param).grid(row=0, column=7, padx=(14, 2))
        ttk.Button(ed, text="Restore default (RP)", command=self.reset_param).grid(row=1, column=7, padx=(14, 2))
        ttk.Label(ed, text="* untested on the unit", foreground="#777").grid(row=0, column=8, rowspan=2, padx=10)
        self.p_desc = ttk.Label(f, text="Select a parameter to see what it does.", justify="left",
                                anchor="nw", wraplength=980, font=("TkDefaultFont", 10))
        self.p_desc.pack(fill="x", pady=(6, 0))

    def _tree(self, parent, cols, widths):
        frame = ttk.Frame(parent)
        frame.pack(fill="both", expand=True)
        t = ttk.Treeview(frame, columns=cols, show="headings", selectmode="browse")
        for c, w in zip(cols, widths):
            t.heading(c, text=c.capitalize() if c != "i" else "#")
            t.column(c, width=w, anchor="w" if c in ("name", "desc") else "e", stretch=c in ("name", "desc"))
        sb = ttk.Scrollbar(frame, orient="vertical", command=t.yview)
        t.configure(yscrollcommand=sb.set)
        t.pack(side="left", fill="both", expand=True)
        sb.pack(side="right", fill="y")
        return t

    def read_params(self):
        def done(status, body):
            rows = parse_gpl(body)
            if not rows:
                messagebox.showerror("GPL", "Could not parse reply:\n" + "\n".join(body[:10]))
                return
            self.params = rows
            self._fill_params()
        self.send("GPL", done)

    def _fill_params(self):
        sel = self.p_tree.selection()
        self.p_tree.delete(*self.p_tree.get_children())
        for p in self.params:
            b = self.baseline_p.get(p["i"])
            tag = ()
            if b and b["value"] != p["value"]:
                tag = ("drift",)
            elif p["value"] != p["default"]:
                tag = ("changed",)
            pi = self.info["params"].get(p["name"], {})
            self.p_tree.insert("", "end", iid=str(p["i"]), tags=tag, values=(
                p["i"], p["name"], pi.get("group", ""), p["value"], fmt_value(pi.get("unit"), p["value"]),
                p["min"], p["max"], p["default"], b["value"] if b else ""))
        if sel and self.p_tree.exists(sel[0]):
            self.p_tree.selection_set(sel)
            self.p_tree.see(sel[0])

    def _selected_param(self):
        sel = self.p_tree.selection()
        if not sel:
            messagebox.showinfo("Parameters", "Select a parameter first (Read all).")
            return None
        return next(p for p in self.params if p["i"] == int(sel[0]))

    def _param_selected(self, _e=None):
        sel = self.p_tree.selection()
        if not sel:
            return
        p = next(p for p in self.params if p["i"] == int(sel[0]))
        self.p_sel.config(text=f"#{p['i']}  {p['name']}")
        for k, e in self.p_entry.items():
            e.delete(0, "end")
            e.insert(0, str(p[k]))
        self.p_desc.config(text=self.param_text(p))

    def param_text(self, p):
        pi = self.info["params"].get(p["name"])
        if not pi:
            return f"{p['name']}: no description available ({INFO_PATH} missing?)"
        unit = pi.get("unit")
        f = lambda v: fmt_value(unit, v)
        text = (f"{p['name']}  [{pi['group']}]  — unit: {self.info['units'].get(unit, unit)}\n{pi['desc']}\n"
                f"Now {p['value']} = {f(p['value'])}   ·   default {f(p['default'])}   ·   "
                f"allowed {f(p['min'])} … {f(p['max'])}")
        if pi.get("bits"):
            text += "\n" + decode_bits(pi["bits"], p["value"])
        return text

    def set_param(self, key, cmd):
        p = self._selected_param()
        if not p:
            return
        try:
            v = int(self.p_entry[key].get())
        except ValueError:
            messagebox.showerror("Value", "Enter an integer 0..255")
            return
        if not 0 <= v <= 255:
            messagebox.showerror("Value", "Parameters are bytes: 0..255")
            return
        why = f"{p['name']}: {key} {p[key]} → {v}"
        if key == "value" and not p["min"] <= v <= p["max"]:
            why += f"\nOutside min/max {p['min']}..{p['max']}: the firmware should reject it (0x85)."
        line = f"{cmd} {p['i']},{v}"
        self.guarded(line, lambda s, b, i=p["i"]: self._verify_param(i, s, b), why)

    def _verify_param(self, i, status, body):
        if status != "OK":
            messagebox.showwarning("Write", f"Reply: {' '.join(body)}")
        self.read_params()

    def get_param(self):
        p = self._selected_param()
        if p:
            self.send(f"GP {p['i']}", lambda s, b: self.set_status(f"GP {p['i']} ({p['name']}) = {' '.join(b)}"))

    def reset_param(self):
        p = self._selected_param()
        if p:
            self.guarded(f"RP {p['i']}", lambda s, b, i=p["i"]: self._verify_param(i, s, b),
                         f"{p['name']}: {p['value']} → default {p['default']}")

    def restore_params_baseline(self):
        if not self.baseline_p:
            messagebox.showerror("Baseline", f"Not found: {BASELINE_GPL}")
            return
        if not self.params:
            messagebox.showinfo("Baseline", "Read all parameters (GPL) first.")
            return
        cmds = []
        for p in self.params:
            b = self.baseline_p.get(p["i"])
            if not b:
                continue
            if b["min"] != p["min"]:
                cmds.append(f"SMN {p['i']},{b['min']}")
            if b["max"] != p["max"]:
                cmds.append(f"SMX {p['i']},{b['max']}")
            if b["value"] != p["value"]:
                cmds.append(f"SP {p['i']},{b['value']}")
        self._run_batch(cmds, "parameters", self.read_params)

    def _run_batch(self, cmds, what, after):
        if not cmds:
            messagebox.showinfo("Baseline", f"All {what} already match the baseline.")
            return
        untested = sorted({classify(c)[0] for c in cmds} & UNTESTED)
        text = f"{len(cmds)} EEPROM write(s) to restore {what} from the baseline:\n\n" + "\n".join(cmds[:25])
        if len(cmds) > 25:
            text += f"\n… and {len(cmds) - 25} more"
        if untested:
            text += f"\n\nIncludes commands not yet verified on the unit: {', '.join(untested)}"
        if not messagebox.askyesno("Restore from baseline", text + "\n\nSend them?", icon="warning"):
            return
        for c in cmds:
            self.send(c)
        self.send("GPL" if what == "parameters" else "GCL", lambda s, b: after())

    # ---------- Counters tab
    def _build_counters(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Counters", (FW_347,))
        top = ttk.Frame(f)
        top.pack(fill="x")
        ttk.Button(top, text="Read all (GCL)", command=self.read_counters).pack(side="left")
        ttk.Button(top, text="Export CSV…", command=lambda: self.export_csv(self.counters, "counters")).pack(side="left", padx=4)
        ttk.Button(top, text="Restore from baseline… *", command=self.restore_counters_baseline).pack(side="left", padx=4)
        ttk.Button(top, text="Clear ALL counters (RCL)", style="Danger.TButton",
                   command=lambda: self.guarded("RCL", lambda s, b: self.read_counters(),
                                                "Clears all 16 counters and both byte statistics.")
                   ).pack(side="right")
        cols = ("i", "name", "value", "baseline", "desc")
        self.c_tree = self._tree(f, cols, (40, 60, 110, 110, 560))
        self.c_tree.heading("desc", text="Meaning")
        self.c_tree.tag_configure("drift", background="#ffd9b0")

        ed = ttk.LabelFrame(f, text="Selected counter", padding=6)
        ed.pack(fill="x", pady=(6, 0))
        ttk.Button(ed, text="Read (GC)", command=self.get_counter).pack(side="left")
        ttk.Button(ed, text="Clear (RC) *", command=self.clear_counter).pack(side="left", padx=6)
        ttk.Label(ed, text="Value:").pack(side="left", padx=(16, 2))
        self.c_entry = ttk.Entry(ed, width=12)
        self.c_entry.pack(side="left")
        ttk.Button(ed, text="Set (gNN value) *", command=self.set_counter).pack(side="left", padx=6)
        ttk.Label(ed, text="* untested on the unit", foreground="#777").pack(side="left", padx=10)
        self.c_desc = ttk.Label(f, text="Select a counter to see what it counts.", justify="left",
                                anchor="nw", wraplength=980, font=("TkDefaultFont", 10))
        self.c_desc.pack(fill="x", pady=(6, 0))
        self.c_tree.bind("<<TreeviewSelect>>", self._counter_selected)

    def read_counters(self):
        def done(status, body):
            rows = parse_gcl(body)
            if not rows:
                messagebox.showerror("GCL", "Could not parse reply:\n" + "\n".join(body[:10]))
                return
            self.counters = rows
            sel = self.c_tree.selection()
            self.c_tree.delete(*self.c_tree.get_children())
            for c in rows:
                b = self.baseline_c.get(c["i"])
                self.c_tree.insert("", "end", iid=str(c["i"]), tags=("drift",) if b and b["value"] != c["value"] else (),
                                   values=(c["i"], c["name"], f"{c['value']:,}", f"{b['value']:,}" if b else "",
                                           self._counter_desc(c)))
            if sel and self.c_tree.exists(sel[0]):
                self.c_tree.selection_set(sel)
        self.send("GCL", done)

    def _counter_desc(self, c):
        ci = self.info["counters"].get(c["name"], {})
        real = fmt_value(ci.get("unit"), c["value"]) if ci.get("unit") not in (None, "count") else ""
        return (f"[{real}]  " if real else "") + ci.get("desc", "")

    def _selected_counter(self):
        sel = self.c_tree.selection()
        if not sel:
            messagebox.showinfo("Counters", "Select a counter first (Read all).")
            return None
        return next(c for c in self.counters if c["i"] == int(sel[0]))

    def _counter_selected(self, _e=None):
        c = self._selected_counter()
        if c:
            self.c_entry.delete(0, "end")
            self.c_entry.insert(0, str(c["value"]))
            ci = self.info["counters"].get(c["name"], {})
            self.c_desc.config(text=f"{c['name']} — {ci.get('desc', 'no description')}\n"
                                    f"Now {c['value']:,} {self.info['units'].get(ci.get('unit'), '')}"
                                    f" = {fmt_value(ci.get('unit'), c['value'])}")

    def get_counter(self):
        c = self._selected_counter()
        if c:
            self.send(f"GC {c['i']}", lambda s, b: self.set_status(f"GC {c['i']} ({c['name']}) = {' '.join(b)}"))

    def clear_counter(self):
        c = self._selected_counter()
        if c:
            self.guarded(f"RC {c['i']}", lambda s, b: self.read_counters(), f"{c['name']}: {c['value']:,} → 0")

    @staticmethod
    def g_line(i, v):
        line = f"g{i:02d} {v}"
        return line if len(line) <= MAX_LINE else f"g{i:02d}{v}"  # atol skips leading spaces, so the space is optional

    def set_counter(self):
        c = self._selected_counter()
        if not c:
            return
        try:
            v = int(self.c_entry.get().replace(",", ""))
        except ValueError:
            messagebox.showerror("Value", "Enter an integer")
            return
        if not 0 <= v <= 0xFFFFFFFF:
            messagebox.showerror("Value", "Counters are 32-bit unsigned")
            return
        self.guarded(self.g_line(c["i"], v), lambda s, b: self.read_counters(), f"{c['name']}: {c['value']:,} → {v:,}")

    def restore_counters_baseline(self):
        if not self.baseline_c:
            messagebox.showerror("Baseline", f"Not found: {BASELINE_GCL}")
            return
        if not self.counters:
            messagebox.showinfo("Baseline", "Read all counters (GCL) first.")
            return
        cmds = [self.g_line(c["i"], self.baseline_c[c["i"]]["value"]) for c in self.counters
                if c["i"] in self.baseline_c and self.baseline_c[c["i"]]["value"] != c["value"]]
        self._run_batch(cmds, "counters", self.read_counters)

    def export_csv(self, rows, what):
        if not rows:
            messagebox.showinfo("Export", f"Read the {what} first.")
            return
        path = filedialog.asksaveasfilename(defaultextension=".csv", initialdir=HERE,
                                            initialfile=f"{what}_{datetime.datetime.now():%Y%m%d_%H%M%S}.csv")
        if path:
            with open(path, "w") as f:
                f.write(",".join(rows[0].keys()) + "\n")
                for r in rows:
                    f.write(",".join(str(v) for v in r.values()) + "\n")
            self.set_status(f"Wrote {path}")

    # ---------- Controls tab
    def _build_controls(self, nb):
        f = ttk.Frame(nb, padding=10)
        self._tab(f, "Controls", (FW_347,))
        ttk.Label(f, text="These commands switch outputs or change the operating mode. Each one asks for confirmation; "
                          "STP is always sent immediately.", wraplength=900, foreground="#777").pack(anchor="w")
        groups = [
            ("Dispense", [("DCW", "Dispense cold"), ("DHW", "Dispense hot"), ("STP", "Stop")]),
            ("Child protection", [("CP1", "Child protection ON"), ("CP0", "Child protection OFF"),
                                  ("CWC", "Read state")]),
            ("Extra-hot", [("EH1", "Extra-hot ON"), ("EH0", "Extra-hot OFF")]),
            ("Mode", [("NM", "Normal mode (wake)"), ("SM", "Sleep mode"), ("PD", "Power down (standby)"),
                      ("RS", "Reset controller")]),
        ]
        for title, items in groups:
            lf = ttk.LabelFrame(f, text=title, padding=8)
            lf.pack(fill="x", pady=6)
            for cmd, label in items:
                ttk.Button(lf, text=f"{label}  [{cmd}]", style="Stop.TButton" if cmd == "STP" else "TButton",
                           command=lambda c=cmd: self.guarded(c)).pack(side="left", padx=4)

        lf = ttk.LabelFrame(f, text="Execute command-table entry (XC n) — untested", padding=8)
        lf.pack(fill="x", pady=6)
        ttk.Label(lf, text="Entry #").pack(side="left")
        self.xc_var = tk.IntVar(value=4)
        ttk.Spinbox(lf, from_=0, to=27, width=4, textvariable=self.xc_var).pack(side="left", padx=4)
        ttk.Button(lf, text="Send XC", command=lambda: self.guarded(
            f"XC {self.xc_var.get()}", why="Runs whichever command sits at that index of the table (see LCL), "
                                            "which may be a hardware action.")).pack(side="left", padx=4)
        ttk.Button(lf, text="Show table (LCL)", command=lambda: self.send("LCL")).pack(side="left", padx=4)

    # ---------- v3.5.13: Status tab
    def _build_status35(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Status", (FW_35,))
        top = ttk.Frame(f)
        top.pack(fill="x")
        ttk.Button(top, text="Refresh all", command=self.refresh_status35).pack(side="left")
        ttk.Checkbutton(top, text="Auto-refresh every", variable=self.auto_var,
                        command=self._auto_toggle).pack(side="left", padx=(12, 2))
        ttk.Spinbox(top, from_=5, to=300, width=5, textvariable=self.auto_sec).pack(side="left")
        ttk.Label(top, text="s").pack(side="left")

        body = ttk.Frame(f)
        body.pack(fill="both", expand=True, pady=8)
        left = ttk.LabelFrame(body, text="Readings", padding=8)
        left.pack(side="left", fill="both", expand=True, padx=(0, 4))
        self.status35_vals = {}
        for r, (key, label, cmd) in enumerate(self.STATUS35_ROWS):
            ttk.Label(left, text=label).grid(row=r, column=0, sticky="w", pady=2)
            ttk.Label(left, text=cmd, foreground="#777").grid(row=r, column=1, sticky="w", padx=6)
            v = ttk.Label(left, text="—", font=("TkDefaultFont", 10, "bold"))
            v.grid(row=r, column=2, sticky="w")
            self.status35_vals[key] = v
            ttk.Button(left, text="↻", width=3, command=lambda c=cmd: self._read35(c)).grid(row=r, column=3, padx=4)
        left.columnconfigure(2, weight=1)

        right = ttk.LabelFrame(body, text="Outputs (from input)", padding=8)
        right.pack(side="left", fill="both", expand=True, padx=(4, 0))
        self.out_tree35 = self._out_tree(right)
        ttk.Label(right, text="Bench note: with no NTC sensors / UV lamp attached, temperatures read -1 (A2D 1023) "
                              "and errors 6, 21 are active. The error numbers are not decoded yet.",
                  foreground="#777", wraplength=420).pack(anchor="w", pady=(6, 0))

    def _out_tree(self, parent, height=8):
        t = ttk.Treeview(parent, columns=("n", "name", "state"), show="headings", height=height, selectmode="browse")
        for c, w, txt in (("n", 40, "#"), ("name", 170, "Output"), ("state", 80, "State")):
            t.heading(c, text=txt)
            t.column(c, width=w, anchor="w")
        t.tag_configure("on", foreground="#2e7d32", font=("TkDefaultFont", 10, "bold"))
        for n, name in enumerate(SHELL_OUTPUTS):
            t.insert("", "end", iid=str(n), values=(n, name, "?"))
        t.pack(fill="both", expand=True)
        return t

    def refresh_status35(self):
        for cmd in ("ver", "get_hwt_type", "temp", "input", "get_errors_bitmap", "get_wu"):
            self._read35(cmd)

    def _read35(self, cmd):
        self.send(cmd, lambda s, b, c=cmd: self._show35(c, s, b))

    def _set35(self, key, text, err=False):
        self.status35_vals[key].config(text=text, foreground="#b00020" if err else "")

    def _show35(self, cmd, status, body):
        keys = [k for k, _, c in self.STATUS35_ROWS if c == cmd]
        if status != "OK":
            for k in keys:
                self._set35(k, "error: " + " ".join(body), True)
            return
        if cmd == "ver":
            self._set35("ver", " ".join(l.strip() for l in body))
        elif cmd == "get_hwt_type":
            self._set35("hwt", " ".join(l.strip() for l in body).replace("Hot Tank ", ""))
        elif cmd == "temp":
            kv = parse_kv(body)
            for k in keys:
                v = kv.get(k)
                self._set35(k, "—" if v is None else "open sensor (-1)" if v == -1 else f"{v} °C", v == -1)
        elif cmd == "input":
            kv = parse_kv(body)
            for l in body:
                if l.startswith("A2D:"):
                    self._set35("A2D", l[4:].strip())
                elif l.startswith("Buttons:"):
                    self._set35("Buttons", l[8:].strip() + "   (raw)")
            for k in ("UV_POS", "UV_READY", "HEATER_FEEDBACK"):
                if k in kv:
                    self._set35(k, f"{kv[k]}" + {"UV_POS": ("  (no lamp)", "  (lamp present)"),
                                                 "UV_READY": ("  (not lit)", "  (lit)")}.get(k, ("", ""))[kv[k] & 1])
            self._show_outputs(body)
        elif cmd == "get_errors_bitmap":
            nums = re.findall(r"\d+", " ".join(body))
            self._set35("errors", ", ".join(nums) if nums else "none", bool(nums))
        elif cmd == "get_wu":
            m = re.search(r"(\d+)\s*$", " ".join(body))
            self._set35("wu", f"{int(m[1]):,}   (unit not decoded)" if m else " ".join(body))

    def _show_outputs(self, body):
        outs = parse_outputs(body)
        for t in (self.out_tree35, self.out_tree_ctl):
            for n, (name, v) in outs.items():
                if t.exists(str(n)):
                    t.item(str(n), values=(n, name, "ON" if v else "off"), tags=("on",) if v else ())

    # ---------- v3.5.13: Controls tab
    def _build_controls35(self, nb):
        f = ttk.Frame(nb, padding=10)
        self._tab(f, "Controls", (FW_35,))
        ttk.Label(f, text="These commands switch outputs or change the operating mode. Each one asks for confirmation "
                          "(none has been tested on the unit yet). Switching an output OFF and the STOP button are "
                          "sent immediately.", wraplength=950, foreground="#777").pack(anchor="w")
        row = ttk.Frame(f)
        row.pack(fill="both", expand=True, pady=6)
        lf = ttk.LabelFrame(row, text="Outputs (output=n,v)", padding=8)
        lf.pack(side="left", fill="both", padx=(0, 6))
        self.out_tree_ctl = self._out_tree(lf)
        bt = ttk.Frame(lf)
        bt.pack(fill="x", pady=(6, 0))
        ttk.Button(bt, text="Read (output)", command=lambda: self.send("output", lambda s, b: self._show_outputs(b))
                   ).pack(side="left")
        ttk.Button(bt, text="Switch ON", command=lambda: self._switch_output(1)).pack(side="left", padx=4)
        ttk.Button(bt, text="Switch OFF", command=lambda: self._switch_output(0)).pack(side="left")
        ttk.Label(lf, text="Writes the port latch directly. The normal control tasks may switch it back "
                           "(inferred); testing mode probably prevents that.", foreground="#777",
                  wraplength=320).pack(anchor="w", pady=(6, 0))

        col = ttk.Frame(row)
        col.pack(side="left", fill="both", expand=True)
        lf = ttk.LabelFrame(col, text="Dispense (hot=a / cold=a / mix=a)", padding=8)
        lf.pack(fill="x")
        ttk.Label(lf, text="Argument:").pack(side="left")
        self.disp_arg = ttk.Entry(lf, width=6)
        self.disp_arg.insert(0, "1")
        self.disp_arg.pack(side="left", padx=4)
        for cmd, label in (("hot", "Hot"), ("cold", "Cold"), ("mix", "Mix")):
            ttk.Button(lf, text=f"{label}  [{cmd}=…]", command=lambda c=cmd: self._dispense(c)).pack(side="left", padx=3)
        ttk.Label(col, text="The argument is required and stored at RAM 0x10A; whether it is a volume or a time is not "
                            "decoded. There is no dispense-stop command in v3.5.13: STOP switches the hot, cold and "
                            "inlet valves off with output=n,0. If water still flows, use reset.",
                  foreground="#777", wraplength=560).pack(anchor="w", pady=(2, 8))

        lf = ttk.LabelFrame(col, text="Simulate a key press (manual_press=k,t)", padding=8)
        lf.pack(fill="x")
        ttk.Label(lf, text="Key (0-6):").pack(side="left")
        self.key_var = tk.IntVar(value=0)
        ttk.Spinbox(lf, from_=0, to=6, width=4, textvariable=self.key_var).pack(side="left", padx=4)
        ttk.Label(lf, text="Time (> 0):").pack(side="left", padx=(10, 0))
        self.key_time = ttk.Entry(lf, width=6)
        self.key_time.insert(0, "10")
        self.key_time.pack(side="left", padx=4)
        ttk.Button(lf, text="Press", command=self._manual_press).pack(side="left", padx=6)
        ttk.Label(col, text="Key numbers and the time unit are not decoded.", foreground="#777").pack(anchor="w", pady=(2, 8))

        lf = ttk.LabelFrame(col, text="Testing mode / other", padding=8)
        lf.pack(fill="x")
        ttk.Button(lf, text="Enter testing mode", command=lambda: self.guarded("testing_mode=1")).pack(side="left")
        ttk.Button(lf, text="Leave testing mode", command=lambda: self.guarded("testing_mode=0")).pack(side="left", padx=4)
        ttk.Button(lf, text="ex (unknown)", command=lambda: self.guarded("ex")).pack(side="left", padx=4)
        ttk.Button(lf, text="Reset controller", style="Danger.TButton",
                   command=lambda: self.guarded("reset")).pack(side="left", padx=4)

    def _switch_output(self, v):
        sel = self.out_tree_ctl.selection()
        if not sel:
            messagebox.showinfo("Outputs", "Select an output first.")
            return
        n = int(sel[0])
        line = f"output={n},{v}"
        after = lambda s, b: self.send("output", lambda s2, b2: self._show_outputs(b2))
        if v == 0:
            self.send(line, after)
        else:
            self.guarded(line, after, f"Switches {SHELL_OUTPUTS[n]} ON.")

    def _dispense(self, cmd):
        arg = self.disp_arg.get().strip()
        if not re.fullmatch(r"-?\d+", arg):
            messagebox.showerror("Argument", "Enter an integer argument (it is required).")
            return
        self.guarded(f"{cmd}={arg}", why="Use STOP to close the valves.")

    def _manual_press(self):
        t = self.key_time.get().strip()
        if not t.isdigit() or int(t) <= 0:
            messagebox.showerror("Time", "The time must be a whole number > 0.")
            return
        self.guarded(f"manual_press={self.key_var.get()},{t}")

    # ---------- v3.5.13: Setup tab
    def _build_setup35(self, nb):
        f = ttk.Frame(nb, padding=10)
        self._tab(f, "Setup", (FW_35,))
        ttk.Label(f, text="Production / service settings. These write EEPROM; shipping and production mode also reset "
                          "the controller. None has been tested on the unit yet.", wraplength=950,
                  foreground="#777").pack(anchor="w")

        lf = ttk.LabelFrame(f, text="Language (set_language=n)", padding=8)
        lf.pack(fill="x", pady=6)
        self.lang_var = tk.StringVar(value="5 Hebrew")
        ttk.Combobox(lf, textvariable=self.lang_var, state="readonly", width=16,
                     values=[f"{n} {LANGUAGES.get(n, '(not decoded)')}" for n in range(8)]).pack(side="left")
        ttk.Button(lf, text="Set language", command=lambda: self.guarded(
            f"set_language={self.lang_var.get().split()[0]}",
            why="Writes the language field (bits 0x38) of SYSTEMCONFIG2.")).pack(side="left", padx=6)

        for title, cmd, why in (
                ("Shipping mode (set_shipping_mode=n)", "set_shipping_mode",
                 "Shipping mode = SYSTEMCONFIG4 bit 0: the first-installation flow runs at the next power-up."),
                ("Production mode (set_production_mode=n)", "set_production_mode",
                 "Production mode = SYSTEMCONFIG3 bit 0x02. While it is set, every boot forces the factory "
                 "configuration in RAM (SYSTEMCONFIG |= 0xBF, SYSTEMCONFIG2 = 0x40 = English, SYSTEMCONFIG4 = 0xE7), "
                 "as the factory jumper does.")):
            lf = ttk.LabelFrame(f, text=title, padding=8)
            lf.pack(fill="x", pady=6)
            ttk.Button(lf, text="ON (1)", command=lambda c=cmd, w=why: self.guarded(f"{c}=1", why=w)).pack(side="left")
            ttk.Button(lf, text="OFF (0)", command=lambda c=cmd, w=why: self.guarded(f"{c}=0", why=w)
                       ).pack(side="left", padx=4)
            ttk.Label(lf, text=why + " The controller resets afterwards.", foreground="#777",
                      wraplength=700).pack(side="left", padx=10)

        lf = ttk.LabelFrame(f, text="Other", padding=8)
        lf.pack(fill="x", pady=6)
        ttk.Button(lf, text="Show command table (ls)", command=lambda: self.send("ls")).pack(side="left")
        ttk.Button(lf, text="Restore factory settings", style="Danger.TButton", command=lambda: self.guarded(
            "restore_factory_settings", why="v3.5.13 has no command to read the parameters back, so the current "
            "values cannot be saved first over serial.")).pack(side="left", padx=6)
        ttk.Button(lf, text="Reset controller", style="Danger.TButton",
                   command=lambda: self.guarded("reset")).pack(side="left", padx=6)

    # ---------- v3.5.13: Parameters (reference) tab
    # ---------- Parameters (editable, v3.5.13 `par` patch)
    def _build_params_edit(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Parameters (edit)", (FW_35,))
        top = ttk.Frame(f)
        top.pack(fill="x")
        ttk.Button(top, text="Read all (par)", command=self.read_params35).pack(side="left")
        ttk.Button(top, text="Read selected", command=self.get_param35).pack(side="left", padx=4)
        ttk.Button(top, text="Export CSV…",
                   command=lambda: self.export_csv(self._pe_export_rows(), "params_v35")).pack(side="left", padx=4)
        ttk.Label(f, text="Needs the `par` patch flashed (see ../v3.5.13/PARAM_SHELL_PATCH.md); a stock v3.5.13 unit "
                          "answers ERROR -123. 'par=i' reads, 'par=i,v' writes with the firmware's min/max enforced. "
                          "Highlighted: value differs from ROM default (yellow).",
                  foreground="#777", wraplength=980).pack(anchor="w", pady=(4, 2))

        cols = ("i", "name", "group", "value", "real", "min", "max", "default")
        self.pe_tree = self._tree(f, cols, (40, 250, 90, 60, 120, 55, 55, 60))
        self.pe_tree.heading("real", text="Meaning")
        self.pe_tree.tag_configure("changed", background="#fff6c2")
        self.pe_tree.bind("<<TreeviewSelect>>", self._pe_selected)

        ed = ttk.LabelFrame(f, text="Edit selected parameter", padding=6)
        ed.pack(fill="x", pady=(6, 0))
        self.pe_sel = ttk.Label(ed, text="(select a row)", width=34)
        self.pe_sel.grid(row=0, column=0, rowspan=2, sticky="w")
        ttk.Label(ed, text="Value").grid(row=0, column=1, sticky="e", padx=(10, 2))
        self.pe_entry = ttk.Entry(ed, width=6)
        self.pe_entry.grid(row=0, column=2, sticky="w")
        ttk.Button(ed, text="Set (par=i,v)", command=self.set_param35).grid(row=1, column=1, columnspan=2, pady=2)
        ttk.Button(ed, text="Read (par=i)", command=self.get_param35).grid(row=0, column=3, padx=(14, 2))
        ttk.Button(ed, text="Restore default", command=self.reset_param35).grid(row=1, column=3, padx=(14, 2))
        ttk.Label(ed, text="Values are bytes 0..255; writes outside min..max are rejected by the firmware.",
                  foreground="#777").grid(row=0, column=4, rowspan=2, padx=10, sticky="w")
        self.pe_desc = ttk.Label(f, text="Select a parameter to see what it does.", justify="left",
                                 anchor="nw", wraplength=980, font=("TkDefaultFont", 10))
        self.pe_desc.pack(fill="x", pady=(6, 0))

        self.pe_rows = rom_table(self.info, FW_35)       # i, name, default, min, max
        self.pe_val = {}                                  # i -> current live value (int), once read
        for r in self.pe_rows:
            pi = self.info["params"].get(r["name"], {})
            self.pe_tree.insert("", "end", iid=str(r["i"]), values=(
                r["i"], r["name"], pi.get("group", ""), "—", "", r["min"], r["max"], r["default"]))

    def _pe_row(self, i):
        return next(r for r in self.pe_rows if r["i"] == i)

    def _pe_export_rows(self):
        out = []
        for r in self.pe_rows:
            d = dict(r)
            d["value"] = self.pe_val.get(r["i"], "")
            out.append(d)
        return out

    def _pe_selected(self, _e=None):
        sel = self.pe_tree.selection()
        if not sel:
            return
        i = int(sel[0])
        r = self._pe_row(i)
        self.pe_sel.config(text=f"#{i}  {r['name']}")
        self.pe_entry.delete(0, "end")
        self.pe_entry.insert(0, str(self.pe_val.get(i, r["default"])))
        self.pe_desc.config(text=self._pe_text(r))

    def _pe_text(self, r):
        pi = self.info["params"].get(r["name"])
        v = self.pe_val.get(r["i"])
        if not pi:
            now = f"Now {v}   ·   " if v is not None else ""
            return f"{r['name']}: no description available\n{now}default {r['default']}   ·   allowed {r['min']} … {r['max']}"
        unit = pi.get("unit")
        fv = lambda x: fmt_value(unit, x)
        now = f"Now {v} = {fv(v)}   ·   " if v is not None else ""
        text = (f"{r['name']}  [{pi['group']}]  — unit: {self.info['units'].get(unit, unit)}\n{pi['desc']}\n"
                f"{now}default {fv(r['default'])}   ·   allowed {fv(r['min'])} … {fv(r['max'])}")
        note = self.info.get("versions", {}).get(FW_35, {}).get("notes", {}).get(r["name"])
        if note:
            text += "\n" + note
        if pi.get("bits") and v is not None:
            text += "\n" + decode_bits(pi["bits"], v)
        return text

    def _pe_set_value(self, i, v):
        self.pe_val[i] = v
        r = self._pe_row(i)
        pi = self.info["params"].get(r["name"], {})
        self.pe_tree.set(str(i), "value", v)
        self.pe_tree.set(str(i), "real", fmt_value(pi.get("unit"), v))
        self.pe_tree.item(str(i), tags=("changed",) if v != r["default"] else ())
        sel = self.pe_tree.selection()
        if sel and int(sel[0]) == i:
            self.pe_desc.config(text=self._pe_text(r))

    def _pe_got(self, i, status, body):
        if status != "OK" or not body:
            self.set_status(f"par={i}: {' '.join(body) or 'no reply'}")
            return
        m = re.search(r"-?\d+", body[0])
        if m:
            self._pe_set_value(i, int(m.group()))

    def read_params35(self):
        if not self.link.port:
            self.set_status("Not connected")
            return
        for r in self.pe_rows:
            i = r["i"]
            self.send(f"par={i}", lambda s, b, i=i: self._pe_got(i, s, b))

    def _pe_selected_row(self):
        sel = self.pe_tree.selection()
        if not sel:
            messagebox.showinfo("Parameters", "Select a parameter first.")
            return None
        return self._pe_row(int(sel[0]))

    def get_param35(self):
        r = self._pe_selected_row()
        if r:
            self.send(f"par={r['i']}", lambda s, b, i=r["i"]: self._pe_got(i, s, b))

    def set_param35(self):
        r = self._pe_selected_row()
        if not r:
            return
        try:
            v = int(self.pe_entry.get())
        except ValueError:
            messagebox.showerror("Value", "Enter an integer 0..255")
            return
        if not 0 <= v <= 255:
            messagebox.showerror("Value", "Parameters are bytes: 0..255")
            return
        if not r["min"] <= v <= r["max"]:
            # The `par` write path in the jug patch no longer range-checks in firmware, so block here.
            messagebox.showerror("Out of range",
                                 f"{r['name']} must be {r['min']}..{r['max']} (you entered {v}).\n"
                                 "Blocked: this firmware does not range-check par writes.")
            return
        cur = self.pe_val.get(r["i"], r["default"])
        self.guarded(f"par={r['i']},{v}", lambda s, b, i=r["i"]: self._pe_verify(i, s, b),
                     f"{r['name']}: {cur} → {v}")

    def reset_param35(self):
        r = self._pe_selected_row()
        if not r:
            return
        cur = self.pe_val.get(r["i"], "?")
        self.guarded(f"par={r['i']},{r['default']}", lambda s, b, i=r["i"]: self._pe_verify(i, s, b),
                     f"{r['name']}: {cur} → default {r['default']}")

    def _pe_verify(self, i, status, body):
        if status != "OK":
            messagebox.showwarning("Write", f"par={i}: {' '.join(body)}")
        self.send(f"par={i}", lambda s, b, i=i: self._pe_got(i, s, b))  # read back the stored value

    def _build_params_ref(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Parameters (reference)", (FW_35,))
        ttk.Label(f, text="v3.5.13 has no serial command to read or write parameters. This is its ROM table "
                          "(defaults and limits) with the explanations; change settings from the unit's menu. "
                          "Highlighted: new in v3.5.13 (green) / changed from v3.47 (yellow).",
                  foreground="#777", wraplength=980).pack(anchor="w", pady=(0, 4))
        cols = ("i", "name", "group", "default", "real", "min", "max", "v347")
        self.r_tree = self._tree(f, cols, (40, 260, 90, 60, 110, 50, 50, 140))
        self.r_tree.heading("real", text="Meaning")
        self.r_tree.heading("v347", text="v3.47 def/min/max")
        self.r_tree.tag_configure("new", background="#d7f5d0")
        self.r_tree.tag_configure("changed", background="#fff6c2")
        self.r_desc = ttk.Label(f, text="Select a parameter to see what it does.", justify="left",
                                anchor="nw", wraplength=980, font=("TkDefaultFont", 10))
        self.r_desc.pack(fill="x", pady=(6, 0))
        old = {r["name"]: r for r in rom_table(self.info, FW_347)}
        self.ref_rows = rom_table(self.info, FW_35)
        for r in self.ref_rows:
            o = old.get(r["name"])
            pi = self.info["params"].get(r["name"], {})
            same = o and (o["default"], o["min"], o["max"]) == (r["default"], r["min"], r["max"])
            self.r_tree.insert("", "end", iid=str(r["i"]), tags=() if same else ("changed",) if o else ("new",),
                               values=(r["i"], r["name"], pi.get("group", ""), r["default"],
                                       fmt_value(pi.get("unit"), r["default"]), r["min"], r["max"],
                                       "" if same else f"{o['default']} / {o['min']} / {o['max']}" if o else "new"))
        self.r_tree.bind("<<TreeviewSelect>>", self._ref_selected)

    def _ref_selected(self, _e=None):
        sel = self.r_tree.selection()
        if not sel:
            return
        r = next(r for r in self.ref_rows if r["i"] == int(sel[0]))
        pi = self.info["params"].get(r["name"])
        if not pi:
            self.r_desc.config(text=f"{r['name']}: no description available")
            return
        unit = pi.get("unit")
        f = lambda v: fmt_value(unit, v)
        text = (f"{r['name']}  [{pi['group']}]  — unit: {self.info['units'].get(unit, unit)}\n{pi['desc']}\n"
                f"Default {f(r['default'])}   ·   allowed {f(r['min'])} … {f(r['max'])}")
        note = self.info.get("versions", {}).get(FW_35, {}).get("notes", {}).get(r["name"])
        if note:
            text += "\n" + note
        if pi.get("bits"):
            text += "\nBits at the default value (v3.47 meanings):\n" + decode_bits(pi["bits"], r["default"])
        self.r_desc.config(text=text)

    # ---------- Console tab
    def _build_console(self, nb):
        f = ttk.Frame(nb, padding=8)
        self._tab(f, "Console", (FW_347, FW_35))
        self.console = tk.Text(f, wrap="none", font=("TkFixedFont", 10), state="disabled", height=20)
        sb = ttk.Scrollbar(f, orient="vertical", command=self.console.yview)
        self.console.configure(yscrollcommand=sb.set)
        self.console.tag_configure("tx", foreground="#1565c0", font=("TkFixedFont", 10, "bold"))
        self.console.tag_configure("err", foreground="#b00020")
        self.console.tag_configure("ok", foreground="#2e7d32")
        bottom = ttk.Frame(f)
        bottom.pack(side="bottom", fill="x", pady=(6, 0))
        sb.pack(side="right", fill="y")
        self.console.pack(fill="both", expand=True)

        ttk.Label(bottom, text="Command:").pack(side="left")
        self.cmd_var = tk.StringVar()
        e = ttk.Entry(bottom, textvariable=self.cmd_var, width=30, font=("TkFixedFont", 11))
        e.pack(side="left", padx=4)
        e.bind("<Return>", lambda _e: self.console_send())
        e.bind("<Up>", lambda _e: self._hist(-1))
        e.bind("<Down>", lambda _e: self._hist(1))
        ttk.Button(bottom, text="Send", command=self.console_send).pack(side="left")
        self.cmd_info = ttk.Label(bottom, text="", foreground="#777")
        self.cmd_info.pack(side="left", padx=10)
        ttk.Button(bottom, text="Clear", command=self._console_clear).pack(side="right")
        self.cmd_var.trace_add("write", lambda *_: self._cmd_preview())
        self.history, self.hist_pos = [], 0

    def _cmd_preview(self):
        line = self.cmd_var.get()
        if not line:
            self.cmd_info.config(text="")
            return
        n = len(line)
        if self.fw == FW_35:
            name, cat = classify_shell(line.strip())
            ml, problem = FIRMWARES[FW_35]["max_line"], shell_arg_problem(line.strip())
            text = f"{n}/{ml} chars · " + (f"{name} ({cat}) — {SHELL_CMDS[name][2]}" if name else
                                           "not a command: the shell will answer ERROR -123 (names are case-sensitive)")
            self.cmd_info.config(text=text + (f" · {problem}" if problem else ""),
                                 foreground="#b00020" if n > ml or problem or cat in ("eeprom", "hardware") else "#777")
            return
        name, cat = classify(line)
        self.cmd_info.config(
            text=f"{n}/{MAX_LINE} chars · hash 0x{cmd_hash(line):02X} → {name or '?'} ({cat})",
            foreground="#b00020" if n > MAX_LINE or cat in ("eeprom", "hardware") else "#777")

    def _hist(self, d):
        if self.history:
            self.hist_pos = max(0, min(len(self.history) - 1, self.hist_pos + d))
            self.cmd_var.set(self.history[self.hist_pos])

    def console_send(self):
        line = self.cmd_var.get().rstrip()
        if self.fw == FW_35:  # a stray leading character makes the shell reject the line
            line = line.lstrip()
        if not line:
            return
        if self.confirm(line):
            self.send(line)
            self.history.append(line)
            self.hist_pos = len(self.history)
            self.cmd_var.set("")

    def console_append(self, line, status, body):
        self.console.configure(state="normal")
        self.console.insert("end", f"[{datetime.datetime.now():%H:%M:%S}] >>> {line}\n", "tx")
        for b in body:
            self.console.insert("end", f"    {b}\n", "err" if status != "OK" else "")
        self.console.insert("end", f"    {status}\n", "ok" if status == "OK" else "err")
        self.console.see("end")
        self.console.configure(state="disabled")

    def _console_clear(self):
        self.console.configure(state="normal")
        self.console.delete("1.0", "end")
        self.console.configure(state="disabled")

    def _quit(self):
        self.link.close()
        self.destroy()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--port", default="/dev/ttyUSB0", help="serial port (the first USB adapter if this one is absent)")
    ap.add_argument("--fw", choices=("auto", FW_347, FW_35), default="auto", help="firmware / protocol (default: auto)")
    ap.add_argument("--demo", action="store_true", help="simulate the unit (no hardware)")
    App(ap.parse_args()).mainloop()


if __name__ == "__main__":
    main()
