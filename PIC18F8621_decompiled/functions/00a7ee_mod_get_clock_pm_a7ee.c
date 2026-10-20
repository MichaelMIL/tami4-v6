// address 0x00a7ee  size 56 bytes
// callers: 001908,

/* Auto: reads clock_pm,clock_minute,clock_hour; 25 instr */

void mod_get_clock_pm_a7ee(void)

{
  BADSPACEBASE *in_FSR0;
  byte *pbVar1;
  
  mod_c18_prologue_a8c8();
  mod_chain_fna8ba_fna992_a9ce();
  *(undefined1 *)in_FSR0 = clock_pm;
  mod_frame_load_ptr_arg_a8ba();
  pbVar1 = (byte *)((short)in_FSR0 + 1);
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  *(undefined1 *)((short)in_FSR0 + 1) = clock_minute;
  mod_frame_load_ptr_arg_a8ba();
  *pbVar1 = clock_hour;
  mod_chain_fna8ba_fna992_a9ce();
  if (*pbVar1 != '\x02') {
    mod_frame_load_ptr_arg_a8ba();
    if (0xb < *pbVar1) {
      mod_chain_fna8ba_fna992_a9ce('\v' - *pbVar1);
      if (*pbVar1 == '\x01') {
        mod_frame_load_ptr_arg_a8ba(0);
        if (*pbVar1 == '\f') goto LAB_CODE_00a824;
      }
      mod_compare_multibyte_aa38();
    }
  }
LAB_CODE_00a824:
  mod_c18_epilogue_a902();
  return;
}

