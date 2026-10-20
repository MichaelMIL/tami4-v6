// address 0x00c0e6  size 14 bytes
// callers: 00bf94,

/* Auto: reads temp_new_reading; 6 instr */

void mod_get_temp_new_reading_c0e6(void)

{
  BADSPACEBASE *in_FSR0;
  
  mod_calc_array_ptr_c166();
  *(undefined1 *)in_FSR0 = 3;
  mod_calc_array_ptr_c158();
  *(undefined1 *)in_FSR0 = temp_new_reading;
  return;
}

