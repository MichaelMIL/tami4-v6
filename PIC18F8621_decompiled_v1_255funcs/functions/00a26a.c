// address 0x00a26a

byte FUN_CODE_00a26a(void)

{
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a302();
  return *(byte *)((short)in_FSR0 + 1) | *(byte *)in_FSR0;
}

