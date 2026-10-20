import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5.13-par-jug.hex"
mem=parse(SRC)
prog={a:mem.get(a) for a in range(0x10000)}

# ---- new code in top erased region 0xFF5E-0xFFFF ----
lines=["ORG 0xFF5E",
 'par_str:', 'DB 0x70,0x61,0x72,0x00',      # "par\0"
 "par_code:",                                # reached via ex switch case (args already parsed)
 "  MOVLB 1",
 "  MOVF @0x3E,W",     # index high must be 0
 "  BNZ perr",
 "  MOVLW 0x4D",
 "  SUBWF @0x3D,W",    # idx-77 ; C if idx>=77
 "  BC perr",
 "  DECF @0x41,W",     # argcount-1 ; Z if ==1 (read)
 "  BZ pread",
 "  MOVLW 0x02",
 "  SUBWF @0x41,W",    # argcount-2 ; Z if ==2 (write)
 "  BNZ perr",
 "  MOVF @0x3F,W",     # value (arg2 low) ; NO min/max check (GUI enforces)
 "  MOVWF 0x14",
 "  MOVF @0x3D,W",     # addr = idx
 "  CALL ee_write",
 "  GOTO 0x7E1C",
 "pread:",
 "  MOVF @0x3D,W",
 "  CALL ee_read",     # W=value
 "  MOVWF 0x14",
 "  CLRF 0xFE6",       # push field-width 0
 "  MOVF 0x14,W",
 "  CALL 0x848E",      # print value + newline
 "  GOTO 0x7E1C",
 "perr:",
 "  GOTO 0x7E28",
 "ee_read:",           # W=addr -> W=value
 "  MOVWF 0xA9",
 "  CLRF 0xAA",
 "  BSF 0xA6,0",
 "  MOVF 0xA8,W",
 "  RETURN",
 "ee_write:",          # W=addr, 0x14=value
 "  MOVWF 0xA9",
 "  CLRF 0xAA",
 "  MOVF 0x14,W",
 "  MOVWF 0xA8",
 "  BSF 0xA6,2",
 "  BCF 0xF2,7",
 "  MOVLW 0x55",
 "  MOVWF 0xA7",
 "  MOVLW 0xAA",
 "  MOVWF 0xA7",
 "  BSF 0xA6,1",
 "eew:",
 "  BTFSC 0xA6,1",
 "  BRA eew",
 "  BSF 0xF2,7",
 "  RETURN",
 # jug quantity edit handler: clone of COLD qty (0x0CB0 body) with param 0x43
 "jug_qty:",
 "  MOVLW 0x43",
 "  CALL 0x23EC",               # load value for editor
 "  MOVLW 0x43",
 "  CALL 0x2200",               # load min/bounds
 "  MOVLW 0x43",
 "  CALL 0x2A4A",               # display setup (as COLD qty)
 "  MOVLW jug_oe",              # on_enter ptr low  (assembler emits low byte via DB? need lit)
 "  MOVWF @0xC5",
 "  MOVLW jug_oe_hi",
 "  GOTO 0x245C",
 "jug_oe:",                     # on_enter: save edited value to param 0x43
 "  CALL 0x294A",
 "  MOVLW 0x43",
 "  GOTO 0x2840",
 "jug_label:",                 # EN "JUG WATER QTY." compressed menu string
 "DB 0x4A,0x55,0x47,0x20,0x01,0x01,0x20,0x01,0x1C,0x00",
 "jug_label_he:",              # HE: QTY + jug(קנקן) + WATER  -> displays "מים קנקן כמות"
 "DB 0xEF,0xF7,0xF0,0xF7,0x20,0x01,0x07,0x00",
]
# We need MOVLW with low/high byte of a label. asm MOVLW takes a literal; emit via resolve of label then &0xFF.
# Patch: our asm 'lit' does resolve(o)&0xFF, so MOVLW jug_oe -> low byte. For high byte we need (jug_oe>>8).
# Add a pseudo: we'll post-process. Simpler: assemble twice - first to get jug_oe addr, then substitute.
# Do a two-pass: assemble to get labels, then replace 'jug_oe_hi' with the numeric high byte.
# pass1 with placeholder high byte
lines1=[l.replace("MOVLW jug_oe_hi","MOVLW 0x00") for l in lines]
_,labels=asm(lines1)
oe=labels['jug_oe']
lines2=[l.replace("MOVLW jug_oe_hi", f"MOVLW 0x{(oe>>8)&0xFF:02X}") for l in lines]
code,labels=asm(lines2)

# region check
top=[a for a in code if a>=0xFF00]
print(f"top used 0x{min(top):04X}..0x{max(top):04X} (limit 0xFFFF) {'OK' if max(top)<=0xFFFF else 'OVERFLOW'}")
for k in ("par_str","par_code","pread","perr","ee_read","ee_write","jug_qty","jug_oe"):
    print(f"  {k}=0x{labels[k]:04X}")
def is_free(a): return 0xFF5D<=a<=0xFFFF
bad=[hex(a) for a in code if not is_free(a)]
print("collisions:", bad)

# ---- byte patches ----
patches={}
# repoint ex table entry (index7) at 0xFE2A -> par_str
patches[0xFE2A]=labels['par_str']&0xFF
patches[0xFE2B]=(labels['par_str']>>8)&0xFF
# ex switch case 0x7B70 -> GOTO par_code
g,_=asm([f"ORG 0x7B70","GOTO par_code"],labels)
for a in range(0x7B70,0x7B74): patches[a]=g[a]
# menu record 0xE39F: n 5->6, name6 @0xE3A8=0x28 (borrowed COLD WATER QTY label), action5 @0xE3C4 -> jug_qty
patches[0xE3A1]=0x06
patches[0xE3A8]=0x28
patches[0xE3C4]=labels['jug_qty']&0xFF
patches[0xE3C5]=(labels['jug_qty']>>8)&0xFF
# real label: name byte 0x28 -> 0x36 (free index); EN phrase table[0x36] @0xF2DC -> jug_label
patches[0xE3A8]=0x36
patches[0xF2DC]=labels['jug_label']&0xFF
patches[0xF2DD]=(labels['jug_label']>>8)&0xFF
patches[0xEFBA]=labels['jug_label_he']&0xFF
patches[0xEFBB]=(labels['jug_label_he']>>8)&0xFF

for a,b in code.items(): prog[a]=b
for a,b in patches.items(): prog[a]=b
print("\npatches:")
print(f"  0xFE2A/2B ex-entry -> par_str 0x{labels['par_str']:04X}")
print(f"  0x7B70 ex-case -> GOTO par_code: "+" ".join(f"{patches[a]:02X}" for a in range(0x7B70,0x7B74)))
print(f"  0xE3A1 menu n: 05->06   0xE3A8 name6=0x36(JUG)   0xE3C4/C5 action5 -> jug_qty 0x{labels['jug_qty']:04X}")

# emit hex in-place patching original text
changed={a:prog[a] for a in range(0x10000) if mem.get(a)!=prog.get(a)}
print(f"\nchanged program bytes: {len(changed)}")
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
