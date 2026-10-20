// address 0x000018

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 thunk_FUN_CODE_00bd4a(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  bool bVar10;
  
  puVar3 = &FramePointer10x000b;
  cVar8 = '\x14';
  puVar7 = (undefined1 *)0x0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar2 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  cVar8 = '\x10';
  puVar7 = &DAT_DATA_0014;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar4 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar4 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  puVar5 = puVar3 + 1;
  puVar6 = puVar3 + 1;
  *puVar3 = *puVar3;
  bVar1 = INTCON;
  if (((bVar1 & 0x20) == 0) || (bVar1 = INTCON, (bVar1 & 4) == 0)) {
    FUN_CODE_00b49c();
    puVar7 = puVar6;
  }
  else {
    bVar1 = INTCON;
    INTCON = bVar1 & 0xfb;
    bVar1 = TMR0L;
    cVar8 = TMR0H;
    DAT_DATA_0edc = bVar1 + DAT_DATA_0eda;
    DAT_DATA_0edd = cVar8 + DAT_DATA_0edb + CARRY1(bVar1,DAT_DATA_0eda);
    TMR0H = DAT_DATA_0edd;
    TMR0L = DAT_DATA_0edc;
    if (DAT_DATA_0ede == '\0') {
      FUN_CODE_00b482(0);
      puVar7 = puVar5;
    }
    else {
      DAT_DATA_0edf = DAT_DATA_0edf + '\x01';
      puVar7 = puVar3 + 1;
      if (DAT_DATA_0edf == 'd') {
        DAT_DATA_0edf = '\0';
        puVar7 = puVar3 + 1;
      }
    }
  }
  *puVar7 = *puVar7;
  cVar8 = '\x10';
  puVar7 = puVar7 + -1;
  puVar9 = &DAT_DATA_0023;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  cVar8 = '\x14';
  puVar9 = &DAT_DATA_0013;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  return puVar7[-8];
}

