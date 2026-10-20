// address 0x00b256  size 554 bytes
// callers: 00fc08,

/* WARNING: Instruction at (CODE,0x00b276) overlaps instruction at (CODE,0x00b274)
    */
/* Hardware init, load SYSTEMCONFIG bytes, create Salvo tasks, run scheduler forever */

void main(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char cVar13;
  byte unaff_C;
  
  main_init_flag = 0;
  tick_div_100ms = 0;
  tick_div_1s = 0;
  sec_div_10s = 0;
  sec_div_60s = 0;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & ~nRBPU;
  cVar13 = '<';
  do {
    cVar13 = cVar13 + -1;
  } while (cVar13 != '\0');
  bVar1 = TRISB;
  TRISB = bVar1 | TRISB5;
  bVar1 = PORTB;
  factory_jumper = (bVar1 & RB5) == 0;
  bVar1 = INTCON2;
  INTCON2 = bVar1 | nRBPU;
  os_set_OScTcbP_9ad4();
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  *(undefined1 *)in_FSR1 = 0;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x9e;
  puVar2 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = 0;
  OSCreateSem();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar2[-2];
  puVar2[-3] = 0;
  puVar2[-2] = 0xa2;
  puVar2[-1] = 0;
  OSCreateSem();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar3 = puVar2 + -3;
  puVar2[-2] = puVar2[-2];
  hw_init_peripherals();
  standby_countdown = 0xff;
  sleep_countdown = 0xff;
  outputs_all_off();
  serial_init();
  params_verify();
  system_mode = 0;
  puVar4 = puVar3 + 1;
  *puVar3 = 0x23;
  cfg_sleep_delay = eeprom_read_param();
  *puVar4 = *puVar4;
  sleep_check_period = 10;
  puVar4[-1] = 0x25;
  cfg_systemconfig = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x2b;
  cfg_systemconfig2 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x2c;
  cfg_systemconfig3 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x3a;
  cfg_systemconfig4 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x41;
  cfg_systemconfig5 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x45;
  cfg_systemconfig6 = eeprom_read_param();
  puVar5 = puVar4 + -1;
  *puVar4 = *puVar4;
  if (factory_jumper != '\0') {
    cfg_systemconfig = cfg_systemconfig | 0xbf;
    cfg_systemconfig2 = 0x68;
    cfg_systemconfig3 = cfg_systemconfig3 & 0x46 | 0x44;
    cfg_systemconfig4 = 0xe7;
  }
  stats_load(factory_jumper);
  compressor_init();
  heater_init();
  alarm_init();
  inlet_valve_init();
  cold_valve_init();
  hot_valve_init();
  mod_set_r202_0_fca2();
  mod_set_r0ff_0_fc98();
  cooling_init();
  heating_init();
  dispense_init();
  uv_init();
  ui_init();
  fan_init();
  c18_tmp0 = beep_and_halt();
  serial_create_task(c18_tmp0 << 1 | unaff_C & 1);
  cooling_create_task();
  heating_create_task();
  dispense_create_task();
  uv_create_task();
  ui_create_task();
  fan_create_task();
  *puVar5 = 1;
  puVar5[1] = 0x86;
  puVar5[2] = 0;
  puVar5[3] = 0xaa;
  puVar6 = puVar5 + 5;
  puVar5[4] = 0xb0;
  c18_tmp0 = OSCreateTask();
  bVar1 = (byte)puVar6;
  if (bVar1 < 5) {
    puVar7 = (undefined1 *)((ushort)puVar6 & 0xff00);
    puVar6 = puVar7 + -1;
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)puVar6 >> 8),bVar1 - 5);
  *puVar8 = 4;
  puVar8[1] = 0x8c;
  puVar8[2] = 0;
  puVar8[3] = 4;
  puVar9 = puVar8 + 5;
  puVar8[4] = 0xb1;
  c18_tmp0 = OSCreateTask();
  bVar1 = (byte)puVar9;
  if (bVar1 < 5) {
    puVar10 = (undefined1 *)((ushort)puVar9 & 0xff00);
    puVar9 = puVar10 + -1;
    *puVar10 = *puVar10;
  }
  puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar9 >> 8),bVar1 - 5);
  bVar1 = INTCON;
  INTCON = bVar1 | (PEIE | GIE);
  puVar12 = puVar11 + 1;
  *puVar11 = 0x88;
  ui_get_buzzer_pattern_4850();
  *puVar12 = *puVar12;
  do {
    bVar1 = INTCON;
    INTCON = bVar1 | (PEIE | GIE);
    OSSched(0xc0);
  } while( true );
}

