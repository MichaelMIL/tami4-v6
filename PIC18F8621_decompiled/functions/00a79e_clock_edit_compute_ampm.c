// address 0x00a79e  size 80 bytes
// callers: 001974,

/* Clock edit: compute AM/PM/24h for edited time */

void clock_edit_compute_ampm(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR0;
  byte unaff_Z;
  
  mod_c18_prologue_a8c8();
  mod_get_clock_pm_a99c();
  if ((unaff_Z & 1) == 0) {
    mod_frame_load_ptr_arg_a8ba();
    c18_tmp0 = *(undefined1 *)in_FSR0;
    mod_frame_load_ptr_arg_a8ba(c18_tmp0);
    c18_tmp1 = *(byte *)in_FSR0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 1);
    *(bool *)in_FSR1 = 0xb < c18_tmp1;
    mod_chain_fna8ba_fna992_a9ce();
    *puVar1 = *puVar1;
    *(undefined1 *)in_FSR0 = puVar1[-1];
    mod_chain_fna8ba_fna992_a9ce();
    if (*(char *)in_FSR0 == '\x01') {
      mod_frame_load_ptr_arg_a8ba(0);
      if (0xc < *(byte *)in_FSR0) {
        mod_compare_multibyte_aa38('\f' - *(byte *)in_FSR0);
      }
    }
  }
  else {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xdd) = 2;
  }
  mod_c18_epilogue_a902();
  return;
}

