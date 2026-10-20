// address 0x004eb2  size 10 bytes
// callers: 002c22,

/* Auto: reads params DBNCCNTR; writes keys_changed; 5 instr */

void ui_param_dbnccntr_4eb2(void)

{
  keys_changed = ui_to_eeprom_read_param_4f64(0x30);
  return;
}

