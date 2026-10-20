// address 0x001c74  size 66 bytes
// callers: 000ca6,001de2,

/* Menu/screen handler (callback analysis) */

void menu_mix_water_temp_on_down(void)

{
  byte bVar1;
  byte unaff_Z;
  byte unaff_C;
  
  ui_get_menu_value_step_lo_2180();
  if ((unaff_Z & 1) == 0) {
    ui_to___divs16_21a0();
  }
  else {
    ui_set_menu_value_min_lo_255e();
  }
  if (((menu_value_step_hi ^ menu_value_hi) & 0x80) == 0) {
    bVar1 = ui_get_menu_value_lo_2752();
  }
  else {
    bVar1 = unaff_C & 1;
    unaff_C = (char)menu_value_hi < '\0';
    bVar1 = menu_value_hi << 1 | bVar1;
  }
  if ((unaff_C & 1) == 0) {
    bVar1 = ui_get_menu_value_min_lo_250c(bVar1);
    if ((bVar1 & 0x80) == 0) {
      bVar1 = ui_get_menu_value_step_lo_275c();
    }
    else {
      bVar1 = unaff_C & 1;
      unaff_C = (char)menu_value_step_hi < '\0';
      bVar1 = menu_value_step_hi << 1 | bVar1;
    }
    if ((unaff_C & 1) == 0) {
      ui_get_menu_value_step_lo_25c2(bVar1);
    }
    else {
      ui_get_menu_value_min_lo_2766();
    }
    ui_to_progress_bar_scale_28fe();
  }
  return;
}

