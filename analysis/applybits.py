import os,sys,re
sys.path.insert(0,'/home/michael/Desktop/PIC18F8621_RE/analysis')
import bitlib
src,dst=sys.argv[1],sys.argv[2]
os.makedirs(dst,exist_ok=True)
for fn in os.listdir(src):
    if not fn.endswith('.c'): continue
    t=open(f'{src}/{fn}').read()
    t=re.sub(r'\bSPBREG2\b','SPBRG2',t)
    open(f'{dst}/{fn}','w').write(bitlib.transform(t))
print('changed',bitlib.changed,'symbols',len(bitlib.used))
