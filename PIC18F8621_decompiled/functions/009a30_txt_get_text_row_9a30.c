// address 0x009a30  size 14 bytes
// callers: 0093ee,

/* Auto: reads text_row; 5 instr */

void txt_get_text_row_9a30(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

