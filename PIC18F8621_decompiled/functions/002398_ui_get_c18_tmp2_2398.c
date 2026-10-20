// address 0x002398  size 14 bytes
// callers: 0028f6,000f94,0029cc,

/* Auto: reads c18_tmp2,TBLPTRL,c18_tmp3,TBLPTRH; 4 instr */

void ui_get_c18_tmp2_2398(void)

{
  undefined1 in_TBLPTRL;
  undefined1 in_TBLPTRH;
  
  ui_get_TBLPTRL_2c14();
  c18_tmp2 = in_TBLPTRL;
  c18_tmp3 = in_TBLPTRH;
  return;
}

