// address 0x001bf2  size 8 bytes
// callers: 000342,001410,00089a,0007b0,0014a6,000634,00091a,0002fa,00279e,000200,001458,

/* Menu/screen handler (callback analysis) */

void menu_default_back(void)

{
  ui_bank1_ui_set_menu_cb_up_2454();
  menu_draw();
  return;
}

