// address 0x009a9c  size 12 bytes
// callers: 0098fc,009914,

/* Auto: Copy stack-frame arguments onto the stack for a call; 5 instr */

void txt_frame_push_args_9a9c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  txt_to_lcd_printf_98dc();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  txt_c18_epilogue_9972();
  return;
}

