// address 0x00999c  size 12 bytes
// callers: 0098fc,009936,

/* Auto: reads printf_fmt_lo,printf_fmt_hi; 4 instr */

void txt_get_printf_fmt_lo_999c(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  txt_to_cfg_language_9a6c();
  printf_fmt_lo = in_PRODL;
  printf_fmt_hi = in_PRODH;
  return;
}

