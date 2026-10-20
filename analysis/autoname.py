import re,collections,sys
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
sys.path.insert(0,S)
from words import word
b=open(S+'pic18f8621_prog.bin','rb').read()
strs={int(l[:5],16):l[6:].rstrip('\n') for l in open(S+'strings.txt')}
PARAM={}
for i in range(74):
    r=b[0xdd62+7*i:0xdd62+7*i+7]; pid=r[6] if i<73 else 0x4b
    PARAM[pid-1]=strs[r[0]|r[1]<<8]
names={};vnames={}
for l in open('/home/michael/Desktop/PIC18F8621_RE/PIC18F8621_ghidra/names.tsv'):
    p=l.rstrip('\n').split('\t')
    if len(p)>2 and not l.startswith('#'): (names if p[0]=='func' else vnames)[int(p[1],16)]=p[2]
body=collections.defaultdict(list);cur=None;allf=[]
for l in open(S+'listing_named.txt'):
    if l.startswith(';=== FUNCTION'): cur=int(l.split('@CODE:')[1],16); allf.append(cur); continue
    p=l.split(None,1)
    if cur is not None and len(p)==2 and len(p[0])==6 and not p[1].startswith('.data'): body[cur].append((int(p[0],16),p[1].strip()))
def first_call(f):
    for a,t in body[f][:5]:
        m=re.match(r'(CALL|RCALL|GOTO|BRA) 0x([0-9a-f]+)',t)
        if m: return int(m.group(2),16)
    return None
def is_param_reader(f,depth=0):
    n=names.get(f,'')
    if 'read_param' in n or n in('eeprom_read_raw','eeprom_read_param'): return True
    if depth<2 and f in body and len(body[f])<=6:
        c=first_call(f)
        return c is not None and is_param_reader(c,depth+1)
    return False
WORDF={0x27b0,0x2ba4,0x24ca,0x2790,0x27a4,0x2b90,0x9316}
def is_word_drawer(f,depth=0):
    if f in WORDF: return True
    if depth<2 and f in body and len(body[f])<=5:
        c=first_call(f); return c is not None and is_word_drawer(c,depth+1)
    return False
SKIP={'OS_Yield','lcd_write_data'}
def features(f):
    params=[];words=[];wr=[];rd=[];calls=[];B=None;W=None
    bd=body[f]
    for i,(a,t) in enumerate(bd):
        m=re.match(r'MOVLB #0x([0-9a-f]+)',t)
        if m: B=int(m.group(1),16); continue
        m=re.match(r'MOVLW #0x([0-9a-f]+)$',t)
        if m: W=int(m.group(1),16)
        m=re.match(r'(CALL|RCALL|GOTO|BRA) 0x([0-9a-f]+)',t)
        if m:
            tgt=int(m.group(2),16)
            if tgt in names and names[tgt] not in SKIP and not names[tgt].startswith('h_'): calls.append(names[tgt])
            if W is not None and tgt not in body.get(f,[]) and is_param_reader(tgt) and W in PARAM: params.append(PARAM[W])
            elif W is not None and is_word_drawer(tgt) and W<178: words.append(word(W).replace('\n',' ').replace('\r','').strip())
        bb=B if B is not None else 1
        m=re.match(r'(MOVWF|CLRF|SETF|INCF|DECF|BSF|BCF|BTG) 0x([0-9a-f]+),(?:#0x[0-7],)?(?:f,)?BANKED',t)
        if m:
            v=(bb<<8)|int(m.group(2),16)
            if v in vnames and (m.group(1) in('MOVWF','CLRF','SETF','BSF','BCF','BTG') or True): wr.append(vnames[v])
        m=re.match(r'(MOVF|BTFSS|BTFSC|SUBWF|ADDWF|IORWF|ANDWF|XORWF|CPFSEQ|TSTFSZ) 0x([0-9a-f]+),.*BANKED',t)
        if m:
            v=(bb<<8)|int(m.group(2),16)
            if v in vnames: rd.append(vnames[v])
        for x in re.findall(r'MOVFF 0x0([0-9a-f]{3}),|,0x0([0-9a-f]{3})$',t):
            for y in x:
                if y and int(y,16) in vnames: rd.append(vnames[int(y,16)])
        for sfr in re.findall(r'\b(PORT[A-J]|LAT[A-J]|TRIS[A-J]|INTCON\d?|PIR\d|PIE\d|TBLPTR[LHU]?|TABLAT|PCLATH|EECON1|ADCON\d)\b',t):
            rd.append(sfr)
        if t.startswith('MOVWF PC'): calls.append('computed_jump')
    u=lambda x:list(dict.fromkeys(x))
    return u(params),u(words),u(wr),u(rd),u(calls)
def slug(s): return re.sub(r'[^a-z0-9]+','_',s.lower()).strip('_')[:28]
def region(f):
    if f<0x5000: return 'ui'
    if f<0x7ae0: return 'ser'
    if 0x9282<=f<0x9ad4: return 'txt'
    if 0x9ad4<=f<0xa30c: return 'os'
    return 'mod'
if __name__=='__main__':
    out=[]
    for f in allf:
        if f in names: continue
        params,words,wr,rd,calls=features(f)
        n=len(body[f])
        if params: tok='param_'+slug(params[0])
        elif words: tok='word_'+slug(words[0])
        elif calls and calls[0]!='computed_jump': tok='to_'+calls[0]
        elif wr: tok='set_'+wr[0]
        elif rd: tok='get_'+rd[0]
        elif 'computed_jump' in calls: tok='call_ptr'
        else:
            ops=[t.split()[0].lower() for a,t in body[f][:3]]
            tok='code_'+'_'.join(ops)
        name=f'{region(f)}_{tok}_{f:04x}'[:60]
        desc=[]
        if params: desc.append('reads params '+','.join(params))
        if words: desc.append('shows "'+'" "'.join(words)+'"')
        if wr: desc.append('writes '+','.join(wr[:6]))
        if rd: desc.append('reads '+','.join(rd[:6]))
        if calls: desc.append('calls '+','.join(calls[:6]))
        desc.append(f'{n} instr')
        out.append(f'func\t0x{f:04x}\t{name}\tAuto: {"; ".join(desc)}')
    open(S+'autonames.tsv','w').write('\n'.join(out)+'\n')
    print(len(out))
