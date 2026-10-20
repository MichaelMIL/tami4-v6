# Minimal PIC18 assembler. Supports the subset needed for the patch.
# Operand forms:
#   #k        literal (0..255)
#   0xNN      file reg, access bank (a=0)
#   @0xNN     file reg, BSR bank (a=1)
#   ,W / ,F   destination for d-ops
# Directives: LABEL:  ORG 0xADDR   DB b0,b1,...   DW word   PTR 0xADDR (little-endian 16-bit)
import re
def asm(lines, labels=None):
    if labels is None: labels={}
    # pass 1: addresses
    pc=None; items=[]
    def size(mn,ops):
        if mn in ('MOVFF','GOTO','CALL','LFSR'): return 4
        if mn=='DB': return len(ops)
        if mn=='DW': return 2*len(ops)
        if mn=='PTR': return 2*len(ops)
        return 2
    cur=None
    for raw in lines:
        line=raw.split(';')[0].strip()
        if not line: continue
        if line.startswith('ORG'):
            pc=int(line.split()[1],0); continue
        m=re.match(r'^(\w+):$',line)
        if m:
            labels[m.group(1)]=pc; continue
        parts=line.split(None,1)
        mn=parts[0].upper()
        ops=[o.strip() for o in parts[1].split(',')] if len(parts)>1 else []
        items.append((pc,mn,ops,line))
        pc+=size(mn,ops)
    # pass 2: encode
    out={}
    def emitw(a,w): out[a]=w&0xFF; out[a+1]=(w>>8)&0xFF
    def lit(o):
        o=o.strip()
        if o.startswith('#'): o=o[1:]
        return resolve(o)&0xFF
    def resolve(o):
        o=o.strip()
        if o in labels: return labels[o]
        return int(o,0)
    def freg(o):
        o=o.strip()
        if o.startswith('@'): return (resolve(o[1:])&0xFF,1)
        return (resolve(o)&0xFF,0)
    for a,mn,ops,line in items:
        if mn=='DB':
            for i,b in enumerate(ops): out[a+i]=resolve(b)&0xFF
            continue
        if mn in ('DW','PTR'):
            for i,o in enumerate(ops):
                v=resolve(o); out[a+2*i]=v&0xFF; out[a+2*i+1]=(v>>8)&0xFF
            continue
        if mn=='MOVLB': emitw(a,0x0100|(resolve(ops[0])&0xF)); continue
        if mn=='MOVLW': emitw(a,0x0E00|lit(ops[0])); continue
        if mn=='ADDLW': emitw(a,0x0F00|lit(ops[0])); continue
        if mn=='SUBLW': emitw(a,0x0800|lit(ops[0])); continue
        if mn=='IORLW': emitw(a,0x0900|lit(ops[0])); continue
        if mn=='XORLW': emitw(a,0x0A00|lit(ops[0])); continue
        if mn=='ANDLW': emitw(a,0x0B00|lit(ops[0])); continue
        if mn=='RETLW': emitw(a,0x0C00|lit(ops[0])); continue
        if mn=='RETURN': emitw(a,0x0012); continue
        if mn=='NOP': emitw(a,0x0000); continue
        if mn=='MOVFF':
            src=resolve(ops[0])&0xFFF; dst=resolve(ops[1])&0xFFF
            emitw(a,0xC000|src); emitw(a+2,0xF000|dst); continue
        if mn in ('GOTO','CALL'):
            tgt=resolve(ops[0]); k=tgt>>1
            s=1 if (len(ops)>1 and ops[1].upper()=='FAST') else 0
            if mn=='GOTO': emitw(a,0xEF00|(k&0xFF))
            else: emitw(a,0xEC00|(s<<8)|(k&0xFF))
            emitw(a+2,0xF000|((k>>8)&0xFFF)); continue
        if mn=='LFSR':
            n=resolve(ops[0]); k=resolve(ops[1])
            emitw(a,0xEE00|((n&3)<<4)|((k>>8)&0xF)); emitw(a+2,0xF000|(k&0xFF)); continue
        # branches rel
        if mn in ('BRA','RCALL'):
            tgt=resolve(ops[0]); off=(tgt-(a+2))>>1
            assert -1024<=off<=1023, f"{mn} out of range at 0x{a:X} -> 0x{tgt:X} off={off}"
            base=0xD000 if mn=='BRA' else 0xD800
            emitw(a,base|(off&0x7FF)); continue
        cc={'BZ':0xE0,'BNZ':0xE1,'BC':0xE2,'BNC':0xE3,'BOV':0xE4,'BNOV':0xE5,'BN':0xE6,'BNN':0xE7}
        if mn in cc:
            tgt=resolve(ops[0]); off=(tgt-(a+2))>>1
            assert -128<=off<=127, f"{mn} out of range at 0x{a:X} -> 0x{tgt:X} off={off}"
            emitw(a,(cc[mn]<<8)|(off&0xFF)); continue
        # byte d,a ops
        BY6={'ADDWF':0x09,'ADDWFC':0x08,'ANDWF':0x05,'COMF':0x07,'DECF':0x01,'INCF':0x0A,
             'IORWF':0x04,'MOVF':0x14,'RLCF':0x0D,'RRCF':0x0C,'SUBFWB':0x15,'SUBWF':0x17,
             'SUBWFB':0x16,'SWAPF':0x0E,'XORWF':0x06,'DECFSZ':0x0B,'INCFSZ':0x0F}
        if mn in BY6:
            f,ac=freg(ops[0]); d=1 if (len(ops)>1 and ops[1].upper()=='F') else 0
            emitw(a,(BY6[mn]<<10)|(d<<9)|(ac<<8)|f); continue
        BY7={'CLRF':0b0110101,'MOVWF':0b0110111,'SETF':0b0110100,'NEGF':0b0110110,
             'CPFSEQ':0b0110001,'CPFSGT':0b0110010,'CPFSLT':0b0110000,'TSTFSZ':0b0110011,'MULWF':0b0000001}
        if mn in BY7:
            f,ac=freg(ops[0]); emitw(a,(BY7[mn]<<9)|(ac<<8)|f); continue
        BIT={'BCF':0b1001,'BSF':0b1000,'BTFSC':0b1011,'BTFSS':0b1010,'BTG':0b0111}
        if mn in BIT:
            f,ac=freg(ops[0]); b=resolve(ops[1])&7
            emitw(a,(BIT[mn]<<12)|(b<<9)|(ac<<8)|f); continue
        TBL={'TBLRD*':0x0008,'TBLRD*+':0x0009,'TBLRD*-':0x000A,'TBLRD+*':0x000B,
             'TBLWT*':0x000C,'TBLWT*+':0x000D,'TBLWT*-':0x000E,'TBLWT+*':0x000F,
             'MULLW':None}
        if mn in TBL and TBL[mn] is not None: emitw(a,TBL[mn]); continue
        if mn=='MULLW': emitw(a,0x0D00|lit(ops[0])); continue
        raise Exception("unknown mnemonic "+mn+" : "+line)
    return out,labels
