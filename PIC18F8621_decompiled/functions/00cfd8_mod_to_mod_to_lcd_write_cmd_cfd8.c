// address 0x00cfd8  size 22 bytes
// callers: 001e3e,00cfc6,001ae2,

/* Auto: Small wrapper around mod_to_lcd_write_cmd; 11 instr */

void mod_to_mod_to_lcd_write_cmd_cfd8(void)

{
  BADSPACEBASE *in_FSR2;
  byte bVar1;
  
  bVar1 = mod_frame_access_d16c();
  mod_to_lcd_write_cmd_d15c(bVar1 >> 4 | 0x10);
  mod_to_lcd_write_cmd_d15c(*(byte *)((short)in_FSR2 + -2) & 0xf);
  mod_c18_epilogue_d130();
  return;
}

