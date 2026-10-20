// address 0x0099ca  size 24 bytes
// callers: 0092ae,009282,

/* Auto: reads TBLPTRH,c18_tmp0,TABLAT,c18_tmp1; 8 instr */

void txt_get_TBLPTRH_99ca(char param_1)

{
  undefined3 in_TBLPTR;
  undefined1 *puVar1;
  byte unaff_C;
  
  puVar1 = (undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                    CONCAT11((char)((uint3)in_TBLPTR >> 8) + param_1 + (unaff_C & 1),(char)in_TBLPTR
                            ));
  c18_tmp0 = *puVar1;
  c18_tmp1 = puVar1[1];
  return;
}

