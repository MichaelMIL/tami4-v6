// address 0x00cd7c

undefined1 FUN_CODE_00cd7c(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte in_FramePointer2_0000fffe;
  
  bVar1 = (byte)((ushort)in_FramePointer2_0000fffe * 7);
  DAT_DATA_0014 = bVar1 - 0x20;
  DAT_DATA_0015 = (char)((ushort)in_FramePointer2_0000fffe * 7 >> 8) + '\x7f' + (0x1f < bVar1);
  return *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7);
}

