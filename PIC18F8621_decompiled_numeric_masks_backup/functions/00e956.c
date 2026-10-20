// address 0x00e956

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 FUN_CODE_00e926(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte bVar4;
  bool bVar5;
  
  bVar2 = 0xe;
  if ((DAT_DATA_0ee0 & 0x40) == 0) {
    return 1;
  }
  bVar4 = FUN_CODE_00b53c();
  if (bVar4 == 0) {
    FUN_CODE_00ea76(9);
    bVar4 = FUN_CODE_00ea80();
    if ((DAT_DATA_0ee3 & 0x80) == 0) {
      bVar5 = DAT_DATA_0ee3 != ~(bVar4 <= DAT_DATA_0ee2);
      bVar4 = DAT_DATA_0ee3 - ~(bVar4 <= DAT_DATA_0ee2);
    }
    else {
      bVar5 = false;
    }
    if (bVar5) goto LAB_CODE_00e956;
    bVar4 = 0xc;
    DAT_DATA_0ee2 = 0xc;
  }
  else {
    bVar2 = 1;
    DAT_DATA_01e2 = 0;
  }
  *(undefined1 *)((ushort)bVar2 * 0x100 + 0xe3) = 0;
LAB_CODE_00e956:
  bVar2 = PORTG;
  PORTG = bVar2 & 0xf7;
  DAT_DATA_0ee0 = DAT_DATA_0ee0 & 0xbf;
  FUN_CODE_00d926(bVar4);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  FUN_CODE_004bd8();
  *puVar3 = *puVar3;
  puVar3[-1] = 0xc;
  FUN_CODE_00ed58();
  *puVar3 = *puVar3;
  cVar1 = DAT_DATA_00f2 - DAT_DATA_01e6;
  if (DAT_DATA_00f2 < DAT_DATA_01e6) {
    DAT_DATA_00f2 = DAT_DATA_01e6;
    puVar3[-1] = 0;
    FUN_CODE_00ed94(cVar1);
    *puVar3 = *puVar3;
  }
  return 0;
}

