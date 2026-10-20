// address 0x002150  size 10 bytes
// callers: 0013e8,0008c4,00148c,000360,00011e,00094a,000148,000318,00207e,0001a8,001ff2,001438,0000ca,000178,0000b2,0020b0,

/* Store enter-callback high byte and install default back/up/down callbacks */

void menu_set_cbs_back_default(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xf2;
  menu_set_cbs_back_hi_b(0x1b);
  return;
}

