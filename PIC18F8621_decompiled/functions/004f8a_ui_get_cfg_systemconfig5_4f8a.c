// address 0x004f8a  size 16 bytes
// callers: 004c34,002d86,

/* Auto: reads cfg_systemconfig5; 8 instr */

byte ui_get_cfg_systemconfig5_4f8a(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}

