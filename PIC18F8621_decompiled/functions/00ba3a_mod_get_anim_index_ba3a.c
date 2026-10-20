// address 0x00ba3a  size 32 bytes
// callers: 00bbda,00b898,

/* Auto: reads anim_index,TBLPTRL,TBLPTRH,TABLAT; 16 instr */

undefined1 mod_get_anim_index_ba3a(void)

{
  byte bVar1;
  byte unaff_BSR;
  byte in_PRODL;
  char in_PRODH;
  undefined3 in_TBLPTR;
  
  c18_tmp0 = in_PRODL + c18_tmp2;
  c18_tmp1 = in_PRODH + c18_tmp3 + CARRY1(in_PRODL,c18_tmp2);
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x56);
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,bVar1),c18_tmp0 + bVar1));
}

