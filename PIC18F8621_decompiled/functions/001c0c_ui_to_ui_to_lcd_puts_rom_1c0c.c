// address 0x001c0c  size 38 bytes
// callers: 001b4a,

/* Auto: Small wrapper around ui_to_lcd_puts_rom; 16 instr */

void ui_to_ui_to_lcd_puts_rom_1c0c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  char cVar3;
  
  cVar3 = ui_frag_2b16();
  if (*(char *)((short)in_FSR2 + (short)cVar3 + 1) == '\0') {
    *(undefined1 *)in_FSR1 = 0x7f;
  }
  else {
    *(undefined1 *)in_FSR1 = 0x89;
  }
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  ui_to_lcd_puts_rom_23f6(0x58);
  puVar2 = puVar1 + 1;
  *puVar1 = 0x20;
  mod_get_lcd_text_width_ca24();
  *puVar2 = *puVar2;
  ui_c18_epilogue_21d8();
  return;
}

