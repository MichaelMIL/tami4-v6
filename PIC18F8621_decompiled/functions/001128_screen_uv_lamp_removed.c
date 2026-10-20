// address 0x001128  size 24 bytes
// callers: 00d998,

/* "UV LAMP IS REMOVED / INSERT UV LAMP" */

void screen_uv_lamp_removed(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 3;
  ui_word_uv_lamp_26ae();
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word(0x79);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}

