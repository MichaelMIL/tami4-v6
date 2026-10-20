// address 0x00c128  size 16 bytes
// callers: 00bfcc,00bfdc,

/* adc_read() and store raw result in adc_raw (copy) */

void adc_read_to_tmp_b(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  puVar1 = &FramePointer10x0001;
  adc_read();
  *puVar1 = *puVar1;
  adc_raw_lo = in_PRODL;
  adc_raw_hi = in_PRODH;
  return;
}

