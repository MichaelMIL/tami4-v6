// address 0x0098fc  size 24 bytes
// callers: 0025b4,00a312,0028b4,000a0e,00b772,00b7e6,009316,002594,

/* Auto: writes ui_hold_counter,buzzer_pattern; 11 instr */

void txt_set_ui_hold_counter_98fc(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  
  bVar1 = txt_frag_9a00();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe) = bVar1 - 5;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xf) = (char)((ushort)in_FSR1 >> 8) + -1 + (4 < bVar1);
  txt_get_printf_fmt_lo_999c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -4);
  txt_frame_push_args_9a9c(0xfc);
  return;
}

