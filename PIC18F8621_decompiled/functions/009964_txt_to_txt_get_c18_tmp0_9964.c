// address 0x009964  size 14 bytes
// callers: 00930a,0092f2,0092da,0092e6,0092fe,

/* Auto: Small wrapper around txt_get_c18_tmp0; 5 instr */

void txt_to_txt_get_c18_tmp0_9964(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  txt_c18_prologue_9a5a();
  txt_get_c18_tmp0_9ac8();
  *(undefined1 *)in_FSR1 = in_PRODL;
  *(undefined1 *)((short)in_FSR1 + 1) = in_PRODH;
  return;
}

