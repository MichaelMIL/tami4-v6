// address 0x00dc32  size 18 bytes
// callers: 00aa56,

/* Start a UV cycle with TUVKEEP on-time */

undefined1 uv_start_keep_cycle(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  
  uVar1 = uv_load_on_time(0x10);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x8a) = uVar1;
  uv_verify_off_timer = uv_read_param(0x47);
  uv_flags = uv_flags | 1;
  return 0;
}

