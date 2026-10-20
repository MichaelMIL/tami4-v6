// address 0x000606  size 46 bytes
// callers: 000642,000656,00066c,

/* Auto: writes text_fill_width; reads menu_value_lo; 18 instr */

void ui_set_text_fill_width_0606(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  cVar2 = ui_get_cfg_systemconfig2_2b2e();
  if (cVar2 == '\a') {
    ui_set_text_row_2b08();
    text_fill_width = 0x3c;
  }
  else {
    ui_set_text_row_2b08();
    text_fill_width = 0x44;
  }
  *(undefined1 *)in_FSR1 = 0xe4;
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  puVar1 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = menu_value_lo;
  ui_to_txt_set_ui_hold_counter_28b4();
  *puVar1 = *puVar1;
  return;
}

