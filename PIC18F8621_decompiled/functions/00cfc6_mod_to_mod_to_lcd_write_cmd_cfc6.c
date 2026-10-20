// address 0x00cfc6  size 18 bytes
// callers: 00e488,00d154,00a9c2,00a414,00238c,00f3b4,009a30,00f278,00ba5a,004c62,00293a,

/* Auto: Small wrapper around mod_to_lcd_write_cmd; 8 instr */

void mod_to_mod_to_lcd_write_cmd_cfc6(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  bVar2 = mod_frame_access_d16c();
  mod_to_lcd_write_cmd_d15c(bVar2 | 0xb0);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  mod_to_mod_to_lcd_write_cmd_cfd8();
  *puVar1 = *puVar1;
  mod_c18_epilogue_d130();
  return;
}

