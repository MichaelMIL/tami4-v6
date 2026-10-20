# v3.5.13: settext=TEXT (custom idle text) + replace "Strauss Water" logo with that text (blank if empty).
# Reuses `ex` command slot for settext; patches 0x431C (brand draw CALL 0xF67E) -> our text draw.
# Font: built-in 5x8 ASCII at 0x6C88. LCD cmd/data: 0xD8C0/0xD8E4. Text EEPROM: 0x130 (20 chars).
import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/tmp/logo.hex"
mem=parse(SRC); prog={a:mem.get(a) for a in range(0x10000)}
PAGE=0xB3  # LCD page for the text (tune on unit)
XPOS=0x1E  # fixed start column (tune on unit)

lines=["ORG 0xFF5E",
 'sstr:', 'DB 0x73,0x65,0x74,0x74,0x65,0x78,0x74,0x00',   # "settext\0"
 # ---- settext command ----
 "scode:",
 "  LFSR 0, 0x11A",
 "sf:", "  MOVF 0xEE, W", "  BNZ sf",       # scan to NUL after command word -> FSR0 at text
 "  RCALL seeadr",                          # EEADR=0x130
 "sl:",
 "  MOVF 0xEE, W", "  MOVWF 0x14",
 "  MOVLW 0x20", "  SUBWF 0x14, W", "  BNC sterm",
 "  RCALL eew", "  INCF 0xFA9, F", "  BRA sl",
 "sterm:", "  CLRF 0x14", "  RCALL eew", "  GOTO 0x7E1C",
 "eew:",                                    # write 0x14 -> EEPROM[EEADRH:EEADR]
 "  MOVF 0x14, W", "  MOVWF 0xFA8",
 "  BSF 0xFA6, 2", "  BCF 0xFF2, 7",
 "  MOVLW 0x55", "  MOVWF 0xFA7", "  MOVLW 0xAA", "  MOVWF 0xFA7",
 "  BSF 0xFA6, 1",
 "ew:", "  BTFSC 0xFA6, 1", "  BRA ew",
 "  BSF 0xFF2, 7", "  RETURN",
 "seeadr:",                                 # EEADR=0x30, EEADRH=1 (addr 0x130)
 "  MOVLW 0x30", "  MOVWF 0xFA9", "  MOVLW 0x01", "  MOVWF 0xFAA", "  RETURN",
 # ---- logo text draw (replaces CALL 0xF67E). Empty text -> nothing drawn (blank). ----
 # Fixed start x = XPOS (col low/high precomputed); LCD auto-advances the column.
 "logo:",
 "  RCALL seeadr",                          # EEADR=0x130
 f"  MOVLW 0x{PAGE:02X}", "  RCALL cmd",     # page
 f"  MOVLW 0x{XPOS&0x0F:02X}", "  RCALL cmd",        # column low = XPOS & 0x0F
 f"  MOVLW 0x{0x10|((XPOS>>4)&0x0F):02X}", "  RCALL cmd",  # column high = 0x10|(XPOS>>4)
 "dl:", "  BSF 0xFA6,0", "  MOVF 0xFA8,W", "  BZ done", "  MOVWF 0x18",
 "  MOVLW 0x05", "  MULWF 0x18",
 "  MOVLW 0x88", "  ADDWF 0xF3,W", "  MOVWF 0xFF6",
 "  MOVLW 0x6C", "  ADDWFC 0xF4,W", "  MOVWF 0xFF7",
 "  MOVLW 0x05", "  MOVWF 0x19",
 "cc:", "  TBLRD*+", "  MOVF 0xFF5,W", "  RCALL dat", "  DECFSZ 0x19,F", "  BRA cc",
 "  MOVLW 0x00", "  RCALL dat",
 "  INCF 0xFA9,F", "  BRA dl",
 "done:", "  RETURN",
 "cmd:", "  MOVWF 0xFE6", "  CALL 0xD8C0", "  MOVF 0xFE5,F", "  RETURN",
 "dat:", "  MOVWF 0xFE6", "  CALL 0xD8E4", "  MOVF 0xFE5,F", "  RETURN",
]
code,labels=asm(lines)
used=max(code)-0xFF5E+1
print(f"code 0x{min(code):04X}..0x{max(code):04X} used {used}/162 bytes {'OK' if used<=162 else 'OVERFLOW'}")
assert max(code)<=0xFFFF

patches={}
patches[0xFE2A]=labels['sstr']&0xFF; patches[0xFE2B]=(labels['sstr']>>8)&0xFF   # ex slot -> settext
g,_=asm(["ORG 0x7B70","GOTO scode"],labels)
for a in range(0x7B70,0x7B74): patches[a]=g[a]
g,_=asm(["ORG 0x431C","CALL logo"],labels)                                     # brand draw -> logo text
for a in range(0x431C,0x4320): patches[a]=g[a]

for a,b in code.items(): prog[a]=b
for a,b in patches.items(): prog[a]=b
changed={a:prog[a] for a in range(0x10000) if mem.get(a)!=prog.get(a)}
print(f"changed program bytes: {len(changed)}")
lines_out=[]; base=0
for line in open(SRC):
    raw=line.rstrip("\n").rstrip("\r")
    if not raw or raw[0]!=':': lines_out.append(raw); continue
    bb=bytes.fromhex(raw[1:]); n=bb[0]; addr=bb[1]<<8|bb[2]; typ=bb[3]; data=bytearray(bb[4:4+n])
    if typ==4: base=(bb[4]<<8|bb[5])<<16
    if typ==0 and (base>>16)==0:
        t=False
        for i in range(n):
            if addr+i in changed: data[i]=changed[addr+i]; t=True
        if t:
            rec=bytes([n,(addr>>8)&0xFF,addr&0xFF,0])+bytes(data); chk=(-sum(rec))&0xFF
            lines_out.append(":"+rec.hex().upper()+f"{chk:02X}"); continue
    lines_out.append(raw)
open(OUT,"w").write("\n".join(lines_out)+"\n")
print("wrote",OUT)
