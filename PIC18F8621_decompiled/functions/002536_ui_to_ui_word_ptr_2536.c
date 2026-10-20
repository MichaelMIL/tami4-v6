// address 0x002536  size 20 bytes
// callers: 00097a,001a54,

/* Auto: reads c18_tmp0,c18_tmp1; calls ui_word_ptr; 6 instr */

void ui_to_ui_word_ptr_2536(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  uVar1 = in_PRODL;
  ui_word_ptr();
  c18_tmp0 = uVar1;
  c18_tmp1 = in_PRODH;
  *(undefined1 *)in_FSR1 = c18_tmp0;
  *(undefined1 *)((short)in_FSR1 + 1) = in_PRODH;
  return;
}

