// address 0x00e6ba  size 70 bytes
// callers: 00b256,

/* Initialise heater state; power-up delay (30 s, 120 s if TPOWERDELAY set, 0 with factory jumper)
    */

undefined1 heater_init(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  
  heater_power_level = 0;
  heater_maxon_timer = 0;
  heater_zc_counter = 0;
  heater_pattern_lo = 0;
  heater_pattern_hi = 0;
  heater_holdoff = 0;
  puVar1 = &FramePointer10x0001;
  cVar4 = eeprom_read_param();
  puVar2 = puVar1 + -1;
  *puVar1 = *puVar1;
  if (cVar4 == '\0') {
    cVar4 = is_factory_jumper();
    if (cVar4 == '\0') {
      heater_powerup_delay = 0x1e;
    }
    else {
      heater_powerup_delay = 0;
    }
  }
  else {
    heater_powerup_delay = 0x78;
    puVar2 = puVar1 + -1;
  }
  puVar3 = puVar2 + 1;
  *puVar2 = 0x22;
  heater_zc_cycle_len = eeprom_read_param();
  *puVar3 = *puVar3;
  heater_fault = 0;
  return 0;
}

