import re,collections,json
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
ins={};order=[]
for l in open(S+'listing_m.txt'):
    p=l.split(None,1)
    if len(p)==2 and len(p[0])==6 and p[0][:1] in '0123456789abcdef' and not p[1].startswith('.data'):
        a=int(p[0],16); ins[a]=p[1].strip(); order.append(a)
order.sort(); nxt={a:order[i+1] for i,a in enumerate(order[:-1])}
CB={0x134:'enter',0x136:'back',0x138:'up',0x13a:'down',0x13c:'key',0x13e:'timeout',0x140:'aux'}
def sim(start):
    W=None;B=None;mem={};stack=[];pc=start;steps=0
    while pc in ins and steps<400:
        steps+=1;t=ins[pc];n=nxt.get(pc)
        m=re.match(r'MOVLW #0x([0-9a-f]+)$',t)
        if m: W=int(m.group(1),16); pc=n; continue
        m=re.match(r'MOVLB #0x([0-9a-f]+)$',t)
        if m: B=int(m.group(1),16); pc=n; continue
        m=re.match(r'(MOVWF|CLRF) 0x([0-9a-f]+),BANKED$',t)
        if m:
            if B is not None:
                addr=(B<<8)|int(m.group(2),16)
                mem[addr]=0 if m.group(1)=='CLRF' else W
            pc=n; continue
        m=re.match(r'(GOTO|BRA) 0x([0-9a-f]+)',t)
        if m: pc=int(m.group(2),16); continue
        m=re.match(r'(CALL|RCALL) 0x([0-9a-f]+)',t)
        if m: stack.append(n); pc=int(m.group(2),16); continue
        if t.startswith('RETURN') or t.startswith('RETLW'):
            if t.startswith('RETLW'): W=int(t.split('#')[1],16)
            if not stack: break
            pc=stack.pop(); continue
        if t.startswith('MOVWF PC') or t.startswith('B') and not t.startswith('BSF') and not t.startswith('BCF') and not t.startswith('BTG') and not t.startswith('BTFS'):
            # conditional branch: assume fallthrough; computed jump: stop
            if t.startswith('MOVWF PC'): break
            pc=n; continue
        if re.match(r'(MOVF|ADDWF|ANDWF|IORWF|XORWF|SUBWF|INCF|DECF|RLCF|RRCF|RLNCF|RRNCF|COMF|SWAPF|MOVFF|MULWF|ADDLW|ANDLW|IORLW|XORLW|SUBLW|MULLW).*',t):
            if re.search(r',w,|LW ',t) or t.startswith(('ADDLW','ANDLW','IORLW','XORLW','SUBLW')): W=None
            if t.startswith('MOVFF'):
                d=t.split(',')[-1].strip()
                if d.startswith('0x'): mem[int(d,16)]=None
            pc=n; continue
        pc=n
    res={}
    for base,name in CB.items():
        lo,hi=mem.get(base,'u'),mem.get(base+1,'u')
        if lo!='u' and hi!='u' and lo is not None and hi is not None: res[name]=hi<<8|lo
    return res
if __name__=='__main__':
    import sys
    for a in sys.argv[1:]: print(a,{k:hex(v) for k,v in sim(int(a,16)).items()})
