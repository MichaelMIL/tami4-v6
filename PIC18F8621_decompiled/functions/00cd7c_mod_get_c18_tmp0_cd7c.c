// address 0x00cd7c  size 26 bytes
// callers: 00cc5a,00ca50,

/* Auto: reads c18_tmp0,c18_tmp1,lcd_text_width; 11 instr */

undefined1 mod_get_c18_tmp0_cd7c(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte in_FramePointer2_0000fffe;
  
  bVar1 = (byte)((ushort)in_FramePointer2_0000fffe * 7);
  c18_tmp0 = bVar1 - 0x20;
  c18_tmp1 = (char)((ushort)in_FramePointer2_0000fffe * 7 >> 8) + '\x7f' + (0x1f < bVar1);
  return *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7);
}

