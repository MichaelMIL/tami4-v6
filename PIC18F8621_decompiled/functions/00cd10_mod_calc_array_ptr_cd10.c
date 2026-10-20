// address 0x00cd10  size 20 bytes
// callers: 00cab8,00ca90,00caa4,00caf0,00ca68,00ca7c,00cad4,00cb0c,

/* Auto: Compute array element address in FSR0; 10 instr */

byte mod_calc_array_ptr_cd10(void)

{
  byte in_FSR1L;
  char in_FSR1H;
  byte *pbVar1;
  
  mod_c18_prologue_cdd2();
  pbVar1 = (byte *)CONCAT11(in_FSR1H + -1 + (3 < in_FSR1L),in_FSR1L - 4);
  return pbVar1[1] | *pbVar1;
}

