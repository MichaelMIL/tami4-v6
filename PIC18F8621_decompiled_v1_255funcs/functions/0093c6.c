// address 0x0093c6

void FUN_CODE_0093c6(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  
  cVar2 = FUN_CODE_0099e2();
  if (cVar2 == '\a') {
    *(undefined1 *)in_FSR1 = 0x5b;
    uVar3 = 0x12;
  }
  else {
    *(undefined1 *)in_FSR1 = 0x5f;
    uVar3 = 0x10;
  }
  *(undefined1 *)((short)in_FSR1 + 1) = uVar3;
  *(undefined1 *)((short)in_FSR1 + 2) = 1;
  puVar1 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_00d008();
  *puVar1 = *puVar1;
  FUN_CODE_009aa8();
  return;
}

