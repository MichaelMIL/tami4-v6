// address 0x0022ea  size 16 bytes
// callers: 0008c4,00094a,

/* Auto: reads cfg_systemconfig3; calls ui_draw_on_off; 6 instr */

undefined1 ui_to_ui_draw_on_off_22ea(void)

{
  ui_chain_ui_to_lcd_clear_fn21d8_0450();
  ui_draw_on_off();
  return cfg_systemconfig3;
}

