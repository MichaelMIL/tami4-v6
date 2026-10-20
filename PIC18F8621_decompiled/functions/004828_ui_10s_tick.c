// address 0x004828  size 28 bytes
// callers: 00b104,

/* Every 10 s: refresh idle screen / clock */

char ui_10s_tick(void)

{
  char cVar1;
  
  if ((ui_screen == '\0') || (cVar1 = ui_screen + -1, ui_screen + -1 == '\0')) {
    if (ui_menu_active != '\0') {
      cVar1 = lcd_clear(ui_menu_active);
      return cVar1;
    }
    cVar1 = ui_clock_suppressed;
    if (ui_clock_suppressed == '\0') {
      cVar1 = clock_draw(0);
    }
  }
  return cVar1;
}

