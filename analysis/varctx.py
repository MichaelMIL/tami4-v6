import re,sys,collections
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
want=set(int(x,16) for x in sys.argv[1:])
strs={int(l[:5],16):l[6:].rstrip('\n') for l in open(S+'strings.txt')}
lines=[];cur=None;bsr=None
for l in open(S+'listing_final.txt'):
    if l.startswith(';=== FUNCTION'): cur=l.split('@CODE:')[1].strip(); bsr=None; continue
    p=l.split(None,1)
    if len(p)==2 and len(p[0])==6:
        t=p[1].strip(); m=re.match(r'MOVLB #0x([0-9a-f]+)',t)
        if m: bsr=int(m.group(1),16)
        lines.append((cur,p[0],t,bsr))
ctx=collections.defaultdict(list)
for i,(f,a,t,b) in enumerate(lines):
    for addr,mode in re.findall(r'\b0x([0-9a-f]{1,4}),(?:[^,]*,)?(BANKED|ACCESS)',t)+[(x,'ABS') for x in re.findall(r'MOVFF\s+(?:0x([0-9a-f]+))',t) if x]:
        v=int(addr,16)
        if mode=='BANKED':
            if b is None: continue
            v=(b<<8)|v
        if v in want:
            w=' | '.join(x[2] for x in lines[max(0,i-2):i+3])
            ctx[v].append(f'{f}: {w}')
for v in sorted(ctx):
    print(f'### {v:03x} ({len(ctx[v])} refs)')
    for c in ctx[v][:6]: print('   ',c[:200])
