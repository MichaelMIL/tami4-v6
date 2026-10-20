// address 0x0093ba  size 12 bytes
// callers: 004fb2,005052,

/* Auto: calls text_draw_char; 6 instr */

void txt_to_text_draw_char_93ba(void)

{
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char cVar2;
  
  cVar2 = txt_frame_access_99e2();
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = cVar2 + '\x06';
  text_draw_char();
  *pcVar1 = *pcVar1;
  txt_c18_epilogue_9972();
  return;
}

