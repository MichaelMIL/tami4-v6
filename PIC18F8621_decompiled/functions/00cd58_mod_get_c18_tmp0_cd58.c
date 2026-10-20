// address 0x00cd58  size 28 bytes
// callers: 00ca3a,00ca24,

/* Auto: reads c18_tmp0,c18_tmp1,lcd_text_width; 11 instr */

void mod_get_c18_tmp0_cd58(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte in_FramePointer2_0000fffe;
  
  bVar1 = (byte)((ushort)in_FramePointer2_0000fffe * 5);
  c18_tmp0 = bVar1 - 0x20;
  c18_tmp1 = (char)((ushort)in_FramePointer2_0000fffe * 5 >> 8) + 'z' + (0x1f < bVar1);
  mod_get_TBLPTRL_cdf4(*(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7));
  return;
}

