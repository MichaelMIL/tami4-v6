// address 0x00bbda  size 10 bytes
// callers: 00b908,00b85a,00b944,

/* Auto: writes anim_index; 5 instr */

void mod_set_anim_index_bbda(void)

{
  mod_get_anim_index_ba3a();
  mod_callw_lcd_write_data_baa6();
  anim_index = anim_index + '\x01';
  return;
}

