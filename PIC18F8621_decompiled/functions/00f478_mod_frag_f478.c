// address 0x00f478  size 6 bytes
// callers: 00f43a,

/* WARNING: Instruction at (CODE,0x00f47c) overlaps instruction at (CODE,0x00f47a)
    */
/* Auto: compiler fragment: BTFSC 0x0000,#0x7,ACCESS ; GOTO 0x00f458 */

undefined1 mod_frag_f478(void)

{
  undefined1 uVar1;
  
  if ((math_sign & 0x80) != 0) {
    uVar1 = mod_frag_f458();
    return uVar1;
  }
  math_flags = math_flags | 0x10;
  return 0xff;
}

