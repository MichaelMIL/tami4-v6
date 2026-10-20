// address 0x00a8ea  size 24 bytes
// callers: 00a826,

/* Auto: calls fmt_byte; 9 instr */

void mod_to_fmt_byte_a8ea(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  fmt_byte();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  puVar2 = puVar1 + -2;
  puVar1[-3] = *(undefined1 *)in_FSR2;
  mod_get_lcd_text_width_ca24();
  *puVar2 = *puVar2;
  return;
}

