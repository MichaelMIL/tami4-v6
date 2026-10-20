// address 0x00cc0c  size 32 bytes
// callers: 0093ee,

/* Auto: calls text_measure_width; 14 instr */

void mod_to_text_measure_width_cc0c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  mod_c18_prologue_cdd2();
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -4) | 0x10;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  pbVar1 = (byte *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)in_FSR2;
  text_measure_width();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  mod_c18_epilogue_cd24();
  return;
}

