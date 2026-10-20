// address 0x00f8bc  size 30 bytes
// callers: 00da82,

/* Switch UV lamp on (RF6) if UV fitted */

undefined1 uv_lamp_on(void)

{
  byte bVar1;
  
  if ((outputs_shadow & 0x20) == 0) {
    if ((cfg_systemconfig & 8) != 0) {
      bVar1 = PORTF;
      PORTF = bVar1 | RF6;
      outputs_shadow = outputs_shadow | 0x20;
      return uv_alarm_code;
    }
  }
  return 0;
}

