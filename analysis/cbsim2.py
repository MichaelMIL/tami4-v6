import re,collections
from cbsim import ins,nxt,CB
HELPERS={0x2150,0x2198,0x2248,0x2434,0x252c,0x254a,0x2580,0x2806,0x2846,0x2972,0x2a48,0x2a8a,0x2ad8}
def size(a): t=ins[a]; return 4 if t.split()[0] in ('CALL','GOTO','LFSR','MOVFF') else 2
def explore(start,budget=6000):
    found=collections.defaultdict(set)
    work=[(start,None,None,{},())];seen=set();steps=0
    while work and steps<budget:
        pc,W,B,mem,stack=work.pop()
        while pc in ins and steps<budget:
            steps+=1;t=ins[pc];n=nxt.get(pc);op=t.split()[0]
            key=(pc,W,B,stack,tuple(sorted((k,v) for k,v in mem.items() if k in range(0x134,0x142))))
            if key in seen: break
            seen.add(key)
            m=re.match(r'MOVLW #0x([0-9a-f]+)$',t)
            if m: W=int(m.group(1),16); pc=n; continue
            m=re.match(r'MOVLB #0x([0-9a-f]+)$',t)
            if m: B=int(m.group(1),16); pc=n; continue
            m=re.match(r'(MOVWF|CLRF|SETF) 0x([0-9a-f]+),BANKED$',t)
            if m:
                off=int(m.group(2),16)
                bb=B if B is not None else (1 if 0x34<=off<=0x41 else None)
                if bb is not None:
                    addr=(bb<<8)|off; mem=dict(mem); mem[addr]={'CLRF':0,'SETF':255}.get(m.group(1),W)
                    if 0x134<=addr<0x142:
                        base=addr&~1
                        lo,hi=mem.get(base),mem.get(base+1)
                        if lo is not None and hi is not None and base in CB: found[CB[base]].add(hi<<8|lo)
                pc=n; continue
            if op in('GOTO','BRA'): pc=int(t.split()[1].split(',')[0],16); continue
            if op in('CALL','RCALL'):
                tgt=int(t.split()[1].split(',')[0],16)
                if tgt in HELPERS: stack=stack+(n,); pc=tgt; continue
                W=None; B=None; pc=n; continue
            if op in('RETURN','RETLW','RETFIE'):
                if op=='RETLW': W=int(t.split('#')[1],16)
                if not stack: break
                pc=stack[-1]; stack=stack[:-1]; continue
            if t.startswith('MOVWF PC'): break
            if op in('BZ','BNZ','BC','BNC','BN','BNN','BOV','BNOV'):
                work.append((int(t.split()[1],16),W,B,mem,stack)); pc=n; continue
            if op in('BTFSS','BTFSC','DECFSZ','INCFSZ','DCFSNZ','INFSNZ','CPFSEQ','CPFSGT','CPFSLT','TSTFSZ'):
                if n in ins: work.append((n+size(n),W,B,mem,stack))
                if op in('DECFSZ','INCFSZ','DCFSNZ','INFSNZ') and ',w,' in t: W=None
                pc=n; continue
            if re.search(r',w,',t) or op in('ADDLW','ANDLW','IORLW','XORLW','SUBLW','MULLW') or (op=='MOVFF' and 'WREG' in t): W=None
            pc=n
    return found
if __name__=='__main__':
    import sys
    for a in sys.argv[1:]: print(a,{k:sorted(hex(x) for x in v) for k,v in explore(int(a,16)).items()})
