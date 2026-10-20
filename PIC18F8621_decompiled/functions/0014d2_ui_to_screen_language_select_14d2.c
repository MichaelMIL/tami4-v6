// address 0x0014d2  size 4 bytes
// callers: 003b12,

/* Auto: calls screen_language_select; 1 instr */

void ui_to_screen_language_select_14d2(void)

{
  char cVar1;
  
  menu_edit_mode = ui_get_cfg_systemconfig2_2b2e();
  ui_word_installation_2370();
  menu_table_ptr_lo = 0xce;
  menu_table_ptr_hi = 0xe5;
  menu_item = 0;
  while( true ) {
    cVar1 = menu_item - 8;
    if (7 < menu_item) break;
    ui_get_menu_item_24ba(cVar1);
    ui_get_c18_tmp0_25e8();
    if (cVar1 == '\0') break;
    menu_item = menu_item + 1;
  }
  cVar1 = menu_item - 8;
  if (7 < menu_item) {
    menu_item = 0;
  }
  menu_draw(cVar1);
  menu_cb_enter = 0x24;
  menu_cb_enter_hi = 0x15;
  menu_cb_back = 0x98;
  menu_clear_cbs(0);
  return;
}

