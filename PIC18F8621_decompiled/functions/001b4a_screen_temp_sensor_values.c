// address 0x001b4a  size 168 bytes
// callers: 001bfa,0013e8,001304,002af0,

/* WARNING: Removing unreachable block (CODE,0x001bce) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Service: show all temperature sensor readings */

void screen_temp_sensor_values(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined1 uVar9;
  byte bVar10;
  byte unaff_Z;
  
  ui_to_ui_get_cfg_systemconfig2_2334();
  if ((unaff_Z & 1) == 0) {
    uVar9 = 1;
  }
  else {
    uVar9 = 0x6e;
  }
  pcVar2 = (char *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = uVar9;
  ui_callw_fncfc6_238c(4);
  pcVar3 = pcVar2 + 1;
  *pcVar2 = menu_edit_mode;
  ui_to_ui_to_lcd_puts_rom_1c0c();
  pcVar4 = pcVar3 + -1;
  cVar1 = *pcVar3;
  *pcVar3 = cVar1;
  ui_to_ui_get_cfg_systemconfig2_2334();
  if (cVar1 == '\0') {
    uVar9 = 0x6e;
  }
  else {
    uVar9 = 1;
  }
  puVar5 = pcVar4 + 1;
  *pcVar4 = uVar9;
  ui_callw_fncfc6_238c(6);
  pcVar6 = puVar5 + 1;
  *puVar5 = menu_edit_mode == '\0';
  ui_to_ui_to_lcd_puts_rom_1c0c();
  pbVar7 = (byte *)(pcVar6 + -1);
  cVar1 = *pcVar6;
  *pcVar6 = cVar1;
  ui_set_ui_wake_pending_2aae(4);
  if (cVar1 == '\0') {
    text_fill_width = 0x58;
  }
  else {
    text_fill_width = 0x6c;
  }
  if (menu_edit_mode == '\0') {
    bVar10 = 0;
  }
  else {
    bVar10 = 0x80;
  }
  *pbVar7 = bVar10 | 0x26;
  pbVar7[1] = 0;
  pbVar7[2] = menu_text_a_lo;
  pbVar8 = pbVar7 + 4;
  pbVar7[3] = menu_text_a_hi;
  ui_to_txt_set_ui_hold_counter_2718();
  ui_set_ui_wake_pending_2aae(6);
  text_fill_width = 0x58;
  if (menu_edit_mode == '\0') {
    bVar10 = 0x80;
  }
  else {
    bVar10 = 0;
  }
  *pbVar8 = bVar10 | 0x26;
  pbVar8[1] = 0;
  pbVar8[2] = menu_text_b_lo;
  pbVar8[3] = menu_text_b_hi;
  ui_to_txt_set_ui_hold_counter_2718();
  return;
}

