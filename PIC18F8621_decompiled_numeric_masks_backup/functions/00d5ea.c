// address 0x00d5ea

void FUN_CODE_00d5ca(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x4b;
      FUN_CODE_00d724();
      if (bVar1 < 0xb5) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = FUN_CODE_00d76a();
      goto LAB_CODE_00d5ea;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5ea:
  FUN_CODE_00d6c6(uVar3);
  return;
}

