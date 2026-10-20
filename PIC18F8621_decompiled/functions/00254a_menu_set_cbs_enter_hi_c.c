// address 0x00254a  size 10 bytes
// callers: 000f42,

/* Store enter-callback high byte (variant) */

void menu_set_cbs_enter_hi_c(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xb8;
  menu_set_cbs_back_hi_b(0xd);
  return;
}

