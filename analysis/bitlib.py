#!/usr/bin/env python3
"""Replace numeric SFR bit masks in the decompiled PIC18F8621 output with
datasheet bit names (from the MPLAB device pack), and emit a header defining them."""
import os, re, sys
from collections import defaultdict

PIC = "/opt/microchip/mplabx/v6.30/packs/Microchip/PIC18Fxxxx_DFP/1.7.171/edc/PIC18F8621.PIC"
OUT = os.path.expanduser("~/Desktop/PIC18F8621_RE/PIC18F8621_decompiled")
# Registers holding data values rather than bit fields; never decode these.
DATA_REGS = re.compile(r"^(TMR\d[LH]?|TXREG\d?|RCREG\d?|SPBRG\w*|PR\d|CCPR\d[LH]|ADRES[LH]|EEDATA|EEADRH?|"
                       r"FSR\d[LH]|PLUSW\d|PREINC\d|POSTDEC\d|POSTINC\d|INDF\d|WREG|PROD[LH]|TABLAT|TBLPTR[LHU]|"
                       r"PCL|PCLAT[HU]|TOS[LHU]|SSPBUF|SSPADD|BSR)$")

# ---- parse register bit layouts (datasheet mode "DS.0") ----
src = open(PIC).read()
bits = {}  # reg -> {bit: name}
for m in re.finditer(r'<edc:SFRDef [^>]*?edc:cname="(\w+)"[^>]*?edc:_addr="(0x[0-9A-Fa-f]+)".*?</edc:SFRDef>', src, re.S):
    reg, addr, body = m.group(1), int(m.group(2), 16), m.group(0)
    if addr < 0xF60 or reg in bits or DATA_REGS.match(reg):
        continue
    mode = re.search(r'<edc:SFRMode edc:id="DS\.0".*?</edc:SFRMode>', body, re.S)
    if not mode:
        continue
    pos, layout = 0, {}
    for f in re.finditer(r'<edc:(AdjustPoint|SFRFieldDef)\b([^>]*)', mode.group(0)):
        attrs = dict(re.findall(r'edc:(\w+)="([^"]*)"', f.group(2)))
        if f.group(1) == "AdjustPoint":
            pos += int(attrs["offset"], 0)
            continue
        width = int(attrs["nzwidth"], 0)
        name = attrs["cname"].split("_")[0]          # GIE_GIEH -> GIE (datasheet primary name)
        for i in range(width):
            layout[pos + i] = name if width == 1 else f"{name}{i}"
        pos += width
    if layout:
        bits[reg] = layout

# names that mean different bits in different registers get a REG_ prefix
owners = defaultdict(set)
for reg, layout in bits.items():
    for b, n in layout.items():
        owners[n].add(b)
def sym(reg, b):
    n = bits[reg][b]
    return n if len(owners[n]) == 1 else f"{reg}_{n}"

used = {}  # symbol -> (reg, bit)
def names(reg, mask):
    parts, rest = [], 0
    for b in range(8):
        if mask >> b & 1:
            if b in bits[reg]:
                s = sym(reg, b); used[s] = (reg, b); parts.append(s)
            else:
                rest |= 1 << b
    if rest:
        parts.append(f"0x{rest:x}")
    return parts

def render(reg, op, k):
    """Expression for `x <op> k` where x holds register `reg`."""
    if op == "&" and bin(k).count("1") >= 5:           # clearing mask, e.g. & 0xbf
        p = names(reg, ~k & 0xFF)
        return "~" + (p[0] if len(p) == 1 else "(" + " | ".join(p) + ")")
    p = names(reg, k)
    return p[0] if len(p) == 1 else "(" + " | ".join(p) + ")"

REGS = "|".join(sorted(bits, key=len, reverse=True))
NUM = r"(0x[0-9a-f]+|\d+)"
VAR = r"[bcu]Var\d+"
pat = re.compile(
    rf"(?P<store>\b(?P<sreg>{REGS})\s*=\s*(?P<svar>{VAR})\s*(?P<sop>[&|])\s*{NUM}(?=\s*;))"
    rf"|(?P<full>\b(?P<freg>{REGS})\s*=\s*(?P<fk>0x[0-9a-f]+|[1-9]\d*)(?=\s*;))"
    rf"|(?P<bind>\b(?P<bvar>{VAR})\s*=\s*(?P<breg>{REGS})(?=\s*[;,)]))"
    rf"|(?P<assign>\b(?P<avar>{VAR})\s*=(?!=))"
    rf"|(?P<test>\b(?P<tvar>{VAR})\s*(?P<top>[&|])\s*(?P<tk>0x[0-9a-f]+|\d+)\b)")

changed = 0
def transform(text):
    global changed
    bound = {}
    out = []
    for line in text.split("\n"):
        if line.startswith("//"):
            out.append(line); continue
        def sub(m):
            global changed
            if m.group("store"):
                reg, var, op = m.group("sreg"), m.group("svar"), m.group("sop")
                k = int(m.group(5), 0)
                changed += 1
                return f"{reg} = {var} {op} {render(reg, op, k)}"
            if m.group("full"):
                reg, k = m.group("freg"), int(m.group("fk"), 0)
                changed += 1
                return f"{reg} = {render(reg, '|', k)}"
            if m.group("bind"):
                bound[m.group("bvar")] = m.group("breg"); return m.group(0)
            if m.group("assign"):
                bound.pop(m.group("avar"), None); return m.group(0)
            var, op, k = m.group("tvar"), m.group("top"), int(m.group("tk"), 0)
            reg = bound.get(var)
            if reg is None or k == 0:
                return m.group(0)
            changed += 1
            return f"{var} {op} {render(reg, op, k)}"
        out.append(pat.sub(sub, line))
    return "\n".join(out)

