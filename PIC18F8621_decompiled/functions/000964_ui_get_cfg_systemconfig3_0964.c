// address 0x000964  size 6 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: reads cfg_systemconfig3; 3 instr */

void ui_get_cfg_systemconfig3_0964(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if ((cfg_systemconfig3 & 4) != 0) {
    ui_push_args_4c_096e();
    return;
  }
  puVar1 = &FramePointer10x0001;
  txt_to_mod_set_lcd_text_flag_92f2();
  *puVar1 = *puVar1;
  return;
}

