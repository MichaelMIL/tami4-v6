// address 0x00ed58

void FUN_CODE_00ed58(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  DAT_DATA_0032 = FUN_CODE_00edc4();
  bVar1 = (byte)((ushort)DAT_DATA_0032 * 4);
  DAT_DATA_0014 = bVar1 + 0xb2;
  DAT_DATA_0015 = (char)((ushort)DAT_DATA_0032 * 4 >> 8) + (0x4d < bVar1);
  FUN_CODE_00edfc();
  *(undefined1 *)in_FSR1 = 4;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  bVar2 = DAT_DATA_0032 * '\x04';
  DAT_DATA_0017 = 0;
  DAT_DATA_0016 = bVar2 - 0x1c;
  FUN_CODE_00ede6(0);
  if (bVar2 < 0x1c) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  FUN_CODE_00edda(DAT_DATA_0018);
  return;
}

