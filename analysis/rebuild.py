import os,sys
S='/home/michael/Desktop/PIC18F8621_RE/analysis/'
O=os.path.expanduser('~/Desktop/PIC18F8621_RE/PIC18F8621_decompiled/')
import shutil; shutil.rmtree(O+'functions',ignore_errors=True); os.makedirs(O+'functions')
idx=[l.rstrip('\n').split('\t') for l in open(S+'decn/index.tsv')]
out=open(O+'all_functions.c','w')
out.write('// PIC18F8621 water dispenser controller firmware - full decompilation\n// Ghidra 12.1.4 (PIC-18), %d functions, names from names.tsv (also applied in ~/Desktop/PIC18F8621_RE/PIC18F8621_ghidra)\n// Reconstructed pseudo-C, not original source. "(inferred)"/"(probable)" in comments = lower confidence.\n// SFR bit masks use datasheet names, see pic18f8621_bits.h. Overview: README.md\n#include "pic18f8621_bits.h"\n\n'%len(idx))
for a,name,size,callers,callees in idx:
    body=open(f'{S}decnb/{a}.c').read().split('\n',1)[1]
    open(f'{O}functions/{a}_{name}.c','w').write(f'// address 0x{a}  size {size} bytes\n// callers: {callers or "(none: entry point, task, or reached via pointer)"}\n{body}')
    out.write(f'// ===== 0x{a} {name} =====\n{body}\n')
print('written',len(idx))
