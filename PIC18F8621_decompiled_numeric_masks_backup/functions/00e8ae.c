// address 0x00e8ae

undefined1 FUN_CODE_00e8ae(void)

{
  byte unaff_BSR;
  char cVar1;
  byte bVar2;
  bool bVar3;
  
  FUN_CODE_00e926();
  cVar1 = FUN_CODE_00b53c();
  if (cVar1 == '\0') {
    FUN_CODE_00ea76(9);
    bVar2 = FUN_CODE_00ea80();
    if ((*(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) & 0x80) == 0) {
      bVar3 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) !=
              ~(bVar2 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0xe2));
    }
    else {
      bVar3 = false;
    }
    if (bVar3) goto LAB_CODE_00e8da;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe2) = 0xc;
  }
  else {
    unaff_BSR = 1;
    DAT_DATA_01e2 = 0;
  }
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe3) = 0;
LAB_CODE_00e8da:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe4) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe5) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe6) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe1) = 0;
  return 0;
}

