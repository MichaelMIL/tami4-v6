// address 0x00edc4  size 22 bytes
// callers: 00ed58,00ecee,00ed94,00ed38,

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 7 instr */

undefined1 mod_c18_prologue_edc4(void)

{
  BADSPACEBASE *in_FSR1;
  
  return *(undefined1 *)
          (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
}

