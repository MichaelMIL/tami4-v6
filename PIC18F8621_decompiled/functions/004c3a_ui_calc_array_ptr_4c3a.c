// address 0x004c3a  size 14 bytes
// callers: 004f78,003584,0050aa,004fbc,

/* Auto: Compute array element address in FSR0; 7 instr */

char ui_calc_array_ptr_4c3a(void)

{
  byte in_FSR2L;
  char in_FSR2H;
  
  return in_FSR2H + (0xfa < in_FSR2L);
}

