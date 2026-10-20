// address 0x009914  size 34 bytes
// callers: 002b10,002718,

/* Auto: writes ui_hold_counter,buzzer_pattern; reads printf_fmt_lo,printf_fmt_hi; 14 instr */

void txt_set_ui_hold_counter_9914(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  
  bVar1 = txt_frag_9a00();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe) = bVar1 - 6;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xf) = (char)((ushort)in_FSR1 >> 8) + -1 + (5 < bVar1);
  printf_fmt_lo = *(undefined1 *)((short)in_FSR2 + -3);
  printf_fmt_hi = *(undefined1 *)((short)in_FSR2 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  txt_frame_push_args_9a9c(0xfb);
  return;
}

