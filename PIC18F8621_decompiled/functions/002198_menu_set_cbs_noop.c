// address 0x002198  size 8 bytes
// callers: 001644,002a7e,00281a,002ad8,001550,

/* Install no-op callbacks */

void menu_set_cbs_noop(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0x98;
  menu_set_cbs_back_hi(0);
  return;
}

