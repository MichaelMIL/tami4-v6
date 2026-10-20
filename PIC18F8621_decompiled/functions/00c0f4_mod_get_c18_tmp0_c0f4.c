// address 0x00c0f4  size 20 bytes
// callers: 00beae,

/* Auto: reads c18_tmp0,TABLAT,c18_tmp1; 8 instr */

undefined1 mod_get_c18_tmp0_c0f4(void)

{
  undefined1 in_TABLAT;
  undefined1 *in_TBLPTR;
  
  mod_get_ntc_table_ptr_lo_c144();
  mod_get_TBLPTRL_c14e(2);
  c18_tmp0 = in_TABLAT;
  c18_tmp1 = *in_TBLPTR;
  return in_TABLAT;
}

