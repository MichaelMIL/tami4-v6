// address 0x002ad8  size 6 bytes
// callers: 001538,001392,00120a,

/* Store enter high byte then defaults */

void menu_set_cbs_enter_hi_e(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  menu_set_cbs_noop();
  return;
}

