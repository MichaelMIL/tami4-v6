// address 0x00a20e

byte FUN_CODE_00a20e(undefined1 param_1)

{
  char in_FSR2H;
  byte *pbVar1;
  byte unaff_C;
  
  pbVar1 = (byte *)CONCAT11(in_FSR2H + (unaff_C & 1),param_1);
  return pbVar1[1] | *pbVar1;
}

