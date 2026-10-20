// address 0x0099c0

byte FUN_CODE_0099c0(void)

{
  BADSPACEBASE *in_FSR2;
  
  FUN_CODE_009a5a();
  return *(byte *)((short)in_FSR2 + -3) ^ 4;
}

