// address 0x00bf94  size 56 bytes
// callers: 00b572,00b542,00bfcc,00bfdc,

/* Per-channel filter: accept new temperature after 3 consistent readings */

undefined1 temp_filter(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  temp_new_reading = ntc_table_lookup();
  temp_channel = adc_current_channel;
  mod_calc_array_ptr_c108();
  if (*(char *)in_FSR0 == -0x7f) {
    mod_calc_array_ptr_c108();
    *(char *)in_FSR0 = temp_new_reading;
    mod_get_temp_new_reading_c0e6();
  }
  mod_calc_array_ptr_c158();
  if (temp_new_reading - *(char *)in_FSR0 != '\0') {
    mod_get_temp_new_reading_c0e6(temp_new_reading - *(char *)in_FSR0);
  }
  mod_calc_array_ptr_c166();
  cVar1 = *(char *)in_FSR0;
  *(char *)in_FSR0 = *(char *)in_FSR0 + -1;
  if (cVar1 == '\0') {
    mod_calc_array_ptr_c108();
    *(char *)in_FSR0 = temp_new_reading;
  }
  mod_calc_array_ptr_c108();
  return *(undefined1 *)in_FSR0;
}

