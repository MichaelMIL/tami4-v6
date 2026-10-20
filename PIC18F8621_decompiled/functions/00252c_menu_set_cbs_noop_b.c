// address 0x00252c  size 10 bytes
// callers: 002a7e,00281a,0013b0,

/* Install no-op enter callback */

undefined1 menu_set_cbs_noop_b(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x98;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0;
  return 0;
}

