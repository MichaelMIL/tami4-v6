// address 0x0024ca  size 8 bytes
// callers: 0029be,001644,001780,

/* Draw word then push 6 */

undefined1 ui_draw_word_push6(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_draw_word();
  *(undefined1 *)in_FSR1 = 6;
  return 6;
}

