// address 0x00e70a  size 96 bytes
// callers: 00c606,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Switch heater on at a power level (loads burst pattern from ROM 0xFC5C) */

void heater_set_power(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined3 in_TBLPTR;
  undefined1 uVar6;
  undefined1 *puVar5;
  
  uVar6 = (undefined1)((uint3)in_TBLPTR >> 0x10);
  mod_c18_prologue_e880();
  if (heater_powerup_delay == '\0') {
    cVar4 = heater_fault;
    if (-1 < heater_fault) {
      puVar2 = (undefined1 *)((short)in_FSR2 + 1);
      if (heater_power_level == *(char *)((short)in_FSR2 + -2)) {
        cVar4 = '\x01';
      }
      else {
        puVar3 = (undefined1 *)((short)in_FSR2 + 1);
        if (heater_power_level == '\0') {
          heater_load_maxon(0);
          puVar3 = puVar2;
        }
        bVar1 = INTCON;
        INTCON = bVar1 & ~(PEIE | GIE);
        heater_power_level = puVar3[-2];
        heater_zc_counter = 0;
        bVar1 = (heater_power_level + -1) * '\x02';
        puVar5 = (undefined1 *)
                 CONCAT12(uVar6,CONCAT11((heater_power_level + -1 < '\0') + -4 + (0xa3 < bVar1),
                                         bVar1 + 0x5c));
        heater_pattern_lo = *puVar5;
        heater_pattern_hi = puVar5[1];
        fan_start_heater_runon();
        bVar1 = INTCON;
        INTCON = bVar1 | (PEIE | GIE);
        cVar4 = '\0';
      }
    }
  }
  else {
    cVar4 = -0x7d;
  }
  mod_c18_epilogue_e8a2(cVar4);
  return;
}

