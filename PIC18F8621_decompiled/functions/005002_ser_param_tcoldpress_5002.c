// address 0x005002  size 14 bytes
// callers: 002d86,

/* Auto: reads params TCOLDPRESS; calls dispense_hot_allow,dispense_warm_cup; 5 instr */

void ser_param_tcoldpress_5002(void)

{
  ui_set_ui_screen_4e10(0xc);
  dispense_hot_allow();
  dispense_warm_cup();
  return;
}

