import re,sys
sys.path.insert(0,'/home/michael/Desktop/PIC18F8621_RE/analysis')
import autoname as A
auto={}
for l in open(A.S+'autonames.tsv'):
    p=l.rstrip('\n').split('\t'); auto[int(p[1],16)]=[p[2],p[3]]
def base(n): return re.sub(r'_[0-9a-f]{4}$','',n)
def tgtname(t):
    if t in A.names: return A.names[t]
    if t in auto and '_code_' not in auto[t][0]: return base(auto[t][0])
    return None
def pattern(f):
    bd=A.body[f]; ts=[t for a,t in bd]; seq=' ; '.join(re.sub(r'0x[0-9a-f]+','N',t) for t in ts)
    tg=[int(m.group(2),16) for t in ts for m in [re.match(r'(CALL|RCALL|GOTO|BRA) 0x([0-9a-f]+)',t)] if m]
    tn=[tgtname(x) for x in tg]
    if seq.startswith('MOVF POSTDEC1,f,ACCESS ; MOVFF POSTDEC1,FSR2H ; MOVFF INDF1,FSR2L'): return 'c18_epilogue','C18 function epilogue: restore FSR2 frame pointer and return'
    if seq.startswith('MOVFF FSR2L,POSTINC1 ; MOVFF FSR2H,POSTINC1 ; MOVFF FSR1L,FSR2L'): return 'c18_prologue','C18 function prologue: save FSR2 and set new frame pointer'
    m=re.fullmatch(r'RETLW #0x([0-9a-f]+)',' ; '.join(ts))
    if m: return f'return_{int(m.group(1),16):#04x}',f'Return constant {int(m.group(1),16):#04x}'
    if ts==['RETURN 0x0']: return 'return_void','Empty function (return)'
    if 'MOVFF PLUSW2,FSR0L' in seq and 'MOVFF PLUSW2,FSR0H' in seq and len(ts)<=5: return 'frame_load_ptr_arg','Load pointer argument from stack frame into FSR0'
    if 'MOVFF PLUSW2,POSTINC1' in seq and len(ts)<=5: return 'frame_push_args','Copy stack-frame arguments onto the stack for a call'
    if re.fullmatch(r'(MOVF POSTDEC1,f,ACCESS ; )+RETURN N',seq): return f'pop{seq.count("POSTDEC1")}_return','Drop stack arguments and return'
    if seq.startswith('MOVWF POSTINC1,ACCESS ; CALL') or seq.startswith('MOVWF POSTINC1,ACCESS ; GOTO'):
        return f'callw_{tn[0] or "fn%04x"%tg[0]}',f'Push W as argument and call {tn[0] or hex(tg[0])}'
    if re.fullmatch(r'(MOVLW #N ; MOVWF POSTINC1,ACCESS ; )+(CLRF POSTINC1,ACCESS ; )?(RETURN N|GOTO N|CALL N,N.*)',seq):
        consts=[int(t.split('#')[1],16) for t in ts if t.startswith('MOVLW')]
        return 'push_args_'+'_'.join(f'{c:02x}' for c in consts)+(f'_{tn[-1]}' if tg and tn[-1] else ''),f'Push constant arguments {consts}'+(f' then call {tn[-1] or hex(tg[-1])}' if tg else '')
    if seq.startswith('MOVLB #N ; GOTO') or seq.startswith('MOVLB #N ; CALL'):
        return f'bank1_{tn[0] or "fn%04x"%tg[0]}',f'Select bank then jump to {tn[0] or hex(tg[0])}'
    m=re.fullmatch(r'MOVLW #N ; MOVLB #N ; MOVWF N,BANKED ; RETURN N',seq)
    if m:
        k=int(ts[0].split('#')[1],16); bk=int(ts[1].split('#')[1],16); v=(bk<<8)|int(ts[2].split()[1].split(',')[0],16)
        return f'set_{A.vnames.get(v,"r%03x"%v)}_{k}',f'Set {A.vnames.get(v,hex(v))} = {k}'
    if len(ts)==1 and tg: return f'jump_{tn[0] or "fn%04x"%tg[0]}',f'Jump to {tn[0] or hex(tg[0])}'
    if tg and all(t.split()[0] in('CALL','RCALL','GOTO','BRA') for t in ts):
        return 'chain_'+'_'.join((x or 'fn%04x'%y)[:18] for x,y in zip(tn,tg)),'Calls '+', '.join(x or hex(y) for x,y in zip(tn,tg))
    if tg and any(tn): 
        k=[x for x in tn if x][0]; return f'to_{k}',f'Small wrapper around {k}'
    if 'TBLRD' in seq: return 'rom_table_read','Read bytes from ROM table (TBLRD)'
    if 'SWAPF INDF0' in seq or ('ANDLW' in seq and 'POSTINC2' in seq): return 'bcd_digit_helper','BCD/ASCII digit helper for number formatting'
    if 'FSR0L' in seq and 'ADDLW' in seq: return 'calc_array_ptr','Compute array element address in FSR0'
    if 'PLUSW2' in seq: return 'frame_access','Access stack-frame local/argument'
    if 'POSTDEC1' in seq or 'POSTINC1' in seq: return 'stack_adjust','Software stack push/pop helper'
    return None,None
out=[];cnt=0
for f,(n,d) in sorted(auto.items()):
    if '_code_' in n:
        pn,pd=pattern(f)
        if pn:
            cnt+=1; n=f'{A.region(f)}_{pn}_{f:04x}'[:64]; d='Auto: '+pd+'; '+d.replace('Auto: ','')
    out.append(f'func\t0x{f:04x}\t{n}\t{d}')
open(A.S+'autonames2.tsv','w').write('\n'.join(out)+'\n')
left=[l for l in out if '_code_' in l.split('\t')[2]]
print('patterned',cnt,'still mnemonic-only',len(left))
for l in left[:40]: 
    f=int(l.split('\t')[1],16); print(l.split('\t')[2], ' | ', ' ; '.join(t for a,t in A.body[f])[:150])
