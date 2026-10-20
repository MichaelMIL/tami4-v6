// address 0x002606  size 20 bytes
// callers: 000e04,

/* Auto: reads TBLPTRH,c18_tmp4,TABLAT,c18_tmp5; 8 instr */

void ui_get_TBLPTRH_2606(undefined1 param_1)

{
  undefined3 in_TBLPTR;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(param_1,(char)in_TBLPTR));
  c18_tmp4 = *puVar1;
  c18_tmp5 = puVar1[1];
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  return;
}

