// address 0x00bfdc  size 16 bytes
// callers: 003584,006e5c,00d794,

/* Temperature on AN7 (cold table) */

void temp_read_ch7(void)

{
  adc_read_to_tmp_b(7);
  ntc_table_ptr_lo = 0x96;
  ntc_table_ptr_hi = 0xea;
  temp_filter();
  return;
}

