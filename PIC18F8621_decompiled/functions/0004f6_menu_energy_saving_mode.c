// address 0x0004f6  size 88 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_callw_fn0450_2b5e(0x22);
  if ((cfg_systemconfig2 & 1) == 0) {
    ui_set_menu_value_lo_26a6();
  }
  else {
    *(undefined1 *)in_FSR1 = 0x23;
    cVar2 = ui_to_eeprom_read_raw_2b00();
    cVar1 = cVar2 * '\n';
    ui_set_menu_value_lo_2bae(cVar2 * '\n');
    math_aarg_lo = cVar1;
    math_barg_lo = 0x1e;
    math_barg_hi = 0;
    math_aarg_hi = menu_value_hi;
    ui_to___divs16_289c();
  }
  screen_energy_saving_draw();
  menu_cb_enter = 0xa0;
  menu_cb_enter_hi = 4;
  menu_cb_up = 0xcc;
  menu_cb_up_hi = 4;
  menu_cb_down = 0xe2;
  menu_set_cbs_down_hi(4);
  return;
}

