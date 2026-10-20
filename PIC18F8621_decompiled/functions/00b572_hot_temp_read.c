// address 0x00b572  size 32 bytes
// callers: 00b59a,00b592,

/* Read hot-tank NTC on given ADC channel (table 0xEB4A); 0 if no heater */

void hot_temp_read(void)

{
  undefined1 uVar1;
  
  mod_c18_prologue_b5e8();
  if ((cfg_systemconfig & 3) == 0) {
    uVar1 = 0;
  }
  else {
    adc_read_to_tmp();
    ntc_table_ptr_lo = 0x4a;
    ntc_table_ptr_hi = 0xeb;
    uVar1 = temp_filter();
  }
  mod_c18_epilogue_b60a(uVar1);
  return;
}

