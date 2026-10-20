// address 0x002b46  size 12 bytes
// callers: 0020de,0022ea,0022dc,

/* Draw ON/OFF choice */

void ui_draw_on_off(void)

{
  ui_stack_adjust_2800();
  ui_set_text_a(0x44);
  ui_set_text_b(0x45);
  return;
}

