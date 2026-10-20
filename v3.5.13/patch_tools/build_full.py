# v3.5.13 FULL: par (+read-all) + settext (logo text) + jug menu item (x100, shows 1000), one image (custom idle text replacing the logo), in ONE image.
# Grows the command table 19->21 (par=index19, settext=index20). par + EEPROM helpers live in the erased
# flash tail; settext + the text-draw live in the reclaimed "Strauss Water" bitmap (0x950A-0x95D5, dead once
# both brand-draw sites 0x431C/0xAE28 are repointed to our text draw). Font 0x6C88 (5x8 ASCII). No firmware
# range-check on par writes (the GUI warns).
import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/tmp/full.hex"
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
 "  MOVF @0x41,W", "  BNZ pc1", "  GOTO pall",          # no args -> read all
 "pc1:",
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
 "  MOVWF 0xA9", "  CLRF 0xAA", "  MOVF 0x14,W", "  MOVWF 0xA8", "  BRA wrstrobe",
 "scode:",
 "  LFSR 0, 0x11A",
 "sf:", "  MOVF 0xEE, W", "  BNZ sf",
 "  RCALL seeadr",
 "sl:", "  MOVF 0xEE, W", "  MOVWF 0x14",
 "  MOVLW 0x20", "  SUBWF 0x14, W", "  BNC sterm",
 "  RCALL teew", "  INCF 0xFA9, F", "  BRA sl",
 "sterm:", "  CLRF 0x14", "  RCALL teew", "  GOTO 0x7E1C",
 "teew:",   # write 0x14 -> EEPROM[EEADRH:EEADR]; EEADR/EEADRH preset by caller
 "  MOVF 0x14, W", "  MOVWF 0xFA8", "  BRA wrstrobe",
 "wrstrobe:",   # shared EEPROM byte-write strobe
 "  BSF 0xFA6, 2", "  BCF 0xFF2, 7",
 "  MOVLW 0x55", "  MOVWF 0xFA7", "  MOVLW 0xAA", "  MOVWF 0xFA7", "  BSF 0xFA6, 1",
 "ws:", "  BTFSC 0xFA6, 1", "  BRA ws", "  BSF 0xFF2, 7", "  RETURN",
 "seeadr:", "  MOVLW 0x30", "  MOVWF 0xFA9", "  MOVLW 0x01", "  MOVWF 0xFAA", "  RETURN",
 # Two-row idle text. Line separator = '|' (0x7C): bumps the LCD down 2 pages and
 # resets the column. Page tracked in 0x1A. (Uppercasing is done by the ESP before storing.)
 "logo:",
 "  RCALL seeadr",
 f"  MOVLW 0x{PAGE:02X}", "  MOVWF 0x1A", "  RCALL setpos",
 "dl:", "  BSF 0xFA6,0", "  MOVF 0xFA8,W", "  BZ ldone", "  MOVWF 0x18",
 "  MOVLW 0x7C", "  SUBWF 0x18,W", "  BZ lbrk",          # '|' -> next row
 "  MOVLW 0x05", "  MULWF 0x18",
 "  MOVLW 0x88", "  ADDWF 0xF3,W", "  MOVWF 0xFF6",
 "  MOVLW 0x6C", "  ADDWFC 0xF4,W", "  MOVWF 0xFF7",
 "  MOVLW 0x05", "  MOVWF 0x19",
 "cc:", "  TBLRD*+", "  MOVF 0xFF5,W", "  RCALL dat", "  DECFSZ 0x19,F", "  BRA cc",
 "  MOVLW 0x00", "  RCALL dat",
 "  INCF 0xFA9,F", "  BRA dl",
 "lbrk:", "  INCF 0xFA9,F", "  INCF 0x1A,F", "  INCF 0x1A,F", "  RCALL setpos", "  BRA dl",
 "ldone:", "  RETURN",
 "setpos:",                                              # LCD page=0x1A, column=XPOS
 "  MOVF 0x1A,W", "  RCALL cmd",
 f"  MOVLW 0x{XPOS&0x0F:02X}", "  RCALL cmd",
 f"  MOVLW 0x{0x10|((XPOS>>4)&0x0F):02X}", "  RCALL cmd",
 "  RETURN",
 "cmd:", "  MOVWF 0xFE6", "  CALL 0xD8C0", "  MOVF 0xFE5,F", "  RETURN",
 "dat:", "  MOVWF 0xFE6", "  CALL 0xD8E4", "  MOVF 0xFE5,F", "  RETURN",
 # ---- reclaimed brand-routine body 0xF67E-0xF735: read-all + x100 jug editor ----
 "ORG 0xF67E",
 "pall:",
 "  CLRF 0xA9", "  CLRF 0xAA",
 "pl:", "  BSF 0xA6,0", "  CLRF 0xFE6", "  MOVF 0xA8,W", "  CALL 0x848E",
 "  INCF 0xA9,F", "  MOVLW 0x4D", "  SUBWF 0xA9,W", "  BNC pl",
 "  GOTO 0x7E1C",
 "jug_qty:",
 "  MOVLW 0x43", "  CALL 0x23EC",
 "  MOVLW 0x43", "  CALL jug_minmax",
 "  MOVLW 0x43", "  CALL jug_disp",
 "  MOVLW jug_oe", "  MOVWF @0xC5", "  MOVLW jug_oe_hi", "  GOTO 0x245C",
 "jug_oe:", "  CALL jug_save", "  MOVLW 0x43", "  GOTO 0x2840",
 "jug_disp:",
 "  CALL 0x285C", "  MOVLW 0x64", "  CALL 0x29B4", "  CALL 0x1FB0", "  CALL 0x1EA6", "  MOVLB 1", "  RETURN",
 "jug_save:", "  MOVLW 0x64", "  CALL 0x233A", "  MOVFF 0x8, 0xFE6", "  RETURN",
 "jug_minmax:", "  CALL mm100", "  CALL 0x2824", "  GOTO 0x2BBE",
 "mm100:",
 "  CALL 0x2BB2", "  MOVWF @0xF7", "  CLRF @0xF8", "  MOVLW 0x64", "  MULWF @0xF6",
 "  MOVFF 0xFF3, 0x1F6", "  MULWF @0xF5", "  MOVFF 0xFF3, 0x1F5", "  MOVF 0xF4, W", "  ADDWF @0xF6, F",
 "  MOVLW 0x64", "  MULWF @0xF8", "  MOVFF 0xFF3, 0x1F8", "  MULWF @0xF7", "  MOVFF 0xFF3, 0x1F7",
 "  MOVF 0xF4, W", "  ADDWF @0xF8, F", "  CLRF 0xE6", "  RETURN",
 "jug_label:", "DB 0x4A,0x55,0x47,0x20,0x01,0x01,0x20,0x01,0x1C,0x00",
 "jug_label_he:", "DB 0xEF,0xF7,0xF0,0xF7,0x20,0x01,0x07,0x00",
]
lines1=[l.replace("MOVLW jug_oe_hi","MOVLW 0x00") for l in lines]
_,lab1=asm(lines1); oe=lab1["jug_oe"]
lines=[l.replace("MOVLW jug_oe_hi", f"MOVLW 0x{(oe>>8)&0xFF:02X}") for l in lines]
code,labels=asm(lines)
top=[a for a in code if a>=0xFF00]; bm=[a for a in code if 0x950A<=a<0x9600]
print(f"top region 0x{min(top):04X}-0x{max(top):04X} used {max(top)-NEWTABLE+1}/{0xFFFF-NEWTABLE+1} {'OK' if max(top)<=0xFFFF else 'OVERFLOW'}")
print(f"bitmap region 0x{min(bm):04X}-0x{max(bm):04X} used {max(bm)-0x950A+1}/{0x95D5-0x950A+1} {'OK' if max(bm)<=0x95D5 else 'OVERFLOW'}")
bb=[a for a in code if 0xF67E<=a<=0xF800]
print(f"brand-body region 0x{min(bb):04X}-0x{max(bb):04X} used {max(bb)-0xF67E+1}/{0xF735-0xF67E+1} {'OK' if max(bb)<=0xF735 else 'OVERFLOW'}")
for k in ("newdisp","pcmd","scode","logo","pall","jug_qty","mm100"): print(f"  {k}=0x{labels[k]:04X}")
def free(a): return (0xFF5D<=a<=0xFFFF) or (0x950A<=a<=0x95D5) or (0xF67E<=a<=0xF735)
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

patches[0xE3A1]=0x06
patches[0xE3A8]=0x36
patches[0xE3C4]=labels['jug_qty']&0xFF; patches[0xE3C5]=(labels['jug_qty']>>8)&0xFF
patches[0xF2DC]=labels['jug_label']&0xFF; patches[0xF2DD]=(labels['jug_label']>>8)&0xFF
patches[0xEFBA]=labels['jug_label_he']&0xFF; patches[0xEFBB]=(labels['jug_label_he']>>8)&0xFF
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
