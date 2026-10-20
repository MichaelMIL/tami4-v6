// address 0x002aae  size 12 bytes
// callers: 001b4a,

/* Auto: writes ui_wake_pending,text_x; 5 instr */

void ui_set_ui_wake_pending_2aae(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 3) = param_1;
  text_x = 0xf;
  ui_to_ui_get_cfg_systemconfig2_2334();
  return;
}

