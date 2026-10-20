// address 0x00b542  size 18 bytes
// callers: 00b554,00b55e,

/* Read cold-tank NTC on given ADC channel (table 0xEA96), filtered */

void cold_temp_read(void)

{
  mod_c18_prologue_b5e8();
  adc_read_to_tmp();
  ntc_table_ptr_lo = 0x96;
  ntc_table_ptr_hi = 0xea;
  temp_filter();
  mod_c18_epilogue_b60a();
  return;
}

