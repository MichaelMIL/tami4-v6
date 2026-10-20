import sys; sys.path.insert(0,".")
from hexparse import parse
from asm import asm

SRC="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"
OUT=sys.argv[1] if len(sys.argv)>1 else "/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5.13-par-patch.hex"

mem=parse(SRC)
# mutable program image 0..0xFFFF
prog={a:mem.get(a) for a in range(0x10000)}

ORIG_PTRS=[0x6C82,0x6C7D,0x6C77,0x6C70,0x6C6C,0x6C67,0x6C63,0x6C60,0x6C5C,0x6C4F,
           0x6C3D,0x6C36,0x6C1D,0x6C10,0x6BFE,0x6BEA,0x6BDD,0x6BD0,0x6BCA]

NEWTABLE=0xFF5E   # even, in top free region
# Build the assembly listing. Everything in one asm() call so labels resolve.
lines=[]
# --- top region: table, string, newdisp, pcmd ---
lines += [f"ORG 0x{NEWTABLE:X}"]
lines += ["newtable:"]
# 20 entries: 0..18 original, 19 = par_str
lines += ["PTR "+",".join(f"0x{p:X}" for p in ORIG_PTRS)+",par_str"]
lines += ['par_str:', 'DB 0x70,0x61,0x72,0x00']   # "par\0"
# newdisp
lines += [
 "newdisp:",
 "  MOVLB 1",
 "  MOVF @0x09,W",      # index
 "  XORLW 0x13",        # ==19 (par)?
 "  BZ pcmd",
 "  MOVLB 2",
 "  MOVLW 0x85",        # unknown command
 "  GOTO 0x7E26",       # 0x7E26 = original 'MOVWF [0x2B6]' then falls into the error epilogue
]
# pcmd (combined read/write)
lines += [
 "pcmd:",
 "  MOVF @0x3E,W",      # index high must be 0
 "  BNZ perr",
 "  MOVLW 0x4D",
 "  SUBWF @0x3D,W",     # idx-77, C set if idx>=77
 "  BC perr",
 "  DECF @0x41,W",      # argcount-1 ; Z if ==1 (read)
 "  BZ pread",
 "  MOVLW 0x02",
 "  SUBWF @0x41,W",     # argcount-2 ; Z if ==2 (write)
 "  BNZ perr",
 "  MOVF @0x40,W",      # value high must be 0
 "  BNZ perr",
 "  MOVF @0x3F,W",      # value low
 "  MOVWF 0x14",        # 0x14 = value (access/bank0 scratch)
 "  MOVF @0x3D,W",      # idx
 "  ADDLW 0x4D",        # idx+0x4D (max addr)
 "  CALL ee_read",      # W=max
 "  MOVWF 0x15",
 "  MOVF 0x14,W",       # value
 "  SUBWF 0x15,W",      # max-value, C=0 if value>max
 "  BNC perr",
 "  MOVF @0x3D,W",
 "  ADDLW 0x9A",        # idx+0x9A (min addr)
 "  CALL ee_read",      # W=min
 "  MOVWF 0x15",
 "  MOVF 0x15,W",       # min
 "  SUBWF 0x14,W",      # value-min, C=0 if value<min
 "  BNC perr",
 "  MOVF @0x3D,W",      # addr=idx
 "  CALL ee_write",     # write 0x14 to EEPROM[idx]
 "  BRA psucc",         # success
 "pread:",
 "  MOVF @0x3D,W",      # idx
 "  CALL ee_read",      # W=value
 "  MOVWF 0x14",        # save value
 "  CLRF 0xFE6",        # push field-width byte (0) onto the C18 stack (POSTINC1)
 "  MOVF 0x14,W",       # W = value
 "  CALL 0x848E",       # print value + newline; pops 3 incl the width byte
 "psucc:",
 "  GOTO 0x7E1C",
 "perr:",
 "  GOTO 0x7E28",
 # ee_read lives in the top region too (0x9134 was referenced font data - unsafe)
 "ee_read:",            # W=addr(0..76) -> W=value
 "  MOVWF 0xA9",        # EEADR
 "  CLRF 0xAA",         # EEADRH=0 (EEPGD/CFGS are always 0: firmware never sets them)
 "  BSF 0xA6,0",        # RD=1
 "  MOVF 0xA8,W",       # W=EEDATA
 "  RETURN",
]
# --- old-table region: ee_write ---
lines += ["ORG 0xFE1C",
 "ee_write:",           # W=addr(0..255), 0x14=value
 "  MOVWF 0xA9",        # EEADR
 "  CLRF 0xAA",         # EEADRH=0
 "  MOVF 0x14,W",
 "  MOVWF 0xA8",        # EEDATA=value
 "  BCF 0xA6,7",        # EEPGD=0 (data EEPROM)
 "  BCF 0xA6,6",        # CFGS=0
 "  BSF 0xA6,2",        # WREN=1
 "  BCF 0xF2,7",        # GIE=0 (INTCON)
 "  MOVLW 0x55",
 "  MOVWF 0xA7",        # EECON2=0x55
 "  MOVLW 0xAA",
 "  MOVWF 0xA7",        # EECON2=0xAA
 "  BSF 0xA6,1",        # WR=1
 "eew_wait:",
 "  BTFSC 0xA6,1",      # wait WR clear
 "  BRA eew_wait",
 "  BSF 0xF2,7",        # GIE=1
 "  BCF 0xA6,2",        # WREN=0
 "  RETURN",
]

