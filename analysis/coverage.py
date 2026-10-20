import sys
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
b=open(S+'pic18f8621_prog.bin','rb').read()
ins=set()
for l in open(S+sys.argv[1]):
    p=l.split()
    if len(p)>=2 and p[0][:1] in '0123456789abcdef' and len(p[0])==6:
        a=int(p[0],16); n=4 if p[1] in('CALL','GOTO','LFSR','MOVFF') else 2
        ins.update(range(a,a+n))
tot=0
for blk in range(0,0x10000,0x800):
    nz=sum(1 for i in range(blk,blk+0x800) if b[i]!=0xff)
    co=sum(1 for i in range(blk,blk+0x800) if i in ins); tot+=co
    print(f"{blk:05x} nonFF={nz:5d} code={co:5d}")
print('total code bytes',tot)
# largest uncovered non-FF runs
runs=[];s=None
for i in range(0x10000):
    u = b[i]!=0xff and i not in ins
    if u and s is None: s=i
    if not u and s is not None:
        if i-s>=64: runs.append((s,i))
        s=None
print('uncovered runs >=64B:',len(runs)); print(' '.join(f'{a:x}-{e:x}' for a,e in runs[:60]))
