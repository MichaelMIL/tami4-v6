// address 0x0075e2

undefined1 FUN_CODE_0075e2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_0079ea();
  FUN_CODE_009f46();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  DAT_DATA_0169 = 0;
  DAT_DATA_016c = 0;
  DAT_DATA_016b = 0;
  DAT_DATA_0168 = DAT_DATA_0168 | 3;
  return 0;
}

