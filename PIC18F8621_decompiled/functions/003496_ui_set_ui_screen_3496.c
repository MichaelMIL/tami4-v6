// address 0x003496  size 12 bytes
// callers: 00b4a6,

/* Auto: writes ui_screen; 5 instr */

undefined1 ui_set_ui_screen_3496(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  byte unaff_Z;
  
  uVar1 = ui_get_ui_screen_4ee4();
  if ((unaff_Z & 1) == 0) {
    uVar1 = 2;
    *(undefined1 *)((ushort)unaff_BSR * 0x100) = 2;
  }
  return uVar1;
}

