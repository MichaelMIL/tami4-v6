# Build per-function knowledge base from the Ghidra listing + index.
import re, collections, json
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
b=open(S+'pic18f8621_prog.bin','rb').read()
strs={int(l[:5],16):l[6:].rstrip('\n') for l in open(S+'strings.txt')}
# also allow refs into the middle of a string? only starts
idx={}
for l in open(S+'dec/index.tsv'):
    a,n,sz,cr,ce=l.rstrip('\n').split('\t')
    idx[int(a,16)]=dict(name=n,size=int(sz),callers=[int(x,16) for x in cr.split(',') if x],callees=[int(x,16) for x in ce.split(',') if x])
body=collections.defaultdict(list); cur=None
for l in open(S+'listing_final.txt'):
    if l.startswith(';=== FUNCTION'): cur=int(l.split('@CODE:')[1],16); continue
    p=l.split(None,1)
    if cur is not None and len(p)==2 and len(p[0])==6: body[cur].append((int(p[0],16),p[1].strip()))
SFR=set(re.findall(r'\b[A-Z][A-Z0-9]+\b',open('/home/michael/Desktop/PIC18F8621_RE/PIC18F8621_decompiled/pic18f8621_bits.h').read()))
kb={}
for f,ins in body.items():
    s=[];sfr=collections.Counter();ram=collections.Counter();bsr=None
    for i,(a,t) in enumerate(ins):
        m=re.match(r'MOVLB #0x([0-9a-f]+)',t)
        if m: bsr=int(m.group(1),16)
        if t.startswith('MOVLW') and i+2<len(ins) and ins[i+1][1].startswith('MOVWF POSTINC1') and ins[i+2][1].startswith('MOVLW'):
            lo=int(t.split('#')[1],16); hi=int(ins[i+2][1].split('#')[1],16); v=hi<<8|lo
            if v in strs: s.append(strs[v])
        for r in re.findall(r'\b(PORT[A-J]|LAT[A-J]|TRIS[A-J]|INTCON\d?|PIR\d|PIE\d|IPR\d|RCON|T[0-4]CON|TMR\d[LH]?|ADCON\d|ADRES[LH]|CMCON|RCSTA\d|TXSTA\d|TXREG\d|RCREG\d|SPBRG\d|EECON\d|EEDATA|EEADRH?|SSPCON\d|SSPSTAT|SSPBUF|SSPADD|CCP\d+CON|CCPR\d[LH]|PR\d|MEMCON|PSPCON|WDTCON|OSCCON|LVDCON|CVRCON|BAUDCON\d)\b',t): sfr[r]+=1
        for addr,mode in re.findall(r'\b0x([0-9a-f]{1,4}),(?:[wf#0-9x,]*)?(BANKED|ACCESS)',t):
            v=int(addr,16)
            if mode=='BANKED' and bsr is not None: ram[(bsr<<8)|v]+=1
            elif mode=='ACCESS' and v<0x60: ram[v]+=1
        for x in re.findall(r'MOVFF\s+0x([0-9a-f]+),\s*0x([0-9a-f]+)|MOVFF\s+0x([0-9a-f]+),|MOVFF\s+\w+,0x([0-9a-f]+)',t):
            for y in x:
                if y: ram[int(y,16)]+=1
    d=idx.get(f,{})
    kb[f]=dict(name=d.get('name'),size=d.get('size'),callers=d.get('callers',[]),callees=d.get('callees',[]),strings=s,sfr=dict(sfr),ram=dict(ram))
json.dump({f'{k:06x}':v for k,v in kb.items()},open(S+'kb.json','w'))
print('functions',len(kb),'with strings',sum(1 for v in kb.values() if v['strings']),'with sfr',sum(1 for v in kb.values() if v['sfr']))
allram=collections.Counter()
for v in kb.values():
    for r in v['ram']: allram[r]+=1
print('distinct RAM addrs',len(allram)); print('most shared RAM:',', '.join(f'{r:03x}:{c}' for r,c in allram.most_common(40)))
