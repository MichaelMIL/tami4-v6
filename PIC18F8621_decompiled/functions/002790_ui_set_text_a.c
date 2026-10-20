// address 0x002790  size 14 bytes
// callers: 002144,0001a8,001140,002b46,0011aa,

/* Load text pointer of word (id in W) into menu_text_a and redraw */

void ui_set_text_a(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  uVar1 = in_PRODL;
  uVar2 = in_PRODH;
  ui_word_ptr();
  menu_text_a_hi = uVar2;
  menu_text_a_lo = uVar1;
  ui_to_ui_get_cfg_systemconfig2_2c1c();
  return;
}

