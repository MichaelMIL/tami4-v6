// address 0x002b52  size 12 bytes
// callers: 002780,002254,0017c4,

/* Auto: reads c18_tmp0,TBLPTRL,c18_tmp1,TBLPTRH; 4 instr */

void ui_get_c18_tmp0_2b52(void)

{
  undefined1 in_TBLPTRL;
  undefined1 in_TBLPTRH;
  
  ui_get_TBLPTRL_2c14();
  c18_tmp0 = in_TBLPTRL;
  c18_tmp1 = in_TBLPTRH;
  return;
}

