// address 0x002a8a  size 12 bytes
// callers: 0014d6,002580,

/* Store back high byte and clear other callbacks */

void menu_clear_cbs(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0;
  return;
}

