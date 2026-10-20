// address 0x0025b4  size 14 bytes
// callers: 00054e,000a0e,000458,

/* Auto: Push W as argument and call txt_set_ui_hold_counter; 6 instr */

char ui_callw_txt_set_ui_hold_counter_25b4(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp2 = txt_set_ui_hold_counter_98fc();
  return cVar1 + -5;
}

