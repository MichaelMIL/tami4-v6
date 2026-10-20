# v3.5.13 COMBINED: par (edit parameters) + settext (custom idle text replacing the logo), in ONE image.
# Grows the command table 19->21 (par=index19, settext=index20). par + EEPROM helpers live in the erased
# flash tail; settext + the text-draw live in the reclaimed "Strauss Water" bitmap (0x950A-0x95D5, dead once
# both brand-draw sites 0x431C/0xAE28 are repointed to our text draw). Font 0x6C88 (5x8 ASCII). No firmware
# range-check on par writes (the GUI warns).
import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/tmp/both.hex"
mem=parse(SRC); prog={a:mem.get(a) for a in range(0x10000)}
PAGE=0xB3; XPOS=0x1E
ORIG_PTRS=[0x6C82,0x6C7D,0x6C77,0x6C70,0x6C6C,0x6C67,0x6C63,0x6C60,0x6C5C,0x6C4F,
           0x6C3D,0x6C36,0x6C1D,0x6C10,0x6BFE,0x6BEA,0x6BDD,0x6BD0,0x6BCA]
NEWTABLE=0xFF5E

lines=[f"ORG 0x{NEWTABLE:X}", "newtable:",
 "PTR "+",".join(f"0x{p:X}" for p in ORIG_PTRS)+",par_str,settext_str",
 'par_str:', 'DB 0x70,0x61,0x72,0x00',                         # "par\0"
 'settext_str:', 'DB 0x73,0x65,0x74,0x74,0x65,0x78,0x74,0x00', # "settext\0"
 "newdisp:",
 "  MOVLB 1",
 "  MOVF @0x09,W", "  XORLW 0x14", "  BNZ nd_par",   # index 20 = settext
 "  GOTO scode",
 "nd_par:",
 "  MOVF @0x09,W", "  XORLW 0x13", "  BZ pcmd",       # index 19 = par
 "  MOVLB 2", "  MOVLW 0x85", "  GOTO 0x7E26",        # unknown command
 "pcmd:",                                             # bank1 active
 "  MOVF @0x3E,W", "  BNZ perr",
 "  MOVLW 0x4D", "  SUBWF @0x3D,W", "  BC perr",
 "  DECF @0x41,W", "  BZ pread",
 "  MOVLW 0x02", "  SUBWF @0x41,W", "  BNZ perr",
 "  MOVF @0x3F,W", "  MOVWF 0x14",
 "  MOVF @0x3D,W", "  CALL ee_write",
 "  GOTO 0x7E1C",
 "pread:",
 "  MOVF @0x3D,W", "  CALL ee_read", "  MOVWF 0x14",
 "  CLRF 0xFE6", "  MOVF 0x14,W", "  CALL 0x848E",
 "  GOTO 0x7E1C",
 "perr:", "  GOTO 0x7E28",
 # ---- reclaimed brand bitmap region: par EEPROM helpers + settext + text draw ----
 "ORG 0x950A",
 "ee_read:",   # W=addr -> W=value (EEADRH=0)
 "  MOVWF 0xA9", "  CLRF 0xAA", "  BSF 0xA6,0", "  MOVF 0xA8,W", "  RETURN",
 "ee_write:",  # W=addr, 0x14=value (EEADRH=0)
 "  MOVWF 0xA9", "  CLRF 0xAA", "  MOVF 0x14,W", "  MOVWF 0xA8",
 "  BSF 0xA6,2", "  BCF 0xF2,7", "  MOVLW 0x55", "  MOVWF 0xA7", "  MOVLW 0xAA", "  MOVWF 0xA7", "  BSF 0xA6,1",
 "eew:", "  BTFSC 0xA6,1", "  BRA eew", "  BSF 0xF2,7", "  RETURN",
 "scode:",
 "  LFSR 0, 0x11A",
 "sf:", "  MOVF 0xEE, W", "  BNZ sf",
 "  RCALL seeadr",
 "sl:", "  MOVF 0xEE, W", "  MOVWF 0x14",
 "  MOVLW 0x20", "  SUBWF 0x14, W", "  BNC sterm",
 "  RCALL teew", "  INCF 0xFA9, F", "  BRA sl",
 "sterm:", "  CLRF 0x14", "  RCALL teew", "  GOTO 0x7E1C",
 "teew:",   # write 0x14 -> EEPROM[EEADRH:EEADR]
 "  MOVF 0x14, W", "  MOVWF 0xFA8",
 "  BSF 0xFA6, 2", "  BCF 0xFF2, 7",
 "  MOVLW 0x55", "  MOVWF 0xFA7", "  MOVLW 0xAA", "  MOVWF 0xFA7", "  BSF 0xFA6, 1",
 "tew:", "  BTFSC 0xFA6, 1", "  BRA tew", "  BSF 0xFF2, 7", "  RETURN",
 "seeadr:", "  MOVLW 0x30", "  MOVWF 0xFA9", "  MOVLW 0x01", "  MOVWF 0xFAA", "  RETURN",
 "logo:",
 "  RCALL seeadr",
 f"  MOVLW 0x{PAGE:02X}", "  RCALL cmd",
 f"  MOVLW 0x{XPOS&0x0F:02X}", "  RCALL cmd",
 f"  MOVLW 0x{0x10|((XPOS>>4)&0x0F):02X}", "  RCALL cmd",
 "dl:", "  BSF 0xFA6,0", "  MOVF 0xFA8,W", "  BZ ldone", "  MOVWF 0x18",
 "  MOVLW 0x05", "  MULWF 0x18",
 "  MOVLW 0x88", "  ADDWF 0xF3,W", "  MOVWF 0xFF6",
 "  MOVLW 0x6C", "  ADDWFC 0xF4,W", "  MOVWF 0xFF7",
 "  MOVLW 0x05", "  MOVWF 0x19",
 "cc:", "  TBLRD*+", "  MOVF 0xFF5,W", "  RCALL dat", "  DECFSZ 0x19,F", "  BRA cc",
 "  MOVLW 0x00", "  RCALL dat",
 "  INCF 0xFA9,F", "  BRA dl",
 "ldone:", "  RETURN",
 "cmd:", "  MOVWF 0xFE6", "  CALL 0xD8C0", "  MOVF 0xFE5,F", "  RETURN",
 "dat:", "  MOVWF 0xFE6", "  CALL 0xD8E4", "  MOVF 0xFE5,F", "  RETURN",
]
code,labels=asm(lines)
top=[a for a in code if a>=0xFF00]; bm=[a for a in code if 0x950A<=a<0x9600]
print(f"top region 0x{min(top):04X}-0x{max(top):04X} used {max(top)-NEWTABLE+1}/{0xFFFF-NEWTABLE+1} {'OK' if max(top)<=0xFFFF else 'OVERFLOW'}")
print(f"bitmap region 0x{min(bm):04X}-0x{max(bm):04X} used {max(bm)-0x950A+1}/{0x95D5-0x950A+1} {'OK' if max(bm)<=0x95D5 else 'OVERFLOW'}")
for k in ("newdisp","pcmd","scode","logo","ee_write","teew"): print(f"  {k}=0x{labels[k]:04X}")
def free(a): return (0xFF5D<=a<=0xFFFF) or (0x950A<=a<=0x95D5)
bad=[hex(a) for a in code if not free(a)]; print("collisions:",bad); assert not bad

patches={}
patches[0x8414]=0x15                              # match limit 19 -> 21
patches[0x7B2E]=0x15                              # ls printed count 19 -> 21
patches[0x83E0]=NEWTABLE&0xFF; patches[0x83E4]=(NEWTABLE>>8)&0xFF   # table base
for (org,) in [(0x7E22,)]:
    g,_=asm([f"ORG 0x{org:04X}","GOTO newdisp"],labels)
    for a in range(org,org+4): patches[a]=g[a]
for site in (0x431C,0xAE28):                      # both brand-draw CALL 0xF67E -> CALL logo
    g,_=asm([f"ORG 0x{site:04X}","CALL logo"],labels)
    for a in range(site,site+4): patches[a]=g[a]

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
