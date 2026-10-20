// address 0x003afc  size 22 bytes
// callers: 004dc8,

/* Auto: writes ui_message_timer,ui_screen; reads ui_header_text; 8 instr */

void ui_set_ui_message_timer_3afc(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  ui_header_text = *(undefined1 *)((short)in_FSR2 + -2);
  ui_message_timer = 6;
  ui_screen = 0;
  ui_c18_epilogue_4d6e();
  return;
}

