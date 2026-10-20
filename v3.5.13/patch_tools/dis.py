import sys; sys.path.insert(0,".")
from hexparse import parse

from sfr import SFR

def fname(f,a):
    # a=1 -> BSR bank, a=0 -> access bank
    if a==0:
        if f>=0x60:
            full=0xF00|f
            return SFR.get(full,f'0x{full:X}')
        return f'0x{f:02X}(acc)'
    return f'[0x{f:02X}]'

def disasm(mem,lo,hi):
    out=[]
    a=lo
    while a<hi:
        w=mem.get(a)
        if w is None: a+=1; continue
        w|=mem.get(a+1,0)<<8
        txt,size=decode(mem,a,w)
        raw=' '.join(f'{mem.get(a+i,0):02X}' for i in range(size))
        out.append(f'{a:06X}  {raw:<12}  {txt}')
        a+=size
    return '\n'.join(out)

def decode(mem,a,w):
    hi4=w>>12
    d='f' if (w>>9)&1 else 'W'
    acc=(w>>8)&1
    f=w&0xFF
    # two-word first
    if (w&0xF000)==0xC000:  # MOVFF
        src=w&0xFFF; w2=mem.get(a+2,0)|mem.get(a+3,0)<<8; dst=w2&0xFFF
        return f'MOVFF 0x{src:X}, 0x{dst:X}',4
    if (w&0xFF00)==0xEF00:  # GOTO
        w2=mem.get(a+2,0)|mem.get(a+3,0)<<8
        addr=((w2&0xFFF)<<8|(w&0xFF))<<1
        return f'GOTO 0x{addr:X}',4
    if (w&0xFE00)==0xEC00:  # CALL
        s=(w>>8)&1
        w2=mem.get(a+2,0)|mem.get(a+3,0)<<8
        addr=((w2&0xFFF)<<8|(w&0xFF))<<1
        return f'CALL 0x{addr:X}{",FAST" if s else ""}',4
    if (w&0xFFC0)==0xEE00:  # LFSR
        fsr=(w>>4)&3; w2=mem.get(a+2,0)|mem.get(a+3,0)<<8
        k=((w&0xF)<<8)|(w2&0xFF)
        return f'LFSR {fsr}, 0x{k:X}',4
    # branches
    if (w&0xF800)==0xD000:  # BRA
        n=w&0x7FF
        if n&0x400: n-=0x800
        return f'BRA 0x{a+2+2*n:X}',2
    if (w&0xF800)==0xD800:  # RCALL
        n=w&0x7FF
        if n&0x400: n-=0x800
        return f'RCALL 0x{a+2+2*n:X}',2
    cond={0xE0:'BZ',0xE1:'BNZ',0xE2:'BC',0xE3:'BNC',0xE4:'BOV',0xE5:'BNOV',0xE6:'BN',0xE7:'BNN'}
    if (w>>8) in cond:
        n=w&0xFF
        if n&0x80: n-=0x100
        return f'{cond[w>>8]} 0x{a+2+2*n:X}',2
    # literal
    lit={0x08:'SUBLW',0x09:'IORLW',0x0A:'XORLW',0x0B:'ANDLW',0x0C:'RETLW',0x0D:'MULLW',0x0E:'MOVLW',0x0F:'ADDLW'}
    if (w>>8) in lit:
        return f'{lit[w>>8]} 0x{f:02X}',2
    if (w&0xFFF0)==0x0100:
        return f'MOVLB 0x{w&0xF:X}',2
    # simple
    simple={0x0000:'NOP',0x0003:'SLEEP',0x0004:'CLRWDT',0x0005:'PUSH',0x0006:'POP',
    0x0007:'DAW',0x0008:'TBLRD*',0x0009:'TBLRD*+',0x000A:'TBLRD*-',0x000B:'TBLRD+*',
    0x000C:'TBLWT*',0x000D:'TBLWT*+',0x000E:'TBLWT*-',0x000F:'TBLWT+*',
    0x0010:'RETFIE',0x0011:'RETFIE FAST',0x0012:'RETURN',0x0013:'RETURN FAST',
    0x0014:'CALLW',0x00FF:'RESET'}
    if w in simple: return simple[w],2
    # byte-oriented ffff with d,a
    bo={0b001001:'ADDWF',0b001000:'ADDWFC',0b000101:'ANDWF',0b000111:'COMF',
    0b000001:'DECF',0b001011:'DECFSZ',0b010011:'DCFSNZ',0b001010:'INCF',
    0b001111:'INCFSZ',0b010010:'INFSNZ',0b000100:'IORWF',0b010100:'MOVF',
    0b001101:'RLCF',0b010001:'RLNCF',0b001100:'RRCF',0b010000:'RRNCF',
    0b010111:'SUBFWB',0b010101:'SUBWF',0b010110:'SUBWFB',0b001110:'SWAPF',
    0b000110:'XORWF'}
    op6=w>>10
    if op6 in bo:
        return f'{bo[op6]} {fname(f,acc)}, {d}',2
    # byte f,a only (no d)
    fa={0b0110101:'CLRF',0b0110111:'MOVWF',0b0110110:'NEGF',0b0110100:'SETF',
    0b0110001:'CPFSEQ',0b0110010:'CPFSGT',0b0110000:'CPFSLT',0b0110011:'TSTFSZ',
    0b0000001:'MULWF'}
    op7=w>>9
    if op7 in fa:
        return f'{fa[op7]} {fname(f,acc)}',2
    # bit-oriented bbba
    bit={0b1001:'BCF',0b1000:'BSF',0b1011:'BTFSC',0b1010:'BTFSS',0b0111:'BTG'}
    if hi4 in bit:
        b=(w>>9)&7; aa=(w>>8)&1
        return f'{bit[hi4]} {fname(f,aa)}, {b}',2
    return f'DB 0x{w:04X}',2

if __name__=="__main__":
    mem=parse("/Users/michael/Downloads/PIC18F8621_RE 2/v3.5.13/PIC18F8621-3.5b.hex")
    lo=int(sys.argv[1],16); hi=int(sys.argv[2],16)
    print(disasm(mem,lo,hi))
