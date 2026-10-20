// address 0x001cb6  size 96 bytes
// callers: 001de8,

/* Increase edited value by step, clamp to maximum */

void menu_value_increment(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte unaff_Z;
  byte unaff_C;
  bool bVar4;
  bool bVar5;
  
  ui_get_menu_value_step_lo_2180();
  if ((unaff_Z & 1) == 0) {
    ui_to___divs16_21a0();
  }
  else {
    ui_set_menu_value_min_lo_255e();
  }
  bVar2 = menu_value_max_hi;
  if (((menu_value_hi ^ menu_value_step_hi) & 0x80) == 0) {
    bVar1 = ~(menu_value_step_lo <= menu_value_lo);
    bVar4 = menu_value_hi < bVar1 || menu_value_step_hi < menu_value_hi - bVar1;
    bVar1 = (menu_value_hi - menu_value_step_hi) - ~(menu_value_step_lo <= menu_value_lo);
  }
  else {
    bVar4 = (char)menu_value_step_hi < '\0';
    bVar1 = menu_value_step_hi << 1 | unaff_C & 1;
  }
  if (bVar4) {
    bVar4 = ((menu_value_hi ^ menu_value_max_hi) & 0x80) != 0;
    if (bVar4) {
      bVar1 = menu_value_max_hi << 1 | 1;
    }
    else {
      bVar1 = ui_get_menu_value_max_lo_272a();
    }
    bVar4 = !bVar4;
    bVar5 = bVar4 || (char)bVar2 < '\0';
    if (!bVar4 && (char)bVar2 >= '\0') {
      bVar2 = ui_get_menu_value_lo_24fa(bVar1);
      if ((bVar2 & 0x80) == 0) {
        cVar3 = ui_get_menu_value_max_lo_2734();
      }
      else {
        bVar5 = c18_tmp1 < '\0';
        cVar3 = c18_tmp1 << 1;
      }
      if (bVar5) {
        ui_get_menu_value_min_lo_273e();
      }
      else {
        ui_get_menu_value_max_lo_2748(cVar3);
      }
    }
  }
  else {
    ui_get_menu_value_step_lo_25c2(bVar1);
    cfg_systemconfig5 = cfg_systemconfig5 | 4;
  }
  ui_to_progress_bar_scale_28fe();
  return;
}

