// address 0x000360  size 28 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_reset(void)

{
  BADSPACEBASE *in_FSR1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  lcd_clear();
  *(undefined1 *)in_FSR1 = 0x8b;
  ui_to_ui_draw_title_2986();
  menu_cb_enter = 0x42;
  menu_set_cbs_back_default(3);
  return;
}

