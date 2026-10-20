// address 0x009aba  size 14 bytes
// callers: 0096c0,009a6c,

/* Language code from SYSTEMCONFIG2 bits 3-5 (0 EN, 4 RU, 5 HE) */

byte cfg_language(void)

{
  return (cfg_systemconfig2 & 0x38) >> 3;
}

