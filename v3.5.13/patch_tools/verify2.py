import sys; sys.path.insert(0,".")
from emu import PIC18
from hexparse import parse
HEX="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5.13-par-patch.hex"; ORIG="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex"

# multi-command sequence in ONE shell session (accumulation test)
def run_seq(cmds):
    p=PIC18(HEX); p._setfsr(1,0x0D00); p._setfsr(2,0x0D00); p.ram[0xFE0]=1
    p.ram[0xFAC]=0x02; p.maxcycles=8_000_000
    drifts=[]
    for cmd in cmds:
        # load buffer, start parse
        for a in range(0x11A,0x140): p.ram[a]=0
        for i,b in enumerate(cmd.encode()+b'\x00'): p.ram[0x11A+i]=b
        p.tx=bytearray(); p.pc=0x79CE
        c0=p.cycles
        while p.cycles<p.maxcycles:
            if p.pc==0x79B4: break
            p.step()
        drifts.append(p._fsr(1)-0x0D00)
    return drifts, p
cmds=["par=1","par=1,8","par=1","ver","par=76","par=76,45","par=76,61","par=0","ls","par=37","par=37,100"]
drifts,p=run_seq(cmds)
print("Accumulation test (FSR1 relative to 0xD00 after each command):")
for c,d in zip(cmds,drifts): print(f"  after {c:14s}: FSR1 offset = {d}")
print("  -> all zero:", all(d==0 for d in drifts))
print(f"  EEPROM[1]={p.ee[1]} (set to 8), EEPROM[76]={p.ee[76]} (set to 45), EEPROM[37]={p.ee[37]} (set to 100)")

# boundary value tests for param 76 (default50,min45,max60)
def run(cmd):
    p=PIC18(HEX); p._setfsr(1,0x0D00); p._setfsr(2,0x0D00); p.ram[0xFE0]=1
    p.ram[0xFAC]=0x02; p.maxcycles=3_000_000
    for i,b in enumerate(cmd.encode()+b'\x00'): p.ram[0x11A+i]=b
    p.pc=0x79CE
    while p.cycles<p.maxcycles:
        if p.pc==0x79B4: break
        p.step()
    return bytes(p.tx),p
print("\nBoundary tests param 76 (min45 max60):")
for cmd in ["par=76","par=76,45","par=76,60","par=76,44","par=76,61","par=75","par=76,50"]:
    tx,p=run(cmd)
    print(f"  {cmd:12s} -> {tx!r:22s} ee[76]={p.ee[76]}")

# check min/max EEPROM entries for new params 75,76
o=parse(ORIG)
def ee(a): return o[0xF00000+a]
for idx in [74,75,76]:
    print(f"  param {idx}: val={ee(idx)} max@{hex(idx+0x4D)}={ee(idx+0x4D)} min@{hex(idx+0x9A)}={ee(idx+0x9A)}")

# byte-level diff original vs patched
patched=parse(HEX)
diffs=[]
for a in range(0x10000):
    ov=o.get(a); pv=patched.get(a)
    if ov!=pv: diffs.append((a,ov,pv))
print(f"\nProgram-memory bytes changed: {len(diffs)}")
# summarize contiguous ranges
ranges=[]
for a,ov,pv in diffs:
    if ranges and a==ranges[-1][1]+1: ranges[-1][1]=a
    else: ranges.append([a,a])
for lo,hi in ranges:
    print(f"  0x{lo:04X}..0x{hi:04X} ({hi-lo+1} bytes)")
# confirm EEPROM + config unchanged
eediff=[a for a in range(0xF00000,0xF00400) if o.get(a)!=patched.get(a)]
cfgdiff=[a for a in list(range(0x200000,0x200008))+list(range(0x300000,0x30000E)) if o.get(a)!=patched.get(a)]
print(f"EEPROM bytes changed: {len(eediff)}  (must be 0)")
print(f"Config bytes changed: {len(cfgdiff)}  (must be 0)")
