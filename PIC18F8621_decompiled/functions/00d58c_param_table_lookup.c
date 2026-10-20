// address 0x00d58c  size 28 bytes
// callers: 00d67e,0025d4,0021e4,0079c2,

/* Find parameter in ROM table (0xDD62) and return a field */

void param_table_lookup(void)

{
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if ((unaff_C & 1) == 0) {
    mod_chain_fnd78c_mod_get_c18_tmp0_d776();
    if ((unaff_Z & 1) != 0) {
      mod_to_mod_get_TBLPTRL_d78c();
      uVar1 = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                        CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfc < (byte)in_TBLPTR),
                                 (byte)in_TBLPTR + 3));
      goto LAB_CODE_00d5a6;
    }
  }
  uVar1 = 0;
LAB_CODE_00d5a6:
  mod_c18_epilogue_d6c6(uVar1);
  return;
}

