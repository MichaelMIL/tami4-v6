import re,collections,sys
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
sys.path.insert(0,S)
names={};vnames={}
for l in open('/home/michael/Desktop/PIC18F8621_RE/PIC18F8621_ghidra/names.tsv'):
    p=l.rstrip('\n').split('\t')
    if len(p)>2 and not l.startswith('#'):
        (names if p[0]=='func' else vnames)[int(p[1],16)]=p[2]
idx={}
for l in open(S+'decn/index.tsv'):
    a,n,sz,cr,ce=l.rstrip('\n').split('\t'); idx[int(a,16)]=(n,int(sz),[int(x,16) for x in cr.split(',') if x])
body=collections.defaultdict(list);cur=None
for l in open(S+'listing_named.txt'):
    if l.startswith(';=== FUNCTION'): cur=int(l.split('@CODE:')[1],16); continue
    p=l.split(None,1)
    if cur is not None and len(p)==2 and len(p[0])==6: body[cur].append((int(p[0],16),p[1].strip()))
def vn(a): return vnames.get(a,f'r{a:03x}')
def fn(a): return names.get(a,f'f{a:04x}')
def summ(f,maxi=30):
    out=[];B=None
    for a,t in body[f][:maxi]:
        m=re.match(r'MOVLB #0x([0-9a-f]+)',t)
        if m: B=int(m.group(1),16); continue
        bb=B if B is not None else 1
        t=re.sub(r'0x([0-9a-f]+),(#0x[0-7],)?BANKED',lambda m:vn((bb<<8)|int(m.group(1),16))+(','+m.group(2)[:-1] if m.group(2) else ''),t)
        t=re.sub(r'0x00([0-9a-f]{2}),ACCESS',lambda m:vn(int(m.group(1),16)),t)
        t=re.sub(r'MOVFF 0x0([0-9a-f]{3})',lambda m:'MOVFF '+vn(int(m.group(1),16)),t)
        t=re.sub(r',0x0([0-9a-f]{3})$',lambda m:','+vn(int(m.group(1),16)),t)
        t=re.sub(r'(CALL|GOTO|RCALL|BRA|BZ|BNZ|BC|BNC|BN|BNN) 0x0*([0-9a-f]+)(,0x0)?',lambda m:f'{m.group(1)} {fn(int(m.group(2),16))}',t)
        t=t.replace(',ACCESS','').replace(',f,',',').replace('POSTINC1','push').replace('POSTDEC1','pop')
        out.append(t)
    more='' if len(body[f])<=maxi else f' ...(+{len(body[f])-maxi})'
    return '; '.join(out)+more
if __name__=='__main__':
    lo,hi=int(sys.argv[1],16),int(sys.argv[2],16)
    for f in sorted(idx):
        n,sz,cr=idx[f]
        if lo<=f<hi and (n.startswith('FUN_CODE') or n.startswith('thunk_')):
            print(f'{f:04x} [{sz}] by {",".join(fn(c) for c in cr[:3])}: {summ(f)}')
