// address 0x00c9f0  size 16 bytes
// callers: 00c606,

/* APPLICATION setting (copy in heating module) */

byte cfg_application_b(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}

