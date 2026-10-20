// address 0x00cf6e

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cf6e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  
  FUN_CODE_00d11e();
  DAT_DATA_01f0 = *(char *)((short)in_FSR2 + -3);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  while( true ) {
    if (DAT_DATA_01f0 == '\0') break;
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    puVar2 = puVar1 + 1;
    *(undefined1 *)in_FSR1 = puVar1[-2];
    DAT_DATA_01f0 = DAT_DATA_01f0 + -1;
    FUN_CODE_00cefe();
    in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
    *puVar3 = *puVar3;
    puVar1 = puVar2;
  }
  DAT_DATA_01f0 = DAT_DATA_01f0 + -1;
  FUN_CODE_00d130(0);
  return;
}

