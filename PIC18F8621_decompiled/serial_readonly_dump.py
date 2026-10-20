#!/usr/bin/env python3
"""Send only read-only service commands to the PIC18F8621 dispenser (EUSART2, 9600 8N1) and log replies.

Usage: python3 serial_readonly_dump.py /dev/ttyUSB0
Nothing here writes EEPROM or switches outputs. (No SP/SMN/SMX/RP/RPL/RC/RCL/g, no DCW/DHW/CP*/EH*/RS/PD/SM/NM.)
"""
import sys, time, datetime
import serial  # pip install pyserial

READ_ONLY = [
    "VER",            # firmware version
    "ST",             # component fault status
    "GHT", "GCT", "GDT", "COT",   # temperatures
    "GHS", "GCS",     # heating / cooling state
    "HTS", "UVS", "IVS", "CVS", "HVS",  # output states
    "CWC",            # child-protection state (GCH is broken in this firmware)
    "LCL",            # help / command list
    "GCL",            # all usage counters
    "GPL",            # all parameters (value, max, min)
]
READ_ONLY += [f"GP {i}" for i in range(75)]      # each parameter raw value
READ_ONLY += [f"GC {i}" for i in range(18)]      # each counter

def run(port):
    log = open(f"serial_dump_{datetime.datetime.now():%Y%m%d_%H%M%S}.txt", "w")
    with serial.Serial(port, 9600, bytesize=8, parity="N", stopbits=1, timeout=0.3) as s:
        s.reset_input_buffer()
        for cmd in READ_ONLY:
            s.write((cmd + "\r").encode())
            out, quiet = b"", 0
            deadline = time.time() + (8 if cmd in ("GPL", "GCL", "LCL") else 2)
            while time.time() < deadline and quiet < 3:   # stop after ~0.9 s of silence
                chunk = s.read(256)
                if chunk: out += chunk; quiet = 0
                else: quiet += 1
            text = out.decode("latin1", "replace")
            print(f">>> {cmd}\n{text}\n"); log.write(f">>> {cmd}\n{text}\n\n"); log.flush()
    print("log written:", log.name)

if __name__ == "__main__":
    if len(sys.argv) != 2: sys.exit(__doc__)
    run(sys.argv[1])