code,labels=asm(lines)

# region bounds check
def span(lbl_lo, lo, hi):
    pass
# compute extents per region
addrs=sorted(code)
# group contiguous
def region_end(start):
    a=start
    while a in code: a+=1
    return a
print("Labels:")
for k in ("newtable","par_str","newdisp","pcmd","pread","perr","ee_write","ee_read","eew_wait"):
    print(f"  {k} = 0x{labels[k]:04X}")
# region usage
top_end=max(a for a in code if a>=0xFF00)
print(f"top region used: 0x{NEWTABLE:04X}..0x{top_end:04X}  (limit 0xFFFF) -> {'OK' if top_end<=0xFFFF else 'OVERFLOW'}")
ew=[a for a in code if 0xFE1C<=a<=0xFE50]
print(f"ee_write used: 0x{min(ew):04X}..0x{max(ew):04X} (limit 0xFE41) -> {'OK' if max(ew)<=0xFE41 else 'OVERFLOW'}")

# collision check: ensure we only write to free/dead bytes
def is_free(a):
    if 0xFF5D<=a<=0xFFFF: return True          # top erased
    if 0xFE1C<=a<=0xFE41: return True           # reclaimed old table
    return False
bad=[a for a in code if not is_free(a)]
print("collision bytes (should be []):", [hex(a) for a in bad])

# ---- apply byte patches ----
patches={}
patches[0x8414]=0x14     # limit 19 -> 20
patches[0x83E0]=NEWTABLE & 0xFF   # table base low
patches[0x83E4]=(NEWTABLE>>8)&0xFF # table base high
# GOTO newdisp at 0x7E22
g,_=asm([f"ORG 0x7E22","GOTO newdisp"],labels)
for a in range(0x7E22,0x7E26): patches[a]=g[a]

# write code + patches into prog
for a,b in code.items(): prog[a]=b
for a,b in patches.items(): prog[a]=b

print("\nByte patches:")
print(f"  0x8414: 0x13 -> 0x{patches[0x8414]:02X}  (command count 19->20)")
print(f"  0x83E0: 0x1C -> 0x{patches[0x83E0]:02X}  (table base low)")
print(f"  0x83E4: 0xFE -> 0x{patches[0x83E4]:02X}  (table base high)")
print(f"  0x7E22..0x7E25: GOTO 0x{labels['newdisp']:04X} = "+" ".join(f"{patches[a]:02X}" for a in range(0x7E22,0x7E26)))

# ---- emit Intel HEX (full image: prog 0..FFFF, config, eeprom) ----
def emit_hex(fn):
    lines_out=[]
    def rec(addr,data,typ=0):
        n=len(data); s=n+((addr>>8)&0xFF)+(addr&0xFF)+typ+sum(data)
        chk=(-s)&0xFF
        return ":%02X%04X%02X%s%02X"%(n,addr&0xFFFF,typ,''.join('%02X'%b for b in data),chk)
    # program memory, grouped into 16-byte records, only emit addresses present in original OR patched
    present=set(a for a in range(0x10000) if mem.get(a) is not None or a in code or a in patches)
    cur_upper=None
    a=0
    while a<0x10000:
        if a not in present: a+=1; continue
        # gather run of up to 16 contiguous present bytes
        run=[]
        start=a
        while a<0x10000 and a in present and len(run)<16:
            run.append(prog[a]&0xFF); a+=1
        up=(start>>16)&0xFFFF
        lines_out.append(rec(start&0xFFFF,run,0))
    # config words 0x300000.. and EEPROM 0xF00000.. : copy from original mem unchanged
    for base in (0x200000,0x300000,0xF00000):
        hi=base>>16
        lines_out.append(rec(0,[(base>>24)&0xFF,(base>>16)&0xFF],4))  # ext linear addr
        addrs=sorted(x for x in mem if (x>>16)==hi)
        i=0
        while i<len(addrs):
            start=addrs[i]; run=[]
            while i<len(addrs) and addrs[i]==start+len(run) and len(run)<16:
                run.append(mem[addrs[i]]&0xFF); i+=1
            lines_out.append(rec(start&0xFFFF,run,0))
    lines_out.append(":00000001FF")
    open(fn,"w").write("\n".join(lines_out)+"\n")
emit_hex(OUT)
print(f"\nWrote {OUT}")
