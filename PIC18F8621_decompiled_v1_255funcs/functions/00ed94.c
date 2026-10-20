// address 0x00ed94

void FUN_CODE_00ed94(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  bool bVar2;
  
  DAT_DATA_0032 = FUN_CODE_00edc4();
  DAT_DATA_0015 = 0xd < DAT_DATA_0032;
  DAT_DATA_0014 = DAT_DATA_0032 - 0xe;
  FUN_CODE_00edfc();
  *(undefined1 *)in_FSR1 = 1;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  DAT_DATA_0017 = 0;
  bVar2 = DAT_DATA_0032 < 0xdc;
  DAT_DATA_0016 = DAT_DATA_0032 + 0x24;
  FUN_CODE_00ede6(1);
  if (bVar2) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  FUN_CODE_00edda(DAT_DATA_0018);
  return;
}

