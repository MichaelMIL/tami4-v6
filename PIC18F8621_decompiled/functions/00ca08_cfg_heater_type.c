// address 0x00ca08  size 10 bytes
// callers: 00c936,00c9bc,00c606,

/* cfg_systemconfig & 3 (0 = no heater fitted) */

byte cfg_heater_type(void)

{
  return cfg_systemconfig & 3;
}

