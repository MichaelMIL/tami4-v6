// address 0x0034a2  size 12 bytes
// callers: 00b4f8,

/* Auto: writes ui_screen; 5 instr */

undefined1 ui_set_ui_screen_34a2(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  byte unaff_Z;
  
  uVar1 = ui_get_ui_screen_4ee4();
  if ((unaff_Z & 1) == 0) {
    uVar1 = 4;
    *(undefined1 *)((ushort)unaff_BSR * 0x100) = 4;
  }
  return uVar1;
}

