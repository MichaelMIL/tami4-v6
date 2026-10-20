// address 0x0092ac

void FUN_CODE_009282(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = FUN_CODE_0099c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      FUN_CODE_00998e();
      uVar2 = 0xee;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092ac;
      FUN_CODE_00998e();
      uVar2 = 0xf1;
    }
  }
  else {
    FUN_CODE_00998e();
    uVar2 = 0xef;
  }
  FUN_CODE_0099ca(uVar2);
LAB_CODE_0092ac:
  FUN_CODE_009972();
  return;
}

