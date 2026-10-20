// address 0x00d654  size 20 bytes
// callers: 006e5c,

/* Write parameter minimum to EEPROM (address + 0x96) */

void param_write_min(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  bVar2 = mod_frame_access_d782();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(byte *)in_FSR1 = bVar2 + 0x96;
  mod_to_eeprom_write_byte_d750();
  if (bVar2 < 0x6a) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_d6c6(c18_tmp0);
  return;
}

