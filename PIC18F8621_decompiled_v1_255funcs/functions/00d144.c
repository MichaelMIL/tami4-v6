// address 0x00d144

void FUN_CODE_00d144(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  FUN_CODE_00cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  DAT_DATA_01f2 = DAT_DATA_01f2 + '\x01';
  return;
}

