// address 0x00cd48

undefined1 FUN_CODE_00cd48(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11((0x1f < param_1) + -0x7a,param_1 - 0x20));
}

