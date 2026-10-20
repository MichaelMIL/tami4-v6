// address 0x00ede6

char FUN_CODE_00ede6(char param_1)

{
  char cVar1;
  byte unaff_C;
  
  DAT_DATA_0017 = DAT_DATA_0017 + param_1 + (unaff_C & 1);
  cVar1 = '\x02';
  DAT_DATA_0018 = FUN_CODE_00e060();
  return cVar1 + -6;
}

