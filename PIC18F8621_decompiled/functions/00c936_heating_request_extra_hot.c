// address 0x00c936  size 76 bytes
// callers: 006e5c,003b12,002d86,

/* Start extra-hot mode (if allowed); load TEMPHOTCHNGTIME */

undefined1 heating_request_extra_hot(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  byte unaff_Z;
  
  cfg_heater_type();
  if ((unaff_Z & 1) != 0) {
    return 0;
  }
  if ((heating_flags & 1) != 0) {
    return 0;
  }
  cVar2 = heater_is_ready();
  if (cVar2 == '\0') {
    return 0;
  }
  if (heating_fault != -0x73) {
    if (heating_fault != -0x72) {
      if (heating_fault != -0x71) {
        puVar1 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 5;
        stat_counter_inc();
        *puVar1 = *puVar1;
        puVar1[-1] = 5;
        stat_counter_save();
        *puVar1 = *puVar1;
        extra_hot_timer = heating_read_param(0x27);
        heating_flags = heating_flags | 1;
        return 1;
      }
    }
  }
  return 0;
}

