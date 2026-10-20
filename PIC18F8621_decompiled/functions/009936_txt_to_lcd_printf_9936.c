// address 0x009936  size 46 bytes
// callers: 001ae2,

/* Auto: writes printf_args_lo,printf_args_hi; calls lcd_printf,text_measure_width; 20 instr */

void txt_to_lcd_printf_9936(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  txt_c18_prologue_9a5a();
  txt_get_printf_fmt_lo_999c();
  printf_args_lo = (byte)in_FSR2 - 4;
  printf_args_hi = (char)((ushort)in_FSR2 >> 8) + -1 + (3 < (byte)in_FSR2);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  lcd_printf();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar1[-3];
  txt_push_args_12_0e_9a26();
  text_measure_width();
  txt_stack_adjust_9aa8();
  return;
}

