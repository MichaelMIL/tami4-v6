// address 0x0093c6  size 40 bytes
// callers: 0093ba,00a826,004fa8,009316,003b12,

/* Draw one character */

void text_draw_char(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  
  cVar2 = txt_frame_access_99e2();
  if (cVar2 == '\a') {
    *(undefined1 *)in_FSR1 = 0x5b;
    uVar3 = 0x12;
  }
  else {
    *(undefined1 *)in_FSR1 = 0x5f;
    uVar3 = 0x10;
  }
  *(undefined1 *)((short)in_FSR1 + 1) = uVar3;
  *(undefined1 *)((short)in_FSR1 + 2) = 1;
  puVar1 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR2 + -2);
  lcd_draw_glyph();
  *puVar1 = *puVar1;
  txt_stack_adjust_9aa8();
  return;
}

