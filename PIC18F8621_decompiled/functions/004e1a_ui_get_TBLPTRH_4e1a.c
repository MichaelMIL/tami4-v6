// address 0x004e1a  size 24 bytes
// callers: 004b32,

/* Auto: reads TBLPTRH,TABLAT; 12 instr */

char ui_get_TBLPTRH_4e1a(undefined1 param_1)

{
  byte bVar1;
  undefined3 in_TBLPTR;
  byte *pbVar2;
  
  pbVar2 = (byte *)CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(param_1,(char)in_TBLPTR));
  bVar1 = *pbVar2;
  c18_tmp0 = bVar1 - c18_tmp4;
  c18_tmp1 = (pbVar2[1] - c18_tmp5) - ~(c18_tmp4 <= bVar1);
  c18_tmp2 = 0;
  c18_tmp3 = 0;
  return c18_tmp1;
}

