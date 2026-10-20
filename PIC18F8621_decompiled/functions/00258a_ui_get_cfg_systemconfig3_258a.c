// address 0x00258a  size 10 bytes
// callers: 00097a,001a54,

/* Auto: reads cfg_systemconfig3; 5 instr */

byte ui_get_cfg_systemconfig3_258a(void)

{
  ui_to_ui_get_cfg_systemconfig2_2c1c();
  return cfg_systemconfig3 & 4;
}

