// address 0x004af4  size 62 bytes
// callers: 003b12,002d86,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Map current screen to its home/return screen */

byte ui_select_home_screen(void)

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

