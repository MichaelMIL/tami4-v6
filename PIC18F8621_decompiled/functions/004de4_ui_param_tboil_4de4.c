// address 0x004de4  size 22 bytes
// callers: 003b12,

/* Auto: reads params TBOIL,TDELTAHOTTOPNORMALCUTOUT; reads c18_tmp0; 10 instr */

char ui_param_tboil_4de4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  c18_tmp0 = ui_to_eeprom_read_param_4f64(0x15);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = c18_tmp0;
  cVar2 = ui_to_eeprom_read_param_4f64(0x16);
  *puVar1 = *puVar1;
  c18_tmp0 = puVar1[-1];
  return puVar1[-1] - cVar2;
}

