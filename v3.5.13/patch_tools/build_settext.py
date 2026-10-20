# v3.5.13: add `settext=YOUR TEXT` shell command that stores a custom string in free EEPROM (0x130..0x14F).
# Stage 1 = the command + EEPROM storage (this file). The display overdraw is added in build_settext2.py.
# Reuses the unused `ex` command slot (like the par patch). Text region: EEPROM 0x130, max 24 chars, NUL-terminated.
import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm
SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/tmp/settext1.hex"
mem=parse(SRC)
prog={a:mem.get(a) for a in range(0x10000)}
TEXT_EE=0x130  # EEADR=0x30, EEADRH=1

lines=["ORG 0xFF5E",
 'settext_str:', 'DB 0x73,0x65,0x74,0x74,0x65,0x78,0x74,0x00',  # "settext\0"
 "settext_code:",
 "  LFSR 0, 0x11A",          # FSR0 -> shell line buffer
 "st_find:",
 "  MOVF 0xEE, W",            # W = *FSR0++ (the shell replaced '=' with NUL)
 "  BNZ st_find",            # scan to the NUL that ends the command word
 # FSR0 now points at the first argument char (the custom text)
 "  MOVLW 0x30",
 "  MOVWF 0xFA9",            # EEADR = 0x30
 "  MOVLW 0x01",
 "  MOVWF 0xFAA",            # EEADRH = 1  -> address 0x130
 "  MOVLW 0x14",             # max 20 chars
 "  MOVWF 0x15",
 "st_loop:",
 "  MOVF 0xEE, W",            # W = *FSR0++
 "  MOVWF 0x14",
 "  MOVLW 0x20",
 "  SUBWF 0x14, W",          # char-0x20 ; C if char>=0x20
 "  BNC st_term",            # control char / end -> terminate
 "  RCALL eew",
 "  INCF 0xFA9, F",          # EEADR++
 "  DECFSZ 0x15, F",
 "  BRA st_loop",
 "st_term:",
 "  CLRF 0x14",
 "  RCALL eew",              # write NUL terminator
 "  GOTO 0x7E1C",            # shell success -> prints OK
 "eew:",                     # write byte in 0x14 to EEPROM[EEADRH:EEADR]
 "  MOVF 0x14, W",
 "  MOVWF 0xFA8",            # EEDATA
 "  BSF 0xFA6, 2",           # EECON1.WREN
 "  BCF 0xFF2, 7",           # GIE off
 "  MOVLW 0x55",
 "  MOVWF 0xFA7",            # EECON2
 "  MOVLW 0xAA",
 "  MOVWF 0xFA7",
 "  BSF 0xFA6, 1",           # EECON1.WR
 "eew_wait:",
 "  BTFSC 0xFA6, 1",
 "  BRA eew_wait",
 "  BSF 0xFF2, 7",           # GIE on
 "  RETURN",
]
code,labels=asm(lines)
top=[a for a in code]
print(f"code 0x{min(top):04X}..0x{max(top):04X} used {max(top)-0xFF5E+1} bytes (limit 162)")
for k in ("settext_str","settext_code","eew"): print(f"  {k}=0x{labels[k]:04X}")

patches={}
patches[0xFE2A]=labels['settext_str']&0xFF   # ex table entry -> "settext"
patches[0xFE2B]=(labels['settext_str']>>8)&0xFF
g,_=asm([f"ORG 0x7B70","GOTO settext_code"],labels)  # ex switch case -> GOTO settext_code
for a in range(0x7B70,0x7B74): patches[a]=g[a]

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
