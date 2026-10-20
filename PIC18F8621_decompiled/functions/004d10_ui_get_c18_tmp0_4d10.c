// address 0x004d10  size 20 bytes
// callers: 003584,

/* Auto: reads c18_tmp0,c18_tmp1,cfg_systemconfig3; 8 instr */

byte ui_get_c18_tmp0_4d10(void)

{
  return cfg_systemconfig3 & 4;
}

