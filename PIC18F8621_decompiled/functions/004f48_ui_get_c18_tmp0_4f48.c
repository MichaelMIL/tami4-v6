// address 0x004f48  size 18 bytes
// callers: 0048b2,

/* Auto: reads c18_tmp0,c18_tmp1; 7 instr */

undefined1 ui_get_c18_tmp0_4f48(void)

{
  undefined1 in_FSR2L;
  undefined1 in_FSR2H;
  BADSPACEBASE *in_FSR0;
  
  c18_tmp0 = in_FSR2L;
  c18_tmp1 = in_FSR2H;
  ui_frame_access_4be8();
  *(undefined1 *)in_FSR0 = 0x2c;
  return 0x2c;
}

