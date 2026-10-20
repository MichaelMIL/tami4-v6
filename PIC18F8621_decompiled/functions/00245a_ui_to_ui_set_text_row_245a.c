// address 0x00245a  size 16 bytes
// callers: 000814,00089a,00092e,00066c,

/* Auto: Small wrapper around ui_set_text_row; 7 instr */

undefined1 ui_to_ui_set_text_row_245a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_chain_ui_to_lcd_clear_fn21d8_0450();
  puVar1 = (undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  ui_set_text_row_2b08();
  *puVar1 = 2;
  puVar1[1] = 0;
  return 2;
}

