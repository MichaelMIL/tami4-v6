import sys
# Parse Intel HEX -> dict of linear addr -> byte
def parse(fn):
    mem={}
    base=0
    with open(fn) as f:
        for line in f:
            line=line.strip()
            if not line or line[0]!=':': continue
            n=int(line[1:3],16)
            addr=int(line[3:7],16)
            typ=int(line[7:9],16)
            data=bytes.fromhex(line[9:9+2*n])
            if typ==0:
                for i,b in enumerate(data):
                    mem[base+addr+i]=b
            elif typ==4:
                base=int.from_bytes(data,'big')<<16
            elif typ==2:
                base=int.from_bytes(data,'big')<<4
            elif typ==1:
                break
    return mem

if __name__=="__main__":
    fn=sys.argv[1]
    mem=parse(fn)
    lo=min(mem); hi=max(mem)
    print(f"addr range 0x{lo:X}..0x{hi:X}, {len(mem)} bytes")
    # show segment boundaries
    segs=[]
    start=None; prev=None
    for a in sorted(mem):
        if start is None:
            start=a; prev=a
        elif a==prev+1:
            prev=a
        else:
            segs.append((start,prev)); start=a; prev=a
    segs.append((start,prev))
    for s,e in segs:
        print(f"  seg 0x{s:06X} .. 0x{e:06X}  ({e-s+1} bytes)")
