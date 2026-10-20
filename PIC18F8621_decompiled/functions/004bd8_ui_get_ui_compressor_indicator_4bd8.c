// address 0x004bd8  size 10 bytes
// callers: 00e8e6,00e9b2,00e926,

/* Auto: reads ui_compressor_indicator; 4 instr */

void ui_get_ui_compressor_indicator_4bd8(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  ui_compressor_indicator = *(undefined1 *)((short)in_FSR2 + -2);
  ui_c18_epilogue_4d6e();
  return;
}

