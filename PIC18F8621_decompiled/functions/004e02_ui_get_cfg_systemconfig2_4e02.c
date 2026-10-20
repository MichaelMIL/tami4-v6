// address 0x004e02  size 14 bytes
// callers: 0048b2,004550,

/* Auto: reads cfg_systemconfig2; 7 instr */

byte ui_get_cfg_systemconfig2_4e02(void)

{
  return (cfg_systemconfig2 & 0x38) >> 3;
}

