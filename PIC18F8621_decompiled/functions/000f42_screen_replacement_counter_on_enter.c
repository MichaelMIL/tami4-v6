// address 0x000f42  size 82 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

byte screen_replacement_counter_on_enter(void)

{
  byte bVar1;
  
  if (menu_edit_mode != 0) {
    if ((cfg_systemconfig4 & 4) == 0) {
      ui_stack_adjust_26e2(0x4d);
      ui_to_text_draw_word_2996(0x4f);
      ui_set_menu_edit_mode_2498();
      menu_cb_enter = 0x2e;
      menu_set_cbs_enter_hi_c(0xf);
    }
  }
  bVar1 = menu_edit_mode;
  if (menu_edit_mode == 0) {
    bVar1 = cfg_systemconfig4 & 0x20;
    if (bVar1 == 0) {
      ui_stack_adjust_26e2(0x4e);
      ui_to_text_draw_word_2996(0x50);
      ui_set_menu_edit_mode_2498();
      menu_cb_enter = 0x1c;
      bVar1 = menu_set_cbs_enter_hi_c(0xf);
    }
  }
  return bVar1;
}

