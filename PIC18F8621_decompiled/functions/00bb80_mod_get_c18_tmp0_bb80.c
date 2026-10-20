// address 0x00bb80  size 14 bytes
// callers: 00b64a,00b6a6,

/* Auto: reads c18_tmp0; 6 instr */

char mod_get_c18_tmp0_bb80(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  mod_frame_load_ptr_arg_ba1a();
  mod_ptr_add_baf2();
  c18_tmp0 = *(char *)in_FSR0;
  cVar1 = mod_frag_bc1a();
  return c18_tmp0 + cVar1;
}

