// address 0x001c32  size 66 bytes
// callers: 001ddc,000c9e,

/* Menu/screen handler (callback analysis) */

void menu_mix_water_temp_on_up(void)

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
  if (((menu_value_hi ^ menu_value_max_hi) & 0x80) == 0) {
    bVar1 = ui_get_menu_value_max_lo_272a();
  }
  else {
    bVar1 = unaff_C & 1;
    unaff_C = (char)menu_value_max_hi < '\0';
    bVar1 = menu_value_max_hi << 1 | bVar1;
  }
  if ((unaff_C & 1) == 0) {
    bVar1 = ui_get_menu_value_lo_24fa(bVar1);
    if ((bVar1 & 0x80) == 0) {
      bVar1 = ui_get_menu_value_max_lo_2734();
    }
    else {
      bVar1 = unaff_C & 1;
      unaff_C = c18_tmp1 < '\0';
      bVar1 = c18_tmp1 << 1 | bVar1;
    }
    if ((unaff_C & 1) == 0) {
      ui_get_menu_value_max_lo_2748(bVar1);
    }
    else {
      ui_get_menu_value_min_lo_273e();
    }
    ui_to_progress_bar_scale_28fe();
  }
  return;
}

