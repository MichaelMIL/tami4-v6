// address 0x00cbf2

void FUN_CODE_00cbf2(void)

{
  undefined1 uVar1;
  char cVar2;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  char cVar3;
  byte unaff_Z;
  
  FUN_CODE_00cd96();
  cVar3 = '\x01';
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 1;
  while( true ) {
    FUN_CODE_00ce04(cVar3);
    if ((unaff_Z & 1) != 0) break;
    cVar3 = *(char *)in_FSR2 + -10;
    unaff_Z = 0;
    if (cVar3 == '\0') {
      cVar2 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe9) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe9) = cVar2;
      unaff_Z = cVar2 == '\0';
    }
  }
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  FUN_CODE_00cd24(uVar1);
  return;
}

