// address 0x00bfcc  size 16 bytes
// callers: 003584,006e5c,00d794,

/* Temperature on AN6 (table 0xEBD6; device/ambient sensor) */

void temp_read_ch6(void)

{
  adc_read_to_tmp_b(6);
  ntc_table_ptr_lo = 0xd6;
  ntc_table_ptr_hi = 0xeb;
  temp_filter();
  return;
}

