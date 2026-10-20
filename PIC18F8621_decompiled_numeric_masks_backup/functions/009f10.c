// address 0x009f10

undefined1 FUN_CODE_009f10(void)

{
  DAT_DATA_00b0 = DAT_DATA_00b0 + '\x01';
  DAT_DATA_0014 = bDATA00b1;
  DAT_DATA_0015 = 0;
  if (0xfe < bDATA00b1 != true) {
    return 1;
  }
  bDATA00b1 = bDATA00b1 + 1;
  return 0;
}

