// address 0x004c54  size 14 bytes
// callers: 00508e,003584,

/* Auto: Small wrapper around mod_get_lcd_text_width; 6 instr */

void ui_to_mod_get_lcd_text_width_4c54(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ser_chain_fn4f80_fn5036_50b2();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x20;
  mod_get_lcd_text_width_ca24();
  *puVar1 = *puVar1;
  return;
}

