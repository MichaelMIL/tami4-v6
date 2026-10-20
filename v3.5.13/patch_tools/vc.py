import sys; sys.path.insert(0,".")
from emu import PIC18
HEX="/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5.13-par-jug.hex"
def run(cmd):
    p=PIC18(HEX)
    for i,b in enumerate(cmd.encode()+b'\x00'): p.ram[0x11A+i]=b
    p._setfsr(1,0x0D00); p._setfsr(2,0x0D00); p.ram[0xFE0]=1; p.ram[0xFAC]=2
    p.maxcycles=3_000_000; p.pc=0x79CE
    while p.cycles<p.maxcycles:
        if p.pc==0x79B4: break
        p.step()
    return bytes(p.tx), p._fsr(1)-0x0D00, p
print("=== par via repointed ex slot ===")
for cmd in ["par=29","par=1","par=37","par=1,8","par=1,99","par=77","ver","ex","get_wu"]:
    tx,dr,p=run(cmd)
    extra=""
    if cmd in ("par=1,8","par=1,99"):
        extra=f"  EEPROM[1]={p.ee[1]}"
    print(f"  {cmd:9s} -> {tx!r:34s} drift={dr}{extra}")

# jug handler trace: call jug_qty (0xFFCC) and check it invokes 0x23EC/2200/2A4A with W=0x43 and reaches 0x245C
print("=== jug handler (0xFFCC) ===")
p=PIC18(HEX); p._setfsr(1,0x0D00); p._setfsr(2,0x0D00); p.ram[0xFE0]=1
p.stack.append(0x0002)  # return sentinel
p.pc=0xFFCC; p.maxcycles=200000
seen=[]
while p.cycles<p.maxcycles:
    pc=p.pc
    if pc in (0x23EC,0x2200,0x2A4A,0x245C,0x294A,0x2840):
        seen.append((hex(pc),"W=0x%02X"%p.W))
    if pc==0x245C:  # reached editor entry — stop (don't run full editor)
        seen.append(("reached editor 0x245C","W=0x%02X"%p.W)); break
    if pc==0x0002: break
    try: p.step()
    except Exception as e: seen.append(("ERR",str(e))); break
for s in seen: print("  ",s)
