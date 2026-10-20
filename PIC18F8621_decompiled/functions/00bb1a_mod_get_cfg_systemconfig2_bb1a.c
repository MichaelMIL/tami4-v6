// address 0x00bb1a  size 16 bytes
// callers: 00b7e6,00b772,

/* Auto: reads cfg_systemconfig2; 8 instr */

char mod_get_cfg_systemconfig2_bb1a(void)

{
  return '\x05' - ((cfg_systemconfig2 & 0x38) >> 3);
}

