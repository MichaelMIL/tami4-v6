// address 0x004af0  size 4 bytes
// callers: 001178,001140,0011aa,001334,0012f8,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: calls ui_select_home_screen; 1 instr */

byte ui_to_ui_select_home_screen_4af0(void)

{
  if (ui_return_screen == 0x14) {
    ui_screen = 0;
    return 0;
  }
  if (ui_return_screen == 0x1f) {
    ui_screen = 0x1e;
  }
  else {
    if (ui_return_screen == 0x1d) {
      ui_screen = 0;
      return 0;
    }
    if (ui_return_screen == 0x1c) {
      ui_screen = 0x1b;
    }
    else if (ui_return_screen == 5) {
      ui_screen = 4;
    }
    else {
      if (ui_return_screen != 3) {
        if ((ui_return_screen ^ 1) == 0) {
          ui_screen = 0;
          return 0;
        }
        ui_screen = ui_return_screen;
        return ui_return_screen ^ 1;
      }
      ui_screen = 2;
    }
  }
  return ui_screen;
}

