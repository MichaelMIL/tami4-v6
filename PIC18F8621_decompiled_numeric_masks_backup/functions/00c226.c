// address 0x00c226

char FUN_CODE_00c226(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  short sVar8;
  char in_FramePointer1_00000003;
  byte in_FramePointer1_0000fffe;
  
  puVar3 = (undefined1 *)(ushort)in_FramePointer1_0000fffe;
  puVar6 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    puVar4 = puVar3 + 1;
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x000a;
  }
  *puVar6 = *puVar6;
  puVar6[1] = puVar6[1];
  puVar6[2] = (byte)(puVar6 + 2) - 2;
  puVar6[3] = (char)((ushort)(puVar6 + 2) >> 8) + -1 + (1 < (byte)(puVar6 + 2));
  puVar6[3] = puVar6[3];
  puVar7 = puVar6 + 6;
  puVar6[4] = puVar6[-1];
  FUN_CODE_00c2e2();
  bVar5 = (byte)puVar7;
  uVar2 = (ushort)puVar7 >> 8;
  FUN_CODE_00c2c2();
  if ((char)uVar2 + -1 + (4 < bVar5) == '\0') {
    FUN_CODE_00c2bc();
  }
  else {
    FUN_CODE_00c2d8();
    FUN_CODE_00c2ce();
  }
  FUN_CODE_00c2d8();
  *puVar4 = 0;
  bVar5 = (byte)puVar7 - 5;
  cVar1 = (char)((ushort)puVar7 >> 8) + -1 + (4 < (byte)puVar7);
  sVar8 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  return cVar1 + -1 + (2 < bVar5);
}

