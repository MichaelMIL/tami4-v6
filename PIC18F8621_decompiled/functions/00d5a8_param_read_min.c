// address 0x00d5a8  size 34 bytes
// callers: 004264,006d6a,002b7a,

/* Read parameter minimum from EEPROM (address + 0x96) */

void param_read_min(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if ((unaff_C & 1) == 0) {
    mod_chain_fnd78c_mod_get_c18_tmp0_d776();
    if ((unaff_Z & 1) != 0) {
      mod_push_args_32_00_01_d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x96;
      mod_to_eeprom_read_byte_d724();
      if (bVar1 < 0x6a) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = mod_frag_d76a();
      goto LAB_CODE_00d5c8;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5c8:
  mod_c18_epilogue_d6c6(uVar3);
  return;
}

