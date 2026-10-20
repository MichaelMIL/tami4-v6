// address 0x0029d6  size 18 bytes
// callers: 002296,0017c4,

/* Auto: reads c18_tmp0,TABLAT,c18_tmp1; 7 instr */

byte ui_get_c18_tmp0_29d6(void)

{
  byte *in_TBLPTR;
  
  c18_tmp0 = *in_TBLPTR;
  c18_tmp1 = in_TBLPTR[1];
  return in_TBLPTR[1] | *in_TBLPTR;
}

