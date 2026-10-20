// address 0x00bbee  size 12 bytes
// callers: 00b898,00b982,00b9be,

/* Auto: writes anim_index; 5 instr */

void mod_set_anim_index_bbee(void)

{
  BADSPACEBASE *in_FSR1;
  
  lcd_write_data();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  anim_index = anim_index + '\x01';
  return;
}

