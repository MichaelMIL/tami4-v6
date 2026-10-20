// address 0x00d5ec

void FUN_CODE_00d5ec(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if (((unaff_C & 1) == 0) && (FUN_CODE_00d776(), (unaff_Z & 1) != 0)) {
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    cVar3 = *(char *)((short)in_FSR2 + -2);
    if (cVar3 == 'A') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_015b = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ':') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_015a = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ',') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_0159 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == '+') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_0158 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    cVar3 = FUN_CODE_00d710((char)puVar1);
    bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
    *(undefined1 *)in_FSR1 = puVar1[(short)cVar3 + 1];
    FUN_CODE_00d750();
    uVar4 = DAT_DATA_0014;
    if ((unaff_C & 1) == 0) {
      *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      uVar4 = DAT_DATA_0014;
    }
  }
  else {
    uVar4 = 0x81;
  }
  FUN_CODE_00d6c6(uVar4);
  return;
}

