// address 0x002a28  size 16 bytes
// callers: 00089a,00091a,

/* Auto: reads cfg_systemconfig3,menu_edit_mode; 6 instr */

undefined1 ui_get_cfg_systemconfig3_2a28(void)

{
  ui_to_param_write_215a(0x2c);
  return menu_edit_mode;
}

