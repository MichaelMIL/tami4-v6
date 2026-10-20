// address 0x00d6d2

undefined1 FUN_CODE_00d6d2(byte param_1)

{
  byte in_TBLPTRL;
  char in_TBLPTRH;
  
  DAT_DATA_0014 = in_TBLPTRL + param_1;
  DAT_DATA_0015 = in_TBLPTRH + CARRY1(in_TBLPTRL,param_1);
  return 1;
}

