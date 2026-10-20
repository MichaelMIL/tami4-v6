// address 0x004ed4  size 16 bytes
// callers: 0048b2,

/* Auto: reads c18_tmp0,c18_tmp1; 6 instr */

undefined1 ui_get_c18_tmp0_4ed4(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 in_FramePointer2_00000017;
  
  c18_tmp0 = 0;
  c18_tmp1 = (char)((ushort)in_FSR2 >> 8);
  return in_FramePointer2_00000017;
}

