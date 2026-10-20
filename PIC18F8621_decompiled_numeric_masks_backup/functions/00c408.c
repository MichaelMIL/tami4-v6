// address 0x00c408

undefined1 FUN_CODE_00c408(void)

{
  char cVar1;
  char cVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar5 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  *puVar5 = 0;
  pbVar8 = puVar5 + 2;
  puVar5[1] = 0;
  puVar5[2] = 0;
  bVar9 = false;
  puVar3 = &FramePointer10x0003;
  while( true ) {
    puVar3[-2] = puVar3[-1] << 1 | bVar9;
    puVar3[1] = puVar3[2] << 1 | (char)puVar3[-1] < '\0';
    cVar1 = *pbVar8;
    *pbVar8 = cVar1 << 1 | (char)puVar3[2] < '\0';
    pbVar6 = pbVar8 + -2;
    cVar2 = pbVar8[-1];
    pbVar8[-1] = cVar2 << 1 | cVar1 < '\0';
    pbVar8[-2] = pbVar8[-2] << 1 | cVar2 < '\0';
    puVar4 = puVar3 + 6;
    bVar9 = puVar3[5] != '\0';
    cVar1 = puVar3[5] + -1;
    puVar3[4] = cVar1;
    if (cVar1 == '\0') break;
    FUN_CODE_00c44a();
    puVar7 = pbVar6 + 1;
    *pbVar6 = *pbVar6;
    FUN_CODE_00c44a();
    pbVar8 = puVar7 + 1;
    *puVar7 = *puVar7;
    FUN_CODE_00c44a();
    puVar3 = puVar4;
  }
  puVar3[6] = 0xff;
  return 0xff;
}

