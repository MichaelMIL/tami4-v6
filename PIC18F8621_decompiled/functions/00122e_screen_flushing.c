// address 0x00122e  size 76 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Flushing: open cold valve for flush time computed from WATERFLOW */

void screen_flushing(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_draw_flushing();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x26;
  eeprom_read_param();
  *puVar1 = *puVar1;
  ui_set_menu_value_lo_2bae();
  math_aarg_lo = 0xb0;
  math_aarg_hi = 4;
  math_barg_lo = menu_value_lo;
  math_barg_hi = menu_value_hi;
  ui_to___divs16_289c();
  menu_timer_lo = math_aarg_lo;
  menu_timer_hi = math_aarg_hi;
  menu_timer_reload_lo = math_aarg_lo;
  menu_timer_reload_hi = math_aarg_hi;
  dispense_cold_request();
  ui_push_args_14_04_mod_to_ui_draw_progress_segment_265e();
  menu_cb_aux = 0xd0;
  menu_cb_aux_hi = 0x12;
  ui_set_menu_cb_timeout_2402();
  return;
}

