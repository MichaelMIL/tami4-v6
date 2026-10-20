// address 0x00dd24  size 16 bytes
// callers: 00da82,

/* APPLICATION setting (copy in UV module) */

byte uv_cfg_application(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}

