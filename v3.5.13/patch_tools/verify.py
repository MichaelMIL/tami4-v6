import sys; sys.path.insert(0,".")
from emu import PIC18
HEX="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5.13-par-patch.hex"
def run(cmd, ee_pre=None):
    p=PIC18(HEX)
    if ee_pre:
        for a,v in ee_pre.items(): p.ee[a]=v
    for i,b in enumerate(cmd.encode()+b'\x00'): p.ram[0x11A+i]=b
    p._setfsr(1,0x0D00); p._setfsr(2,0x0D00); p.ram[0xFE0]=1
    p.ram[0xFAC]=0x02; p.maxcycles=3_000_000; p.pc=0x79CE
    while p.cycles<p.maxcycles:
        if p.pc==0x79B4: break
        p.step()
    drift=p._fsr(1)-0x0D00
    return bytes(p.tx), drift, p
print("=== READS ===")
for cmd,exp in [("par=1","3"),("par=29","0"),("par=37","126"),("par=21","100"),("par=0","0")]:
    tx,dr,p=run(cmd)
    print(f"  {cmd:10s} -> {tx!r:40s} drift={dr}")
print("=== WRITES (valid) ===")
for cmd,idx,val in [("par=1,7",1,7),("par=36,20",36,20),("par=29,85",29,85)]:
    tx,dr,p=run(cmd)
    print(f"  {cmd:12s} -> {tx!r:20s} drift={dr}  EEPROM[{idx}]={p.ee[idx]} (want {val}) {'OK' if p.ee[idx]==val else 'FAIL'}")
print("=== WRITES (out of range -> must be rejected, EEPROM unchanged) ===")
for cmd,idx in [("par=1,99",1),("par=1,0",1),("par=21,50",21),("par=29,200",29)]:
    pre={idx:p.ee[idx]} if False else None
    tx,dr,p=run(cmd)
    # original ee value
    orig=PIC18(HEX).ee[idx]
    print(f"  {cmd:12s} -> {tx!r:18s} drift={dr}  EEPROM[{idx}]={p.ee[idx]} (orig {orig}) {'UNCHANGED-OK' if p.ee[idx]==orig else 'CHANGED-BAD'}")
print("=== INVALID INDEX / ARGS ===")
for cmd in ["par=77","par=200","par","par=5,6,7"]:
    tx,dr,p=run(cmd)
    print(f"  {cmd:10s} -> {tx!r:24s} drift={dr}")
print("=== EXISTING COMMANDS STILL WORK ===")
for cmd in ["ver","get_wu","get_hwt_type","reset?no"]:
    if cmd=="reset?no": continue
    tx,dr,p=run(cmd)
    print(f"  {cmd:14s} -> {tx!r:50s} drift={dr}")
print("=== UNKNOWN COMMAND ===")
tx,dr,p=run("xyz"); print(f"  xyz -> {tx!r} drift={dr}")
print("=== ls (should list 'par' as #19, count 20) ===")
tx,dr,p=run("ls")
print("  ",tx.decode('latin1').replace('\r\n','|'))
print("  drift=",dr)
