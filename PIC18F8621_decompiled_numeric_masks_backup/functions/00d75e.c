// address 0x00d75e

byte FUN_CODE_00d75e(void)

{
  byte unaff_C;
  
  DAT_DATA_0201 = DAT_DATA_0016;
  return DAT_DATA_0016 << 1 | unaff_C & 1;
}

