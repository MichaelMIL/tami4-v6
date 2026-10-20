// address 0x00d668  size 22 bytes
// callers: 00d67e,00da78,00a94c,002b00,00bfec,00ec76,004dd4,0079b6,00b4a6,

/* Read EEPROM byte at address */

void eeprom_read_raw(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte unaff_C;
  
  mod_c18_prologue_d6b4();
  mod_push_args_32_00_01_d700();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  mod_to_eeprom_read_byte_d724();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_frag_d76a();
  mod_c18_epilogue_d6c6();
  return;
}

