# v3.5.13 settext + display overdraw (ROUND 1, photo-iteration).
# settext=TEXT -> EEPROM 0x130; idle screen center overdrawn with that text via text_draw_char.
import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/tmp/settext2.hex"
mem=parse(SRC); prog={a:mem.get(a) for a in range(0x10000)}

# round-1 position (tune via photo):
ROW=0x03   # text_row = LCD page 3
XPOS=0x14  # text_x = 20

lines=["ORG 0xFF5E",
 'settext_str:', 'DB 0x73,0x65,0x74,0x74,0x65,0x78,0x74,0x00',  # "settext\0"
 "settext_code:",
 "  LFSR 0, 0x11A",
 "st_find:",
 "  MOVF 0xEE, W",            # *FSR0++ ; scan to NUL after command word
 "  BNZ st_find",
 "  MOVLW 0x30",
 "  MOVWF 0xFA9",            # EEADR=0x30
 "  MOVLW 0x01",
 "  MOVWF 0xFAA",            # EEADRH=1 -> 0x130
 "  MOVLW 0x14",             # max 20 chars
 "  MOVWF 0x15",
 "st_loop:",
 "  MOVF 0xEE, W",
 "  MOVWF 0x14",
 "  MOVLW 0x20",
 "  SUBWF 0x14, W",
 "  BNC st_term",
 "  RCALL eew",
 "  INCF 0xFA9, F",
 "  DECFSZ 0x15, F",
 "  BRA st_loop",
 "st_term:",
 "  CLRF 0x14",
 "  RCALL eew",
 "  GOTO 0x7E1C",
 "eew:",                     # write 0x14 -> EEPROM[EEADRH:EEADR]
 "  MOVF 0x14, W",
 "  MOVWF 0xFA8",
 "  BSF 0xFA6, 2",
 "  BCF 0xFF2, 7",
 "  MOVLW 0x55",
 "  MOVWF 0xFA7",
 "  MOVLW 0xAA",
 "  MOVWF 0xFA7",
 "  BSF 0xFA6, 1",
 "eew_wait:",
 "  BTFSC 0xFA6, 1",
 "  BRA eew_wait",
 "  BSF 0xFF2, 7",
 "  RETURN",
 # ---- display: wrapper replaces clock_draw at hooked sites ----
 "logo_wrap:",
 "  CALL 0x2166",            # ui_c18_prologue (save FSR2, FSR2=FSR1) - keep frame valid
 "  CALL 0xA312",            # clock_draw (temps + brand/clock)
 "  RCALL logo_draw",        # overlay custom text
 "  GOTO 0x21D8",            # ui_c18_epilogue (restore FSR2, return)
 "logo_draw:",
 "  MOVLB 0x0E",
 f"  MOVLW 0x{ROW:02X}",
 "  MOVWF @0x03",            # text_row (0xE03)
 f"  MOVLW 0x{XPOS:02X}",
 "  MOVWF @0x04",            # text_x (0xE04)
 "  CLRF @0x00",             # text_flags=0
 "  MOVLW 0x30",
 "  MOVWF 0xFA9",            # EEADR=0x30
 "  MOVLW 0x01",
 "  MOVWF 0xFAA",            # EEADRH=1
 "ld_loop:",
 "  BSF 0xFA6, 0",           # EECON1.RD
 "  MOVF 0xFA8, W",          # W=EEDATA (char)
 "  BZ ld_done",             # NUL terminator -> done
 "  MOVWF 0xFE6",            # push char (POSTINC1)
 "  CALL 0x93C6",            # text_draw_char
 "  MOVF 0xFE5, F",          # pop (POSTDEC1)
 "  INCF 0xFA9, F",          # EEADR++
 "  BRA ld_loop",
 "ld_done:",
 "  RETURN",
]
code,labels=asm(lines)
used=max(code)-0xFF5E+1
print(f"code 0x{min(code):04X}..0x{max(code):04X} used {used}/162 bytes")
for k in ("settext_code","logo_wrap","logo_draw"): print(f"  {k}=0x{labels[k]:04X}")
assert max(code)<=0xFFFF

patches={}
patches[0xFE2A]=labels['settext_str']&0xFF   # ex slot -> "settext"
patches[0xFE2B]=(labels['settext_str']>>8)&0xFF
g,_=asm(["ORG 0x7B70","GOTO settext_code"],labels)
for a in range(0x7B70,0x7B74): patches[a]=g[a]
# hook clock_draw at 0x3c4c and 0x483e -> logo_wrap
for site in (0x3C4C,0x483E):
    g,_=asm([f"ORG 0x{site:04X}","CALL logo_wrap"],labels)
    for a in range(site,site+4): patches[a]=g[a]

for a,b in code.items(): prog[a]=b
for a,b in patches.items(): prog[a]=b
changed={a:prog[a] for a in range(0x10000) if mem.get(a)!=prog.get(a)}
print(f"changed program bytes: {len(changed)}  (EEPROM/config/vectors untouched)")

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
