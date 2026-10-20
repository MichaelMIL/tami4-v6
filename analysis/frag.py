import sys
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
b=open(S+'pic18f8621_prog.bin','rb').read()
cov=set()
for l in open(sys.argv[1]):
    p=l.split()
    if len(p)>=2 and len(p[0])==6 and p[0][:1] in '0123456789abcdef':
        a=int(p[0],16); cov.update(range(a,a+(4 if p[1] in('CALL','GOTO','LFSR','MOVFF') else 2)))
w=lambda a:b[a]|b[a+1]<<8
def ln(x): return 4 if (x>>8) in (0xEC,0xED,0xEF,0xEE) or (x>>12)==0xC else 2
def term(x): return x in (0x0012,0x0013,0x0010,0x0011) or (x>>8)==0xEF or (x>>11)==0b11010 or (x>>8)==0x0C
seeds=[]
for lo,hi in [(0x98,0x5000),(0x9282,0xdd5a)]:
    a=lo
    while a<hi:
        if a in cov or b[a:a+2]==b'\xff\xff': a+=2; continue
        start=True
        while a<hi and a not in cov:
            if start and b[a:a+4]!=b'\0\0\0\0': seeds.append(a)
            x=w(a); start=term(x); a+=ln(x)
open(S+'gap_targets.txt','w').write('\n'.join(f'0x{x:x}\t1' for x in seeds))
print(len(seeds),' '.join(f'{x:x}' for x in seeds))
