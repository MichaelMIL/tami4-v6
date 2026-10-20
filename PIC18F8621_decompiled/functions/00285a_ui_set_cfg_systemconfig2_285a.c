// address 0x00285a  size 26 bytes
// callers: 001524,0003cc,

/* Auto: writes cfg_systemconfig2; reads TABLAT,cfg_systemconfig2; 13 instr */

void ui_set_cfg_systemconfig2_285a(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte in_PRODL;
  undefined1 in_TABLAT;
  
  ui_get_menu_item_24ba();
  bVar1 = ui_frag_25a6(in_TABLAT);
  cfg_systemconfig2 = in_PRODL | cfg_systemconfig2 & bVar1;
  *(byte *)in_FSR1 = cfg_systemconfig2;
  ui_to_param_write_215a(0x2b);
  return;
}

