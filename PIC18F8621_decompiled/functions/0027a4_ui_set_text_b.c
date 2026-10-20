// address 0x0027a4  size 12 bytes
// callers: 002144,0001a8,001140,002b46,0011aa,

/* Load text pointer of word (id in W) into menu_text_b */

void ui_set_text_b(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  ui_word_ptr();
  menu_text_b_lo = in_PRODL;
  menu_text_b_hi = in_PRODH;
  return;
}

