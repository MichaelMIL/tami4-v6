// address 0x00e2ba  size 22 bytes
// callers: 001582,003b12,00265e,

/* Auto: writes popup_flag; reads popup_index,popup_arg; calls ui_draw_progress_segment; 9 instr */

void mod_to_ui_draw_progress_segment_e2ba(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_e3fc();
  popup_index = *(undefined1 *)((short)in_FSR2 + -3);
  popup_arg = *(undefined1 *)((short)in_FSR2 + -1);
  popup_flag = 0;
  ui_draw_progress_segment();
  mod_c18_epilogue_e40e();
  return;
}

