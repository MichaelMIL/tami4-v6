// address 0x00afe8  size 20 bytes
// callers: 00af08,

/* Auto: reads cfg_systemconfig5; 10 instr */

char mod_get_cfg_systemconfig5_afe8(void)

{
  return '\x03' - ((cfg_systemconfig5 & 0x60) >> 5);
}

