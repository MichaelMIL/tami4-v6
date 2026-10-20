// address 0x002b68  size 18 bytes
// callers: 002780,0017c4,

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 9 instr */

undefined1 ui_get_TBLPTRL_2b68(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,param_1),c18_tmp0 + param_1));
}

