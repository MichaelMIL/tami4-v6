// address 0x00a9e2  size 20 bytes
// callers: 00a92e,00a892,

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 10 instr */

undefined1 mod_get_TBLPTRL_a9e2(void)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,local1),c18_tmp0 + local1));
}

