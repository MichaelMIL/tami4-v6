import sys; sys.path.insert(0,".")
from hexparse import parse

class PIC18:
    def __init__(self, hexfile):
        m=parse(hexfile)
        self.prog=bytearray(0x10000)
        for a in range(0x10000):
            v=m.get(a); self.prog[a]=v if v is not None else 0xFF
        self.ee=bytearray(1024)
        for a in range(1024):
            v=m.get(0xF00000+a); self.ee[a]=v if v is not None else 0xFF
        self.ram=bytearray(0x1000)   # 4K GPR+SFR space (banked 0x000-0xEFF) ; SFR 0xF00-0xFFF
        self.W=0
        self.pc=0
        self.stack=[]        # hardware return stack
        self.tx=bytearray()
        self.cycles=0
        self.trace=False
        self.maxcycles=5_000_000
        self.ee_rd_pending=False
        self.shadowstk=[]

    # ---- memory access ----
    def sfr(self,full): # full 12-bit address in 0xF00..0xFFF
        return full
    def getf(self,f,a):
        # returns full address
        if a==0:
            if f>=0x60: return 0xF00|f      # access SFR (PIC18F8621 split at 0x60)
            return f                        # access GPR low (bank0 0x00-0x7F)
        else:
            bsr=self.ram[0xFE0]&0xF
            return (bsr<<8)|f
    def rd(self,addr):
        addr&=0xFFF
        if addr==0xFEF: # INDF0
            return self.rd(self._fsr(0))
        if addr==0xFE7: # INDF1
            return self.rd(self._fsr(1))
        if addr==0xFDF: # INDF2
            return self.rd(self._fsr(2))
        if addr in (0xFEE,0xFED,0xFEC,0xFEB): return self._indf_mode(0,addr)
        if addr in (0xFE6,0xFE5,0xFE4,0xFE3): return self._indf_mode(1,addr)
        if addr in (0xFDE,0xFDD,0xFDC,0xFDB): return self._indf_mode(2,addr)
        if addr==0xFE8: return self.W   # WREG as file reg
        if addr==0xFA8: # EEDATA read
            return self.ram[0xFA8]
        if addr==0xFA4: # PIR3: force TX2IF(bit4) set = TX ready
            return self.ram[0xFA4]|0x10
        return self.ram[addr]
    def wr(self,addr,v):
        addr&=0xFFF; v&=0xFF
        if addr==0xFEF: self.wr(self._fsr(0),v); return
        if addr==0xFE7: self.wr(self._fsr(1),v); return
        if addr==0xFDF: self.wr(self._fsr(2),v); return
        if addr in (0xFEE,0xFED,0xFEC,0xFEB): self._indf_mode(0,addr,v); return
        if addr in (0xFE6,0xFE5,0xFE4,0xFE3): self._indf_mode(1,addr,v); return
        if addr in (0xFDE,0xFDD,0xFDC,0xFDB): self._indf_mode(2,addr,v); return
        if addr==0xFE8: self.W=v&0xFF; return   # WREG as file reg
        if addr==0xF6D: # TXREG2
            self.tx.append(v); self.ram[addr]=v; return
        if addr==0xFA6: # EECON1 write (handle WR/RD bits)
            old=self.ram[0xFA6]
            self.ram[0xFA6]=v
            if v&0x01: # RD
                ad=self.ram[0xFA9]|((self.ram[0xFAA]&0x3)<<8)
                self.ram[0xFA8]=self.ee[ad&0x3FF]
                self.ram[0xFA6]&=~0x01
            if v&0x02: # WR start
                ad=self.ram[0xFA9]|((self.ram[0xFAA]&0x3)<<8)
                if self.ram[0xFA6]&0x04: # WREN
                    self.ee[ad&0x3FF]=self.ram[0xFA8]
                self.ram[0xFA6]&=~0x02 # write completes immediately
            return
        self.ram[addr]=v
    def _fsr(self,n):
        lo=[0xFE9,0xFE1,0xFD9][n]; hi=[0xFEA,0xFE2,0xFDA][n]
        return self.ram[lo]|(self.ram[hi]<<8)
    def _setfsr(self,n,val):
        lo=[0xFE9,0xFE1,0xFD9][n]; hi=[0xFEA,0xFE2,0xFDA][n]
        self.ram[lo]=val&0xFF; self.ram[hi]=(val>>8)&0xFF
    def _indf_mode(self,n,addr,v=None):
        base=self._fsr(n)
        last=addr&0xF
        # POSTINC: FEE/FE6/FDE ; POSTDEC: FED/FE5/FDD ; PREINC: FEC/FE4/FDC ; PLUSW: FEB/FE3/FDB
        post_inc={0xE,0x6,0xE}; 
        kind=addr&0xF
        if kind in (0xE,): # POSTINCn (0xFEE,0xFE6? no 0xFE6 low=6) -> handle by exact
            pass
        # determine by exact address
        if addr in (0xFEE,0xFE6,0xFDE): # POSTINC
            ea=base
            if v is None: r=self.rd(ea)
            else: self.wr(ea,v); r=None
            self._setfsr(n,base+1); return r
        if addr in (0xFED,0xFE5,0xFDD): # POSTDEC
            ea=base
            if v is None: r=self.rd(ea)
            else: self.wr(ea,v); r=None
            self._setfsr(n,base-1); return r
        if addr in (0xFEC,0xFE4,0xFDC): # PREINC
            self._setfsr(n,base+1); ea=base+1
            if v is None: return self.rd(ea)
            else: self.wr(ea,v); return None
        if addr in (0xFEB,0xFE3,0xFDB): # PLUSW (W is SIGNED offset)
            off=self.W-256 if self.W>=128 else self.W
            ea=(base+off)&0xFFFF
            if v is None: return self.rd(ea)
            else: self.wr(ea,v); return None
    # ---- flags ----
    def getC(self): return self.ram[0xFD8]&1
    def setC(self,b): self.ram[0xFD8]=(self.ram[0xFD8]&~1)|(1 if b else 0)
    def setZ(self,b): self.ram[0xFD8]=(self.ram[0xFD8]&~4)|(4 if b else 0)
    def setN(self,b): self.ram[0xFD8]=(self.ram[0xFD8]&~0x10)|(0x10 if b else 0)
    def setDC(self,b): self.ram[0xFD8]=(self.ram[0xFD8]&~2)|(2 if b else 0)
    def setOV(self,b): self.ram[0xFD8]=(self.ram[0xFD8]&~8)|(8 if b else 0)
    def nz(self,v):
        v&=0xFF; self.setZ(v==0); self.setN(v>=0x80); return v
    def word(self,a): return self.prog[a]|(self.prog[a+1]<<8)

    def step(self):
        pc=self.pc
        w=self.word(pc)
        self.pc=(pc+2)&0xFFFF
        self.cycles+=1
        op=self._exec(pc,w)

    def run(self,stop_sp=0):
        start_depth=len(self.stack)
        while self.cycles<self.maxcycles:
            if len(self.stack)<start_depth:  # returned past entry
                return 'ret'
            self.step()
        return 'timeout'

    def _isize(self,a):
        w=self.word(a)
        if (w&0xF000)==0xC000: return 4
        if (w&0xFF00)==0xEF00: return 4
        if (w&0xFE00)==0xEC00: return 4
        if (w&0xFFC0)==0xEE00: return 4
        return 2
    def _skip(self):
        self.pc=(self.pc+self._isize(self.pc))&0xFFFF
        self.cycles+=1

    def _exec(self,pc,w):
        d_to_f=(w>>9)&1          # d bit: 1->f, 0->W
        a=(w>>8)&1
        f=w&0xFF
        hi4=w>>12
        # two-word
        if (w&0xF000)==0xC000: # MOVFF
            src=w&0xFFF; w2=self.word(self.pc); self.pc=(self.pc+2)&0xFFFF; self.cycles+=1
            dst=w2&0xFFF
            self.wr(dst,self.rd(src)); return
        if (w&0xFF00)==0xEF00: # GOTO
            w2=self.word(self.pc); self.pc=(self.pc+2)&0xFFFF; self.cycles+=1
            self.pc=(((w2&0xFFF)<<8|(w&0xFF))<<1)&0xFFFF; return
        if (w&0xFE00)==0xEC00: # CALL
            s=(w>>8)&1
            w2=self.word(self.pc); self.pc=(self.pc+2)&0xFFFF; self.cycles+=1
            ret=self.pc
            self.stack.append(ret)
            if s: self.shadowstk.append((self.W,self.ram[0xFD8],self.ram[0xFE0]))
            self.pc=(((w2&0xFFF)<<8|(w&0xFF))<<1)&0xFFFF; return
        if (w&0xFFC0)==0xEE00: # LFSR
            n=(w>>4)&3; w2=self.word(self.pc); self.pc=(self.pc+2)&0xFFFF; self.cycles+=1
            k=((w&0xF)<<8)|(w2&0xFF); self._setfsr(n,k); return
        # branches
        if (w&0xF800)==0xD000: # BRA
            n=w&0x7FF
            if n&0x400: n-=0x800
            self.pc=(pc+2+2*n)&0xFFFF; return
        if (w&0xF800)==0xD800: # RCALL
            n=w&0x7FF
            if n&0x400: n-=0x800
            self.stack.append(self.pc)
            self.pc=(pc+2+2*n)&0xFFFF; return
        ch=w>>8
        condmap={0xE0:('Z',1),0xE1:('Z',0),0xE2:('C',1),0xE3:('C',0),
                 0xE6:('N',1),0xE7:('N',0),0xE4:('OV',1),0xE5:('OV',0)}
        if ch in condmap:
            fl,want=condmap[ch]
            st=self.ram[0xFD8]
            val={'Z':(st>>2)&1,'C':st&1,'N':(st>>4)&1,'OV':(st>>3)&1}[fl]
            n=w&0xFF
            if n&0x80: n-=0x100
            if val==want: self.pc=(pc+2+2*n)&0xFFFF
            return
        # literal
        if ch==0x0E: self.W=f; return  # MOVLW
        if ch==0x0C: # RETLW
            self.W=f; self.pc=self.stack.pop() if self.stack else 0; return
        if ch==0x08: # SUBLW  W = f - W
            r=f-self.W; self._alu_sub_flags(f,self.W,0,r); self.W=r&0xFF; return
        if ch==0x0F: # ADDLW
            r=self.W+f; self._alu_add(self.W,f,0,r); self.W=r&0xFF; return
        if ch==0x09: self.W=self.nz(self.W|f); return  # IORLW
        if ch==0x0A: self.W=self.nz(self.W^f); return  # XORLW
        if ch==0x0B: self.W=self.nz(self.W&f); return  # ANDLW
        if ch==0x0D: # MULLW
            r=self.W*f; self.ram[0xFF3]=r&0xFF; self.ram[0xFF4]=(r>>8)&0xFF; return
        if (w&0xFFF0)==0x0100: self.ram[0xFE0]=w&0xF; return  # MOVLB
        # simple
        if w==0x0012 or w==0x0013: # RETURN
            if w==0x0013 and self.shadowstk:
                self.W,self.ram[0xFD8],self.ram[0xFE0]=self.shadowstk.pop()
            self.pc=self.stack.pop() if self.stack else 0; return
        if w==0x0010 or w==0x0011: self.pc=self.stack.pop() if self.stack else 0; return # RETFIE
        if w==0x0000: return # NOP
        if w==0x0003: return # SLEEP
        if w==0x0004: return # CLRWDT
        if w in (0x0005,0x0006): # PUSH/POP
            if w==0x0005: self.stack.append(self.pc)
            else:
                if self.stack: self.stack.pop()
            return
        if w in (0x0008,0x0009,0x000A,0x000B): # TBLRD variants
            self._tblrd(w&3); return
        if w in (0x000C,0x000D,0x000E,0x000F): # TBLWT - ignore (prog mem) 
            return
        if w==0x00FF: return # RESET (ignore)
        if w==0x0007: return # DAW approx
        # byte-oriented file ops (6-bit opcode), format OOOOOOda ffffffff
        op6=w>>10
        BYTE6={0x09:'ADDWF',0x08:'ADDWFC',0x05:'ANDWF',0x07:'COMF',0x01:'DECF',
               0x0B:'DECFSZ',0x13:'DCFSNZ',0x0A:'INCF',0x0F:'INCFSZ',0x12:'INFSNZ',
               0x04:'IORWF',0x14:'MOVF',0x0D:'RLCF',0x11:'RLNCF',0x0C:'RRCF',
               0x10:'RRNCF',0x15:'SUBFWB',0x17:'SUBWF',0x16:'SUBWFB',0x0E:'SWAPF',
               0x06:'XORWF'}
        if op6 in BYTE6:
            ea=self._resolve(f,a); v=self.rd(ea)
            m=BYTE6[op6]
            def store(r):
                r&=0xFF
                if d_to_f: self.wr(ea,r)
                else: self.W=r
            C=self.getC()
            if m=='ADDWF': r=v+self.W; self._alu_add(v,self.W,0,r); store(r)
            elif m=='ADDWFC': r=v+self.W+C; self._alu_add(v,self.W,C,r); store(r)
            elif m=='ANDWF': store(self.nz(v&self.W))
            elif m=='COMF': store(self.nz((~v)&0xFF))
            elif m=='DECF': r=v-1; self._alu_sub_flags(v,1,0,r); store(self.nz0(r))
            elif m=='INCF': r=v+1; self._alu_add(v,1,0,r); store(r&0xFF); self.nz(r&0xFF)
            elif m=='IORWF': store(self.nz(v|self.W))
            elif m=='MOVF': store(self.nz(v))
            elif m=='XORWF': store(self.nz(v^self.W))
            elif m=='SWAPF': store(((v<<4)|(v>>4))&0xFF)
            elif m=='RLCF': r=((v<<1)|C)&0xFF; self.setC((v>>7)&1); store(self.nz(r))
            elif m=='RRCF': r=((v>>1)|(C<<7))&0xFF; self.setC(v&1); store(self.nz(r))
            elif m=='RLNCF': store(self.nz(((v<<1)|(v>>7))&0xFF))
            elif m=='RRNCF': store(self.nz(((v>>1)|((v&1)<<7))&0xFF))
            elif m=='SUBWF': r=v-self.W; self._alu_sub_flags(v,self.W,0,r); store(r&0xFF)
            elif m=='SUBFWB': r=self.W-v-(1-C); self._alu_sub_flags(self.W,v,1-C,r); store(r&0xFF)
            elif m=='SUBWFB': r=v-self.W-(1-C); self._alu_sub_flags(v,self.W,1-C,r); store(r&0xFF)
            elif m=='DECFSZ': r=(v-1)&0xFF; store(r); 
            elif m=='INCFSZ': r=(v+1)&0xFF; store(r)
            elif m=='DCFSNZ': r=(v-1)&0xFF; store(r)
            elif m=='INFSNZ': r=(v+1)&0xFF; store(r)
            if m=='DECFSZ' and ((v-1)&0xFF)==0: self._skip()
            if m=='INCFSZ' and ((v+1)&0xFF)==0: self._skip()
            if m=='DCFSNZ' and ((v-1)&0xFF)!=0: self._skip()
            if m=='INFSNZ' and ((v+1)&0xFF)!=0: self._skip()
            return
        # byte ops f,a only (7-bit opcode)
        op7=w>>9
        BYTE7={0b0110101:'CLRF',0b0110111:'MOVWF',0b0110110:'NEGF',0b0110100:'SETF',
               0b0110001:'CPFSEQ',0b0110010:'CPFSGT',0b0110000:'CPFSLT',
               0b0110011:'TSTFSZ',0b0000001:'MULWF'}
        if op7 in BYTE7:
            ea=self._resolve(f,a); v=self.rd(ea); m=BYTE7[op7]
            if m=='CLRF': self.wr(ea,0); self.setZ(True)
            elif m=='MOVWF': self.wr(ea,self.W)
            elif m=='SETF': self.wr(ea,0xFF)
            elif m=='NEGF': r=(-v)&0xFF; self.wr(ea,r); self.nz(r)
            elif m=='MULWF': r=self.W*v; self.ram[0xFF3]=r&0xFF; self.ram[0xFF4]=(r>>8)&0xFF
            elif m=='CPFSEQ':
                if v==self.W: self._skip()
            elif m=='CPFSGT':
                if v>self.W: self._skip()
            elif m=='CPFSLT':
                if v<self.W: self._skip()
            elif m=='TSTFSZ':
                if v==0: self._skip()
            return
        # bit ops bbba
        BIT={0b1001:'BCF',0b1000:'BSF',0b1011:'BTFSC',0b1010:'BTFSS',0b0111:'BTG'}
        if hi4 in BIT:
            b=(w>>9)&7; aa=(w>>8)&1; ea=self._resolve(f,aa); v=self.rd(ea); m=BIT[hi4]
            if m=='BCF': self.wr(ea,v&~(1<<b))
            elif m=='BSF': self.wr(ea,v|(1<<b))
            elif m=='BTG': self.wr(ea,v^(1<<b))
            elif m=='BTFSC':
                if not (v>>b)&1: self._skip()
            elif m=='BTFSS':
                if (v>>b)&1: self._skip()
            return
        raise Exception(f"unimpl opcode 0x{w:04X} at 0x{pc:04X}")

    def _resolve(self,f,a):
        addr=self.getf(f,a)
        IND={0xFEF:(0,'i'),0xFEE:(0,'pi'),0xFED:(0,'pd'),0xFEC:(0,'pr'),0xFEB:(0,'pw'),
             0xFE7:(1,'i'),0xFE6:(1,'pi'),0xFE5:(1,'pd'),0xFE4:(1,'pr'),0xFE3:(1,'pw'),
             0xFDF:(2,'i'),0xFDE:(2,'pi'),0xFDD:(2,'pd'),0xFDC:(2,'pr'),0xFDB:(2,'pw')}
        if addr in IND:
            n,m=IND[addr]; base=self._fsr(n)
            if m=='i': return base
            if m=='pi': self._setfsr(n,(base+1)&0xFFFF); return base
            if m=='pd': self._setfsr(n,(base-1)&0xFFFF); return base
            if m=='pr': nb=(base+1)&0xFFFF; self._setfsr(n,nb); return nb
            if m=='pw': off=self.W-256 if self.W>=128 else self.W; return (base+off)&0xFFFF
        return addr
    def nz0(self,r): return r&0xFF
    def _alu_add(self,x,y,cin,r):
        self.setC(1 if r>0xFF else 0)
        self.setZ((r&0xFF)==0); self.setN((r&0x80)!=0)
        self.setDC(1 if ((x&0xF)+(y&0xF)+cin)>0xF else 0)
        self.setOV(1 if (~(x^y)&(x^r)&0x80) else 0)
    def _alu_sub_flags(self,x,y,bin,r):
        # x - y - bin ; C=1 if no borrow (r>=0)
        self.setC(1 if r>=0 else 0)
        self.setZ((r&0xFF)==0); self.setN((r&0x80)!=0)
    def _alu_sub(self,x,y,r): pass
    def _tblrd(self,mode):
        tp=self.ram[0xFF6]|(self.ram[0xFF7]<<8)|(self.ram[0xFF8]<<16)
        if mode==3: tp=(tp+1)&0xFFFFFF          # TBLRD+*
        self.ram[0xFF5]=self.prog[tp&0xFFFF] if (tp&0xFFFFFF)<0x10000 else 0xFF
        if mode==1: tp=(tp+1)&0xFFFFFF           # TBLRD*+
        elif mode==2: tp=(tp-1)&0xFFFFFF         # TBLRD*-
        self.ram[0xFF6]=tp&0xFF; self.ram[0xFF7]=(tp>>8)&0xFF; self.ram[0xFF8]=(tp>>16)&0xFF
