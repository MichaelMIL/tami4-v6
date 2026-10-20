// address 0x00e7a4  size 32 bytes
// callers: 00b104,

/* Per second: heater usage counter, hold-off and power-up delay countdowns */

char heater_second_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  if ((outputs_shadow & 0x80) != 0) {
    puVar1 = &FramePointer10x0001;
    stat_counter_inc();
    *puVar1 = *puVar1;
  }
  if (heater_holdoff != '\0') {
    heater_holdoff = heater_holdoff + -1;
  }
  cVar2 = heater_powerup_delay;
  if (heater_powerup_delay != '\0') {
    heater_powerup_delay = heater_powerup_delay + -1;
  }
  return cVar2;
}

