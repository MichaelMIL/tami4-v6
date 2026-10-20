// address 0x00247a  size 30 bytes
// callers: 000f2e,00120a,

/* Auto: writes stat_GFI,stat_FWU; 14 instr */

void ui_set_stat_GFI_247a(void)

{
  stat_GFI = 0;
  uDATA00eb = 0;
  uDATA00ec = 0;
  uDATA00ed = 0;
  ui_to_stat_counter_save_2904(0xe);
  stat_FWU = 0;
  uDATA00ef = 0;
  uDATA00f0 = 0;
  uDATA00f1 = 0;
  ui_to_stat_counter_save_2904(0xf);
  return;
}

