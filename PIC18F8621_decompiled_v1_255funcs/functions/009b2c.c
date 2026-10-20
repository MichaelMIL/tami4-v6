// address 0x009b2c

void FUN_CODE_009b2c(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a28c();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(byte *)((short)in_FSR2 + -4) < 0x10) {
    *(undefined1 *)((short)in_FSR2 + 1) = 0;
  }
  else {
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + -3) = 0xf;
    *(undefined1 *)((short)in_FSR2 + 2) = 1;
  }
  puVar3 = puVar2 + 1;
  DAT_DATA_0014 = puVar2[-4];
  FUN_CODE_00a160();
  *(byte *)in_FSR0 = DAT_DATA_0014 & 0xf | *(byte *)in_FSR0 & 0xf0;
  uVar1 = *puVar3;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  FUN_CODE_00a180(uVar1);
  return;
}

