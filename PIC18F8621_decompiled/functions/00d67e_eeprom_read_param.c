// address 0x00d67e  size 34 bytes
// callers: 00b022,00dd1a,004f64,004264,00d794,0017a2,00e6ba,00e892,00d490,00b4d2,00c9e6,00122e,00b5ae,00f816,00f9fe,00ea76,00f76a,00b256,

/* Read one EEPROM byte (address = parameter id - 1) */

void eeprom_read_param(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  mod_c18_prologue_d6b4();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  eeprom_read_raw();
  *puVar2 = *puVar2;
  uVar3 = adc_raw_lo;
  if (fault_code < '\0') {
    puVar2[-1] = puVar1[-2];
    uVar3 = param_table_lookup();
    *puVar2 = *puVar2;
  }
  mod_c18_epilogue_d6c6(uVar3);
  return;
}

