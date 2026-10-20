// address 0x00f3ce

/* WARNING: Instruction at (CODE,0x00f414) overlaps instruction at (CODE,0x00f412)
    */

undefined1 FUN_CODE_00f3ce(void)

{
  DAT_DATA_0000 = 0;
  if ((DAT_DATA_000e & 0x80) != 0) {
    DAT_DATA_000d = -DAT_DATA_000d;
    DAT_DATA_000e = ~DAT_DATA_000e + ('\0' < DAT_DATA_000d);
    DAT_DATA_0000 = 0xff;
  }
  if ((DAT_DATA_0009 & 0x80) != 0) {
    DAT_DATA_0008 = -DAT_DATA_0008;
    DAT_DATA_0009 = ~DAT_DATA_0009 + ('\0' < DAT_DATA_0008);
    DAT_DATA_0000 = ~DAT_DATA_0000;
  }
  FUN_CODE_00fbbc();
  if ((DAT_DATA_0009 & 0x80) == 0) {
    if ((DAT_DATA_0000 & 0x80) == 0) {
      return 0;
    }
  }
  else if ((DAT_DATA_0000 & 0x80) == 0) {
    DAT_DATA_0001 = DAT_DATA_0001 | 0x10;
    return 0xff;
  }
  DAT_DATA_0008 = -DAT_DATA_0008;
  DAT_DATA_0009 = ~DAT_DATA_0009 + ('\0' < DAT_DATA_0008);
  DAT_DATA_0004 = -DAT_DATA_0004;
  DAT_DATA_0005 = ~DAT_DATA_0005 + ('\0' < DAT_DATA_0004);
  return 0;
}

