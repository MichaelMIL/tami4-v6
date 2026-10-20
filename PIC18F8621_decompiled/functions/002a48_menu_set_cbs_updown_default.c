// address 0x002a48  size 16 bytes
// callers: 000db8,00246a,

/* Install default up/down callbacks */

undefined1 menu_set_cbs_updown_default(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0xf2;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0xd;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xf2;
  return 0xd;
}

