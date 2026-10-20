// address 0x00bbaa  size 16 bytes
// callers: 00b7e6,00b772,

/* Auto: writes anim_pos; 8 instr */

void mod_set_anim_pos_bbaa(void)

{
  mod_callw_fnba5a_bc20(6);
  mod_callw_lcd_write_data_baa6(0x1f);
  anim_pos = 0;
  return;
}

