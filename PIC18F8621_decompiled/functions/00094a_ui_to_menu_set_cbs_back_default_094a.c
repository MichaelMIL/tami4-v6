// address 0x00094a  size 26 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: writes menu_cb_enter; calls menu_set_cbs_back_default; 10 instr */

void ui_to_menu_set_cbs_back_default_094a(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  bVar1 = ui_to_ui_draw_on_off_22ea(0x37);
  ui_set_menu_edit_mode_2386((bVar1 & 0x20) != 0);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x1a;
  menu_set_cbs_back_default(9);
  return;
}

