// address 0x00b5fa  size 16 bytes
// callers: 00b5ae,00b104,

/* APPLICATION setting (SYSTEMCONFIG5 bits5-6): 0 COLD ONLY, 1 HOT ONLY, 2 COLD/HOT, 3 COLD/ROOM */

byte cfg_application(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}

