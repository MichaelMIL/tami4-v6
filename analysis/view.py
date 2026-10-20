#!/usr/bin/env python3
"""Compact view of decompiled functions: view.py START END  (hex, address range) or list of addrs."""
import re,sys,os
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
D=S+'decb/'
names={}
for l in open('/home/michael/Desktop/PIC18F8621_RE/PIC18F8621_ghidra/names.tsv'):
    if l.startswith('#') or not l.strip(): continue
    p=l.rstrip('\n').split('\t')
    names[(p[0],int(p[1],16))]=p[2]
idx={}
for l in open(S+'dec/index.tsv'):
    p=l.rstrip('\n').split('\t'); idx[int(p[0],16)]=p
args=sys.argv[1:]
if len(args)==2 and all(len(a)<=6 for a in args) and '-' not in args[0]:
    lo,hi=int(args[0],16),int(args[1],16); addrs=[a for a in sorted(idx) if lo<=a<hi]
else: addrs=[int(a,16) for a in args]
DECL=re.compile(r'^\s+(undefined\d?|byte|char|bool|BADSPACEBASE|uint\d?|int\d?|ushort|short|code|float) \*?[\w]+;$')
NOISE=re.compile(r'^\s*\*?\(?(\w+)(\[-?\d+\])?\)? = \*?\(?\1(\[-?\d+\])?\)?;$|^\s*\*\w+ = \*\w+;$|^\s*\w+\[-?\d+\] = \w+\[-?\d+\];$')
def rn(t):
    def f(m):
        a=int(m.group(2),16); n=names.get(('func',a)); return n if n else m.group(0)
    t=re.sub(r'\b(thunk_)?FUN_CODE_([0-9a-f]{6})\b',f,t)
    def v(m):
        a=int(m.group(2),16); n=names.get(('var',a)); return n if n else m.group(0)
    t=re.sub(r'\b(DAT|[a-z]?DATA|uDATA|cDATA|bDATA)_?DATA_?([0-9a-f]{4})\b',v,t)
    t=re.sub(r'\b([bcu]?)DATA([0-9a-f]{4})\b',lambda m:names.get(('var',int(m.group(2),16)),m.group(0)),t)
    return t
for a in addrs:
    fn=f'{D}{a:06x}.c'
    if not os.path.exists(fn): continue
    p=idx[a]
    nm=names.get(('func',a),'')
    print(f'=== {a:06x} {nm} size={p[2]} callers={p[3]}')
    for l in open(fn).read().split('\n')[2:]:
        if not l.strip() or DECL.match(l) or NOISE.match(l) or l.startswith('/*') or l.strip().startswith('*/'): continue
        print(rn(l))
