// address 0x00d58c

void FUN_CODE_00d58c(void)

{
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d78c();
      uVar1 = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                        CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfc < (byte)in_TBLPTR),
                                 (byte)in_TBLPTR + 3));
      goto LAB_CODE_00d5a6;
    }
  }
  uVar1 = 0;
LAB_CODE_00d5a6:
  FUN_CODE_00d6c6(uVar1);
  return;
}

