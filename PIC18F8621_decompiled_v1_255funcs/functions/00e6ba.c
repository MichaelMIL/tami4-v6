// address 0x00e6ba

undefined1 FUN_CODE_00e6ba(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  
  DAT_DATA_01bb = 0;
  DAT_DATA_01be = 0;
  DAT_DATA_01bd = 0;
  DAT_DATA_01c1 = 0;
  DAT_DATA_01c2 = 0;
  DAT_DATA_01bf = 0;
  puVar1 = &FramePointer10x0001;
  cVar4 = FUN_CODE_00d67e();
  puVar2 = puVar1 + -1;
  *puVar1 = *puVar1;
  if (cVar4 == '\0') {
    cVar4 = FUN_CODE_00b53c();
    if (cVar4 == '\0') {
      DAT_DATA_01c0 = 0x1e;
    }
    else {
      DAT_DATA_01c0 = 0;
    }
  }
  else {
    DAT_DATA_01c0 = 0x78;
    puVar2 = puVar1 + -1;
  }
  puVar3 = puVar2 + 1;
  *puVar2 = 0x22;
  DAT_DATA_01bc = FUN_CODE_00d67e();
  *puVar3 = *puVar3;
  DAT_DATA_01ba = 0;
  return 0;
}

