// address 0x004d80  size 14 bytes
// callers: 003b12,

/* Auto: reads cfg_systemconfig; calls child_protect_is_active; 6 instr */

byte ui_to_child_protect_is_active_4d80(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = child_protect_is_active();
  *(undefined1 *)in_FSR1 = uVar1;
  return cfg_systemconfig & 8;
}

