// address 0x00d008

void FUN_CODE_00d008(void)

{
  BADSPACEBASE *in_FSR2;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  BADSPACEBASE *in_FSR1;
  char *pcVar4;
  byte bVar5;
  char cVar6;
  
  bVar5 = FUN_CODE_00d16c();
  cVar6 = '\a' - bVar5;
  if (bVar5 < 8) {
    cVar6 = '\x7f' - *(byte *)((short)in_FSR2 + -4);
    if (*(byte *)((short)in_FSR2 + -4) < 0x80) {
      *(char *)in_FSR1 = *(char *)((short)in_FSR2 + -2);
      pcVar1 = (char *)((short)in_FSR2 + 3);
      cVar6 = *(char *)in_FSR2;
      *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
      if (8 < (byte)(*(char *)in_FSR1 + cVar6)) {
        *(char *)in_FSR1 = *(char *)((short)in_FSR2 + 1);
        *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = '\t' - *(char *)in_FSR1;
        pcVar1 = (char *)((short)in_FSR2 + 5);
        *(char *)((short)in_FSR2 + 1) = *(char *)in_FSR1;
      }
      *(char *)in_FSR1 = pcVar1[-5];
      pcVar3 = pcVar1 + 2;
      cVar6 = pcVar1[-3];
      *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
      if (0x7f < (byte)(*(char *)in_FSR1 + cVar6)) {
        *(char *)in_FSR1 = pcVar1[-2];
        *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = -0x7f - *(char *)in_FSR1;
        pcVar3 = pcVar1 + 4;
        pcVar1[-2] = *(undefined1 *)in_FSR1;
      }
      DAT_DATA_01f2 = 0;
      while( true ) {
        cVar6 = DAT_DATA_01f2 - pcVar3[-3];
        if ((byte)pcVar3[-3] <= DAT_DATA_01f2) break;
        pcVar4 = (char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = pcVar3[-3];
        pcVar2 = pcVar3 + 3;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
        *pcVar4 = DAT_DATA_01f2 + *pcVar3;
        FUN_CODE_00d154();
        pcVar3 = pcVar2 + 1;
        FUN_CODE_00d144(pcVar2[-5] + '\x01');
      }
    }
  }
  FUN_CODE_00d130(cVar6);
  return;
}

