// address 0x002b2e  size 14 bytes
// callers: 0014d6,002334,0025e8,002c1c,000606,

/* Auto: reads cfg_systemconfig2; 7 instr */

byte ui_get_cfg_systemconfig2_2b2e(void)

{
  return (cfg_systemconfig2 & 0x38) >> 3;
}

