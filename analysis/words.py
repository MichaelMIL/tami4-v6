S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
b=open(S+'pic18f8621_prog.bin','rb').read()
w=lambda a:b[a]|b[a+1]<<8
LANG={0:(0xf114,0xf22e),4:(0xef8e,0xf0a8),5:(0xee06,0xef20)}
def raw(p):
    s=bytearray()
    while b[p]: s.append(b[p]); p+=1
    return bytes(s)
def expand(s,lang,depth=0):
    out='';i=0
    while i<len(s):
        c=s[i]
        if c==1 and i+1<len(s) and depth<5:
            out+=expand(raw(w(LANG[lang][1]+2*(s[i+1]-1))),lang,depth+1); i+=2
        else:
            out+=chr(c) if 32<=c<127 else (s[i:i+1].decode('iso8859-8','replace') if lang==5 else f'\\x{c:02x}'); i+=1
    return out
def word(i,lang=0): return expand(raw(w(LANG[lang][0]+2*i)),lang)
def dictword(i,lang=0): return expand(raw(w(LANG[lang][1]+2*i)),lang)
