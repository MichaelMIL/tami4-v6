// address 0x004bce  size 10 bytes
// callers: 00e870,00e7c4,

/* Auto: reads ui_heater_indicator; 4 instr */

void ui_get_ui_heater_indicator_4bce(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  ui_heater_indicator = *(undefined1 *)((short)in_FSR2 + -2);
  ui_c18_epilogue_4d6e();
  return;
}

