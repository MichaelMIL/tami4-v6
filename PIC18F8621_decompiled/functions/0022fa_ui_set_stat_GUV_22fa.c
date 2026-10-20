// address 0x0022fa  size 58 bytes
// callers: 000f1c,001178,

/* Auto: writes stat_GUV,stat_FM,stat_UVS,stat_UI; 28 instr */

void ui_set_stat_GUV_22fa(void)

{
  stat_GUV = 0;
  uDATA00e7 = 0;
  uDATA00e8 = 0;
  uDATA00e9 = 0;
  ui_to_stat_counter_save_2904(0xd);
  stat_FM = 0;
  uDATA00cb = 0;
  uDATA00cc = 0;
  uDATA00cd = 0;
  ui_to_stat_counter_save_2904(6);
  stat_UVS = 0;
  uDATA00cf = 0;
  uDATA00d0 = 0;
  uDATA00d1 = 0;
  ui_to_stat_counter_save_2904(7);
  stat_UI = 0;
  uDATA00d3 = 0;
  uDATA00d4 = 0;
  uDATA00d5 = 0;
  ui_to_stat_counter_save_2904(8);
  return;
}

