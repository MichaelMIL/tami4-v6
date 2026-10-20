// address 0x00e440  size 14 bytes
// callers: 00e2fc,

/* Auto: Compute array element address in FSR0; 7 instr */

char mod_calc_array_ptr_e440(void)

{
  byte in_FSR2L;
  char in_FSR2H;
  
  return in_FSR2H + (0xfd < in_FSR2L);
}

