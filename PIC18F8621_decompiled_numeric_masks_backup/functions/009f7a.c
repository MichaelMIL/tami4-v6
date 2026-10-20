// address 0x009f7a

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_009f7a(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR0;
  byte *pbVar3;
  
  FUN_CODE_00a28c();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  FUN_CODE_00a1aa();
  FUN_CODE_00a286();
  DAT_DATA_0014 = *(byte *)in_FSR0;
  DAT_DATA_0015 = 0;
  if (0xfe < DAT_DATA_0014 == true) {
    FUN_CODE_00a286(0);
    cVar1 = *(char *)in_FSR0;
    *(char *)in_FSR0 = cVar1 + '\x01';
    FUN_CODE_00a160();
    FUN_CODE_00a2fc();
    if (cVar1 + '\x01' != '\0') {
      if ((DAT_DATA_00ad | DAT_DATA_00ac) == 0) {
        DAT_DATA_00ac = *(byte *)in_FSR2;
        DAT_DATA_00ad = *(byte *)((short)in_FSR2 + 1);
      }
      else {
        in_FSR0 = (BADSPACEBASE *)CONCAT11(DAT_DATA_00ab,DAT_DATA_00aa);
        FUN_CODE_00a298(DAT_DATA_00ad | DAT_DATA_00ac);
      }
      DAT_DATA_00aa = *(undefined1 *)in_FSR2;
      DAT_DATA_00ab = *(undefined1 *)((short)in_FSR2 + 1);
      FUN_CODE_00a272();
      FUN_CODE_00a1ee();
      pbVar3 = (byte *)((short)in_FSR0 + 1);
      DAT_DATA_0014 = *(byte *)in_FSR0;
      DAT_DATA_0015 = *(byte *)((short)in_FSR0 + 1);
      FUN_CODE_00a160();
      *pbVar3 = DAT_DATA_0014;
      pbVar3[1] = DAT_DATA_0015;
      FUN_CODE_00a272();
      pbVar3[4] = 0;
      pbVar3[6] = 0;
    }
    *(undefined1 *)in_FSR2 = 0;
  }
  else {
    *(undefined1 *)in_FSR2 = 4;
  }
  FUN_CODE_00a2d4();
  *puVar2 = *puVar2;
  FUN_CODE_00a180();
  return;
}

