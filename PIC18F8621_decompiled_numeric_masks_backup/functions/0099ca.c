// address 0x0099ca

void FUN_CODE_0099ca(char param_1)

{
  undefined3 in_TBLPTR;
  undefined1 *puVar1;
  byte unaff_C;
  
  puVar1 = (undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                    CONCAT11((char)((uint3)in_TBLPTR >> 8) + param_1 + (unaff_C & 1),(char)in_TBLPTR
                            ));
  DAT_DATA_0014 = *puVar1;
  DAT_DATA_0015 = puVar1[1];
  return;
}

