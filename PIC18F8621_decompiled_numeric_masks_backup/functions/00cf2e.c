// address 0x00cf2e

void FUN_CODE_00cf2e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char cVar3;
  char *in_TBLPTR;
  undefined1 uVar4;
  
  FUN_CODE_00d11e();
  do {
    *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + '\x01';
    puVar1 = (undefined1 *)((short)in_FSR2 + 4);
    uVar4 = (undefined1)((uint3)in_TBLPTR >> 0x10);
    in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(*(undefined1 *)((short)in_FSR2 + 1),
                                                *(undefined1 *)((short)in_FSR2 + -3)));
    if (*(char *)((short)in_FSR2 + -1) == -1) {
      puVar1 = (undefined1 *)((short)in_FSR2 + 6);
      *(char *)((short)in_FSR2 + 2) = *(char *)((short)in_FSR2 + 3) + '\x01';
    }
    DAT_DATA_01f0 = *in_TBLPTR;
    if (DAT_DATA_01f0 == '\0') {
      in_FSR2 = (BADSPACEBASE *)(puVar1 + 2);
      in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(puVar1[-1],puVar1[-3]));
      cVar3 = *in_TBLPTR;
      if (cVar3 == '\0') {
        FUN_CODE_00d130(0);
        return;
      }
      *(undefined1 *)in_FSR1 = 0;
    }
    else {
      *(char *)in_FSR1 = DAT_DATA_01f0;
      in_FSR2 = (BADSPACEBASE *)puVar1;
      cVar3 = DAT_DATA_01f0;
    }
    pcVar2 = (char *)((short)in_FSR1 + 1);
    FUN_CODE_00cefe(cVar3);
    in_FSR1 = (BADSPACEBASE *)(pcVar2 + -1);
    *pcVar2 = *pcVar2;
  } while( true );
}

