// address 0x002594  size 18 bytes
// callers: 000e04,

/* Auto: Small wrapper around txt_set_ui_hold_counter; 8 instr */

char ui_to_txt_set_ui_hold_counter_2594(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  
  ui_stack_adjust_2b26();
  cVar1 = (char)(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x75;
  c18_tmp8 = txt_set_ui_hold_counter_98fc();
  return cVar1 + -5;
}

