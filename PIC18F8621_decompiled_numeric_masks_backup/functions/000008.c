// address 0x000008

undefined1 thunk_FUN_CODE_00bcc0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 in_WS;
  
  puVar2 = &FramePointer10x0008;
  cVar6 = '\x14';
  puVar5 = (undefined1 *)0x0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  cVar6 = '\x10';
  puVar5 = &DAT_DATA_0014;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar3 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  puVar4 = puVar2 + 1;
  *puVar2 = *puVar2;
  thunk_FUN_CODE_007628();
  *puVar4 = *puVar4;
  cVar6 = '\x10';
  puVar5 = puVar4 + -1;
  puVar7 = &DAT_DATA_0023;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  cVar6 = '\x14';
  puVar7 = &DAT_DATA_0013;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  return in_WS;
}

