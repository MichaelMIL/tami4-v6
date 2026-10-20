// address 0x00cd48  size 16 bytes
// callers: 00cdec,00ce12,00cb0c,00cb86,

/* Auto: reads TBLPTRH,TBLPTRL,TABLAT; 8 instr */

undefined1 mod_get_TBLPTRH_cd48(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11((0x1f < param_1) + -0x7a,param_1 - 0x20));
}

