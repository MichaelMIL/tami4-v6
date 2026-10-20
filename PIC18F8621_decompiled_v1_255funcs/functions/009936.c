// address 0x009936

void FUN_CODE_009936(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  FUN_CODE_009a5a();
  FUN_CODE_00999c();
  DAT_DATA_0e0e = (byte)in_FSR2 - 4;
  DAT_DATA_0e0f = (char)((ushort)in_FSR2 >> 8) + -1 + (3 < (byte)in_FSR2);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  FUN_CODE_0096c0();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar1[-3];
  FUN_CODE_009a26();
  FUN_CODE_00cb86();
  FUN_CODE_009aa8();
  return;
}

