// address 0x009b64

void FUN_CODE_009b64(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  BADSPACEBASE *in_FSR1;
  byte *pbVar9;
  char cVar10;
  undefined1 uVar11;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a28c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  pbVar9 = (byte *)((short)in_FSR1 + 4);
  cVar10 = *(char *)((short)in_FSR1 + 3);
  *(char *)((short)in_FSR1 + 3) = cVar10;
  FUN_CODE_00a19c();
  FUN_CODE_00a2fc();
  if (cVar10 == '\0') {
    FUN_CODE_00a19c();
    FUN_CODE_00a200();
    FUN_CODE_00a160();
    *(undefined1 *)((short)in_FSR0 + 4) = 0;
    *(undefined1 *)((short)in_FSR0 + 6) = 0;
    DAT_DATA_0014 = 0;
  }
  else {
    *(undefined1 *)((short)in_FSR2 + 3) = 0;
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + 5) = 0;
    FUN_CODE_00a232();
    if (DAT_DATA_0015 == '\0') {
      cVar10 = FUN_CODE_00a2ec(0);
      puVar2[(short)cVar10 + 1] = *(undefined1 *)in_FSR0;
      while( true ) {
        puVar4 = puVar2 + 1;
        FUN_CODE_00a160();
        FUN_CODE_00a1ca();
        DAT_DATA_0014 = *(byte *)in_FSR0;
        puVar5 = puVar4 + 1;
        cVar10 = DAT_DATA_0014 - puVar4[5];
        puVar6 = puVar4 + 1;
        if ((DAT_DATA_0014 < (byte)puVar4[5]) ||
           (FUN_CODE_00a1ba(cVar10), puVar6 = puVar5, cVar10 == '\0')) break;
        cVar10 = FUN_CODE_00a2ec();
        puVar2 = puVar5 + 1;
        *pbVar9 = puVar5[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 + *(char *)in_FSR0;
        puVar5[6] = *pbVar9;
      }
      FUN_CODE_00a26a();
      puVar7 = puVar6;
      if (cVar10 != '\0') {
        cVar10 = FUN_CODE_00a2ec();
        *pbVar9 = puVar6[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 - *(char *)in_FSR0;
        puVar7 = puVar6 + 2;
        puVar6[6] = *pbVar9;
      }
      FUN_CODE_00a160();
      cVar10 = FUN_CODE_00a292();
      puVar8 = puVar7 + 1;
      cVar1 = puVar7[(short)cVar10 + 1];
      cVar10 = *(char *)in_FSR0;
      *(char *)in_FSR0 = cVar10 - cVar1;
      FUN_CODE_00a26a();
      puVar6 = puVar8;
      if (cVar10 - cVar1 != '\0') {
        FUN_CODE_00a2f2();
        cVar10 = FUN_CODE_00a2ec();
        *(char *)in_FSR0 = *(char *)in_FSR0 - puVar8[(short)cVar10 + 1];
        puVar6 = puVar8 + 1;
      }
    }
    else {
      FUN_CODE_00a160();
      *pbVar9 = *(byte *)in_FSR0 & 0xf;
      puVar2[5] = *pbVar9;
      puVar7 = puVar2 + 1;
      do {
        FUN_CODE_00a272();
        puVar3 = puVar7 + 1;
        cVar10 = puVar7[5] - (*(byte *)in_FSR0 & 0xf);
        puVar6 = puVar7 + 1;
        if ((byte)puVar7[5] < (*(byte *)in_FSR0 & 0xf)) break;
        FUN_CODE_00a1ba(cVar10);
        puVar6 = puVar3;
        puVar7 = puVar3;
      } while (cVar10 != '\0');
    }
    FUN_CODE_00a20e();
    if ((char)puVar6 == -2) {
      uVar11 = FUN_CODE_00a19c();
    }
    else {
      FUN_CODE_00a252();
      uVar11 = 0;
    }
    FUN_CODE_00a200(uVar11);
    FUN_CODE_00a160();
    DAT_DATA_0014 = FUN_CODE_00a298();
  }
  if ((byte)pbVar9 < 5) {
    *(undefined1 *)((ushort)pbVar9 & 0xff00) = *(undefined1 *)((ushort)pbVar9 & 0xff00);
  }
  FUN_CODE_00a180(DAT_DATA_0014);
  return;
}

