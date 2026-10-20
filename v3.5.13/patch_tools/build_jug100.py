# Build a v3.5.13 image whose jug (QTYJUGWATER) menu editor displays x100 (1000, not 100).
# Trade-off vs build_combined.py: this build has NO `par` serial command. The freed flash holds
# jug-specific x100 clones of the editor's display-scale, min/max-scale and save-conversion routines
# (the stock editor hardcodes x10, shared by all quantity editors, so cold/hot must stay x10).
import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5.13-jug1000.hex"
mem=parse(SRC)
prog={a:mem.get(a) for a in range(0x10000)}

lines=["ORG 0xFF5E",
 # ---- jug quantity edit handler (x100), param 0x43 ----
 "jug_qty:",
 "  MOVLW 0x43",
 "  CALL 0x23EC",          # load raw value -> [0x1F5:0x1F6]
 "  MOVLW 0x43",
 "  CALL jug_minmax",      # min/max x100 -> [0x1F5:0x1F8]
 "  MOVLW 0x43",
 "  CALL jug_disp",        # display value x100 -> [0x1F1:0x1F2]
 "  MOVLW jug_oe",         # on_enter ptr low
 "  MOVWF @0xC5",
 "  MOVLW jug_oe_hi",      # on_enter ptr high (two-pass substituted)
 "  GOTO 0x245C",          # install editor (cold-style callbacks) + run
 "jug_oe:",                # on_enter: save edited value /100 to param 0x43
 "  CALL jug_save",
 "  MOVLW 0x43",
 "  GOTO 0x2840",
 # ---- jug_disp: clone of 0x2A4A (display setup) but x100 instead of x10 ----
 "jug_disp:",              # entered with W = param index
 "  CALL 0x285C",          # [0x1F1:0x1F2] = raw value
 "  MOVLW 0x64",
 "  CALL 0x29B4",          # [0x1F1:0x1F2] *= 100
 "  CALL 0x1FB0",          # (as 0x2A4A) render/limit setup
 "  CALL 0x1EA6",
 "  MOVLB 1",
 "  RETURN",
 # ---- jug_save: clone of 0x294A (save conversion) but /100 instead of /10 ----
 "jug_save:",
 "  MOVLW 0x64",
 "  CALL 0x233A",          # [0x8:0x9] = [0x1F1:0x1F2] / 100
 "  MOVFF 0x8, 0xFE6",     # push raw value for 0x2840 to write
 "  RETURN",
 # ---- jug_minmax: clone of 0x2200 (min/max load) using mm100 (x100) instead of 0x2864 ----
 "jug_minmax:",            # entered with W = param index
 "  CALL mm100",
 "  CALL 0x2824",
 "  GOTO 0x2BBE",
 # ---- mm100: exact clone of 0x2864 with scale 0x0A -> 0x64 (two spots), RCALL->CALL ----
 "mm100:",                 # entered with W = param index
 "  CALL 0x2BB2",          # W = max (EEPROM[idx+0x4D])
 "  MOVWF @0xF7",
 "  CLRF @0xF8",
 "  MOVLW 0x64",
 "  MULWF @0xF6",
 "  MOVFF 0xFF3, 0x1F6",
 "  MULWF @0xF5",
 "  MOVFF 0xFF3, 0x1F5",
 "  MOVF 0xF4, W",         # PRODH
 "  ADDWF @0xF6, F",
 "  MOVLW 0x64",
 "  MULWF @0xF8",
 "  MOVFF 0xFF3, 0x1F8",
 "  MULWF @0xF7",
 "  MOVFF 0xFF3, 0x1F7",
 "  MOVF 0xF4, W",
 "  ADDWF @0xF8, F",
 "  CLRF 0xE6",            # CLRF POSTINC1 (push 0)
 "  RETURN",
 # ---- menu labels (same as combined build) ----
 "jug_label:",            # EN "JUG WATER QTY." compressed menu string
 "DB 0x4A,0x55,0x47,0x20,0x01,0x01,0x20,0x01,0x1C,0x00",
 "jug_label_he:",         # HE jug/water
 "DB 0xEF,0xF7,0xF0,0xF7,0x20,0x01,0x07,0x00",
]
# two-pass for jug_oe high byte
lines1=[l.replace("MOVLW jug_oe_hi","MOVLW 0x00") for l in lines]
_,labels=asm(lines1)
oe=labels['jug_oe']
lines2=[l.replace("MOVLW jug_oe_hi", f"MOVLW 0x{(oe>>8)&0xFF:02X}") for l in lines]
code,labels=asm(lines2)

top=[a for a in code]
print(f"code 0x{min(top):04X}..0x{max(top):04X} (region 0xFF5E-0xFFFF) {'OK' if max(top)<=0xFFFF and min(top)>=0xFF5E else 'OVERFLOW'}  used {max(top)-0xFF5E+1}/{0xFFFF-0xFF5E+1} bytes")
for k in ("jug_qty","jug_oe","jug_disp","jug_save","jug_minmax","mm100","jug_label","jug_label_he"):
    print(f"  {k}=0x{labels[k]:04X}")
assert all(0xFF5E<=a<=0xFFFF for a in code), "code outside free region"

# ---- menu byte patches (identical to combined build; par-related patches omitted) ----
patches={}
patches[0xE3A1]=0x06                       # WATER-QTY menu item count 5 -> 6
patches[0xE3A8]=0x36                        # 6th item name byte -> 0x36 (JUG label index)
patches[0xE3C4]=labels['jug_qty']&0xFF      # 6th action ptr -> jug_qty
patches[0xE3C5]=(labels['jug_qty']>>8)&0xFF
patches[0xF2DC]=labels['jug_label']&0xFF    # EN name-table[0x36] -> jug_label
patches[0xF2DD]=(labels['jug_label']>>8)&0xFF
patches[0xEFBA]=labels['jug_label_he']&0xFF # HE name-table[0x36] -> jug_label_he
patches[0xEFBB]=(labels['jug_label_he']>>8)&0xFF

for a,bb in code.items(): prog[a]=bb
for a,bb in patches.items(): prog[a]=bb

changed={a:prog[a] for a in range(0x10000) if mem.get(a)!=prog.get(a)}
print(f"\nchanged program bytes: {len(changed)}  (EEPROM/config/vectors untouched)")

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
print(f"wrote {OUT}")
