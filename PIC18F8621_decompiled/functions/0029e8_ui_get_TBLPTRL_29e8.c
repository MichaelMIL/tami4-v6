// address 0x0029e8  size 18 bytes
// callers: 001848,001a54,

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 9 instr */

undefined1 ui_get_TBLPTRL_29e8(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp3 + CARRY1(c18_tmp2,param_1),c18_tmp2 + param_1));
}

