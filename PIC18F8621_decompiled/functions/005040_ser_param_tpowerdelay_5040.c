// address 0x005040  size 8 bytes
// callers: 003b12,

/* Auto: reads params TPOWERDELAY; 4 instr */

undefined1 ser_param_tpowerdelay_5040(void)

{
  undefined1 uVar1;
  
  uVar1 = ui_to_eeprom_read_raw_4dd4(0x31);
  return uVar1;
}

