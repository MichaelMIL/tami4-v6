// address 0x004ebc  size 14 bytes
// callers: 002d86,

/* Auto: writes ui_screen,ui_countdown_100ms; calls dispense_hot_request; 6 instr */

void ui_to_dispense_hot_request_4ebc(void)

{
  ui_screen = 0x10;
  ui_countdown_100ms = 10;
  dispense_hot_request();
  return;
}

