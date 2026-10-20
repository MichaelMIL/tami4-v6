// address 0x002b90  size 12 bytes
// callers: 0027a4,002536,002790,

/* Return pointer to UI word in current language */

void ui_word_ptr(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  word_lookup_a();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

