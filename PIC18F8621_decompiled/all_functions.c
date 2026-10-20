// PIC18F8621 water dispenser controller firmware - full decompilation
// Ghidra 12.1.4 (PIC-18), 1195 functions, names from names.tsv (also applied in ~/Desktop/PIC18F8621_ghidra)
// Reconstructed pseudo-C, not original source. "(inferred)"/"(probable)" in comments = lower confidence.
// SFR bit masks use datasheet names, see pic18f8621_bits.h. Overview: README.md
#include "pic18f8621_bits.h"

// ===== 0x000000 ui_to_c018_startup_0000 =====

/* Auto: calls c018_startup; 1 instr */

void ui_to_c018_startup_0000(void)

{
  math_flags = math_flags & 0xbf;
  _do_cinit();
  do {
    user_init_hook();
    main();
  } while( true );
}


// ===== 0x000008 ui_to_isr_high_0008 =====

/* Auto: calls isr_high; 1 instr */

undefined1 ui_to_isr_high_0008(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 in_WS;
  
  puVar2 = &FramePointer10x0008;
  cVar6 = '\x14';
  puVar5 = (undefined1 *)0x0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  cVar6 = '\x10';
  puVar5 = &c18_tmp0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar3 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  puVar4 = puVar2 + 1;
  *puVar2 = *puVar2;
  mod_to_uart2_rx_isr_b498();
  *puVar4 = *puVar4;
  cVar6 = '\x10';
  puVar5 = puVar4 + -1;
  puVar7 = &c18_tmp15;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  cVar6 = '\x14';
  puVar7 = &math_tmp13;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  return in_WS;
}


// ===== 0x000018 ui_to_isr_low_0018 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: calls isr_low; 1 instr */

undefined1 ui_to_isr_low_0018(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  bool bVar10;
  
  puVar3 = &FramePointer10x000b;
  cVar8 = '\x14';
  puVar7 = (undefined1 *)0x0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar2 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  cVar8 = '\x10';
  puVar7 = &c18_tmp0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar4 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar4 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  puVar5 = puVar3 + 1;
  puVar6 = puVar3 + 1;
  *puVar3 = *puVar3;
  bVar1 = INTCON;
  if (((bVar1 & TMR0IE) == 0) || (bVar1 = INTCON, (bVar1 & TMR0IF) == 0)) {
    isr_low_other();
    puVar7 = puVar6;
  }
  else {
    bVar1 = INTCON;
    INTCON = bVar1 & ~TMR0IF;
    bVar1 = TMR0L;
    cVar8 = TMR0H;
    tmr0_next_lo = bVar1 + tmr0_reload_lo;
    tmr0_next_hi = cVar8 + tmr0_reload_hi + CARRY1(bVar1,tmr0_reload_lo);
    TMR0H = tmr0_next_hi;
    TMR0L = tmr0_next_lo;
    if (os_tick_suppress == '\0') {
      os_tick(0);
      puVar7 = puVar5;
    }
    else {
      tick_hold_counter = tick_hold_counter + '\x01';
      puVar7 = puVar3 + 1;
      if (tick_hold_counter == 'd') {
        tick_hold_counter = '\0';
        puVar7 = puVar3 + 1;
      }
    }
  }
  *puVar7 = *puVar7;
  cVar8 = '\x10';
  puVar7 = puVar7 + -1;
  puVar9 = &c18_tmp15;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  cVar8 = '\x14';
  puVar9 = &math_tmp13;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  return puVar7[-8];
}


// ===== 0x000098 menu_cb_noop =====

/* Menu/screen handler (callback analysis) */

void menu_cb_noop(void)

{
  return;
}


// ===== 0x00009a menu_enter_power_down_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_enter_power_down_on_enter(void)

{
  if (menu_edit_mode != '\0') {
    system_request_wake(menu_edit_mode);
  }
  lcd_clear();
  ui_bank1_ui_set_menu_cb_up_2454();
  menu_table_ptr_lo = 0;
  menu_table_ptr_hi = 0;
  return;
}


// ===== 0x0000b2 menu_enter_power_down =====

/* Menu/screen handler (callback analysis) */

void menu_enter_power_down(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_lcd_clear_2bf2();
  ui_to_ui_draw_title_2986();
  menu_cb_enter = 0x9a;
  menu_set_cbs_back_default(0);
  return;
}


// ===== 0x0000ca menu_beep_on_key =====

/* Menu/screen handler (callback analysis) */

void menu_beep_on_key(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig & 0x80) != 0);
  menu_cb_enter = 0xec;
  menu_set_cbs_back_default(0);
  return;
}


// ===== 0x0000ec menu_beep_on_key_on_enter =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_beep_on_key_on_enter(void)

{
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig = cfg_systemconfig | 0x80;
  }
  ui_to_menu_default_back_279e(0x25);
  return;
}


// ===== 0x0000f6 ui_set_cfg_systemconfig_00f6 =====

/* WARNING: Removing unreachable block (CODE,0x0000fe) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes cfg_systemconfig; reads cfg_systemconfig; 8 instr */

void ui_set_cfg_systemconfig_00f6(void)

{
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  ui_to_menu_default_back_279e(0x25);
  return;
}


// ===== 0x00010a menu_child_lock_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_child_lock_on_enter(void)

{
  ui_to_menu_default_back_279e(0x28);
  return;
}


// ===== 0x000114 ui_to_ui_to_menu_default_back_0114 =====

/* Auto: Small wrapper around ui_to_menu_default_back; 4 instr */

void ui_to_ui_to_menu_default_back_0114(void)

{
  ui_to_menu_default_back_279e(0x28);
  return;
}


// ===== 0x00011e menu_child_lock =====

/* Menu/screen handler (callback analysis) */

void menu_child_lock(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  child_protect_is_active();
  ui_set_menu_edit_mode_2386();
  menu_cb_enter = 10;
  menu_set_cbs_back_default(1);
  return;
}


// ===== 0x00013a menu_spout_light_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_spout_light_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  byte bVar2;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0xbf;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x40;
  }
  ui_get_cfg_systemconfig3_2bfa();
  return;
}


// ===== 0x000148 menu_spout_light =====

/* Menu/screen handler (callback analysis) */

void menu_spout_light(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig3 & 0x40) != 0);
  menu_cb_enter = 0x3a;
  menu_set_cbs_back_default(1);
  return;
}


// ===== 0x00016a menu_clock_view_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_clock_view_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  byte bVar2;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0x7f;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x80;
  }
  ui_get_cfg_systemconfig3_2bfa();
  return;
}


// ===== 0x000178 menu_clock_view =====

/* Menu/screen handler (callback analysis) */

void menu_clock_view(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig3 & 0x80) != 0);
  menu_cb_enter = 0x6a;
  menu_set_cbs_back_default(1);
  return;
}


// ===== 0x00019a menu_units_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_units_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  byte bVar2;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0xfb;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 4;
  }
  ui_get_cfg_systemconfig3_2bfa();
  return;
}


// ===== 0x0001a8 menu_units =====

/* Menu/screen handler (callback analysis) */

void menu_units(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_lcd_clear_2bf2();
  ui_draw_title();
  ui_stack_adjust_2800();
  ui_set_text_a(0x46);
  ui_set_text_b(0x47);
  ui_set_menu_edit_mode_2386((cfg_systemconfig3 & 4) != 0);
  menu_cb_enter = 0x9a;
  menu_set_cbs_back_default(1);
  return;
}


// ===== 0x0001de menu_restore_factory_confirm2 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_restore_factory_confirm2(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  BADSPACEBASE *in_FSR0;
  byte *pbVar4;
  byte in_PRODL;
  
  ui_stack_adjust_2af8();
  ui_to_param_table_lookup_21e4(0x23);
  ui_to_param_write_215a(0x23);
  ui_to_param_table_lookup_25d4(0x2b);
  if ((cfg_systemconfig2 & 1) == 0) {
    *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0xfe;
  }
  else {
    *(byte *)in_FSR0 = *(byte *)in_FSR0 | 1;
  }
  c18_tmp0 = (cfg_systemconfig2 & 0x38) >> 3;
  pbVar4 = (byte *)in_FSR2;
  bVar3 = ui_frag_25a6(c18_tmp0);
  *pbVar4 = in_PRODL | *pbVar4 & bVar3;
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR2;
  ui_to_param_write_215a(0x2b);
  ui_to_param_table_lookup_21e4(0x31);
  ui_to_param_write_215a(0x31);
  ui_to_param_table_lookup_21e4(0x37);
  ui_to_param_write_215a(0x37);
  ui_to_param_table_lookup_21e4(0x36);
  ui_to_param_write_215a(0x36);
  ui_to_param_table_lookup_21e4(0x39);
  ui_to_param_write_215a(0x39);
  ui_to_param_table_lookup_21e4(0x38);
  ui_to_param_write_215a(0x38);
  ui_to_param_table_lookup_21e4(0x2c);
  ui_to_param_write_215a(0x2c);
  ui_to_param_table_lookup_25d4(0x25);
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  if ((*pbVar4 & 0x80) != 0) {
    cfg_systemconfig = cfg_systemconfig | 0x80;
  }
  pbVar2 = pbVar1 + 1;
  *pbVar1 = cfg_systemconfig;
  ui_to_param_write_215a(0x25);
  ui_to_param_table_lookup_21e4(3);
  ui_to_param_write_215a(3);
  ui_to_param_table_lookup_21e4(0x32);
  ui_to_param_write_215a(0x32);
  ui_to_param_table_lookup_21e4(0x33);
  ui_to_param_write_215a(0x33);
  ui_to_param_table_lookup_21e4(0x3e);
  ui_to_param_write_215a(0x3e);
  ui_to_param_table_lookup_21e4(0x34);
  ui_to_param_write_215a(0x34);
  ui_to_param_table_lookup_21e4(0x35);
  ui_to_param_write_215a(0x35);
  ui_to_param_table_lookup_21e4(0x42);
  ui_to_param_write_215a(0x42);
  ui_to_param_table_lookup_21e4(0x28);
  ui_to_param_write_215a(0x28);
  menu_default_back();
  *pbVar2 = *pbVar2;
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x000200 restore_factory_apply =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Restore factory settings: rewrite SYSTEMCONFIG2 language bits and user parameters */

void restore_factory_apply(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  byte in_PRODL;
  
  c18_tmp0 = (*(byte *)((ushort)unaff_BSR * 0x100 + 0x58) & 0x38) >> 3;
  pbVar4 = (byte *)in_FSR2;
  bVar3 = ui_frag_25a6(c18_tmp0);
  *pbVar4 = in_PRODL | *pbVar4 & bVar3;
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR2;
  ui_to_param_write_215a(0x2b);
  ui_to_param_table_lookup_21e4(0x31);
  ui_to_param_write_215a(0x31);
  ui_to_param_table_lookup_21e4(0x37);
  ui_to_param_write_215a(0x37);
  ui_to_param_table_lookup_21e4(0x36);
  ui_to_param_write_215a(0x36);
  ui_to_param_table_lookup_21e4(0x39);
  ui_to_param_write_215a(0x39);
  ui_to_param_table_lookup_21e4(0x38);
  ui_to_param_write_215a(0x38);
  ui_to_param_table_lookup_21e4(0x2c);
  ui_to_param_write_215a(0x2c);
  ui_to_param_table_lookup_25d4(0x25);
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  if ((*pbVar4 & 0x80) != 0) {
    cfg_systemconfig = cfg_systemconfig | 0x80;
  }
  pbVar2 = pbVar1 + 1;
  *pbVar1 = cfg_systemconfig;
  ui_to_param_write_215a(0x25);
  ui_to_param_table_lookup_21e4(3);
  ui_to_param_write_215a(3);
  ui_to_param_table_lookup_21e4(0x32);
  ui_to_param_write_215a(0x32);
  ui_to_param_table_lookup_21e4(0x33);
  ui_to_param_write_215a(0x33);
  ui_to_param_table_lookup_21e4(0x3e);
  ui_to_param_write_215a(0x3e);
  ui_to_param_table_lookup_21e4(0x34);
  ui_to_param_write_215a(0x34);
  ui_to_param_table_lookup_21e4(0x35);
  ui_to_param_write_215a(0x35);
  ui_to_param_table_lookup_21e4(0x42);
  ui_to_param_write_215a(0x42);
  ui_to_param_table_lookup_21e4(0x28);
  ui_to_param_write_215a(0x28);
  menu_default_back();
  *pbVar2 = *pbVar2;
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x0002fa menu_restore_factory_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_restore_factory_on_enter(void)

{
  if (menu_edit_mode == '\0') {
    menu_default_back();
    return;
  }
  lcd_clear(menu_edit_mode);
  ui_to_ui_draw_title_word_2874(0x48);
  menu_cb_enter = 0xde;
  menu_set_cbs_enter_hi(1);
  return;
}


// ===== 0x000304 ui_to_lcd_clear_0304 =====

/* Auto: writes menu_cb_enter; calls lcd_clear,menu_set_cbs_enter_hi; 7 instr */

void ui_to_lcd_clear_0304(void)

{
  byte unaff_BSR;
  
  lcd_clear();
  ui_to_ui_draw_title_word_2874(0x48);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xde;
  menu_set_cbs_enter_hi(1);
  return;
}


// ===== 0x000318 menu_restore_factory =====

/* Menu/screen handler (callback analysis) */

void menu_restore_factory(void)

{
  BADSPACEBASE *in_FSR1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  lcd_clear();
  *(undefined1 *)in_FSR1 = 0x48;
  ui_to_ui_draw_title_2986();
  menu_cb_enter = 0xfa;
  menu_set_cbs_back_default(2);
  return;
}


// ===== 0x000334 menu_reset_confirm2 =====

/* Menu/screen handler (callback analysis) */

undefined1 menu_reset_confirm2(void)

{
  menu_flag = 1;
  return 1;
}


// ===== 0x00033c ui_get_menu_flag_033c =====

/* Auto: reads menu_flag; 3 instr */

undefined1 ui_get_menu_flag_033c(void)

{
  return menu_flag;
}


// ===== 0x000342 menu_reset_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_reset_on_enter(void)

{
  if (menu_edit_mode == '\0') {
    menu_default_back();
    return;
  }
  lcd_clear(menu_edit_mode);
  ui_to_ui_draw_title_word_2874(0x8b);
  menu_cb_enter = 0x34;
  menu_set_cbs_enter_hi(3);
  return;
}


// ===== 0x000360 menu_reset =====

/* Menu/screen handler (callback analysis) */

void menu_reset(void)

{
  BADSPACEBASE *in_FSR1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  lcd_clear();
  *(undefined1 *)in_FSR1 = 0x8b;
  ui_to_ui_draw_title_2986();
  menu_cb_enter = 0x42;
  menu_set_cbs_back_default(3);
  return;
}


// ===== 0x00037c menu_language =====

/* Menu/screen handler (callback analysis) */

undefined1 menu_language(undefined1 param_1)

{
  char cVar1;
  byte unaff_Z;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return param_1;
  }
  ui_to_ui_get_menu_table_ptr_lo_28f6();
  ui_get_menu_item_2296();
  if ((unaff_Z & 1) == 0) {
    ui_get_menu_item_2254();
    menu_item = 0;
    while( true ) {
      cVar1 = menu_item - 8;
      if (7 < menu_item) break;
      ui_get_menu_item_24ba(cVar1);
      ui_get_c18_tmp0_25e8();
      if (cVar1 == '\0') break;
      menu_item = menu_item + 1;
    }
    cVar1 = menu_item - 8;
    if (7 < menu_item) {
      menu_item = 0;
    }
    menu_draw(cVar1);
  }
  menu_cb_enter = 0xcc;
  menu_cb_enter_hi = 3;
  menu_cb_back = 0xe2;
  menu_cb_back_hi = 3;
  return 3;
}


// ===== 0x0003cc menu_language_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_language_on_enter(void)

{
  byte bVar1;
  byte unaff_BSR;
  
  ui_set_cfg_systemconfig2_285a();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x26) | *(byte *)((ushort)unaff_BSR * 0x100 + 0x25);
  if (bVar1 != 0) {
    ui_get_menu_item_2270(bVar1);
    menu_draw();
  }
  ui_bank1_ui_set_menu_cb_enter_26ce();
  return;
}


// ===== 0x0003e2 menu_language_on_back =====

/* Menu/screen handler (callback analysis) */

void menu_language_on_back(void)

{
  if ((menu_table_ptr_hi | menu_table_ptr_lo) != 0) {
    ui_get_menu_item_2270(menu_table_ptr_hi | menu_table_ptr_lo);
    menu_draw();
  }
  ui_bank1_ui_set_menu_cb_enter_26ce();
  return;
}


// ===== 0x0003f6 ui_draw_set_hint =====

/* WARNING: Removing unreachable block (CODE,0x000412) */
/* WARNING: Removing unreachable block (CODE,0x000440) */
/* Draw "USE COLD / CUP TO SET TEMP./QTY." hint */

void ui_draw_set_hint(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 uVar2;
  byte unaff_Z;
  
  ui_to_lcd_clear_29ac();
  text_row = 2;
  ui_to_ui_get_cfg_systemconfig2_2334();
  if ((unaff_Z & 1) == 0) {
    c18_tmp0 = 2;
  }
  else {
    c18_tmp0 = 4;
  }
  c18_tmp1 = 0;
  ui_get_c18_tmp0_29a2();
  cVar1 = *(char *)((short)in_FSR2 + -3);
  if (cVar1 == '\0') {
    uVar2 = 0x66;
  }
  else {
    uVar2 = 0x65;
  }
  ui_stack_adjust_21f4(uVar2);
  text_row = 5;
  ui_to_ui_get_cfg_systemconfig2_2334();
  if (cVar1 == '\0') {
    c18_tmp0 = 4;
  }
  else {
    c18_tmp0 = 2;
  }
  c18_tmp1 = 0;
  ui_get_c18_tmp0_29a2();
  ui_stack_adjust_21f4(100);
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x000450 ui_chain_ui_to_lcd_clear_fn21d8_0450 =====

/* Auto: Calls ui_to_lcd_clear, 0x21d8; 2 instr */

void ui_chain_ui_to_lcd_clear_fn21d8_0450(void)

{
  ui_to_lcd_clear_29ac();
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x000458 screen_energy_saving_draw =====

/* Draw energy-saving setting ("MODE IS OFF" / "SHUT OFF HEATER AFTER %d MIN") */

undefined1 screen_energy_saving_draw(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  undefined1 uVar2;
  undefined1 in_PRODL;
  byte unaff_Z;
  byte unaff_C;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) != 0) {
    ui_to_ui_set_ui_wake_pending_2a20();
    *(undefined1 *)in_FSR1 = 0x22;
    *(undefined1 *)((short)in_FSR1 + 1) = 0;
    uVar2 = ui_stack_adjust_21f4(0x72);
    return uVar2;
  }
  ui_to_ui_set_ui_wake_pending_2a20();
  c18_tmp0 = menu_value_lo;
  c18_tmp1 = menu_value_hi;
  ui_get_c18_tmp1_2632(0x1e);
  *(undefined1 *)in_FSR1 = in_PRODL;
  *(undefined1 *)((short)in_FSR1 + 1) = c18_tmp1;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x22;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 4) >> 8);
  *(undefined1 *)((short)in_FSR1 + 3) = 0;
  ui_callw_txt_set_ui_hold_counter_25b4(0x73);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  return c18_tmp2;
}


// ===== 0x0004a0 menu_energy_saving_mode_on_enter =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 in_PRODL;
  byte unaff_Z;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) == 0) {
    cfg_systemconfig2 = cfg_systemconfig2 | 1;
    ui_get_menu_value_hi_23d8(3);
    pbVar1 = (byte *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = in_PRODL;
    ui_to_param_write_215a(0x23);
  }
  else {
    cfg_systemconfig2 = cfg_systemconfig2 & 0xfe;
    pbVar1 = (byte *)in_FSR1;
  }
  *pbVar1 = cfg_systemconfig2;
  ui_to_menu_default_back_279e(0x2b);
  return;
}


// ===== 0x0004cc menu_energy_saving_mode_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode_on_up(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  ui_set_menu_value_lo_2720();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) ^ 9;
  if ((bVar1 == 0) && (bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 0;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  screen_energy_saving_draw(bVar1);
  return;
}


// ===== 0x0004e2 menu_energy_saving_mode_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode_on_down(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte unaff_Z;
  
  bVar1 = ui_set_menu_value_lo_2678();
  if (((unaff_Z & 1) != 0) && (bVar1 = ~*(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    bVar1 = 8;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 8;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  screen_energy_saving_draw(bVar1);
  return;
}


// ===== 0x0004f6 menu_energy_saving_mode =====

/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_callw_fn0450_2b5e(0x22);
  if ((cfg_systemconfig2 & 1) == 0) {
    ui_set_menu_value_lo_26a6();
  }
  else {
    *(undefined1 *)in_FSR1 = 0x23;
    cVar2 = ui_to_eeprom_read_raw_2b00();
    cVar1 = cVar2 * '\n';
    ui_set_menu_value_lo_2bae(cVar2 * '\n');
    math_aarg_lo = cVar1;
    math_barg_lo = 0x1e;
    math_barg_hi = 0;
    math_aarg_hi = menu_value_hi;
    ui_to___divs16_289c();
  }
  screen_energy_saving_draw();
  menu_cb_enter = 0xa0;
  menu_cb_enter_hi = 4;
  menu_cb_up = 0xcc;
  menu_cb_up_hi = 4;
  menu_cb_down = 0xe2;
  menu_set_cbs_down_hi(4);
  return;
}


// ===== 0x00054e screen_power_down_draw =====

/* Draw auto power-down setting ("OFF" / "POWER DOWN AFTER %d HOURS") */

undefined1 screen_power_down_draw(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  undefined1 uVar2;
  byte unaff_Z;
  byte unaff_C;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) != 0) {
    ui_to_ui_set_ui_wake_pending_2a20();
    *(undefined1 *)in_FSR1 = 0x22;
    *(undefined1 *)((short)in_FSR1 + 1) = 0;
    uVar2 = ui_stack_adjust_21f4(0x70);
    return uVar2;
  }
  ui_to_ui_set_ui_wake_pending_2a20();
  ui_to___mul16x16_32_24ea(0x18);
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  *(undefined1 *)in_FSR1 = math_res0;
  *(undefined1 *)((short)in_FSR1 + 1) = math_res1;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x22;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 4) >> 8);
  *(undefined1 *)((short)in_FSR1 + 3) = 0;
  ui_callw_txt_set_ui_hold_counter_25b4(0x71);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  return c18_tmp2;
}


// ===== 0x000596 menu_power_down_mode_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_to___mul16x16_32_24ea(0x18);
  *(undefined1 *)in_FSR1 = math_res0;
  ui_to_menu_default_back_279e(0x31);
  return;
}


// ===== 0x0005a6 menu_power_down_mode_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode_on_up(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  ui_set_menu_value_lo_2720();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) ^ 4;
  if ((bVar1 == 0) && (bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 0;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  screen_power_down_draw(bVar1);
  return;
}


// ===== 0x0005bc menu_power_down_mode_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode_on_down(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte unaff_Z;
  
  bVar1 = ui_set_menu_value_lo_2678();
  if (((unaff_Z & 1) != 0) && (bVar1 = ~*(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    bVar1 = 3;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 3;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  screen_power_down_draw(bVar1);
  return;
}


// ===== 0x0005d0 menu_power_down_mode =====

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_callw_fn0450_2b5e(10);
  ui_callw_ui_to_eeprom_read_raw_228c(0x31);
  ui_get_menu_value_lo_22aa(0x18);
  screen_power_down_draw();
  menu_cb_enter = 0x96;
  menu_cb_enter_hi = 5;
  menu_cb_up = 0xa6;
  menu_cb_up_hi = 5;
  menu_cb_down = 0xbc;
  menu_set_cbs_down_hi(5);
  return;
}


// ===== 0x000606 ui_set_text_fill_width_0606 =====

/* Auto: writes text_fill_width; reads menu_value_lo; 18 instr */

void ui_set_text_fill_width_0606(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  cVar2 = ui_get_cfg_systemconfig2_2b2e();
  if (cVar2 == '\a') {
    ui_set_text_row_2b08();
    text_fill_width = 0x3c;
  }
  else {
    ui_set_text_row_2b08();
    text_fill_width = 0x44;
  }
  *(undefined1 *)in_FSR1 = 0xe4;
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  puVar1 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = menu_value_lo;
  ui_to_txt_set_ui_hold_counter_28b4();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x000634 menu_clock_day_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_clock_day_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  clock_set_day();
  *puVar1 = *puVar1;
  menu_default_back();
  return;
}


// ===== 0x000642 menu_clock_day_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_clock_day_on_down(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte unaff_Z;
  
  bVar1 = ui_set_menu_value_lo_2678();
  if (((unaff_Z & 1) != 0) && (bVar1 = ~*(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    bVar1 = 6;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 6;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  ui_set_text_fill_width_0606(bVar1);
  return;
}


// ===== 0x000656 menu_clock_day_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_clock_day_on_up(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  ui_set_menu_value_lo_2720();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) ^ 7;
  if ((bVar1 == 0) && (bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 0;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  ui_set_text_fill_width_0606(bVar1);
  return;
}


// ===== 0x00066c menu_clock_day =====

/* Menu/screen handler (callback analysis) */

void menu_clock_day(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_get_TBLPTRL_22ba();
  ui_to_ui_set_text_row_245a();
  ui_stack_adjust_21f4(0x38);
  clock_get_day();
  ui_set_menu_value_lo_2bae();
  ui_set_text_fill_width_0606();
  menu_item = 1;
  menu_cb_enter = 0x34;
  menu_cb_enter_hi = 6;
  menu_cb_up = 0x56;
  menu_cb_up_hi = 6;
  menu_cb_down = 0x42;
  menu_set_cbs_down_hi(6);
  return;
}


// ===== 0x0006aa ui_draw_time =====

/* Draw time "%02b:%02b AM/PM" for clock/wake-up editing */

void ui_draw_time(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  char cVar7;
  bool bVar8;
  
  ui_c18_prologue_2166();
  ui_set_text_row_2b08();
  if ((menu_value_lo == '\x02') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = uVar6;
  cVar7 = mod_get_clock_edit_ampm_a774();
  if (cVar7 == '\0') {
    c18_tmp0 = 0xc4;
  }
  else {
    cVar7 = mod_get_clock_edit_ampm_a774();
    if (cVar7 == '\x01') {
      c18_tmp0 = 0xc1;
    }
    else if (*(char *)((short)in_FSR2 + -2) == '\0') {
      c18_tmp0 = 0xbb;
    }
    else {
      c18_tmp0 = 0xbe;
    }
  }
  c18_tmp1 = 0x58;
  *puVar1 = c18_tmp0;
  puVar1[1] = 0x58;
  if ((menu_value_lo == '\x02') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar1[2] = uVar6;
  if ((menu_value_lo == '\x01') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar2 = puVar1 + 4;
  puVar1[3] = uVar6;
  uVar6 = mod_get_clock_edit_minute_a74a();
  *puVar2 = uVar6;
  if ((menu_value_lo == '\x01') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar2[1] = uVar6;
  bVar8 = menu_value_hi != '\0' || menu_value_lo != '\0';
  if (bVar8) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0xd;
  }
  puVar3 = puVar2 + 3;
  puVar2[2] = uVar6;
  uVar6 = clock_edit_hour12();
  puVar4 = puVar3 + 1;
  *puVar3 = uVar6;
  ui_get_menu_value_lo_2778();
  if (bVar8) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0xd;
  }
  *puVar4 = uVar6;
  puVar4[1] = 4;
  puVar4[2] = 0;
  puVar5 = puVar4 + 4;
  puVar4[3] = 199;
  c18_tmp2 = ui_callw_txt_set_ui_hold_counter_2b10(0x58);
  if ((byte)puVar5 < 0xe) {
    *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
  }
  ui_c18_epilogue_21d8(c18_tmp2);
  return;
}


// ===== 0x000788 menu_clock_time_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_clock_time_on_down(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_clock_edit_hour_a730();
  *puVar1 = *puVar1;
  ui_to_ui_draw_time_23ea();
  return;
}


// ===== 0x000794 menu_clock_time_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_clock_time_on_up(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_clock_edit_hour_a718();
  *puVar1 = *puVar1;
  ui_to_ui_draw_time_23ea();
  return;
}


// ===== 0x0007a0 screen_clock_edit_hour_on_down =====

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_on_down(void)

{
  mod_set_clock_edit_minute_a750();
  ui_to_ui_draw_time_23ea();
  return;
}


// ===== 0x0007a8 screen_clock_edit_hour_on_up =====

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_on_up(void)

{
  mod_set_clock_edit_minute_a760();
  ui_to_ui_draw_time_23ea();
  return;
}


// ===== 0x0007b0 screen_clock_edit_hour_confirm2 =====

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_confirm2(void)

{
  mod_get_clock_edit_ampm_a77a();
  menu_default_back();
  return;
}


// ===== 0x0007b8 screen_clock_edit_hour_edit_on_down =====

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_edit_on_down(void)

{
  mod_set_clock_edit_ampm_a78e();
  ui_to_ui_draw_time_23ea();
  return;
}


// ===== 0x0007c0 screen_clock_edit_hour_edit_on_up =====

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_edit_on_up(void)

{
  mod_set_clock_edit_ampm_a780();
  ui_to_ui_draw_time_23ea();
  return;
}


// ===== 0x0007c8 screen_clock_edit_hour_edit_on_back =====

/* Menu/screen handler (callback analysis) */

undefined1 screen_clock_edit_hour_edit_on_back(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = ui_set_menu_value_lo_2bae(1);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = uVar2;
  ui_draw_time();
  *puVar1 = *puVar1;
  menu_cb_up = 0xa8;
  menu_cb_up_hi = 7;
  menu_cb_down = 0xa0;
  menu_cb_down_hi = 7;
  menu_cb_back = 6;
  menu_cb_back_hi = 8;
  menu_cb_enter = 0xcc;
  menu_cb_enter_hi = 7;
  return 7;
}


// ===== 0x0007cc screen_clock_edit_minute =====

/* Clock set: edit minutes */

undefined1 screen_clock_edit_minute(void)

{
  mod_get_clock_edit_minute_a76e();
  ui_set_menu_value_lo_2bae(2);
  ui_to_ui_draw_time_23ea();
  menu_cb_up = 0xc0;
  menu_cb_up_hi = 7;
  menu_cb_down = 0xb8;
  menu_cb_down_hi = 7;
  menu_cb_back = 200;
  menu_cb_back_hi = 7;
  menu_cb_enter = 0xb0;
  menu_cb_enter_hi = 7;
  return 7;
}


// ===== 0x0007fe menu_clock_time_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_clock_time_on_enter(void)

{
  mod_get_clock_edit_hour_a6f8();
  screen_clock_edit_hour();
  return;
}


// ===== 0x000806 screen_clock_edit_hour_on_back =====

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_on_back(void)

{
  ui_set_menu_value_lo_26a6();
  ui_to_ui_draw_time_23ea();
  ui_to_menu_set_cbs_down_hi_2882();
  return;
}


// ===== 0x000814 menu_clock_time =====

/* Menu/screen handler (callback analysis) */

void menu_clock_time(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_get_TBLPTRL_22ba();
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x39);
  clock_copy_to_edit();
  ui_to_ui_draw_time_23ea();
  menu_item = 0;
  ui_to_menu_set_cbs_down_hi_2882();
  return;
}


// ===== 0x000838 screen_value_edit_setup_on_down =====

/* Menu/screen handler (callback analysis) */

void screen_value_edit_setup_on_down(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_clock_edit_hour_a730();
  *puVar1 = *puVar1;
  ui_to_ui_draw_time_249e();
  return;
}


// ===== 0x000846 screen_value_edit_setup_on_up =====

/* Menu/screen handler (callback analysis) */

void screen_value_edit_setup_on_up(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_clock_edit_hour_a718();
  *puVar1 = *puVar1;
  ui_to_ui_draw_time_249e();
  return;
}


// ===== 0x000854 screen_value_edit_setup_b_on_down =====

/* Menu/screen handler (callback analysis) */

void screen_value_edit_setup_b_on_down(void)

{
  mod_set_clock_edit_minute_a750();
  ui_to_ui_draw_time_249e();
  return;
}


// ===== 0x00085c screen_value_edit_setup_b_on_up =====

/* Menu/screen handler (callback analysis) */

void screen_value_edit_setup_b_on_up(void)

{
  mod_set_clock_edit_minute_a760();
  ui_to_ui_draw_time_249e();
  return;
}


// ===== 0x000864 fn_087a_on_back =====

/* Menu/screen handler (callback analysis) */

void fn_087a_on_back(void)

{
  ui_set_menu_value_lo_26a6();
  screen_wakeup1_edit_hour();
  return;
}


// ===== 0x00086c fn_087a_on_enter =====

/* Menu/screen handler (callback analysis) */

void fn_087a_on_enter(void)

{
  mod_get_clock_edit_minute_a74a();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_menu_default_back_279e(0x37);
  return;
}


// ===== 0x00087a screen_wakeup1_edit_minute =====

/* Wake up 1: edit minute (WKUPMINUTE1) */

undefined1 screen_wakeup1_edit_minute(void)

{
  byte unaff_BSR;
  
  mod_get_clock_edit_hour_a6f2();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_screen_time_edit_setup_b_2964(0x36);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 100;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 8;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x6c;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}


// ===== 0x00089a menu_wakeup_1_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_wakeup_1_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  byte unaff_Z;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0xef;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x10;
  }
  ui_get_cfg_systemconfig3_2a28();
  if ((unaff_Z & 1) != 0) {
    menu_default_back();
    return;
  }
  *(undefined1 *)in_FSR1 = 0x36;
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x49);
  clock_edit_load_wake1();
  screen_wakeup1_edit_hour();
  return;
}


// ===== 0x0008c4 menu_wakeup_1 =====

/* Menu/screen handler (callback analysis) */

void menu_wakeup_1(void)

{
  byte bVar1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  bVar1 = ui_to_ui_draw_on_off_22ea(0x36);
  ui_set_menu_edit_mode_2386((bVar1 & 0x10) != 0);
  menu_cb_enter = 0x9a;
  menu_set_cbs_back_default(8);
  return;
}


// ===== 0x0008e4 fn_08fa_on_back =====

/* Menu/screen handler (callback analysis) */

void fn_08fa_on_back(void)

{
  ui_set_menu_value_lo_26a6();
  screen_wakeup2_edit_hour();
  return;
}


// ===== 0x0008ec fn_08fa_on_enter =====

/* Menu/screen handler (callback analysis) */

void fn_08fa_on_enter(void)

{
  mod_get_clock_edit_minute_a74a();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_menu_default_back_279e(0x39);
  return;
}


// ===== 0x0008fa screen_wakeup2_edit_minute =====

/* Wake up 2: edit minute (WKUPMINUTE2) */

undefined1 screen_wakeup2_edit_minute(void)

{
  byte unaff_BSR;
  
  mod_get_clock_edit_hour_a6f2();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_screen_time_edit_setup_b_2964(0x38);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xe4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 8;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xec;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}


// ===== 0x00091a menu_wakeup_2_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_wakeup_2_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  byte unaff_Z;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0xdf;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x20;
  }
  ui_get_cfg_systemconfig3_2a28();
  if ((unaff_Z & 1) != 0) {
    menu_default_back();
    return;
  }
  *(undefined1 *)in_FSR1 = 0x37;
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x4a);
  clock_edit_load_wake2();
  screen_wakeup2_edit_hour();
  return;
}


// ===== 0x00092e ui_to_clock_edit_load_wake2_092e =====

/* Auto: calls clock_edit_load_wake2,screen_wakeup2_edit_hour; 7 instr */

void ui_to_clock_edit_load_wake2_092e(void)

{
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x4a);
  clock_edit_load_wake2();
  screen_wakeup2_edit_hour();
  return;
}


// ===== 0x000944 menu_wakeup_2 =====

/* Menu/screen handler (callback analysis) */

void menu_wakeup_2(void)

{
  byte bVar1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  bVar1 = ui_to_ui_draw_on_off_22ea(0x37);
  ui_set_menu_edit_mode_2386((bVar1 & 0x20) != 0);
  menu_cb_enter = 0x1a;
  menu_set_cbs_back_default(9);
  return;
}


// ===== 0x00094a ui_to_menu_set_cbs_back_default_094a =====

/* Auto: writes menu_cb_enter; calls menu_set_cbs_back_default; 10 instr */

void ui_to_menu_set_cbs_back_default_094a(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  bVar1 = ui_to_ui_draw_on_off_22ea(0x37);
  ui_set_menu_edit_mode_2386((bVar1 & 0x20) != 0);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x1a;
  menu_set_cbs_back_default(9);
  return;
}


// ===== 0x000964 ui_get_cfg_systemconfig3_0964 =====

/* Auto: reads cfg_systemconfig3; 3 instr */

void ui_get_cfg_systemconfig3_0964(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if ((cfg_systemconfig3 & 4) != 0) {
    ui_push_args_4c_096e();
    return;
  }
  puVar1 = &FramePointer10x0001;
  txt_to_mod_set_lcd_text_flag_92f2();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00096a ui_const_then_0970_096a =====

/* Auto: compiler fragment: MOVLW #0x4b ; BRA 0x000970 */

void ui_const_then_0970_096a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  txt_to_mod_set_lcd_text_flag_92f2();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00096e ui_push_args_4c_096e =====

/* Auto: Push constant arguments [76] then call 0x92f2; 5 instr */

void ui_push_args_4c_096e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  txt_to_mod_set_lcd_text_flag_92f2();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00097a ui_draw_temp_value =====

/* Draw a temperature with deg C/deg F symbol (converts when imperial) */

void ui_draw_temp_value(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  byte *pbVar2;
  char cVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  cVar3 = ui_frag_2b16();
  text_row = *(undefined1 *)((short)in_FSR2 + (short)cVar3 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 2);
  text_x = *(undefined1 *)((short)in_FSR2 + -2);
  text_fill_width = 0x23;
  ui_get_cfg_systemconfig3_258a();
  if ((unaff_Z & 1) == 0) {
    uVar4 = 0x4c;
  }
  else {
    uVar4 = 0x4b;
  }
  ui_to_ui_word_ptr_2536(uVar4);
  if ((cfg_systemconfig3 & 4) == 0) {
    ui_get_c18_tmp2_26d4();
    math_aarg_lo = (byte)((ushort)c18_tmp2 * 9);
    math_aarg_hi = c18_tmp3 * '\t' + (char)((ushort)c18_tmp2 * 9 >> 8);
    math_barg_lo = 5;
    math_barg_hi = 0;
    c18_tmp2 = math_aarg_lo;
    c18_tmp3 = math_aarg_hi;
    __divs16();
    c18_tmp2 = math_aarg_lo + 0x20;
    c18_tmp3 = math_aarg_hi + (0xdf < math_aarg_lo);
  }
  else {
    ui_get_c18_tmp2_26d4();
  }
  *(byte *)in_FSR1 = c18_tmp2;
  pbVar2 = (byte *)((short)in_FSR1 + 2);
  *(char *)((short)in_FSR1 + 1) = c18_tmp3;
  c18_tmp4 = puVar1[-6];
  c18_tmp5 = ui_stack_adjust_2644(c18_tmp4 | 0x60);
  if ((byte)pbVar2 < 8) {
    *(undefined1 *)((ushort)pbVar2 & 0xff00) = *(undefined1 *)((ushort)pbVar2 & 0xff00);
  }
  ui_c18_epilogue_21d8(c18_tmp5);
  return;
}


// ===== 0x000a0e ui_draw_temp_units =====

/* Draw temperature in selected units */

void ui_draw_temp_units(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  byte bVar6;
  byte *pbVar5;
  byte bVar7;
  char cVar8;
  byte unaff_C;
  
  ui_c18_prologue_2166();
  text_row = *(undefined1 *)((short)in_FSR2 + -4);
  text_x = *(undefined1 *)((short)in_FSR2 + -4);
  if ((cfg_systemconfig3 & 4) == 0) {
    *(undefined1 *)in_FSR1 = 0xf;
    bVar1 = *(byte *)((short)in_FSR2 + -1);
    puVar3 = (undefined1 *)((short)in_FSR2 + 4);
    bVar2 = *(byte *)((short)in_FSR2 + 1);
    bVar7 = *(byte *)in_FSR1;
    c18_tmp0 = bVar1 + bVar7;
    c18_tmp1 = bVar2 + CARRY1(bVar1,bVar7);
    ui_to___divs16_28c8(0x1e);
    *(undefined1 *)in_FSR1 = math_aarg_lo;
    *(undefined1 *)((short)in_FSR1 + 1) = math_aarg_hi;
    *(undefined1 *)((short)in_FSR1 + 2) = puVar3[-6];
    bVar6 = (byte)((ushort)((short)in_FSR1 + 4) >> 8);
    *(undefined1 *)((short)in_FSR1 + 3) = 0;
    ui_callw_txt_set_ui_hold_counter_25b4(0x61);
    cVar8 = c18_tmp2;
    if (!CARRY1(bVar2,CARRY1(bVar1,bVar7))) {
      *(undefined1 *)((ushort)bVar6 << 8) = *(undefined1 *)((ushort)bVar6 << 8);
      cVar8 = c18_tmp2;
    }
  }
  else {
    pbVar5 = (byte *)((short)in_FSR1 + 1);
    puVar4 = (undefined1 *)((short)in_FSR2 + 3);
    *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -1);
    ui_frame_push_args_25cc();
    *pbVar5 = puVar4[-6];
    pbVar5[1] = 0;
    bVar7 = (byte)((ushort)(pbVar5 + 3) >> 8);
    pbVar5[2] = 0x60;
    txt_set_ui_hold_counter_98fc();
    ui_compare_multibyte_2b1e();
    cVar8 = c18_tmp0;
    if ((unaff_C & 1) == 0) {
      *(undefined1 *)((ushort)bVar7 << 8) = *(undefined1 *)((ushort)bVar7 << 8);
      cVar8 = c18_tmp0;
    }
  }
  ui_c18_epilogue_21d8(cVar8);
  return;
}


// ===== 0x000a90 menu_cold_water_temp =====

/* Menu/screen handler (callback analysis) */

void menu_cold_water_temp(void)

{
  bool bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar9;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar10;
  undefined1 uVar11;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(3);
  ui_set_menu_value_step_lo_2344(3);
  cVar10 = '\x05';
  if ((menu_value_step_hi & 0x80) == 0) {
    bVar1 = menu_value_step_hi != ~(4 < menu_value_step_lo);
    cVar10 = menu_value_step_hi - ~(4 < menu_value_step_lo);
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    cVar10 = '\x05';
    menu_value_step_lo = 5;
    menu_value_step_hi = 0;
  }
  ui_get_menu_value_step_lo_2568(cVar10);
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x50;
  uVar11 = ui_to_ui_draw_temp_value_2356(2);
  uVar9 = (undefined1)((ushort)puVar2 >> 8);
  if (!bVar1) {
    puVar3 = (undefined1 *)((ushort)puVar2 & 0xff00);
    uVar9 = (undefined1)((ushort)(puVar3 + -1) >> 8);
    *puVar3 = *puVar3;
  }
  puVar4 = (undefined1 *)CONCAT11(uVar9,uVar11);
  ui_get_menu_value_max_lo_2574(c18_tmp0);
  puVar5 = puVar4 + 1;
  *puVar4 = 0x50;
  uVar11 = ui_to_ui_draw_temp_value_2356(6);
  uVar9 = (undefined1)((ushort)puVar5 >> 8);
  if (!bVar1) {
    puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
    uVar9 = (undefined1)((ushort)(puVar6 + -1) >> 8);
    *puVar6 = *puVar6;
  }
  puVar7 = (undefined1 *)CONCAT11(uVar9,uVar11);
  ui_callw_ui_to_eeprom_read_raw_228c(3);
  puVar8 = puVar7 + 1;
  *puVar7 = 1;
  screen_cold_temp_bar();
  *puVar8 = *puVar8;
  menu_cb_enter = 0x18;
  menu_cb_enter_hi = 0xb;
  menu_cb_up = 0x9e;
  menu_cb_up_hi = 0x1d;
  menu_cb_down = 0x5e;
  menu_set_cbs_down_hi(0x1d);
  return;
}


// ===== 0x000b18 menu_cold_water_temp_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_cold_water_temp_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_to_param_write_215a(3);
  *puVar1 = menu_value_lo;
  ui_to_menu_default_back_279e(2);
  return;
}


// ===== 0x000b2c menu_mix_water_temp =====

/* Menu/screen handler (callback analysis) */

void menu_mix_water_temp(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar4;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar5;
  undefined1 uVar6;
  byte unaff_C;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(0x33);
  ui_set_menu_value_step_lo_2344(0x33);
  ui_get_menu_value_max_lo_2574();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x50;
  uVar6 = ui_to_ui_draw_temp_value_2356(2);
  uVar4 = (undefined1)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    uVar4 = (undefined1)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  puVar3 = (undefined1 *)CONCAT11(uVar4,uVar6);
  ui_get_menu_value_step_lo_2568(c18_tmp0);
  bVar5 = (byte)((ushort)(puVar3 + 1) >> 8);
  *puVar3 = 0x50;
  ui_to_ui_draw_temp_value_2356(6);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar5 << 8) = *(undefined1 *)((ushort)bVar5 << 8);
  }
  ui_callw_ui_to_eeprom_read_raw_228c(0x33);
  ui_to_screen_cold_temp_bar_2684();
  menu_cb_enter = 0x92;
  menu_cb_enter_hi = 0xb;
  menu_cb_up = 0x32;
  menu_cb_up_hi = 0x1c;
  menu_cb_down = 0x74;
  menu_set_cbs_down_hi(0x1c);
  return;
}


// ===== 0x000b92 menu_mix_water_temp_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_mix_water_temp_on_enter(void)

{
  ui_to_menu_default_back_279e(0x33);
  return;
}


// ===== 0x000b9c screen_param_checksum =====

/* WARNING: Removing unreachable block (CODE,0x000c06) */
/* Compute and show "PARAMETERS CS" (sum of 75 EEPROM parameters) */

void screen_param_checksum(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 uVar7;
  undefined1 *puVar6;
  undefined1 uVar8;
  
  ui_stack_adjust_2af8();
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  puVar6 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  pbVar2 = (byte *)((short)in_FSR2 + 1);
  *(undefined1 *)((short)in_FSR2 + 2) = 0;
  if ((cfg_systemconfig5 & 0x10) != 0) {
    ui_callw_fn0450_2b5e(0x89);
    *pbVar2 = 0;
    pbVar4 = puVar3;
    for (; bVar1 = *pbVar2, bVar1 < 0x4b; pbVar2 = pbVar2 + 2) {
      pbVar5 = pbVar4 + 1;
      *pbVar4 = *pbVar2;
      c18_tmp0 = ui_to_eeprom_read_raw_2b00(bVar1 + 0xb5);
      *pbVar5 = pbVar2[2];
      *pbVar5 = *pbVar5 + c18_tmp0;
      pbVar2[3] = *pbVar5;
      pbVar2[2] = pbVar2[2] + '\x01';
      pbVar4 = pbVar5;
    }
    text_row = 4;
    text_x = 0x1e;
    text_fill_width = 0x23;
    *pbVar4 = pbVar2[2];
    pbVar4[1] = 6;
    pbVar4[2] = 0;
    uVar7 = (undefined1)((ushort)(pbVar4 + 4) >> 8);
    pbVar4[3] = 0xb3;
    ui_callw_txt_set_ui_hold_counter_2b10(0x58);
    uVar8 = ui_compare_multibyte_2b1e();
    puVar6 = (undefined1 *)CONCAT11(uVar7,uVar8);
    menu_cb_enter = 0xf2;
    menu_cb_enter_hi = 0x1b;
    menu_cb_up = 0xf2;
    menu_cb_up_hi = 0x1b;
    menu_cb_down = 0xf2;
    menu_set_cbs_down_hi(0x1b);
  }
  *puVar6 = *puVar6;
  puVar6[-1] = puVar6[-1];
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x000c32 menu_install_boiling_temp =====

/* Menu/screen handler (callback analysis) */

void menu_install_boiling_temp(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_C;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  puVar1 = &FramePointer10x0001;
  ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992();
  menu_value_max_lo = 100;
  menu_value_max_hi = 0;
  ui_param_tboil_28e2(0x58);
  bVar3 = (byte)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    bVar3 = (byte)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  ui_to_ui_get_menu_value_step_lo_290e();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar3 << 8) = *(undefined1 *)((ushort)bVar3 << 8);
  }
  ui_to_menu_set_cbs_down_hi_2826();
  return;
}


// ===== 0x000c62 menu_service_boiling_temp =====

/* Menu/screen handler (callback analysis) */

void menu_service_boiling_temp(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_C;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  puVar1 = &FramePointer10x0001;
  ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992();
  ui_to_param_read_max_2360(0x15);
  ui_to_param_read_min_2b7a(0x15);
  ui_param_tboil_28e2();
  bVar3 = (byte)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    bVar3 = (byte)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  ui_to_ui_get_menu_value_step_lo_290e();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar3 << 8) = *(undefined1 *)((ushort)bVar3 << 8);
  }
  ui_to_menu_set_cbs_down_hi_2826();
  return;
}


// ===== 0x000c94 menu_install_boiling_temp_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_install_boiling_temp_on_enter(void)

{
  ui_to_menu_default_back_279e(0x15);
  return;
}


// ===== 0x000c9e menu_install_boiling_temp_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_install_boiling_temp_on_up(void)

{
  menu_mix_water_temp_on_up();
  ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae();
  return;
}


// ===== 0x000ca6 menu_install_boiling_temp_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_install_boiling_temp_on_down(void)

{
  menu_mix_water_temp_on_down();
  ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae();
  return;
}


// ===== 0x000cae ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae =====

/* Auto: Push constant arguments [1, 70, 3] then call ui_to_ui_draw_temp_value; 13 instr */

undefined1 ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte unaff_C;
  
  puVar1 = &FramePointer10x0001;
  ui_get_menu_value_lo_2ace();
  bVar2 = (byte)((ushort)(puVar1 + 1) >> 8);
  *puVar1 = 0x46;
  ui_to_ui_draw_temp_value_2356(3);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
  }
  return c18_tmp0;
}


// ===== 0x000ccc menu_cold_water_qty =====

/* Menu/screen handler (callback analysis) */

void menu_cold_water_qty(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(0x3e);
  ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(0x3e);
  ui_to_screen_mix_temp_bar_2bce(0x3e);
  menu_cb_enter = 0xee;
  menu_set_cbs_enter_hi_d(0xc);
  return;
}


// ===== 0x000cee menu_cold_water_qty_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_cold_water_qty_on_enter(void)

{
  ui_get_math_aarg_lo_295a();
  ui_to_menu_default_back_279e(0x3e);
  return;
}


// ===== 0x000cf8 ui_to_menu_set_cbs_enter_hi_d_0cf8 =====

/* Auto: writes menu_cb_enter; calls menu_set_cbs_enter_hi_d; 11 instr */

void ui_to_menu_set_cbs_enter_hi_d_0cf8(void)

{
  byte unaff_BSR;
  
  ui_to_param_read_max_2360(0x34);
  ui_set_menu_value_step_lo_27d2(0x34);
  ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992();
  ui_to_screen_mix_temp_bar_2bce(0x34);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x18;
  menu_set_cbs_enter_hi_d(0xd);
  return;
}


// ===== 0x000d18 ui_to_ui_get_math_aarg_lo_0d18 =====

/* Auto: Small wrapper around ui_get_math_aarg_lo; 3 instr */

void ui_to_ui_get_math_aarg_lo_0d18(void)

{
  ui_get_math_aarg_lo_295a();
  ui_to_menu_default_back_279e(0x34);
  return;
}


// ===== 0x000d22 menu_mix_water_qty =====

/* Menu/screen handler (callback analysis) */

void menu_mix_water_qty(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(0x35);
  ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(0x35);
  ui_to_ui_get_menu_value_hi_2952(0x35);
  screen_qty_bar();
  ui_to_ui_to_ui_draw_temp_units_1df4();
  menu_cb_enter = 0x4e;
  menu_set_cbs_enter_hi_d(0xd);
  return;
}


// ===== 0x000d4e menu_mix_water_qty_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_mix_water_qty_on_enter(void)

{
  ui_get_math_aarg_lo_295a();
  ui_to_menu_default_back_279e(0x35);
  return;
}


// ===== 0x000d58 menu_hot_water_qty =====

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty(void)

{
  if ((cfg_systemconfig5 & 0x10) != 0) {
    ui_to_param_read_max_2360(0x42);
    ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(0x42);
    ui_to_ui_get_menu_value_hi_2952(0x42);
    if ((cfg_systemconfig5 & 4) == 0) {
      menu_value_lo = 0;
      menu_value_hi = 0;
    }
    screen_qty_bar();
    ui_to_ui_to_ui_draw_temp_units_1df4();
    menu_cb_enter = 0xa0;
    menu_cb_enter_hi = 0xd;
    menu_cb_up = 0xe8;
    menu_cb_up_hi = 0x1d;
    menu_cb_down = 0xee;
    menu_set_cbs_down_hi(0x1d);
    return;
  }
  return;
}


// ===== 0x000da0 menu_hot_water_qty_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty_on_enter(void)

{
  byte unaff_Z;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) != 0) {
    ui_get_menu_value_step_lo_25c2();
  }
  ui_get_math_aarg_lo_295a();
  ui_to_param_write_215a(0x42);
  ui_get_cfg_systemconfig5_2c02();
  return;
}


// ===== 0x000db8 menu_replacement =====

/* Menu/screen handler (callback analysis) */

void menu_replacement(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  menu_edit_mode = 1;
  screen_replacement_counter();
  menu_cb_back = 0xf2;
  menu_cb_back_hi = 0x1b;
  if ((cfg_systemconfig & 8) == 0) {
    menu_cb_up = 4;
    menu_cb_up_hi = 0xe;
    menu_cb_down = 4;
    menu_cb_down_hi = 0xe;
  }
  else {
    menu_cb_down_hi = menu_set_cbs_updown_default();
  }
  return;
}


// ===== 0x000df2 menu_replacement_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_replacement_on_up(void)

{
  menu_edit_mode = menu_edit_mode == '\0';
  menu_replacement_on_up_b();
  return;
}


// ===== 0x000e04 menu_replacement_on_up_b =====

/* Menu/screen handler (callback analysis) */

byte menu_replacement_on_up_b(void)

{
  bool bVar1;
  bool bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  byte bVar9;
  bool bVar10;
  
  ui_callw_fn0450_2b5e(0x1e);
  text_row = 2;
  *(undefined1 *)in_FSR1 = 6;
  puVar3 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  ui_stack_adjust_21f4(0x74);
  ui_set_ui_wake_pending_244a(4);
  if (menu_edit_mode == '\0') {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80;
  }
  ui_to_ui_get_c18_tmp0_22cc(uVar7);
  ui_stack_adjust_21f4(0x4d);
  text_row = 4;
  ui_get_TBLPTRH_2606(0xfc);
  if ((c18_tmp5 & 0x80) != 0) {
    c18_tmp6 = 0xff;
    c18_tmp7 = 0xff;
  }
  c18_tmp0 = c18_tmp4 - stat_GFI;
  bVar9 = ~(stat_GFI <= c18_tmp4);
  bVar10 = c18_tmp5 < bVar9 || bDATA00eb < c18_tmp5 - bVar9;
  c18_tmp1 = (c18_tmp5 - bDATA00eb) - ~(stat_GFI <= c18_tmp4);
  bVar9 = ~bVar10;
  bVar1 = bVar9 <= c18_tmp6;
  bVar2 = c18_tmp6 - bVar9 <= bDATA00ec;
  c18_tmp2 = (c18_tmp6 - bDATA00ec) - ~bVar10;
  bVar10 = cDATA00ed == '\0';
  ui_get_menu_edit_mode_2652(cDATA00ed);
  if (bVar10) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80;
  }
  uVar8 = ui_to_txt_set_ui_hold_counter_2594(uVar7);
  uVar7 = (undefined1)((ushort)puVar3 >> 8);
  if (bVar1 && bVar2) {
    puVar4 = (undefined1 *)((ushort)puVar3 & 0xff00);
    uVar7 = (undefined1)((ushort)(puVar4 + -1) >> 8);
    *puVar4 = *puVar4;
  }
  puVar5 = (undefined1 *)CONCAT11(uVar7,uVar8);
  if ((cfg_systemconfig & 8) != 0) {
    ui_set_ui_wake_pending_244a(5);
    if (menu_edit_mode == '\0') {
      uVar7 = 0x80;
    }
    else {
      uVar7 = 0;
    }
    ui_to_ui_get_c18_tmp0_22cc(uVar7);
    ui_stack_adjust_21f4(0x4e);
    text_row = 5;
    ui_get_TBLPTRH_2606(0xfc);
    if ((c18_tmp5 & 0x80) != 0) {
      c18_tmp6 = 0xff;
      c18_tmp7 = 0xff;
    }
    c18_tmp0 = c18_tmp4 - stat_GUV;
    bVar9 = ~(stat_GUV <= c18_tmp4);
    bVar10 = c18_tmp5 < bVar9 || bDATA00e7 < c18_tmp5 - bVar9;
    c18_tmp1 = (c18_tmp5 - bDATA00e7) - ~(stat_GUV <= c18_tmp4);
    bVar9 = ~bVar10;
    bVar1 = bVar9 <= c18_tmp6;
    bVar2 = c18_tmp6 - bVar9 <= bDATA00e8;
    c18_tmp2 = (c18_tmp6 - bDATA00e8) - ~bVar10;
    bVar10 = cDATA00e9 == '\0';
    ui_get_menu_edit_mode_2652(cDATA00e9);
    if (bVar10) {
      uVar7 = 0x80;
    }
    else {
      uVar7 = 0;
    }
    uVar8 = ui_to_txt_set_ui_hold_counter_2594(uVar7);
    uVar7 = (undefined1)((ushort)puVar5 >> 8);
    if (bVar1 && bVar2) {
      puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
      uVar7 = (undefined1)((ushort)(puVar6 + -1) >> 8);
      *puVar6 = *puVar6;
    }
    puVar5 = (undefined1 *)CONCAT11(uVar7,uVar8);
  }
  if (((menu_edit_mode != '\0') && ((cfg_systemconfig4 & 4) == 0)) ||
     ((bVar9 = 0, menu_edit_mode != '\0' && (bVar9 = cfg_systemconfig4 & 0x20, bVar9 == 0)))) {
    text_row = 6;
    *puVar5 = 6;
    puVar5[1] = 0;
    bVar9 = ui_stack_adjust_21f4(0x67);
  }
  return bVar9;
}


// ===== 0x000f1c screen_replacement_counter_confirm =====

/* Menu/screen handler (callback analysis) */

void screen_replacement_counter_confirm(void)

{
  if (menu_edit_mode != '\0') {
    ui_set_stat_GUV_22fa(menu_edit_mode);
  }
  menu_edit_mode = 0;
  ui_to_screen_replacement_counter_246a();
  return;
}


// ===== 0x000f2e screen_replacement_counter_confirm_b =====

/* Menu/screen handler (callback analysis) */

void screen_replacement_counter_confirm_b(void)

{
  if (menu_edit_mode != '\0') {
    ui_set_stat_GFI_247a(menu_edit_mode);
  }
  menu_edit_mode = 1;
  ui_to_screen_replacement_counter_246a();
  return;
}


// ===== 0x000f42 screen_replacement_counter_on_enter =====

/* Menu/screen handler (callback analysis) */

byte screen_replacement_counter_on_enter(void)

{
  byte bVar1;
  
  if (menu_edit_mode != 0) {
    if ((cfg_systemconfig4 & 4) == 0) {
      ui_stack_adjust_26e2(0x4d);
      ui_to_text_draw_word_2996(0x4f);
      ui_set_menu_edit_mode_2498();
      menu_cb_enter = 0x2e;
      menu_set_cbs_enter_hi_c(0xf);
    }
  }
  bVar1 = menu_edit_mode;
  if (menu_edit_mode == 0) {
    bVar1 = cfg_systemconfig4 & 0x20;
    if (bVar1 == 0) {
      ui_stack_adjust_26e2(0x4e);
      ui_to_text_draw_word_2996(0x50);
      ui_set_menu_edit_mode_2498();
      menu_cb_enter = 0x1c;
      bVar1 = menu_set_cbs_enter_hi_c(0xf);
    }
  }
  return bVar1;
}


// ===== 0x000f94 menu_enter =====

/* WARNING: Removing unreachable block (CODE,0x00102c) */
/* WARNING: Removing unreachable block (CODE,0x001022) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Open the menu (table at ROM 0xE49E) and call its enter callback */

undefined1 menu_enter(void)

{
  byte bVar1;
  undefined3 in_TBLPTR;
  undefined1 uVar3;
  undefined1 *puVar2;
  
  uVar3 = (undefined1)((uint3)in_TBLPTR >> 0x10);
  if ((menu_cb_enter_hi | menu_cb_enter) == 0) {
    if ((menu_table_ptr_hi | menu_table_ptr_lo) != 0) {
      ui_get_menu_table_ptr_lo_2b3c(menu_table_ptr_hi | menu_table_ptr_lo);
      ui_get_c18_tmp2_2398(0x18);
      ui_get_menu_item_2296();
      c18_tmp2 = menu_table_ptr_lo + 0x18;
      c18_tmp3 = menu_table_ptr_hi + (0xe7 < menu_table_ptr_lo);
      bVar1 = (byte)((ushort)menu_item * 2);
      puVar2 = (undefined1 *)
               CONCAT12(uVar3,CONCAT11((char)((ushort)menu_item * 2 >> 8) + c18_tmp3 +
                                       CARRY1(bVar1,c18_tmp2),bVar1 + c18_tmp2));
      c18_tmp0 = *puVar2;
      c18_tmp1 = puVar2[1];
      ui_set_menu_item_1016();
      return 1;
    }
    menu_table_ptr_lo = 0x9e;
    menu_table_ptr_hi = 0xe4;
    menu_item = 0;
    menu_draw();
    return 0;
  }
  menu_call_enter_cb(menu_cb_enter_hi | menu_cb_enter);
  if ((menu_table_ptr_hi == 0 && menu_table_ptr_lo == 0) && (menu_mode == '\0')) {
    return 0x80;
  }
  return 1;
}


// ===== 0x000f9e menu_call_enter_cb =====

/* Call menu enter callback (menu_cb_enter) */

undefined1 menu_call_enter_cb(void)

{
  menu_call_enter_cb(menu_cb_enter);
  if ((menu_table_ptr_hi == '\0' && menu_table_ptr_lo == '\0') && (menu_mode == '\0')) {
    return 0x80;
  }
  return 1;
}


// ===== 0x001016 ui_set_menu_item_1016 =====

/* Auto: writes menu_item; reads c18_tmp1,PCLATH; calls computed_jump,menu_draw; 13 instr */

undefined1 ui_set_menu_item_1016(void)

{
  ui_set_menu_item_1016(c18_tmp0);
  return 1;
}


// ===== 0x001038 menu_key_back =====

/* Back key (0x40) in menus: call menu_cb_back */

undefined1 menu_key_back(void)

{
  if ((menu_cb_back_hi | menu_cb_back) != 0) {
    menu_call_back_cb(menu_cb_back_hi | menu_cb_back);
    return 1;
  }
  if ((menu_table_ptr_hi | menu_table_ptr_lo) != 0) {
    ui_get_menu_item_2270(menu_table_ptr_hi | menu_table_ptr_lo);
    if (menu_table_ptr_hi != 0 || menu_table_ptr_lo != 0) {
      menu_draw();
      return 1;
    }
    lcd_clear(0);
    return 0;
  }
  return 0x80;
}


// ===== 0x001042 menu_call_back_cb =====

/* Call menu_cb_back */

undefined1 menu_call_back_cb(void)

{
  menu_call_back_cb(menu_cb_back);
  return 1;
}


// ===== 0x00106e menu_key_up =====

/* Up key (0x01) in menus: call menu_cb_up */

undefined1 menu_key_up(void)

{
  char cVar1;
  
  if ((menu_cb_up_hi | menu_cb_up) != 0) {
    menu_call_up_cb(menu_cb_up_hi | menu_cb_up);
    return 1;
  }
  if (menu_item == '\0') {
    cVar1 = menu_item_count + -1;
    menu_item = menu_item_count + -1;
  }
  else {
    cVar1 = menu_item;
    menu_item = menu_item + -1;
  }
  menu_draw(cVar1);
  return 0;
}


// ===== 0x001078 menu_call_up_cb =====

/* Call menu_cb_up (default: previous item) */

undefined1 menu_call_up_cb(void)

{
  menu_call_up_cb(menu_cb_up);
  return 1;
}


// ===== 0x001096 menu_key_down =====

/* Down key (0x10) in menus: call menu_cb_down */

undefined1 menu_key_down(void)

{
  char cVar1;
  
  if ((menu_cb_down_hi | menu_cb_down) != 0) {
    menu_call_down_cb(menu_cb_down_hi | menu_cb_down);
    return 1;
  }
  menu_item = menu_item + 1;
  cVar1 = menu_item - menu_item_count;
  if (menu_item_count <= menu_item) {
    menu_item = 0;
  }
  menu_draw(cVar1);
  return 0;
}


// ===== 0x0010a0 menu_call_down_cb =====

/* Call menu_cb_down (default: next item) */

undefined1 menu_call_down_cb(void)

{
  menu_call_down_cb(menu_cb_down);
  return 1;
}


// ===== 0x0010bc menu_key_other =====

/* Other keys in menus: call menu_cb_key */

undefined1 menu_key_other(void)

{
  if ((menu_cb_key_hi | menu_cb_key) != 0) {
    menu_call_key_cb(menu_cb_key_hi | menu_cb_key);
  }
  return 0;
}


// ===== 0x0010c6 menu_call_key_cb =====

/* Call menu_cb_key */

undefined1 menu_call_key_cb(void)

{
  menu_call_key_cb(menu_cb_key);
  return 0;
}


// ===== 0x0010d4 ui_bank1_ui_to_lcd_clear_10d4 =====

/* Auto: Select bank then jump to ui_to_lcd_clear; 3 instr */

undefined1 ui_bank1_ui_to_lcd_clear_10d4(void)

{
  ui_to_lcd_clear_21fc();
  return 0;
}


// ===== 0x0010dc menu_timer_tick =====

/* Count down menu timer; on expiry call menu_cb_timeout */

undefined1 menu_timer_tick(void)

{
  undefined1 uVar1;
  bool bVar2;
  
  if ((menu_timer_hi != '\0' || menu_timer_lo != '\0') && (menu_timer_enabled != '\0')) {
    if ((menu_cb_timeout_hi | menu_cb_timeout) != 0) {
      menu_call_timeout_cb(menu_cb_timeout_hi | menu_cb_timeout);
    }
    bVar2 = menu_timer_lo != '\0';
    menu_timer_lo = menu_timer_lo + -1;
    menu_timer_hi = menu_timer_hi - ~bVar2;
    return 0;
  }
  uVar1 = 0;
  if ((menu_cb_aux_hi | menu_cb_aux) != 0) {
    uVar1 = menu_call_aux_cb(menu_cb_aux_hi | menu_cb_aux);
  }
  return uVar1;
}


// ===== 0x0010f0 menu_call_timeout_cb =====

/* Call menu_cb_timeout */

undefined1 menu_call_timeout_cb(void)

{
  bool bVar1;
  
  menu_call_timeout_cb(menu_cb_timeout);
  bVar1 = menu_timer_lo != '\0';
  menu_timer_lo = menu_timer_lo + -1;
  menu_timer_hi = menu_timer_hi - ~bVar1;
  return 0;
}


// ===== 0x00110e menu_call_aux_cb =====

/* Call menu_cb_aux */

void menu_call_aux_cb(void)

{
  menu_call_aux_cb(menu_cb_aux);
  return;
}


// ===== 0x00111c ui_bank1_ui_set_menu_timer_lo_111c =====

/* Auto: Select bank then jump to ui_set_menu_timer_lo; 2 instr */

void ui_bank1_ui_set_menu_timer_lo_111c(void)

{
  ui_set_menu_timer_lo_251e();
  return;
}


// ===== 0x001122 ui_get_menu_mode_1122 =====

/* Auto: reads menu_mode; 3 instr */

undefined1 ui_get_menu_mode_1122(void)

{
  return menu_mode;
}


// ===== 0x001128 screen_uv_lamp_removed =====

/* "UV LAMP IS REMOVED / INSERT UV LAMP" */

void screen_uv_lamp_removed(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 3;
  ui_word_uv_lamp_26ae();
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word(0x79);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}


// ===== 0x001140 screen_uv_lamp_new_old =====

/* Ask NEW/OLD UV LAMP after refit (new resets GUV counter) */

void screen_uv_lamp_new_old(void)

{
  menu_mode = 4;
  if ((cfg_systemconfig4 & 1) == 0) {
    ui_word_uv_lamp_26ae();
    ui_to_ui_get_cfg_systemconfig2_2c1c();
    ui_set_text_a(0x51);
    ui_set_text_b(0x52);
    ui_set_menu_edit_mode_2498();
    menu_cb_enter = 0x78;
    menu_set_cbs_enter_hi_b(0x11);
    return;
  }
  menu_edit_mode = 0;
  ui_set_menu_mode_1178();
  ui_to_ui_select_home_screen_4af0();
  return;
}


// ===== 0x001178 ui_set_menu_mode_1178 =====

/* Auto: writes menu_mode; reads menu_edit_mode; 10 instr */

void ui_set_menu_mode_1178(void)

{
  if (menu_edit_mode != '\0') {
    ui_set_stat_GUV_22fa(menu_edit_mode);
  }
  ui_to_lcd_clear_21fc();
  ui_to_ui_select_home_screen_4af0();
  menu_mode = 0;
  return;
}


// ===== 0x001192 screen_filter_removed =====

/* "FILTER IS REMOVED / INSERT FILTER" */

void screen_filter_removed(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 1;
  ui_word_filter_233c();
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word(0x7a);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}


// ===== 0x0011aa screen_filter_new_old =====

/* Ask NEW/OLD FILTER after refit (new resets GFI counter) */

void screen_filter_new_old(void)

{
  menu_mode = 2;
  if ((cfg_systemconfig4 & 1) == 0) {
    ui_word_filter_233c();
    ui_to_ui_get_cfg_systemconfig2_2c1c();
    ui_set_text_a(0x53);
    ui_set_text_b(0x54);
    ui_set_menu_edit_mode_2498();
    menu_cb_enter = 0xe2;
    menu_set_cbs_enter_hi_b(0x11);
    return;
  }
  menu_edit_mode = 0;
  fn_11e2_on_back_on_enter();
  ui_to_ui_select_home_screen_4af0();
  return;
}


// ===== 0x0011e2 fn_11e2_on_back_on_enter =====

/* Menu/screen handler (callback analysis) */

void fn_11e2_on_back_on_enter(void)

{
  if (menu_edit_mode != '\0') {
    ui_word_filter_233c();
    ui_word_put_2_liter_jug_x0aunder_the_2a72();
    menu_cb_enter = 10;
    menu_cb_enter_hi = 0x12;
    menu_cb_back = 0xaa;
    menu_set_cbs_back_hi(0x11);
    return;
  }
  ui_set_menu_mode_2a06(0);
  return;
}


// ===== 0x00120a fn_11e2_on_enter =====

/* Menu/screen handler (callback analysis) */

void fn_11e2_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_set_stat_GFI_247a();
  ui_word_filter_233c();
  ui_set_text_row_2b08();
  *(undefined1 *)in_FSR1 = 6;
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  ui_stack_adjust_21f4(0x6a);
  menu_cb_enter = 0x2e;
  menu_set_cbs_enter_hi_e(0x12);
  return;
}


// ===== 0x00122e screen_flushing =====

/* Flushing: open cold valve for flush time computed from WATERFLOW */

void screen_flushing(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_draw_flushing();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x26;
  eeprom_read_param();
  *puVar1 = *puVar1;
  ui_set_menu_value_lo_2bae();
  math_aarg_lo = 0xb0;
  math_aarg_hi = 4;
  math_barg_lo = menu_value_lo;
  math_barg_hi = menu_value_hi;
  ui_to___divs16_289c();
  menu_timer_lo = math_aarg_lo;
  menu_timer_hi = math_aarg_hi;
  menu_timer_reload_lo = math_aarg_lo;
  menu_timer_reload_hi = math_aarg_hi;
  dispense_cold_request();
  ui_push_args_14_04_mod_to_ui_draw_progress_segment_265e();
  menu_cb_aux = 0xd0;
  menu_cb_aux_hi = 0x12;
  ui_set_menu_cb_timeout_2402();
  return;
}


// ===== 0x00127a screen_fill_tanks_on_timeout =====

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_on_timeout(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 in_PRODL;
  
  ui_stack_adjust_2af8();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  c18_tmp0 = menu_timer_lo;
  c18_tmp1 = menu_timer_hi;
  uVar1 = in_PRODL;
  ui_get_c18_tmp1_2632(100);
  math_aarg_lo = uVar1;
  math_aarg_hi = c18_tmp1;
  math_barg_lo = menu_timer_reload_lo;
  math_barg_hi = menu_timer_reload_hi;
  __divu16();
  *(undefined1 *)in_FSR2 = math_aarg_lo;
  *(undefined1 *)((short)in_FSR2 + 1) = math_aarg_hi;
  c18_tmp0 = 'f' - *(char *)in_FSR2;
  c18_tmp1 = '\x02' - *(char *)((short)in_FSR2 + 1);
  ui_get_c18_tmp0_29a2();
  ui_draw_progress_popup();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar2[-2];
  puVar2[-3] = puVar2[-3];
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x0012d0 screen_fill_tanks_on_aux =====

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_on_aux(void)

{
  menu_cb_timeout = 0;
  menu_cb_timeout_hi = 0;
  menu_cb_aux = 0xf8;
  menu_cb_aux_hi = 0x12;
  menu_timer_lo = 3;
  menu_timer_hi = 0;
  dispense_stop_all();
  ui_word_filter_233c();
  ui_draw_done(4);
  ui_to_menu_set_cbs_noop_b_2a7e();
  return;
}


// ===== 0x0012f8 screen_fill_tanks_on_aux_on_aux =====

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_on_aux_on_aux(void)

{
  menu_cb_aux = 0;
  menu_cb_aux_hi = 0;
  ui_bank1_ui_set_menu_mode_1356();
  ui_to_ui_select_home_screen_4af0();
  return;
}


// ===== 0x001304 screen_fill_tanks_on_enter =====

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_cb_timeout = 0;
  menu_cb_timeout_hi = 0;
  ui_word_filter_233c();
  *(undefined1 *)in_FSR1 = 2;
  ui_to_text_draw_word_2996(0x57);
  menu_edit_mode = 1;
  screen_temp_sensor_values();
  menu_cb_enter = 0x34;
  menu_set_cbs_enter_hi_b(0x13);
  menu_cb_key = 0;
  menu_cb_key_hi = 0;
  return;
}


// ===== 0x001334 screen_fill_tanks_confirm2 =====

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_confirm2(void)

{
  if (menu_edit_mode != '\0') {
    ui_draw_flushing();
    ui_push_args_14_04_mod_to_ui_draw_progress_segment_265e();
    ui_set_menu_cb_timeout_2402();
    return;
  }
  ui_set_menu_timer_lo_251e(0);
  dispense_stop_all();
  ui_bank1_ui_set_menu_mode_1356();
  ui_to_ui_select_home_screen_4af0();
  return;
}


// ===== 0x001356 ui_bank1_ui_set_menu_mode_1356 =====

/* Auto: Select bank then jump to ui_set_menu_mode; 2 instr */

void ui_bank1_ui_set_menu_mode_1356(void)

{
  ui_set_menu_mode_2a06();
  return;
}


// ===== 0x00135c screen_drop_collector_removed =====

/* "DROP COLLECTOR IS REMOVED / PLEASE REPLACE IT" */

void screen_drop_collector_removed(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 6;
  lcd_clear();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word(0x78);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}


// ===== 0x001374 ui_bank1_ui_set_menu_mode_1374 =====

/* Auto: Select bank then jump to ui_set_menu_mode; 2 instr */

void ui_bank1_ui_set_menu_mode_1374(void)

{
  ui_set_menu_mode_2a06();
  return;
}


// ===== 0x00137a screen_drop_collector_full =====

/* "DROP COLLECTOR IS FULL / PLEASE EMPTY IT" */

void screen_drop_collector_full(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 5;
  lcd_clear();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word(0x7b);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}


// ===== 0x001392 screen_exit_power_down =====

/* "EXIT POWERDOWN MODE?" */

void screen_exit_power_down(void)

{
  ui_draw_power_down();
  ui_draw_word(0x58);
  text_row = 6;
  ui_stack_adjust_2bdc();
  DAT_DATA_0e34 = 0xce;
  menu_set_cbs_enter_hi_e(0x13);
  return;
}


// ===== 0x0013b0 screen_flush_recommended =====

/* "FLUSH SYSTEM RECOMMENDED" */

void screen_flush_recommended(void)

{
  byte unaff_BSR;
  
  ui_set_menu_timer_lo_2ade();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x40) = 0xce;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x41) = 0x13;
  menu_set_cbs_noop_b();
  ui_draw_power_down();
  ui_draw_word(0x7c);
  return;
}


// ===== 0x0013ce fn_13b0_on_aux =====

/* Menu/screen handler (callback analysis) */

void fn_13b0_on_aux(void)

{
  ui_set_menu_timer_lo_251e();
  ui_to_system_wake_2a58();
  return;
}


// ===== 0x0013d8 ui_to_menu_draw_13d8 =====

/* Auto: writes menu_table_ptr_lo,menu_table_ptr_hi; calls menu_draw; 7 instr */

void ui_to_menu_draw_13d8(void)

{
  menu_table_ptr_lo = 0x1a;
  menu_table_ptr_hi = 0xe6;
  menu_draw();
  ui_bank1_ui_set_menu_cb_up_2454();
  return;
}


// ===== 0x0013e8 menu_service_temp_sensor =====

/* Menu/screen handler (callback analysis) */

void menu_service_temp_sensor(void)

{
  BADSPACEBASE *in_FSR1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_lcd_clear_2ae8(cfg_systemconfig3 & 1);
  *(undefined1 *)in_FSR1 = 0x35;
  ui_draw_title();
  ui_draw_yes_no();
  screen_temp_sensor_values();
  menu_cb_enter = 0x10;
  menu_set_cbs_back_default(0x14);
  return;
}


// ===== 0x001410 menu_service_temp_sensor_on_enter =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_service_temp_sensor_on_enter(void)

{
  if (menu_edit_mode != (cfg_systemconfig3 & 1)) {
    cfg_systemconfig3 = cfg_systemconfig3 & 0xfe;
    if ((menu_edit_mode & 1) != 0) {
      cfg_systemconfig3 = cfg_systemconfig3 | 1;
    }
    ui_to_param_write_215a(0x2c);
    screen_service_resetting();
    return;
  }
  menu_default_back(0);
  return;
}


// ===== 0x001438 ui_to_menu_set_cbs_back_default_1438 =====

/* Auto: writes menu_cb_enter; reads cfg_systemconfig4; calls menu_set_cbs_back_default; 13 instr */

void ui_to_menu_set_cbs_back_default_1438(void)

{
  ui_to_lcd_clear_2ae8((cfg_systemconfig4 & 0x40) != 0x40);
  ui_to_ui_draw_title_22dc(0x20);
  menu_cb_enter = 0x58;
  menu_set_cbs_back_default(0x14);
  return;
}


// ===== 0x001458 ui_to_screen_service_resetting_1458 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes cfg_systemconfig4; reads cfg_systemconfig4,menu_edit_mode; calls
   screen_service_resetting,menu_default_back; 22 instr */

void ui_to_screen_service_resetting_1458(void)

{
  char cVar1;
  
  cVar1 = menu_edit_mode - ((cfg_systemconfig4 & 0x40) != 0);
  if (cVar1 == '\0') {
    cfg_systemconfig4 = cfg_systemconfig4 & 0xbf;
    if (menu_edit_mode == '\0') {
      cfg_systemconfig4 = cfg_systemconfig4 | 0x40;
    }
    ui_to_param_write_215a(0x3a);
    screen_service_resetting();
    return;
  }
  menu_default_back(cVar1);
  return;
}


// ===== 0x00148c ui_to_menu_set_cbs_back_default_148c =====

/* Auto: writes menu_cb_enter; reads cfg_systemconfig5; calls menu_set_cbs_back_default; 10 instr */

void ui_to_menu_set_cbs_back_default_148c(void)

{
  ui_to_lcd_clear_2ae8(cfg_systemconfig5 & 1);
  ui_to_ui_draw_title_22dc(0x5a);
  menu_cb_enter = 0xa6;
  menu_set_cbs_back_default(0x14);
  return;
}


// ===== 0x0014a6 ui_to_screen_service_resetting_14a6 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes cfg_systemconfig5; reads cfg_systemconfig5,menu_edit_mode; calls
   screen_service_resetting,menu_default_back; 16 instr */

void ui_to_screen_service_resetting_14a6(void)

{
  if (menu_edit_mode != (cfg_systemconfig5 & 1)) {
    cfg_systemconfig5 = cfg_systemconfig5 & 0xfe;
    if ((menu_edit_mode & 1) != 0) {
      cfg_systemconfig5 = cfg_systemconfig5 | 1;
    }
    ui_to_param_write_215a(0x41);
    screen_service_resetting();
    return;
  }
  menu_default_back(0);
  return;
}


// ===== 0x0014ce fn_2220_on_aux =====

/* Menu/screen handler (callback analysis) */

void fn_2220_on_aux(void)

{
  reset();
  return;
}


// ===== 0x0014d2 ui_to_screen_language_select_14d2 =====

/* Auto: calls screen_language_select; 1 instr */

void ui_to_screen_language_select_14d2(void)

{
  char cVar1;
  
  menu_edit_mode = ui_get_cfg_systemconfig2_2b2e();
  ui_word_installation_2370();
  menu_table_ptr_lo = 0xce;
  menu_table_ptr_hi = 0xe5;
  menu_item = 0;
  while( true ) {
    cVar1 = menu_item - 8;
    if (7 < menu_item) break;
    ui_get_menu_item_24ba(cVar1);
    ui_get_c18_tmp0_25e8();
    if (cVar1 == '\0') break;
    menu_item = menu_item + 1;
  }
  cVar1 = menu_item - 8;
  if (7 < menu_item) {
    menu_item = 0;
  }
  menu_draw(cVar1);
  menu_cb_enter = 0x24;
  menu_cb_enter_hi = 0x15;
  menu_cb_back = 0x98;
  menu_clear_cbs(0);
  return;
}


// ===== 0x0014d6 screen_language_select =====

/* Language list (menu 0xE5CE) */

void screen_language_select(void)

{
  char cVar1;
  
  menu_edit_mode = ui_get_cfg_systemconfig2_2b2e();
  ui_word_installation_2370();
  menu_table_ptr_lo = 0xce;
  menu_table_ptr_hi = 0xe5;
  menu_item = 0;
  while( true ) {
    cVar1 = menu_item - 8;
    if (7 < menu_item) break;
    ui_get_menu_item_24ba(cVar1);
    ui_get_c18_tmp0_25e8();
    if (cVar1 == '\0') break;
    menu_item = menu_item + 1;
  }
  cVar1 = menu_item - 8;
  if (7 < menu_item) {
    menu_item = 0;
  }
  menu_draw(cVar1);
  menu_cb_enter = 0x24;
  menu_cb_enter_hi = 0x15;
  menu_cb_back = 0x98;
  menu_clear_cbs(0);
  return;
}


// ===== 0x001524 screen_language_select_on_enter =====

/* Menu/screen handler (callback analysis) */

void screen_language_select_on_enter(void)

{
  byte unaff_BSR;
  
  ui_set_cfg_systemconfig2_285a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x25) = 0x82;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x26) = 0xe5;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x27) = 0;
  menu_draw();
  ui_bank1_ui_set_menu_cb_up_2454();
  return;
}


// ===== 0x001538 menu_install_fill_tanks =====

/* Menu/screen handler (callback analysis) */

void menu_install_fill_tanks(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_word_installation_2370();
  ui_word_put_2_liter_jug_x0aunder_the_2a72();
  menu_cb_enter = 0xc2;
  menu_set_cbs_enter_hi_e(0x16);
  return;
}


// ===== 0x001550 ui_word_fill_cold_water_tank_1550 =====

/* Auto: shows "FILL COLD WATER TANK"; writes menu_cb_aux,menu_cb_aux_hi; reads
   menu_cb_enter,menu_cb_enter_hi; calls ui_draw_press_ok_when_ready,menu_set_cbs_noop; 19 instr */

void ui_word_fill_cold_water_tank_1550(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  byte unaff_Z;
  
  ui_to_ui_word_installation_2a96();
  if ((unaff_Z & 1) == 0) {
    *(undefined1 *)in_FSR1 = 2;
    uVar1 = 0x5b;
  }
  else {
    *(undefined1 *)in_FSR1 = 2;
    uVar1 = 0x5c;
  }
  ui_draw_press_ok_when_ready(uVar1);
  menu_cb_aux = 0;
  menu_cb_aux_hi = 0;
  menu_cb_enter = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_enter_hi = *(undefined1 *)((short)in_FSR2 + -2);
  menu_set_cbs_noop();
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x001582 screen_tank_filling =====

/* "HOT/COLD TANK IS FILLING UP" screen with timer */

undefined1 screen_tank_filling(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  
  ui_c18_prologue_2166();
  menu_timer_enabled = 1;
  ui_word_installation_2370();
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    *(undefined1 *)in_FSR1 = 2;
    uVar5 = 0x5e;
  }
  else {
    *(undefined1 *)in_FSR1 = 2;
    uVar5 = 0x5d;
  }
  puVar3 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = uVar5;
  text_draw_word();
  *puVar3 = *puVar3;
  puVar3[-1] = puVar3[-1];
  puVar3[-2] = 6;
  puVar3[-1] = 0x56;
  text_draw_word();
  *puVar3 = *puVar3;
  puVar3[-1] = puVar3[-1];
  puVar3[-2] = 0x14;
  puVar3[-1] = 4;
  mod_to_ui_draw_progress_segment_e2ba();
  *puVar3 = *puVar3;
  puVar4 = puVar3 + -2;
  puVar3[-1] = puVar3[-1];
  c18_tmp0 = puVar1[-4];
  puVar2 = puVar1 + 2;
  c18_tmp1 = puVar1[-2];
  menu_install_cbs_from_args();
  menu_cb_aux = puVar2[-6];
  menu_cb_aux_hi = puVar2[-4];
  menu_cb_timeout = 0x7a;
  menu_cb_timeout_hi = 0x12;
  menu_cb_enter = puVar2[-6];
  menu_cb_enter_hi = puVar2[-4];
  menu_cb_back = puVar2[-4];
  menu_cb_back_hi = puVar2[-2];
  menu_cb_up = puVar2[-2];
  menu_cb_up_hi = *puVar2;
  menu_cb_down = *puVar2;
  menu_cb_down_hi = puVar2[2];
  menu_cb_key = puVar2[2];
  menu_cb_key_hi = puVar2[4];
  *puVar4 = *puVar4;
  return 0xf8;
}


// ===== 0x0015dc menu_install_cbs_from_args =====

/* Call callback, then install enter/timeout/aux callbacks from arguments */

undefined1 menu_install_cbs_from_args(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  menu_install_cbs_from_args(c18_tmp0);
  menu_cb_aux = *(undefined1 *)((short)in_FSR2 + -6);
  menu_cb_aux_hi = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_timeout = 0x7a;
  menu_cb_timeout_hi = 0x12;
  menu_cb_enter = *(undefined1 *)((short)in_FSR2 + -6);
  menu_cb_enter_hi = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_back = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_back_hi = *(undefined1 *)((short)in_FSR2 + -2);
  menu_cb_up = *(undefined1 *)((short)in_FSR2 + -2);
  menu_cb_up_hi = *(undefined1 *)in_FSR2;
  menu_cb_down = *(undefined1 *)in_FSR2;
  menu_cb_down_hi = *(undefined1 *)((short)in_FSR2 + 2);
  menu_cb_key = *(undefined1 *)((short)in_FSR2 + 2);
  menu_cb_key_hi = *(undefined1 *)((short)in_FSR2 + 4);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return 0xf8;
}


// ===== 0x001644 screen_stopped =====

/* "STOPPED..." */

void screen_stopped(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ui_c18_prologue_2166();
  menu_timer_enabled = 0;
  ui_word_installation_2370();
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word_push6(0xd);
  ui_draw_press_ok_to_continue();
  dispense_stop_all();
  menu_cb_aux = 0;
  menu_cb_aux_hi = 0;
  menu_cb_timeout = 0;
  menu_cb_timeout_hi = 0;
  menu_cb_enter = *(undefined1 *)((short)in_FSR2 + -3);
  menu_cb_enter_hi = *(undefined1 *)((short)in_FSR2 + -1);
  menu_set_cbs_noop();
  menu_cb_key = 0;
  menu_cb_key_hi = 0;
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x001684 screen_fill_cold_tank =====

/* "FILL COLD WATER TANK" */

void screen_fill_cold_tank(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  byte unaff_Z;
  
  ui_to_ui_word_installation_2a96();
  if ((unaff_Z & 1) == 0) {
    *(undefined1 *)in_FSR1 = 2;
    uVar1 = 0x5b;
  }
  else {
    *(undefined1 *)in_FSR1 = 2;
    uVar1 = 0x5c;
  }
  ui_draw_word(uVar1);
  ui_draw_done(5);
  dispense_stop_all();
  ui_set_menu_timer_lo_2ade();
  menu_cb_aux = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_aux_hi = *(undefined1 *)((short)in_FSR2 + -2);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  ui_to_menu_set_cbs_noop_b_2a7e();
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x0016c2 menu_install_fill_tanks_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_install_fill_tanks_on_enter(void)

{
  ui_chain_ui_word_fill_cold__fn2b9c_26f6();
  return;
}


// ===== 0x0016d2 ui_to_screen_tank_filling_16d2 =====

/* Auto: calls screen_tank_filling; 26 instr */

undefined1 ui_to_screen_tank_filling_16d2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_set_menu_timer_lo_26be();
  *(undefined1 *)in_FSR1 = 10;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x17;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x14;
  *(undefined1 *)((short)in_FSR1 + 3) = 0x17;
  *(undefined1 *)((short)in_FSR1 + 4) = 0x78;
  *(undefined1 *)((short)in_FSR1 + 5) = 0xac;
  puVar1 = (undefined1 *)((short)in_FSR1 + 7);
  *(undefined1 *)((short)in_FSR1 + 6) = 1;
  c18_tmp0 = screen_tank_filling();
  if ((byte)puVar1 < 7) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return c18_tmp0;
}


// ===== 0x00170a ui_to_ui_to_screen_stopped_170a =====

/* Auto: Small wrapper around ui_to_screen_stopped; 4 instr */

void ui_to_ui_to_screen_stopped_170a(void)

{
  ui_to_screen_stopped_26fc(0x16);
  return;
}


// ===== 0x001714 ui_push_args_24_17_01_ui_to_screen_fill_cold_tank_1714 =====

/* Auto: Push constant arguments [36, 23, 1] then call ui_to_screen_fill_cold_tank; 7 instr */

void ui_push_args_24_17_01_ui_to_screen_fill_cold_tank_1714(void)

{
  ui_to_screen_fill_cold_tank_2708();
  return;
}


// ===== 0x001724 ui_push_args_32_17_1724 =====

/* Auto: Push constant arguments [50, 23] then call 0x26f6; 6 instr */

void ui_push_args_32_17_1724(void)

{
  ui_chain_ui_word_fill_cold__fn2b9c_26f6();
  return;
}


// ===== 0x001732 ui_to_screen_tank_filling_1732 =====

/* Auto: calls screen_tank_filling; 25 instr */

undefined1 ui_to_screen_tank_filling_1732(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_set_menu_timer_lo_26be();
  *(undefined1 *)in_FSR1 = 0x68;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x17;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x72;
  *(undefined1 *)((short)in_FSR1 + 3) = 0x17;
  *(undefined1 *)((short)in_FSR1 + 4) = 0x70;
  *(undefined1 *)((short)in_FSR1 + 5) = 0xac;
  puVar1 = (undefined1 *)((short)in_FSR1 + 7);
  *(undefined1 *)((short)in_FSR1 + 6) = 0;
  c18_tmp0 = screen_tank_filling();
  if ((byte)puVar1 < 7) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return c18_tmp0;
}


// ===== 0x001768 ui_to_ui_to_screen_stopped_1768 =====

/* Auto: Small wrapper around ui_to_screen_stopped; 4 instr */

void ui_to_ui_to_screen_stopped_1768(void)

{
  ui_to_screen_stopped_26fc(0x17);
  return;
}


// ===== 0x001772 ui_push_args_80_17_ui_to_screen_fill_cold_tank_1772 =====

/* Auto: Push constant arguments [128, 23] then call ui_to_screen_fill_cold_tank; 6 instr */

void ui_push_args_80_17_ui_to_screen_fill_cold_tank_1772(void)

{
  ui_to_screen_fill_cold_tank_2708();
  return;
}


// ===== 0x001780 screen_installation_completed =====

/* "INSTALLATION COMPLETED" */

undefined1 screen_installation_completed(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_word_installation_2370();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word_push6(0x7d);
  ui_draw_press_ok_to_continue();
  ui_set_menu_timer_lo_251e();
  menu_cb_enter = 0xa2;
  menu_cb_enter_hi = 0x17;
  return 0x17;
}


// ===== 0x0017a2 fn_1780_on_enter =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void fn_1780_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  cfg_systemconfig4 = cfg_systemconfig4 & 0xfe;
  puVar1 = &FramePointer10x0001;
  ui_to_param_write_215a(0x3a);
  puVar2 = puVar1 + 1;
  *puVar1 = 0x25;
  cfg_systemconfig = eeprom_read_param();
  *puVar2 = *puVar2;
  ui_to_system_wake_2a58();
  return;
}


// ===== 0x0017c4 menu_draw =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw current menu (title and items) */

void menu_draw(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  byte in_TABLAT;
  byte *in_TBLPTR;
  bool bVar6;
  
  ui_stack_adjust_2af8();
  bVar2 = in_TABLAT;
  ui_to_ui_get_menu_table_ptr_lo_2628();
  c18_tmp0 = bVar2;
  c18_tmp1 = 0;
  if ((c18_tmp0 ^ 0xff) == 0) {
    menu_item_count = 0;
    while( true ) {
      ui_get_menu_table_ptr_lo_2b3c();
      ui_get_c18_tmp0_2b52(4);
      bVar6 = menu_item_count == 0;
      ui_get_TBLPTRL_2b68(menu_item_count);
      if (bVar6) break;
      menu_item_count = menu_item_count + 1;
    }
  }
  else {
    bVar2 = c18_tmp0;
    ui_to_ui_get_menu_table_ptr_lo_2628(c18_tmp0 ^ 0xff);
    menu_item_count = bVar2;
  }
  lcd_clear();
  ui_get_TBLPTRL_22ba();
  ui_draw_title();
  puVar3 = (undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)in_FSR2 = 0;
  while( true ) {
    cVar1 = *(byte *)in_FSR2 - menu_item_count;
    if (menu_item_count <= *(byte *)in_FSR2) break;
    ui_get_menu_table_ptr_lo_2b3c();
    ui_get_TBLPTRL_2c14(0x24);
    ui_get_c18_tmp0_29d6();
    if (cVar1 == '\0') {
      ui_set_ui_wake_pending_244a(*(char *)in_FSR2 + '\x02');
      if (*(char *)in_FSR2 == menu_item) {
        uVar5 = 0x80;
      }
      else {
        uVar5 = 0;
      }
      ui_to_ui_get_menu_table_ptr_lo_29cc(uVar5);
      uVar5 = ui_get_TBLPTRL_29e8(*(undefined1 *)in_FSR2);
      puVar4 = puVar3 + 1;
      *puVar3 = uVar5;
      ui_to_txt_set_ui_hold_counter_28b4();
    }
    else {
      in_TBLPTR = (byte *)CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                                   CONCAT11(menu_table_ptr_hi + (0xdb < menu_table_ptr_lo),
                                            menu_table_ptr_lo + 0x24));
      c18_tmp0 = *in_TBLPTR;
      in_TBLPTR = in_TBLPTR + 1;
      c18_tmp1 = *in_TBLPTR;
      puVar4 = puVar3 + 1;
      *puVar3 = *(undefined1 *)in_FSR2;
      menu_draw_items();
    }
    puVar3 = puVar4 + -1;
    *puVar4 = *puVar4;
    *(char *)in_FSR2 = *(char *)in_FSR2 + '\x01';
  }
  *puVar3 = *puVar3;
  ui_c18_epilogue_21d8(cVar1);
  return;
}


// ===== 0x001848 menu_draw_items =====

/* Draw menu item list with highlight on selected item */

void menu_draw_items(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar3;
  undefined1 *in_TBLPTR;
  
  uVar3 = c18_tmp0;
  do {
    menu_draw_items(uVar3);
    while( true ) {
      puVar2 = (undefined1 *)((short)in_FSR1 + -1);
      *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
      *(char *)in_FSR2 = *(char *)in_FSR2 + '\x01';
      cVar1 = *(byte *)in_FSR2 - menu_item_count;
      if (menu_item_count <= *(byte *)in_FSR2) {
        *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
        ui_c18_epilogue_21d8(cVar1);
        return;
      }
      ui_get_menu_table_ptr_lo_2b3c();
      ui_get_TBLPTRL_2c14(0x24);
      ui_get_c18_tmp0_29d6();
      if (cVar1 != '\0') break;
      ui_set_ui_wake_pending_244a(*(char *)in_FSR2 + '\x02');
      if (*(char *)in_FSR2 == menu_item) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = 0;
      }
      ui_to_ui_get_menu_table_ptr_lo_29cc(uVar3);
      uVar3 = ui_get_TBLPTRL_29e8(*(undefined1 *)in_FSR2);
      in_FSR1 = (BADSPACEBASE *)(puVar2 + 1);
      *puVar2 = uVar3;
      ui_to_txt_set_ui_hold_counter_28b4();
    }
    uVar3 = 0;
    in_TBLPTR = (undefined1 *)
                CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                         CONCAT11(menu_table_ptr_hi + (0xdb < menu_table_ptr_lo),
                                  menu_table_ptr_lo + 0x24));
    c18_tmp0 = *in_TBLPTR;
    in_TBLPTR = in_TBLPTR + 1;
    c18_tmp1 = *in_TBLPTR;
    in_FSR1 = (BADSPACEBASE *)(puVar2 + 1);
    *puVar2 = *(undefined1 *)in_FSR2;
  } while( true );
}


// ===== 0x001888 ui_draw_clock_text =====

/* WARNING: Removing unreachable block (CODE,0x00189e) */
/* Draw clock text "%02b:%02b %s" */

void ui_draw_clock_text(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  bool bVar5;
  
  ui_c18_prologue_2166();
  if (menu_page == '\x02') {
    ui_get_menu_tmp_a_2aa2(0);
    ui_stack_adjust_2b26(0x80);
    puVar1 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0xa9;
    c18_tmp0 = ui_callw_txt_set_ui_hold_counter_2b10(0x58);
    uVar4 = c18_tmp0;
    if ((byte)puVar1 < 6) {
      *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
      uVar4 = c18_tmp0;
    }
  }
  else {
    bVar5 = menu_page != '\0';
    if (bVar5) {
      c18_tmp0 = 0xc1;
    }
    else {
      c18_tmp0 = 0xc4;
    }
    c18_tmp1 = 0x58;
    *(undefined1 *)in_FSR1 = c18_tmp0;
    puVar2 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = 0x58;
    ui_get_menu_tmp_a_2aa2();
    if (bVar5) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x80;
    }
    ui_stack_adjust_2b26(uVar4);
    puVar3 = puVar2 + 1;
    *puVar2 = 0x9c;
    c18_tmp2 = ui_callw_txt_set_ui_hold_counter_2b10(0x58);
    uVar4 = c18_tmp2;
    if ((byte)puVar3 < 8) {
      *(undefined1 *)((ushort)puVar3 & 0xff00) = *(undefined1 *)((ushort)puVar3 & 0xff00);
      uVar4 = c18_tmp2;
    }
  }
  ui_c18_epilogue_21d8(uVar4);
  return;
}


// ===== 0x001908 ui_draw_day =====

/* WARNING: Removing unreachable block (CODE,0x001960) */
/* Draw day of week */

void ui_draw_day(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  ui_chain_fn2b16_fn28aa_ui_get_menu_item_2bea();
  if ((unaff_Z & 1) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x80;
  }
  ui_to_ui_get_c18_tmp0_22cc(uVar4);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    uVar4 = 0x39;
  }
  else {
    uVar4 = 0x38;
  }
  ui_stack_adjust_21f4(uVar4);
  ui_to_ui_set_ui_wake_pending_28aa(0xfd);
  if (puVar1[-2] == '\0') {
    *(undefined1 *)in_FSR1 = 0x9d;
    puVar2 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = 1;
    mod_get_clock_pm_a7ee();
    *puVar2 = *puVar2;
    puVar3 = puVar2 + -2;
    puVar2[-1] = puVar2[-1];
    ui_frame_push_args_25cc();
    ui_draw_clock_text();
  }
  else {
    menu_day_edit = clock_get_day(puVar1[-2]);
    menu_day_edit_hi = 0;
    ui_get_menu_item_2554();
    ui_stack_adjust_2b26(0x80);
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = menu_day_edit;
    ui_to_txt_set_ui_hold_counter_28b4();
  }
  *puVar3 = *puVar3;
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x001974 menu_draw_item_line =====

/* Draw one menu line (highlighted when selected) */

void menu_draw_item_line(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  
  ui_c18_prologue_2166();
  ui_to_ui_set_ui_wake_pending_28aa(0xfc);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (menu_item == *(char *)((short)in_FSR2 + -3)) {
    uVar9 = 0x80;
  }
  else {
    uVar9 = 0;
  }
  ui_to_ui_get_c18_tmp0_22cc(uVar9);
  ui_frame_push_args_25cc();
  ui_to_txt_set_ui_hold_counter_28b4();
  puVar4 = (undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  ui_to_ui_set_ui_wake_pending_28aa(0xfc);
  if (puVar1[-6] == '\0') {
    if (menu_item == puVar1[-2]) {
      uVar9 = 0x80;
    }
    else {
      uVar9 = 0;
    }
    ui_stack_adjust_2b26(uVar9);
    puVar5 = puVar4 + 1;
    *puVar4 = 0x45;
    ui_to_txt_set_ui_hold_counter_28b4();
  }
  else {
    puVar6 = puVar4 + 1;
    puVar2 = puVar1 + 2;
    *puVar4 = puVar1[-3];
    menu_tmp_a = ui_to_eeprom_read_raw_2b00();
    puVar7 = puVar6 + 1;
    puVar3 = puVar2 + 1;
    *puVar6 = puVar2[-5];
    menu_tmp_a_hi = ui_to_eeprom_read_raw_2b00();
    *puVar7 = 0x9d;
    puVar8 = puVar7 + 2;
    puVar7[1] = 1;
    clock_edit_compute_ampm();
    *puVar8 = *puVar8;
    puVar8[-1] = puVar8[-1];
    puVar5 = puVar8 + -1;
    puVar8[-2] = puVar3[-3];
    ui_draw_clock_text();
  }
  *puVar5 = *puVar5;
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x001a00 ui_draw_wakeup_times =====

/* Draw wake-up 1/2 times (WKUPHOUR/WKUPMINUTE) */

void ui_draw_wakeup_times(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  char cVar2;
  byte unaff_C;
  
  cVar2 = ui_frag_2b16();
  if (*(char *)((short)in_FSR2 + (short)cVar2 + 1) == '\0') {
    *(bool *)in_FSR1 = (cfg_systemconfig3 & 0x10) != 0;
    *(undefined1 *)((short)in_FSR1 + 1) = 0x37;
    bVar1 = (byte)((ushort)((short)in_FSR1 + 3) >> 8);
    *(undefined1 *)((short)in_FSR1 + 2) = 0x36;
    ui_frame_push_args_25cc();
    ui_to_menu_draw_item_line_270e(0x36);
  }
  else {
    *(bool *)in_FSR1 = (cfg_systemconfig3 & 0x20) != 0;
    *(undefined1 *)((short)in_FSR1 + 1) = 0x39;
    bVar1 = (byte)((ushort)((short)in_FSR1 + 3) >> 8);
    *(undefined1 *)((short)in_FSR1 + 2) = 0x38;
    ui_frame_push_args_25cc();
    ui_to_menu_draw_item_line_270e(0x37);
  }
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  ui_c18_epilogue_21d8(c18_tmp0);
  return;
}


// ===== 0x001a54 ui_draw_temp_setting =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw temperature setting value (C or F) */

void ui_draw_temp_setting(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  byte unaff_Z;
  bool bVar5;
  
  ui_chain_fn2b16_fn28aa_ui_get_menu_item_2bea();
  if ((unaff_Z & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80;
  }
  ui_to_ui_get_menu_table_ptr_lo_29cc(uVar2);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  ui_get_TBLPTRL_29e8(*(undefined1 *)((short)in_FSR2 + -2));
  ui_stack_adjust_21f4();
  cVar4 = puVar1[-2];
  if (puVar1[-2] == '\0') {
    ui_callw_ui_to_eeprom_read_raw_228c(0x15);
    if ((cfg_systemconfig3 & 4) == 0) {
      ui_to___mul16x16_32_24ea(9);
      menu_value_lo = math_res0;
      menu_value_hi = math_res1;
      math_barg_lo = 5;
      math_barg_hi = 0;
      math_aarg_lo = math_res0;
      math_aarg_hi = math_res1;
      ui_to___divs16_289c();
      bVar5 = 0xdf < menu_value_lo;
      menu_value_lo = menu_value_lo + 0x20;
      menu_value_hi = menu_value_hi + bVar5;
      bVar5 = menu_value_hi == '\0';
    }
    else {
      bVar5 = true;
    }
    ui_get_cfg_systemconfig3_258a();
    if (bVar5) {
      uVar2 = 0x4b;
    }
    else {
      uVar2 = 0x4c;
    }
    ui_to_ui_word_ptr_2536(uVar2);
    ui_get_menu_value_lo_2ace();
    ui_get_menu_item_2554();
    if (bVar5) {
      bVar3 = 0x80;
    }
    else {
      bVar3 = 0;
    }
    c18_tmp2 = ui_stack_adjust_2644(bVar3 | 4);
    cVar4 = c18_tmp2;
    if ((byte)in_FSR1 < 8) {
      *(undefined1 *)((ushort)in_FSR1 & 0xff00) = *(undefined1 *)((ushort)in_FSR1 & 0xff00);
      cVar4 = c18_tmp2;
    }
  }
  ui_c18_epilogue_21d8(cVar4);
  return;
}


// ===== 0x001ae2 ui_draw_title =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw title bar text */

void ui_draw_title(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte *pbVar2;
  undefined1 uVar3;
  char cVar4;
  
  ui_stack_adjust_2af8();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 9;
  ui_frame_push_args_25cc();
  uVar3 = txt_to_lcd_printf_9936();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  *(undefined1 *)in_FSR2 = uVar3;
  text_row = 0;
  pbVar1[-2] = *(byte *)in_FSR2 < 0x79 | 0x8e;
  pbVar1[-1] = 0;
  ui_frame_push_args_25cc();
  ui_to_txt_set_ui_hold_counter_28b4();
  pbVar2 = pbVar1 + -1;
  *pbVar1 = *pbVar1;
  cVar4 = text_x - 3;
  if (2 < text_x) {
    text_x = text_x - 3;
    pbVar1[-1] = 0x98;
    ui_to_lcd_puts_rom_23f6(0x58);
    pbVar2 = pbVar1 + 1;
    *pbVar1 = text_x;
    mod_to_mod_to_lcd_write_cmd_cfd8();
    *pbVar2 = *pbVar2;
    pbVar2[-1] = 0x93;
    cVar4 = ui_to_lcd_puts_rom_23f6(0x58);
  }
  *pbVar2 = *pbVar2;
  ui_c18_epilogue_21d8(cVar4);
  return;
}


// ===== 0x001b4a screen_temp_sensor_values =====

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


// ===== 0x001bf2 menu_default_back =====

/* Menu/screen handler (callback analysis) */

void menu_default_back(void)

{
  ui_bank1_ui_set_menu_cb_up_2454();
  menu_draw();
  return;
}


// ===== 0x001bfa menu_default_ignore =====

/* Menu/screen handler (callback analysis) */

void menu_default_ignore(void)

{
  menu_edit_mode = menu_edit_mode == '\0';
  screen_temp_sensor_values();
  return;
}


// ===== 0x001c0c ui_to_ui_to_lcd_puts_rom_1c0c =====

/* Auto: Small wrapper around ui_to_lcd_puts_rom; 16 instr */

void ui_to_ui_to_lcd_puts_rom_1c0c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  char cVar3;
  
  cVar3 = ui_frag_2b16();
  if (*(char *)((short)in_FSR2 + (short)cVar3 + 1) == '\0') {
    *(undefined1 *)in_FSR1 = 0x7f;
  }
  else {
    *(undefined1 *)in_FSR1 = 0x89;
  }
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  ui_to_lcd_puts_rom_23f6(0x58);
  puVar2 = puVar1 + 1;
  *puVar1 = 0x20;
  mod_get_lcd_text_width_ca24();
  *puVar2 = *puVar2;
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x001c32 menu_mix_water_temp_on_up =====

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


// ===== 0x001c74 menu_mix_water_temp_on_down =====

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


// ===== 0x001cb6 menu_value_increment =====

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


// ===== 0x001d16 menu_value_decrement =====

/* Decrease edited value by step, clamp to minimum */

void menu_value_decrement(void)

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
  }
  else {
    menu_value_lo = 0;
    menu_value_hi = 0;
    cfg_systemconfig5 = cfg_systemconfig5 & 0xfb;
  }
  ui_to_progress_bar_scale_28fe();
  return;
}


// ===== 0x001d5e menu_cold_water_temp_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_cold_water_temp_on_down(void)

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
    ui_get_menu_value_step_lo_2378();
    progress_bar_scale();
  }
  return;
}


// ===== 0x001d9e menu_cold_water_temp_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_cold_water_temp_on_up(void)

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
    ui_get_menu_value_step_lo_2378();
    progress_bar_scale();
  }
  return;
}


// ===== 0x001ddc menu_mix_water_qty_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_mix_water_qty_on_up(void)

{
  menu_mix_water_temp_on_up();
  ui_to_ui_to_ui_draw_temp_units_1df4();
  return;
}


// ===== 0x001de2 menu_mix_water_qty_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_mix_water_qty_on_down(void)

{
  menu_mix_water_temp_on_down();
  ui_to_ui_to_ui_draw_temp_units_1df4();
  return;
}


// ===== 0x001de8 menu_hot_water_qty_on_up =====

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty_on_up(void)

{
  menu_value_increment();
  ui_set_menu_value_lo_1e14();
  return;
}


// ===== 0x001dee menu_hot_water_qty_on_down =====

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty_on_down(void)

{
  menu_value_decrement();
  ui_set_menu_value_lo_1e14();
  return;
}


// ===== 0x001df4 ui_to_ui_to_ui_draw_temp_units_1df4 =====

/* Auto: Small wrapper around ui_to_ui_draw_temp_units; 15 instr */

undefined1 ui_to_ui_to_ui_draw_temp_units_1df4(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  undefined1 uVar2;
  byte unaff_Z;
  byte unaff_C;
  
  bVar1 = (byte)((ushort)in_FSR1 >> 8);
  ui_to_ui_get_cfg_systemconfig2_2334();
  if ((unaff_Z & 1) == 0) {
    uVar2 = 0x23;
  }
  else {
    uVar2 = 0x37;
  }
  ui_to_ui_draw_temp_units_24d2(uVar2);
  ui_compare_multibyte_2b1e();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  return c18_tmp0;
}


// ===== 0x001e14 ui_set_menu_value_lo_1e14 =====

/* Auto: writes menu_value_lo,menu_value_hi; reads cfg_systemconfig5; 21 instr */

char ui_set_menu_value_lo_1e14(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  byte unaff_Z;
  
  if ((cfg_systemconfig5 & 4) == 0) {
    menu_value_lo = 0;
    menu_value_hi = 0;
    unaff_Z = 1;
  }
  ui_to_ui_get_cfg_systemconfig2_2334();
  if ((unaff_Z & 1) == 0) {
    uVar1 = 0x23;
  }
  else {
    uVar1 = 0x37;
  }
  ui_to_ui_draw_temp_units_24d2(uVar1);
  if ((byte)in_FSR1 < 5) {
    *(undefined1 *)((ushort)in_FSR1 & 0xff00) = *(undefined1 *)((ushort)in_FSR1 & 0xff00);
  }
  return (byte)in_FSR1 - 5;
}


// ===== 0x001e3e screen_cold_temp_bar =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Cold water temperature setting with bar graph */

void screen_cold_temp_bar(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  undefined1 uVar5;
  bool bVar6;
  
  ui_c18_prologue_2166();
  progress_bar_x = 0x10;
  progress_bar_width = 'n';
  progress_bar_y = 0x28;
  ui_set_progress_bar_value_2690(7);
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = progress_bar_width + -2;
  ui_callw_fncfc6_238c(1);
  pcVar2 = pcVar1 + 1;
  *pcVar1 = 0x7b;
  ui_to_lcd_puts_rom_23f6(0x58);
  pcVar3 = pcVar2 + 1;
  *pcVar2 = progress_bar_value + progress_bar_width;
  mod_to_mod_to_lcd_write_cmd_cfd8();
  *pcVar3 = *pcVar3;
  pcVar3[-1] = 0x77;
  ui_to_lcd_puts_rom_23f6(0x58);
  menu_value_min_lo = 2;
  menu_value_min_hi = 0;
  while( true ) {
    cVar4 = '\a';
    if ((menu_value_min_hi & 0x80) == 0) {
      bVar6 = menu_value_min_hi != ~(6 < menu_value_min_lo);
      cVar4 = menu_value_min_hi - ~(6 < menu_value_min_lo);
    }
    else {
      bVar6 = false;
    }
    if (bVar6) break;
    ui_set_menu_value_min_lo_2208(cVar4);
  }
  *pcVar3 = progress_bar_width + -1;
  ui_callw_fncfc6_238c(7);
  ui_callw_lcd_write_data_28be(0x1f);
  menu_value_min_lo = 0;
  for (menu_value_min_hi = 0;
      (menu_value_min_hi & 0x80) != 0 ||
      menu_value_min_hi == ~(progress_bar_value <= menu_value_min_lo);
      menu_value_min_hi = menu_value_min_hi + bVar6) {
    c18_tmp2 = 3;
    math_barg_hi = 3;
    math_aarg_hi = progress_bar_value;
    mod_shift_multibyte_fc24();
    c18_tmp0 = math_aarg_hi;
    c18_tmp1 = 0;
    if ((math_aarg_hi == menu_value_min_lo) && (menu_value_min_hi == 0)) {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x3f;
    }
    ui_callw_lcd_write_data_28be(uVar5);
    bVar6 = 0xfe < menu_value_min_lo;
    menu_value_min_lo = menu_value_min_lo + 1;
  }
  ui_callw_lcd_write_data_28be(0x1f);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    ui_get_menu_value_lo_21ca(0);
  }
  else {
    ui_get_menu_value_step_lo_2378();
  }
  progress_bar_scale();
  ui_c18_epilogue_21d8();
  return;
}


// ===== 0x001f12 screen_mix_temp_bar =====

/* Mix water temperature setting with bar graph */

void screen_mix_temp_bar(void)

{
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char cVar2;
  bool bVar3;
  
  progress_bar_x = 0x10;
  progress_bar_width = 'd';
  progress_bar_y = 0x18;
  ui_set_progress_bar_value_2690(0xc);
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = progress_bar_width + -1;
  ui_callw_fncfc6_238c(1);
  ui_get_progress_bar_value_24a8();
  menu_value_min_lo = 2;
  menu_value_min_hi = 0;
  while( true ) {
    cVar2 = '\x05';
    if ((menu_value_min_hi & 0x80) == 0) {
      bVar3 = menu_value_min_hi != ~(4 < menu_value_min_lo);
      cVar2 = menu_value_min_hi - ~(4 < menu_value_min_lo);
    }
    else {
      bVar3 = false;
    }
    if (bVar3) break;
    ui_set_menu_value_min_lo_2208();
  }
  ui_stack_adjust_2aba(cVar2);
  ui_callw_lcd_write_data_28be(3);
  *pcVar1 = progress_bar_value;
  ui_callw_mod_set_lcd_delay_counter_2a10(2);
  ui_callw_lcd_write_data_28be(3);
  ui_to_progress_bar_scale_28fe();
  return;
}


// ===== 0x001f6a screen_qty_bar =====

/* Water quantity setting with bar graph */

void screen_qty_bar(void)

{
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  char cVar8;
  bool bVar9;
  
  progress_bar_x = 0x18;
  progress_bar_width = 'd';
  progress_bar_y = 0x10;
  ui_set_progress_bar_value_2690(0xd);
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = progress_bar_width + -1;
  ui_callw_fncfc6_238c(2);
  ui_get_progress_bar_value_24a8();
  menu_value_min_lo = 3;
  menu_value_min_hi = 0;
  while( true ) {
    cVar8 = '\x05';
    if ((menu_value_min_hi & 0x80) == 0) {
      bVar9 = menu_value_min_hi != ~(4 < menu_value_min_lo);
      cVar8 = menu_value_min_hi - ~(4 < menu_value_min_lo);
    }
    else {
      bVar9 = false;
    }
    if (bVar9) break;
    ui_set_menu_value_min_lo_2208(cVar8);
  }
  pcVar2 = pcVar1 + 1;
  *pcVar1 = progress_bar_width + -6;
  ui_callw_fncfc6_238c(3);
  pcVar3 = pcVar2 + 1;
  *pcVar2 = 0x70;
  ui_to_lcd_puts_rom_23f6(0x58);
  pcVar4 = pcVar3 + 1;
  *pcVar3 = progress_bar_width + -6;
  ui_callw_fncfc6_238c(4);
  puVar5 = pcVar4 + 1;
  *pcVar4 = 0x69;
  ui_to_lcd_puts_rom_23f6(0x58);
  ui_stack_adjust_2aba();
  pcVar6 = puVar5 + 1;
  *puVar5 = 0x65;
  ui_to_lcd_puts_rom_23f6(0x58);
  pcVar7 = pcVar6 + 1;
  *pcVar6 = progress_bar_value + -2;
  ui_callw_mod_set_lcd_delay_counter_2a10(5);
  *pcVar7 = 0x61;
  ui_to_lcd_puts_rom_23f6(0x58);
  ui_to_progress_bar_scale_28fe();
  return;
}


// ===== 0x001ff2 menu_service_config_menu =====

/* Menu/screen handler (callback analysis) */

void menu_service_config_menu(void)

{
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig5 & 0x10) != 0);
  menu_cb_enter = 8;
  menu_set_cbs_back_default(0x20);
  return;
}


// ===== 0x002008 menu_service_config_menu_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_service_config_menu_on_enter(void)

{
  cfg_systemconfig5 = cfg_systemconfig5 & 0xef;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig5 = cfg_systemconfig5 | 0x10;
  }
  ui_get_cfg_systemconfig5_2c02();
  return;
}


// ===== 0x002020 menu_service_application =====

/* Menu/screen handler (callback analysis) */

undefined1 menu_service_application(void)

{
  byte unaff_Z;
  
  ui_to_ui_get_menu_table_ptr_lo_28f6();
  ui_get_menu_item_2296();
  if ((unaff_Z & 1) == 0) {
    ui_get_menu_item_2254();
  }
  menu_item = (cfg_systemconfig5 & 0x60) >> 5;
  menu_draw();
  menu_cb_enter = 0x5a;
  menu_cb_enter_hi = 0x20;
  menu_cb_back = 0x58;
  menu_cb_back_hi = 0x20;
  return 0x20;
}


// ===== 0x002058 menu_service_application_on_back =====

/* Menu/screen handler (callback analysis) */

void menu_service_application_on_back(void)

{
  ui_set_menu_cb_enter_2c0a();
  menu_key_back();
  return;
}


// ===== 0x00205a menu_service_application_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_service_application_on_enter(void)

{
  cfg_systemconfig5 = (menu_item & 3) << 5 | cfg_systemconfig5 & 0x9f;
  ui_to_param_write_215a(0x41);
  ui_to_menu_key_back_2670();
  return;
}


// ===== 0x00207e menu_service_uv =====

/* Menu/screen handler (callback analysis) */

void menu_service_uv(void)

{
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig & 8) != 0);
  menu_cb_enter = 0x94;
  menu_set_cbs_back_default(0x20);
  return;
}


// ===== 0x002094 menu_service_uv_on_enter =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_service_uv_on_enter(void)

{
  cfg_systemconfig = cfg_systemconfig & 0xf7;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig = cfg_systemconfig | 8;
  }
  ui_to_menu_default_back_279e(0x25);
  return;
}


// ===== 0x0020b0 menu_service_back_light =====

/* Menu/screen handler (callback analysis) */

void menu_service_back_light(void)

{
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig5 & 0x80) != 0);
  menu_cb_enter = 0xc6;
  menu_set_cbs_back_default(0x20);
  return;
}


// ===== 0x0020c6 menu_service_back_light_on_enter =====

/* Menu/screen handler (callback analysis) */

void menu_service_back_light_on_enter(void)

{
  cfg_systemconfig5 = cfg_systemconfig5 & 0x7f;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig5 = cfg_systemconfig5 | 0x80;
  }
  ui_get_cfg_systemconfig5_2c02();
  return;
}


// ===== 0x0020de ui_to_ui_draw_title_20de =====

/* Auto: calls ui_draw_title,ui_draw_on_off; 3 instr */

void ui_to_ui_draw_title_20de(void)

{
  ui_to_lcd_clear_2bf2();
  ui_draw_title();
  ui_draw_on_off();
  return;
}


// ===== 0x0020e8 progress_bar_scale =====

/* Scale a value to bar width */

void progress_bar_scale(char param_1)

{
  BADSPACEBASE *in_FSR1;
  
  c18_tmp4 = progress_bar_y;
  c18_tmp5 = 0;
  math_aarg_lo = (byte)((ushort)c18_tmp2 * (ushort)progress_bar_y);
  math_aarg_hi = (char)((ushort)c18_tmp2 * (ushort)progress_bar_y >> 8) + param_1 * progress_bar_y;
  math_barg_lo = c18_tmp6;
  math_barg_hi = c18_tmp7;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  c18_tmp3 = param_1;
  __divs16();
  menu_value_min_lo = c18_tmp8 + math_aarg_lo;
  menu_value_min_hi = c18_tmp9 + math_aarg_hi + CARRY1(c18_tmp8,math_aarg_lo);
  *(char *)in_FSR1 = menu_value_min_lo;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x4c;
  *(undefined1 *)((short)in_FSR1 + 2) = 1;
  gfx_bitmap_blit();
  ui_pop3_return_2b9c();
  return;
}


// ===== 0x002144 ui_draw_yes_no =====

/* Draw YES/NO choice */

void ui_draw_yes_no(void)

{
  ui_stack_adjust_2800();
  ui_set_text_a(0x42);
  ui_set_text_b(0x43);
  return;
}


// ===== 0x002150 menu_set_cbs_back_default =====

/* Store enter-callback high byte and install default back/up/down callbacks */

void menu_set_cbs_back_default(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xf2;
  menu_set_cbs_back_hi_b(0x1b);
  return;
}


// ===== 0x00215a ui_to_param_write_215a =====

/* Auto: calls param_write; 5 instr */

void ui_to_param_write_215a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  param_write();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002166 ui_c18_prologue_2166 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void ui_c18_prologue_2166(void)

{
  return;
}


// ===== 0x002178 ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__ =====

/* Auto: Calls ui_set_menu_value_step_lo, ui_get_menu_item, ui_to_ui_draw_set_hint; 3 instr */

void ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(void)

{
  ui_set_menu_value_step_lo_27d2();
  ui_get_menu_item_2780();
  ui_to_ui_draw_set_hint_2b86();
  return;
}


// ===== 0x002180 ui_get_menu_value_step_lo_2180 =====

/* Auto: reads menu_value_step_lo,menu_value_max_lo,menu_value_max_hi; 12 instr */

byte ui_get_menu_value_step_lo_2180(void)

{
  c18_tmp0 = menu_value_max_lo - menu_value_step_lo;
  c18_tmp1 = (menu_value_max_hi - menu_value_step_hi) - ~(menu_value_step_lo <= menu_value_max_lo);
  ui_to___divs16_28c8(0xc);
  return math_aarg_hi | math_aarg_lo;
}


// ===== 0x002198 menu_set_cbs_noop =====

/* Install no-op callbacks */

void menu_set_cbs_noop(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0x98;
  menu_set_cbs_back_hi(0);
  return;
}


// ===== 0x0021a0 ui_to___divs16_21a0 =====

/* Auto: writes menu_value_min_lo,menu_value_min_hi; reads
   menu_value_step_lo,menu_value_max_lo,menu_value_step_hi,menu_value_min_lo,menu_value_min_hi,math_aarg_lo;
   calls __divs16; 16 instr */

void ui_to___divs16_21a0(void)

{
  math_aarg_lo = menu_value_max_lo - menu_value_step_lo;
  math_aarg_hi = (menu_value_max_hi - menu_value_step_hi) -
                 ~(menu_value_step_lo <= menu_value_max_lo);
  math_barg_lo = 0xc;
  math_barg_hi = 0;
  menu_value_min_lo = math_aarg_lo;
  menu_value_min_hi = math_aarg_hi;
  __divs16();
  menu_value_min_lo = math_aarg_lo;
  menu_value_min_hi = math_aarg_hi;
  return;
}


// ===== 0x0021ca ui_get_menu_value_lo_21ca =====

/* Auto: reads menu_value_lo,menu_value_max_lo,menu_value_max_hi; 7 instr */

char ui_get_menu_value_lo_21ca(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  ui_get_progress_bar_x_2922();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x98);
  c18_tmp2 = bVar2 - bVar1;
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x99) - *(char *)((ushort)unaff_BSR * 0x100 + 0x95))
         - ~(bVar1 <= bVar2);
}


// ===== 0x0021d8 ui_c18_epilogue_21d8 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void ui_c18_epilogue_21d8(void)

{
  return;
}


// ===== 0x0021e4 ui_to_param_table_lookup_21e4 =====

/* Auto: calls param_table_lookup; 6 instr */

void ui_to_param_table_lookup_21e4(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  puVar1 = &FramePointer10x0001;
  uVar2 = param_table_lookup();
  *puVar1 = *puVar1;
  *(undefined1 *)in_FSR2 = uVar2;
  puVar1[-1] = *(undefined1 *)in_FSR2;
  return;
}


// ===== 0x0021f4 ui_stack_adjust_21f4 =====

/* Auto: Software stack push/pop helper; 4 instr */

void ui_stack_adjust_21f4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_to_txt_set_ui_hold_counter_28b4();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x0021fc ui_to_lcd_clear_21fc =====

/* Auto: writes menu_table_ptr_lo,menu_table_ptr_hi; calls lcd_clear; 4 instr */

void ui_to_lcd_clear_21fc(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x25) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x26) = 0;
  ui_set_menu_cb_up_29fa();
  lcd_clear();
  return;
}


// ===== 0x002208 ui_set_menu_value_min_lo_2208 =====

/* Auto: writes menu_value_min_lo; reads progress_bar_width,progress_bar_value; 12 instr */

undefined1 ui_set_menu_value_min_lo_2208(void)

{
  bool bVar1;
  
  ui_get_menu_value_min_lo_293a(progress_bar_width + -1);
  ui_get_menu_value_min_lo_293a(progress_bar_value + progress_bar_width);
  bVar1 = 0xfe < menu_value_min_lo;
  menu_value_min_lo = menu_value_min_lo + 1;
  menu_value_min_hi = menu_value_min_hi + bVar1;
  return 0;
}


// ===== 0x002220 screen_service_resetting =====

/* "SERVICE" / "RESETTING... WAIT" */

undefined1 screen_service_resetting(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  
  lcd_clear();
  ui_draw_title_word(0x34);
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word(0x59);
  ui_set_menu_timer_lo_2ade();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x40) = 0xce;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x41) = 0x14;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x2f) = 1;
  return 1;
}


// ===== 0x002248 menu_set_cbs_down_hi =====

/* Store down-callback high byte and install defaults */

undefined1 menu_set_cbs_down_hi(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xf2;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0x1b;
  return 0x1b;
}


// ===== 0x002254 ui_get_menu_item_2254 =====

/* Auto: reads menu_item,TBLPTRL,TBLPTRH; 12 instr */

void ui_get_menu_item_2254(void)

{
  byte unaff_BSR;
  short sVar1;
  
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_c18_tmp0_2b52(10);
  sVar1 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x27) * 2;
  ui_get_menu_table_ptr_lo_2a64
            ((char)((ushort)sVar1 >> 8) + c18_tmp1 + CARRY1((byte)sVar1,c18_tmp0));
  return;
}


// ===== 0x002270 ui_get_menu_item_2270 =====

/* Auto: reads menu_item,TABLAT; 9 instr */

void ui_get_menu_item_2270(void)

{
  undefined1 *in_TBLPTR;
  
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_TBLPTRL_2c14(3);
  menu_item = *in_TBLPTR;
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_TBLPTRL_2c14(0x16);
  ui_get_menu_table_ptr_lo_2a64();
  return;
}


// ===== 0x00228c ui_callw_ui_to_eeprom_read_raw_228c =====

/* Auto: Push W as argument and call ui_to_eeprom_read_raw; 3 instr */

void ui_callw_ui_to_eeprom_read_raw_228c(void)

{
  ui_to_eeprom_read_raw_2b00();
  ui_set_menu_value_lo_2bae();
  return;
}


// ===== 0x002296 ui_get_menu_item_2296 =====

/* Auto: reads menu_item,TBLPTRL,TBLPTRH; 9 instr */

void ui_get_menu_item_2296(void)

{
  byte unaff_BSR;
  short sVar1;
  
  sVar1 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x27) * 2;
  ui_get_c18_tmp0_29d6((char)((ushort)sVar1 >> 8) + c18_tmp3 + CARRY1((byte)sVar1,c18_tmp2));
  return;
}


// ===== 0x0022aa ui_get_menu_value_lo_22aa =====

/* Auto: reads menu_value_lo,menu_value_hi; 5 instr */

void ui_get_menu_value_lo_22aa(undefined1 param_1)

{
  math_barg_hi = 0;
  math_aarg_lo = menu_value_lo;
  math_aarg_hi = menu_value_hi;
  math_barg_lo = param_1;
  ui_to___divs16_289c();
  return;
}


// ===== 0x0022ba ui_get_TBLPTRL_22ba =====

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 8 instr */

undefined1 ui_get_TBLPTRL_22ba(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  
  ui_get_menu_table_ptr_lo_2b3c();
  uVar1 = *(undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                    CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfe < (byte)in_TBLPTR),
                             (byte)in_TBLPTR + 1));
  *(undefined1 *)in_FSR1 = uVar1;
  return uVar1;
}


// ===== 0x0022cc ui_to_ui_get_c18_tmp0_22cc =====

/* Auto: Small wrapper around ui_get_c18_tmp0; 7 instr */

void ui_to_ui_get_c18_tmp0_22cc(byte param_1)

{
  c18_tmp0 = param_1 | 0x22;
  c18_tmp1 = 1;
  ui_get_c18_tmp0_29a2();
  return;
}


// ===== 0x0022dc ui_to_ui_draw_title_22dc =====

/* Auto: calls ui_draw_title,ui_draw_on_off; 4 instr */

void ui_to_ui_draw_title_22dc(void)

{
  ui_draw_title();
  ui_draw_on_off();
  ui_to_screen_temp_sensor_values_2af0();
  return;
}


// ===== 0x0022ea ui_to_ui_draw_on_off_22ea =====

/* Auto: reads cfg_systemconfig3; calls ui_draw_on_off; 6 instr */

undefined1 ui_to_ui_draw_on_off_22ea(void)

{
  ui_chain_ui_to_lcd_clear_fn21d8_0450();
  ui_draw_on_off();
  return cfg_systemconfig3;
}


// ===== 0x0022fa ui_set_stat_GUV_22fa =====

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


// ===== 0x002334 ui_to_ui_get_cfg_systemconfig2_2334 =====

/* Auto: Small wrapper around ui_get_cfg_systemconfig2; 3 instr */

char ui_to_ui_get_cfg_systemconfig2_2334(void)

{
  char cVar1;
  
  cVar1 = ui_get_cfg_systemconfig2_2b2e();
  return '\x05' - cVar1;
}


// ===== 0x00233c ui_word_filter_233c =====

/* Auto: shows "FILTER"; calls lcd_clear; 3 instr */

void ui_word_filter_233c(void)

{
  lcd_clear();
  ui_to_ui_draw_title_word_2a1c(0x4d);
  return;
}


// ===== 0x002344 ui_set_menu_value_step_lo_2344 =====

/* Auto: writes menu_value_step_lo,menu_value_step_hi; 7 instr */

void ui_set_menu_value_step_lo_2344(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = ui_to_param_read_min_2b7a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9a) = uVar1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9b) = 0;
  *(undefined1 *)in_FSR1 = 1;
  ui_get_menu_item_2780();
  ui_to_ui_draw_set_hint_2b86();
  return;
}


// ===== 0x002356 ui_to_ui_draw_temp_value_2356 =====

/* Auto: calls ui_draw_temp_value; 3 instr */

void ui_to_ui_draw_temp_value_2356(void)

{
  ui_draw_temp_value();
  ui_compare_multibyte_2b1e();
  return;
}


// ===== 0x002360 ui_to_param_read_max_2360 =====

/* Auto: writes menu_value_max_lo,menu_value_max_hi; calls param_read_max; 7 instr */

void ui_to_param_read_max_2360(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  menu_value_max_lo = param_read_max();
  *puVar1 = *puVar1;
  menu_value_max_hi = 0;
  return;
}


// ===== 0x002370 ui_word_installation_2370 =====

/* Auto: shows "INSTALLATION"; calls lcd_clear; 3 instr */

void ui_word_installation_2370(void)

{
  lcd_clear();
  ui_to_ui_draw_title_word_2a1c(0x29);
  return;
}


// ===== 0x002378 ui_get_menu_value_step_lo_2378 =====

/* Auto: reads menu_value_step_lo,menu_value_lo,menu_value_hi; 7 instr */

char ui_get_menu_value_step_lo_2378(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  ui_get_progress_bar_x_2922();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x9a);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  c18_tmp2 = bVar2 - bVar1;
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) - *(char *)((ushort)unaff_BSR * 0x100 + 0x9b))
         - ~(bVar1 <= bVar2);
}


// ===== 0x002386 ui_set_menu_edit_mode_2386 =====

/* Auto: writes menu_edit_mode; 3 instr */

void ui_set_menu_edit_mode_2386(undefined1 param_1)

{
  menu_edit_mode = param_1;
  ui_to_screen_temp_sensor_values_2af0();
  return;
}


// ===== 0x00238c ui_callw_fncfc6_238c =====

/* Auto: Push W as argument and call 0xcfc6; 5 instr */

void ui_callw_fncfc6_238c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002398 ui_get_c18_tmp2_2398 =====

/* Auto: reads c18_tmp2,TBLPTRL,c18_tmp3,TBLPTRH; 4 instr */

void ui_get_c18_tmp2_2398(void)

{
  undefined1 in_TBLPTRL;
  undefined1 in_TBLPTRH;
  
  ui_get_TBLPTRL_2c14();
  c18_tmp2 = in_TBLPTRL;
  c18_tmp3 = in_TBLPTRH;
  return;
}


// ===== 0x0023a6 screen_clock_edit_hour =====

/* Clock set: edit hours (then minutes) */

undefined1 screen_clock_edit_hour(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = ui_set_menu_value_lo_2bae(1);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = uVar2;
  ui_draw_time();
  *puVar1 = *puVar1;
  menu_cb_up = 0xa8;
  menu_cb_up_hi = 7;
  menu_cb_down = 0xa0;
  menu_cb_down_hi = 7;
  menu_cb_back = 6;
  menu_cb_back_hi = 8;
  menu_cb_enter = 0xcc;
  menu_cb_enter_hi = 7;
  return 7;
}


// ===== 0x0023d8 ui_get_menu_value_hi_23d8 =====

/* Auto: reads menu_value_hi,menu_value_lo; 7 instr */

char ui_get_menu_value_hi_23d8(byte param_1)

{
  byte unaff_BSR;
  short sVar1;
  char cVar2;
  
  menu_value_hi = *(char *)((ushort)unaff_BSR * 0x100 + 0x95) * param_1;
  sVar1 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x94) * (ushort)param_1;
  menu_value_lo = (undefined1)sVar1;
  cVar2 = (char)((ushort)sVar1 >> 8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x95) = *(char *)((ushort)unaff_BSR * 0x100 + 0x95) + cVar2;
  return cVar2;
}


// ===== 0x0023ea ui_to_ui_draw_time_23ea =====

/* Auto: calls ui_draw_time; 5 instr */

void ui_to_ui_draw_time_23ea(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_draw_time();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x0023f6 ui_to_lcd_puts_rom_23f6 =====

/* Auto: calls lcd_puts_rom; 5 instr */

void ui_to_lcd_puts_rom_23f6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_puts_rom();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002402 ui_set_menu_cb_timeout_2402 =====

/* Auto: writes
   menu_cb_timeout,menu_cb_timeout_hi,menu_cb_enter,menu_cb_enter_hi,menu_cb_back,menu_cb_back_hi;
   25 instr */

undefined1 ui_set_menu_cb_timeout_2402(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0x7a;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0x12;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3c) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3d) = 0x13;
  return 0x13;
}


// ===== 0x002434 menu_set_cbs_enter_hi_b =====

/* Store enter-callback high byte (variant) */

void menu_set_cbs_enter_hi_b(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0x98;
  menu_set_cbs_back_hi_b(0);
  return;
}


// ===== 0x00243e ui_draw_press_ok_when_ready =====

/* "PRESS OK WHEN READY" */

void ui_draw_press_ok_when_ready(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_draw_word();
  *(undefined1 *)in_FSR1 = 5;
  ui_draw_word(0x69);
  return;
}


// ===== 0x00244a ui_set_ui_wake_pending_244a =====

/* Auto: writes ui_wake_pending,text_fill_width; 5 instr */

undefined1 ui_set_ui_wake_pending_244a(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 3) = param_1;
  text_fill_width = 0x80;
  return 0x80;
}


// ===== 0x002454 ui_bank1_ui_set_menu_cb_up_2454 =====

/* Auto: Select bank then jump to ui_set_menu_cb_up; 2 instr */

void ui_bank1_ui_set_menu_cb_up_2454(void)

{
  ui_set_menu_cb_up_29fa();
  return;
}


// ===== 0x00245a ui_to_ui_set_text_row_245a =====

/* Auto: Small wrapper around ui_set_text_row; 7 instr */

undefined1 ui_to_ui_set_text_row_245a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_chain_ui_to_lcd_clear_fn21d8_0450();
  puVar1 = (undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  ui_set_text_row_2b08();
  *puVar1 = 2;
  puVar1[1] = 0;
  return 2;
}


// ===== 0x00246a ui_to_screen_replacement_counter_246a =====

/* Auto: writes menu_cb_back,menu_cb_back_hi,menu_cb_down_hi; calls
   screen_replacement_counter,menu_set_cbs_updown_default; 8 instr */

void ui_to_screen_replacement_counter_246a(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  
  screen_replacement_counter();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xb8;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0xd;
  uVar1 = menu_set_cbs_updown_default();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = uVar1;
  return;
}


// ===== 0x00247a ui_set_stat_GFI_247a =====

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


// ===== 0x002498 ui_set_menu_edit_mode_2498 =====

/* Auto: writes menu_edit_mode; 3 instr */

void ui_set_menu_edit_mode_2498(void)

{
  menu_edit_mode = 0;
  ui_to_screen_temp_sensor_values_2af0();
  return;
}


// ===== 0x00249e ui_to_ui_draw_time_249e =====

/* Auto: calls ui_draw_time; 4 instr */

void ui_to_ui_draw_time_249e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_draw_time();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x0024a8 ui_get_progress_bar_value_24a8 =====

/* Auto: reads progress_bar_value; 7 instr */

void ui_get_progress_bar_value_24a8(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_callw_lcd_write_data_28be(0xf0);
  *(undefined1 *)in_FSR1 = progress_bar_value;
  ui_callw_mod_set_lcd_delay_counter_2a10(0x10);
  ui_callw_lcd_write_data_28be(0xf0);
  return;
}


// ===== 0x0024ba ui_get_menu_item_24ba =====

/* Auto: reads menu_item,TBLPTRH,TBLPTRL; 8 instr */

undefined1 ui_get_menu_item_24ba(void)

{
  return 0xe6;
}


// ===== 0x0024ca ui_draw_word_push6 =====

/* Draw word then push 6 */

undefined1 ui_draw_word_push6(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_draw_word();
  *(undefined1 *)in_FSR1 = 6;
  return 6;
}


// ===== 0x0024d2 ui_to_ui_draw_temp_units_24d2 =====

/* Auto: writes ui_substate; calls ui_draw_temp_units; 11 instr */

void ui_to_ui_draw_temp_units_24d2(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 2) = param_1;
  ui_get_menu_value_lo_2ace();
  ui_draw_temp_units();
  return;
}


// ===== 0x0024ea ui_to___mul16x16_32_24ea =====

/* Auto: reads menu_value_lo,menu_value_hi; calls __mul16x16_32; 5 instr */

void ui_to___mul16x16_32_24ea(undefined1 param_1)

{
  math_aarg_hi = 0;
  math_barg_lo = menu_value_lo;
  math_barg_hi = menu_value_hi;
  math_aarg_lo = param_1;
  __mul16x16_32();
  return;
}


// ===== 0x0024fa ui_get_menu_value_lo_24fa =====

/* Auto: reads menu_value_lo,menu_value_min_lo,menu_value_hi,menu_value_max_hi; 9 instr */

byte ui_get_menu_value_lo_24fa(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  c18_tmp0 = bVar2 + bVar1;
  c18_tmp1 = *(char *)((ushort)unaff_BSR * 0x100 + 0x97) +
             *(char *)((ushort)unaff_BSR * 0x100 + 0x95) + CARRY1(bVar2,bVar1);
  return *(byte *)((ushort)unaff_BSR * 0x100 + 0x99) ^ c18_tmp1;
}


// ===== 0x00250c ui_get_menu_value_min_lo_250c =====

/* Auto: reads menu_value_min_lo,menu_value_lo,menu_value_hi,menu_value_step_hi; 9 instr */

byte ui_get_menu_value_min_lo_250c(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  c18_tmp0 = bVar2 - bVar1;
  c18_tmp1 = (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) -
             *(char *)((ushort)unaff_BSR * 0x100 + 0x97)) - ~(bVar1 <= bVar2);
  return c18_tmp1 ^ *(byte *)((ushort)unaff_BSR * 0x100 + 0x9b);
}


// ===== 0x00251e ui_set_menu_timer_lo_251e =====

/* Auto: writes
   menu_timer_lo,menu_timer_hi,menu_cb_timeout,menu_cb_timeout_hi,menu_cb_aux,menu_cb_aux_hi; 7
   instr */

void ui_set_menu_timer_lo_251e(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x2b) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x2c) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x40) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x41) = 0;
  return;
}


// ===== 0x00252c menu_set_cbs_noop_b =====

/* Install no-op enter callback */

undefined1 menu_set_cbs_noop_b(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x98;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0;
  return 0;
}


// ===== 0x002536 ui_to_ui_word_ptr_2536 =====

/* Auto: reads c18_tmp0,c18_tmp1; calls ui_word_ptr; 6 instr */

void ui_to_ui_word_ptr_2536(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  uVar1 = in_PRODL;
  ui_word_ptr();
  c18_tmp0 = uVar1;
  c18_tmp1 = in_PRODH;
  *(undefined1 *)in_FSR1 = c18_tmp0;
  *(undefined1 *)((short)in_FSR1 + 1) = in_PRODH;
  return;
}


// ===== 0x00254a menu_set_cbs_enter_hi_c =====

/* Store enter-callback high byte (variant) */

void menu_set_cbs_enter_hi_c(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xb8;
  menu_set_cbs_back_hi_b(0xd);
  return;
}


// ===== 0x002554 ui_get_menu_item_2554 =====

/* Auto: reads menu_item; 5 instr */

char ui_get_menu_item_2554(void)

{
  char in_FramePointer2_0000fffe;
  
  return menu_item - in_FramePointer2_0000fffe;
}


// ===== 0x00255e ui_set_menu_value_min_lo_255e =====

/* Auto: writes menu_value_min_lo,menu_value_min_hi; 5 instr */

undefined1 ui_set_menu_value_min_lo_255e(void)

{
  menu_value_min_lo = 1;
  menu_value_min_hi = 0;
  return 1;
}


// ===== 0x002568 ui_get_menu_value_step_lo_2568 =====

/* Auto: reads menu_value_step_lo,menu_value_step_hi; 4 instr */

void ui_get_menu_value_step_lo_2568(void)

{
  return;
}


// ===== 0x002574 ui_get_menu_value_max_lo_2574 =====

/* Auto: reads menu_value_max_lo,menu_value_max_hi; 4 instr */

void ui_get_menu_value_max_lo_2574(void)

{
  return;
}


// ===== 0x002580 menu_set_cbs_enter_hi =====

/* Store enter-callback high byte and install defaults */

void menu_set_cbs_enter_hi(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xf2;
  menu_clear_cbs(0x1b);
  return;
}


// ===== 0x00258a ui_get_cfg_systemconfig3_258a =====

/* Auto: reads cfg_systemconfig3; 5 instr */

byte ui_get_cfg_systemconfig3_258a(void)

{
  ui_to_ui_get_cfg_systemconfig2_2c1c();
  return cfg_systemconfig3 & 4;
}


// ===== 0x002594 ui_to_txt_set_ui_hold_counter_2594 =====

/* Auto: Small wrapper around txt_set_ui_hold_counter; 8 instr */

char ui_to_txt_set_ui_hold_counter_2594(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  
  ui_stack_adjust_2b26();
  cVar1 = (char)(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x75;
  c18_tmp8 = txt_set_ui_hold_counter_98fc();
  return cVar1 + -5;
}


// ===== 0x0025a6 ui_frag_25a6 =====

/* Auto: compiler fragment: ANDLW #0x7 ; MOVWF PRODL,ACCESS ; RLNCF PRODL,f,ACCESS ; RLNCF
   PRODL,f,ACCESS ; RLNCF PRODL,f,ACCESS ; MOVLW #0xc7 ; RETURN 0x0 */

undefined1 ui_frag_25a6(void)

{
  return 199;
}


// ===== 0x0025b4 ui_callw_txt_set_ui_hold_counter_25b4 =====

/* Auto: Push W as argument and call txt_set_ui_hold_counter; 6 instr */

char ui_callw_txt_set_ui_hold_counter_25b4(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp2 = txt_set_ui_hold_counter_98fc();
  return cVar1 + -5;
}


// ===== 0x0025c2 ui_get_menu_value_step_lo_25c2 =====

/* Auto: reads menu_value_step_lo,menu_value_step_hi; 3 instr */

void ui_get_menu_value_step_lo_25c2(void)

{
  menu_value_lo = menu_value_step_lo;
  menu_value_hi = menu_value_step_hi;
  return;
}


// ===== 0x0025cc ui_frame_push_args_25cc =====

/* Auto: Copy stack-frame arguments onto the stack for a call; 3 instr */

undefined1 ui_frame_push_args_25cc(void)

{
  return 0xfd;
}


// ===== 0x0025d4 ui_to_param_table_lookup_25d4 =====

/* Auto: calls param_table_lookup; 7 instr */

void ui_to_param_table_lookup_25d4(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  puVar1 = &FramePointer10x0001;
  uVar2 = param_table_lookup();
  *puVar1 = *puVar1;
  *(undefined1 *)in_FSR2 = uVar2;
  return;
}


// ===== 0x0025e8 ui_get_c18_tmp0_25e8 =====

/* Auto: reads c18_tmp0,TABLAT; 4 instr */

char ui_get_c18_tmp0_25e8(void)

{
  char cVar1;
  char in_TABLAT;
  
  c18_tmp0 = in_TABLAT;
  cVar1 = ui_get_cfg_systemconfig2_2b2e();
  return c18_tmp0 - cVar1;
}


// ===== 0x0025f2 screen_time_edit_setup_b =====

/* Install up/down callbacks for time editing (variant) */

undefined1 screen_time_edit_setup_b(void)

{
  menu_cb_up = 0x5c;
  menu_cb_up_hi = 8;
  menu_cb_down = 0x54;
  menu_cb_down_hi = 8;
  return 8;
}


// ===== 0x002606 ui_get_TBLPTRH_2606 =====

/* Auto: reads TBLPTRH,c18_tmp4,TABLAT,c18_tmp5; 8 instr */

void ui_get_TBLPTRH_2606(undefined1 param_1)

{
  undefined3 in_TBLPTR;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(param_1,(char)in_TBLPTR));
  c18_tmp4 = *puVar1;
  c18_tmp5 = puVar1[1];
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  return;
}


// ===== 0x00261a ui_draw_power_down =====

/* "POWER DOWN" */

undefined1 ui_draw_power_down(void)

{
  BADSPACEBASE *in_FSR1;
  
  lcd_clear();
  ui_draw_title_word(10);
  *(undefined1 *)in_FSR1 = 2;
  return 2;
}


// ===== 0x002628 ui_to_ui_get_menu_table_ptr_lo_2628 =====

/* Auto: Small wrapper around ui_get_menu_table_ptr_lo; 5 instr */

void ui_to_ui_get_menu_table_ptr_lo_2628(void)

{
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_TBLPTRL_2c14(2);
  return;
}


// ===== 0x002632 ui_get_c18_tmp1_2632 =====

/* Auto: reads c18_tmp1,c18_tmp0; 7 instr */

char ui_get_c18_tmp1_2632(byte param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)c18_tmp0;
  c18_tmp0 = (char)(uVar1 * param_1);
  cVar2 = (char)(uVar1 * param_1 >> 8);
  c18_tmp1 = c18_tmp1 * param_1 + cVar2;
  return cVar2;
}


// ===== 0x002644 ui_stack_adjust_2644 =====

/* Auto: Software stack push/pop helper; 6 instr */

void ui_stack_adjust_2644(void)

{
  ui_callw_txt_set_ui_hold_counter_2b10(0x58);
  return;
}


// ===== 0x002652 ui_get_menu_edit_mode_2652 =====

/* Auto: reads menu_edit_mode; 6 instr */

undefined1 ui_get_menu_edit_mode_2652(char param_1)

{
  byte unaff_C;
  
  c18_tmp3 = (c18_tmp7 - param_1) - ~(unaff_C & 1);
  ui_get_c18_tmp0_29a2();
  return menu_edit_mode;
}


// ===== 0x00265e ui_push_args_14_04_mod_to_ui_draw_progress_segment_265e =====

/* Auto: Push constant arguments [20, 4] then call mod_to_ui_draw_progress_segment; 8 instr */

void ui_push_args_14_04_mod_to_ui_draw_progress_segment_265e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_to_ui_draw_progress_segment_e2ba();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002670 ui_to_menu_key_back_2670 =====

/* Auto: calls menu_key_back; 3 instr */

void ui_to_menu_key_back_2670(void)

{
  ui_set_menu_cb_enter_2c0a();
  menu_key_back();
  return;
}


// ===== 0x002678 ui_set_menu_value_lo_2678 =====

/* Auto: writes menu_value_lo; 6 instr */

byte ui_set_menu_value_lo_2678(void)

{
  bool bVar1;
  
  bVar1 = menu_value_lo != '\0';
  menu_value_lo = menu_value_lo - 1;
  menu_value_hi = menu_value_hi - ~bVar1;
  return ~menu_value_lo;
}


// ===== 0x002684 ui_to_screen_cold_temp_bar_2684 =====

/* Auto: calls screen_cold_temp_bar; 5 instr */

void ui_to_screen_cold_temp_bar_2684(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  screen_cold_temp_bar();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x002690 ui_set_progress_bar_value_2690 =====

/* Auto: writes progress_bar_value; reads progress_bar_x,progress_bar_y; 6 instr */

void ui_set_progress_bar_value_2690(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x4f) = param_1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x50) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x4e) + *(char *)((ushort)unaff_BSR * 0x100 + 0x4c) +
       -1;
  return;
}


// ===== 0x00269c ui_set_menu_timer_reload_lo_269c =====

/* Auto: writes menu_timer_reload_lo,menu_timer_reload_hi; 5 instr */

void ui_set_menu_timer_reload_lo_269c(undefined1 param_1)

{
  menu_timer_reload_lo = param_1;
  menu_timer_reload_hi = 0;
  return;
}


// ===== 0x0026a6 ui_set_menu_value_lo_26a6 =====

/* Auto: writes menu_value_lo,menu_value_hi; 4 instr */

void ui_set_menu_value_lo_26a6(void)

{
  menu_value_lo = 0;
  menu_value_hi = 0;
  return;
}


// ===== 0x0026ae ui_word_uv_lamp_26ae =====

/* Auto: shows "UV LAMP"; calls lcd_clear; 3 instr */

void ui_word_uv_lamp_26ae(void)

{
  lcd_clear();
  ui_to_ui_draw_title_word_2a1c(0x4e);
  return;
}


// ===== 0x0026b6 ui_draw_done =====

/* "DONE" */

void ui_draw_done(void)

{
  ui_draw_word(0xc);
  return;
}


// ===== 0x0026be ui_set_menu_timer_lo_26be =====

/* Auto: writes menu_timer_lo,menu_timer_hi,menu_timer_reload_lo; reads menu_timer_hi; 7 instr */

undefined1 ui_set_menu_timer_lo_26be(void)

{
  menu_timer_lo = 0x78;
  menu_timer_hi = 0;
  menu_timer_reload_lo = 0x78;
  menu_timer_reload_hi = 0;
  return 0x78;
}


// ===== 0x0026ce ui_bank1_ui_set_menu_cb_enter_26ce =====

/* Auto: Select bank then jump to ui_set_menu_cb_enter; 2 instr */

void ui_bank1_ui_set_menu_cb_enter_26ce(void)

{
  ui_set_menu_cb_enter_2c0a();
  return;
}


// ===== 0x0026d4 ui_get_c18_tmp2_26d4 =====

/* Auto: reads c18_tmp2,c18_tmp3; 5 instr */

undefined1 ui_get_c18_tmp2_26d4(void)

{
  undefined1 in_FramePointer2_0000fffb;
  undefined1 in_FramePointer2_0000fffd;
  
  c18_tmp2 = in_FramePointer2_0000fffb;
  c18_tmp3 = in_FramePointer2_0000fffd;
  return 0xfb;
}


// ===== 0x0026e2 ui_stack_adjust_26e2 =====

/* Auto: Software stack push/pop helper; 4 instr */

undefined1 ui_stack_adjust_26e2(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_callw_fn0450_2b5e();
  *(undefined1 *)in_FSR1 = 2;
  return 2;
}


// ===== 0x0026ea ui_draw_press_any_key_to_stop =====

/* "PRESS ANY KEY TO STOP" */

void ui_draw_press_any_key_to_stop(void)

{
  ui_draw_word(0x56);
  return;
}


// ===== 0x0026f0 ui_draw_press_ok_to_continue =====

/* "PRESS OK TO CONTINUE" */

void ui_draw_press_ok_to_continue(void)

{
  ui_draw_word(0x6b);
  return;
}


// ===== 0x0026f6 ui_chain_ui_word_fill_cold__fn2b9c_26f6 =====

/* Auto: Calls ui_word_fill_cold_water_tank, 0x2b9c; 2 instr */

void ui_chain_ui_word_fill_cold__fn2b9c_26f6(void)

{
  ui_word_fill_cold_water_tank_1550();
  ui_pop3_return_2b9c();
  return;
}


// ===== 0x0026fc ui_to_screen_stopped_26fc =====

/* Auto: calls screen_stopped; 5 instr */

void ui_to_screen_stopped_26fc(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  screen_stopped();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002708 ui_to_screen_fill_cold_tank_2708 =====

/* Auto: calls screen_fill_cold_tank; 2 instr */

void ui_to_screen_fill_cold_tank_2708(void)

{
  screen_fill_cold_tank();
  ui_pop3_return_2b9c();
  return;
}


// ===== 0x00270e ui_to_menu_draw_item_line_270e =====

/* Auto: calls menu_draw_item_line; 3 instr */

void ui_to_menu_draw_item_line_270e(void)

{
  menu_draw_item_line();
  ui_compare_multibyte_2b1e();
  return;
}


// ===== 0x002718 ui_to_txt_set_ui_hold_counter_2718 =====

/* Auto: Small wrapper around txt_set_ui_hold_counter; 3 instr */

void ui_to_txt_set_ui_hold_counter_2718(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_set_ui_hold_counter_9914();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  ui_pop3_return_2b9c();
  return;
}


// ===== 0x002720 ui_set_menu_value_lo_2720 =====

/* Auto: writes menu_value_lo; 5 instr */

undefined1 ui_set_menu_value_lo_2720(void)

{
  bool bVar1;
  
  bVar1 = 0xfe < menu_value_lo;
  menu_value_lo = menu_value_lo + 1;
  menu_value_hi = menu_value_hi + bVar1;
  return 0;
}


// ===== 0x00272a ui_get_menu_value_max_lo_272a =====

/* Auto: reads menu_value_max_lo,menu_value_lo,menu_value_max_hi; 5 instr */

char ui_get_menu_value_max_lo_272a(void)

{
  byte unaff_BSR;
  
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) - *(char *)((ushort)unaff_BSR * 0x100 + 0x99))
         - ~(*(byte *)((ushort)unaff_BSR * 0x100 + 0x98) <=
            *(byte *)((ushort)unaff_BSR * 0x100 + 0x94));
}


// ===== 0x002734 ui_get_menu_value_max_lo_2734 =====

/* Auto: reads menu_value_max_lo; 5 instr */

char ui_get_menu_value_max_lo_2734(void)

{
  byte unaff_BSR;
  
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x99) - c18_tmp1) -
         ~(c18_tmp0 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0x98));
}


// ===== 0x00273e ui_get_menu_value_min_lo_273e =====

/* Auto: reads menu_value_min_lo,menu_value_lo,menu_value_min_hi; 5 instr */

char ui_get_menu_value_min_lo_273e(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) = bVar2 + bVar1;
  cVar3 = *(char *)((ushort)unaff_BSR * 0x100 + 0x97);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x95) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x95) + cVar3 + CARRY1(bVar2,bVar1);
  return cVar3;
}


// ===== 0x002748 ui_get_menu_value_max_lo_2748 =====

/* Auto: reads menu_value_max_lo,menu_value_max_hi; 3 instr */

void ui_get_menu_value_max_lo_2748(void)

{
  menu_value_lo = menu_value_max_lo;
  menu_value_hi = menu_value_max_hi;
  return;
}


// ===== 0x002752 ui_get_menu_value_lo_2752 =====

/* Auto: reads menu_value_lo,menu_value_step_lo,menu_value_hi; 5 instr */

char ui_get_menu_value_lo_2752(void)

{
  byte unaff_BSR;
  
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x9b) - *(char *)((ushort)unaff_BSR * 0x100 + 0x95))
         - ~(*(byte *)((ushort)unaff_BSR * 0x100 + 0x94) <=
            *(byte *)((ushort)unaff_BSR * 0x100 + 0x9a));
}


// ===== 0x00275c ui_get_menu_value_step_lo_275c =====

/* Auto: reads menu_value_step_lo,menu_value_step_hi; 5 instr */

char ui_get_menu_value_step_lo_275c(void)

{
  byte unaff_BSR;
  
  return (c18_tmp1 - *(char *)((ushort)unaff_BSR * 0x100 + 0x9b)) -
         ~(*(byte *)((ushort)unaff_BSR * 0x100 + 0x9a) <= c18_tmp0);
}


// ===== 0x002766 ui_get_menu_value_min_lo_2766 =====

/* Auto: reads menu_value_min_lo,menu_value_lo,menu_value_min_hi; 5 instr */

char ui_get_menu_value_min_lo_2766(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) = bVar2 - bVar1;
  cVar3 = *(char *)((ushort)unaff_BSR * 0x100 + 0x97);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x95) =
       (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) - cVar3) - ~(bVar1 <= bVar2);
  return cVar3;
}


// ===== 0x002770 ui_get_menu_edit_mode_2770 =====

/* Auto: reads menu_edit_mode; 4 instr */

undefined1 ui_get_menu_edit_mode_2770(void)

{
  return menu_edit_mode;
}


// ===== 0x002778 ui_get_menu_value_lo_2778 =====

/* Auto: reads menu_value_lo,menu_value_hi; 4 instr */

byte ui_get_menu_value_lo_2778(void)

{
  return menu_value_hi | menu_value_lo;
}


// ===== 0x002780 ui_get_menu_item_2780 =====

/* Auto: reads menu_item; 8 instr */

void ui_get_menu_item_2780(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_c18_tmp0_2b52(4);
  uVar1 = ui_get_TBLPTRL_2b68(menu_item);
  *(undefined1 *)in_FSR1 = uVar1;
  return;
}


// ===== 0x002790 ui_set_text_a =====

/* Load text pointer of word (id in W) into menu_text_a and redraw */

void ui_set_text_a(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  uVar1 = in_PRODL;
  uVar2 = in_PRODH;
  ui_word_ptr();
  menu_text_a_hi = uVar2;
  menu_text_a_lo = uVar1;
  ui_to_ui_get_cfg_systemconfig2_2c1c();
  return;
}


// ===== 0x00279e ui_to_menu_default_back_279e =====

/* Auto: calls menu_default_back; 2 instr */

void ui_to_menu_default_back_279e(void)

{
  ui_to_param_write_215a();
  menu_default_back();
  return;
}


// ===== 0x0027a4 ui_set_text_b =====

/* Load text pointer of word (id in W) into menu_text_b */

void ui_set_text_b(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  ui_word_ptr();
  menu_text_b_lo = in_PRODL;
  menu_text_b_hi = in_PRODH;
  return;
}


// ===== 0x0027b0 ui_draw_word =====

/* Draw UI word (id in W) via text_draw_word */

void ui_draw_word(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_word();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x0027bc screen_time_edit_setup =====

/* Install up/down callbacks for time editing */

void screen_time_edit_setup(void)

{
  ui_to_ui_draw_time_249e();
  menu_cb_up = 0x46;
  menu_cb_up_hi = 8;
  menu_cb_down = 0x38;
  menu_set_cbs_down_hi(8);
  return;
}


// ===== 0x0027d2 ui_set_menu_value_step_lo_27d2 =====

/* Auto: writes menu_value_step_lo,menu_value_step_hi; reads
   menu_value_max_hi,menu_value_max_lo,menu_value_step_hi,menu_value_step_lo; 19 instr */

char ui_set_menu_value_step_lo_27d2(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  short sVar2;
  char cVar3;
  
  uVar1 = ui_to_param_read_min_2b7a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9a) = uVar1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9b) = 0;
  menu_value_max_hi = *(char *)((ushort)unaff_BSR * 0x100 + 0x99) * '\n';
  sVar2 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x98) * 10;
  menu_value_max_lo = (undefined1)sVar2;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x99) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x99) + (char)((ushort)sVar2 >> 8);
  menu_value_step_hi = *(char *)((ushort)unaff_BSR * 0x100 + 0x9b) * '\n';
  sVar2 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x9a) * 10;
  menu_value_step_lo = (undefined1)sVar2;
  cVar3 = (char)((ushort)sVar2 >> 8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x9b) = *(char *)((ushort)unaff_BSR * 0x100 + 0x9b) + cVar3;
  *(undefined1 *)in_FSR1 = 0;
  return cVar3;
}


// ===== 0x002800 ui_stack_adjust_2800 =====

/* Auto: Software stack push/pop helper; 2 instr */

void ui_stack_adjust_2800(void)

{
  ui_to_ui_get_cfg_systemconfig2_2c1c();
  return;
}


// ===== 0x002806 menu_set_cbs_enter_hi_d =====

/* Store enter-callback high byte (variant) */

void menu_set_cbs_enter_hi_d(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0xdc;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0x1d;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xe2;
  menu_set_cbs_down_hi(0x1d);
  return;
}


// ===== 0x00281a ui_to_menu_set_cbs_noop_b_281a =====

/* Auto: calls menu_set_cbs_noop_b,menu_set_cbs_noop; 4 instr */

void ui_to_menu_set_cbs_noop_b_281a(void)

{
  ui_bank1_ui_set_menu_timer_lo_111c();
  menu_set_cbs_noop_b();
  menu_set_cbs_noop();
  return;
}


// ===== 0x002826 ui_to_menu_set_cbs_down_hi_2826 =====

/* Auto: writes menu_cb_enter,menu_cb_enter_hi,menu_cb_up,menu_cb_up_hi,menu_cb_down; calls
   menu_set_cbs_down_hi; 15 instr */

void ui_to_menu_set_cbs_down_hi_2826(void)

{
  byte unaff_BSR;
  
  ui_to_screen_cold_temp_bar_2684(c18_tmp0);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x94;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0xc;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0x9e;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0xc;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xa6;
  menu_set_cbs_down_hi(0xc);
  return;
}


// ===== 0x002846 menu_set_cbs_back_hi_b =====

/* Store back-callback high byte (variant) */

undefined1 menu_set_cbs_back_hi_b(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0xfa;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0x1b;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xfa;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0x1b;
  return 0x1b;
}


// ===== 0x00285a ui_set_cfg_systemconfig2_285a =====

/* Auto: writes cfg_systemconfig2; reads TABLAT,cfg_systemconfig2; 13 instr */

void ui_set_cfg_systemconfig2_285a(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte in_PRODL;
  undefined1 in_TABLAT;
  
  ui_get_menu_item_24ba();
  bVar1 = ui_frag_25a6(in_TABLAT);
  cfg_systemconfig2 = in_PRODL | cfg_systemconfig2 & bVar1;
  *(byte *)in_FSR1 = cfg_systemconfig2;
  ui_to_param_write_215a(0x2b);
  return;
}


// ===== 0x002874 ui_to_ui_draw_title_word_2874 =====

/* Auto: writes text_row; calls ui_draw_title_word; 6 instr */

void ui_to_ui_draw_title_word_2874(void)

{
  ui_draw_title_word();
  text_row = 4;
  ui_stack_adjust_2bdc(0x16);
  return;
}


// ===== 0x002882 ui_to_menu_set_cbs_down_hi_2882 =====

/* Auto: writes menu_cb_up,menu_cb_up_hi,menu_cb_down,menu_cb_enter,menu_cb_enter_hi; calls
   menu_set_cbs_down_hi; 13 instr */

undefined1 ui_to_menu_set_cbs_down_hi_2882(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0x94;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 7;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0x88;
  menu_set_cbs_down_hi(7);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xfe;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 7;
  return 7;
}


// ===== 0x00289c ui_to___divs16_289c =====

/* Auto: reads math_aarg_lo,math_aarg_hi; calls __divs16; 4 instr */

void ui_to___divs16_289c(void)

{
  __divs16();
  menu_value_lo = math_aarg_lo;
  menu_value_hi = math_aarg_hi;
  return;
}


// ===== 0x0028aa ui_to_ui_set_ui_wake_pending_28aa =====

/* Auto: Small wrapper around ui_set_ui_wake_pending; 4 instr */

void ui_to_ui_set_ui_wake_pending_28aa(char param_1)

{
  BADSPACEBASE *in_FSR2;
  
  ui_set_ui_wake_pending_244a((&FramePointer20x0001)[param_1] + '\x02');
  return;
}


// ===== 0x0028b4 ui_to_txt_set_ui_hold_counter_28b4 =====

/* Auto: Small wrapper around txt_set_ui_hold_counter; 4 instr */

void ui_to_txt_set_ui_hold_counter_28b4(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_set_ui_hold_counter_98fc();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x0028be ui_callw_lcd_write_data_28be =====

/* Auto: Push W as argument and call lcd_write_data; 4 instr */

void ui_callw_lcd_write_data_28be(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x0028c8 ui_to___divs16_28c8 =====

/* Auto: reads c18_tmp0,c18_tmp1,math_aarg_lo,math_aarg_hi; calls __divs16; 8 instr */

void ui_to___divs16_28c8(undefined1 param_1)

{
  math_barg_hi = 0;
  math_aarg_lo = c18_tmp0;
  math_aarg_hi = c18_tmp1;
  math_barg_lo = param_1;
  __divs16();
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  return;
}


// ===== 0x0028e2 ui_param_tboil_28e2 =====

/* Auto: reads params TBOIL; writes menu_value_step_lo,menu_value_step_hi; 9 instr */

void ui_param_tboil_28e2(undefined1 param_1)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9a) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9b) = 0;
  ui_callw_ui_to_eeprom_read_raw_228c(0x15);
  ui_get_menu_value_max_lo_2574();
  *(undefined1 *)in_FSR1 = 0x4b;
  ui_to_ui_draw_temp_value_2356(1);
  return;
}


// ===== 0x0028f6 ui_to_ui_get_menu_table_ptr_lo_28f6 =====

/* Auto: Small wrapper around ui_get_menu_table_ptr_lo; 3 instr */

void ui_to_ui_get_menu_table_ptr_lo_28f6(void)

{
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_c18_tmp2_2398(10);
  return;
}


// ===== 0x0028fe ui_to_progress_bar_scale_28fe =====

/* Auto: calls progress_bar_scale; 2 instr */

void ui_to_progress_bar_scale_28fe(void)

{
  ui_get_menu_value_lo_21ca();
  progress_bar_scale();
  return;
}


// ===== 0x002904 ui_to_stat_counter_save_2904 =====

/* Auto: calls stat_counter_save; 4 instr */

void ui_to_stat_counter_save_2904(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  stat_counter_save();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00290e ui_to_ui_get_menu_value_step_lo_290e =====

/* Auto: Small wrapper around ui_get_menu_value_step_lo; 8 instr */

void ui_to_ui_get_menu_value_step_lo_290e(undefined1 param_1)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),param_1);
  ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae(c18_tmp0);
  ui_get_menu_value_step_lo_2568();
  *puVar1 = 0x4b;
  ui_to_ui_draw_temp_value_2356(7);
  return;
}


// ===== 0x002922 ui_get_progress_bar_x_2922 =====

/* Auto: reads progress_bar_x,menu_value_step_lo,menu_value_max_lo,menu_value_max_hi; 12 instr */

char ui_get_progress_bar_x_2922(void)

{
  c18_tmp8 = progress_bar_x;
  c18_tmp9 = 0;
  c18_tmp6 = menu_value_max_lo - menu_value_step_lo;
  c18_tmp7 = (menu_value_max_hi - menu_value_step_hi) - ~(menu_value_step_lo <= menu_value_max_lo);
  return c18_tmp7;
}


// ===== 0x00293a ui_get_menu_value_min_lo_293a =====

/* Auto: reads menu_value_min_lo; 9 instr */

void ui_get_menu_value_min_lo_293a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0002;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar2 = puVar1 + -1;
  puVar1[-2] = 0xff;
  lcd_write_data();
  *puVar2 = *puVar2;
  return;
}


// ===== 0x002952 ui_to_ui_get_menu_value_hi_2952 =====

/* Auto: Small wrapper around ui_get_menu_value_hi; 3 instr */

void ui_to_ui_get_menu_value_hi_2952(void)

{
  ui_callw_ui_to_eeprom_read_raw_228c();
  ui_get_menu_value_hi_23d8(10);
  return;
}


// ===== 0x00295a ui_get_math_aarg_lo_295a =====

/* Auto: reads math_aarg_lo; 4 instr */

void ui_get_math_aarg_lo_295a(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_get_menu_value_lo_22aa(10);
  *(undefined1 *)in_FSR1 = math_aarg_lo;
  return;
}


// ===== 0x002964 ui_to_screen_time_edit_setup_b_2964 =====

/* Auto: calls screen_time_edit_setup_b; 5 instr */

void ui_to_screen_time_edit_setup_b_2964(void)

{
  ui_to_param_write_215a();
  ui_set_menu_value_lo_2bae(1);
  ui_to_ui_draw_time_249e();
  screen_time_edit_setup_b();
  return;
}


// ===== 0x002972 menu_set_cbs_back_hi =====

/* Store back-callback high byte and install defaults */

undefined1 menu_set_cbs_back_hi(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0x98;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0x98;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0;
  return 0;
}


// ===== 0x002986 ui_to_ui_draw_title_2986 =====

/* Auto: calls ui_draw_title,ui_draw_yes_no; 3 instr */

void ui_to_ui_draw_title_2986(void)

{
  ui_draw_title();
  ui_draw_yes_no();
  ui_set_menu_edit_mode_2498();
  return;
}


// ===== 0x002992 ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992 =====

/* Auto: Calls ui_get_TBLPTRL, ui_to_ui_draw_set_hint; 2 instr */

void ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992(void)

{
  ui_get_TBLPTRL_22ba();
  ui_to_ui_draw_set_hint_2b86();
  return;
}


// ===== 0x002996 ui_to_text_draw_word_2996 =====

/* Auto: calls text_draw_word,ui_draw_yes_no; 4 instr */

void ui_to_text_draw_word_2996(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_word();
  *puVar1 = *puVar1;
  ui_draw_yes_no();
  return;
}


// ===== 0x0029a2 ui_get_c18_tmp0_29a2 =====

/* Auto: reads c18_tmp0,c18_tmp1; 3 instr */

void ui_get_c18_tmp0_29a2(void)

{
  return;
}


// ===== 0x0029ac ui_to_lcd_clear_29ac =====

/* Auto: calls lcd_clear,ui_draw_title; 6 instr */

void ui_to_lcd_clear_29ac(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_c18_prologue_2166();
  lcd_clear();
  ui_frame_push_args_25cc();
  ui_draw_title();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x0029be ui_draw_flushing =====

/* "FLUSHING" */

void ui_draw_flushing(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_word_filter_233c();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word_push6(0x55);
  ui_draw_press_any_key_to_stop();
  return;
}


// ===== 0x0029cc ui_to_ui_get_menu_table_ptr_lo_29cc =====

/* Auto: Small wrapper around ui_get_menu_table_ptr_lo; 4 instr */

void ui_to_ui_get_menu_table_ptr_lo_29cc(void)

{
  ui_to_ui_get_c18_tmp0_22cc();
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_c18_tmp2_2398(4);
  return;
}


// ===== 0x0029d6 ui_get_c18_tmp0_29d6 =====

/* Auto: reads c18_tmp0,TABLAT,c18_tmp1; 7 instr */

byte ui_get_c18_tmp0_29d6(void)

{
  byte *in_TBLPTR;
  
  c18_tmp0 = *in_TBLPTR;
  c18_tmp1 = in_TBLPTR[1];
  return in_TBLPTR[1] | *in_TBLPTR;
}


// ===== 0x0029e8 ui_get_TBLPTRL_29e8 =====

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 9 instr */

undefined1 ui_get_TBLPTRL_29e8(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp3 + CARRY1(c18_tmp2,param_1),c18_tmp2 + param_1));
}


// ===== 0x0029fa ui_set_menu_cb_up_29fa =====

/* Auto: writes menu_cb_up,menu_cb_up_hi,menu_cb_down,menu_cb_down_hi; 6 instr */

void ui_set_menu_cb_up_29fa(void)

{
  byte unaff_BSR;
  
  ui_set_menu_cb_enter_2c0a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0;
  return;
}


// ===== 0x002a06 ui_set_menu_mode_2a06 =====

/* Auto: writes menu_mode; 4 instr */

void ui_set_menu_mode_2a06(void)

{
  ui_to_lcd_clear_21fc();
  menu_mode = 0;
  return;
}


// ===== 0x002a10 ui_callw_mod_set_lcd_delay_counter_2a10 =====

/* Auto: Push W as argument and call mod_set_lcd_delay_counter; 5 instr */

void ui_callw_mod_set_lcd_delay_counter_2a10(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002a1c ui_to_ui_draw_title_word_2a1c =====

/* Auto: calls ui_draw_title_word; 1 instr */

void ui_to_ui_draw_title_word_2a1c(void)

{
  ui_draw_title_word();
  return;
}


// ===== 0x002a20 ui_to_ui_set_ui_wake_pending_2a20 =====

/* Auto: Small wrapper around ui_set_ui_wake_pending; 3 instr */

void ui_to_ui_set_ui_wake_pending_2a20(void)

{
  ui_set_ui_wake_pending_244a(2);
  return;
}


// ===== 0x002a28 ui_get_cfg_systemconfig3_2a28 =====

/* Auto: reads cfg_systemconfig3,menu_edit_mode; 6 instr */

undefined1 ui_get_cfg_systemconfig3_2a28(void)

{
  ui_to_param_write_215a(0x2c);
  return menu_edit_mode;
}


// ===== 0x002a38 screen_replacement_counter =====

/* Replacement counter screen ("TIME TO NEXT REPLACEMENT") */

undefined1 screen_replacement_counter(void)

{
  menu_replacement_on_up_b();
  menu_cb_enter = 0x42;
  menu_cb_enter_hi = 0xf;
  return 0xf;
}


// ===== 0x002a48 menu_set_cbs_updown_default =====

/* Install default up/down callbacks */

undefined1 menu_set_cbs_updown_default(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0xf2;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0xd;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xf2;
  return 0xd;
}


// ===== 0x002a58 ui_to_system_wake_2a58 =====

/* Auto: calls system_wake; 3 instr */

void ui_to_system_wake_2a58(void)

{
  ui_to_lcd_clear_21fc();
  system_wake();
  ui_to_heating_start_task_3470();
  return;
}


// ===== 0x002a64 ui_get_menu_table_ptr_lo_2a64 =====

/* Auto: reads menu_table_ptr_lo,TABLAT,menu_table_ptr_hi; 5 instr */

void ui_get_menu_table_ptr_lo_2a64(void)

{
  undefined1 *in_TBLPTR;
  
  menu_table_ptr_lo = *in_TBLPTR;
  menu_table_ptr_hi = in_TBLPTR[1];
  return;
}


// ===== 0x002a72 ui_word_put_2_liter_jug_x0aunder_the_2a72 =====

/* Auto: shows "PUT 2 LITER JUG\x0aUNDER THE SPOUT"; calls ui_draw_press_ok_when_ready; 6 instr */

void ui_word_put_2_liter_jug_x0aunder_the_2a72(void)

{
  ui_draw_press_ok_when_ready(0x68);
  return;
}


// ===== 0x002a7e ui_to_menu_set_cbs_noop_b_2a7e =====

/* Auto: writes menu_cb_key,menu_cb_key_hi; calls menu_set_cbs_noop_b,menu_set_cbs_noop; 5 instr */

void ui_to_menu_set_cbs_noop_b_2a7e(void)

{
  byte unaff_BSR;
  
  menu_set_cbs_noop_b();
  menu_set_cbs_noop();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3c) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3d) = 0;
  return;
}


// ===== 0x002a8a menu_clear_cbs =====

/* Store back high byte and clear other callbacks */

void menu_clear_cbs(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0;
  return;
}


// ===== 0x002a96 ui_to_ui_word_installation_2a96 =====

/* Auto: Small wrapper around ui_word_installation; 5 instr */

undefined1 ui_to_ui_word_installation_2a96(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_c18_prologue_2166();
  ui_word_installation_2370();
  return *(undefined1 *)((short)in_FSR2 + -2);
}


// ===== 0x002aa2 ui_get_menu_tmp_a_2aa2 =====

/* Auto: reads menu_tmp_a; 3 instr */

void ui_get_menu_tmp_a_2aa2(void)

{
  ui_get_menu_item_2554();
  return;
}


// ===== 0x002aae ui_set_ui_wake_pending_2aae =====

/* Auto: writes ui_wake_pending,text_x; 5 instr */

void ui_set_ui_wake_pending_2aae(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 3) = param_1;
  text_x = 0xf;
  ui_to_ui_get_cfg_systemconfig2_2334();
  return;
}


// ===== 0x002aba ui_stack_adjust_2aba =====

/* Auto: Software stack push/pop helper; 5 instr */

void ui_stack_adjust_2aba(void)

{
  ui_callw_fncfc6_238c(5);
  return;
}


// ===== 0x002ac6 ui_chain_fn21f4_ui_set_menu_value__2ac6 =====

/* Auto: Calls 0x21f4, ui_set_menu_value_lo; 2 instr */

void ui_chain_fn21f4_ui_set_menu_value__2ac6(void)

{
  ui_stack_adjust_21f4();
  ui_set_menu_value_lo_26a6();
  return;
}


// ===== 0x002ace ui_get_menu_value_lo_2ace =====

/* Auto: reads menu_value_lo,menu_value_hi; 3 instr */

void ui_get_menu_value_lo_2ace(void)

{
  return;
}


// ===== 0x002ad8 menu_set_cbs_enter_hi_e =====

/* Store enter high byte then defaults */

void menu_set_cbs_enter_hi_e(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  menu_set_cbs_noop();
  return;
}


// ===== 0x002ade ui_set_menu_timer_lo_2ade =====

/* Auto: writes menu_timer_lo,menu_timer_hi; 5 instr */

undefined1 ui_set_menu_timer_lo_2ade(void)

{
  menu_timer_lo = 3;
  menu_timer_hi = 0;
  return 3;
}


// ===== 0x002ae8 ui_to_lcd_clear_2ae8 =====

/* Auto: writes menu_edit_mode; calls lcd_clear; 3 instr */

void ui_to_lcd_clear_2ae8(undefined1 param_1)

{
  menu_edit_mode = param_1;
  lcd_clear();
  return;
}


// ===== 0x002af0 ui_to_screen_temp_sensor_values_2af0 =====

/* Auto: calls screen_temp_sensor_values; 3 instr */

void ui_to_screen_temp_sensor_values_2af0(void)

{
  screen_temp_sensor_values();
  return;
}


// ===== 0x002af8 ui_stack_adjust_2af8 =====

/* Auto: Software stack push/pop helper; 3 instr */

void ui_stack_adjust_2af8(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_c18_prologue_2166();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x002b00 ui_to_eeprom_read_raw_2b00 =====

/* Auto: calls eeprom_read_raw; 3 instr */

void ui_to_eeprom_read_raw_2b00(void)

{
  BADSPACEBASE *in_FSR1;
  
  eeprom_read_raw();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x002b08 ui_set_text_row_2b08 =====

/* Auto: writes text_row; 4 instr */

undefined1 ui_set_text_row_2b08(void)

{
  text_row = 3;
  return 3;
}


// ===== 0x002b10 ui_callw_txt_set_ui_hold_counter_2b10 =====

/* Auto: Push W as argument and call txt_set_ui_hold_counter; 2 instr */

void ui_callw_txt_set_ui_hold_counter_2b10(void)

{
  txt_set_ui_hold_counter_9914();
  return;
}


// ===== 0x002b16 ui_frag_2b16 =====

/* Auto: compiler fragment: CALL 0x002166,0x0 ; MOVLW #0xfd ; RETURN 0x0 */

undefined1 ui_frag_2b16(void)

{
  ui_c18_prologue_2166();
  return 0xfd;
}


// ===== 0x002b1e ui_compare_multibyte_2b1e =====

/* Auto: compiler fragment: MOVWF 0x0014,ACCESS ; MOVLW #0x5 ; SUBWF FSR1L,w,ACCESS ; RETURN 0x0 */

char ui_compare_multibyte_2b1e(undefined1 param_1)

{
  char in_FSR1L;
  
  c18_tmp0 = param_1;
  return in_FSR1L + -5;
}


// ===== 0x002b26 ui_stack_adjust_2b26 =====

/* Auto: Software stack push/pop helper; 4 instr */

byte ui_stack_adjust_2b26(byte param_1)

{
  return param_1 | 4;
}


// ===== 0x002b2e ui_get_cfg_systemconfig2_2b2e =====

/* Auto: reads cfg_systemconfig2; 7 instr */

byte ui_get_cfg_systemconfig2_2b2e(void)

{
  return (cfg_systemconfig2 & 0x38) >> 3;
}


// ===== 0x002b3c ui_get_menu_table_ptr_lo_2b3c =====

/* Auto: reads menu_table_ptr_lo,TBLPTRL,menu_table_ptr_hi,TBLPTRH; 3 instr */

void ui_get_menu_table_ptr_lo_2b3c(void)

{
  return;
}


// ===== 0x002b46 ui_draw_on_off =====

/* Draw ON/OFF choice */

void ui_draw_on_off(void)

{
  ui_stack_adjust_2800();
  ui_set_text_a(0x44);
  ui_set_text_b(0x45);
  return;
}


// ===== 0x002b52 ui_get_c18_tmp0_2b52 =====

/* Auto: reads c18_tmp0,TBLPTRL,c18_tmp1,TBLPTRH; 4 instr */

void ui_get_c18_tmp0_2b52(void)

{
  undefined1 in_TBLPTRL;
  undefined1 in_TBLPTRH;
  
  ui_get_TBLPTRL_2c14();
  c18_tmp0 = in_TBLPTRL;
  c18_tmp1 = in_TBLPTRH;
  return;
}


// ===== 0x002b5e ui_callw_fn0450_2b5e =====

/* Auto: Push W as argument and call 0x450; 4 instr */

void ui_callw_fn0450_2b5e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_chain_ui_to_lcd_clear_fn21d8_0450();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x002b68 ui_get_TBLPTRL_2b68 =====

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 9 instr */

undefined1 ui_get_TBLPTRL_2b68(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,param_1),c18_tmp0 + param_1));
}


// ===== 0x002b7a ui_to_param_read_min_2b7a =====

/* Auto: calls param_read_min; 5 instr */

void ui_to_param_read_min_2b7a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  param_read_min();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x002b86 ui_to_ui_draw_set_hint_2b86 =====

/* Auto: calls ui_draw_set_hint; 4 instr */

void ui_to_ui_draw_set_hint_2b86(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_draw_set_hint();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x002b90 ui_word_ptr =====

/* Return pointer to UI word in current language */

void ui_word_ptr(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  word_lookup_a();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x002b9c ui_pop3_return_2b9c =====

/* Auto: Drop stack arguments and return; 4 instr */

void ui_pop3_return_2b9c(void)

{
  return;
}


// ===== 0x002ba4 ui_draw_title_word =====

/* Draw title word (id in W) */

void ui_draw_title_word(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_draw_title();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x002bae ui_set_menu_value_lo_2bae =====

/* Auto: writes menu_value_lo,menu_value_hi; 4 instr */

void ui_set_menu_value_lo_2bae(undefined1 param_1)

{
  menu_value_lo = param_1;
  menu_value_hi = 0;
  return;
}


// ===== 0x002bb6 screen_wakeup1_edit_hour =====

/* Wake up 1: edit hour */

undefined1 screen_wakeup1_edit_hour(void)

{
  byte unaff_BSR;
  
  screen_time_edit_setup();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x7a;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}


// ===== 0x002bc2 screen_wakeup2_edit_hour =====

/* Wake up 2: edit hour */

undefined1 screen_wakeup2_edit_hour(void)

{
  byte unaff_BSR;
  
  screen_time_edit_setup();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xfa;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}


// ===== 0x002bce ui_to_screen_mix_temp_bar_2bce =====

/* Auto: calls screen_mix_temp_bar; 5 instr */

void ui_to_screen_mix_temp_bar_2bce(void)

{
  ui_to_ui_get_menu_value_hi_2952();
  screen_mix_temp_bar();
  ui_to_ui_to_ui_draw_temp_units_1df4();
  return;
}


// ===== 0x002bdc ui_stack_adjust_2bdc =====

/* Auto: Software stack push/pop helper; 6 instr */

void ui_stack_adjust_2bdc(void)

{
  ui_stack_adjust_21f4(100);
  return;
}


// ===== 0x002bea ui_chain_fn2b16_fn28aa_ui_get_menu_item_2bea =====

/* Auto: Calls 0x2b16, 0x28aa, ui_get_menu_item; 3 instr */

void ui_chain_fn2b16_fn28aa_ui_get_menu_item_2bea(void)

{
  ui_frag_2b16();
  ui_to_ui_set_ui_wake_pending_28aa();
  ui_get_menu_item_2554();
  return;
}


// ===== 0x002bf2 ui_to_lcd_clear_2bf2 =====

/* Auto: calls lcd_clear; 2 instr */

void ui_to_lcd_clear_2bf2(void)

{
  lcd_clear();
  ui_get_menu_item_2780();
  return;
}


// ===== 0x002bfa ui_get_cfg_systemconfig3_2bfa =====

/* Auto: reads cfg_systemconfig3; 3 instr */

void ui_get_cfg_systemconfig3_2bfa(void)

{
  ui_to_menu_default_back_279e(0x2c);
  return;
}


// ===== 0x002c02 ui_get_cfg_systemconfig5_2c02 =====

/* Auto: reads cfg_systemconfig5; 3 instr */

void ui_get_cfg_systemconfig5_2c02(void)

{
  ui_to_menu_default_back_279e(0x41);
  return;
}


// ===== 0x002c0a ui_set_menu_cb_enter_2c0a =====

/* Auto: writes menu_cb_enter,menu_cb_enter_hi,menu_cb_back,menu_cb_back_hi; 5 instr */

void ui_set_menu_cb_enter_2c0a(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0;
  return;
}


// ===== 0x002c14 ui_get_TBLPTRL_2c14 =====

/* Auto: reads TBLPTRL,TBLPTRH; 4 instr */

undefined1 ui_get_TBLPTRL_2c14(void)

{
  return 0;
}


// ===== 0x002c1c ui_to_ui_get_cfg_systemconfig2_2c1c =====

/* Auto: Small wrapper around ui_get_cfg_systemconfig2; 3 instr */

void ui_to_ui_get_cfg_systemconfig2_2c1c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = ui_get_cfg_systemconfig2_2b2e();
  *(undefined1 *)in_FSR1 = uVar1;
  return;
}


// ===== 0x002c22 task_ui =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 2 task: keypad debounce, key press/release dispatch, buzzer, screen refresh */

void task_ui(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  lcd_clear();
  if ((cfg_systemconfig4 & 1) == 0) {
    clock_draw();
    ui_screen = 0;
    if ((cfg_systemconfig5 & 0x80) == 0) {
      ui_get_PORTH_4f12();
    }
    else {
      bVar3 = PORTH;
      PORTH = bVar3 | RH7;
      bVar3 = PORTB;
      PORTB = bVar3 | RB0;
      bVar3 = PORTB;
      PORTB = bVar3 & ~RB1;
      bVar3 = PORTC;
      PORTC = bVar3 | RC0;
    }
    bVar3 = PORTC;
    PORTC = bVar3 & ~RC1;
  }
  else {
    ui_screen = 0x1e;
  }
  ui_return_screen = ui_screen;
  key_cold_hold_lo = 0xff;
  key_cold_hold_hi = 0xff;
  key_hot_hold_lo = 0;
  key_hot_hold_hi = 0;
  if ((cfg_systemconfig4 & 0x40) != 0) {
    cfg_systemconfig3 = cfg_systemconfig3 & 0x4f;
  }
  do {
    bVar3 = ui_to_ui_to_eeprom_read_param_4efc(1);
    if (ui_refresh_timer < bVar3) {
      ui_refresh_timer = 0;
    }
    else {
      ui_refresh_timer = ui_refresh_timer - local0;
    }
    *(undefined1 *)in_FSR1 = 0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = local0;
    OSDelay();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    puVar1[-1] = puVar1[-1];
    adc_raw_lo = 1;
    OS_Yield();
    bVar3 = keypad_scan();
    local0 = bVar3 & 0x7f;
    if ((keys_current ^ local0) != 0) {
      ui_param_dbnccntr_4eb2(keys_current ^ local0);
      while (keys_changed != 0) {
        bVar3 = keypad_scan(keys_changed);
        bVar3 = bVar3 & 0x7f ^ local0;
        if (bVar3 == 0) {
          keys_changed = keys_changed - 1;
        }
        else {
          ui_param_dbnccntr_4eb2(bVar3);
        }
        bVar3 = keypad_scan();
        keys_sample = bVar3 & 0x7f;
        *(undefined1 *)in_FSR1 = 0;
        puVar2 = (undefined1 *)((short)in_FSR1 + 2);
        *(undefined1 *)((short)in_FSR1 + 1) = 1;
        OSDelay();
        *puVar2 = *puVar2;
        in_FSR1 = (BADSPACEBASE *)(puVar2 + -2);
        puVar2[-1] = puVar2[-1];
        adc_raw_lo = 0x12;
        OS_Yield();
        local0 = keys_sample;
      }
      keys_changed = keys_current ^ local0;
      keys_current = local0;
      local1 = local0 & keys_changed;
      local2 = keys_changed & ~local0;
      if (local1 != 0) {
        ui_on_key_press(local1);
        ui_get_PORTH_4f04();
        ui_backlight_timeout = 0x78;
      }
      if (local2 != 0) {
        ui_on_key_release(local2);
      }
    }
    if ((buzzer_pattern & 0x80) == 0) {
      bVar3 = PORTB;
      PORTB = bVar3 & ~RB3;
    }
    else {
      bVar3 = PORTB;
      PORTB = bVar3 | RB3;
    }
    bVar3 = ui_refresh_timer;
    if (ui_refresh_timer == 0) {
      ui_refresh_timer = ui_to_eeprom_read_param_4f64(0x24);
      buzzer_pattern = buzzer_pattern << 1;
      bVar3 = ui_refresh_screen();
    }
    ui_update(bVar3);
  } while( true );
}


// ===== 0x002d3c ui_hot_side_ok =====

/* Return 1 if no hot-side faults (heating, hot valve, inlet, heater) */

undefined1 ui_hot_side_ok(void)

{
  local0 = heating_fault | hot_valve_fault | inlet_valve_fault | heater_fault;
  if ((char)local0 < '\0') {
    return 0;
  }
  return 1;
}


// ===== 0x002d56 ui_cold_side_ok =====

/* Check cold-side faults (cooling, alarm, cold valve, inlet, compressor) */

void ui_cold_side_ok(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  local0 = cooling_fault | uv_alarm_code | cold_valve_fault | inlet_valve_fault;
  if (*(char *)((short)in_FSR2 + -2) != '\0') {
    local0 = local0 | compressor_fault;
  }
  ui_c18_epilogue_4d6e(-1 < (char)local0);
  return;
}


// ===== 0x002d86 ui_on_key_press =====

/* WARNING: Removing unreachable block (CODE,0x00307e) */
/* WARNING: Removing unreachable block (CODE,0x003084) */
/* WARNING: Removing unreachable block (CODE,0x00308a) */
/* WARNING: Removing unreachable block (CODE,0x003092) */
/* WARNING: Removing unreachable block (CODE,0x003098) */
/* WARNING: Removing unreachable block (CODE,0x0030a0) */
/* WARNING: Removing unreachable block (CODE,0x0030a4) */
/* WARNING: Removing unreachable block (CODE,0x0030aa) */
/* WARNING: Removing unreachable block (CODE,0x0030b2) */
/* WARNING: Removing unreachable block (CODE,0x0030ba) */
/* WARNING: Removing unreachable block (CODE,0x0030bc) */
/* WARNING: Removing unreachable block (CODE,0x0030c2) */
/* WARNING: Removing unreachable block (CODE,0x0030c8) */
/* WARNING: Removing unreachable block (CODE,0x0030ce) */
/* WARNING: Removing unreachable block (CODE,0x0030d6) */
/* WARNING: Removing unreachable block (CODE,0x0030dc) */
/* WARNING: Removing unreachable block (CODE,0x0030e2) */
/* WARNING: Removing unreachable block (CODE,0x00300e) */
/* WARNING: Removing unreachable block (CODE,0x00301a) */
/* WARNING: Removing unreachable block (CODE,0x00304a) */
/* WARNING: Removing unreachable block (CODE,0x003050) */
/* WARNING: Removing unreachable block (CODE,0x003056) */
/* WARNING: Removing unreachable block (CODE,0x00305c) */
/* WARNING: Removing unreachable block (CODE,0x00305e) */
/* WARNING: Removing unreachable block (CODE,0x00306a) */
/* WARNING: Removing unreachable block (CODE,0x003064) */
/* WARNING: Removing unreachable block (CODE,0x003022) */
/* WARNING: Removing unreachable block (CODE,0x00302c) */
/* WARNING: Removing unreachable block (CODE,0x00302e) */
/* WARNING: Removing unreachable block (CODE,0x003034) */
/* WARNING: Removing unreachable block (CODE,0x00303a) */
/* WARNING: Removing unreachable block (CODE,0x003040) */
/* WARNING: Removing unreachable block (CODE,0x003042) */
/* WARNING: Removing unreachable block (CODE,0x002f94) */
/* WARNING: Removing unreachable block (CODE,0x002f9c) */
/* WARNING: Removing unreachable block (CODE,0x002f9e) */
/* WARNING: Removing unreachable block (CODE,0x002fa4) */
/* WARNING: Removing unreachable block (CODE,0x002faa) */
/* WARNING: Removing unreachable block (CODE,0x002fb0) */
/* WARNING: Removing unreachable block (CODE,0x002fb2) */
/* WARNING: Removing unreachable block (CODE,0x002fd0) */
/* WARNING: Removing unreachable block (CODE,0x002fb8) */
/* WARNING: Removing unreachable block (CODE,0x002fc2) */
/* WARNING: Removing unreachable block (CODE,0x002fc0) */
/* WARNING: Removing unreachable block (CODE,0x0030fa) */
/* WARNING: Removing unreachable block (CODE,0x003106) */
/* WARNING: Removing unreachable block (CODE,0x00310e) */
/* WARNING: Removing unreachable block (CODE,0x003110) */
/* WARNING: Removing unreachable block (CODE,0x003116) */
/* WARNING: Removing unreachable block (CODE,0x003118) */
/* WARNING: Removing unreachable block (CODE,0x00311e) */
/* WARNING: Removing unreachable block (CODE,0x003120) */
/* WARNING: Removing unreachable block (CODE,0x003128) */
/* WARNING: Removing unreachable block (CODE,0x00312a) */
/* WARNING: Removing unreachable block (CODE,0x003132) */
/* WARNING: Removing unreachable block (CODE,0x003134) */
/* WARNING: Removing unreachable block (CODE,0x00315c) */
/* WARNING: Removing unreachable block (CODE,0x00316e) */
/* WARNING: Removing unreachable block (CODE,0x003162) */
/* WARNING: Removing unreachable block (CODE,0x002df4) */
/* WARNING: Removing unreachable block (CODE,0x002dfa) */
/* WARNING: Removing unreachable block (CODE,0x002e4a) */
/* WARNING: Removing unreachable block (CODE,0x002e50) */
/* WARNING: Removing unreachable block (CODE,0x002e56) */
/* WARNING: Removing unreachable block (CODE,0x002e5c) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Handle newly pressed keys: fault clearing, menu entry, cup/jug dispensing */

byte ui_on_key_press(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  byte bVar6;
  undefined1 uVar7;
  
  if (((cfg_systemconfig & 0x80) != 0) || (keys_changed == '\0')) {
    puVar1 = &FramePointer10x0001;
    ui_get_buzzer_pattern_4850();
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -1);
    *puVar1 = *puVar1;
  }
  if ((local1 & 0xe) != 0) {
    if (((((heating_fault == -0x74) || (heating_fault == -0x76)) || (heating_fault == -0x73)) ||
        ((heating_fault == -0x72 || (heating_fault == -0x71)))) || (heating_fault == -0x77)) {
      heating_fault = '\0';
      heater_fault = '\0';
      ui_set_heater_output_enable_4f1c(0);
    }
    if (heater_fault == -0x7c) {
      puVar2 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0;
      heater_set_fault(0);
      in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
      *puVar2 = *puVar2;
      ui_set_heater_output_enable_4f1c();
    }
    cVar5 = ui_hot_side_ok();
    if (cVar5 == '\0') {
      ui_get_ui_screen_4ee4();
    }
  }
  if ((local1 & 0x19) != 0) {
    if (((cooling_fault == -0x74) || (cooling_fault == -0x76)) ||
       ((cooling_fault == -0x73 || ((cooling_fault == -0x71 || (cooling_fault == -0x77)))))) {
      cooling_fault = '\0';
      puVar3 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0;
      compressor_set_fault(0);
      in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
      *puVar3 = *puVar3;
      compressor_output_enable = 1;
      bVar6 = TRISG;
      TRISG = bVar6 & ~TRISG3;
    }
    puVar4 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0;
    cVar5 = ui_cold_side_ok();
    *puVar4 = *puVar4;
    if (cVar5 == '\0') {
      ui_get_ui_screen_4ee4();
    }
    if ((compressor_fault != 0x84) && ((char)compressor_fault < '\0')) {
      ui_to_ui_get_buzzer_pattern_4e32(compressor_fault << 1 | 0x83 < compressor_fault);
      local1 = local1 & 0xe6;
    }
  }
  if ((ui_screen == '\v') && (ui_hold_counter != '\0')) {
    return -ui_hold_counter;
  }
  if (ui_screen == '\x11') {
    return 0;
  }
  if ((((ui_screen == '\t') || (ui_screen == '\r')) || (ui_screen == '\x13')) ||
     (ui_screen == '\x0f')) {
    ui_screen = '\n';
    bVar6 = dispense_stop_all();
    return bVar6;
  }
  if ((ui_menu_active == '\0') &&
     ((((((ui_screen == '\0' || (ui_screen == '\x01')) ||
         ((ui_screen == '\x1b' || ((ui_screen == '\x1c' || (ui_screen == '\x1d')))))) ||
        (ui_screen == '\x14')) ||
       (((ui_screen == '\x1f' || (ui_screen == '\x02')) || (ui_screen == '\x03')))) &&
      (local1 == 0x20)))) {
    uVar7 = 0;
    if (ui_screen != '\x1f') {
      if (ui_screen + -0x14 != '\0') {
        ui_return_screen = ui_screen;
        ui_to_clock_display_off_4e84(ui_screen + -0x14);
      }
      uVar7 = 0x3c;
      ui_screen_timeout = 0x3c;
    }
    cVar5 = menu_enter(uVar7);
    bVar6 = 0x80 - cVar5;
    if (bVar6 == 0) {
      cVar5 = system_get_mode();
      if (cVar5 == '\x02') {
        bVar6 = 0;
      }
      else {
        bVar6 = ui_screen - 0x1f;
        if (bVar6 != 0) {
          ui_screen = '\0';
          return bVar6;
        }
        bVar6 = 0;
      }
    }
  }
  else {
    if ((ui_screen == '\x14') || (ui_screen == '\x1f')) {
      if ((local1 & 1) != 0) {
        menu_key_up(0);
        ui_screen_timeout = 0x3c;
        return 0x3c;
      }
      if ((local1 & 0x10) != 0) {
        menu_key_down();
        ui_screen_timeout = 0x3c;
        return 0x3c;
      }
      if (local1 - 0x40 == '\0') {
        cVar5 = menu_key_back();
        if (cVar5 == '\0') {
          ui_select_home_screen();
        }
      }
      else {
        menu_key_other(local1 - 0x40);
      }
      ui_screen_timeout = 0x3c;
    }
    if ((((ui_screen == '\0') || (ui_screen == '\x01')) ||
        ((ui_screen == '\x1b' || ((ui_screen == '\x1c' || (ui_screen == '\x1d')))))) &&
       (local1 == 2)) {
      ser_test_value_50a4(0);
      bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
      return bVar6;
    }
    if (((((((ui_screen == '\0') || (ui_screen == '\x01')) || (ui_screen == '\x02')) ||
          ((ui_screen == '\x03' || (ui_screen == '\x1b')))) || (ui_screen == '\x1c')) ||
        (ui_screen == '\x1d')) && (local1 == 8)) {
      ser_test_value_50a4(0);
      bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
      return bVar6;
    }
    if (local1 == 1) {
      ui_get_ui_screen_4ee4(0);
    }
    if (local1 == 4) {
      ser_test_value_50a4(0);
      bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
      return bVar6;
    }
    if (((((ui_screen == '\0') || (ui_screen == '\x01')) ||
         ((ui_screen == '\x02' ||
          (((ui_screen == '\x03' || (ui_screen == '\x1b')) || (ui_screen == '\x1c')))))) ||
        (ui_screen == '\x1d')) && (local1 == 0x10)) {
      bVar6 = ui_bank1_ui_get_cfg_systemconfig5_4c34(0);
      if (bVar6 == 1) {
        bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
        return bVar6;
      }
      local0 = dispense_cold_cup();
      bVar6 = local0 << 1 | bVar6 < 2;
      if (local0 < '\0') {
        return bVar6;
      }
      ui_get_ui_screen_4f38(bVar6);
      if ((bVar6 == 0) || (ui_screen == '\x1c')) {
        ui_return_screen = '\x1b';
      }
      else {
        ui_return_screen = '\0';
      }
      ui_set_ui_screen_4e10(8);
    }
    bVar6 = 0;
    if ((((cfg_systemconfig5 & 2) != 0) && (bVar6 = ui_screen - 7, bVar6 == 0)) &&
       (bVar6 = local1 - 0x10, bVar6 == 0)) {
      bVar6 = ui_bank1_ui_get_cfg_systemconfig5_4c34(0);
      if (bVar6 == 1) {
        bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
        return bVar6;
      }
      local0 = dispense_jug();
      bVar6 = local0 << 1 | bVar6 < 2;
      if (local0 < '\0') {
        return bVar6;
      }
      ui_get_ui_screen_4f38(bVar6);
      if ((bVar6 == 0) || (ui_screen == '\x1c')) {
        ui_return_screen = '\x1b';
      }
      else {
        ui_return_screen = '\0';
      }
      bVar6 = ui_set_ui_screen_4e10(0xe);
    }
    if (((local1 & 0x40) != 0) && (bVar6 = 0, ui_menu_active != '\0')) {
      ui_menu_active = '\0';
      ui_menu_param = 0;
      cfg_systemconfig4 = ui_to_eeprom_read_param_4f64(0x3a);
      lcd_clear();
      bVar6 = ui_select_home_screen();
    }
  }
  return bVar6;
}


// ===== 0x00323c ui_on_key_release =====

/* Handle released keys */

byte ui_on_key_release(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  
  cVar1 = ui_get_menu_flag_033c();
  if ((cVar1 != '\0') && ((local2 & 0x20) != 0)) {
    fn_2220_on_aux();
  }
  if ((ui_screen == '\v') && (ui_hold_counter != '\0')) {
    return -ui_hold_counter;
  }
  if (ui_screen == '\x14') {
    return 0;
  }
  if (ui_screen == '\x1f') {
    return 0;
  }
  bVar3 = ui_screen - 0x11;
  if ((bVar3 == 0) && (bVar3 = local2 & 2, bVar3 == 0)) {
    return 0;
  }
  if (((((local2 & 1) != 0) && (bVar3 = ~key_cold_hold_lo, bVar3 == 0)) &&
      (bVar3 = ~key_cold_hold_hi, bVar3 == 0)) &&
     (((bVar3 = 0, ui_screen != '\r' && (bVar3 = 0, ui_screen != '\f')) &&
      (bVar3 = 0, ui_screen != '\x0f')))) {
    bVar3 = 0;
    if (ui_screen + -0xe != '\0') {
      bVar3 = dispense_stop_all(ui_screen + -0xe);
    }
  }
  if ((local2 & 2) != 0) {
    if ((ui_screen == '\x11') || (ui_screen == '\x10')) {
      cVar1 = '\0';
      if ((cfg_systemconfig5 & 4) != 0) {
        cVar2 = ui_to_eeprom_read_param_4f64(0x42);
        cVar1 = -cVar2;
        if ((cVar2 != '\0') && (cVar1 = '\0', key_hot_hold_hi != '\0' || key_hot_hold_lo != '\0')) {
          key_hot_hold_lo = '\0';
          key_hot_hold_hi = '\0';
          dispense_hot_cup();
          bVar3 = ui_set_ui_screen_4e10(0x12);
          goto LAB_CODE_0032f4;
        }
      }
      bVar3 = dispense_stop_all(cVar1);
    }
    else if ((ui_screen == '\x15') || (bVar3 = ui_screen - 0x17, bVar3 == 0)) {
      bVar3 = 0x18;
      ui_screen = '\x18';
    }
  }
LAB_CODE_0032f4:
  if (((local2 & 8) != 0) && ((ui_screen == '\x16' || (bVar3 = ui_screen - 0x17, bVar3 == 0)))) {
    bVar3 = 0x18;
    ui_screen = '\x18';
  }
  if ((((local2 & 0x40) != 0) && (bVar3 = 0, ui_menu_param != '\0')) &&
     (bVar3 = -ui_menu_param, ui_menu_param != '\0')) {
    ui_menu_param = '\0';
  }
  return bVar3;
}


// ===== 0x00331e ui_update =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Periodic screen/LED update from the UI task loop */

byte ui_update(void)

{
  byte bVar1;
  byte unaff_BSR;
  byte bVar2;
  char cVar3;
  byte unaff_Z;
  
  bVar2 = ui_get_ui_screen_4ee4();
  if ((unaff_Z & 1) == 0) {
    if (*(char *)((ushort)unaff_BSR * 0x100) == '\x1f') {
      return 0;
    }
    if (((*(char *)((ushort)unaff_BSR * 0x100 + 0xc) == '\0') ||
        (*(char *)((ushort)unaff_BSR * 0x100 + 3) != '\0')) ||
       (cVar3 = system_get_mode(0), cVar3 != '\x02')) {
      if (((keys_current & 0xe) != 0) && (ui_wake_pending == '\0')) {
        system_wake(0);
        if ((keys_current & 4) == 0) {
          ui_substate = 0;
        }
        else {
          ui_substate = 1;
        }
      }
    }
    else {
      ui_return_screen = ui_screen;
      ui_to_clock_display_off_4e84();
      ui_screen_timeout = 0x3c;
      screen_exit_power_down();
    }
    if ((((ui_screen == '\x01') || (ui_screen == '\x1b')) ||
        ((ui_screen == '\x1c' ||
         (((ui_screen == '\x1d' || (ui_screen == '\x02')) || (ui_screen == '\x03')))))) &&
       (((keys_current & 1) != 0 && (key_cold_hold_hi == '\0' && key_cold_hold_lo == '\0')))) {
      key_cold_hold_lo = -1;
      key_cold_hold_hi = -1;
      if ((ui_screen == '\x1b') || (ui_screen == '\x1c')) {
        ui_return_screen = '\x1b';
      }
      else {
        ui_return_screen = ui_screen;
      }
      ui_screen = '\x06';
      ui_countdown_100ms = 10;
      dispense_cold_request();
    }
    if ((keys_current & 0x60) == 0x60) {
      if ((ui_menu_param == 0) || (5 < ui_menu_param)) {
        ui_menu_param = 5;
      }
      else if (ui_menu_param == 1) {
        ui_menu_param = 0;
        ui_return_screen = ui_screen;
        ui_to_clock_display_off_4e84(0);
        ui_screen_timeout = 0x3c;
        ui_to_menu_draw_13d8();
      }
    }
    bVar2 = keys_current - 0x40;
    if ((keys_current - 0x40 == 0) && (bVar2 = ui_menu_active, ui_menu_active == 0)) {
      if (ui_menu_param == 0) {
        bVar2 = 10;
        ui_menu_param = 10;
      }
      else {
        bVar2 = ui_menu_param - 1;
        if (bVar2 == 0) {
          clock_display_off(0);
          lcd_clear();
          ui_menu_param = 0;
          bVar2 = 1;
          ui_menu_active = 1;
          cfg_systemconfig4 = cfg_systemconfig4 & 0xd9;
        }
      }
    }
    if ((cfg_systemconfig3 & 0x40) != 0) {
      if ((cfg_systemconfig5 & 8) != 0) {
        bVar2 = PORTH;
        if ((bVar2 & RH1) == 0) {
          bVar2 = PORTH;
          PORTH = bVar2 & ~RH4;
        }
        else {
          bVar2 = PORTH;
          PORTH = bVar2 | RH4;
        }
        bVar2 = PORTH;
        if ((bVar2 & RH2) == 0) {
          bVar2 = PORTH;
          PORTH = bVar2 & ~RH6;
          return 0;
        }
        bVar1 = PORTH;
        PORTH = bVar1 | RH6;
        return bVar2 & RH2;
      }
      bVar2 = PORTH;
      c18_tmp0 = (bVar2 & RH1) != 0;
      bVar2 = PORTH;
      bVar2 = (bool)c18_tmp0 || (bVar2 & 4) != 0;
      if ((bool)bVar2) {
        bVar1 = PORTH;
        PORTH = bVar1 | RH6;
      }
      else {
        bVar1 = PORTH;
        PORTH = bVar1 & ~RH6;
      }
    }
  }
  return bVar2;
}


// ===== 0x003470 ui_to_heating_start_task_3470 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes ui_screen; reads ui_screen; calls heating_start_task,cooling_start_task; 15 instr */

void ui_to_heating_start_task_3470(void)

{
  char cVar1;
  
  if (ui_screen != '\x02') {
    cVar1 = ui_screen + -3;
    if (cVar1 != '\0') {
      ui_screen = '\0';
      ui_return_screen = 0;
      goto LAB_CODE_00348a;
    }
  }
  cVar1 = '\x19';
  ui_screen = '\x19';
LAB_CODE_00348a:
  ui_set_heater_output_enable_4f1c(cVar1);
  heating_start_task();
  cooling_start_task();
  return;
}


// ===== 0x003496 ui_set_ui_screen_3496 =====

/* Auto: writes ui_screen; 5 instr */

undefined1 ui_set_ui_screen_3496(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  byte unaff_Z;
  
  uVar1 = ui_get_ui_screen_4ee4();
  if ((unaff_Z & 1) == 0) {
    uVar1 = 2;
    *(undefined1 *)((ushort)unaff_BSR * 0x100) = 2;
  }
  return uVar1;
}


// ===== 0x0034a2 ui_set_ui_screen_34a2 =====

/* Auto: writes ui_screen; 5 instr */

undefined1 ui_set_ui_screen_34a2(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  byte unaff_Z;
  
  uVar1 = ui_get_ui_screen_4ee4();
  if ((unaff_Z & 1) == 0) {
    uVar1 = 4;
    *(undefined1 *)((ushort)unaff_BSR * 0x100) = 4;
  }
  return uVar1;
}


// ===== 0x0034ae ui_draw_status_icons =====

/* Draw heater/compressor indicators and smoothed tank temperatures */

undefined1 ui_draw_status_icons(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  if (((ui_screen != '\x04') && (uVar4 = 0, ui_screen != '\x05')) &&
     (uVar4 = 0, ui_screen != '\x14')) {
    if (ui_screen + -0x1f == '\0') {
      return 0;
    }
    puVar1 = &FramePointer10x0001;
    mod_get_TBLPTRH_f334(ui_screen + -0x1f);
    *puVar1 = *puVar1;
    puVar1[-1] = ui_heater_indicator;
    mod_get_TBLPTRH_f364();
    puVar2 = puVar1 + -1;
    *puVar1 = *puVar1;
    ui_temp_scratch = hot_temp_read_top();
    if (ui_temp_scratch < ui_disp_hot_top) {
      ui_temp_scratch = ui_disp_hot_top;
    }
    if (0xfd < ui_disp_hot_bottom && ui_disp_hot_bottom + 2 <= ui_temp_scratch) {
      ui_temp_scratch = ui_disp_hot_bottom;
    }
    c18_tmp10 = ui_layout_0;
    c18_tmp11 = 0;
    c18_tmp8 = ui_disp_hot_bottom - ui_disp_hot_top;
    c18_tmp9 = 0;
    c18_tmp4 = ui_disp_hot_bottom - ui_temp_scratch;
    c18_tmp5 = 0;
    ui_scale_mul(ui_layout_2);
    puVar3 = puVar2 + 1;
    *puVar2 = 0x42;
    ui_to_gfx_bitmap_blit_4fa0(1);
    ui_temp_scratch = cold_temp_read_ch5();
    if (ui_temp_scratch < ui_disp_cold_a) {
      ui_temp_scratch = ui_disp_cold_a;
    }
    if (0xfd < ui_disp_cold_b && ui_disp_cold_b + 2 <= ui_temp_scratch) {
      ui_temp_scratch = ui_disp_cold_b;
    }
    c18_tmp10 = ui_layout_5;
    c18_tmp11 = 0;
    c18_tmp8 = ui_disp_cold_b - ui_disp_cold_a;
    c18_tmp9 = 0;
    c18_tmp4 = ui_temp_scratch - ui_disp_cold_a;
    c18_tmp5 = 0;
    ui_scale_mul(ui_layout_7);
    *puVar3 = 0x47;
    uVar4 = ui_to_gfx_bitmap_blit_4fa0(1);
  }
  return uVar4;
}


// ===== 0x003584 screen_diagnostics =====

/* WARNING: Removing unreachable block (CODE,0x0037fc) */
/* WARNING: Removing unreachable block (CODE,0x003790) */
/* WARNING: Removing unreachable block (CODE,0x00372c) */
/* WARNING: Removing unreachable block (CODE,0x0036c6) */
/* WARNING: Removing unreachable block (CODE,0x00365a) */
/* WARNING: Removing unreachable block (CODE,0x0035f6) */
/* WARNING: Removing unreachable block (CODE,0x0035d4) */
/* WARNING: Removing unreachable block (CODE,0x003638) */
/* WARNING: Removing unreachable block (CODE,0x0036a0) */
/* WARNING: Removing unreachable block (CODE,0x00370a) */
/* WARNING: Removing unreachable block (CODE,0x00376e) */
/* WARNING: Removing unreachable block (CODE,0x0037d6) */
/* WARNING: Removing unreachable block (CODE,0x003abc) */
/* Service diagnostics screen: title "T6 3.47V" (firmware version), sensors, states */

void screen_diagnostics(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  undefined1 *puVar33;
  byte bVar34;
  undefined1 uVar35;
  char cVar36;
  byte bVar37;
  BADSPACEBASE *in_FSR0;
  byte *pbVar38;
  byte *pbVar39;
  byte *pbVar40;
  byte *pbVar41;
  byte *pbVar42;
  byte *pbVar43;
  byte *pbVar44;
  byte *pbVar45;
  bool bVar46;
  bool bVar47;
  
  ui_frag_4c90();
  bVar37 = (byte)in_FSR1;
  bVar47 = 0xf8 < bVar37;
  if (bVar47) {
    puVar1 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),0xff);
    in_FSR1 = (BADSPACEBASE *)(puVar1 + 1);
    *puVar1 = *puVar1;
  }
  puVar2 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),bVar37 + 7);
  puVar3 = puVar2 + 1;
  *puVar2 = 0x5f;
  ui_draw_title();
  *puVar3 = *puVar3;
  puVar3[-1] = 0;
  ui_callw_fncfc6_4c62(1);
  puVar4 = puVar3 + 1;
  *puVar3 = 0xd4;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = hot_temp_read_top();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = (byte *)((short)in_FSR0 + -1);
  pbVar38 = (byte *)((short)in_FSR0 + -1);
  bVar37 = *(byte *)in_FSR0 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar38;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ser_stack_adjust_508e(uVar35);
  ui_callw_fncfc6_4c62(1);
  puVar5 = puVar4 + 1;
  *puVar4 = 0xd0;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = temp_read_ch6();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar41 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar41;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar6 = puVar5 + 1;
  *puVar5 = 0x58;
  ui_callw_fncfc6_4c62(1);
  puVar7 = puVar6 + 1;
  *puVar6 = 0xcc;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = cold_temp_read_ch4();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar42 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_frame_access_4e3c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    temp_c_to_f();
    pbVar39 = pbVar42;
  }
  ui_to_fmt_int_4eaa();
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar8 = puVar7 + 1;
  *puVar7 = 0;
  ui_callw_fncfc6_4c62(2);
  puVar9 = puVar8 + 1;
  *puVar8 = 200;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = hot_temp_read_bottom();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar43 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar43;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ser_stack_adjust_508e(uVar35);
  ui_callw_fncfc6_4c62(2);
  puVar10 = puVar9 + 1;
  *puVar9 = 0xc4;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = temp_read_ch7();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar44 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar44;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar11 = puVar10 + 1;
  *puVar10 = 0x58;
  ui_callw_fncfc6_4c62(2);
  puVar12 = puVar11 + 1;
  *puVar11 = 0xc0;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = cold_temp_read_ch5();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar45 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_frame_access_4e3c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    temp_c_to_f();
    pbVar39 = pbVar45;
  }
  ui_to_fmt_int_4eaa();
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar13 = puVar12 + 1;
  *puVar12 = 0;
  ui_callw_fncfc6_4c62(3);
  puVar14 = puVar13 + 1;
  *puVar13 = 0xbc;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  ui_to_ui_to_fmt_byte_4fbc(heater_power_level);
  ser_stack_adjust_508e();
  ui_callw_fncfc6_4c62(3);
  puVar15 = puVar14 + 1;
  *puVar14 = 0xb8;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  bVar37 = PORTH;
  if ((bVar37 & RH5) == 0) {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ser_stack_adjust_502e(uVar35);
  ui_callw_fncfc6_4c62(3);
  puVar16 = puVar15 + 1;
  *puVar15 = 0xac;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 0x40) == 0) {
    cVar36 = compressor_get_offdelay();
    if (cVar36 == '\0') {
      *puVar16 = 0xb0;
      uVar35 = 0x53;
      puVar16 = puVar16 + 1;
      goto LAB_CODE_00388c;
    }
    compressor_get_offdelay();
    ui_to_ui_to_fmt_byte_4fbc();
    ser_chain_fn4f80_fn5036_50b2();
    puVar17 = puVar16 + 1;
    *puVar16 = 0x30;
    mod_get_lcd_text_width_ca24();
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
LAB_CODE_00388c:
    puVar18 = puVar16 + 1;
    *puVar16 = uVar35;
    mod_set_lcd_text_flag_ca68();
    puVar17 = puVar18 + -1;
    *puVar18 = *puVar18;
  }
  *puVar17 = *puVar17;
  puVar17[-1] = 0;
  ui_callw_fncfc6_4c62(4);
  puVar15 = puVar17 + 1;
  *puVar17 = 0xa8;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 2) == 0) {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ui_callw_mod_set_lcd_text_flag_4c48(uVar35);
  puVar19 = puVar15 + 1;
  *puVar15 = 0x2c;
  ui_callw_fncfc6_4c62(4);
  puVar15 = puVar19 + 1;
  *puVar19 = 0xa4;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 1) == 0) {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ser_stack_adjust_502e(uVar35);
  ui_callw_fncfc6_4c62(4);
  puVar16 = puVar15 + 1;
  *puVar15 = 0xa0;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 4) == 0) {
    *puVar16 = 0xb0;
    uVar35 = 0x53;
    puVar16 = puVar16 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ui_callw_mod_set_lcd_text_flag_4c48(uVar35);
  puVar20 = puVar16 + 1;
  *puVar16 = 0;
  ui_callw_fncfc6_4c62(5);
  puVar15 = puVar20 + 1;
  *puVar20 = 0x9c;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  cVar36 = heating_is_extra_hot();
  if (cVar36 == '\0') {
    cVar36 = system_get_mode();
    if (cVar36 == '\0') {
      puVar21 = puVar15 + 1;
      *puVar15 = 0x96;
      goto LAB_CODE_00395e;
    }
    cVar36 = system_get_mode();
    if (cVar36 == '\x01') {
      puVar21 = puVar15 + 1;
      *puVar15 = 0x93;
      bVar47 = true;
      goto LAB_CODE_00395e;
    }
    bVar37 = system_get_mode();
    bVar47 = bVar37 < 3;
    if (bVar37 == 2) {
      puVar21 = puVar15 + 1;
      *puVar15 = 0x90;
      goto LAB_CODE_00395e;
    }
  }
  else {
    puVar21 = puVar15 + 1;
    *puVar15 = 0x99;
LAB_CODE_00395e:
    ui_callw_mod_set_lcd_text_flag_4c48(0x53);
    puVar15 = puVar21;
  }
  puVar22 = puVar15 + 1;
  *puVar15 = 0x2c;
  ui_callw_fncfc6_4c62(5);
  puVar23 = puVar22 + 1;
  *puVar22 = 0x8c;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  bVar37 = PORTJ;
  if ((bVar37 & RJ3) == 0) {
    *puVar23 = 0x88;
  }
  else {
    bVar37 = PORTJ;
    if ((bVar37 & RJ4) == 0) {
      *puVar23 = 0x84;
    }
    else {
      *puVar23 = 0x80;
    }
  }
  puVar24 = puVar23 + 1;
  ser_stack_adjust_502e(0x53);
  ser_stack_adjust_505a(5);
  bVar37 = PORTJ;
  if ((bVar37 & RJ0) == 0) {
    *puVar24 = 0x88;
  }
  else {
    *puVar24 = 0x80;
  }
  puVar25 = puVar24 + 1;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  puVar26 = puVar25 + 1;
  *puVar25 = 0;
  ui_callw_fncfc6_4c62(6);
  bVar37 = (byte)((ushort)(puVar26 + 1) >> 8);
  *puVar26 = 0x78;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((cfg_systemconfig3 & 4) == 0) {
    filter_usage_calc();
    math_aarg_b3 = 6;
    math_barg_b0 = 0;
    ui_get_math_tmp2_4fc6();
    ui_get_math_res0_4fdc();
    math_res0 = c18_tmp0 + 0xf;
    bVar47 = CARRY1(c18_tmp1,0xf0 < c18_tmp0);
    math_res1 = c18_tmp1 + (0xf0 < c18_tmp0);
    bVar46 = CARRY1(c18_tmp2,bVar47);
    math_aarg_lo = c18_tmp2 + bVar47;
    bVar47 = CARRY1(c18_tmp3,bVar46);
    math_aarg_hi = c18_tmp3 + bVar46;
    math_aarg_b3 = 0x1e;
    math_barg_b0 = 0;
    math_barg_lo = 0;
    math_barg_hi = 0;
    c18_tmp0 = math_res0;
    c18_tmp1 = math_res1;
    c18_tmp2 = math_aarg_lo;
    c18_tmp3 = math_aarg_hi;
    uVar35 = ui_to_ltoa_4daa();
    if (bVar47) goto LAB_CODE_003a26;
  }
  else {
    filter_usage_calc();
    math_aarg_b3 = 0x58;
    math_barg_b0 = 2;
    ui_get_math_tmp2_4fc6();
    uVar35 = ui_to_ltoa_4daa();
    if (bVar47) goto LAB_CODE_003a26;
  }
  puVar27 = (undefined1 *)((ushort)bVar37 * 0x100);
  bVar37 = (byte)((ushort)(puVar27 + -1) >> 8);
  *puVar27 = *puVar27;
LAB_CODE_003a26:
  puVar28 = (undefined1 *)CONCAT11(bVar37,uVar35);
  bVar47 = c18_tmp8 == '\0';
  ser_chain_fn4f80_fn5036_50b2(c18_tmp8);
  puVar29 = puVar28 + 1;
  *puVar28 = 0x2c;
  ui_callw_fncfc6_4c62(6);
  puVar30 = puVar29 + 1;
  *puVar29 = 0x74;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  bVar37 = PORTC;
  if ((bVar37 & RC3) == 0) {
    *puVar30 = 0x88;
  }
  else {
    *puVar30 = 0x80;
  }
  puVar15 = puVar30 + 1;
  ser_stack_adjust_502e(0x53);
  ser_stack_adjust_505a(6);
  bVar37 = PORTJ;
  if ((bVar37 & RJ1) == 0) {
    uVar35 = ui_stack_adjust_4eec();
  }
  else {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  ui_callw_mod_set_lcd_text_flag_4c48(uVar35);
  ui_draw_home_info();
  puVar31 = puVar15 + 1;
  *puVar15 = 0x58;
  ui_callw_fncfc6_4c62(7);
  puVar32 = puVar31 + 1;
  *puVar31 = 0x70;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  uVar35 = ui_to_eeprom_read_param_4f64(0x15);
  puVar33 = puVar32 + 1;
  *puVar32 = uVar35;
  ui_calc_array_ptr_4c3a();
  ui_stack_adjust_4f26();
  if ((cfg_systemconfig3 & 4) == 0) {
    ui_to_temp_c_to_f_4ffc();
  }
  else {
    ui_to_fmt_byte_4c9c();
  }
  bVar37 = ui_stack_adjust_4f5a();
  bVar46 = false;
  if (bVar47) {
    bVar37 = *pbVar40 ^ 0xff;
    bVar46 = bVar37 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar37);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  if ((byte)puVar33 < 7) {
    *(undefined1 *)((ushort)puVar33 & 0xff00) = *(undefined1 *)((ushort)puVar33 & 0xff00);
  }
  ui_c18_epilogue_4d6e((byte)puVar33 - 7);
  return;
}


// ===== 0x003ada ui_word_tue_3ada =====

/* Auto: shows "TUE"; reads ui_header_text; calls text_draw_word; 12 instr */

void ui_word_tue_3ada(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_to_text_draw_char_4fa8(2);
  *(undefined1 *)in_FSR1 = 2;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = ui_header_text;
  text_draw_word();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  ui_to_text_draw_char_4fa8(4);
  ui_to_text_draw_char_4fa8(5);
  return;
}


// ===== 0x003afc ui_set_ui_message_timer_3afc =====

/* Auto: writes ui_message_timer,ui_screen; reads ui_header_text; 8 instr */

void ui_set_ui_message_timer_3afc(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  ui_header_text = *(undefined1 *)((short)in_FSR2 + -2);
  ui_message_timer = 6;
  ui_screen = 0;
  ui_c18_epilogue_4d6e();
  return;
}


// ===== 0x003b12 ui_refresh_screen =====

/* WARNING: Removing unreachable block (CODE,0x003c76) */
/* WARNING: Removing unreachable block (CODE,0x003c6c) */
/* WARNING: Removing unreachable block (CODE,0x003c18) */
/* WARNING: Removing unreachable block (CODE,0x003c22) */
/* WARNING: Removing unreachable block (CODE,0x003c8e) */
/* WARNING: Removing unreachable block (CODE,0x003c98) */
/* WARNING: Removing unreachable block (CODE,0x003fec) */
/* WARNING: Removing unreachable block (CODE,0x003ff6) */
/* WARNING: Removing unreachable block (CODE,0x003c00) */
/* WARNING: Removing unreachable block (CODE,0x003bf6) */
/* WARNING: Removing unreachable block (CODE,0x003c0e) */
/* WARNING: Removing unreachable block (CODE,0x003c84) */
/* WARNING: Removing unreachable block (CODE,0x00402a) */
/* WARNING: Removing unreachable block (CODE,0x00404c) */
/* WARNING: Removing unreachable block (CODE,0x004056) */
/* WARNING: Removing unreachable block (CODE,0x003fcc) */
/* WARNING: Removing unreachable block (CODE,0x003fd6) */
/* WARNING: Removing unreachable block (CODE,0x003fe4) */
/* WARNING: Removing unreachable block (CODE,0x004034) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Redraw current screen (called when refresh timer expires) */

void ui_refresh_screen(void)

{
  BADSPACEBASE *in_FSR2;
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  char *pcVar33;
  char *pcVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  byte *pbVar37;
  byte *pbVar38;
  char *pcVar39;
  undefined1 *puVar40;
  undefined1 *puVar41;
  undefined1 *puVar42;
  char *pcVar43;
  undefined1 *puVar44;
  char cVar45;
  byte bVar46;
  undefined1 uVar47;
  char cVar48;
  short sVar49;
  bool bVar50;
  
  ui_frag_4c90();
  puVar5 = (undefined1 *)((short)in_FSR1 + 1);
  puVar6 = (undefined1 *)((short)in_FSR1 + 1);
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  puVar44 = (undefined1 *)((short)in_FSR1 + 1);
  puVar7 = (undefined1 *)((short)in_FSR1 + 1);
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  puVar9 = (undefined1 *)((short)in_FSR1 + 1);
  puVar10 = (undefined1 *)((short)in_FSR1 + 1);
  puVar11 = (undefined1 *)((short)in_FSR1 + 1);
  puVar12 = (undefined1 *)((short)in_FSR1 + 1);
  puVar13 = (undefined1 *)((short)in_FSR1 + 1);
  puVar14 = (undefined1 *)((short)in_FSR1 + 1);
  puVar15 = (undefined1 *)((short)in_FSR1 + 1);
  puVar35 = (undefined1 *)((short)in_FSR1 + 1);
  puVar16 = (undefined1 *)((short)in_FSR1 + 1);
  puVar17 = (undefined1 *)((short)in_FSR1 + 1);
  puVar20 = (undefined1 *)((short)in_FSR1 + 1);
  puVar21 = (undefined1 *)((short)in_FSR1 + 1);
  puVar22 = (undefined1 *)((short)in_FSR1 + 1);
  puVar23 = (undefined1 *)((short)in_FSR1 + 1);
  puVar24 = (undefined1 *)((short)in_FSR1 + 1);
  puVar25 = (undefined1 *)((short)in_FSR1 + 1);
  puVar26 = (undefined1 *)((short)in_FSR1 + 1);
  puVar27 = (undefined1 *)((short)in_FSR1 + 1);
  puVar28 = (undefined1 *)((short)in_FSR1 + 1);
  puVar30 = (undefined1 *)((short)in_FSR1 + 1);
  puVar31 = (undefined1 *)((short)in_FSR1 + 1);
  pcVar33 = (char *)((short)in_FSR1 + 1);
  puVar41 = (undefined1 *)((short)in_FSR1 + 1);
  puVar42 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  cVar48 = ui_return_screen;
  bVar1 = 1;
  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
  if (ui_screen != '\x1f') {
    if (ui_screen == '\x1e') {
      compressor_stop();
      cooling_stop_task();
      heater_off();
      heater_output_enable = 0;
      heating_stop_task();
      cfg_systemconfig = cfg_systemconfig & 0xf7;
      clock_display_off();
      ui_to_screen_language_select_14d2();
      ui_screen = '\x1f';
      pcVar43 = puVar42;
    }
    else if (ui_screen == '\x14') {
      pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
      if ((ui_screen_timeout == '\0') &&
         (cVar48 = ui_get_menu_mode_1122(0), pcVar43 = puVar41, cVar48 == '\0')) {
        ui_bank1_ui_to_lcd_clear_10d4();
        ui_select_home_screen();
        pcVar43 = puVar41;
      }
    }
    else {
      cVar45 = ui_hold_counter;
      if (ui_screen == '\x1d') goto joined_c0x003d34;
      if (ui_screen == '\x1c') {
        local3 = mod_to_hot_temp_read_top_c932();
        *(byte *)in_FSR2 = local3;
        local4 = 0;
        bVar1 = ui_param_tboil_4de4();
        if ((local4 & 0x80) == 0 && local4 != ~(bVar1 <= local3)) {
          c18_tmp1 = ui_to_eeprom_read_param_4f64(0x15);
          pcVar34 = pcVar33 + 1;
          *pcVar33 = c18_tmp1;
          cVar48 = ui_to_eeprom_read_param_4f64(0x16);
          pcVar33 = pcVar34 + -1;
          puVar4 = pcVar34 + -1;
          *pcVar34 = *pcVar34;
          if (ui_temp_change_timer == pcVar34[-1] - cVar48) goto LAB_CODE_0040c8;
          ui_substate = '\x01';
        }
        else {
LAB_CODE_0040c8:
          ui_substate = '\0';
          puVar4 = pcVar33;
        }
        c18_tmp1 = '\0';
        if ((ui_extra_hot_prev & 0x80) != 0) {
          c18_tmp1 = -1;
        }
        sVar49 = (ushort)(local3 - ui_extra_hot_prev) * 100;
        math_aarg_lo = (byte)sVar49;
        math_aarg_hi = ((local4 - c18_tmp1) - ~(ui_extra_hot_prev <= local3)) * 'd' +
                       (char)((ushort)sVar49 >> 8);
        math_barg_lo = ui_temp_change_timer - ui_extra_hot_prev;
        c18_tmp1 = '\0';
        if ((math_barg_lo & 0x80) != 0) {
          c18_tmp1 = -1;
        }
        math_barg_hi = c18_tmp1;
        c18_tmp0 = math_barg_lo;
        local3 = math_aarg_lo;
        local4 = math_aarg_hi;
        __divs16();
        local3 = math_aarg_lo;
        bVar50 = (char)math_aarg_hi < '\0';
        if (!bVar50) {
          bVar50 = ~(math_aarg_lo < 0x65) != 0 || math_aarg_hi < (byte)-~(math_aarg_lo < 0x65);
        }
        if ((bVar50) && ((math_aarg_hi & 0x80) == 0)) {
          bVar50 = false;
        }
        else {
          bVar50 = true;
        }
        if (bVar50) {
          local3 = 100;
          local4 = 0;
        }
        else {
          local4 = math_aarg_hi;
        }
        cVar48 = heating_is_extra_hot();
        pcVar43 = puVar4;
        if ((((cVar48 == '\0') && (ui_substate != '\0')) ||
            (((cfg_systemconfig5 & 1) == 0 && (heater_power_level < 3)))) ||
           (heater_power_level == 0)) {
          ui_return_screen = ui_screen;
          ui_screen = '\x1d';
          ui_hold_counter = '\x03';
          if (ui_menu_active == '\0') {
            mod_get_popup_index_e2d0(0);
            clock_draw();
            ui_to_txt_to_text_draw_char_4fb2();
            if ((cfg_systemconfig5 & 1) != 0) {
              ui_stack_adjust_4dde();
            }
            if (ui_substate == '\0') {
              puVar35 = puVar4 + 1;
              *puVar4 = 7;
              uVar47 = 0x13;
            }
            else {
              puVar35 = puVar4 + 1;
              *puVar4 = 7;
              uVar47 = 0x12;
            }
LAB_CODE_0041aa:
            puVar36 = puVar35 + 1;
            *puVar35 = uVar47;
            text_draw_word();
            goto LAB_CODE_004204;
          }
        }
        else if (ui_menu_active == '\0') {
          if (ui_substate == '\0') {
            *puVar4 = 2;
            uVar47 = 0x15;
          }
          else {
            *puVar4 = 2;
            uVar47 = 0x14;
          }
          pbVar37 = puVar4 + 1;
          ui_to_ser_to_text_draw_word_4d7a(uVar47);
          if ((cfg_systemconfig5 & 1) != 0) {
            ui_to_txt_to_text_draw_char_4fb2();
          }
          ui_stack_adjust_4dde();
          *pbVar37 = local3;
          pbVar38 = pbVar37 + 2;
          pbVar37[1] = local4;
          ui_draw_progress_popup();
          *pbVar38 = *pbVar38;
          pcVar43 = (char *)(pbVar38 + -2);
          pbVar38[-1] = pbVar38[-1];
          if ((cfg_systemconfig5 & 1) != 0) {
            pbVar38[-2] = 6;
            pbVar38[-1] = 0x20;
            pcVar39 = (char *)(pbVar38 + 1);
            *pbVar38 = *(char *)in_FSR2 + '\x01';
            draw_temperature_screen();
            puVar36 = pcVar39 + -1;
            *pcVar39 = *pcVar39;
            goto LAB_CODE_004204;
          }
        }
      }
      else {
        if (ui_screen == '\x1b') {
          ui_wake_pending = 1;
          ui_return_screen = ui_screen;
          ui_screen = '\x1c';
          ui_hold_counter = '\0';
          pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
          if (ui_menu_active != '\0') goto LAB_CODE_00424e;
          clock_display_off(0);
          if ((cfg_systemconfig4 & 0x40) == 0) {
            ui_to_child_protect_is_active_4d80();
            ui_get_cfg_systemconfig3_4e96(0);
            puVar30 = puVar31;
            if ((cfg_systemconfig3 & 0x20) == 0) goto LAB_CODE_004064;
            uVar47 = 1;
          }
          else {
            ui_to_child_protect_is_active_4d80();
            ui_get_cfg_systemconfig2_4e8c(0);
            ser_param_tpowerdelay_5040();
            puVar30 = puVar31;
LAB_CODE_004064:
            uVar47 = 0;
          }
LAB_CODE_00406a:
          ui_to_ui_draw_label_value_4e4c(uVar47);
          ui_to_gfx_draw_frame_right_4c6e();
          puVar32 = puVar30 + 1;
          *puVar30 = 6;
          ui_to_ser_to_text_draw_word_4d7a(0x11);
          *puVar32 = 0x11;
          puVar36 = puVar32 + 2;
          puVar32[1] = 4;
          mod_to_ui_draw_progress_segment_e2ba();
LAB_CODE_004204:
          puVar40 = puVar36 + -1;
          *puVar36 = *puVar36;
        }
        else {
          if (ui_screen == '\x1a') {
            ui_return_screen = ui_screen;
            ui_screen = '\x1c';
            ui_hold_counter = '\0';
            ui_temp_change_timer = ui_param_tboil_4de4();
            ui_extra_hot_prev = mod_to_hot_temp_read_top_c932();
            ui_wake_pending = 1;
            pcVar43 = puVar30;
            if (ui_menu_active == '\0') {
              clock_display_off(0);
              if ((cfg_systemconfig4 & 0x40) == 0) {
                ui_to_child_protect_is_active_4d80();
                ui_get_cfg_systemconfig3_4e96(0);
                if ((cfg_systemconfig3 & 0x20) != 0) {
                  uVar47 = 1;
                  goto LAB_CODE_00406a;
                }
              }
              else {
                ui_to_child_protect_is_active_4d80();
                ui_get_cfg_systemconfig2_4e8c(0);
                ser_param_tpowerdelay_5040();
              }
              goto LAB_CODE_004064;
            }
            goto LAB_CODE_00424e;
          }
          if (ui_screen == '\x19') {
            ui_hold_counter = '\x02';
            ui_screen = '\x1a';
            ui_wake_pending = 1;
            pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
            goto LAB_CODE_00424e;
          }
          if (ui_screen != '\x18') {
            pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
            if (ui_screen == '\x17') goto LAB_CODE_00424e;
            if (ui_screen != '\x16') {
              if (ui_screen == '\x15') {
                ui_screen = '\x17';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar35 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar35 = puVar26;
                  }
                  ui_to_clock_display_off_4d04();
                  if ((cfg_systemconfig5 & 1) != 0) {
                    ui_stack_adjust_4dde();
                  }
                  ser_word_child_protect_5066();
                  uVar47 = 0x62;
                  goto LAB_CODE_0041aa;
                }
              }
              else if (ui_screen == '\x11') {
                cVar48 = dispense_hot_is_active();
                pcVar43 = puVar25;
                if ((cVar48 == '\0') && (puVar20 = puVar25, ui_countdown_100ms == '\0')) {
LAB_CODE_003f10:
                  ui_screen = ui_return_screen;
                  pcVar43 = puVar20;
                }
              }
              else if (ui_screen == '\x10') {
                ui_screen = '\x11';
                ui_dispense_state = 0;
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar4 = puVar24;
                  }
                  ui_to_clock_display_off_4d04();
                  ui_test_value_4f9a();
joined_c0x003eca:
                  if (cVar48 == '\x1b') {
LAB_CODE_003eee:
                    puVar35 = puVar4 + 1;
                    *puVar4 = 7;
                    uVar47 = 0xe;
                  }
                  else {
                    puVar35 = puVar4 + 1;
                    *puVar4 = 7;
                    uVar47 = 0xf;
                  }
                  goto LAB_CODE_0041aa;
                }
              }
              else if (ui_screen == '\x12') {
                ui_dispense_state = 0;
                ui_screen = '\x13';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar4 = puVar23;
                  }
                  ui_to_clock_display_off_4d04();
                  ui_test_value_4f9a();
                  goto joined_c0x003eca;
                }
              }
              else if (ui_screen == '\f') {
                ui_dispense_state = 0;
                ui_screen = '\r';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar4 = puVar22;
                  }
                  ui_to_clock_display_off_4d04();
                  goto LAB_CODE_003eee;
                }
              }
              else if (ui_screen == '\n') {
                ui_screen = '\v';
                ui_hold_counter = '\x03';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  clock_display_off(0);
                  puVar29 = puVar21 + 1;
                  *puVar21 = 6;
                  ser_to_text_draw_word_5048(0xd);
                  goto LAB_CODE_003f82;
                }
              }
              else if (ui_screen == '\v') {
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_hold_counter == '\0') {
                  cVar48 = system_get_mode(0);
                  puVar12 = puVar20;
                  if (cVar48 == '\0') goto LAB_CODE_00420e;
                  cVar48 = system_get_mode();
                  puVar12 = puVar20;
                  if (cVar48 == '\x01') goto LAB_CODE_003e6c;
                  goto LAB_CODE_003f10;
                }
              }
              else if (ui_screen == '\x0f') {
                bVar46 = 0;
                if (ui_alarm_index != '\x01') {
                  bVar1 = 0xe;
                  bVar46 = uv_status & 1;
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if (bVar46 == 0) goto LAB_CODE_00424e;
                }
                ui_to_ser_set_ui_screen_4dfa(bVar46);
                if ((*(byte *)((ushort)bVar1 * 0x100 + 0xf3) & 1) != 0) {
                  ui_to_dispense_stop_all_4f30();
                }
                pcVar43 = puVar17;
                if (ui_menu_active == '\0') {
                  puVar18 = puVar17 + 1;
                  *puVar17 = ui_dispense_state;
                  gfx_anim_icon_d(0);
LAB_CODE_003e44:
                  puVar19 = puVar18 + -1;
                  *puVar18 = *puVar18;
                  ui_stack_adjust_4dde();
                  puVar35 = puVar19 + 1;
                  *puVar19 = 6;
                  uVar47 = 0xc;
                  goto LAB_CODE_0041aa;
                }
              }
              else {
                if (ui_screen == '\x0e') {
                  ui_dispense_state = 0;
                  ui_screen = '\x0f';
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_menu_active != '\0') goto LAB_CODE_00424e;
joined_c0x003d7c:
                  if (ui_return_screen == '\x1b') {
                    ui_dispense_state = 0;
                    mod_to_mod_get_c18_tmp0_e290();
                    puVar35 = puVar16;
                  }
                  else {
                    ui_dispense_state = 0;
                    clock_display_off(ui_return_screen + -0x1b);
                  }
                  ui_to_text_draw_char_4fa8(2);
                  uVar47 = ui_stack_adjust_4eca();
                  goto LAB_CODE_0041aa;
                }
                if (ui_screen == '\x13') {
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if ((ui_alarm_index == '\x01') &&
                     (ser_set_ui_screen_5080(0), pcVar43 = puVar15, ui_menu_active == '\0')) {
                    puVar18 = puVar15 + 1;
                    *puVar15 = ui_dispense_state;
                    gfx_anim_icon_b(0);
                    goto LAB_CODE_003e44;
                  }
                }
                else if (ui_screen == '\r') {
                  bVar46 = 0;
                  if (ui_alarm_index != '\x01') {
                    bVar1 = 0xe;
                    bVar46 = uv_status & 1;
                    pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                    if (bVar46 == 0) goto LAB_CODE_00424e;
                  }
                  ui_to_ser_set_ui_screen_4dfa(bVar46);
                  if ((*(byte *)((ushort)bVar1 * 0x100 + 0xf3) & 1) != 0) {
                    ui_to_dispense_stop_all_4f30();
                  }
                  pcVar43 = puVar14;
                  if (ui_menu_active == '\0') {
                    puVar18 = puVar14 + 1;
                    *puVar14 = ui_dispense_state;
                    gfx_anim_icon_c(0);
                    goto LAB_CODE_003e44;
                  }
                }
                else if (ui_screen == '\t') {
                  bVar46 = 0;
                  if (ui_alarm_index != '\x01') {
                    bVar1 = 0xe;
                    bVar46 = uv_status & 1;
                    pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                    if (bVar46 == 0) goto LAB_CODE_00424e;
                  }
                  ui_to_ser_set_ui_screen_4dfa(bVar46);
                  if ((*(byte *)((ushort)bVar1 * 0x100 + 0xf3) & 1) != 0) {
                    ui_to_dispense_stop_all_4f30();
                  }
                  pcVar43 = puVar13;
                  if (ui_menu_active == '\0') {
                    puVar18 = puVar13 + 1;
                    *puVar13 = ui_dispense_state;
                    gfx_anim_icon_a(0);
                    goto LAB_CODE_003e44;
                  }
                }
                else if (ui_screen == '\b') {
                  ui_screen = '\t';
joined_c0x003d42:
                  ui_dispense_state = 0;
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_menu_active == '\0') goto joined_c0x003d7c;
                }
                else if (ui_screen == '\a') {
                  cVar48 = dispense_cold_is_active();
                  pcVar43 = puVar12;
                  if ((cVar48 == '\0') && (ui_countdown_100ms == '\0')) {
                    cVar48 = system_get_mode(0);
                    if (cVar48 == '\x01') {
LAB_CODE_003e6c:
                      ui_screen = '\x02';
                      pcVar43 = puVar12;
                    }
                    else {
LAB_CODE_00420e:
                      ui_screen = '\0';
                      pcVar43 = puVar12;
                    }
                  }
                }
                else {
                  if (ui_screen == '\x06') {
                    ui_screen = '\a';
                    goto joined_c0x003d42;
                  }
                  if (ui_screen == '\x01') {
                    cVar48 = system_get_mode();
                    puVar12 = puVar11;
                    if (cVar48 == '\x01') goto LAB_CODE_003e6c;
                    pcVar43 = puVar11;
                    if (ui_message_timer != '\0') {
                      ui_message_timer = ui_message_timer + -1;
                      puVar4 = puVar11;
                      cVar45 = ui_message_timer;
joined_c0x003d34:
                      pcVar43 = puVar4;
                      puVar12 = puVar4;
                      if (cVar45 == '\0') goto LAB_CODE_00420e;
                    }
                  }
                  else {
                    if (ui_screen != '\x03') {
                      if (ui_screen == '\x05') {
                        cVar45 = system_get_mode();
                        puVar4 = puVar9;
                        goto joined_c0x003d34;
                      }
                      if (ui_screen == '\x04') {
                        ui_screen = '\x05';
                        pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                        if (ui_menu_active == '\0') {
                          lcd_clear(0);
                          clock_draw();
                          puVar8 = puVar7 + 1;
                          *puVar7 = 6;
                          ui_to_ser_to_text_draw_word_4d7a(10);
                          ui_get_PORTH_4f12();
                          bVar1 = PORTC;
                          PORTC = bVar1 & ~RC1;
                          ui_backlight_timeout = 0;
                          pcVar43 = puVar8;
                        }
                        goto LAB_CODE_00424e;
                      }
                      if (ui_screen != '\x02') {
                        if (ui_screen != '\0') goto LAB_CODE_00425e;
                        ui_wake_pending = 0;
                        ui_screen = '\x01';
                        pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                        if (ui_menu_active != '\0') goto LAB_CODE_00424e;
                        puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                        if (ui_message_timer == '\0') {
                          if ((cfg_systemconfig4 & 0x40) == 0) {
                            ui_to_child_protect_is_active_4d80(0);
                            ui_get_cfg_systemconfig3_4e96(0);
                            puVar2 = puVar3;
                            if ((cfg_systemconfig3 & 0x20) == 0) goto LAB_CODE_003c30;
                            uVar47 = 1;
                          }
                          else {
                            ui_to_child_protect_is_active_4d80(0);
                            ui_get_cfg_systemconfig2_4e8c(0);
                            ser_param_tpowerdelay_5040();
LAB_CODE_003c30:
                            uVar47 = 0;
                            puVar3 = puVar2;
                          }
                          ui_to_ui_draw_label_value_4e4c(uVar47);
                          puVar4 = puVar3;
                        }
                        ui_to_gfx_draw_frame_right_4c6e();
                        ui_to_txt_to_text_draw_char_4fb2();
                        ui_stack_adjust_4dde();
                        if (ui_message_timer == '\0') {
                          clock_draw();
                          pcVar43 = puVar4;
                        }
                        else {
                          ui_word_tue_3ada(ui_message_timer);
                          pcVar43 = puVar4;
                        }
                        goto LAB_CODE_00424e;
                      }
                      ui_screen = '\x03';
                      pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                      if (ui_menu_active != '\0') goto LAB_CODE_00424e;
                      if ((cfg_systemconfig4 & 0x40) == 0) {
                        ui_to_child_protect_is_active_4d80(0);
                        ui_get_cfg_systemconfig3_4e96(0);
                        puVar5 = puVar6;
                        if ((cfg_systemconfig3 & 0x20) == 0) goto LAB_CODE_003ca6;
                        uVar47 = 1;
                      }
                      else {
                        ui_to_child_protect_is_active_4d80(0);
                        ui_get_cfg_systemconfig2_4e8c(0);
                        ser_param_tpowerdelay_5040();
LAB_CODE_003ca6:
                        uVar47 = 0;
                        puVar6 = puVar5;
                      }
                      ui_to_ui_draw_label_value_4e4c(uVar47);
                      ui_to_gfx_draw_frame_right_4c6e();
                      ui_stack_adjust_4dde();
                      clock_draw();
                      puVar35 = puVar6 + 1;
                      *puVar6 = 6;
                      uVar47 = 9;
                      goto LAB_CODE_0041aa;
                    }
                    cVar48 = system_get_mode();
                    pcVar43 = puVar10;
                    if (cVar48 == '\0') {
                      if (ui_substate == '\0') {
                        ui_screen = '\x19';
                      }
                      else {
                        cVar48 = heating_request_extra_hot(ui_substate);
                        puVar12 = puVar10;
                        if (cVar48 == '\0') goto LAB_CODE_00420e;
                        ui_screen = '\x1b';
                        pcVar43 = puVar10;
                      }
                    }
                  }
                }
              }
              goto LAB_CODE_00424e;
            }
            ui_screen = '\x17';
            pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
            if (ui_menu_active != '\0') goto LAB_CODE_00424e;
            puVar35 = (undefined1 *)((short)in_FSR1 + 1);
            if (ui_return_screen == '\x1b') {
              mod_to_mod_get_c18_tmp0_e290(0);
              puVar35 = puVar27;
            }
            ui_to_clock_display_off_4d04();
            if ((cfg_systemconfig5 & 1) != 0) {
              ui_stack_adjust_4dde();
            }
            ser_word_child_protect_5066();
            uVar47 = 99;
            goto LAB_CODE_0041aa;
          }
          ui_screen = ui_return_screen;
          pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
          if (ui_menu_active != '\0') goto LAB_CODE_00424e;
          ui_to_text_draw_char_4fa8(2);
          puVar29 = puVar28 + 1;
          *puVar28 = 4;
          text_draw_char();
LAB_CODE_003f82:
          puVar40 = puVar29 + -1;
          *puVar29 = *puVar29;
          ser_push_args_01_txt_to_text_draw_char_5052();
        }
        *puVar40 = *puVar40;
        pcVar43 = puVar40 + -1;
      }
    }
  }
LAB_CODE_00424e:
  if (ui_menu_active == '\0') {
    ui_draw_status_icons(0);
    puVar44 = pcVar43;
  }
  else {
    screen_diagnostics();
    puVar44 = pcVar43;
  }
LAB_CODE_00425e:
  *puVar44 = *puVar44;
  ui_c18_epilogue_4d6e();
  return;
}


// ===== 0x004264 ui_init =====

/* WARNING: Instruction at (CODE,0x004354) overlaps instruction at (CODE,0x004352)
    */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Initialise UI state, LEDs and display */

undefined1 ui_init(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  byte bVar21;
  char cVar22;
  bool bVar23;
  
  pbVar3 = (byte *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  bVar21 = PORTH;
  PORTH = bVar21 & ~RH6;
  if ((cfg_systemconfig5 & 8) == 0) {
    bVar21 = PORTH;
    PORTH = bVar21 & ~RH6;
  }
  else {
    bVar21 = PORTH;
    PORTH = bVar21 & ~RH4;
  }
  bVar21 = PORTH;
  PORTH = bVar21 | RH7;
  bVar21 = PORTB;
  PORTB = bVar21 | RB0;
  bVar21 = PORTB;
  PORTB = bVar21 & ~RB1;
  bVar21 = PORTC;
  PORTC = bVar21 | RC0;
  bVar21 = PORTC;
  PORTC = bVar21 & ~RC1;
  keys_current = 0;
  buzzer_pattern = 0;
  ui_countdown_100ms = 0;
  ui_screen_timeout = 0xff;
  ui_backlight_timeout = 0;
  ui_menu_active = 0;
  ui_menu_param = 0;
  ui_header_text = 0;
  ui_message_timer = 0;
  ui_clock_suppressed = 0;
  puVar6 = &FramePointer10x0006;
  ui_refresh_timer = eeprom_read_param();
  puVar7 = puVar6 + -1;
  *puVar6 = *puVar6;
  c18_tmp0 = (cfg_systemconfig2 & 0x38) >> 3;
  if (7 < c18_tmp0) {
    cfg_systemconfig2 = cfg_systemconfig2 & 199;
  }
  lcd_init(c18_tmp0 - 8);
  lcd_clear();
  puVar8 = puVar7 + 1;
  *puVar7 = 0x5f;
  ui_draw_title();
  pbVar9 = puVar8 + -1;
  *puVar8 = *puVar8;
  bVar21 = keypad_scan();
  if ((bVar21 & 0x20) == 0) {
    cVar22 = is_factory_jumper();
    if (cVar22 == '\0') {
      if (((cfg_systemconfig4 & 1) == 0) || (bVar21 = keypad_scan(), (bVar21 & 0x40) == 0)) {
        if ((cfg_systemconfig4 & 1) == 0) {
          puVar17 = pbVar9 + 1;
          *pbVar9 = 0x88;
          ui_get_buzzer_pattern_4850();
          puVar13 = puVar17 + -1;
          *puVar17 = *puVar17;
        }
        else {
          puVar16 = pbVar9 + 1;
          *pbVar9 = 0x80;
          ui_get_buzzer_pattern_4850();
          puVar13 = puVar16 + -1;
          *puVar16 = *puVar16;
        }
        lcd_draw_big_glyph();
      }
      else {
        cfg_systemconfig4 = cfg_systemconfig4 & 0xfe;
        *pbVar9 = cfg_systemconfig4;
        pbVar14 = pbVar9 + 2;
        pbVar9[1] = 0x3a;
        param_write();
        *pbVar14 = *pbVar14;
        pbVar14[-1] = pbVar14[-1];
        pbVar14[-2] = 3;
        pbVar14[-1] = 0x6d;
        text_draw_word();
        *pbVar14 = *pbVar14;
        pbVar14[-1] = pbVar14[-1];
        puVar15 = pbVar14 + -1;
        pbVar14[-2] = 0xf0;
        ui_get_buzzer_pattern_4850();
        puVar13 = puVar15 + -1;
        *puVar15 = *puVar15;
      }
    }
    else {
      cfg_systemconfig4 = cfg_systemconfig4 & 0xfe;
      *pbVar9 = 3;
      puVar11 = pbVar9 + 2;
      pbVar9[1] = 0x6f;
      text_draw_word();
      *puVar11 = *puVar11;
      puVar11[-1] = puVar11[-1];
      puVar12 = puVar11 + -1;
      puVar11[-2] = 0xaa;
      ui_get_buzzer_pattern_4850();
      puVar13 = puVar12 + -1;
      *puVar12 = *puVar12;
    }
    ui_compressor_indicator = 0;
    ui_heater_indicator = 0;
    ui_layout_0 = 8;
    ui_layout_1 = 6;
    ui_layout_2 = 0x28;
    ui_layout_3 = 7;
    ui_layout_4 = 0x2f;
    ui_disp_hot_top = 0x32;
    puVar18 = puVar13 + 1;
    *puVar13 = 0x15;
    ui_disp_hot_bottom = eeprom_read_param();
    *puVar18 = *puVar18;
    ui_layout_5 = 8;
    ui_layout_6 = 0x73;
    ui_layout_7 = 0x28;
    ui_layout_8 = 7;
    ui_layout_9 = 0x2f;
    puVar18[-1] = 3;
    ui_disp_cold_a = param_read_min();
    *puVar18 = *puVar18;
    puVar18[-1] = 3;
    ui_disp_cold_b = param_read_max();
    *puVar18 = *puVar18;
    puVar18[-1] = 0;
    cVar22 = eeprom_read_param();
    puVar20 = puVar18 + -1;
    *puVar18 = *puVar18;
    if (cVar22 != '\0') {
      puVar18[-1] = 0;
      puVar19 = puVar18 + 1;
      *puVar18 = 0;
      param_write();
      *puVar19 = *puVar19;
      puVar20 = puVar19 + -2;
      puVar19[-1] = puVar19[-1];
    }
    *puVar20 = *puVar20;
    puVar20[-1] = puVar20[-1];
    puVar20[-2] = puVar20[-2];
    puVar20[-3] = puVar20[-3];
    return 0;
  }
  cfg_systemconfig4 = cfg_systemconfig4 | 1;
  *pbVar9 = cfg_systemconfig4;
  pbVar10 = pbVar9 + 2;
  pbVar9[1] = 0x3a;
  param_write();
  *pbVar10 = *pbVar10;
  pbVar10[-1] = pbVar10[-1];
  pbVar10[-2] = 3;
  pbVar10[-1] = 0x6c;
  text_draw_word();
  *pbVar10 = *pbVar10;
  pbVar10[-1] = pbVar10[-1];
  *pbVar3 = 0;
  while (*pbVar3 < 3) {
    bVar21 = PORTB;
    PORTB = bVar21 | RB3;
    pbVar3[2] = 0;
    pbVar3[4] = 0;
    pbVar2 = pbVar3 + 2;
    while( true ) {
      puVar4 = pbVar2;
      bVar21 = puVar4[4];
      bVar23 = false;
      if (-1 < (char)bVar21) {
        bVar23 = bVar21 < (byte)~(0x99 < (byte)puVar4[2]) || 2 < bVar21 - ~(0x99 < (byte)puVar4[2]);
      }
      if (bVar23) break;
      cVar22 = '<';
      do {
        cVar22 = cVar22 + -1;
      } while (cVar22 != '\0');
      puVar4[4] = puVar4[5] + '\x01';
      pbVar2 = puVar4 + 4;
      if (puVar4[5] == -1) {
        puVar4[7] = puVar4[8] + '\x01';
        pbVar2 = puVar4 + 6;
      }
    }
    bVar21 = PORTB;
    PORTB = bVar21 & ~RB3;
    puVar4[4] = 0;
    puVar4[6] = 0;
    puVar1 = puVar4 + 4;
    while( true ) {
      puVar5 = puVar1;
      pbVar3 = puVar5 + 2;
      bVar21 = puVar5[4];
      bVar23 = false;
      if (-1 < (char)bVar21) {
        bVar23 = bVar21 < (byte)~(0x99 < (byte)puVar5[2]) || 2 < bVar21 - ~(0x99 < (byte)puVar5[2]);
      }
      if (bVar23) break;
      cVar22 = '<';
      do {
        cVar22 = cVar22 + -1;
      } while (cVar22 != '\0');
      puVar5[4] = puVar5[5] + '\x01';
      puVar1 = puVar5 + 4;
      if (puVar5[5] == -1) {
        puVar5[7] = puVar5[8] + '\x01';
        puVar1 = puVar5 + 6;
      }
    }
    puVar5[2] = puVar5[2] + '\x01';
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== 0x0044d4 ui_create_task =====

/* Create task_ui (TCB 0x6e) */

undefined1 ui_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x0044fe ui_10ms_tick =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Every 10 ms: key hold timers */

byte ui_10ms_tick(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_C;
  bool bVar3;
  
  if ((((keys_current & 1) != 0) && (unaff_C = (char)key_cold_hold_hi < '\0', !(bool)unaff_C)) &&
     (bVar2 = ~(key_cold_hold_lo == 0), unaff_C = bVar2 != 0 || key_cold_hold_hi < -bVar2,
     bVar2 == 0 && key_cold_hold_hi >= -bVar2)) {
    c18_tmp0 = ~key_cold_hold_lo;
    c18_tmp1 = ~key_cold_hold_hi;
    if (c18_tmp1 != 0 || c18_tmp0 != 0) {
      bVar3 = key_cold_hold_lo != 0;
      key_cold_hold_lo = key_cold_hold_lo - 1;
      unaff_C = key_cold_hold_hi != ~bVar3;
      key_cold_hold_hi = key_cold_hold_hi - ~bVar3;
    }
  }
  bVar2 = 0;
  if ((((keys_current & 2) != 0) && (bVar2 = 0, (cfg_systemconfig5 & 4) != 0)) &&
     ((bVar2 = key_hot_hold_hi << 1 | unaff_C & 1, -1 < (char)key_hot_hold_hi &&
      (bVar1 = ~(key_hot_hold_lo == '\0'), bVar2 = -~(key_hot_hold_lo == '\0') - key_hot_hold_hi,
      bVar1 == 0 && -bVar1 <= key_hot_hold_hi)))) {
    bVar3 = key_hot_hold_lo != '\0';
    key_hot_hold_lo = key_hot_hold_lo + -1;
    bVar2 = 0;
    key_hot_hold_hi = key_hot_hold_hi - ~bVar3;
  }
  return bVar2;
}


// ===== 0x004550 ui_second_tick =====

/* WARNING: Removing unreachable block (CODE,0x0047cc) */
/* WARNING: Removing unreachable block (CODE,0x004730) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Per second: UI timeouts and screen updates */

byte ui_second_tick(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  undefined1 uVar10;
  undefined1 in_PRODL;
  byte unaff_C;
  bool bVar11;
  
  bVar7 = ui_menu_active;
  if (ui_menu_active == 0) {
    unaff_C = 0x1d < ui_screen;
    bVar7 = 0;
    if (ui_screen != 0x1e) {
      unaff_C = 0x1e < ui_screen;
      bVar7 = 0;
      if (((ui_screen != 0x1f) && (bVar7 = 0, ui_backlight_timeout != '\0')) &&
         (bVar7 = cfg_systemconfig5 & 0x80, bVar7 == 0)) {
        unaff_C = ui_backlight_timeout != '\0';
        ui_backlight_timeout = ui_backlight_timeout + -1;
        if (ui_backlight_timeout == '\0') {
          bVar7 = ui_get_PORTH_4f12();
          bVar9 = PORTC;
          PORTC = bVar9 & ~RC1;
        }
      }
    }
  }
  if ((cfg_systemconfig5 & 0x80) != 0) {
    ui_get_PORTH_4f04(bVar7);
    ui_backlight_timeout = '\x03';
  }
  if ((ui_menu_active == 0) && (ui_menu_param != '\0')) {
    unaff_C = ui_menu_param != '\0';
    ui_menu_param = ui_menu_param + -1;
  }
  if ((ui_screen == 4) || (ui_screen == 5)) {
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    bVar7 = clock_blink_update(0);
    return bVar7;
  }
  if ((((ui_screen == 0) || (ui_screen == 1)) || (ui_screen == 2)) || (ui_screen == 3)) {
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    clock_blink_update(0);
    ui_clock_block_tmp = replacement_days_left();
    bVar9 = ui_clock_suppressed;
    bVar7 = ui_clock_block_tmp;
    if ((ui_clock_block_tmp == 0) && (bVar7 = 0, ui_clock_suppressed != 0)) {
      ui_clock_suppressed = 0;
      bVar7 = clock_draw(bVar9);
    }
    ui_clock_suppressed = ui_clock_block_tmp;
    return bVar7;
  }
  if (ui_screen == 0x1f) {
    bVar7 = 0;
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
LAB_CODE_0047f8:
    bVar7 = menu_timer_tick(bVar7);
    return bVar7;
  }
  if (ui_screen == 0x14) {
    *(undefined1 *)in_FSR1 = 0;
    if ((ui_screen_timeout & 0x80) == 0) {
      bVar7 = *(byte *)in_FSR1;
      bVar11 = bVar7 < 0xfe || ui_screen_timeout < bVar7 + 2;
      bVar7 = (bVar7 - ui_screen_timeout) + 2;
    }
    else {
      bVar11 = (char)ui_screen_timeout < '\0';
      bVar7 = ui_screen_timeout << 1 | unaff_C & 1;
    }
    if (!bVar11) {
      ui_screen_timeout = ui_screen_timeout - 1;
    }
    goto LAB_CODE_0047f8;
  }
  if (ui_screen == 0x11) {
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    bVar7 = ui_to_gfx_anim_icon_b_4e66(0);
    if (bVar7 >= 5) {
      ui_dispense_state = 0;
    }
    bVar9 = ui_set_ui_blink_phase_4ef4('\x04' - bVar7);
    if (bVar7 < 5) {
      return bVar9;
    }
    if ((ui_blink_phase & 1) == 0) {
      ui_to_txt_to_text_draw_char_4fb2();
      ui_test_value_4f9a();
      *(undefined1 *)in_FSR1 = 7;
      puVar6 = (undefined1 *)((short)in_FSR1 + 1);
      bVar7 = ser_to_text_draw_word_5048(0xe);
      goto LAB_CODE_0047d6;
    }
    puVar6 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 6;
    uVar10 = 0x16;
  }
  else {
    if (ui_screen != 0x13) {
      if (ui_screen == 0xd) {
        if (ui_menu_active != 0) {
          return ui_menu_active;
        }
        pbVar3 = (byte *)((short)in_FSR1 + 1);
        *(byte *)in_FSR1 = ui_dispense_state;
        ui_dispense_state = ui_dispense_state + 1;
        gfx_anim_icon_c();
        puVar4 = pbVar3 + -1;
        *pbVar3 = *pbVar3;
        bVar11 = ui_dispense_state < 3;
        cVar8 = '\x02' - ui_dispense_state;
        if (!bVar11) {
          ui_dispense_state = 0;
        }
        bVar7 = ui_set_ui_blink_phase_4ef4(cVar8);
        if (bVar11) {
          return bVar7;
        }
        if ((ui_blink_phase & 1) == 0) {
          ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096();
          ui_to_eeprom_read_raw_4dd4(0x35);
          ui_to_ui_draw_temp_units_4d8e();
          *(undefined1 *)((ushort)puVar4 & 0xff00) = *(undefined1 *)((ushort)puVar4 & 0xff00);
          bVar7 = ser_set_ui_blink_phase_5074();
          return bVar7;
        }
        in_FSR1 = (BADSPACEBASE *)(puVar4 + 1);
        *puVar4 = 6;
        ui_to_ser_to_text_draw_word_4d7a(0xe);
        cVar8 = ui_get_cfg_systemconfig2_4e02();
        if (cVar8 == '\a') {
          return 0;
        }
      }
      else {
        if (((ui_screen == 0x19) || (ui_screen == 0x1d)) || (ui_screen == 0xb)) {
          bVar7 = -ui_hold_counter;
          if (ui_hold_counter == '\0') {
            return 0;
          }
          ui_hold_counter = ui_hold_counter + -1;
          return bVar7;
        }
        if (ui_screen == 0xf) {
          if (ui_menu_active != 0) {
            return ui_menu_active;
          }
          pbVar1 = (byte *)((short)in_FSR1 + 1);
          *(byte *)in_FSR1 = ui_dispense_state;
          ui_dispense_state = ui_dispense_state + 1;
          gfx_anim_icon_d();
          in_FSR1 = (BADSPACEBASE *)(pbVar1 + -1);
          *pbVar1 = *pbVar1;
          bVar11 = ui_dispense_state < 3;
          cVar8 = '\x02' - ui_dispense_state;
          if (!bVar11) {
            ui_dispense_state = 0;
          }
          bVar7 = ui_set_ui_blink_phase_4ef4(cVar8);
          if (bVar11) {
            return bVar7;
          }
          if ((ui_blink_phase & 1) == 0) {
            ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096();
            ui_to_eeprom_read_raw_4dd4(0x43);
            ui_to_ui_draw_temp_units_4d8e();
LAB_CODE_0046a0:
            puVar2 = (undefined1 *)((ushort)in_FSR1 & 0xff00);
            in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
            *puVar2 = *puVar2;
            ui_stack_adjust_4e78();
LAB_CODE_0046a6:
            bVar7 = ser_to_text_draw_word_5048();
            goto LAB_CODE_0046f4;
          }
          if (1 < (ui_blink_phase & 3)) goto LAB_CODE_004680;
LAB_CODE_004688:
          *(undefined1 *)in_FSR1 = 6;
          uVar10 = 0xb;
          in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
        }
        else {
          if (ui_screen == 9) {
            if (ui_menu_active != 0) {
              return ui_menu_active;
            }
            bVar7 = ui_to_gfx_anim_icon_a_4e54(0);
            if (bVar7 >= 3) {
              ui_dispense_state = 0;
            }
            bVar9 = ui_set_ui_blink_phase_4ef4('\x02' - bVar7);
            if (bVar7 < 3) {
              return bVar9;
            }
            if ((ui_blink_phase & 1) == 0) {
              ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096();
              ui_to_eeprom_read_raw_4dd4(0x3e);
              ui_to_ui_draw_temp_units_4d8e();
              goto LAB_CODE_0046a0;
            }
            if ((ui_blink_phase & 3) < 2) goto LAB_CODE_004688;
          }
          else {
            if ((ui_screen ^ 7) != 0) {
              return ui_screen ^ 7;
            }
            if (ui_menu_active != 0) {
              return ui_menu_active;
            }
            bVar7 = ui_to_gfx_anim_icon_a_4e54(0);
            if (4 < bVar7) {
              ui_dispense_state = 0;
            }
            bVar9 = ui_set_ui_blink_phase_4ef4('\x04' - bVar7);
            if (4 >= bVar7) {
              return bVar9;
            }
            if ((ui_blink_phase & 1) == 0) {
              ui_stack_adjust_4eca();
              goto LAB_CODE_0046a6;
            }
          }
LAB_CODE_004680:
          *(undefined1 *)in_FSR1 = 6;
          uVar10 = 0x16;
          in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
        }
        ui_to_ser_to_text_draw_word_4d7a(uVar10);
      }
      bVar7 = ser_push_args_01_txt_to_text_draw_char_5052();
LAB_CODE_0046f4:
      *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
      return bVar7;
    }
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    bVar7 = ui_to_gfx_anim_icon_b_4e66(0);
    if (2 < bVar7) {
      ui_dispense_state = 0;
    }
    bVar9 = ui_set_ui_blink_phase_4ef4('\x02' - bVar7);
    if (2 >= bVar7) {
      return bVar9;
    }
    if ((ui_blink_phase & 1) == 0) {
      ui_to_lcd_draw_glyph_4ca8();
      cVar8 = ser_to_ui_to_eeprom_read_raw_509c(0x42);
      if (local4 == '\0' && cVar8 == '\0') {
        ui_test_value_4f9a(0);
        ser_to_ui_to_eeprom_read_raw_509c(0x35);
      }
      if (local4 == '\0' && local3 == '\0') {
        ui_test_value_4f9a(0);
        ser_to_ui_to_eeprom_read_raw_509c(0x3e);
      }
      ui_stack_adjust_4ea0();
      c18_tmp0 = local3;
      c18_tmp1 = local4;
      ser_get_c18_tmp1_5010(10);
      *(undefined1 *)in_FSR1 = in_PRODL;
      puVar5 = (undefined1 *)((short)in_FSR1 + 2);
      *(char *)((short)in_FSR1 + 1) = c18_tmp1;
      c18_tmp2 = ui_draw_temp_units();
      if ((byte)puVar5 < 5) {
        *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
      }
      bVar7 = ser_set_ui_blink_phase_5074((byte)puVar5 - 5);
      return bVar7;
    }
    ui_test_value_4f9a();
    puVar6 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 6;
    uVar10 = 0xf;
  }
  ui_to_ser_to_text_draw_word_4d7a(uVar10);
  bVar7 = ser_push_args_01_txt_to_text_draw_char_5052();
LAB_CODE_0047d6:
  *puVar6 = *puVar6;
  return bVar7;
}


// ===== 0x004828 ui_10s_tick =====

/* Every 10 s: refresh idle screen / clock */

char ui_10s_tick(void)

{
  char cVar1;
  
  if ((ui_screen == '\0') || (cVar1 = ui_screen + -1, ui_screen + -1 == '\0')) {
    if (ui_menu_active != '\0') {
      cVar1 = lcd_clear(ui_menu_active);
      return cVar1;
    }
    cVar1 = ui_clock_suppressed;
    if (ui_clock_suppressed == '\0') {
      cVar1 = clock_draw(0);
    }
  }
  return cVar1;
}


// ===== 0x004844 ui_100ms_tick =====

/* Every 100 ms: UI countdown */

char ui_100ms_tick(void)

{
  char cVar1;
  
  cVar1 = -ui_countdown_100ms;
  if (ui_countdown_100ms != '\0') {
    ui_countdown_100ms = ui_countdown_100ms + -1;
  }
  return cVar1;
}


// ===== 0x004850 ui_get_buzzer_pattern_4850 =====

/* Auto: reads buzzer_pattern; 4 instr */

void ui_get_buzzer_pattern_4850(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  buzzer_pattern = *(undefined1 *)((short)in_FSR2 + -2);
  ui_c18_epilogue_4d6e();
  return;
}


// ===== 0x00485a keypad_scan =====

/* Scan 3x3 key matrix (rows RB4/RE6/RE7, columns RB5-RB7); returns 7-bit key mask */

byte keypad_scan(void)

{
  byte bVar1;
  
  local0 = 0;
  bVar1 = TRISB;
  TRISB = bVar1 & ~TRISB4;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB4;
  bVar1 = PORTB;
  if ((bVar1 & RB7) == 0) {
    local0 = 2;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB5) == 0) {
    local0 = local0 | 1;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    local0 = local0 | 4;
  }
  bVar1 = TRISB;
  TRISB = bVar1 | TRISB4;
  bVar1 = PORTB;
  PORTB = bVar1 | RB4;
  bVar1 = TRISE;
  TRISE = bVar1 & ~TRISE6;
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE6;
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    local0 = local0 | 0x40;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | TRISE6;
  bVar1 = PORTE;
  PORTE = bVar1 | RE6;
  bVar1 = TRISE;
  TRISE = bVar1 & ~TRISE7;
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE7;
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    local0 = local0 | 0x20;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB7) == 0) {
    local0 = local0 | 8;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB5) == 0) {
    local0 = local0 | 0x10;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | TRISE7;
  bVar1 = PORTE;
  PORTE = bVar1 | RE7;
  return local0;
}


// ===== 0x004894 ui_set_ui_alarm_index_4894 =====

/* Auto: writes ui_alarm_index,ui_blink_phase; reads ui_screen; 15 instr */

byte ui_set_ui_alarm_index_4894(void)

{
  if ((((ui_screen != 0xd) && (ui_screen != 9)) && (ui_screen != 0x13)) && ((ui_screen ^ 0xf) != 0))
  {
    return ui_screen ^ 0xf;
  }
  ui_alarm_index = 1;
  ui_blink_phase = 0;
  return 1;
}


// ===== 0x0048b2 ui_draw_home_info =====

/* Draw home-screen information (temperatures / clock area) */

void ui_draw_home_info(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  char cVar18;
  undefined1 uVar19;
  BADSPACEBASE *in_FSR0;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  ui_frag_4c90();
  bVar5 = (byte)in_FSR1;
  if (0xea < bVar5) {
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),0xff);
    in_FSR1 = (BADSPACEBASE *)(puVar7 + 1);
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),bVar5 + 0x15);
  *puVar8 = 0x14;
  puVar8[1] = 0;
  puVar9 = puVar8 + 3;
  puVar8[2] = 0x20;
  ui_stack_adjust_4f80();
  c18_tmp0 = mod_frag_f55e();
  bVar5 = (byte)puVar9;
  if (bVar5 < 5) {
    puVar10 = (undefined1 *)((ushort)puVar9 & 0xff00);
    puVar9 = puVar10 + -1;
    *puVar10 = *puVar10;
  }
  puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar9 >> 8),bVar5 - 5);
  cVar18 = ui_get_cfg_systemconfig2_4e02(c18_tmp0);
  if (cVar18 == '\x05') {
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
    *(undefined1 *)((short)in_FSR2 + 0x15) = 0;
  }
  else {
    c18_tmp0 = 0x6c;
    c18_tmp1 = 0x53;
    c18_tmp2 = 0;
    *puVar11 = 0x6c;
    puVar11[1] = 0x53;
    puVar12 = puVar11 + 3;
    puVar11[2] = c18_tmp2;
    ui_stack_adjust_4f80();
    c18_tmp3 = strcpy_rom2ram();
    bVar5 = (byte)puVar12;
    if (bVar5 < 5) {
      puVar13 = (undefined1 *)((ushort)puVar12 & 0xff00);
      puVar12 = puVar13 + -1;
      *puVar13 = *puVar13;
    }
    puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar12 >> 8),bVar5 - 5);
    *(undefined1 *)((short)in_FSR2 + 0x15) = 4;
    in_PRODL = 0x20;
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + 5) = 0x20;
  }
  if (cooling_fault == -0x76) {
    ui_frag_4ff2();
    uVar19 = 0x39;
LAB_CODE_00494a:
    ui_get_c18_tmp0_4f48(uVar19);
  }
  else {
    if (cooling_fault == -0x71) {
      ui_frame_access_4be8();
      uVar19 = 0x31;
      goto LAB_CODE_00494a;
    }
    if (cooling_fault == -0x73) {
      ui_frame_access_4be8();
      uVar19 = 0x32;
      goto LAB_CODE_00494a;
    }
  }
  if (heating_fault == -0x72) {
    ui_frame_access_4be8();
    uVar19 = 0x37;
LAB_CODE_004976:
    ui_get_c18_tmp0_4f48(uVar19);
  }
  else {
    if (heating_fault == -0x76) {
      ui_frag_4f6e();
      uVar19 = 0x30;
      goto LAB_CODE_004976;
    }
    if (heating_fault == -0x71) {
      ui_frame_access_4be8();
      uVar19 = 0x35;
      goto LAB_CODE_004976;
    }
    if (heating_fault == -0x73) {
      ui_frame_access_4be8();
      uVar19 = 0x36;
      goto LAB_CODE_004976;
    }
  }
  if (compressor_fault == -0x7c) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x34);
  }
  if (heater_fault == -0x7c) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x38);
  }
  if (uv_alarm_code == -0x75) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x33);
  }
  if (inlet_valve_fault == -0x7c) {
    ui_frag_4ff2(0);
    ui_get_c18_tmp0_4f48(0x31);
  }
  if (cold_valve_fault == -0x7c) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x39);
  }
  if (hot_valve_fault == -0x7c) {
    ui_frag_4ff2(0);
    ui_get_c18_tmp0_4f48(0x30);
  }
  if (uv_alarm_code == -0x7e) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x31);
  }
  if (device_sensor_fault == -0x71) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x32);
  }
  if (device_sensor_fault == -0x73) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x33);
  }
  if (dryer_sensor_fault == -0x71) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x34);
  }
  if (dryer_sensor_fault == -0x73) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x35);
  }
  bVar5 = 0xe;
  if (uv_alarm_code == -0x70) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x36);
  }
  cVar18 = ui_get_cfg_systemconfig2_4e02();
  if (cVar18 == '\x05') {
    puVar3 = puVar2 + 1;
    pcVar1 = puVar2 + 0x15;
    puVar2 = puVar2 + 1;
    uVar19 = 0;
    if (*pcVar1 != '\0') {
      ui_get_c18_tmp0_4ed4(*pcVar1);
      ser_ptr_add_5022();
      *(undefined1 *)in_FSR0 = 0x20;
      *puVar11 = 5;
      puVar14 = puVar11 + 2;
      puVar11[1] = 0x17;
      word_lookup_a();
      c18_tmp0 = in_PRODL;
      *puVar14 = *puVar14;
      puVar14[-1] = puVar14[-1];
      c18_tmp2 = 0;
      c18_tmp1 = in_PRODH;
      puVar14[-2] = c18_tmp0;
      puVar14[-1] = in_PRODH;
      *puVar14 = c18_tmp2;
      c18_tmp5 = SUB21(puVar3,0);
      c18_tmp6 = (undefined1)((ushort)puVar3 >> 8);
      puVar2 = puVar3 + 1;
      bVar5 = 0;
      bVar6 = (byte)(puVar3 + 1) + puVar3[0x15];
      c18_tmp3 = bVar6 + 1;
      c18_tmp4 = (char)((ushort)(puVar3 + 1) >> 8) + CARRY1((byte)(puVar3 + 1),puVar3[0x15]) +
                 (0xfe < bVar6);
      puVar14[1] = c18_tmp3;
      puVar15 = puVar14 + 3;
      puVar14[2] = c18_tmp4;
      c18_tmp7 = strcpy_rom2ram();
      bVar6 = (byte)puVar15;
      if (bVar6 < 5) {
        puVar16 = (undefined1 *)((ushort)puVar15 & 0xff00);
        puVar15 = puVar16 + -1;
        *puVar16 = *puVar16;
      }
      puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar15 >> 8),bVar6 - 5);
      uVar19 = c18_tmp7;
    }
  }
  else {
    ui_get_c18_tmp0_4ed4();
    uVar19 = ser_ptr_add_5022();
    *(undefined1 *)in_FSR0 = 0;
  }
  cVar18 = ui_get_cfg_systemconfig2_4e02(uVar19);
  puVar4 = puVar2;
  if (cVar18 == '\x05') {
LAB_CODE_004aaa:
    if ((*(byte *)((ushort)bVar5 * 0x100 + 0x58) & 0x38) == 0x28) {
      if (puVar4[0x15] != '\0') goto LAB_CODE_004ac0;
    }
    c18_tmp0 = 0;
  }
  else {
    puVar4 = puVar2 + 1;
    if ((byte)puVar2[0x15] < 5) goto LAB_CODE_004aaa;
LAB_CODE_004ac0:
    ui_to_text_draw_char_4fa8(7);
    puVar17 = puVar11 + 1;
    *puVar11 = 0x12;
    ui_callw_fncfc6_4c62(7);
    ser_chain_fn4f80_fn5036_50b2();
    c18_tmp0 = 1;
    puVar11 = puVar17;
  }
  if ((byte)puVar11 < 0x15) {
    *(undefined1 *)((ushort)puVar11 & 0xff00) = *(undefined1 *)((ushort)puVar11 & 0xff00);
  }
  ui_c18_epilogue_4d6e(c18_tmp0);
  return;
}


// ===== 0x004ae6 ui_get_ui_screen_4ae6 =====

/* Auto: reads ui_screen; 3 instr */

void ui_get_ui_screen_4ae6(void)

{
  ui_return_screen = ui_screen;
  ui_to_clock_display_off_4e84();
  return;
}


// ===== 0x004af0 ui_to_ui_select_home_screen_4af0 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: calls ui_select_home_screen; 1 instr */

byte ui_to_ui_select_home_screen_4af0(void)

{
  if (ui_return_screen == 0x14) {
    ui_screen = 0;
    return 0;
  }
  if (ui_return_screen == 0x1f) {
    ui_screen = 0x1e;
  }
  else {
    if (ui_return_screen == 0x1d) {
      ui_screen = 0;
      return 0;
    }
    if (ui_return_screen == 0x1c) {
      ui_screen = 0x1b;
    }
    else if (ui_return_screen == 5) {
      ui_screen = 4;
    }
    else {
      if (ui_return_screen != 3) {
        if ((ui_return_screen ^ 1) == 0) {
          ui_screen = 0;
          return 0;
        }
        ui_screen = ui_return_screen;
        return ui_return_screen ^ 1;
      }
      ui_screen = 2;
    }
  }
  return ui_screen;
}


// ===== 0x004af4 ui_select_home_screen =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Map current screen to its home/return screen */

byte ui_select_home_screen(void)

{
  if (ui_return_screen == 0x14) {
    ui_screen = 0;
    return 0;
  }
  if (ui_return_screen == 0x1f) {
    ui_screen = 0x1e;
  }
  else {
    if (ui_return_screen == 0x1d) {
      ui_screen = 0;
      return 0;
    }
    if (ui_return_screen == 0x1c) {
      ui_screen = 0x1b;
    }
    else if (ui_return_screen == 5) {
      ui_screen = 4;
    }
    else {
      if (ui_return_screen != 3) {
        if ((ui_return_screen ^ 1) == 0) {
          ui_screen = 0;
          return 0;
        }
        ui_screen = ui_return_screen;
        return ui_return_screen ^ 1;
      }
      ui_screen = 2;
    }
  }
  return ui_screen;
}


// ===== 0x004b32 replacement_days_left =====

/* Compute days to next filter/UV replacement */

void replacement_days_left(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  bool bVar5;
  
  ui_frag_4c90();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  uVar4 = ui_to_eeprom_read_raw_4dd4(0x40);
  *(undefined1 *)in_FSR2 = uVar4;
  c18_tmp4 = *(undefined1 *)in_FSR2;
  c18_tmp5 = 0;
  ui_get_TBLPTRH_4e1a(0xfc);
  if ((c18_tmp1 & 0x80) != 0) {
    c18_tmp2 = 0xff;
    c18_tmp3 = 0xff;
  }
  if (((bDATA00ed ^ c18_tmp3) & 0x80) == 0) {
    bVar1 = ~(bDATA00eb < (byte)~(c18_tmp0 <= stat_GFI) ||
             c18_tmp1 < bDATA00eb - ~(c18_tmp0 <= stat_GFI));
    bVar1 = ~(bDATA00ec < bVar1 || c18_tmp2 < bDATA00ec - bVar1);
    bVar5 = bDATA00ed < bVar1 || c18_tmp3 < bDATA00ed - bVar1;
  }
  else {
    bVar5 = (char)c18_tmp3 < '\0';
  }
  if (bVar5) {
    puVar3 = puVar2 + 1;
    *puVar2 = 7;
    uVar4 = 0x18;
LAB_CODE_004bbe:
    ui_to_ser_to_text_draw_word_4d7a(uVar4);
    uVar4 = 1;
    puVar2 = puVar3;
  }
  else {
    if ((cfg_systemconfig4 & 0x20) != 0) {
      c18_tmp4 = *(undefined1 *)in_FSR2;
      c18_tmp5 = 0;
      ui_get_TBLPTRH_4e1a(0xfc);
      if ((c18_tmp1 & 0x80) != 0) {
        c18_tmp2 = 0xff;
        c18_tmp3 = 0xff;
      }
      if (((bDATA00e9 ^ c18_tmp3) & 0x80) == 0) {
        bVar1 = ~(bDATA00e7 < (byte)~(c18_tmp0 <= stat_GUV) ||
                 c18_tmp1 < bDATA00e7 - ~(c18_tmp0 <= stat_GUV));
        bVar1 = ~(bDATA00e8 < bVar1 || c18_tmp2 < bDATA00e8 - bVar1);
        bVar5 = bDATA00e9 < bVar1 || c18_tmp3 < bDATA00e9 - bVar1;
      }
      else {
        bVar5 = (char)c18_tmp3 < '\0';
      }
      if (bVar5) {
        puVar3 = puVar2 + 1;
        *puVar2 = 7;
        uVar4 = 0x19;
        goto LAB_CODE_004bbe;
      }
    }
    uVar4 = 0;
  }
  *puVar2 = *puVar2;
  ui_c18_epilogue_4d6e(uVar4);
  return;
}


// ===== 0x004bcc ui_return_0x01_4bcc =====

/* Auto: Return constant 0x01; 1 instr */

undefined1 ui_return_0x01_4bcc(void)

{
  return 1;
}


// ===== 0x004bce ui_get_ui_heater_indicator_4bce =====

/* Auto: reads ui_heater_indicator; 4 instr */

void ui_get_ui_heater_indicator_4bce(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  ui_heater_indicator = *(undefined1 *)((short)in_FSR2 + -2);
  ui_c18_epilogue_4d6e();
  return;
}


// ===== 0x004bd8 ui_get_ui_compressor_indicator_4bd8 =====

/* Auto: reads ui_compressor_indicator; 4 instr */

void ui_get_ui_compressor_indicator_4bd8(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  ui_compressor_indicator = *(undefined1 *)((short)in_FSR2 + -2);
  ui_c18_epilogue_4d6e();
  return;
}


// ===== 0x004be2 ui_get_ui_clock_block_tmp_4be2 =====

/* Auto: reads ui_clock_block_tmp; 3 instr */

undefined1 ui_get_ui_clock_block_tmp_4be2(void)

{
  return ui_clock_block_tmp;
}


// ===== 0x004be8 ui_frame_access_4be8 =====

/* Auto: Access stack-frame local/argument; 5 instr */

void ui_frame_access_4be8(void)

{
  undefined1 in_FramePointer2_00000015;
  
  ser_ptr_add_5022(in_FramePointer2_00000015);
  return;
}


// ===== 0x004bf6 temp_c_to_f =====

/* Convert deg C to deg F (x9/5+32) */

undefined1 temp_c_to_f(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte in_PRODL;
  
  ui_stack_adjust_4f80();
  c18_tmp0 = *(undefined1 *)((short)in_FSR2 + 6);
  c18_tmp1 = *(char *)((short)in_FSR2 + 8);
  bVar1 = in_PRODL;
  ser_get_c18_tmp1_5010(9);
  math_aarg_lo = bVar1;
  math_barg_lo = 5;
  math_barg_hi = 0;
  math_aarg_hi = c18_tmp1;
  __divs16();
  c18_tmp0 = math_aarg_lo + 0x20;
  c18_tmp1 = math_aarg_hi + (0xdf < math_aarg_lo);
  *(char *)in_FSR1 = c18_tmp0;
  *(char *)((short)in_FSR1 + 1) = c18_tmp1;
  return 0;
}


// ===== 0x004c34 ui_bank1_ui_get_cfg_systemconfig5_4c34 =====

/* Auto: Select bank then jump to ui_get_cfg_systemconfig5; 2 instr */

void ui_bank1_ui_get_cfg_systemconfig5_4c34(void)

{
  ui_get_cfg_systemconfig5_4f8a();
  return;
}


// ===== 0x004c3a ui_calc_array_ptr_4c3a =====

/* Auto: Compute array element address in FSR0; 7 instr */

char ui_calc_array_ptr_4c3a(void)

{
  byte in_FSR2L;
  char in_FSR2H;
  
  return in_FSR2H + (0xfa < in_FSR2L);
}


// ===== 0x004c48 ui_callw_mod_set_lcd_text_flag_4c48 =====

/* Auto: Push W as argument and call mod_set_lcd_text_flag; 5 instr */

void ui_callw_mod_set_lcd_text_flag_4c48(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_lcd_text_flag_ca68();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x004c54 ui_to_mod_get_lcd_text_width_4c54 =====

/* Auto: Small wrapper around mod_get_lcd_text_width; 6 instr */

void ui_to_mod_get_lcd_text_width_4c54(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ser_chain_fn4f80_fn5036_50b2();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x20;
  mod_get_lcd_text_width_ca24();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004c62 ui_callw_fncfc6_4c62 =====

/* Auto: Push W as argument and call 0xcfc6; 5 instr */

void ui_callw_fncfc6_4c62(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x004c6e ui_to_gfx_draw_frame_right_4c6e =====

/* Auto: calls gfx_draw_frame_right,gfx_draw_frame_left; 14 instr */

void ui_to_gfx_draw_frame_right_4c6e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  gfx_draw_frame_right();
  *(undefined1 *)in_FSR1 = 0x40;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0x47;
  ui_to_gfx_bitmap_blit_4fa0(1);
  gfx_draw_frame_left();
  *puVar1 = 0x40;
  puVar1[1] = 0x42;
  ui_to_gfx_bitmap_blit_4fa0(1);
  return;
}


// ===== 0x004c90 ui_frag_4c90 =====

/* Auto: compiler fragment: RCALL 0x004f80 ; MOVFF FSR1L,FSR2L ; MOVFF FSR1H,FSR2H ; RETURN 0x0 */

void ui_frag_4c90(void)

{
  ui_stack_adjust_4f80();
  return;
}


// ===== 0x004c9c ui_to_fmt_byte_4c9c =====

/* Auto: calls fmt_byte; 4 instr */

void ui_to_fmt_byte_4c9c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ui_stack_adjust_4f80();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + 6);
  fmt_byte();
  return;
}


// ===== 0x004ca8 ui_to_lcd_draw_glyph_4ca8 =====

/* Auto: writes text_fill_width; calls lcd_draw_glyph; 12 instr */

void ui_to_lcd_draw_glyph_4ca8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  text_fill_width = 0x5b;
  puVar1 = &FramePointer10x0004;
  lcd_draw_glyph();
  *puVar1 = *puVar1;
  ser_pop3_return_50b8();
  return;
}


// ===== 0x004cc2 filter_usage_calc =====

/* Filter usage from FWU counter and WATERFLOW */

void filter_usage_calc(void)

{
  ui_stack_adjust_4f80();
  math_aarg_b3 = ui_to_eeprom_read_param_4f64(0x26);
  c18_tmp5 = 0;
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  math_res0 = stat_IWS;
  math_res1 = DAT_DATA_00bb;
  math_aarg_lo = DAT_DATA_00bc;
  math_aarg_hi = DAT_DATA_00bd;
  math_barg_b0 = 0;
  math_barg_lo = 0;
  math_barg_hi = 0;
  c18_tmp4 = math_aarg_b3;
  __mul32();
  c18_tmp0 = math_tmp2;
  c18_tmp1 = math_tmp3;
  c18_tmp2 = math_rem_lo;
  c18_tmp3 = math_rem_hi;
  return;
}


// ===== 0x004d04 ui_to_clock_display_off_4d04 =====

/* Auto: calls clock_display_off; 4 instr */

void ui_to_clock_display_off_4d04(void)

{
  clock_display_off();
  ui_to_text_draw_char_4fa8(2);
  ui_to_txt_to_text_draw_char_4fb2();
  return;
}


// ===== 0x004d10 ui_get_c18_tmp0_4d10 =====

/* Auto: reads c18_tmp0,c18_tmp1,cfg_systemconfig3; 8 instr */

byte ui_get_c18_tmp0_4d10(void)

{
  return cfg_systemconfig3 & 4;
}


// ===== 0x004d24 ui_scale_mul =====

/* Multiply/divide helper for display values */

char ui_scale_mul(byte param_1)

{
  BADSPACEBASE *in_FSR1;
  char cVar1;
  
  c18_tmp7 = 0;
  math_aarg_lo = (byte)((ushort)c18_tmp4 * (ushort)param_1);
  math_aarg_hi = (char)((ushort)c18_tmp4 * (ushort)param_1 >> 8) + c18_tmp5 * param_1;
  math_barg_lo = c18_tmp8;
  math_barg_hi = c18_tmp9;
  c18_tmp2 = math_aarg_lo;
  c18_tmp3 = math_aarg_hi;
  c18_tmp6 = param_1;
  __divs16();
  c18_tmp0 = c18_tmp10 + math_aarg_lo;
  c18_tmp1 = c18_tmp11 + math_aarg_hi + CARRY1(c18_tmp10,math_aarg_lo);
  cVar1 = c18_tmp1;
  DAT_DATA_0118 = c18_tmp0;
  *(char *)in_FSR1 = c18_tmp0;
  return cVar1;
}


// ===== 0x004d6e ui_c18_epilogue_4d6e =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void ui_c18_epilogue_4d6e(void)

{
  return;
}


// ===== 0x004d7a ui_to_ser_to_text_draw_word_4d7a =====

/* Auto: Small wrapper around ser_to_text_draw_word; 3 instr */

void ui_to_ser_to_text_draw_word_4d7a(void)

{
  BADSPACEBASE *in_FSR1;
  
  ser_to_text_draw_word_5048();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x004d80 ui_to_child_protect_is_active_4d80 =====

/* Auto: reads cfg_systemconfig; calls child_protect_is_active; 6 instr */

byte ui_to_child_protect_is_active_4d80(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = child_protect_is_active();
  *(undefined1 *)in_FSR1 = uVar1;
  return cfg_systemconfig & 8;
}


// ===== 0x004d8e ui_to_ui_draw_temp_units_4d8e =====

/* Auto: reads c18_tmp0,c18_tmp1; calls ui_draw_temp_units; 9 instr */

char ui_to_ui_draw_temp_units_4d8e(void)

{
  char cVar1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  cVar1 = '\x02';
  c18_tmp0 = in_PRODL;
  c18_tmp1 = in_PRODH;
  c18_tmp2 = ui_draw_temp_units();
  return cVar1 + -5;
}


// ===== 0x004daa ui_to_ltoa_4daa =====

/* Auto: reads math_res0,math_res1,math_aarg_lo,math_aarg_hi; calls ltoa; 10 instr */

char ui_to_ltoa_4daa(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  
  ui_get_math_res0_4fdc();
  *(undefined1 *)in_FSR1 = math_res0;
  *(undefined1 *)((short)in_FSR1 + 1) = math_res1;
  *(undefined1 *)((short)in_FSR1 + 2) = math_aarg_lo;
  cVar1 = (char)(undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = math_aarg_hi;
  c18_tmp8 = ltoa();
  return cVar1 + -6;
}


// ===== 0x004dc8 ui_push_args_85_ui_set_ui_message_timer_4dc8 =====

/* Auto: Push constant arguments [133] then call ui_set_ui_message_timer; 5 instr */

void ui_push_args_85_ui_set_ui_message_timer_4dc8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_set_ui_message_timer_3afc();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004dd4 ui_to_eeprom_read_raw_4dd4 =====

/* Auto: calls eeprom_read_raw; 4 instr */

void ui_to_eeprom_read_raw_4dd4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004dde ui_stack_adjust_4dde =====

/* Auto: Software stack push/pop helper; 3 instr */

void ui_stack_adjust_4dde(void)

{
  BADSPACEBASE *in_FSR1;
  
  ser_push_args_01_txt_to_text_draw_char_5052();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x004de4 ui_param_tboil_4de4 =====

/* Auto: reads params TBOIL,TDELTAHOTTOPNORMALCUTOUT; reads c18_tmp0; 10 instr */

char ui_param_tboil_4de4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  c18_tmp0 = ui_to_eeprom_read_param_4f64(0x15);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = c18_tmp0;
  cVar2 = ui_to_eeprom_read_param_4f64(0x16);
  *puVar1 = *puVar1;
  c18_tmp0 = puVar1[-1];
  return puVar1[-1] - cVar2;
}


// ===== 0x004dfa ui_to_ser_set_ui_screen_4dfa =====

/* Auto: Small wrapper around ser_set_ui_screen; 4 instr */

void ui_to_ser_set_ui_screen_4dfa(void)

{
  ser_set_ui_screen_5080();
  return;
}


// ===== 0x004e02 ui_get_cfg_systemconfig2_4e02 =====

/* Auto: reads cfg_systemconfig2; 7 instr */

byte ui_get_cfg_systemconfig2_4e02(void)

{
  return (cfg_systemconfig2 & 0x38) >> 3;
}


// ===== 0x004e10 ui_set_ui_screen_4e10 =====

/* Auto: writes ui_screen,ui_alarm_index,ui_blink_phase; 5 instr */

undefined1 ui_set_ui_screen_4e10(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x1a) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x1b) = 100;
  return 100;
}


// ===== 0x004e1a ui_get_TBLPTRH_4e1a =====

/* Auto: reads TBLPTRH,TABLAT; 12 instr */

char ui_get_TBLPTRH_4e1a(undefined1 param_1)

{
  byte bVar1;
  undefined3 in_TBLPTR;
  byte *pbVar2;
  
  pbVar2 = (byte *)CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(param_1,(char)in_TBLPTR));
  bVar1 = *pbVar2;
  c18_tmp0 = bVar1 - c18_tmp4;
  c18_tmp1 = (pbVar2[1] - c18_tmp5) - ~(c18_tmp4 <= bVar1);
  c18_tmp2 = 0;
  c18_tmp3 = 0;
  return c18_tmp1;
}


// ===== 0x004e32 ui_to_ui_get_buzzer_pattern_4e32 =====

/* Auto: Small wrapper around ui_get_buzzer_pattern; 5 instr */

void ui_to_ui_get_buzzer_pattern_4e32(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_get_buzzer_pattern_4850();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004e3c ui_frame_access_4e3c =====

/* Auto: Access stack-frame local/argument; 6 instr */

undefined1 ui_frame_access_4e3c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ui_stack_adjust_4f80();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + 6);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + 8);
  return 6;
}


// ===== 0x004e4c ui_to_ui_draw_label_value_4e4c =====

/* Auto: calls ui_draw_label_value; 3 instr */

void ui_to_ui_draw_label_value_4e4c(void)

{
  ui_draw_label_value();
  ser_pop3_return_50b8();
  return;
}


// ===== 0x004e54 ui_to_gfx_anim_icon_a_4e54 =====

/* Auto: writes ui_dispense_state; reads ui_dispense_state; calls gfx_anim_icon_a; 8 instr */

undefined1 ui_to_gfx_anim_icon_a_4e54(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) = *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + '\x01';
  puVar1 = &FramePointer10x0001;
  gfx_anim_icon_a();
  *puVar1 = *puVar1;
  return ui_dispense_state;
}


// ===== 0x004e66 ui_to_gfx_anim_icon_b_4e66 =====

/* Auto: writes ui_dispense_state; reads ui_dispense_state; calls gfx_anim_icon_b; 8 instr */

undefined1 ui_to_gfx_anim_icon_b_4e66(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) = *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + '\x01';
  puVar1 = &FramePointer10x0001;
  gfx_anim_icon_b();
  *puVar1 = *puVar1;
  return ui_dispense_state;
}


// ===== 0x004e78 ui_stack_adjust_4e78 =====

/* Auto: Software stack push/pop helper; 6 instr */

undefined1 ui_stack_adjust_4e78(undefined1 param_1)

{
  BADSPACEBASE *in_FSR1;
  
  *(undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),param_1) = 6;
  return 0x56;
}


// ===== 0x004e84 ui_to_clock_display_off_4e84 =====

/* Auto: writes ui_screen; calls clock_display_off; 3 instr */

void ui_to_clock_display_off_4e84(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100) = 0x14;
  clock_display_off();
  return;
}


// ===== 0x004e8c ui_get_cfg_systemconfig2_4e8c =====

/* Auto: reads cfg_systemconfig2; 5 instr */

byte ui_get_cfg_systemconfig2_4e8c(void)

{
  return cfg_systemconfig2 & 1;
}


// ===== 0x004e96 ui_get_cfg_systemconfig3_4e96 =====

/* Auto: reads cfg_systemconfig3; 5 instr */

byte ui_get_cfg_systemconfig3_4e96(void)

{
  return cfg_systemconfig3 & 0x10;
}


// ===== 0x004ea0 ui_stack_adjust_4ea0 =====

/* Auto: Software stack push/pop helper; 5 instr */

undefined1 ui_stack_adjust_4ea0(void)

{
  return 0x66;
}


// ===== 0x004eaa ui_to_fmt_int_4eaa =====

/* Auto: calls fmt_int; 3 instr */

void ui_to_fmt_int_4eaa(void)

{
  BADSPACEBASE *in_FSR1;
  
  fmt_int();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x004eb2 ui_param_dbnccntr_4eb2 =====

/* Auto: reads params DBNCCNTR; writes keys_changed; 5 instr */

void ui_param_dbnccntr_4eb2(void)

{
  keys_changed = ui_to_eeprom_read_param_4f64(0x30);
  return;
}


// ===== 0x004ebc ui_to_dispense_hot_request_4ebc =====

/* Auto: writes ui_screen,ui_countdown_100ms; calls dispense_hot_request; 6 instr */

void ui_to_dispense_hot_request_4ebc(void)

{
  ui_screen = 0x10;
  ui_countdown_100ms = 10;
  dispense_hot_request();
  return;
}


// ===== 0x004eca ui_stack_adjust_4eca =====

/* Auto: Software stack push/pop helper; 5 instr */

undefined1 ui_stack_adjust_4eca(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_to_txt_to_text_draw_char_4fb2();
  *(undefined1 *)in_FSR1 = 7;
  return 0xb;
}


// ===== 0x004ed4 ui_get_c18_tmp0_4ed4 =====

/* Auto: reads c18_tmp0,c18_tmp1; 6 instr */

undefined1 ui_get_c18_tmp0_4ed4(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 in_FramePointer2_00000017;
  
  c18_tmp0 = 0;
  c18_tmp1 = (char)((ushort)in_FSR2 >> 8);
  return in_FramePointer2_00000017;
}


// ===== 0x004ee4 ui_get_ui_screen_4ee4 =====

/* Auto: reads ui_screen; 4 instr */

char ui_get_ui_screen_4ee4(void)

{
  return ui_screen + -0x14;
}


// ===== 0x004eec ui_stack_adjust_4eec =====

/* Auto: Software stack push/pop helper; 4 instr */

undefined1 ui_stack_adjust_4eec(void)

{
  return 0x53;
}


// ===== 0x004ef4 ui_set_ui_blink_phase_4ef4 =====

/* Auto: writes ui_blink_phase; reads ui_blink_phase; 4 instr */

char ui_set_ui_blink_phase_4ef4(void)

{
  char cVar1;
  byte unaff_BSR;
  
  cVar1 = *(char *)((ushort)unaff_BSR * 0x100 + 0x1b);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x1b) = *(char *)((ushort)unaff_BSR * 0x100 + 0x1b) + -1;
  return -cVar1;
}


// ===== 0x004efc ui_to_ui_to_eeprom_read_param_4efc =====

/* Auto: Small wrapper around ui_to_eeprom_read_param; 4 instr */

undefined1 ui_to_ui_to_eeprom_read_param_4efc(void)

{
  local0 = ui_to_eeprom_read_param_4f64();
  return local0;
}


// ===== 0x004f04 ui_get_PORTH_4f04 =====

/* Auto: reads PORTH,PORTB,PORTC; 7 instr */

void ui_get_PORTH_4f04(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 | RH7;
  bVar1 = PORTB;
  PORTB = bVar1 | RB0;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB1;
  bVar1 = PORTC;
  PORTC = bVar1 | RC0;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC1;
  return;
}


// ===== 0x004f12 ui_get_PORTH_4f12 =====

/* Auto: reads PORTH,PORTB,PORTC; 5 instr */

void ui_get_PORTH_4f12(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH7;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB0;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB1;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC0;
  return;
}


// ===== 0x004f1c ui_set_heater_output_enable_4f1c =====

/* Auto: writes heater_output_enable; reads TRISG; 5 instr */

undefined1 ui_set_heater_output_enable_4f1c(void)

{
  byte bVar1;
  
  bVar1 = TRISG;
  TRISG = bVar1 & ~TRISG0;
  heater_output_enable = 1;
  return 1;
}


// ===== 0x004f26 ui_stack_adjust_4f26 =====

/* Auto: Software stack push/pop helper; 5 instr */

void ui_stack_adjust_4f26(void)

{
  return;
}


// ===== 0x004f30 ui_to_dispense_stop_all_4f30 =====

/* Auto: calls dispense_stop_all,inlet_valve_close; 2 instr */

void ui_to_dispense_stop_all_4f30(void)

{
  dispense_stop_all();
  inlet_valve_close();
  return;
}


// ===== 0x004f38 ui_get_ui_screen_4f38 =====

/* Auto: reads ui_screen; 4 instr */

char ui_get_ui_screen_4f38(void)

{
  return ui_screen + -0x1b;
}


// ===== 0x004f40 ui_to_child_protect_is_active_4f40 =====

/* Auto: calls child_protect_is_active; 3 instr */

undefined1 ui_to_child_protect_is_active_4f40(void)

{
  undefined1 uVar1;
  
  uVar1 = child_protect_is_active();
  return uVar1;
}


// ===== 0x004f48 ui_get_c18_tmp0_4f48 =====

/* Auto: reads c18_tmp0,c18_tmp1; 7 instr */

undefined1 ui_get_c18_tmp0_4f48(void)

{
  undefined1 in_FSR2L;
  undefined1 in_FSR2H;
  BADSPACEBASE *in_FSR0;
  
  c18_tmp0 = in_FSR2L;
  c18_tmp1 = in_FSR2H;
  ui_frame_access_4be8();
  *(undefined1 *)in_FSR0 = 0x2c;
  return 0x2c;
}


// ===== 0x004f5a ui_stack_adjust_4f5a =====

/* Auto: Software stack push/pop helper; 4 instr */

void ui_stack_adjust_4f5a(void)

{
  ser_test_value_50aa();
  return;
}


// ===== 0x004f64 ui_to_eeprom_read_param_4f64 =====

/* Auto: calls eeprom_read_param; 4 instr */

void ui_to_eeprom_read_param_4f64(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004f6e ui_frag_4f6e =====

/* Auto: compiler fragment: RCALL 0x004be8 ; MOVLW #0x32 ; MOVWF INDF0,ACCESS ; GOTO 0x004be8 */

void ui_frag_4f6e(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_frame_access_4be8();
  *(undefined1 *)in_FSR0 = 0x32;
  ui_frame_access_4be8();
  return;
}


// ===== 0x004f78 ui_test_value_4f78 =====

/* Auto: compiler fragment: RCALL 0x004c3a ; MOVLW #0xfe ; XORWF POSTINC0,w,ACCESS ; RETURN 0x0 */

byte ui_test_value_4f78(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_calc_array_ptr_4c3a();
  return *(byte *)in_FSR0 ^ 0xfe;
}


// ===== 0x004f80 ui_stack_adjust_4f80 =====

/* Auto: Software stack push/pop helper; 3 instr */

void ui_stack_adjust_4f80(void)

{
  return;
}


// ===== 0x004f8a ui_get_cfg_systemconfig5_4f8a =====

/* Auto: reads cfg_systemconfig5; 8 instr */

byte ui_get_cfg_systemconfig5_4f8a(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}


// ===== 0x004f9a ui_test_value_4f9a =====

/* Auto: compiler fragment: RCALL 0x004c34 ; SUBLW #0x3 ; RETURN 0x0 */

char ui_test_value_4f9a(void)

{
  char cVar1;
  
  cVar1 = ui_bank1_ui_get_cfg_systemconfig5_4c34();
  return '\x03' - cVar1;
}


// ===== 0x004fa0 ui_to_gfx_bitmap_blit_4fa0 =====

/* Auto: calls gfx_bitmap_blit; 3 instr */

void ui_to_gfx_bitmap_blit_4fa0(void)

{
  gfx_bitmap_blit();
  ser_pop3_return_50b8();
  return;
}


// ===== 0x004fa8 ui_to_text_draw_char_4fa8 =====

/* Auto: calls text_draw_char; 4 instr */

void ui_to_text_draw_char_4fa8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_char();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004fb2 ui_to_txt_to_text_draw_char_4fb2 =====

/* Auto: Small wrapper around txt_to_text_draw_char; 4 instr */

void ui_to_txt_to_text_draw_char_4fb2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  txt_to_text_draw_char_93ba();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x004fbc ui_to_ui_to_fmt_byte_4fbc =====

/* Auto: Small wrapper around ui_to_fmt_byte; 5 instr */

void ui_to_ui_to_fmt_byte_4fbc(void)

{
  ui_calc_array_ptr_4c3a();
  ui_stack_adjust_4f26();
  ui_to_fmt_byte_4c9c();
  ser_pop3_return_50b8();
  return;
}


// ===== 0x004fc6 ui_get_math_tmp2_4fc6 =====

/* Auto: reads math_tmp2,math_tmp3,math_rem_lo,math_rem_hi; 7 instr */

void ui_get_math_tmp2_4fc6(void)

{
  math_barg_lo = 0;
  math_barg_hi = 0;
  math_res0 = math_tmp2;
  math_res1 = math_tmp3;
  math_aarg_lo = math_rem_lo;
  math_aarg_hi = math_rem_hi;
  return;
}


// ===== 0x004fdc ui_get_math_res0_4fdc =====

/* Auto: reads math_res0,math_res1,math_aarg_lo,math_aarg_hi; 6 instr */

void ui_get_math_res0_4fdc(void)

{
  mod_frag_f41a();
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  c18_tmp2 = math_aarg_lo;
  c18_tmp3 = math_aarg_hi;
  return;
}


// ===== 0x004ff2 ui_frag_4ff2 =====

/* Auto: compiler fragment: RCALL 0x004be8 ; MOVLW #0x31 ; MOVWF INDF0,ACCESS ; GOTO 0x004be8 */

void ui_frag_4ff2(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_frame_access_4be8();
  *(undefined1 *)in_FSR0 = 0x31;
  ui_frame_access_4be8();
  return;
}


// ===== 0x004ffc ui_to_temp_c_to_f_4ffc =====

/* Auto: calls temp_c_to_f; 2 instr */

void ui_to_temp_c_to_f_4ffc(void)

{
  temp_c_to_f();
  ui_to_fmt_int_4eaa();
  return;
}


// ===== 0x005002 ser_param_tcoldpress_5002 =====

/* Auto: reads params TCOLDPRESS; calls dispense_hot_allow,dispense_warm_cup; 5 instr */

void ser_param_tcoldpress_5002(void)

{
  ui_set_ui_screen_4e10(0xc);
  dispense_hot_allow();
  dispense_warm_cup();
  return;
}


// ===== 0x005010 ser_get_c18_tmp1_5010 =====

/* Auto: reads c18_tmp1,c18_tmp0; 7 instr */

char ser_get_c18_tmp1_5010(byte param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)c18_tmp0;
  c18_tmp0 = (char)(uVar1 * param_1);
  cVar2 = (char)(uVar1 * param_1 >> 8);
  c18_tmp1 = c18_tmp1 * param_1 + cVar2;
  return cVar2;
}


// ===== 0x005022 ser_ptr_add_5022 =====

/* Auto: compiler fragment: ADDWF FSR2L,w,ACCESS ; MOVWF FSR0L,ACCESS ; MOVLW #0x0 ; ADDWFC
   FSR2H,w,ACCESS ; MOVWF FSR0H,ACCESS ; RETURN 0x0 */

char ser_ptr_add_5022(byte param_1)

{
  byte in_FSR2L;
  char in_FSR2H;
  
  return in_FSR2H + CARRY1(in_FSR2L,param_1);
}


// ===== 0x00502e ser_stack_adjust_502e =====

/* Auto: Software stack push/pop helper; 4 instr */

undefined1 ser_stack_adjust_502e(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_callw_mod_set_lcd_text_flag_4c48();
  *(undefined1 *)in_FSR1 = 0x58;
  return 0x58;
}


// ===== 0x005036 ser_to_mod_set_lcd_text_flag_5036 =====

/* Auto: Small wrapper around mod_set_lcd_text_flag; 4 instr */

void ser_to_mod_set_lcd_text_flag_5036(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_set_lcd_text_flag_ca90();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x005040 ser_param_tpowerdelay_5040 =====

/* Auto: reads params TPOWERDELAY; 4 instr */

undefined1 ser_param_tpowerdelay_5040(void)

{
  undefined1 uVar1;
  
  uVar1 = ui_to_eeprom_read_raw_4dd4(0x31);
  return uVar1;
}


// ===== 0x005048 ser_to_text_draw_word_5048 =====

/* Auto: calls text_draw_word; 4 instr */

void ser_to_text_draw_word_5048(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_word();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x005052 ser_push_args_01_txt_to_text_draw_char_5052 =====

/* Auto: Push constant arguments [1] then call txt_to_text_draw_char; 3 instr */

void ser_push_args_01_txt_to_text_draw_char_5052(void)

{
  txt_to_text_draw_char_93ba();
  return;
}


// ===== 0x00505a ser_stack_adjust_505a =====

/* Auto: Software stack push/pop helper; 5 instr */

void ser_stack_adjust_505a(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_callw_fncfc6_4c62();
  *(undefined1 *)in_FSR1 = 0x7c;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  return;
}


// ===== 0x005066 ser_word_child_protect_5066 =====

/* Auto: shows "CHILD PROTECT!"; 7 instr */

undefined1 ser_word_child_protect_5066(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_to_ser_to_text_draw_word_4d7a(0x10);
  *puVar1 = 4;
  return 4;
}


// ===== 0x005074 ser_set_ui_blink_phase_5074 =====

/* Auto: writes ui_blink_phase; 6 instr */

undefined1 ser_set_ui_blink_phase_5074(void)

{
  ui_stack_adjust_4e78();
  ui_to_ser_to_text_draw_word_4d7a();
  ui_blink_phase = 2;
  return 2;
}


// ===== 0x005080 ser_set_ui_screen_5080 =====

/* Auto: writes ui_screen,ui_dispense_state,ui_hold_counter; 7 instr */

undefined1 ser_set_ui_screen_5080(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100) = 0xb;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xd) = 2;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe) = 3;
  return 3;
}


// ===== 0x00508e ser_stack_adjust_508e =====

/* Auto: Software stack push/pop helper; 4 instr */

undefined1 ser_stack_adjust_508e(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_to_mod_get_lcd_text_width_4c54();
  *(undefined1 *)in_FSR1 = 0x2c;
  return 0x2c;
}


// ===== 0x005096 ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096 =====

/* Auto: Calls ui_to_lcd_draw_glyph, 0x4ea0; 2 instr */

void ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096(void)

{
  ui_to_lcd_draw_glyph_4ca8();
  ui_stack_adjust_4ea0();
  return;
}


// ===== 0x00509c ser_to_ui_to_eeprom_read_raw_509c =====

/* Auto: Small wrapper around ui_to_eeprom_read_raw; 4 instr */

void ser_to_ui_to_eeprom_read_raw_509c(void)

{
  local3 = ui_to_eeprom_read_raw_4dd4();
  local4 = 0;
  return;
}


// ===== 0x0050a4 ser_test_value_50a4 =====

/* Auto: compiler fragment: RCALL 0x004c34 ; IORLW #0x0 ; RETURN 0x0 */

undefined1 ser_test_value_50a4(void)

{
  undefined1 uVar1;
  
  uVar1 = ui_bank1_ui_get_cfg_systemconfig5_4c34();
  return uVar1;
}


// ===== 0x0050aa ser_test_value_50aa =====

/* Auto: compiler fragment: RCALL 0x004c3a ; MOVLW #0xff ; XORWF POSTINC0,w,ACCESS ; RETURN 0x0 */

byte ser_test_value_50aa(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_calc_array_ptr_4c3a();
  return *(byte *)in_FSR0 ^ 0xff;
}


// ===== 0x0050b2 ser_chain_fn4f80_fn5036_50b2 =====

/* Auto: Calls 0x4f80, 0x5036; 2 instr */

void ser_chain_fn4f80_fn5036_50b2(void)

{
  ui_stack_adjust_4f80();
  ser_to_mod_set_lcd_text_flag_5036();
  return;
}


// ===== 0x0050b8 ser_pop3_return_50b8 =====

/* Auto: Drop stack arguments and return; 4 instr */

void ser_pop3_return_50b8(void)

{
  return;
}


// ===== 0x006d6a serial_report_param =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Print a parameter's name, value, maximum and minimum */

void serial_report_param(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar6;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined1 uVar7;
  byte bVar8;
  byte bVar9;
  bool bVar10;
  
  puVar2 = &FramePointer10x0002;
  bVar8 = (byte)((ushort)serial_cmd_hash * 7);
  bVar9 = (byte)((ushort)serial_cmd_hash * 7 >> 8);
  bVar10 = 0xa5 < bVar8;
  c18_tmp0 = bVar8 + 0x5a;
  c18_tmp1 = (bVar9 - 0x23) + bVar10;
  c18_tmp2 = 0;
  ser_get_c18_tmp0_791a();
  puVar3 = puVar2 + 1;
  *puVar2 = 0x32;
  uVar7 = ser_to_memcpypgm2ram_79ce(0);
  uVar6 = (undefined1)((ushort)puVar3 >> 8);
  if (!CARRY1(bVar9,bVar10) && bVar9 + bVar10 < 0x23) {
    puVar4 = (undefined1 *)((ushort)puVar3 & 0xff00);
    uVar6 = (undefined1)((ushort)(puVar4 + -1) >> 8);
    *puVar4 = *puVar4;
  }
  uVar1 = c18_tmp3;
  pbVar5 = (byte *)CONCAT11(uVar6,uVar7) + 1;
  *(byte *)CONCAT11(uVar6,uVar7) = serial_cmd_hash;
  temp_channel = param_read_max(uVar1);
  *pbVar5 = *pbVar5;
  pbVar5[-1] = serial_cmd_hash;
  temp_new_reading = param_read_min();
  *pbVar5 = *pbVar5;
  ntc_table_ptr_hi = ser_to_eeprom_read_raw_79b6();
  return;
}


// ===== 0x006dc0 serial_read_counter_desc =====

/* Read usage-counter descriptor (name) from ROM table */

undefined1 serial_read_counter_desc(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  puVar1 = &FramePointer10x0002;
  bVar2 = (byte)((ushort)serial_cmd_hash * 6);
  bVar3 = (byte)((ushort)serial_cmd_hash * 6 >> 8);
  bVar4 = 0x98 < bVar2;
  c18_tmp0 = bVar2 + 0x67;
  c18_tmp1 = (bVar3 - 0x21) + bVar4;
  c18_tmp2 = 0;
  ser_get_c18_tmp0_791a();
  bVar2 = (byte)((ushort)(puVar1 + 1) >> 8);
  *puVar1 = 0x39;
  ser_to_memcpypgm2ram_79ce(0);
  if (!CARRY1(bVar3,bVar4) && bVar3 + bVar4 < 0x21) {
    *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
  }
  return c18_tmp3;
}


// ===== 0x006df8 serial_cmd_reset =====

/* Software reset */

void serial_cmd_reset(void)

{
  reset();
  return;
}


// ===== 0x006dfc serial_parse_index_value_args =====
/* decompile failed: Exception while decompiling CODE:006dfc: java.lang.IndexOutOfBoundsException: Index 0 out of bounds for length 0
 */

// ===== 0x006e5c task_serial_protocol =====

/* WARNING: Removing unreachable block (CODE,0x007294) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 5 task: serial console. Commands: RS NM SM ST PD GHT GCT GDT COT DCW DHW STP CP0 CP1 EH1
   EH0 GCS GHS HTS UVS IVS CVS HVS CWC GCH TC AC g, hidden GP SP RP GPL RPL SMN SMX GC RC GCL RCL
   VER XC LCL */

void task_serial_protocol(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar29;
  undefined1 *puVar30;
  byte *pbVar31;
  char *pcVar32;
  undefined1 *puVar33;
  byte bVar34;
  char cVar35;
  undefined1 uVar36;
  byte bVar37;
  char cVar38;
  undefined1 uVar39;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar40;
  byte *in_TBLPTR;
  undefined2 *puVar41;
  bool bVar42;
  bool bVar43;
  undefined1 *puVar2;
  undefined1 *puVar28;
  
  uart2_rx_flags = uart2_rx_flags | 1;
  do {
    while( true ) {
      serial_push_sem();
      bVar34 = OSWaitSem();
      puVar1 = (undefined1 *)((short)in_FSR1 + -1);
      puVar2 = (undefined1 *)((short)in_FSR1 + -1);
      *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
      puVar3 = (undefined1 *)((short)in_FSR1 + -2);
      in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
      *puVar1 = *puVar2;
      if ((bVar34 & 2) == 0) break;
      OS_Yield();
    }
    ser_get_TBLPTRL_79f4();
    *puVar3 = *puVar3;
    fault_code = -0x7f;
    if ((serial_cmd_hash == 0xd4) && (uart2_rx_buffer != 'R')) {
      serial_cmd_hash = 0xd3;
    }
    if ((serial_cmd_hash == 0xfb) && (uart2_rx_buffer != 'S')) {
      serial_cmd_hash = 0xfa;
    }
    if ((serial_cmd_hash == 0xf1) && (uart2_rx_buffer != 'G')) {
      serial_cmd_hash = 0xf0;
    }
    if ((serial_cmd_hash == 0xa9) && (uart2_rx_buffer != 'S')) {
      serial_cmd_hash = 0xa7;
    }
    if ((serial_cmd_hash == 0xe1) && (uart2_rx_buffer != 'G')) {
      serial_cmd_hash = 0xe0;
    }
    if ((serial_cmd_hash == 0x8d) && (uart2_rx_buffer != 'G')) {
      serial_cmd_hash = 0x8c;
    }
    if (uart2_rx_buffer == 'g') {
      serial_cmd_hash = 0x67;
    }
    bVar42 = 0xdd < serial_cmd_hash;
    pbVar31 = puVar3 + -1;
    if (serial_cmd_hash == 0xde) {
      if ((uart2_rx_buffer_3 == '\0') || (uart2_rx_buffer_2 == '\0')) {
        serial_cmd_hash = 0;
        pbVar31 = puVar3 + -1;
      }
      else {
        puVar3[-1] = 0x6f;
        uVar39 = ser_to_atol_7a3a(1);
        ser_get_TBLPTRL_799c(uVar39);
        serial_cmd_hash = *in_TBLPTR;
        pbVar31 = puVar3;
      }
    }
    if (serial_cmd_hash == 0xa8) {
      cVar38 = hot_valve_is_open();
      if (cVar38 == '\0') {
        puVar30 = pbVar31 + 1;
        *pbVar31 = 0xcc;
        uVar39 = 0x50;
LAB_CODE_007588:
        pbVar31 = puVar30 + 1;
        *puVar30 = uVar39;
        uart2_puts_rom();
LAB_CODE_00758c:
        *pbVar31 = *pbVar31;
        pbVar31[-1] = pbVar31[-1];
        puVar29 = pbVar31 + -2;
      }
      else {
        puVar29 = pbVar31;
        if (cVar38 == '\x01') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xdb;
          uVar39 = 0x50;
          goto LAB_CODE_007588;
        }
      }
LAB_CODE_007590:
      ser_get_TBLPTRL_79f4();
LAB_CODE_007592:
      pbVar31 = puVar29 + -1;
      *puVar29 = *puVar29;
LAB_CODE_007594:
      fault_code = '\0';
    }
    else {
      if (serial_cmd_hash == 0xa3) {
        cVar38 = cold_valve_is_open();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xe9;
          uVar39 = 0x50;
        }
        else {
          puVar29 = pbVar31;
          if (cVar38 != '\x01') goto LAB_CODE_007590;
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xf8;
          uVar39 = 0x50;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xa7) {
        cVar38 = inlet_valve_is_open();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 6;
          uVar39 = 0x51;
        }
        else {
          puVar29 = pbVar31;
          if (cVar38 != '\x01') goto LAB_CODE_007590;
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x18;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xb5) {
        bVar34 = PORTJ;
        if ((bVar34 & RJ1) == 0) {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x37;
          uVar39 = 0x51;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x29;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xac) {
        cVar38 = heater_is_on();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x44;
          uVar39 = 0x51;
        }
        else {
          puVar29 = pbVar31;
          if (cVar38 != '\x01') goto LAB_CODE_007590;
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x4f;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xe1) {
LAB_CODE_007500:
        fault_code = -0x7e;
        goto LAB_CODE_0075a0;
      }
      if (serial_cmd_hash == 0x9b) {
        cVar38 = heating_get_state();
        if (cVar38 == '\x04') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x74;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\x03') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x8f;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\x02') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xa6;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\x01') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xc0;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xd8;
          uVar39 = 0x51;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x59;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0x8d) {
        cVar38 = cooling_get_state();
        if (cVar38 == '\x02') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xb;
          uVar39 = 0x52;
        }
        else if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x22;
          uVar39 = 0x52;
        }
        else if (cVar38 == '\x01') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x37;
          uVar39 = 0x52;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xef;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xe0) {
        cVar38 = child_protect_is_active();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x4b;
          uVar39 = 0x52;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x6e;
          uVar39 = 0x52;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0x11) {
        system_wake();
        heating_request_extra_hot();
        goto LAB_CODE_007594;
      }
      if (serial_cmd_hash == 0x15) {
        heating_cancel_extra_hot();
        goto LAB_CODE_007594;
      }
      if (serial_cmd_hash == 0x27) {
        *pbVar31 = 1;
LAB_CODE_00745a:
        puVar29 = pbVar31 + 1;
        mod_to_mod_to_param_write_b52a();
        goto LAB_CODE_007592;
      }
      if (serial_cmd_hash == 0x23) {
        *pbVar31 = 0;
        goto LAB_CODE_00745a;
      }
      if (serial_cmd_hash != 0xbb) {
        if (serial_cmd_hash == 0x88) {
          fault_code = dispense_hot_request();
          goto LAB_CODE_0075a0;
        }
        if (serial_cmd_hash == 0x9e) {
          fault_code = dispense_cold_request();
          goto LAB_CODE_0075a0;
        }
        if (serial_cmd_hash == 0x91) {
          local0 = cold_temp_read_ch4();
          ser_chain_fn7ac8_fn7aa8_7842();
          local0 = cold_temp_read_ch5();
        }
        else {
          if (serial_cmd_hash != 0x87) {
            if ((serial_cmd_hash == 199) || (serial_cmd_hash == 0xd2)) goto LAB_CODE_007500;
            if (serial_cmd_hash == 0xfb) {
              serial_cmd_hash = 0;
              while( true ) {
                c18_tmp0 = serial_cmd_hash;
                c18_tmp1 = 0;
                bVar42 = 7 < serial_cmd_hash != true;
                if (7 < serial_cmd_hash != true) break;
                OS_Yield(0);
                ser_get_serial_cmd_hash_7962();
                puVar41 = (undefined2 *)
                          CONCAT21((short)((uint3)in_TBLPTR >> 8),(char)in_TBLPTR + '\x02');
                ser_get_TBLPTRH_7a50();
                uart2_puts_rom();
                puVar27 = pbVar31 + -1;
                puVar28 = pbVar31 + -1;
                *pbVar31 = *pbVar31;
                pbVar31 = pbVar31 + -2;
                *puVar27 = *puVar28;
                ser_get_serial_cmd_hash_7962();
                in_TBLPTR = (byte *)((int3)puVar41 + 1);
                in_FSR0 = (BADSPACEBASE *)*puVar41;
                ser_frag_7a48(*(undefined1 *)in_FSR0);
                serial_cmd_hash = serial_cmd_hash + 1;
              }
            }
            else if (serial_cmd_hash == 0xc9) {
              system_enter_sleep();
            }
            else if (serial_cmd_hash == 0xd3) {
              system_wake();
            }
            else {
              if (serial_cmd_hash == 0xf4) {
                *pbVar31 = 0x8d;
                puVar25 = pbVar31 + 2;
                pbVar31[1] = 0x52;
                ser_to_uart2_puts_rom_7914();
                *puVar25 = 0;
                puVar26 = puVar25 + 2;
                puVar25[1] = 200;
                OSDelay();
                *puVar26 = *puVar26;
                pbVar31 = puVar26 + -2;
                puVar26[-1] = puVar26[-1];
                adc_raw_lo = 0x10;
                OS_Yield();
                serial_cmd_reset();
                goto LAB_CODE_0075a0;
              }
              if (serial_cmd_hash == 0xd8) {
                fault_code = -0x7e;
                system_enter_standby();
              }
              else {
                if (serial_cmd_hash != 0xe4) {
                  if (serial_cmd_hash == 0xd4) {
                    if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) &&
                       (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                      bVar42 = 0x11 < serial_cmd_hash;
                      bVar34 = serial_cmd_hash - 0x12;
                      if (!bVar42) {
                        bVar37 = ser_to_serial_read_counter_desc_7a80(bVar34);
                        if ((bVar37 & 0x80) == 0) {
                          bVar37 = ser_compare_multibyte_78ec();
                          bVar43 = bVar42;
                        }
                        else {
                          bVar43 = c18_tmp7 < '\0';
                          bVar34 = c18_tmp7 << 1 | bVar42;
                          bVar37 = bVar34;
                        }
                        if (bVar43) {
                          ser_to_ser_get_serial_ptr_lo_7a26();
                          *(undefined1 *)in_FSR0 = 0;
                          pbVar21 = pbVar31 + 1;
                          *pbVar31 = local0;
                          stat_byte_save();
                        }
                        else {
                          ser_to_ser_get_serial_ptr_lo_7a58(bVar37);
                          do {
                            ser_shift_multibyte_79dc();
                          } while (bVar34 != 0);
                          local0 = c18_tmp0;
                          ser_frag_7a66(c18_tmp0);
                          pbVar21 = pbVar31 + 1;
                          *pbVar31 = local0;
                          stat_counter_save();
                        }
                        pbVar20 = pbVar21 + -1;
                        pbVar31 = pbVar21 + -1;
                        *pbVar21 = *pbVar21;
                        bVar42 = 0xfe < serial_param_index;
                        if (serial_param_index != 0xff) {
                          ser_calc_array_ptr_7956(serial_param_index);
                          *(undefined1 *)in_FSR0 = 0;
LAB_CODE_007354:
                          pbVar22 = pbVar20 + 1;
                          *pbVar20 = serial_param_index;
                          stat_byte_save();
LAB_CODE_00735c:
                          pbVar31 = pbVar22 + -1;
                          *pbVar22 = *pbVar22;
                        }
                        goto LAB_CODE_007594;
                      }
                    }
                  }
                  else if (serial_cmd_hash == 0x67) {
                    if ((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) {
                      *pbVar31 = 2;
                      pbVar31[1] = 0;
                      puVar11 = pbVar31 + 3;
                      pbVar31[2] = 0x6d;
                      uVar36 = ser_to_memcpy_7986(1);
                      uVar39 = (undefined1)((ushort)puVar11 >> 8);
                      if (!bVar42) {
                        puVar12 = (undefined1 *)((ushort)puVar11 & 0xff00);
                        uVar39 = (undefined1)((ushort)(puVar12 + -1) >> 8);
                        *puVar12 = *puVar12;
                      }
                      serial_buf_a4 = 0;
                      puVar13 = (undefined1 *)CONCAT11(uVar39,uVar36) + 1;
                      *(undefined1 *)CONCAT11(uVar39,uVar36) = 0xa2;
                      serial_cmd_hash = ser_to_atol_7a3a(1);
                      *puVar13 = 8;
                      puVar13[1] = 0;
                      puVar14 = puVar13 + 3;
                      puVar13[2] = 0x6f;
                      uVar36 = ser_to_memcpy_7986(1);
                      uVar39 = (undefined1)((ushort)puVar14 >> 8);
                      if (!bVar42) {
                        puVar15 = (undefined1 *)((ushort)puVar14 & 0xff00);
                        uVar39 = (undefined1)((ushort)(puVar15 + -1) >> 8);
                        *puVar15 = *puVar15;
                      }
                      puVar16 = (undefined1 *)CONCAT11(uVar39,uVar36);
                      serial_buf_aa = 0;
                      *puVar16 = 0xa2;
                      puVar17 = puVar16 + 2;
                      puVar16[1] = 1;
                      serial_print_number();
                      *puVar17 = *puVar17;
                      pbVar18 = puVar17 + -2;
                      pbVar31 = puVar17 + -2;
                      puVar17[-1] = puVar17[-1];
                      serial_value32 = math_res0;
                      DAT_DATA_01ad = math_res1;
                      DAT_DATA_01ae = math_aarg_lo;
                      DAT_DATA_01af = math_aarg_hi;
                      bVar42 = 0x11 < serial_cmd_hash;
                      bVar34 = serial_cmd_hash - 0x12;
                      if (!bVar42) {
                        bVar37 = ser_to_serial_read_counter_desc_7a80(bVar34);
                        if ((bVar37 & 0x80) == 0) {
                          bVar37 = ser_compare_multibyte_78ec();
                          bVar43 = bVar42;
                        }
                        else {
                          bVar43 = c18_tmp7 < '\0';
                          bVar34 = c18_tmp7 << 1 | bVar42;
                          bVar37 = bVar34;
                        }
                        if (bVar43) {
                          ser_to_ser_get_serial_ptr_lo_7a26();
                          *(undefined1 *)in_FSR0 = serial_value32;
                          pbVar19 = pbVar18 + 1;
                          *pbVar18 = local0;
                          stat_byte_save();
                        }
                        else {
                          ser_to_ser_get_serial_ptr_lo_7a58(bVar37);
                          do {
                            ser_shift_multibyte_79dc();
                          } while (bVar34 != 0);
                          local0 = c18_tmp0;
                          ser_ptr_add_7928(c18_tmp0);
                          *(undefined1 *)in_FSR0 = serial_value32;
                          *(undefined1 *)((short)in_FSR0 + 1) = DAT_DATA_01ad;
                          puVar40 = (undefined1 *)((short)in_FSR0 + 3);
                          *(undefined1 *)((short)in_FSR0 + 2) = DAT_DATA_01ae;
                          in_FSR0 = (BADSPACEBASE *)((short)in_FSR0 + 4);
                          *puVar40 = DAT_DATA_01af;
                          pbVar19 = pbVar18 + 1;
                          *pbVar18 = local0;
                          stat_counter_save();
                        }
                        pbVar20 = pbVar19 + -1;
                        pbVar31 = pbVar19 + -1;
                        *pbVar19 = *pbVar19;
                        bVar42 = 0xfe < serial_param_index;
                        if (serial_param_index != 0xff) {
                          ser_calc_array_ptr_7956(serial_param_index);
                          *(undefined1 *)in_FSR0 = serial_value32;
                          goto LAB_CODE_007354;
                        }
                        goto LAB_CODE_007594;
                      }
                    }
                  }
                  else {
                    if (serial_cmd_hash != 0xc1) {
                      if (serial_cmd_hash == 0xf1) {
                        ser_frag_7a48(0x12);
                        for (serial_cmd_hash = 0; serial_cmd_hash < 0x12;
                            serial_cmd_hash = serial_cmd_hash + 1) {
                          OS_Yield(serial_cmd_hash - 0x12);
                          serial_read_counter_desc();
                          ser_get_serial_cmd_hash_7a96();
                          puVar8 = pbVar31 + 1;
                          *pbVar31 = serial_counter_ptr_lo;
                          pbVar31 = pbVar31 + 2;
                          *puVar8 = serial_counter_ptr_hi;
                          ser_to_uart2_puts_rom_7910();
                          bVar34 = ser_get_serial_ptr_lo_7890();
                          cVar38 = c18_tmp7;
                          bVar42 = (bVar34 & 0x80) != 0;
                          if (bVar42) {
                            cVar35 = c18_tmp7 << 1;
                          }
                          else {
                            cVar35 = ser_compare_multibyte_78ec();
                          }
                          if (!bVar42 || -1 < cVar38) {
                            uVar36 = ser_to_ltoa_78ce(cVar35);
                            uVar39 = (undefined1)((ushort)pbVar31 >> 8);
                            if (!bVar42 || -1 < cVar38) {
                              puVar9 = (undefined1 *)((ushort)pbVar31 & 0xff00);
                              uVar39 = (undefined1)((ushort)(puVar9 + -1) >> 8);
                              *puVar9 = *puVar9;
                            }
                            pbVar31 = (byte *)CONCAT11(uVar39,uVar36);
                            bVar34 = c18_tmp0;
                          }
                          else {
                            ser_to_ser_get_serial_ptr_lo_79b0();
                            bVar34 = ser_to_fmt_byte_7a08();
                          }
                          ser_to_uart2_puts_ram_7aa2(bVar34);
                          ser_to_ser_get_TBLPTRL_7aa8();
                        }
                        bVar42 = true;
                      }
                      else {
                        if (serial_cmd_hash != 0xc2) {
                          if (serial_cmd_hash == 0xf2) {
                            if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) &&
                               (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                              bVar42 = 0x4a < serial_cmd_hash;
                              if (!bVar42) {
                                bVar34 = ser_to_param_table_lookup_79c2(serial_cmd_hash + 0xb5);
LAB_CODE_007138:
                                *pbVar31 = bVar34;
                                pbVar6 = pbVar31 + 2;
                                pbVar31[1] = serial_cmd_hash;
                                fault_code = param_write();
                                goto LAB_CODE_007142;
                              }
                            }
                          }
                          else if (serial_cmd_hash == 0xf0) {
                            cVar38 = serial_parse_index_value_args();
                            if (cVar38 != '\0') {
                              *pbVar31 = local0;
                              pbVar6 = pbVar31 + 2;
                              pbVar31[1] = serial_cmd_hash;
                              fault_code = param_write_min();
LAB_CODE_007142:
                              *pbVar6 = *pbVar6;
                              pbVar31 = pbVar6 + -2;
                              pbVar6[-1] = pbVar6[-1];
                            }
                          }
                          else if (serial_cmd_hash == 0xa9) {
                            cVar38 = serial_parse_index_value_args();
                            if (cVar38 != '\0') {
                              *pbVar31 = local0;
                              pbVar6 = pbVar31 + 2;
                              pbVar31[1] = serial_cmd_hash;
                              fault_code = param_write_max();
                              goto LAB_CODE_007142;
                            }
                          }
                          else {
                            if (serial_cmd_hash != 0xf3) {
                              if (serial_cmd_hash == 0xfa) {
                                ser_frag_7a48(0x1c);
                                serial_cmd_hash = 0;
                                while( true ) {
                                  c18_tmp0 = serial_cmd_hash;
                                  c18_tmp1 = 0;
                                  bVar42 = 0x1b < serial_cmd_hash != true;
                                  if (0x1b < serial_cmd_hash != true) break;
                                  OS_Yield(0);
                                  ser_get_serial_cmd_hash_7a96();
                                  ser_get_TBLPTRL_799c(serial_cmd_hash);
                                  in_TBLPTR = (byte *)CONCAT21((short)((uint3)in_TBLPTR >> 8),
                                                               (char)in_TBLPTR + '\x01');
                                  ser_get_TBLPTRH_7a50();
                                  ser_to_uart2_puts_rom_7914();
                                  serial_cmd_hash = serial_cmd_hash + 1;
                                }
                              }
                              else {
                                if (serial_cmd_hash == 0xe7) {
                                  if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0'))
                                     && (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                                    bVar42 = 0x4a < serial_cmd_hash;
                                    if (!bVar42) {
                                      ser_push_args_6c_01_79fe(serial_cmd_hash + 0xb5);
                                      bVar34 = ser_to_eeprom_read_raw_79b6();
                                      goto LAB_CODE_0071fe;
                                    }
                                  }
                                  goto LAB_CODE_0075a0;
                                }
                                if (serial_cmd_hash != 0xd7) {
                                  if (serial_cmd_hash != 0x94) {
                                    if (serial_cmd_hash == 0x8c) {
                                      local0 = temp_read_ch7();
                                    }
                                    else {
                                      if (serial_cmd_hash != 0x9f) {
                                        fault_code = -0x7b;
                                        goto LAB_CODE_0075a0;
                                      }
                                      local0 = temp_read_ch6();
                                    }
                                    ser_push_args_6c_01_79fe();
                                    bVar34 = local0;
                                    goto LAB_CODE_0071fe;
                                  }
                                  puVar4 = pbVar31 + 1;
                                  *pbVar31 = 0x90;
                                  pbVar31 = pbVar31 + 2;
                                  *puVar4 = 0x52;
                                  uart2_puts_rom();
                                  goto LAB_CODE_007214;
                                }
                                ser_frag_7a48(0x4b);
                                for (serial_cmd_hash = 0; serial_cmd_hash < 0x4b;
                                    serial_cmd_hash = serial_cmd_hash + 1) {
                                  OS_Yield(serial_cmd_hash + 0xb5);
                                  serial_report_param();
                                  ser_get_serial_cmd_hash_7a96();
                                  puVar5 = pbVar31 + 1;
                                  *pbVar31 = adc_raw_hi;
                                  pbVar31 = pbVar31 + 2;
                                  *puVar5 = ntc_table_ptr_lo;
                                  ser_to_uart2_puts_rom_7910();
                                  local0 = temp_new_reading;
                                  ser_push_args_6c_01_79fe();
                                  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784
                                            (temp_new_reading);
                                  local0 = temp_channel;
                                  ser_push_args_6c_01_79fe();
                                  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784
                                            (temp_channel);
                                  local0 = ser_to_eeprom_read_raw_79b6();
                                  ser_push_args_6c_01_79fe();
                                  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784
                                            (local0);
                                  ser_to_param_table_lookup_79c2();
                                  ser_frag_7a48();
                                }
                                bVar42 = true;
                              }
                              goto LAB_CODE_007594;
                            }
                            cVar38 = serial_parse_index_value_args();
                            bVar34 = local0;
                            if (cVar38 != '\0') goto LAB_CODE_007138;
                          }
                          goto LAB_CODE_0075a0;
                        }
                        for (serial_cmd_hash = 0; serial_cmd_hash < 0x4b;
                            serial_cmd_hash = serial_cmd_hash + 1) {
                          OS_Yield(serial_cmd_hash + 0xb5);
                          uVar39 = ser_to_param_table_lookup_79c2();
                          *pbVar31 = uVar39;
                          puVar7 = pbVar31 + 2;
                          pbVar31[1] = serial_cmd_hash;
                          fault_code = param_write();
                          *puVar7 = *puVar7;
                          pbVar31 = puVar7 + -2;
                          puVar7[-1] = puVar7[-1];
                          if (fault_code < '\0') {
                            bVar42 = true;
                            goto LAB_CODE_007594;
                          }
                          pbVar31 = puVar7 + -2;
                        }
                        bVar42 = true;
                      }
                      goto LAB_CODE_007594;
                    }
                    if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) &&
                       (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                      bVar43 = 0x11 < serial_cmd_hash;
                      bVar42 = bVar43;
                      if (!bVar43) {
                        bVar34 = ser_to_serial_read_counter_desc_7a80(serial_cmd_hash - 0x12);
                        if ((bVar34 & 0x80) == 0) {
                          bVar34 = ser_compare_multibyte_78ec();
                        }
                        else {
                          bVar42 = c18_tmp7 < '\0';
                          bVar34 = c18_tmp7 << 1 | bVar43;
                        }
                        if (bVar42) {
                          bVar34 = ser_to_ser_get_serial_ptr_lo_79b0();
LAB_CODE_0071fe:
                          bVar34 = ser_to_fmt_byte_7a08(bVar34);
                        }
                        else {
                          uVar36 = ser_to_ltoa_78ce(bVar34);
                          uVar39 = (undefined1)((ushort)pbVar31 >> 8);
                          if (bVar42 == false) {
                            puVar10 = (undefined1 *)((ushort)pbVar31 & 0xff00);
                            uVar39 = (undefined1)((ushort)(puVar10 + -1) >> 8);
                            *puVar10 = *puVar10;
                          }
                          pbVar31 = (byte *)CONCAT11(uVar39,uVar36);
                          bVar34 = c18_tmp0;
                        }
                        ser_to_uart2_puts_ram_7aa2(bVar34);
LAB_CODE_007214:
                        *pbVar31 = *pbVar31;
                        pbVar22 = pbVar31 + -2;
                        pbVar31[-1] = pbVar31[-1];
                        ser_get_TBLPTRL_79f4();
                        goto LAB_CODE_00735c;
                      }
                    }
                  }
                  goto LAB_CODE_0075a0;
                }
                for (serial_cmd_hash = 0; serial_cmd_hash < 0x10;
                    serial_cmd_hash = serial_cmd_hash + 1) {
                  OS_Yield(serial_cmd_hash - 0x10);
                  ser_frag_7a66(serial_cmd_hash);
                  pbVar23 = pbVar31 + 1;
                  *pbVar31 = serial_cmd_hash;
                  stat_counter_save();
                  pbVar31 = pbVar23 + -1;
                  *pbVar23 = *pbVar23;
                }
                for (serial_cmd_hash = 0; serial_cmd_hash < 2; serial_cmd_hash = serial_cmd_hash + 1
                    ) {
                  OS_Yield(serial_cmd_hash - 2);
                  ser_calc_array_ptr_7956(serial_cmd_hash);
                  *(undefined1 *)in_FSR0 = 0;
                  pbVar24 = pbVar31 + 1;
                  *pbVar31 = serial_cmd_hash;
                  stat_byte_save();
                  pbVar31 = pbVar24 + -1;
                  *pbVar24 = *pbVar24;
                }
                bVar42 = true;
              }
            }
            goto LAB_CODE_007594;
          }
          local0 = hot_temp_top;
          ser_chain_fn7ac8_fn7aa8_7842();
          local0 = hot_temp_bottom;
        }
        ser_to_ser_to_fmt_byte_7ac8();
        goto LAB_CODE_00758c;
      }
      fault_code = dispense_stop_all();
    }
LAB_CODE_0075a0:
    if (fault_code < '\0') {
      ser_push_args_6c_01_79fe(fault_code << 1 | bVar42);
      pcVar32 = (char *)(pbVar31 + 1);
      *pbVar31 = fault_code;
      fmt_byte();
      *pcVar32 = *pcVar32;
      pcVar32[-1] = pcVar32[-1];
      pcVar32[-2] = pcVar32[-2];
      pcVar32[-3] = 0xc5;
      puVar33 = pcVar32 + -1;
      pcVar32[-2] = 0x50;
      uart2_puts_rom();
      *puVar33 = *puVar33;
      in_FSR1 = (BADSPACEBASE *)(puVar33 + -2);
      puVar33[-1] = puVar33[-1];
      ser_to_uart2_puts_ram_7aa2();
    }
    else {
      *pbVar31 = 0x8d;
      in_FSR1 = (BADSPACEBASE *)(pbVar31 + 2);
      pbVar31[1] = 0x52;
      uart2_puts_rom();
    }
    ser_to_ser_get_TBLPTRL_7aa8();
    uart2_rx_count = 0;
    serial_cmd_hash = 0;
    uart2_rx_flags = uart2_rx_flags | 3;
  } while( true );
}


// ===== 0x0075e2 serial_init =====

/* Create serial line semaphore, reset receive state */

undefined1 serial_init(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  serial_push_sem();
  OSCreateSem();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  uart2_rx_count = 0;
  uart2_rx_buffer = 0;
  serial_cmd_hash = 0;
  uart2_rx_flags = uart2_rx_flags | 3;
  return 0;
}


// ===== 0x0075fe serial_create_task =====

/* Create task_serial_protocol (TCB 0x62) */

undefined1 serial_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x007628 uart2_rx_isr =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* EUSART2 receive: echo, collect line (max 11 chars), hash command word, signal task on CR */

char uart2_rx_isr(char param_1)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar4;
  bool bVar5;
  undefined1 *puVar3;
  
  while (bVar1 = PIR3, (bVar1 & RC2IF) != 0) {
    uart2_rx_byte = RCREG2;
    param_1 = '\0';
    if (((uart2_rx_flags & 1) != 0) &&
       ((uart2_rx_count < 0xb || (param_1 = RCREG2 - 0xd, param_1 == '\0')))) {
      do {
        bVar1 = PIR3;
      } while ((bVar1 & TX2IF) == 0);
      TXREG2 = RCREG2;
      if (RCREG2 == 0xd) {
        uart2_rx_flags = uart2_rx_flags & 0xfe;
        serial_push_sem(0);
        param_1 = OSSignalSem();
        puVar2 = (undefined1 *)((short)in_FSR1 + -1);
        puVar3 = (undefined1 *)((short)in_FSR1 + -1);
        *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
        *puVar2 = *puVar3;
      }
      else {
        if (RCREG2 == 0x20) {
          uart2_rx_flags = uart2_rx_flags & 0xfd;
        }
        if ((uart2_rx_flags & 2) != 0) {
          *(byte *)in_FSR1 = uart2_rx_count;
          cVar4 = *(char *)in_FSR1;
          *(char *)in_FSR1 = cVar4;
          bVar1 = RCREG2;
          while (cVar4 != '\0') {
            bVar1 = bVar1 << 1;
            cVar4 = *(char *)in_FSR1 + -1;
            *(char *)in_FSR1 = cVar4;
          }
          serial_cmd_hash = bVar1 ^ serial_cmd_hash;
        }
        bVar5 = 0x93 < uart2_rx_count;
        cVar4 = uart2_rx_count + 0x6c;
        uart2_rx_byte = TXREG2;
        uart2_rx_count = uart2_rx_count + 1;
        *(byte *)CONCAT11(bVar5 + '\x01',cVar4) = TXREG2;
        param_1 = '\x01';
        *(undefined1 *)CONCAT11((0x93 < uart2_rx_count) + '\x01',uart2_rx_count + 0x6c) = 0;
      }
    }
  }
  return param_1;
}


// ===== 0x0076ac uart2_puts_rom =====

/* Send NUL-terminated ROM string on EUSART2 */

void uart2_puts_rom(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char *in_TBLPTR;
  
  ser_c18_prologue_78fe();
  puVar2 = (undefined1 *)in_FSR2;
  while( true ) {
    puVar2[-2] = puVar2[-1] + '\x01';
    puVar3 = puVar2 + 4;
    in_TBLPTR = (char *)CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(puVar2[1],puVar2[-3]));
    if (puVar2[-1] == -1) {
      puVar3 = puVar2 + 6;
      puVar2[2] = puVar2[3] + '\x01';
    }
    uart2_tx_char = *in_TBLPTR;
    if (uart2_tx_char == '\0') break;
    do {
      bVar1 = PIR3;
      TXREG2 = uart2_tx_char;
      puVar2 = puVar3;
    } while ((bVar1 & TX2IF) == 0);
  }
  ser_c18_epilogue_794a(0);
  return;
}


// ===== 0x0076d8 uart2_puts_ram =====

/* Send NUL-terminated RAM string on EUSART2 */

void uart2_puts_ram(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  ser_c18_prologue_78fe();
  puVar2 = (undefined1 *)in_FSR2;
  while( true ) {
    puVar2[-2] = puVar2[-1] + '\x01';
    puVar3 = puVar2 + 4;
    if (puVar2[-1] == -1) {
      puVar3 = puVar2 + 6;
      puVar2[2] = puVar2[3] + '\x01';
    }
    uart2_tx_char = *(char *)CONCAT11(puVar2[1],puVar2[-3]);
    if (*(char *)CONCAT11(puVar2[1],puVar2[-3]) == '\0') break;
    do {
      bVar1 = PIR3;
      TXREG2 = uart2_tx_char;
      puVar2 = puVar3;
    } while ((bVar1 & TX2IF) == 0);
  }
  ser_c18_epilogue_794a(0);
  return;
}


// ===== 0x007702 serial_hex_digit =====

/* Convert nibble to ASCII hex digit */

void serial_hex_digit(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ser_c18_prologue_78fe();
  if (*(byte *)((short)in_FSR2 + -2) < 0x41) {
    c18_tmp0 = '0';
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -1);
    *(char *)in_FSR1 = *(char *)in_FSR1 - c18_tmp0;
  }
  else {
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -1) - 0x37;
  }
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR1;
  if (*(byte *)in_FSR2 < 0x41) {
    c18_tmp0 = '0';
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + 1);
    *(char *)in_FSR1 = *(char *)in_FSR1 - c18_tmp0;
  }
  else {
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + 1) - 0x37;
  }
  *(byte *)((short)in_FSR2 + 2) = *(byte *)in_FSR1;
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + 3);
  bVar1 = *(byte *)((short)in_FSR2 + 5);
  *(byte *)((short)in_FSR1 + 1) = *(byte *)((short)in_FSR1 + 1);
  ser_c18_epilogue_794a(*(char *)in_FSR1 + bVar1 * '\x10');
  return;
}


// ===== 0x007774 serial_print_number =====

/* Print number in hex/decimal on serial console */

void serial_print_number(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar3;
  BADSPACEBASE *in_FSR0;
  bool bVar4;
  bool bVar5;
  
  ser_c18_prologue_78fe();
  ser_stack_adjust_784e(1);
  ser_frame_load_ptr_arg_7a72();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
  c18_tmp0 = serial_hex_digit();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  c18_tmp1 = 0;
  c18_tmp2 = 0;
  c18_tmp3 = 0;
  cVar3 = '\x18';
  do {
    bVar4 = (char)c18_tmp0 < '\0';
    c18_tmp0 = c18_tmp0 << 1;
    bVar5 = (char)c18_tmp1 < '\0';
    c18_tmp1 = c18_tmp1 << 1 | bVar4;
    bVar4 = (char)c18_tmp2 < '\0';
    c18_tmp2 = c18_tmp2 << 1 | bVar5;
    c18_tmp3 = c18_tmp3 << 1 | bVar4;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  ser_get_c18_tmp3_7a88();
  ser_stack_adjust_784e(3);
  c18_tmp4 = ser_chain_fn784e_ser_to_serial_hex__7a90(2);
  c18_tmp5 = 0;
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  cVar3 = '\x10';
  do {
    bVar4 = (char)c18_tmp4 < '\0';
    c18_tmp4 = c18_tmp4 * '\x02';
    bVar5 = (char)c18_tmp5 < '\0';
    c18_tmp5 = c18_tmp5 << 1 | bVar4;
    bVar4 = (char)c18_tmp6 < '\0';
    c18_tmp6 = c18_tmp6 << 1 | bVar5;
    c18_tmp7 = c18_tmp7 << 1 | bVar4;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  bVar4 = CARRY1(c18_tmp0,c18_tmp4);
  c18_tmp0 = c18_tmp0 + c18_tmp4;
  bVar5 = CARRY1(c18_tmp1,bVar4) || CARRY1(c18_tmp5,c18_tmp1 + bVar4);
  c18_tmp1 = c18_tmp1 + c18_tmp5 + bVar4;
  bVar4 = CARRY1(c18_tmp2,bVar5);
  bVar1 = c18_tmp2 + bVar5;
  c18_tmp2 = c18_tmp2 + c18_tmp6 + bVar5;
  c18_tmp3 = c18_tmp3 + c18_tmp7 + (bVar4 || CARRY1(c18_tmp6,bVar1));
  ser_get_c18_tmp3_7a88();
  ser_stack_adjust_784e(5);
  c18_tmp8 = ser_chain_fn784e_ser_to_serial_hex__7a90(4);
  c18_tmp9 = 0;
  c18_tmp10 = 0;
  c18_tmp11 = 0;
  cVar3 = '\b';
  do {
    bVar4 = (char)c18_tmp8 < '\0';
    c18_tmp8 = c18_tmp8 * '\x02';
    bVar5 = (char)c18_tmp9 < '\0';
    c18_tmp9 = c18_tmp9 << 1 | bVar4;
    bVar4 = (char)c18_tmp10 < '\0';
    c18_tmp10 = c18_tmp10 << 1 | bVar5;
    c18_tmp11 = c18_tmp11 << 1 | bVar4;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  bVar4 = CARRY1(c18_tmp0,c18_tmp8);
  c18_tmp0 = c18_tmp0 + c18_tmp8;
  bVar5 = CARRY1(c18_tmp1,bVar4) || CARRY1(c18_tmp9,c18_tmp1 + bVar4);
  c18_tmp1 = c18_tmp1 + c18_tmp9 + bVar4;
  bVar4 = CARRY1(c18_tmp2,bVar5);
  bVar1 = c18_tmp2 + bVar5;
  c18_tmp2 = c18_tmp2 + c18_tmp10 + bVar5;
  c18_tmp3 = c18_tmp3 + c18_tmp11 + (bVar4 || CARRY1(c18_tmp10,bVar1));
  ser_get_c18_tmp3_7a88();
  ser_stack_adjust_784e(7);
  c18_tmp12 = ser_chain_fn784e_ser_to_serial_hex__7a90(6);
  c18_tmp13 = 0;
  c18_tmp14 = 0;
  c18_tmp15 = 0;
  math_res0 = c18_tmp0 + c18_tmp12;
  bVar4 = CARRY1(c18_tmp1,CARRY1(c18_tmp0,c18_tmp12));
  math_res1 = c18_tmp1 + CARRY1(c18_tmp0,c18_tmp12);
  math_aarg_lo = c18_tmp2 + bVar4;
  math_aarg_hi = c18_tmp3 + CARRY1(c18_tmp2,bVar4);
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  c18_tmp2 = math_aarg_lo;
  c18_tmp3 = math_aarg_hi;
  ser_c18_epilogue_794a();
  return;
}


// ===== 0x007842 ser_chain_fn7ac8_fn7aa8_7842 =====

/* Auto: Calls 0x7ac8, 0x7aa8; 2 instr */

void ser_chain_fn7ac8_fn7aa8_7842(void)

{
  ser_to_ser_to_fmt_byte_7ac8();
  ser_to_ser_get_TBLPTRL_7aa8();
  return;
}


// ===== 0x007848 ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784 =====

/* Auto: Calls ser_to_fmt_byte, ser_to_uart2_puts_ram, ser_get_TBLPTRL; 3 instr */

void ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784(void)

{
  ser_to_fmt_byte_7a08();
  ser_to_uart2_puts_ram_7aa2();
  ser_get_TBLPTRL_7a16();
  return;
}


// ===== 0x00784e ser_stack_adjust_784e =====

/* Auto: Software stack push/pop helper; 9 instr */

undefined1 ser_stack_adjust_784e(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  ser_frame_load_ptr_arg_7a72();
  uVar1 = *(undefined1 *)
           CONCAT11((char)((ushort)in_FSR0 >> 8) + CARRY1((byte)in_FSR0,*(byte *)in_FSR1),
                    (byte)in_FSR0 + *(byte *)in_FSR1);
  *(undefined1 *)in_FSR1 = uVar1;
  return uVar1;
}


// ===== 0x007860 serial_parse_index_arg =====

/* Parse numeric index argument (atol from rx buffer byte 3) into serial_cmd_hash */

undefined1 serial_parse_index_arg(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  
  uVar1 = ser_to_atol_7a3a(1);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x6b) = uVar1;
  return *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x6b);
}


// ===== 0x007870 ser_compare_multibyte_7870 =====

/* Auto: compiler fragment: MOVWF 0x001d,ACCESS ; CLRF 0x001e,ACCESS ; CLRF 0x001f,ACCESS ; MOVF
   0x001c,w,ACCESS ; SUBWF 0x003c,w,ACCESS ; MOVWF 0x0014,ACCESS ; MOVF 0x001d,w,ACCESS ; SUBWFB
   0x003d,w,ACCESS ; MOVWF 0x0015,ACCESS ; MOVF 0x001e,w,ACCESS ; SUBW */

char ser_compare_multibyte_7870(byte param_1)

{
  byte bVar1;
  bool bVar2;
  
  c18_tmp9 = param_1;
  c18_tmp10 = 0;
  c18_tmp11 = 0;
  c18_tmp0 = serial_ptr_lo - c18_tmp8;
  bVar1 = ~(c18_tmp8 <= serial_ptr_lo);
  bVar2 = serial_ptr_hi < bVar1 || param_1 < serial_ptr_hi - bVar1;
  c18_tmp1 = (serial_ptr_hi - param_1) - ~(c18_tmp8 <= serial_ptr_lo);
  c18_tmp2 = c18_tmp6 - ~bVar2;
  c18_tmp3 = c18_tmp7 - ~(c18_tmp6 != ~bVar2);
  return c18_tmp3;
}


// ===== 0x007890 ser_get_serial_ptr_lo_7890 =====

/* Auto: reads serial_ptr_lo,serial_ptr_hi; 13 instr */

undefined1 ser_get_serial_ptr_lo_7890(void)

{
  c18_tmp0 = serial_ptr_lo;
  c18_tmp1 = serial_ptr_hi;
  c18_tmp2 = 0;
  c18_tmp3 = 0;
  c18_tmp4 = 0xf2;
  c18_tmp5 = 0;
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  return 0;
}


// ===== 0x0078ae ser_to_serial_hex_digit_78ae =====

/* Auto: reads c18_tmp3,c18_tmp2,c18_tmp1,c18_tmp0; calls serial_hex_digit; 12 instr */

void ser_to_serial_hex_digit_78ae(void)

{
  BADSPACEBASE *in_FSR1;
  
  serial_hex_digit();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)((short)in_FSR1 + -2) = *(undefined1 *)((short)in_FSR1 + -2);
  c18_tmp3 = *(undefined1 *)((short)in_FSR1 + -3);
  *(undefined1 *)((short)in_FSR1 + -3) = *(undefined1 *)((short)in_FSR1 + -3);
  c18_tmp2 = *(undefined1 *)((short)in_FSR1 + -4);
  *(undefined1 *)((short)in_FSR1 + -4) = *(undefined1 *)((short)in_FSR1 + -4);
  c18_tmp1 = *(undefined1 *)((short)in_FSR1 + -5);
  *(undefined1 *)((short)in_FSR1 + -5) = *(undefined1 *)((short)in_FSR1 + -5);
  c18_tmp0 = *(undefined1 *)((short)in_FSR1 + -6);
  return;
}


// ===== 0x0078ce ser_to_ltoa_78ce =====

/* Auto: calls ltoa; 10 instr */

char ser_to_ltoa_78ce(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  ser_get_serial_ptr_lo_7abc();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR0 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR0 + 2);
  cVar1 = (char)(undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR0 + 3);
  c18_tmp0 = ltoa();
  return cVar1 + -6;
}


// ===== 0x0078ec ser_compare_multibyte_78ec =====

/* Auto: compiler fragment: MOVF 0x0018,w,ACCESS ; SUBWF 0x0014,w,ACCESS ; MOVF 0x0019,w,ACCESS ;
   SUBWFB 0x0015,w,ACCESS ; MOVF 0x001a,w,ACCESS ; SUBWFB 0x0016,w,ACCESS ; MOVF 0x001b,w,ACCESS ;
   SUBWFB 0x0017,w,ACCESS ; RETURN 0x0 */

char ser_compare_multibyte_78ec(void)

{
  byte bVar1;
  
  bVar1 = ~(c18_tmp1 < (byte)~(c18_tmp4 <= c18_tmp0) ||
           c18_tmp5 < c18_tmp1 - ~(c18_tmp4 <= c18_tmp0));
  return (c18_tmp3 - c18_tmp7) - ~(c18_tmp2 < bVar1 || c18_tmp6 < c18_tmp2 - bVar1);
}


// ===== 0x0078fe ser_c18_prologue_78fe =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void ser_c18_prologue_78fe(void)

{
  return;
}


// ===== 0x007910 ser_to_uart2_puts_rom_7910 =====

/* Auto: calls uart2_puts_rom; 2 instr */

void ser_to_uart2_puts_rom_7910(void)

{
  uart2_puts_rom();
  ser_get_TBLPTRL_7a16();
  return;
}


// ===== 0x007914 ser_to_uart2_puts_rom_7914 =====

/* Auto: calls uart2_puts_rom; 2 instr */

void ser_to_uart2_puts_rom_7914(void)

{
  uart2_puts_rom();
  ser_to_ser_get_TBLPTRL_7aa8();
  return;
}


// ===== 0x00791a ser_get_c18_tmp0_791a =====

/* Auto: reads c18_tmp0,c18_tmp1,c18_tmp2; 4 instr */

void ser_get_c18_tmp0_791a(void)

{
  return;
}


// ===== 0x007928 ser_ptr_add_7928 =====

/* Auto: compiler fragment: MULLW #0x4 ; MOVFF PRODL,FSR0L ; MOVFF PRODH,FSR0H ; MOVLW #0xb2 ; ADDWF
   FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ; RETURN 0x0 */

undefined1 ser_ptr_add_7928(void)

{
  return 0;
}


// ===== 0x00793c ser_get_serial_ptr_lo_793c =====

/* Auto: reads serial_ptr_lo,serial_ptr_hi; 5 instr */

void ser_get_serial_ptr_lo_793c(void)

{
  c18_tmp4 = serial_ptr_lo;
  c18_tmp5 = serial_ptr_hi;
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  return;
}


// ===== 0x00794a ser_c18_epilogue_794a =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void ser_c18_epilogue_794a(void)

{
  return;
}


// ===== 0x007956 ser_calc_array_ptr_7956 =====

/* Auto: Compute array element address in FSR0; 6 instr */

undefined1 ser_calc_array_ptr_7956(void)

{
  return 0;
}


// ===== 0x007962 ser_get_serial_cmd_hash_7962 =====

/* Auto: reads serial_cmd_hash,TBLPTRL,TBLPTRH; 10 instr */

undefined1 ser_get_serial_cmd_hash_7962(void)

{
  return 0xfa;
}


// ===== 0x00797a ser_get_local1_797a =====

/* Auto: reads local1,local2; 4 instr */

undefined1 ser_get_local1_797a(void)

{
  return *(undefined1 *)CONCAT11(local2,local1);
}


// ===== 0x007986 ser_to_memcpy_7986 =====

/* Auto: calls memcpy; 10 instr */

char ser_to_memcpy_7986(void)

{
  char cVar1;
  
  cVar1 = '\x03';
  c18_tmp0 = memcpy();
  return cVar1 + -6;
}


// ===== 0x00799c ser_get_TBLPTRL_799c =====

/* Auto: reads TBLPTRL,TBLPTRH; 8 instr */

undefined1 ser_get_TBLPTRL_799c(void)

{
  return 0xfa;
}


// ===== 0x0079b0 ser_to_ser_get_serial_ptr_lo_79b0 =====

/* Auto: Small wrapper around ser_get_serial_ptr_lo; 3 instr */

undefined1 ser_to_ser_get_serial_ptr_lo_79b0(void)

{
  BADSPACEBASE *in_FSR0;
  
  ser_get_serial_ptr_lo_7abc();
  return *(undefined1 *)in_FSR0;
}


// ===== 0x0079b6 ser_to_eeprom_read_raw_79b6 =====

/* Auto: reads serial_cmd_hash; calls eeprom_read_raw; 4 instr */

void ser_to_eeprom_read_raw_79b6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x0079c2 ser_to_param_table_lookup_79c2 =====

/* Auto: reads serial_cmd_hash; calls param_table_lookup; 4 instr */

void ser_to_param_table_lookup_79c2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  param_table_lookup();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x0079ce ser_to_memcpypgm2ram_79ce =====

/* Auto: calls memcpypgm2ram; 6 instr */

char ser_to_memcpypgm2ram_79ce(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp3 = memcpypgm2ram();
  return cVar1 + -7;
}


// ===== 0x0079dc ser_shift_multibyte_79dc =====

/* Auto: compiler fragment: BCF STATUS,#0x0,ACCESS ; RRCF 0x0017,f,ACCESS ; RRCF 0x0016,f,ACCESS ;
   RRCF 0x0015,f,ACCESS ; RRCF 0x0014,f,ACCESS ; DECF WREG,f,ACCESS ; RETURN 0x0 */

char ser_shift_multibyte_79dc(char param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = c18_tmp3;
  bVar2 = c18_tmp2;
  bVar1 = c18_tmp1;
  c18_tmp3 = c18_tmp3 >> 1;
  c18_tmp2 = c18_tmp2 >> 1 | bVar3 << 7;
  c18_tmp1 = c18_tmp1 >> 1 | bVar2 << 7;
  c18_tmp0 = c18_tmp0 >> 1 | bVar1 << 7;
  return param_1 + -1;
}


// ===== 0x0079ea serial_push_sem =====

/* Push serial semaphore ECB address (0x9a) */

undefined1 serial_push_sem(void)

{
  return 0;
}


// ===== 0x0079f4 ser_get_TBLPTRL_79f4 =====

/* Auto: reads TBLPTRL; 4 instr */

void ser_get_TBLPTRL_79f4(void)

{
  ser_to_uart2_puts_rom_7ab2(0xfc);
  return;
}


// ===== 0x0079fe ser_push_args_6c_01_79fe =====

/* Auto: Push constant arguments [108, 1]; 5 instr */

undefined1 ser_push_args_6c_01_79fe(void)

{
  return 1;
}


// ===== 0x007a08 ser_to_fmt_byte_7a08 =====

/* Auto: calls fmt_byte; 6 instr */

void ser_to_fmt_byte_7a08(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  fmt_byte();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  return;
}


// ===== 0x007a16 ser_get_TBLPTRL_7a16 =====

/* Auto: reads TBLPTRL; 8 instr */

void ser_get_TBLPTRL_7a16(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10xfffe;
  ser_to_uart2_puts_rom_7ab2(0xfc);
  *puVar1 = *puVar1;
  return;
}


// ===== 0x007a26 ser_to_ser_get_serial_ptr_lo_7a26 =====

/* Auto: Small wrapper around ser_get_serial_ptr_lo; 9 instr */

void ser_to_ser_get_serial_ptr_lo_7a26(void)

{
  ser_get_serial_ptr_lo_793c();
  c18_tmp8 = 0xf2;
  ser_compare_multibyte_7870(0);
  local0 = c18_tmp0;
  ser_calc_array_ptr_7956(c18_tmp0);
  return;
}


// ===== 0x007a3a ser_to_atol_7a3a =====

/* Auto: calls atol; 6 instr */

void ser_to_atol_7a3a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  atol();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x007a48 ser_frag_7a48 =====

/* Auto: compiler fragment: MOVWF 0x0024,ACCESS ; RCALL 0x007842 ; MOVLB #0x1 ; RETURN 0x0 */

void ser_frag_7a48(undefined1 param_1)

{
  local0 = param_1;
  ser_chain_fn7ac8_fn7aa8_7842();
  return;
}


// ===== 0x007a50 ser_get_TBLPTRH_7a50 =====

/* Auto: reads TBLPTRH; 3 instr */

void ser_get_TBLPTRH_7a50(void)

{
  ser_get_TABLAT_7ad2(0);
  return;
}


// ===== 0x007a58 ser_to_ser_get_serial_ptr_lo_7a58 =====

/* Auto: Small wrapper around ser_get_serial_ptr_lo; 7 instr */

undefined1 ser_to_ser_get_serial_ptr_lo_7a58(void)

{
  ser_get_serial_ptr_lo_793c();
  c18_tmp8 = 0xb2;
  ser_compare_multibyte_7870(0);
  return 2;
}


// ===== 0x007a66 ser_frag_7a66 =====

/* Auto: compiler fragment: RCALL 0x007928 ; CLRF POSTINC0,ACCESS ; CLRF POSTINC0,ACCESS ; CLRF
   POSTINC0,ACCESS ; CLRF POSTINC0,ACCESS ; RETURN 0x0 */

void ser_frag_7a66(void)

{
  BADSPACEBASE *in_FSR0;
  
  ser_ptr_add_7928();
  *(undefined1 *)in_FSR0 = 0;
  *(undefined1 *)((short)in_FSR0 + 1) = 0;
  *(undefined1 *)((short)in_FSR0 + 2) = 0;
  *(undefined1 *)((short)in_FSR0 + 3) = 0;
  return;
}


// ===== 0x007a72 ser_frame_load_ptr_arg_7a72 =====

/* Auto: Load pointer argument from stack frame into FSR0; 5 instr */

undefined1 ser_frame_load_ptr_arg_7a72(void)

{
  return 0xfd;
}


// ===== 0x007a80 ser_to_serial_read_counter_desc_7a80 =====

/* Auto: calls serial_read_counter_desc; 2 instr */

void ser_to_serial_read_counter_desc_7a80(void)

{
  serial_read_counter_desc();
  ser_get_serial_ptr_lo_7890();
  return;
}


// ===== 0x007a88 ser_get_c18_tmp3_7a88 =====

/* Auto: reads c18_tmp3; 3 instr */

void ser_get_c18_tmp3_7a88(void)

{
  BADSPACEBASE *in_FSR1;
  
  ser_get_c18_tmp0_791a();
  *(undefined1 *)in_FSR1 = c18_tmp3;
  return;
}


// ===== 0x007a90 ser_chain_fn784e_ser_to_serial_hex__7a90 =====

/* Auto: Calls 0x784e, ser_to_serial_hex_digit; 2 instr */

void ser_chain_fn784e_ser_to_serial_hex__7a90(void)

{
  ser_stack_adjust_784e();
  ser_to_serial_hex_digit_78ae();
  return;
}


// ===== 0x007a96 ser_get_serial_cmd_hash_7a96 =====

/* Auto: reads serial_cmd_hash; 4 instr */

void ser_get_serial_cmd_hash_7a96(void)

{
  local0 = serial_cmd_hash;
  ser_push_args_6c_01_79fe();
  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784(local0);
  return;
}


// ===== 0x007aa2 ser_to_uart2_puts_ram_7aa2 =====

/* Auto: calls uart2_puts_ram; 2 instr */

void ser_to_uart2_puts_ram_7aa2(void)

{
  ser_push_args_6c_01_79fe();
  uart2_puts_ram();
  return;
}


// ===== 0x007aa8 ser_to_ser_get_TBLPTRL_7aa8 =====

/* Auto: Small wrapper around ser_get_TBLPTRL; 5 instr */

void ser_to_ser_get_TBLPTRL_7aa8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10xfffe;
  ser_get_TBLPTRL_79f4();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x007ab2 ser_to_uart2_puts_rom_7ab2 =====

/* Auto: reads TBLPTRH; calls uart2_puts_rom; 5 instr */

void ser_to_uart2_puts_rom_7ab2(void)

{
  BADSPACEBASE *in_FSR1;
  
  ser_get_TABLAT_7ad2();
  uart2_puts_rom();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x007abc ser_get_serial_ptr_lo_7abc =====

/* Auto: reads serial_ptr_lo,serial_ptr_hi; 4 instr */

void ser_get_serial_ptr_lo_7abc(void)

{
  ser_push_args_6c_01_79fe();
  return;
}


// ===== 0x007ac8 ser_to_ser_to_fmt_byte_7ac8 =====

/* Auto: Small wrapper around ser_to_fmt_byte; 4 instr */

void ser_to_ser_to_fmt_byte_7ac8(void)

{
  ser_push_args_6c_01_79fe();
  ser_to_fmt_byte_7a08(local0);
  ser_to_uart2_puts_ram_7aa2();
  return;
}


// ===== 0x007ad2 ser_get_TABLAT_7ad2 =====

/* Auto: reads TABLAT; 5 instr */

void ser_get_TABLAT_7ad2(void)

{
  return;
}


// ===== 0x009282 word_lookup_a =====

/* Word table lookup (group A: 0xF114 EN, 0xEF8E RU, 0xEE06 HE) */

void word_lookup_a(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = txt_frame_access_99c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      txt_get_TBLPTRH_998e();
      uVar2 = 0xee;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092ac;
      txt_get_TBLPTRH_998e();
      uVar2 = 0xf1;
    }
  }
  else {
    txt_get_TBLPTRH_998e();
    uVar2 = 0xef;
  }
  txt_get_TBLPTRH_99ca(uVar2);
LAB_CODE_0092ac:
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0092ae word_lookup_b =====

/* Word table lookup (group B dictionary: 0xF22E EN, 0xF0A8 RU, 0xEF20 HE) */

void word_lookup_b(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = txt_frame_access_99c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      txt_get_TBLPTRH_998e();
      uVar2 = 0xef;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092d8;
      txt_get_TBLPTRH_998e();
      uVar2 = 0xf2;
    }
  }
  else {
    txt_get_TBLPTRH_998e();
    uVar2 = 0xf0;
  }
  txt_get_TBLPTRH_99ca(uVar2);
LAB_CODE_0092d8:
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0092da txt_to_mod_set_lcd_text_flag_92da =====

/* Auto: Small wrapper around mod_set_lcd_text_flag; 5 instr */

void txt_to_mod_set_lcd_text_flag_92da(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_to_txt_get_c18_tmp0_9964();
  mod_set_lcd_text_flag_cad4();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0092e6 txt_to_mod_set_lcd_text_flag_92e6 =====

/* Auto: Small wrapper around mod_set_lcd_text_flag; 5 instr */

void txt_to_mod_set_lcd_text_flag_92e6(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_to_txt_get_c18_tmp0_9964();
  mod_set_lcd_text_flag_cb0c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0092f2 txt_to_mod_set_lcd_text_flag_92f2 =====

/* Auto: Small wrapper around mod_set_lcd_text_flag; 5 instr */

void txt_to_mod_set_lcd_text_flag_92f2(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_to_txt_get_c18_tmp0_9964();
  mod_set_lcd_text_flag_ca68();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0092fe txt_to_mod_set_lcd_text_flag_92fe =====

/* Auto: Small wrapper around mod_set_lcd_text_flag; 5 instr */

void txt_to_mod_set_lcd_text_flag_92fe(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_to_txt_get_c18_tmp0_9964();
  mod_set_lcd_text_flag_ca7c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x00930a txt_to_mod_set_lcd_text_flag_930a =====

/* Auto: Small wrapper around mod_set_lcd_text_flag; 5 instr */

void txt_to_mod_set_lcd_text_flag_930a(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_to_txt_get_c18_tmp0_9964();
  mod_set_lcd_text_flag_cab8();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x009316 text_draw_word =====

/* Draw a word from the word table (with language/screen header) */

void text_draw_word(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  char *pcVar2;
  byte bVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  txt_c18_prologue_9a5a();
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  pcVar8 = (char *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  if (((((cfg_systemconfig4 & 1) == 0) && (ui_screen != '\x04')) && (ui_screen != '\x05')) &&
     ((ui_screen != '\x14' && (ui_screen + -0x1f != '\0')))) {
    txt_get_c18_tmp0_9ac8(ui_screen + -0x1f);
    c18_tmp2 = 0;
    *puVar4 = in_PRODL;
    puVar4[1] = in_PRODH;
    puVar5 = puVar4 + 3;
    puVar4[2] = c18_tmp2;
    txt_push_args_12_0e_9a26();
    c18_tmp3 = strcpy_rom2ram();
    bVar3 = (byte)puVar5;
    if (bVar3 < 5) {
      puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
      puVar5 = puVar6 + -1;
      *puVar6 = *puVar6;
    }
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)puVar5 >> 8),bVar3 - 5);
    txt_push_args_12_0e_9a26(c18_tmp3);
    uVar11 = mod_set_lcd_text_maxwidth_cbf2();
    *puVar7 = *puVar7;
    pcVar8 = puVar7 + -2;
    puVar7[-1] = puVar7[-1];
    *(undefined1 *)in_FSR2 = uVar11;
    while (*(char *)in_FSR2 != '\0') {
      pcVar2 = (char *)((short)in_FSR2 + 1);
      pcVar9 = pcVar8 + 1;
      *pcVar8 = *(char *)((short)in_FSR2 + 1) + *(char *)((short)in_FSR2 + -3) + -1;
      text_draw_char();
      pcVar8 = pcVar9 + -1;
      *pcVar9 = *pcVar9;
      *pcVar2 = *pcVar2 + -1;
      in_FSR2 = (BADSPACEBASE *)pcVar2;
    }
    cVar1 = *(char *)((short)in_FSR2 + -3);
  }
  else {
    cVar1 = *(char *)((short)in_FSR2 + -3);
  }
  if (cVar1 == '\a') {
    text_row = *(undefined1 *)((short)in_FSR2 + -2);
    uVar11 = 0x16;
  }
  else {
    text_row = *(undefined1 *)((short)in_FSR2 + -2);
    uVar11 = 6;
  }
  *pcVar8 = uVar11;
  pcVar8[1] = 0;
  puVar10 = pcVar8 + 3;
  pcVar8[2] = *(undefined1 *)in_FSR2;
  txt_set_ui_hold_counter_98fc();
  *puVar10 = *puVar10;
  txt_stack_adjust_9aa8();
  return;
}


// ===== 0x0093ba txt_to_text_draw_char_93ba =====

/* Auto: calls text_draw_char; 6 instr */

void txt_to_text_draw_char_93ba(void)

{
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char cVar2;
  
  cVar2 = txt_frame_access_99e2();
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = cVar2 + '\x06';
  text_draw_char();
  *pcVar1 = *pcVar1;
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0093c6 text_draw_char =====

/* Draw one character */

void text_draw_char(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  
  cVar2 = txt_frame_access_99e2();
  if (cVar2 == '\a') {
    *(undefined1 *)in_FSR1 = 0x5b;
    uVar3 = 0x12;
  }
  else {
    *(undefined1 *)in_FSR1 = 0x5f;
    uVar3 = 0x10;
  }
  *(undefined1 *)((short)in_FSR1 + 1) = uVar3;
  *(undefined1 *)((short)in_FSR1 + 2) = 1;
  puVar1 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR2 + -2);
  lcd_draw_glyph();
  *puVar1 = *puVar1;
  txt_stack_adjust_9aa8();
  return;
}


// ===== 0x0093ee text_layout_line =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Compute alignment and fill for a text line */

void text_layout_line(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined1 uVar5;
  
  txt_c18_prologue_9a5a();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = text_flags & 0xcf;
  txt_frame_push_args_99a8();
  text_width2 = mod_to_text_measure_width_cc0c();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  text_x_adjust = '\0';
  text_width_saved = text_width;
  text_x_end = text_x;
  bVar4 = text_flags & 0x60;
  if (bVar4 == 0) {
    bVar4 = text_flags & 6;
    if (bVar4 == 6) {
      c18_tmp0 = 0x40;
      text_x_end = 0x40 - (text_width2 >> 1);
    }
    else if (bVar4 == 4) {
      text_x_end = 0x82 - text_width2;
    }
    else if (bVar4 == 2) {
      text_x_end = 0;
    }
    goto LAB_CODE_00948a;
  }
  if (bVar4 == 0x60) {
    if (text_width < 0xfe || text_width2 < text_width + 2) {
      text_x_end = text_x + (text_width - text_width2 >> 1);
      goto LAB_CODE_00948a;
    }
    bVar4 = text_width2 - text_width >> 1;
  }
  else {
    if (bVar4 != 0x40) goto LAB_CODE_00948a;
    if (text_width < 0xfe || text_width2 < text_width + 2) {
      text_x_end = ((text_width + text_x) - text_width2) + 2;
      goto LAB_CODE_00948a;
    }
    bVar4 = text_width2 - text_width;
  }
  text_x_adjust = -bVar4;
LAB_CODE_00948a:
  bVar4 = text_flags & 0x60;
  if (bVar4 == 0) {
    pbVar1[-3] = text_x_end;
    txt_get_text_row_9a30(0);
  }
  else {
    puVar2 = pbVar1 + -2;
    pbVar1[-3] = text_x;
    txt_get_text_row_9a30(bVar4);
    for (text_column = text_x; text_column < text_x_end; text_column = text_column + 1) {
      if ((text_flags & 0x80) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xff;
      }
      puVar3 = puVar2 + 1;
      *puVar2 = uVar5;
      lcd_write_data();
      puVar2 = puVar3 + -1;
      *puVar3 = *puVar3;
    }
    text_x_end = text_x_end - text_x;
  }
  text_x_end = text_x_adjust + text_width2 + text_x_end;
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0094d8 text_draw_string =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Render a string with alignment, newline, tab handling */

void text_draw_string(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte bVar12;
  undefined1 uVar13;
  char cVar14;
  undefined1 *puVar5;
  undefined1 *puVar8;
  
  txt_c18_prologue_9a5a();
  if ((text_flags & 0x10) != 0) {
    txt_frame_push_args_99a8();
    text_width2 = mod_set_lcd_text_maxwidth_cbf2();
    puVar4 = (undefined1 *)((short)in_FSR1 + -1);
    puVar5 = (undefined1 *)((short)in_FSR1 + -1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
    *puVar4 = *puVar5;
    text_row = text_row - (text_width2 + -1);
  }
  if ((text_flags & 0x60) == 0) {
    pbVar6 = (byte *)((short)in_FSR1 + 1);
    *(byte *)in_FSR1 = text_flags & 0xcf;
    txt_frame_push_args_99a8();
    text_width = text_measure_width();
    *pbVar6 = *pbVar6;
    pbVar6[-1] = pbVar6[-1];
    pbVar6[-2] = pbVar6[-2];
    pbVar9 = pbVar6 + -3;
    if (0x80 < text_width) {
      text_width = 0x80;
      pbVar9 = pbVar6 + -3;
    }
  }
  else {
    text_width = text_fill_width;
    pbVar9 = (byte *)in_FSR1;
  }
  bVar12 = text_flags & 6;
  if (bVar12 == 6) {
    c18_tmp0 = 0x40;
    bVar12 = 0x40 - (text_width >> 1);
    text_x = bVar12;
  }
  else if (bVar12 == 4) {
    bVar12 = 0x82 - text_width;
    text_x = bVar12;
  }
  else {
    bVar12 = bVar12 ^ 2;
    if (bVar12 == 0) {
      text_x = 0;
    }
  }
LAB_CODE_009546:
  txt_frame_push_args_99a8(bVar12);
  text_layout_line();
  puVar7 = pbVar9 + -1;
  puVar8 = pbVar9 + -1;
  *pbVar9 = *pbVar9;
  pbVar9 = pbVar9 + -2;
  *puVar7 = *puVar8;
  do {
    while( true ) {
      puVar1 = (undefined1 *)((short)in_FSR2 + -3);
      *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + '\x01';
      puVar2 = (undefined1 *)((short)in_FSR2 + 1);
      puVar3 = (undefined1 *)((short)in_FSR2 + 4);
      if (*(char *)((short)in_FSR2 + -1) == -1) {
        *(char *)((short)in_FSR2 + 2) = *(char *)((short)in_FSR2 + 3) + '\x01';
        puVar3 = (undefined1 *)((short)in_FSR2 + 6);
      }
      in_FSR2 = (BADSPACEBASE *)puVar3;
      text_char = *(char *)CONCAT11(*puVar2,*puVar1);
      if (*(char *)CONCAT11(*puVar2,*puVar1) == '\0') {
        cVar14 = '\0';
        if ((text_flags & 0x60) != 0) {
          while (cVar14 = text_x_end - text_width, text_x_end < text_width) {
            if ((text_flags & 0x80) == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = 0xff;
            }
            txt_set_text_x_end_9a3e(uVar13);
          }
        }
        txt_c18_epilogue_9972(cVar14);
        return;
      }
      if ((text_flags & 8) == 0) break;
LAB_CODE_0095bc:
      *pbVar9 = text_flags & 0xcf | 0x20;
      pbVar10 = pbVar9 + 2;
      pbVar9[1] = text_char;
      text_render_glyphs();
      pbVar11 = pbVar10 + -1;
      *pbVar10 = *pbVar10;
LAB_CODE_0095ce:
      pbVar9 = pbVar11 + -1;
      *pbVar11 = *pbVar11;
    }
    if (text_char == '\n') break;
    if (text_char != '\b') {
      if (text_char == '\r') {
        text_flags = ~(text_flags & 0x80) | text_flags & 0x7f;
      }
      else if (text_char != '\t') goto LAB_CODE_0095bc;
      pbVar11 = pbVar9 + 1;
      *pbVar9 = text_flags & 0xcf | 0x20;
      mod_set_text_x_adjust_cc2c();
      goto LAB_CODE_0095ce;
    }
    text_flags = ~(text_flags & 1) | text_flags & 0xfe;
  } while( true );
  bVar12 = 0;
  text_char = '\n';
  if ((text_flags & 0x60) != 0) {
    while (bVar12 = text_x_end - text_width, text_x_end < text_width) {
      if ((text_flags & 0x80) == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = 0xff;
      }
      txt_set_text_x_end_9a3e(uVar13);
    }
  }
  text_row = text_row + '\x01';
  goto LAB_CODE_009546;
}


// ===== 0x0095f2 printf_handle_conv =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* printf: handle %d/%b conversion */

char printf_handle_conv(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar8;
  byte in_PRODL;
  bool bVar9;
  
  if (text_char == 'd') {
    printf_args_lo = printf_args_lo + -2;
    txt_get_printf_out_lo_99ea();
    puVar8 = (undefined1 *)((short)in_FSR0 + 1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
    puVar3 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR0 + 1);
    fmt_int();
    puVar2 = puVar3 + -1;
    *puVar3 = *puVar3;
  }
  else {
    puVar8 = (undefined1 *)in_FSR0;
    if (text_char != 'b') goto LAB_CODE_009626;
    printf_args_lo = printf_args_lo + -1;
    txt_get_printf_out_lo_99ea();
    puVar2 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
    fmt_byte();
    puVar8 = (undefined1 *)in_FSR0;
  }
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  in_FSR1 = (BADSPACEBASE *)(puVar2 + -3);
  puVar2[-2] = puVar2[-2];
LAB_CODE_009626:
  *(byte *)in_FSR1 = printf_out_lo;
  pbVar4 = (byte *)((short)in_FSR1 + 2);
  *(char *)((short)in_FSR1 + 1) = printf_out_hi;
  mod_frag_f5c4();
  text_width = in_PRODL;
  *pbVar4 = *pbVar4;
  puVar5 = pbVar4 + -2;
  pbVar4[-1] = pbVar4[-1];
  c18_tmp1 = 0;
  bVar9 = CARRY1(printf_out_lo,text_width);
  printf_out_lo = printf_out_lo + text_width;
  printf_out_hi = printf_out_hi + bVar9;
  if (text_column != '\0') {
    if (text_x_end <= text_width) {
      return text_width - text_x_end;
    }
    text_width2 = text_x_end - text_width;
    c18_tmp1 = 0;
    bVar9 = CARRY1(printf_out_lo,text_width2 - 1);
    printf_out_lo = printf_out_lo + (text_width2 - 1);
    printf_out_hi = printf_out_hi + bVar9;
    while( true ) {
      bVar1 = text_width - 1;
      bVar9 = text_width == 0;
      text_width = bVar1;
      if (bVar9) break;
      c18_tmp0 = text_width2;
      c18_tmp1 = 0;
      puVar8 = (undefined1 *)
               CONCAT11(printf_out_hi - ~(text_width2 <= printf_out_lo),printf_out_lo - text_width2)
      ;
      uVar7 = txt_get_printf_out_lo_99b6(*puVar8);
      *puVar8 = uVar7;
      bVar9 = printf_out_lo != 0;
      printf_out_lo = printf_out_lo - 1;
      printf_out_hi = printf_out_hi - ~bVar9;
    }
    while( true ) {
      if (text_width2 == 0) break;
      if (text_column == '\x01') {
        uVar7 = 0x20;
      }
      else {
        uVar7 = 0x30;
      }
      puVar6 = puVar5 + 1;
      *puVar5 = uVar7;
      text_width2 = text_width2 - 1;
      txt_get_printf_out_lo_99b6();
      bVar9 = printf_out_lo != 0;
      printf_out_lo = printf_out_lo - 1;
      printf_out_hi = printf_out_hi - ~bVar9;
      puVar5 = puVar6 + -1;
      *puVar6 = *puVar6;
      *puVar8 = puVar6[-1];
    }
    bVar9 = CARRY1(printf_out_lo,text_x_end + 1);
    printf_out_lo = printf_out_lo + text_x_end + 1;
    printf_out_hi = printf_out_hi + bVar9;
    text_width2 = 0xff;
  }
  c18_tmp1 = 0;
  return '\0';
}


// ===== 0x0096c0 lcd_printf =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* printf-style formatted output to the LCD */

void lcd_printf(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR0;
  short in_PROD;
  byte *in_TBLPTR;
  bool bVar7;
  bool bVar8;
  
  txt_c18_prologue_9a5a();
  printf_out_lo = 0x12;
  printf_out_hi = 0xe;
  *(undefined1 *)in_FSR1 = 0xff;
  text_flags = *(byte *)((short)in_FSR2 + -3) & *(byte *)in_FSR1;
  c18_tmp0 = *(byte *)((short)in_FSR2 + -1);
  c18_tmp1 = 0;
  DAT_DATA_0e01 = c18_tmp0;
  if ((c18_tmp0 & 1) != 0) {
    txt_set_keys_current_9a80();
    *(undefined1 *)in_FSR0 = 9;
  }
  bVar3 = text_flags & 8;
  if ((bVar3 == 0) && (bVar3 = text_char - 0x3c, bVar3 == 0)) {
    bVar8 = 0xfe < printf_fmt_lo;
    printf_fmt_lo = printf_fmt_lo + 1;
    printf_fmt_hi = printf_fmt_hi + bVar8;
    bVar3 = text_fill_width;
LAB_CODE_009714:
    text_fill_width = bVar3;
    txt_get_printf_fmt_lo_9ab0();
    text_char = *in_TBLPTR;
    if (text_char != 0x3e) {
      bVar8 = 0xfe < printf_fmt_lo;
      printf_fmt_lo = printf_fmt_lo + 1;
      printf_fmt_hi = printf_fmt_hi + bVar8;
      bVar3 = text_fill_width;
      if (text_char == 0x42) {
        text_flags = text_flags & 0xfe;
      }
      else if (text_char == 0x62) {
        text_flags = text_flags | 1;
      }
      else if (text_char == 0x49) {
        text_flags = text_flags & 0x7f;
      }
      else {
        if (text_char != 0x69) {
          if (text_char == 0x4e) {
            bVar2 = 0x9f;
          }
          else {
            if (text_char == 0x43) {
              text_flags = text_flags & 0x9f | 0x60;
              goto LAB_CODE_009714;
            }
            if (text_char == 0x52) {
              text_flags = text_flags & 0x9f | 0x40;
              goto LAB_CODE_009714;
            }
            if (text_char == 0x4c) {
              text_flags = text_flags & 0x9f | 0x20;
              goto LAB_CODE_009714;
            }
            if (text_char != 0x6e) {
              if (text_char == 99) {
                text_flags = text_flags & 0xf9 | 6;
              }
              else if (text_char == 0x72) {
                text_flags = text_flags & 0xf9 | 4;
              }
              else {
                bVar3 = text_char;
                if (text_char == 0x6c) {
                  text_flags = text_flags & 0xf9 | 2;
                  bVar3 = text_fill_width;
                }
              }
              goto LAB_CODE_009714;
            }
            bVar2 = 0xf9;
          }
          text_flags = text_flags & bVar2;
          goto LAB_CODE_009714;
        }
        text_flags = text_flags | 0x80;
      }
      goto LAB_CODE_009714;
    }
    bVar8 = 0xfe < printf_fmt_lo;
    printf_fmt_lo = printf_fmt_lo + 1;
    bVar3 = 0;
    printf_fmt_hi = printf_fmt_hi + bVar8;
    text_char = 0x3e;
  }
  cVar4 = cfg_language(bVar3);
  bVar8 = false;
  bVar3 = 5U - cVar4;
  if (5U - cVar4 == 0) {
    if ((text_flags & 0x60) == 0x40) {
      text_flags = text_flags & 0x9f | 0x20;
    }
    else if ((text_flags & 0x60) == 0x20) {
      text_flags = text_flags & 0x9f | 0x40;
    }
    if ((text_flags & 6) == 4) {
      text_flags = text_flags & 0xf9 | 2;
    }
    else {
      bVar3 = text_flags & 6 ^ 2;
      bVar8 = bVar3 == 0;
      if (!bVar8) goto LAB_CODE_0097f0;
      text_flags = text_flags & 0xf9 | 4;
    }
    bVar8 = text_flags == 0;
    bVar3 = text_flags;
  }
LAB_CODE_0097f0:
  do {
    txt_get_text_char_9a08(bVar3);
    if (bVar8) {
LAB_CODE_0098d6:
      txt_get_printf_out_lo_99b6();
      *(undefined1 *)in_FSR0 = 0;
      txt_c18_epilogue_9972();
      return;
    }
    bVar2 = printf_fmt_lo + 1;
    printf_fmt_hi = printf_fmt_hi + (0xfe < printf_fmt_lo);
    if (text_char != 1) {
      if (text_char - 0x25 != 0) {
        if ((text_flags & 8) == 0) {
          bVar8 = false;
          bVar6 = text_char - 0x3c;
          if (text_char - 0x3c == 0) {
            printf_fmt_hi = printf_fmt_hi - ~(bVar2 != 0);
            goto LAB_CODE_0098d6;
          }
        }
        else {
          bVar8 = false;
          bVar6 = text_char - 0x25;
        }
LAB_CODE_0098ce:
        printf_fmt_lo = bVar2;
        bVar3 = txt_set_keys_current_9a80(bVar6);
        *(byte *)in_FSR0 = text_char;
        goto LAB_CODE_0097f0;
      }
      printf_fmt_lo = bVar2;
      txt_set_ui_header_text_997e(0);
      text_column = 0;
      if ((0x2f < text_char) && (text_char < 0x3a)) {
        if (text_char == 0x30) {
          txt_set_ui_header_text_997e(0);
          text_column = 2;
        }
        else {
          text_column = 1;
        }
        text_x_end = 0;
        while ((0x2f < text_char && (text_char < 0x3a))) {
          c18_tmp0 = text_char - 0x30;
          in_PROD = (ushort)text_x_end * 10;
          text_x_end = c18_tmp0 + (char)in_PROD;
          txt_set_ui_header_text_997e();
        }
      }
      if (text_char == 0x3c) {
        txt_set_keys_current_9a80();
        bVar3 = 0x3c;
      }
      else {
        if (text_char == 99) {
          printf_args_lo = printf_args_lo + -1;
          txt_get_printf_args_lo_9a4c();
          text_char = *(byte *)in_FSR0;
          bVar8 = text_char == 0;
          bVar3 = 0;
          bVar6 = text_char;
          bVar2 = printf_fmt_lo;
          if (!bVar8) goto LAB_CODE_0098ce;
          goto LAB_CODE_0097f0;
        }
        if (text_char == 0x73) {
          printf_args_lo = printf_args_lo + -2;
          bVar7 = printf_args_lo == '\0';
          txt_get_printf_args_lo_9a4c();
          printf_tmp_lo = *(undefined1 *)in_FSR0;
          printf_tmp_hi = *(undefined1 *)((short)in_FSR0 + 1);
          while( true ) {
            bVar3 = txt_get_printf_tmp_lo_9a14();
            bVar8 = true;
            if (bVar7) break;
            txt_set_keys_sample_9a8a();
          }
          goto LAB_CODE_0097f0;
        }
        if (text_char != 0x25) {
          bVar8 = text_char == 0x62;
          if (!bVar8) {
            bVar3 = text_char ^ 100;
            bVar8 = bVar3 == 0;
            if (!bVar8) goto LAB_CODE_0097f0;
          }
          bVar3 = printf_handle_conv();
          goto LAB_CODE_0097f0;
        }
        txt_set_keys_current_9a80();
        bVar3 = 0x25;
      }
      bVar8 = true;
      *(byte *)in_FSR0 = bVar3;
      goto LAB_CODE_0097f0;
    }
    printf_fmt_lo = bVar2;
    txt_set_ui_header_text_997e(0);
    uVar5 = cfg_language();
    *(undefined1 *)in_FSR1 = uVar5;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = text_char - 1;
    word_lookup_b();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    cVar4 = puVar1[-1];
    puVar1[-1] = cVar4;
    printf_tmp_lo = (undefined1)in_PROD;
    printf_tmp_hi = (undefined1)((ushort)in_PROD >> 8);
    while( true ) {
      bVar3 = txt_get_printf_tmp_lo_9a14();
      bVar8 = true;
      if (cVar4 == '\0') break;
      txt_set_keys_sample_9a8a();
    }
  } while( true );
}


// ===== 0x0098dc txt_to_lcd_printf_98dc =====

/* Auto: reads text_render_flag; calls lcd_printf,text_draw_string; 16 instr */

void txt_to_lcd_printf_98dc(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  uVar4 = txt_c18_prologue_9a5a();
  puVar3 = (undefined1 *)in_FSR1;
  while( true ) {
    txt_get_text_char_9a08(uVar4);
    if ((unaff_Z & 1) != 0) break;
    txt_frame_push_args_99a8();
    lcd_printf();
    *puVar3 = *puVar3;
    puVar2 = puVar3 + -2;
    puVar3[-1] = puVar3[-1];
    unaff_Z = text_render_flag == '\0';
    uVar4 = 0;
    puVar3 = puVar3 + -2;
    if (!(bool)unaff_Z) {
      txt_push_args_12_0e_9a26();
      uVar4 = text_draw_string();
      *puVar2 = *puVar2;
      puVar3 = puVar2 + -2;
      cVar1 = puVar2[-1];
      puVar2[-1] = cVar1;
      unaff_Z = cVar1 == '\0';
    }
  }
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x0098fc txt_set_ui_hold_counter_98fc =====

/* Auto: writes ui_hold_counter,buzzer_pattern; 11 instr */

void txt_set_ui_hold_counter_98fc(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  
  bVar1 = txt_frag_9a00();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe) = bVar1 - 5;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xf) = (char)((ushort)in_FSR1 >> 8) + -1 + (4 < bVar1);
  txt_get_printf_fmt_lo_999c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -4);
  txt_frame_push_args_9a9c(0xfc);
  return;
}


// ===== 0x009914 txt_set_ui_hold_counter_9914 =====

/* Auto: writes ui_hold_counter,buzzer_pattern; reads printf_fmt_lo,printf_fmt_hi; 14 instr */

void txt_set_ui_hold_counter_9914(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  
  bVar1 = txt_frag_9a00();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe) = bVar1 - 6;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xf) = (char)((ushort)in_FSR1 >> 8) + -1 + (5 < bVar1);
  printf_fmt_lo = *(undefined1 *)((short)in_FSR2 + -3);
  printf_fmt_hi = *(undefined1 *)((short)in_FSR2 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  txt_frame_push_args_9a9c(0xfb);
  return;
}


// ===== 0x009936 txt_to_lcd_printf_9936 =====

/* Auto: writes printf_args_lo,printf_args_hi; calls lcd_printf,text_measure_width; 20 instr */

void txt_to_lcd_printf_9936(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  txt_c18_prologue_9a5a();
  txt_get_printf_fmt_lo_999c();
  printf_args_lo = (byte)in_FSR2 - 4;
  printf_args_hi = (char)((ushort)in_FSR2 >> 8) + -1 + (3 < (byte)in_FSR2);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  lcd_printf();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar1[-3];
  txt_push_args_12_0e_9a26();
  text_measure_width();
  txt_stack_adjust_9aa8();
  return;
}


// ===== 0x009964 txt_to_txt_get_c18_tmp0_9964 =====

/* Auto: Small wrapper around txt_get_c18_tmp0; 5 instr */

void txt_to_txt_get_c18_tmp0_9964(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  txt_c18_prologue_9a5a();
  txt_get_c18_tmp0_9ac8();
  *(undefined1 *)in_FSR1 = in_PRODL;
  *(undefined1 *)((short)in_FSR1 + 1) = in_PRODH;
  return;
}


// ===== 0x009972 txt_c18_epilogue_9972 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void txt_c18_epilogue_9972(void)

{
  return;
}


// ===== 0x00997e txt_set_ui_header_text_997e =====

/* Auto: writes ui_header_text; reads text_char,TABLAT; 7 instr */

undefined1 txt_set_ui_header_text_997e(void)

{
  byte bVar1;
  byte unaff_BSR;
  undefined1 *in_TBLPTR;
  
  txt_get_printf_fmt_lo_9ab0();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xb) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xb) + (0xfe < bVar1);
  text_char = *in_TBLPTR;
  return 0;
}


// ===== 0x00998e txt_get_TBLPTRH_998e =====

/* Auto: reads TBLPTRH,TBLPTRL; 7 instr */

char txt_get_TBLPTRH_998e(void)

{
  char in_FramePointer2_0000fffe;
  
  return in_FramePointer2_0000fffe << 1;
}


// ===== 0x00999c txt_get_printf_fmt_lo_999c =====

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


// ===== 0x0099a8 txt_frame_push_args_99a8 =====

/* Auto: Copy stack-frame arguments onto the stack for a call; 5 instr */

undefined1 txt_frame_push_args_99a8(void)

{
  return 0xfd;
}


// ===== 0x0099b6 txt_get_printf_out_lo_99b6 =====

/* Auto: reads printf_out_lo,printf_out_hi; 3 instr */

void txt_get_printf_out_lo_99b6(void)

{
  return;
}


// ===== 0x0099c0 txt_frame_access_99c0 =====

/* Auto: Access stack-frame local/argument; 5 instr */

byte txt_frame_access_99c0(void)

{
  BADSPACEBASE *in_FSR2;
  
  txt_c18_prologue_9a5a();
  return *(byte *)((short)in_FSR2 + -3) ^ 4;
}


// ===== 0x0099ca txt_get_TBLPTRH_99ca =====

/* Auto: reads TBLPTRH,c18_tmp0,TABLAT,c18_tmp1; 8 instr */

void txt_get_TBLPTRH_99ca(char param_1)

{
  undefined3 in_TBLPTR;
  undefined1 *puVar1;
  byte unaff_C;
  
  puVar1 = (undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                    CONCAT11((char)((uint3)in_TBLPTR >> 8) + param_1 + (unaff_C & 1),(char)in_TBLPTR
                            ));
  c18_tmp0 = *puVar1;
  c18_tmp1 = puVar1[1];
  return;
}


// ===== 0x0099e2 txt_frame_access_99e2 =====

/* Auto: Access stack-frame local/argument; 4 instr */

undefined1 txt_frame_access_99e2(void)

{
  BADSPACEBASE *in_FSR2;
  
  txt_c18_prologue_9a5a();
  return *(undefined1 *)((short)in_FSR2 + -2);
}


// ===== 0x0099ea txt_get_printf_out_lo_99ea =====

/* Auto: reads printf_out_lo,printf_out_hi,printf_args_lo,printf_args_hi; 7 instr */

undefined1 txt_get_printf_out_lo_99ea(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}


// ===== 0x009a00 txt_frag_9a00 =====

/* Auto: compiler fragment: RCALL 0x009a5a ; MOVLB #0xe ; MOVF FSR1L,w,ACCESS ; RETURN 0x0 */

undefined1 txt_frag_9a00(void)

{
  undefined1 in_FSR1L;
  
  txt_c18_prologue_9a5a();
  return in_FSR1L;
}


// ===== 0x009a08 txt_get_text_char_9a08 =====

/* Auto: reads text_char,TABLAT; 5 instr */

undefined1 txt_get_text_char_9a08(void)

{
  undefined1 *in_TBLPTR;
  
  txt_get_printf_fmt_lo_9ab0();
  text_char = *in_TBLPTR;
  return *in_TBLPTR;
}


// ===== 0x009a14 txt_get_printf_tmp_lo_9a14 =====

/* Auto: reads printf_tmp_lo,TBLPTRL,printf_tmp_hi,TBLPTRH,text_char,TABLAT; 6 instr */

undefined1 txt_get_printf_tmp_lo_9a14(void)

{
  undefined3 in_TBLPTR;
  
  text_char = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(printf_tmp_hi,printf_tmp_lo));
  return text_char;
}


// ===== 0x009a26 txt_push_args_12_0e_9a26 =====

/* Auto: Push constant arguments [18, 14]; 5 instr */

undefined1 txt_push_args_12_0e_9a26(void)

{
  return 0xe;
}


// ===== 0x009a30 txt_get_text_row_9a30 =====

/* Auto: reads text_row; 5 instr */

void txt_get_text_row_9a30(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x009a3e txt_set_text_x_end_9a3e =====

/* Auto: writes text_x_end; 6 instr */

void txt_set_text_x_end_9a3e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  text_x_end = text_x_end + '\x01';
  return;
}


// ===== 0x009a4c txt_get_printf_args_lo_9a4c =====

/* Auto: reads printf_args_lo,printf_args_hi; 5 instr */

undefined1 txt_get_printf_args_lo_9a4c(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}


// ===== 0x009a5a txt_c18_prologue_9a5a =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void txt_c18_prologue_9a5a(void)

{
  return;
}


// ===== 0x009a6c txt_to_cfg_language_9a6c =====

/* Auto: calls cfg_language,word_lookup_a; 8 instr */

void txt_to_cfg_language_9a6c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = cfg_language();
  *(undefined1 *)in_FSR1 = uVar2;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  word_lookup_a();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x009a80 txt_set_keys_current_9a80 =====

/* Auto: writes keys_current; 5 instr */

undefined1 txt_set_keys_current_9a80(void)

{
  byte bVar1;
  byte unaff_BSR;
  
  txt_get_printf_out_lo_99b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + (0xfe < bVar1);
  return 0;
}


// ===== 0x009a8a txt_set_keys_sample_9a8a =====

/* Auto: writes keys_sample,keys_current; reads text_char; 8 instr */

void txt_set_keys_sample_9a8a(void)

{
  byte bVar1;
  byte unaff_BSR;
  char cVar2;
  BADSPACEBASE *in_FSR0;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x11) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x11) + (0xfe < bVar1);
  cVar2 = txt_get_printf_out_lo_99b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + cVar2 + (0xfe < bVar1);
  *(undefined1 *)in_FSR0 = text_char;
  return;
}


// ===== 0x009a9c txt_frame_push_args_9a9c =====

/* Auto: Copy stack-frame arguments onto the stack for a call; 5 instr */

void txt_frame_push_args_9a9c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  txt_to_lcd_printf_98dc();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x009aa8 txt_stack_adjust_9aa8 =====

/* Auto: Software stack push/pop helper; 4 instr */

void txt_stack_adjust_9aa8(void)

{
  txt_c18_epilogue_9972();
  return;
}


// ===== 0x009ab0 txt_get_printf_fmt_lo_9ab0 =====

/* Auto: reads printf_fmt_lo,TBLPTRL,printf_fmt_hi,TBLPTRH; 3 instr */

void txt_get_printf_fmt_lo_9ab0(void)

{
  return;
}


// ===== 0x009aba cfg_language =====

/* Language code from SYSTEMCONFIG2 bits 3-5 (0 EN, 4 RU, 5 HE) */

byte cfg_language(void)

{
  return (cfg_systemconfig2 & 0x38) >> 3;
}


// ===== 0x009ac8 txt_get_c18_tmp0_9ac8 =====

/* Auto: reads c18_tmp0,c18_tmp1; 4 instr */

void txt_get_c18_tmp0_9ac8(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  txt_to_cfg_language_9a6c();
  c18_tmp0 = in_PRODL;
  c18_tmp1 = in_PRODH;
  return;
}


// ===== 0x009ad4 os_set_OScTcbP_9ad4 =====

/* Auto: writes OScTcbP,OScTcbP_hi,os_tmp_tcb_ptr,os_tmp_tcb_ptr_hi,OSdelayQP,OSdelayQP_hi; 14 instr
    */

void os_set_OScTcbP_9ad4(void)

{
  OScTcbP = 0;
  OScTcbP_hi = 0;
  os_tmp_tcb_ptr = 0;
  os_tmp_tcb_ptr_hi = 0;
  OSdelayQP = 0;
  OSdelayQP_hi = 0;
  OSlostTicks = 0;
  OStimerTicks = 0;
  OSeligQTail = 0;
  OSeligQTail_hi = 0;
  OSeligQP = 0;
  OSeligQP_hi = 0;
  return;
}


// ===== 0x009af0 OSCreateTask =====

/* Salvo: create task (function pointer, TCB pointer, priority) */

void OSCreateTask(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar2;
  
  os_c18_prologue_a16e();
  OSDisableInts();
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -6) & 0x7f;
  os_frame_push_args_a244();
  os_frame_access_9b2c();
  os_pop3_return_a2e4();
  os_frame_load_ptr_arg_a19c();
  os_frag_a260();
  os_frame_load_ptr_arg_a19c();
  *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x7f;
  os_frame_load_ptr_arg_a19c();
  puVar2 = (undefined1 *)((short)in_FSR0 + 1);
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  os_frame_access_a200();
  os_frame_load_ptr_arg_a19c();
  os_const_then_a2dc_a1ca();
  *puVar2 = OStimerTicks;
  if ((puVar1[-6] & 0x80) == 0) {
    os_frame_load_ptr_arg_a19c();
    os_stack_adjust_a220();
    os_frame_push_args_a244();
    os_to_OSInsPrioQ_a1e6();
  }
  OSRestoreInts();
  os_c18_epilogue_a180(0);
  return;
}


// ===== 0x009b2c os_frame_access_9b2c =====

/* Auto: Access stack-frame local/argument; 27 instr */

void os_frame_access_9b2c(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  os_stack_adjust_a28c();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(byte *)((short)in_FSR2 + -4) < 0x10) {
    *(undefined1 *)((short)in_FSR2 + 1) = 0;
  }
  else {
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + -3) = 0xf;
    *(undefined1 *)((short)in_FSR2 + 2) = 1;
  }
  puVar3 = puVar2 + 1;
  c18_tmp0 = puVar2[-4];
  os_frame_load_ptr_arg_a160();
  *(byte *)in_FSR0 = c18_tmp0 & 0xf | *(byte *)in_FSR0 & 0xf0;
  uVar1 = *puVar3;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  os_c18_epilogue_a180(uVar1);
  return;
}


// ===== 0x009b64 OSInsPrioQ =====

/* Salvo: insert TCB into priority queue */

void OSInsPrioQ(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  BADSPACEBASE *in_FSR1;
  byte *pbVar9;
  char cVar10;
  undefined1 uVar11;
  BADSPACEBASE *in_FSR0;
  
  os_stack_adjust_a28c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  pbVar9 = (byte *)((short)in_FSR1 + 4);
  cVar10 = *(char *)((short)in_FSR1 + 3);
  *(char *)((short)in_FSR1 + 3) = cVar10;
  os_frame_load_ptr_arg_a19c();
  os_chain_fna27c_fna26a_a2fc();
  if (cVar10 == '\0') {
    os_frame_load_ptr_arg_a19c();
    os_frame_access_a200();
    os_frame_load_ptr_arg_a160();
    *(undefined1 *)((short)in_FSR0 + 4) = 0;
    *(undefined1 *)((short)in_FSR0 + 6) = 0;
    c18_tmp0 = 0;
  }
  else {
    *(undefined1 *)((short)in_FSR2 + 3) = 0;
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + 5) = 0;
    os_get_c18_tmp0_a232();
    if (c18_tmp1 == '\0') {
      cVar10 = os_chain_fna272_fna292_a2ec(0);
      puVar2[(short)cVar10 + 1] = *(undefined1 *)in_FSR0;
      while( true ) {
        puVar4 = puVar2 + 1;
        os_frame_load_ptr_arg_a160();
        os_const_then_a2dc_a1ca();
        c18_tmp0 = *(byte *)in_FSR0;
        puVar5 = puVar4 + 1;
        cVar10 = c18_tmp0 - puVar4[5];
        puVar6 = puVar4 + 1;
        if ((c18_tmp0 < (byte)puVar4[5]) ||
           (os_ptr_add_a1ba(cVar10), puVar6 = puVar5, cVar10 == '\0')) break;
        cVar10 = os_chain_fna272_fna292_a2ec();
        puVar2 = puVar5 + 1;
        *pbVar9 = puVar5[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 + *(char *)in_FSR0;
        puVar5[6] = *pbVar9;
      }
      os_frag_a26a();
      puVar7 = puVar6;
      if (cVar10 != '\0') {
        cVar10 = os_chain_fna272_fna292_a2ec();
        *pbVar9 = puVar6[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 - *(char *)in_FSR0;
        puVar7 = puVar6 + 2;
        puVar6[6] = *pbVar9;
      }
      os_frame_load_ptr_arg_a160();
      cVar10 = os_frag_a292();
      puVar8 = puVar7 + 1;
      cVar1 = puVar7[(short)cVar10 + 1];
      cVar10 = *(char *)in_FSR0;
      *(char *)in_FSR0 = cVar10 - cVar1;
      os_frag_a26a();
      puVar6 = puVar8;
      if (cVar10 - cVar1 != '\0') {
        os_frame_access_a2f2();
        cVar10 = os_chain_fna272_fna292_a2ec();
        *(char *)in_FSR0 = *(char *)in_FSR0 - puVar8[(short)cVar10 + 1];
        puVar6 = puVar8 + 1;
      }
    }
    else {
      os_frame_load_ptr_arg_a160();
      *pbVar9 = *(byte *)in_FSR0 & 0xf;
      puVar2[5] = *pbVar9;
      puVar7 = puVar2 + 1;
      do {
        os_copy_ptr_field_a272();
        puVar3 = puVar7 + 1;
        cVar10 = puVar7[5] - (*(byte *)in_FSR0 & 0xf);
        puVar6 = puVar7 + 1;
        if ((byte)puVar7[5] < (*(byte *)in_FSR0 & 0xf)) break;
        os_ptr_add_a1ba(cVar10);
        puVar6 = puVar3;
        puVar7 = puVar3;
      } while (cVar10 != '\0');
    }
    os_ptr_add_a20e();
    if ((char)puVar6 == -2) {
      uVar11 = os_frame_load_ptr_arg_a19c();
    }
    else {
      os_frame_load_ptr_arg_a252();
      uVar11 = 0;
    }
    os_frame_access_a200(uVar11);
    os_frame_load_ptr_arg_a160();
    c18_tmp0 = os_copy_ptr_field_a298();
  }
  if ((byte)pbVar9 < 5) {
    *(undefined1 *)((ushort)pbVar9 & 0xff00) = *(undefined1 *)((ushort)pbVar9 & 0xff00);
  }
  os_c18_epilogue_a180(c18_tmp0);
  return;
}


// ===== 0x009c40 os_insert_delay_queue =====

/* Salvo internal: insert task into delay queue */

void os_insert_delay_queue(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  BADSPACEBASE *in_FSR0;
  bool bVar10;
  
  os_c18_prologue_a16e();
  bVar6 = (byte)in_FSR1;
  if (0xf9 < bVar6) {
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),0xff);
    in_FSR1 = (BADSPACEBASE *)(puVar7 + 1);
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),bVar6 + 6);
  os_frame_load_ptr_arg_a19c();
  os_copy_ptr_field_a27c();
  *(undefined1 *)((short)in_FSR2 + 5) = 0;
  puVar1 = (undefined1 *)((short)in_FSR2 + 2);
  *(undefined1 *)((short)in_FSR2 + 7) = 0;
  bVar10 = true;
  os_frame_load_ptr_arg_a160();
  os_const_then_a2dc_a1ee();
  os_frame_access_a2a4();
  do {
    os_frag_a26a();
    if (bVar10) {
      c18_tmp0 = 1;
LAB_CODE_009cd4:
      if ((byte)puVar8 < 6) {
        *(undefined1 *)((ushort)puVar8 & 0xff00) = *(undefined1 *)((ushort)puVar8 & 0xff00);
      }
      os_c18_epilogue_a180(c18_tmp0);
      return;
    }
    puVar5 = puVar1 + 1;
    bVar6 = puVar1[-3] ^ puVar1[1];
    if (bVar6 == 0) {
      puVar1[2] = puVar1[2];
      puVar5 = puVar1 + 2;
      puVar2 = puVar1 + 2;
      bVar6 = puVar1[-1] ^ puVar1[3];
      if (bVar6 == 0) {
        os_ptr_add_a20e();
        if ((char)(puVar1 + 2) != -4) {
          puVar3 = puVar2 + 2;
          in_FSR0 = (BADSPACEBASE *)CONCAT11(puVar2[7],puVar2[5]);
          os_const_then_a2dc_a1ee();
        }
        else {
          os_frame_load_ptr_arg_a19c();
          puVar3 = puVar2;
        }
        *(undefined1 *)in_FSR0 = puVar3[3];
        puVar4 = puVar3 + 2;
        *(undefined1 *)((short)in_FSR0 + 1) = puVar3[5];
        os_get_c18_tmp0_a232();
        if ((char)(puVar1 + 2) == -4) {
          if (c18_tmp1 == '\0') {
            cVar9 = (char)puVar4;
            os_ptr_add_a20e();
            if (cVar9 != -2) {
              os_frame_access_a2f2();
              os_frame_load_ptr_arg_a252();
              cVar9 = os_frag_a292();
              *(char *)in_FSR0 = *(char *)in_FSR0 + puVar4[(short)cVar9 + 1];
            }
          }
        }
        c18_tmp0 = 0;
        goto LAB_CODE_009cd4;
      }
    }
    bVar10 = false;
    os_frag_a302(bVar6);
    puVar5[5] = *(undefined1 *)in_FSR0;
    puVar1 = puVar5 + 2;
    puVar5[7] = *(undefined1 *)((short)in_FSR0 + 1);
    os_copy_ptr_field_a272();
    os_const_then_a2dc_a1ee();
    os_copy_ptr_field_a27c();
  } while( true );
}


// ===== 0x009ce6 OSSched =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Salvo RTOS scheduler (runs eligible tasks, processes delay queue) */

byte OSSched(void)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  short sVar15;
  char *pcVar16;
  byte *pbVar17;
  byte *pbVar18;
  undefined1 *puVar19;
  
  clearWatchDogTimer();
  uVar2 = INTCON;
  pbVar7 = &FramePointer10x0001;
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  while (OSeligQP_hi != '\0' || OSeligQP != 0) {
    os_tmp_tcb_ptr = OSeligQP;
    os_tmp_tcb_ptr_hi = OSeligQP_hi;
    pbVar14 = (byte *)CONCAT11(OSeligQP_hi + (0xfc < OSeligQP),OSeligQP + 3);
    sVar15 = CONCAT11(OSeligQP_hi,OSeligQP);
    OSeligQP = *pbVar14;
    OSeligQP_hi = pbVar14[1];
    *(undefined1 *)(sVar15 + 4) = 0;
    *(undefined1 *)(sVar15 + 6) = 0;
    *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) =
         *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x8f | 0x50;
    *pbVar7 = 0x98;
    pbVar7[1] = 0;
    pbVar7[2] = os_tmp_tcb_ptr;
    puVar5 = pbVar7 + 4;
    pbVar7[3] = os_tmp_tcb_ptr_hi;
    OSInsPrioQ();
    *puVar5 = *puVar5;
    puVar5[-1] = puVar5[-1];
    puVar5[-2] = puVar5[-2];
    puVar5[-3] = puVar5[-3];
    if (OSeligQP_hi == '\0' && OSeligQP == 0) {
      OSeligQTail = 0;
      OSeligQTail_hi = 0;
    }
    pbVar6 = (byte *)CONCAT11((char)((ushort)(puVar5 + -4) >> 8) - ~((char)(puVar5 + -4) != '\0'),
                              (char)(puVar5 + -4) + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 | *pbVar6;
    bVar1 = INTCON;
    pbVar7 = pbVar6 + 1;
    *pbVar6 = bVar1 & (PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
  }
  while (OSlostTicks != '\0') {
    OSlostTicks = OSlostTicks + -1;
    os_tmp_tcb_ptr = OSdelayQP;
    os_tmp_tcb_ptr_hi = OSdelayQP_hi;
    if (OSdelayQP_hi != '\0' || OSdelayQP != 0) {
      pcVar16 = (char *)CONCAT11(OSdelayQP_hi + (0xfa < OSdelayQP),OSdelayQP + 5);
      *pcVar16 = *pcVar16 + -1;
    }
    while ((os_tmp_tcb_ptr_hi != '\0' || os_tmp_tcb_ptr != 0 &&
           (*(char *)CONCAT11(os_tmp_tcb_ptr_hi + (0xfa < os_tmp_tcb_ptr),os_tmp_tcb_ptr + 5) ==
            '\0'))) {
      pbVar17 = (byte *)CONCAT11(os_tmp_tcb_ptr_hi + (0xfc < os_tmp_tcb_ptr),os_tmp_tcb_ptr + 3);
      OSdelayQP = *pbVar17;
      OSdelayQP_hi = pbVar17[1];
      *(undefined1 *)CONCAT11(os_tmp_tcb_ptr_hi + (0xfa < os_tmp_tcb_ptr),os_tmp_tcb_ptr + 5) =
           OStimerTicks;
      *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) =
           *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x8f | 0x50;
      *pbVar7 = 0x98;
      pbVar7[1] = 0;
      pbVar7[2] = os_tmp_tcb_ptr;
      puVar8 = pbVar7 + 4;
      pbVar7[3] = os_tmp_tcb_ptr_hi;
      OSInsPrioQ();
      *puVar8 = *puVar8;
      puVar8[-1] = puVar8[-1];
      puVar8[-2] = puVar8[-2];
      puVar8[-3] = puVar8[-3];
      os_tmp_tcb_ptr = OSdelayQP;
      os_tmp_tcb_ptr_hi = OSdelayQP_hi;
      pbVar9 = (byte *)CONCAT11((char)((ushort)(puVar8 + -4) >> 8) - ~((char)(puVar8 + -4) != '\0'),
                                (char)(puVar8 + -4) + -1);
      bVar1 = INTCON;
      INTCON = bVar1 & ~(PEIE | GIE);
      bVar1 = INTCON;
      INTCON = bVar1 | *pbVar9;
      bVar1 = INTCON;
      pbVar7 = pbVar9 + 1;
      *pbVar9 = bVar1 & (PEIE | GIE);
      bVar1 = INTCON;
      INTCON = bVar1 & ~(PEIE | GIE);
    }
  }
  os_tmp_tcb_ptr = OScTcbP;
  os_tmp_tcb_ptr_hi = OScTcbP_hi;
  cVar4 = (char)pbVar7;
  if (OScTcbP_hi == '\0' && OScTcbP == 0) {
    pbVar13 = (byte *)CONCAT11((char)((ushort)pbVar7 >> 8) - ~(cVar4 != '\0'),cVar4 + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 | *pbVar13;
    OSIdlingHook(*pbVar13);
    bVar1 = INTCON;
    pbVar12 = pbVar13 + 1;
    *pbVar13 = bVar1 & (PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
  }
  else {
    pbVar18 = (byte *)CONCAT11(OScTcbP_hi + (0xfc < OScTcbP),OScTcbP + 3);
    pbVar10 = (byte *)CONCAT11((char)((ushort)pbVar7 >> 8) - ~(cVar4 != '\0'),cVar4 + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    bVar1 = *pbVar10;
    bVar3 = INTCON;
    INTCON = bVar3 | bVar1;
    puVar19 = (undefined1 *)CONCAT11(OScTcbP_hi,OScTcbP);
    OScTcbP = *pbVar18;
    OScTcbP_hi = pbVar18[1];
    *puVar19 = *puVar19;
    c18_tmp0 = puVar19[1];
    c18_tmp1 = puVar19[2];
    OSDispatch(bVar1);
    bVar1 = INTCON;
    pbVar12 = pbVar10 + 1;
    *pbVar10 = bVar1 & (PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    if ((*(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x70) == 0x50) {
      pbVar10[1] = 0x98;
      pbVar10[2] = 0;
      pbVar10[3] = os_tmp_tcb_ptr;
      pbVar11 = pbVar10 + 5;
      pbVar10[4] = os_tmp_tcb_ptr_hi;
      OSInsPrioQ();
      *pbVar11 = *pbVar11;
      pbVar11[-1] = pbVar11[-1];
      pbVar11[-2] = pbVar11[-2];
      pbVar12 = pbVar11 + -4;
      pbVar11[-3] = pbVar11[-3];
    }
  }
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar12 >> 8) - ~((char)pbVar12 != '\0'),
                            (char)pbVar12 + -1);
  bVar3 = INTCON;
  INTCON = bVar3 | bVar1;
  return bVar1;
}


// ===== 0x009e94 OSDispatch =====

/* Salvo: dispatch current task */

byte OSDispatch(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar3;
  byte *pbVar4;
  
  OSDispatch(c18_tmp0);
  bVar1 = INTCON;
  pbVar4 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = bVar1 & (PEIE | GIE);
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  if ((*(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x70) == 0x50) {
    *(undefined1 *)((short)in_FSR1 + 1) = 0x98;
    *(undefined1 *)((short)in_FSR1 + 2) = 0;
    *(undefined1 *)((short)in_FSR1 + 3) = os_tmp_tcb_ptr;
    pbVar3 = (byte *)((short)in_FSR1 + 5);
    *(undefined1 *)((short)in_FSR1 + 4) = os_tmp_tcb_ptr_hi;
    OSInsPrioQ();
    *pbVar3 = *pbVar3;
    pbVar3[-1] = pbVar3[-1];
    pbVar3[-2] = pbVar3[-2];
    pbVar4 = pbVar3 + -4;
    pbVar3[-3] = pbVar3[-3];
  }
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar4 >> 8) - ~((char)pbVar4 != '\0'),(char)pbVar4 + -1)
  ;
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}


// ===== 0x009f10 OSTimer =====

/* Salvo: advance OS timer tick counters */

undefined1 OSTimer(void)

{
  OStimerTicks = OStimerTicks + '\x01';
  c18_tmp0 = OSlostTicks;
  c18_tmp1 = 0;
  if (0xfe < OSlostTicks != true) {
    return 1;
  }
  OSlostTicks = OSlostTicks + 1;
  return 0;
}


// ===== 0x009f30 OS_Yield =====

/* Salvo context switch: save resume address in TCB and return to OSSched */

void OS_Yield(void)

{
  BADSPACEBASE *in_FSR0;
  
  OSDisableInts();
  os_get_os_tmp_tcb_ptr_a1ce();
  *(undefined1 *)((short)in_FSR0 + 2) = 0x9f;
  *(undefined1 *)((short)in_FSR0 + 4) = 0;
  OSRestoreInts();
  return;
}


// ===== 0x009f46 OSCreateSem =====

/* Salvo: create semaphore (ECB pointer, initial count) */

void OSCreateSem(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  os_to_OSDisableInts_a2b2();
  *(undefined1 *)in_FSR0 = 0;
  *(undefined1 *)((short)in_FSR0 + 1) = 0;
  os_chain_fna160_fna21c_a286();
  *(undefined1 *)in_FSR0 = *(undefined1 *)((short)in_FSR2 + -4);
  OSRestoreInts();
  os_c18_epilogue_a180(0);
  return;
}


// ===== 0x009f5a OSWaitSem =====

/* Salvo: wait on semaphore (returns 'must wait' flag) */

void OSWaitSem(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  BADSPACEBASE *in_FSR0;
  
  mod_to_OSDisableInts_a30c();
  os_chain_fna160_fna21c_a286();
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR0;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR2;
  os_frame_push_args_a1d8();
  os_wait_event_internal();
  uVar1 = os_pop3_return_a2e4();
  *(undefined1 *)in_FSR2 = uVar1;
  if ((*(byte *)in_FSR2 & 8) != 0) {
    os_chain_fna160_fna21c_a286();
    *(char *)in_FSR0 = *(char *)in_FSR0 + -1;
  }
  os_to_OSRestoreInts_a2d4();
  os_c18_epilogue_a180();
  return;
}


// ===== 0x009f7a OSSignalSem =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Salvo: signal semaphore */

void OSSignalSem(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR0;
  byte *pbVar3;
  
  os_stack_adjust_a28c();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  OSDisableInts();
  os_chain_fna160_fna21c_a286();
  c18_tmp0 = *(byte *)in_FSR0;
  c18_tmp1 = 0;
  if (0xfe < c18_tmp0 == true) {
    os_chain_fna160_fna21c_a286(0);
    cVar1 = *(char *)in_FSR0;
    *(char *)in_FSR0 = cVar1 + '\x01';
    os_frame_load_ptr_arg_a160();
    os_chain_fna27c_fna26a_a2fc();
    if (cVar1 + '\x01' != '\0') {
      if ((OSeligQP_hi | OSeligQP) == 0) {
        OSeligQP = *(byte *)in_FSR2;
        OSeligQP_hi = *(byte *)((short)in_FSR2 + 1);
      }
      else {
        in_FSR0 = (BADSPACEBASE *)CONCAT11(OSeligQTail_hi,OSeligQTail);
        os_copy_ptr_field_a298(OSeligQP_hi | OSeligQP);
      }
      OSeligQTail = *(undefined1 *)in_FSR2;
      OSeligQTail_hi = *(undefined1 *)((short)in_FSR2 + 1);
      os_copy_ptr_field_a272();
      os_const_then_a2dc_a1ee();
      pbVar3 = (byte *)((short)in_FSR0 + 1);
      c18_tmp0 = *(byte *)in_FSR0;
      c18_tmp1 = *(byte *)((short)in_FSR0 + 1);
      os_frame_load_ptr_arg_a160();
      *pbVar3 = c18_tmp0;
      pbVar3[1] = c18_tmp1;
      os_copy_ptr_field_a272();
      pbVar3[4] = 0;
      pbVar3[6] = 0;
    }
    *(undefined1 *)in_FSR2 = 0;
  }
  else {
    *(undefined1 *)in_FSR2 = 4;
  }
  os_to_OSRestoreInts_a2d4();
  *puVar2 = *puVar2;
  os_c18_epilogue_a180();
  return;
}


// ===== 0x009ff4 os_wait_event_internal =====

/* Salvo internal: event wait handling */

void os_wait_event_internal(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  BADSPACEBASE *in_FSR0;
  
  os_c18_prologue_a16e();
  if (*(char *)((short)in_FSR2 + -4) == '\0') {
    os_get_os_tmp_tcb_ptr_a1ce(0);
    *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x8f | 0x30;
    os_get_os_tmp_tcb_ptr_a1ce();
    *(byte *)in_FSR0 = *(byte *)in_FSR0 | 0x80;
    os_frame_load_ptr_arg_a160();
    c18_tmp0 = SUB21(in_FSR0,0);
    c18_tmp1 = (char)((ushort)in_FSR0 >> 8);
    *(undefined1 *)in_FSR1 = c18_tmp0;
    *(char *)((short)in_FSR1 + 1) = (char)((ushort)in_FSR0 >> 8);
    os_get_os_tmp_tcb_ptr_a2ba();
  }
  else {
    os_get_os_tmp_tcb_ptr_a1ce(*(char *)((short)in_FSR2 + -4));
    if ((*(byte *)in_FSR0 & 0x80) != 0) {
      os_get_os_tmp_tcb_ptr_a1ce();
      *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x7f;
      uVar1 = 9;
      goto LAB_CODE_00a036;
    }
    os_get_os_tmp_tcb_ptr_a1ce();
    *(byte *)in_FSR0 = *(byte *)in_FSR0 | 0x80;
  }
  uVar1 = 2;
LAB_CODE_00a036:
  os_c18_epilogue_a180(uVar1);
  return;
}


// ===== 0x00a038 OSDelay =====

/* Salvo: delay current task for N ticks */

void OSDelay(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  char cVar6;
  BADSPACEBASE *in_FSR0;
  
  mod_to_OSDisableInts_a30c();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    os_get_os_tmp_tcb_ptr_a1ce(0);
    os_frag_a260();
  }
  else {
    os_get_os_tmp_tcb_ptr_a1ce(*(char *)((short)in_FSR2 + -2));
    *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x8f | 0x20;
    if (puVar2[-3] == '\0') {
      pcVar4 = puVar2 + 2;
      cVar6 = puVar2[-1];
      puVar2[2] = cVar6;
    }
    else {
      pcVar3 = puVar2 + 2;
      puVar2[2] = puVar2[-1];
      os_get_os_tmp_tcb_ptr_a1ce();
      os_const_then_a2dc_a1ca();
      *pcVar3 = *pcVar3 + *(char *)in_FSR0;
      *pcVar3 = *pcVar3 - OStimerTicks;
      pcVar4 = pcVar3 + 1;
      bVar1 = pcVar3[-2];
      cVar6 = (bVar1 - pcVar3[1]) + '\x02';
      if (0xfd < bVar1 && bVar1 + 2 <= (byte)pcVar3[1]) {
        pcVar4 = pcVar3 + 2;
        cVar6 = pcVar3[-1];
        pcVar3[2] = pcVar3[2] + cVar6;
      }
    }
    os_get_os_tmp_tcb_ptr_a1ce(cVar6);
    os_const_then_a2dc_a1ca();
    *(char *)in_FSR0 = *pcVar4;
    puVar5 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0xae;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
    *puVar5 = 0;
    os_get_os_tmp_tcb_ptr_a2ba();
  }
  OSRestoreInts();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  os_c18_epilogue_a180();
  return;
}


// ===== 0x00a09a OSStartTask =====

/* Salvo: start a stopped task (probable) */

void OSStartTask(void)

{
  char cVar1;
  
  os_to_OSDisableInts_a2b2();
  cVar1 = os_tcb_get_state_a2c6();
  if (cVar1 == '\x01') {
    os_frame_load_ptr_arg_a160();
    os_stack_adjust_a220();
    os_frame_push_args_a1d8();
    os_to_OSInsPrioQ_a1e6();
    OSRestoreInts();
  }
  else {
    OSRestoreInts();
  }
  os_c18_epilogue_a180(cVar1 != '\x01');
  return;
}


// ===== 0x00a0b6 OSStopTask =====

/* Salvo: stop a task (probable) */

void OSStopTask(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  char cVar1;
  
  mod_to_OSDisableInts_a30c();
  os_frame_push_args_a1d8();
  cVar1 = os_calc_array_ptr_a0e2();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  if (cVar1 != '\0') {
    *(undefined1 *)((short)in_FSR1 + -2) = 1;
    os_frame_push_args_a1d8();
    os_remove_from_queues();
    cVar1 = os_pop3_return_a2e4();
    if (cVar1 == '\0') {
      os_frame_load_ptr_arg_a160();
      os_frag_a260();
      *(undefined1 *)in_FSR2 = 0;
      goto LAB_CODE_00a0de;
    }
  }
  *(undefined1 *)in_FSR2 = 1;
LAB_CODE_00a0de:
  os_to_OSRestoreInts_a2d4();
  os_c18_epilogue_a180();
  return;
}


// ===== 0x00a0e2 os_calc_array_ptr_a0e2 =====

/* Auto: Compute array element address in FSR0; 26 instr */

void os_calc_array_ptr_a0e2(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  
  os_stack_adjust_a28c();
  puVar5 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  pbVar7 = (byte *)CONCAT11((char)((ushort)in_FSR2 >> 8) + -1 + (3 < (byte)in_FSR2),
                            (byte)in_FSR2 - 4);
  bVar2 = pbVar7[1] | *pbVar7;
  puVar3 = (undefined1 *)in_FSR2;
  puVar6 = (undefined1 *)((short)in_FSR1 + 1);
  if (bVar2 != 0) {
    os_frame_load_ptr_arg_a160(bVar2);
    os_frame_access_a1f2();
    puVar3 = (undefined1 *)((short)in_FSR2 + 1);
    puVar4 = (undefined1 *)((short)in_FSR2 + 1);
    puVar6 = puVar5;
    if (*(char *)((short)in_FSR2 + 2) != '\a') {
      *(undefined1 *)((short)in_FSR2 + 1) = 1;
      goto LAB_CODE_00a10e;
    }
  }
  *puVar3 = 0;
  puVar4 = puVar3;
  puVar5 = puVar6;
LAB_CODE_00a10e:
  uVar1 = *puVar4;
  *puVar5 = *puVar5;
  puVar5[-1] = puVar5[-1];
  os_c18_epilogue_a180(uVar1);
  return;
}


// ===== 0x00a116 os_remove_from_queues =====

/* Salvo internal: remove task from eligible/delay queues */

void os_remove_from_queues(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  undefined1 uVar6;
  
  os_stack_adjust_a28c();
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)in_FSR2 = 0;
  os_frame_load_ptr_arg_a160();
  cVar5 = os_frame_access_a1f2();
  if (cVar5 == '\x02') {
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    if (*(char *)((short)in_FSR2 + -4) == '\0') goto LAB_CODE_00a158;
    *puVar3 = 0xae;
  }
  else {
    if (((cVar5 != '\x05') && (cVar5 != '\x06')) && (cVar5 != '\x04')) {
      *(undefined1 *)in_FSR2 = 1;
      puVar2 = (undefined1 *)in_FSR2;
      goto LAB_CODE_00a158;
    }
    *puVar3 = 0x98;
    puVar1 = (undefined1 *)in_FSR2;
  }
  puVar4 = puVar3 + 2;
  puVar3[1] = 0;
  os_frame_push_args_a1d8();
  os_insert_delay_queue();
  uVar6 = os_pop3_return_a2e4();
  puVar3 = puVar4 + -1;
  *puVar4 = *puVar4;
  *puVar1 = uVar6;
  puVar2 = puVar1;
LAB_CODE_00a158:
  uVar6 = *puVar2;
  *puVar3 = *puVar3;
  puVar3[-1] = puVar3[-1];
  os_c18_epilogue_a180(uVar6);
  return;
}


// ===== 0x00a160 os_frame_load_ptr_arg_a160 =====

/* Auto: Load pointer argument from stack frame into FSR0; 5 instr */

undefined1 os_frame_load_ptr_arg_a160(void)

{
  return 0xfd;
}


// ===== 0x00a16e os_c18_prologue_a16e =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void os_c18_prologue_a16e(void)

{
  return;
}


// ===== 0x00a180 os_c18_epilogue_a180 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void os_c18_epilogue_a180(void)

{
  return;
}


// ===== 0x00a18c OSRestoreInts =====

/* Salvo helper: restore saved GIE/PEIE state */

byte OSRestoreInts(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  bVar1 = *(byte *)CONCAT11((char)((ushort)in_FSR1 >> 8) + '\x01',0xff);
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}


// ===== 0x00a19c os_frame_load_ptr_arg_a19c =====

/* Auto: Load pointer argument from stack frame into FSR0; 5 instr */

undefined1 os_frame_load_ptr_arg_a19c(void)

{
  return 0xfb;
}


// ===== 0x00a1aa OSDisableInts =====

/* Salvo helper: save and clear GIE/PEIE */

undefined1 OSDisableInts(void)

{
  undefined1 uVar1;
  byte bVar2;
  
  uVar1 = INTCON;
  bVar2 = INTCON;
  INTCON = bVar2 & ~(PEIE | GIE);
  return 0x3f;
}


// ===== 0x00a1ba os_ptr_add_a1ba =====

/* Auto: compiler fragment: RCALL 0x00a302 ; RCALL 0x00a2a4 ; RCALL 0x00a272 ; ADDWF FSR0L,f,ACCESS
   ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ; GOTO 0x00a2fc */

void os_ptr_add_a1ba(void)

{
  os_frag_a302();
  os_frame_access_a2a4();
  os_copy_ptr_field_a272();
  os_chain_fna27c_fna26a_a2fc(0);
  return;
}


// ===== 0x00a1ca os_const_then_a2dc_a1ca =====

/* Auto: compiler fragment: MOVLW #0x5 ; BRA 0x00a2dc */

void os_const_then_a2dc_a1ca(void)

{
  os_ptr_add_a2dc(5);
  return;
}


// ===== 0x00a1ce os_get_os_tmp_tcb_ptr_a1ce =====

/* Auto: reads os_tmp_tcb_ptr,os_tmp_tcb_ptr_hi; 3 instr */

void os_get_os_tmp_tcb_ptr_a1ce(void)

{
  return;
}


// ===== 0x00a1d8 os_frame_push_args_a1d8 =====

/* Auto: Copy stack-frame arguments onto the stack for a call; 5 instr */

undefined1 os_frame_push_args_a1d8(void)

{
  return 0xfd;
}


// ===== 0x00a1e6 os_to_OSInsPrioQ_a1e6 =====

/* Auto: calls OSInsPrioQ; 4 instr */

void os_to_OSInsPrioQ_a1e6(void)

{
  BADSPACEBASE *in_FSR1;
  
  OSInsPrioQ();
  os_pop3_return_a2e4();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x00a1ee os_const_then_a2dc_a1ee =====

/* Auto: compiler fragment: MOVLW #0x3 ; BRA 0x00a2dc */

void os_const_then_a2dc_a1ee(void)

{
  os_ptr_add_a2dc(3);
  return;
}


// ===== 0x00a1f2 os_frame_access_a1f2 =====

/* Auto: Access stack-frame local/argument; 6 instr */

undefined1 os_frame_access_a1f2(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = os_tcb_get_state_a2c6();
  *(undefined1 *)in_FSR1 = uVar1;
  *(undefined1 *)((short)in_FSR2 + 2) = *(undefined1 *)in_FSR1;
  return *(undefined1 *)((short)in_FSR2 + 3);
}


// ===== 0x00a200 os_frame_access_a200 =====

/* Auto: Access stack-frame local/argument; 5 instr */

undefined1 os_frame_access_a200(void)

{
  return 0xfd;
}


// ===== 0x00a20e os_ptr_add_a20e =====

/* Auto: compiler fragment: MOVWF FSR0L,ACCESS ; MOVLW #0x0 ; ADDWFC FSR2H,w,ACCESS ; MOVWF
   FSR0H,ACCESS ; MOVF POSTINC0,w,ACCESS ; IORWF POSTDEC0,w,ACCESS ; RETURN 0x0 */

byte os_ptr_add_a20e(undefined1 param_1)

{
  char in_FSR2H;
  byte *pbVar1;
  byte unaff_C;
  
  pbVar1 = (byte *)CONCAT11(in_FSR2H + (unaff_C & 1),param_1);
  return pbVar1[1] | *pbVar1;
}


// ===== 0x00a21c os_const_then_a2dc_a21c =====

/* Auto: compiler fragment: MOVLW #0x2 ; BRA 0x00a2dc */

void os_const_then_a2dc_a21c(void)

{
  os_ptr_add_a2dc(2);
  return;
}


// ===== 0x00a220 os_stack_adjust_a220 =====

/* Auto: Software stack push/pop helper; 9 instr */

undefined1 os_stack_adjust_a220(void)

{
  return 0;
}


// ===== 0x00a232 os_get_c18_tmp0_a232 =====

/* Auto: reads c18_tmp0,c18_tmp1; 7 instr */

byte os_get_c18_tmp0_a232(void)

{
  byte in_FramePointer2_0000fffb;
  undefined1 in_FramePointer2_0000fffd;
  
  c18_tmp0 = in_FramePointer2_0000fffb;
  c18_tmp1 = in_FramePointer2_0000fffd;
  return in_FramePointer2_0000fffb ^ 0xae;
}


// ===== 0x00a244 os_frame_push_args_a244 =====

/* Auto: Copy stack-frame arguments onto the stack for a call; 5 instr */

undefined1 os_frame_push_args_a244(void)

{
  return 0xfb;
}


// ===== 0x00a252 os_frame_load_ptr_arg_a252 =====

/* Auto: Load pointer argument from stack frame into FSR0; 5 instr */

undefined1 os_frame_load_ptr_arg_a252(void)

{
  return 3;
}


// ===== 0x00a260 os_frag_a260 =====

/* Auto: compiler fragment: MOVLW #0x8f ; ANDWF INDF0,w,ACCESS ; IORLW #0x10 ; MOVWF INDF0,ACCESS ;
   RETURN 0x0 */

byte os_frag_a260(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 & 0x8f | 0x10;
}


// ===== 0x00a26a os_frag_a26a =====

/* Auto: compiler fragment: RCALL 0x00a302 ; MOVF POSTINC0,w,ACCESS ; IORWF POSTDEC0,w,ACCESS ;
   RETURN 0x0 */

byte os_frag_a26a(void)

{
  BADSPACEBASE *in_FSR0;
  
  os_frag_a302();
  return *(byte *)((short)in_FSR0 + 1) | *(byte *)in_FSR0;
}


// ===== 0x00a272 os_copy_ptr_field_a272 =====

/* Auto: compiler fragment: MOVFF POSTINC2,FSR0L ; MOVFF POSTDEC2,FSR0H ; RETURN 0x0 */

void os_copy_ptr_field_a272(void)

{
  return;
}


// ===== 0x00a27c os_copy_ptr_field_a27c =====

/* Auto: compiler fragment: MOVFF POSTINC0,POSTINC2 ; MOVFF POSTDEC0,POSTDEC2 ; RETURN 0x0 */

void os_copy_ptr_field_a27c(void)

{
  return;
}


// ===== 0x00a286 os_chain_fna160_fna21c_a286 =====

/* Auto: Calls 0xa160, 0xa21c; 2 instr */

void os_chain_fna160_fna21c_a286(void)

{
  os_frame_load_ptr_arg_a160();
  os_const_then_a2dc_a21c();
  return;
}


// ===== 0x00a28c os_stack_adjust_a28c =====

/* Auto: Software stack push/pop helper; 3 instr */

void os_stack_adjust_a28c(void)

{
  BADSPACEBASE *in_FSR1;
  
  os_c18_prologue_a16e();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x00a292 os_frag_a292 =====

/* Auto: compiler fragment: RCALL 0x00a1ca ; MOVLW #0x4 ; RETURN 0x0 */

undefined1 os_frag_a292(void)

{
  os_const_then_a2dc_a1ca();
  return 4;
}


// ===== 0x00a298 os_copy_ptr_field_a298 =====

/* Auto: compiler fragment: RCALL 0x00a1ee ; MOVFF POSTINC2,POSTINC0 ; MOVFF POSTDEC2,POSTDEC0 ;
   RETURN 0x0 */

void os_copy_ptr_field_a298(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  os_const_then_a2dc_a1ee();
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR2;
  *(undefined1 *)((short)in_FSR0 + 1) = *(undefined1 *)((short)in_FSR2 + 1);
  return;
}


// ===== 0x00a2a4 os_frame_access_a2a4 =====

/* Auto: Access stack-frame local/argument; 5 instr */

undefined1 os_frame_access_a2a4(void)

{
  return 3;
}


// ===== 0x00a2b2 os_to_OSDisableInts_a2b2 =====

/* Auto: calls OSDisableInts; 3 instr */

void os_to_OSDisableInts_a2b2(void)

{
  os_c18_prologue_a16e();
  OSDisableInts();
  os_frame_load_ptr_arg_a160();
  return;
}


// ===== 0x00a2ba os_get_os_tmp_tcb_ptr_a2ba =====

/* Auto: reads os_tmp_tcb_ptr,os_tmp_tcb_ptr_hi; 3 instr */

void os_get_os_tmp_tcb_ptr_a2ba(void)

{
  os_to_OSInsPrioQ_a1e6();
  return;
}


// ===== 0x00a2c6 os_tcb_get_state_a2c6 =====

/* Auto: compiler fragment: MOVF INDF0,w,ACCESS ; ANDLW #0x70 ; RRNCF WREG,f,ACCESS ; RRNCF
   WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RETURN 0x0 */

byte os_tcb_get_state_a2c6(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0x70) >> 4;
}


// ===== 0x00a2d4 os_to_OSRestoreInts_a2d4 =====

/* Auto: calls OSRestoreInts; 4 instr */

undefined1 os_to_OSRestoreInts_a2d4(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  OSRestoreInts();
  uVar1 = *(undefined1 *)in_FSR2;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return uVar1;
}


// ===== 0x00a2dc os_ptr_add_a2dc =====

/* Auto: compiler fragment: ADDWF FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ; RETURN 0x0
    */

undefined1 os_ptr_add_a2dc(void)

{
  return 0;
}


// ===== 0x00a2e4 os_pop3_return_a2e4 =====

/* Auto: Drop stack arguments and return; 4 instr */

void os_pop3_return_a2e4(void)

{
  return;
}


// ===== 0x00a2ec os_chain_fna272_fna292_a2ec =====

/* Auto: Calls 0xa272, 0xa292; 2 instr */

void os_chain_fna272_fna292_a2ec(void)

{
  os_copy_ptr_field_a272();
  os_frag_a292();
  return;
}


// ===== 0x00a2f2 os_frame_access_a2f2 =====

/* Auto: Access stack-frame local/argument; 4 instr */

void os_frame_access_a2f2(void)

{
  BADSPACEBASE *in_FSR2;
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  os_frame_load_ptr_arg_a160();
  cVar1 = os_frag_a292();
  *(undefined1 *)((short)in_FSR2 + (short)cVar1 + 1) = *(undefined1 *)in_FSR0;
  return;
}


// ===== 0x00a2fc os_chain_fna27c_fna26a_a2fc =====

/* Auto: Calls 0xa27c, 0xa26a; 2 instr */

void os_chain_fna27c_fna26a_a2fc(void)

{
  os_copy_ptr_field_a27c();
  os_frag_a26a();
  return;
}


// ===== 0x00a302 os_frag_a302 =====

/* Auto: compiler fragment: MOVFF FSR2L,FSR0L ; MOVFF FSR2H,FSR0H ; RETURN 0x0 */

void os_frag_a302(void)

{
  return;
}


// ===== 0x00a30c mod_to_OSDisableInts_a30c =====

/* Auto: calls OSDisableInts; 2 instr */

void mod_to_OSDisableInts_a30c(void)

{
  os_stack_adjust_a28c();
  OSDisableInts();
  return;
}


// ===== 0x00a312 clock_draw =====

/* Draw the clock (big digits or text style per SYSTEMCONFIG3 bit7) */

char clock_draw(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  char cVar9;
  undefined1 uVar10;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  mod_to_lcd_draw_glyph_a956();
  clock_display_on = 1;
  cVar8 = ui_draw_home_info();
  if (cVar8 == '\0') {
    cVar8 = replacement_days_left();
    if (cVar8 == '\0') {
      clock_display_blocked = '\0';
      goto LAB_CODE_00a330;
    }
  }
  clock_display_blocked = '\x01';
LAB_CODE_00a330:
  if ((cfg_systemconfig3 & 0x80) == 0) {
    lcd_draw_big_glyph();
    cVar8 = clock_display_blocked;
    if (clock_display_blocked == '\0') {
      cVar8 = clock_draw_text_style(0);
      return cVar8;
    }
  }
  else {
    text_row = 2;
    *(byte *)in_FSR1 = (cfg_systemconfig2 & 0x38) >> 3;
    pbVar2 = (byte *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = clock_day;
    word_lookup_a();
    *pbVar2 = *pbVar2;
    puVar3 = pbVar2 + -2;
    pbVar2[-1] = pbVar2[-1];
    mod_get_c18_tmp0_aa44();
    *puVar3 = in_PRODL;
    puVar3[1] = in_PRODH;
    puVar3[2] = 6;
    puVar3[3] = 0;
    puVar4 = puVar3 + 5;
    puVar3[4] = 0x7e;
    c18_tmp2 = txt_set_ui_hold_counter_98fc();
    bVar1 = (byte)puVar4;
    if (bVar1 < 5) {
      puVar5 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar5;
    }
    puVar6 = (undefined1 *)CONCAT11((char)((ushort)puVar4 >> 8),bVar1 - 5);
    local0 = 0;
    while( true ) {
      cVar8 = local0 - 2;
      if (1 < local0) break;
      puVar7 = puVar6 + 1;
      *puVar6 = 0x20;
      mod_frag_a982(3);
      cVar9 = mod_get_clock_pm_a99c();
      if (cVar8 == '\0') {
LAB_CODE_00a3b4:
        mod_get_clock_hour_a9d4(cVar9);
        puVar6 = puVar7;
      }
      else {
        cVar9 = '\v' - clock_hour;
        if (clock_hour < 0xc) goto LAB_CODE_00a3b4;
        cVar8 = clock_pm + -1;
        if (cVar8 == '\0') {
          cVar8 = clock_hour - 0xc;
          cVar9 = '\0';
          if (cVar8 == '\0') goto LAB_CODE_00a3b4;
        }
        mod_to_mod_get_clock_hour_a91a(cVar8);
        puVar6 = puVar7;
      }
      mod_div_helper_a988();
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local2);
      }
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local3);
      }
      local1 = 0;
      while( true ) {
        if (5 < local1) break;
        if (clock_colon_blink == '\0') {
          uVar10 = 0;
        }
        else {
          uVar10 = mod_to_mod_get_c18_tmp0_a92e(clock_colon_blink);
        }
        mod_callw_lcd_write_data_a9f6(uVar10);
      }
      mod_get_clock_minute_a9b2(local1 - 6);
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local2);
      }
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local3);
      }
      local0 = local0 + 1;
    }
  }
  return cVar8;
}


// ===== 0x00a414 draw_temperature_screen =====

/* Draw temperatures (converted to Fahrenheit unless SYSTEMCONFIG3 bit2) */

void draw_temperature_screen(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  BADSPACEBASE *in_FSR1;
  char *pcVar9;
  char *pcVar10;
  undefined1 *puVar11;
  char *pcVar12;
  char *pcVar13;
  undefined1 uVar14;
  short sVar15;
  
  mod_c18_prologue_a8c8();
  if ((cfg_systemconfig3 & 4) == 0) {
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
    sVar15 = (ushort)*(byte *)((short)in_FSR2 + -2) * 9;
    mod_get_c18_tmp0_aa44();
    math_barg_lo = 5;
    math_barg_hi = 0;
    math_aarg_lo = (byte)sVar15;
    math_aarg_hi = (char)((ushort)sVar15 >> 8);
    __divs16();
    c18_tmp0 = math_aarg_lo + 0x20;
    c18_tmp1 = math_aarg_hi + (0xdf < math_aarg_lo);
    in_FSR2 = (BADSPACEBASE *)(puVar2 + 1);
    puVar2[-2] = c18_tmp0;
  }
  mod_frag_aa4e();
  puVar3 = (undefined1 *)((short)in_FSR2 + 1);
  math_aarg_hi = *(undefined1 *)((short)in_FSR2 + -2);
  mod_div_helper_a90e();
  puVar4 = puVar3 + 1;
  math_aarg_hi = puVar3[-2];
  mod_div_helper_a988();
  for (local0 = 0; local0 < 2; local0 = local0 + 1) {
    pcVar9 = (char *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = puVar4[-3];
    puVar5 = puVar4 + 2;
    mod_frag_a982(puVar4[-3]);
    puVar4 = puVar5 + 1;
    puVar6 = puVar5 + 1;
    if ((byte)puVar5[-2] < 100) {
      mod_to_mod_set_lcd_delay_counter_a9a4(0xe);
      in_FSR1 = (BADSPACEBASE *)pcVar9;
    }
    else {
      mod_frag_aa4e(puVar5[-2] + 0x9c);
      math_aarg_hi = local2;
      mod_shift_multibyte_fc24();
      local2 = math_rem_hi;
      local1 = 0;
      puVar4 = puVar6;
      while (in_FSR1 = (BADSPACEBASE *)pcVar9, local1 < 0xe) {
        c18_tmp4 = 100;
        math_barg_hi = 100;
        puVar7 = puVar4 + 1;
        math_aarg_hi = puVar4[-2];
        mod_shift_multibyte_fc24();
        mod_get_c18_tmp2_a892(math_aarg_hi);
        puVar4 = puVar7;
      }
    }
    local1 = 0;
    while (local1 < 0xe) {
      mod_get_c18_tmp2_a892(local2);
    }
    local1 = 0;
    while (local1 < 0xe) {
      mod_get_c18_tmp2_a892(local3);
    }
  }
  *(char *)in_FSR1 = puVar4[-3] + ',';
  pcVar10 = (char *)((short)in_FSR1 + 2);
  puVar8 = puVar4 + 2;
  *(undefined1 *)((short)in_FSR1 + 1) = puVar4[-3];
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *pcVar10 = *pcVar10;
  pcVar10[-1] = pcVar10[-1];
  pcVar10[-2] = 0xe0;
  pcVar10[-1] = 0x58;
  lcd_puts_rom();
  *pcVar10 = *pcVar10;
  puVar11 = pcVar10 + -2;
  cVar1 = pcVar10[-1];
  pcVar10[-1] = cVar1;
  mod_to_mod_set_lcd_delay_counter_a9a4(2);
  pcVar12 = puVar11 + 1;
  *puVar11 = 4;
  mod_get_cfg_systemconfig3_aa02(0xfc);
  if (cVar1 == '\0') {
    uVar14 = 0xcc;
  }
  else {
    uVar14 = 0xc;
  }
  mod_callw_mod_set_lcd_delay_counter_a940(uVar14);
  pcVar13 = pcVar12 + 1;
  *pcVar12 = puVar8[-3] + '4';
  cVar1 = puVar8[-3];
  mod_callw_fncfc6_a9c2(cVar1 + '\x01');
  *pcVar13 = 4;
  mod_get_cfg_systemconfig3_aa02(0xf);
  if (cVar1 + '\x01' == '\0') {
    uVar14 = 0;
  }
  else {
    uVar14 = 0xc;
  }
  mod_callw_mod_set_lcd_delay_counter_a940(uVar14);
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a530 clock_display_off =====

/* Stop showing the clock */

void clock_display_off(void)

{
  clock_display_on = 0;
  mod_to_lcd_draw_glyph_a956();
  return;
}


// ===== 0x00a538 clock_blink_update =====

/* Toggle colon blink and redraw clock */

char clock_blink_update(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  char cVar4;
  
  clock_colon_blink = clock_colon_blink == '\0';
  if (clock_display_on == '\0') {
    return '\0';
  }
  if ((cfg_systemconfig3 & 0x80) == 0) {
    cVar4 = clock_display_blocked;
    if (clock_display_blocked == '\0') {
      cVar4 = mod_get_clock_colon_blink_a880(0);
    }
  }
  else {
    puVar1 = (undefined1 *)in_FSR1;
    for (local0 = 0; cVar4 = local0 - 2, local0 < 2; local0 = local0 + 1) {
      puVar2 = puVar1 + 1;
      *puVar1 = 0x3c;
      mod_frag_a982(3);
      local1 = 0;
      while (local1 < 6) {
        if (clock_colon_blink == '\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = mod_to_mod_get_c18_tmp0_a92e(clock_colon_blink);
        }
        mod_callw_lcd_write_data_a9f6(uVar3);
      }
      puVar1 = puVar2;
    }
  }
  return cVar4;
}


// ===== 0x00a588 clock_minute_tick =====

/* Per minute: advance clock, daily counters, check wake-up timers 1 and 2 */

char clock_minute_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  
  if (clock_minute < 0x3b) {
    clock_minute = clock_minute + 1;
  }
  else {
    clock_minute = '\0';
    cVar5 = clock_hour - 0x17;
    if (clock_hour < 0x17) {
      bVar4 = clock_hour + 1;
      clock_hour = bVar4;
    }
    else {
      clock_hour = 0;
      if (clock_day < 6) {
        clock_day = clock_day + 1;
      }
      else {
        clock_day = 0;
      }
      if ((cfg_systemconfig & 8) != 0) {
        puVar1 = &FramePointer10x0001;
        stat_counter_inc();
        *puVar1 = *puVar1;
        puVar1[-1] = 0xd;
        stat_counter_save();
        in_FSR1 = (BADSPACEBASE *)(puVar1 + -1);
        *puVar1 = *puVar1;
      }
      pbVar2 = (byte *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0xe;
      stat_counter_inc();
      *pbVar2 = *pbVar2;
      pbVar2[-1] = 0xe;
      cVar5 = stat_counter_save();
      bVar4 = *pbVar2;
      *pbVar2 = bVar4;
    }
    mod_get_clock_pm_a99c(cVar5);
    if (bVar4 != 0) {
      if (clock_hour < 0xc) {
        clock_pm = 0;
      }
      else {
        clock_pm = 1;
      }
    }
  }
  if (clock_display_on != '\0') {
    if ((cfg_systemconfig3 & 0x80) == 0) {
      if (clock_display_blocked == '\0') {
        clock_draw_text_style(0);
      }
    }
    else {
      clock_draw(clock_display_on);
    }
  }
  cVar3 = system_get_mode();
  cVar5 = '\0';
  if (cVar3 != '\0') {
    if ((((cfg_systemconfig3 & 0x10) != 0) &&
        (bVar4 = mod_to_eeprom_read_raw_a94c(0x36), clock_hour == bVar4)) &&
       (cVar5 = mod_to_eeprom_read_raw_a94c(0x37), clock_minute == cVar5)) {
      system_wake(0);
      cVar5 = ui_to_heating_start_task_3470();
      return cVar5;
    }
    cVar5 = '\0';
    if ((cfg_systemconfig3 & 0x20) != 0) {
      cVar5 = mod_to_eeprom_read_raw_a94c(0x38);
      cVar5 = clock_hour - cVar5;
      if (cVar5 == '\0') {
        cVar5 = mod_to_eeprom_read_raw_a94c(0x39);
        cVar5 = clock_minute - cVar5;
        if (cVar5 == '\0') {
          system_wake(0);
          cVar5 = ui_to_heating_start_task_3470();
        }
      }
    }
  }
  return cVar5;
}


// ===== 0x00a656 clock_get_day =====

/* Return day of week */

undefined1 clock_get_day(void)

{
  return clock_day;
}


// ===== 0x00a65c clock_set_day =====

/* Set day of week */

void clock_set_day(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_a8c8();
  clock_day = *(undefined1 *)((short)in_FSR2 + -2);
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a666 clock_copy_to_edit =====

/* Copy current time into the edit buffer */

void clock_copy_to_edit(void)

{
  clock_edit_day = clock_day;
  clock_edit_hour = clock_hour;
  clock_edit_minute = clock_minute;
  clock_edit_ampm = clock_pm;
  return;
}


// ===== 0x00a678 clock_edit_load_wake1 =====

/* Load wake-up time 1 (WKUPHOUR1/WKUPMINUTE1) into edit buffer */

void clock_edit_load_wake1(void)

{
  byte unaff_BSR;
  byte unaff_Z;
  byte unaff_C;
  
  mod_set_clock_edit_hour_aa20(0x36);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xed) = 0;
    unaff_Z = 1;
  }
  mod_set_clock_edit_minute_aa2c(0x37);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xee) = 0;
    unaff_Z = 1;
  }
  mod_get_clock_pm_a99c();
  if ((unaff_Z & 1) == 0) {
    if (clock_edit_hour < 0xc) {
      clock_edit_ampm = 0;
    }
    else {
      clock_edit_ampm = 1;
    }
  }
  else {
    clock_edit_ampm = 2;
  }
  return;
}


// ===== 0x00a6a4 clock_edit_load_wake2 =====

/* Load wake-up time 2 (WKUPHOUR2/WKUPMINUTE2) into edit buffer */

void clock_edit_load_wake2(void)

{
  byte unaff_BSR;
  byte unaff_Z;
  byte unaff_C;
  
  mod_set_clock_edit_hour_aa20(0x38);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xed) = 0;
    unaff_Z = 1;
  }
  mod_set_clock_edit_minute_aa2c(0x39);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xee) = 0;
    unaff_Z = 1;
  }
  mod_get_clock_pm_a99c();
  if ((unaff_Z & 1) == 0) {
    if (clock_edit_hour < 0xc) {
      clock_edit_ampm = 0;
    }
    else {
      clock_edit_ampm = 1;
    }
  }
  else {
    clock_edit_ampm = 2;
  }
  return;
}


// ===== 0x00a6d0 clock_edit_hour12 =====

/* Edit buffer hour in 12-hour format */

byte clock_edit_hour12(void)

{
  if ((clock_edit_ampm == '\x02') || (clock_edit_hour < 0xc)) {
    return clock_edit_hour;
  }
  if ((clock_edit_ampm == '\x01') && (clock_edit_hour == 0xc)) {
    return 0xc;
  }
  return clock_edit_hour - 0xc;
}


// ===== 0x00a6f2 mod_get_clock_edit_hour_a6f2 =====

/* Auto: reads clock_edit_hour; 3 instr */

undefined1 mod_get_clock_edit_hour_a6f2(void)

{
  return clock_edit_hour;
}


// ===== 0x00a6f8 mod_get_clock_edit_hour_a6f8 =====

/* Auto: reads clock_edit_hour; 2 instr */

void mod_get_clock_edit_hour_a6f8(void)

{
  clock_hour = clock_edit_hour;
  return;
}


// ===== 0x00a6fe mod_set_clock_edit_ampm_a6fe =====

/* Auto: writes clock_edit_ampm; reads clock_edit_ampm,clock_edit_hour; 13 instr */

bool mod_set_clock_edit_ampm_a6fe(void)

{
  if (clock_edit_ampm == '\x02') {
    return false;
  }
  clock_edit_ampm = 0xb < clock_edit_hour;
  return 0xb < clock_edit_hour;
}


// ===== 0x00a718 mod_set_clock_edit_hour_a718 =====

/* Auto: writes clock_edit_hour; reads clock_edit_hour; 12 instr */

void mod_set_clock_edit_hour_a718(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_a8c8();
  clock_edit_hour = clock_edit_hour + '\x01';
  if (clock_edit_hour == '\x18') {
    clock_edit_hour = '\0';
  }
  if (*(char *)((short)in_FSR2 + -2) != '\0') {
    mod_set_clock_edit_ampm_a6fe(*(char *)((short)in_FSR2 + -2));
  }
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a730 mod_set_clock_edit_hour_a730 =====

/* Auto: writes clock_edit_hour; reads clock_edit_hour; 13 instr */

void mod_set_clock_edit_hour_a730(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_a8c8();
  clock_edit_hour = clock_edit_hour + -1;
  if (clock_edit_hour == -1) {
    clock_edit_hour = '\x17';
  }
  if (*(char *)((short)in_FSR2 + -2) != '\0') {
    mod_set_clock_edit_ampm_a6fe(*(char *)((short)in_FSR2 + -2));
  }
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a74a mod_get_clock_edit_minute_a74a =====

/* Auto: reads clock_edit_minute; 3 instr */

undefined1 mod_get_clock_edit_minute_a74a(void)

{
  return clock_edit_minute;
}


// ===== 0x00a750 mod_set_clock_edit_minute_a750 =====

/* Auto: writes clock_edit_minute; reads clock_edit_minute; 8 instr */

char mod_set_clock_edit_minute_a750(void)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = clock_edit_minute == '\0';
  cVar1 = clock_edit_minute;
  clock_edit_minute = clock_edit_minute + -1;
  if (bVar2) {
    cVar1 = ';';
    clock_edit_minute = ';';
  }
  return cVar1;
}


// ===== 0x00a760 mod_set_clock_edit_minute_a760 =====

/* Auto: writes clock_edit_minute; reads clock_edit_minute; 7 instr */

char mod_set_clock_edit_minute_a760(void)

{
  char cVar1;
  
  cVar1 = clock_edit_minute + -0x3b;
  clock_edit_minute = clock_edit_minute + '\x01';
  if (cVar1 == '\0') {
    clock_edit_minute = '\0';
  }
  return cVar1;
}


// ===== 0x00a76e mod_get_clock_edit_minute_a76e =====

/* Auto: reads clock_edit_minute; 2 instr */

void mod_get_clock_edit_minute_a76e(void)

{
  clock_minute = clock_edit_minute;
  return;
}


// ===== 0x00a774 mod_get_clock_edit_ampm_a774 =====

/* Auto: reads clock_edit_ampm; 3 instr */

undefined1 mod_get_clock_edit_ampm_a774(void)

{
  return clock_edit_ampm;
}


// ===== 0x00a77a mod_get_clock_edit_ampm_a77a =====

/* Auto: reads clock_edit_ampm; 2 instr */

void mod_get_clock_edit_ampm_a77a(void)

{
  clock_pm = clock_edit_ampm;
  return;
}


// ===== 0x00a780 mod_set_clock_edit_ampm_a780 =====

/* Auto: writes clock_edit_ampm; reads clock_edit_ampm; 7 instr */

char mod_set_clock_edit_ampm_a780(void)

{
  char cVar1;
  
  clock_edit_ampm = clock_edit_ampm + 1;
  cVar1 = '\x02' - clock_edit_ampm;
  if (2 < clock_edit_ampm) {
    clock_edit_ampm = 0;
  }
  return cVar1;
}


// ===== 0x00a78e mod_set_clock_edit_ampm_a78e =====

/* Auto: writes clock_edit_ampm; reads clock_edit_ampm; 8 instr */

char mod_set_clock_edit_ampm_a78e(void)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = clock_edit_ampm == '\0';
  cVar1 = clock_edit_ampm;
  clock_edit_ampm = clock_edit_ampm + -1;
  if (bVar2) {
    cVar1 = '\x02';
    clock_edit_ampm = '\x02';
  }
  return cVar1;
}


// ===== 0x00a79e clock_edit_compute_ampm =====

/* Clock edit: compute AM/PM/24h for edited time */

void clock_edit_compute_ampm(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR0;
  byte unaff_Z;
  
  mod_c18_prologue_a8c8();
  mod_get_clock_pm_a99c();
  if ((unaff_Z & 1) == 0) {
    mod_frame_load_ptr_arg_a8ba();
    c18_tmp0 = *(undefined1 *)in_FSR0;
    mod_frame_load_ptr_arg_a8ba(c18_tmp0);
    c18_tmp1 = *(byte *)in_FSR0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 1);
    *(bool *)in_FSR1 = 0xb < c18_tmp1;
    mod_chain_fna8ba_fna992_a9ce();
    *puVar1 = *puVar1;
    *(undefined1 *)in_FSR0 = puVar1[-1];
    mod_chain_fna8ba_fna992_a9ce();
    if (*(char *)in_FSR0 == '\x01') {
      mod_frame_load_ptr_arg_a8ba(0);
      if (0xc < *(byte *)in_FSR0) {
        mod_compare_multibyte_aa38('\f' - *(byte *)in_FSR0);
      }
    }
  }
  else {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xdd) = 2;
  }
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a7ee mod_get_clock_pm_a7ee =====

/* Auto: reads clock_pm,clock_minute,clock_hour; 25 instr */

void mod_get_clock_pm_a7ee(void)

{
  BADSPACEBASE *in_FSR0;
  byte *pbVar1;
  
  mod_c18_prologue_a8c8();
  mod_chain_fna8ba_fna992_a9ce();
  *(undefined1 *)in_FSR0 = clock_pm;
  mod_frame_load_ptr_arg_a8ba();
  pbVar1 = (byte *)((short)in_FSR0 + 1);
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  *(undefined1 *)((short)in_FSR0 + 1) = clock_minute;
  mod_frame_load_ptr_arg_a8ba();
  *pbVar1 = clock_hour;
  mod_chain_fna8ba_fna992_a9ce();
  if (*pbVar1 != '\x02') {
    mod_frame_load_ptr_arg_a8ba();
    if (0xb < *pbVar1) {
      mod_chain_fna8ba_fna992_a9ce('\v' - *pbVar1);
      if (*pbVar1 == '\x01') {
        mod_frame_load_ptr_arg_a8ba(0);
        if (*pbVar1 == '\f') goto LAB_CODE_00a824;
      }
      mod_compare_multibyte_aa38();
    }
  }
LAB_CODE_00a824:
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a826 clock_draw_text_style =====

/* Draw clock in small text style */

void clock_draw_text_style(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  char cVar5;
  
  mod_c18_prologue_a8c8();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  pcVar2 = (char *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = 7;
  text_draw_char();
  pcVar3 = pcVar2 + -1;
  cVar5 = *pcVar2;
  *pcVar2 = cVar5;
  cVar4 = mod_get_clock_pm_a99c();
  if (cVar5 != '\0') {
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xdb);
    cVar4 = '\v' - bVar1;
    if (0xb < bVar1) {
      cVar5 = *(char *)((ushort)unaff_BSR * 0x100 + 0xdd) + -1;
      if (cVar5 == '\0') {
        cVar5 = *(char *)((ushort)unaff_BSR * 0x100 + 0xdb) + -0xc;
        cVar4 = '\0';
        if (cVar5 == '\0') goto LAB_CODE_00a84a;
      }
      mod_to_mod_get_clock_hour_a91a(cVar5);
      goto LAB_CODE_00a850;
    }
  }
LAB_CODE_00a84a:
  mod_get_clock_hour_a9d4(cVar4);
LAB_CODE_00a850:
  mod_div_helper_a988();
  mod_stack_adjust_a8da(0x32);
  mod_to_fmt_byte_a8ea(local2);
  mod_stack_adjust_a8da(0x38);
  mod_to_fmt_byte_a8ea(local3);
  mod_stack_adjust_a974();
  mod_callw_mod_set_lcd_delay_counter_a940(0x6c);
  mod_get_clock_minute_a9b2();
  mod_stack_adjust_a8da(0x41);
  mod_to_fmt_byte_a8ea(local2);
  mod_stack_adjust_a8da(0x47);
  mod_to_fmt_byte_a8ea(local3);
  *pcVar3 = *pcVar3;
  pcVar3[-1] = pcVar3[-1];
  mod_c18_epilogue_a902();
  return;
}


// ===== 0x00a880 mod_get_clock_colon_blink_a880 =====

/* Auto: reads clock_colon_blink; 8 instr */

void mod_get_clock_colon_blink_a880(void)

{
  undefined1 uVar1;
  
  mod_stack_adjust_a974();
  if (clock_colon_blink == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x6c;
  }
  mod_callw_mod_set_lcd_delay_counter_a940(uVar1);
  return;
}


// ===== 0x00a892 mod_get_c18_tmp2_a892 =====

/* Auto: reads c18_tmp2,c18_tmp3; 17 instr */

void mod_get_c18_tmp2_a892(byte param_1)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)param_1 * 0x1c);
  c18_tmp2 = bVar1 + 0x3c;
  c18_tmp3 = (char)((ushort)param_1 * 0x1c >> 8) + -10 + (0xc3 < bVar1);
  bVar1 = (byte)((ushort)local0 * 0xe);
  c18_tmp0 = bVar1 + c18_tmp2;
  c18_tmp1 = (char)((ushort)local0 * 0xe >> 8) + c18_tmp3 + CARRY1(bVar1,c18_tmp2);
  mod_get_TBLPTRL_a9e2();
  mod_callw_lcd_write_data_a9f6();
  return;
}


// ===== 0x00a8ba mod_frame_load_ptr_arg_a8ba =====

/* Auto: Load pointer argument from stack frame into FSR0; 5 instr */

undefined1 mod_frame_load_ptr_arg_a8ba(void)

{
  return 0xfd;
}


// ===== 0x00a8c8 mod_c18_prologue_a8c8 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_a8c8(void)

{
  return;
}


// ===== 0x00a8da mod_stack_adjust_a8da =====

/* Auto: Software stack push/pop helper; 6 instr */

void mod_stack_adjust_a8da(void)

{
  undefined1 in_FSR2L;
  undefined1 in_FSR2H;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_callw_fncfc6_a9c2(7);
  *puVar1 = in_FSR2L;
  puVar1[1] = in_FSR2H;
  return;
}


// ===== 0x00a8ea mod_to_fmt_byte_a8ea =====

/* Auto: calls fmt_byte; 9 instr */

void mod_to_fmt_byte_a8ea(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  fmt_byte();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  puVar2 = puVar1 + -2;
  puVar1[-3] = *(undefined1 *)in_FSR2;
  mod_get_lcd_text_width_ca24();
  *puVar2 = *puVar2;
  return;
}


// ===== 0x00a902 mod_c18_epilogue_a902 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_a902(void)

{
  return;
}


// ===== 0x00a90e mod_div_helper_a90e =====

/* Auto: compiler fragment: CALL 0x00fc24,0x0 ; MOVF 0x0009,w,ACCESS ; MOVWF 0x0026,ACCESS ; GOTO
   0x00aa4e */

void mod_div_helper_a90e(void)

{
  mod_shift_multibyte_fc24();
  local2 = math_aarg_hi;
  mod_frag_aa4e();
  return;
}


// ===== 0x00a91a mod_to_mod_get_clock_hour_a91a =====

/* Auto: Small wrapper around mod_get_clock_hour; 8 instr */

void mod_to_mod_get_clock_hour_a91a(void)

{
  mod_get_clock_hour_aa10(0xc);
  mod_shift_multibyte_fc24();
  local2 = math_aarg_hi;
  mod_get_clock_hour_aa10(0xc);
  return;
}


// ===== 0x00a92e mod_to_mod_get_c18_tmp0_a92e =====

/* Auto: Small wrapper around mod_get_c18_tmp0; 8 instr */

void mod_to_mod_get_c18_tmp0_a92e(void)

{
  bool bVar1;
  
  mod_get_c18_tmp0_aa44(local0);
  bVar1 = 0xab < c18_tmp0;
  c18_tmp0 = c18_tmp0 + 0x54;
  c18_tmp1 = c18_tmp1 + -9 + bVar1;
  mod_get_TBLPTRL_a9e2();
  return;
}


// ===== 0x00a940 mod_callw_mod_set_lcd_delay_counter_a940 =====

/* Auto: Push W as argument and call mod_set_lcd_delay_counter; 5 instr */

void mod_callw_mod_set_lcd_delay_counter_a940(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00a94c mod_to_eeprom_read_raw_a94c =====

/* Auto: calls eeprom_read_raw; 4 instr */

void mod_to_eeprom_read_raw_a94c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00a956 mod_to_lcd_draw_glyph_a956 =====

/* Auto: calls lcd_draw_glyph; 14 instr */

void mod_to_lcd_draw_glyph_a956(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0004;
  lcd_draw_glyph();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  puVar1[-3] = puVar1[-3];
  return;
}


// ===== 0x00a974 mod_stack_adjust_a974 =====

/* Auto: Software stack push/pop helper; 7 instr */

undefined1 mod_stack_adjust_a974(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_callw_fncfc6_a9c2(7);
  *puVar1 = 2;
  return 2;
}


// ===== 0x00a982 mod_frag_a982 =====

/* Auto: compiler fragment: ADDWF 0x0024,w,ACCESS ; GOTO 0x00a9c2 */

void mod_frag_a982(char param_1)

{
  mod_callw_fncfc6_a9c2(local0 + param_1);
  return;
}


// ===== 0x00a988 mod_div_helper_a988 =====

/* Auto: compiler fragment: CALL 0x00fc24,0x0 ; MOVF 0x0005,w,ACCESS ; MOVWF 0x0027,ACCESS ; RETURN
   0x0 */

undefined1 mod_div_helper_a988(void)

{
  mod_shift_multibyte_fc24();
  local3 = math_rem_hi;
  return math_rem_hi;
}


// ===== 0x00a992 mod_ptr_add_a992 =====

/* Auto: compiler fragment: MOVLW #0x2 ; ADDWF FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ;
   RETURN 0x0 */

undefined1 mod_ptr_add_a992(void)

{
  return 0;
}


// ===== 0x00a99c mod_get_clock_pm_a99c =====

/* Auto: reads clock_pm; 4 instr */

char mod_get_clock_pm_a99c(void)

{
  return clock_pm + -2;
}


// ===== 0x00a9a4 mod_to_mod_set_lcd_delay_counter_a9a4 =====

/* Auto: Small wrapper around mod_set_lcd_delay_counter; 6 instr */

void mod_to_mod_set_lcd_delay_counter_a9a4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00a9b2 mod_get_clock_minute_a9b2 =====

/* Auto: reads clock_minute; 5 instr */

void mod_get_clock_minute_a9b2(void)

{
  mod_frag_aa4e();
  math_aarg_hi = clock_minute;
  mod_div_helper_a90e();
  math_aarg_hi = clock_minute;
  mod_div_helper_a988();
  return;
}


// ===== 0x00a9c2 mod_callw_fncfc6_a9c2 =====

/* Auto: Push W as argument and call 0xcfc6; 5 instr */

void mod_callw_fncfc6_a9c2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00a9ce mod_chain_fna8ba_fna992_a9ce =====

/* Auto: Calls 0xa8ba, 0xa992; 2 instr */

void mod_chain_fna8ba_fna992_a9ce(void)

{
  mod_frame_load_ptr_arg_a8ba();
  mod_ptr_add_a992();
  return;
}


// ===== 0x00a9d4 mod_get_clock_hour_a9d4 =====

/* Auto: reads clock_hour; 5 instr */

void mod_get_clock_hour_a9d4(void)

{
  mod_frag_aa4e();
  math_aarg_hi = clock_hour;
  mod_div_helper_a90e();
  math_aarg_hi = clock_hour;
  return;
}


// ===== 0x00a9e2 mod_get_TBLPTRL_a9e2 =====

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 10 instr */

undefined1 mod_get_TBLPTRL_a9e2(void)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,local1),c18_tmp0 + local1));
}


// ===== 0x00a9f6 mod_callw_lcd_write_data_a9f6 =====

/* Auto: Push W as argument and call lcd_write_data; 5 instr */

void mod_callw_lcd_write_data_a9f6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  local1 = local1 + '\x01';
  return;
}


// ===== 0x00aa02 mod_get_cfg_systemconfig3_aa02 =====

/* Auto: reads cfg_systemconfig3; 7 instr */

byte mod_get_cfg_systemconfig3_aa02(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_callw_mod_set_lcd_delay_counter_a940();
  *(undefined1 *)in_FSR1 = 6;
  return cfg_systemconfig3 & 4;
}


// ===== 0x00aa10 mod_get_clock_hour_aa10 =====

/* Auto: reads clock_hour,c18_tmp0; 7 instr */

undefined1 mod_get_clock_hour_aa10(char param_1)

{
  byte unaff_BSR;
  
  c18_tmp0 = *(char *)((ushort)unaff_BSR * 0x100 + 0xdb) - param_1;
  c18_tmp1 = 10;
  math_barg_hi = 10;
  math_aarg_hi = c18_tmp0;
  return 10;
}


// ===== 0x00aa20 mod_set_clock_edit_hour_aa20 =====

/* Auto: writes clock_edit_hour; 6 instr */

char mod_set_clock_edit_hour_aa20(void)

{
  clock_edit_hour = mod_to_eeprom_read_raw_a94c();
  return '\x17' - clock_edit_hour;
}


// ===== 0x00aa2c mod_set_clock_edit_minute_aa2c =====

/* Auto: writes clock_edit_minute; 6 instr */

char mod_set_clock_edit_minute_aa2c(void)

{
  clock_edit_minute = mod_to_eeprom_read_raw_a94c();
  return ';' - clock_edit_minute;
}


// ===== 0x00aa38 mod_compare_multibyte_aa38 =====

/* Auto: compiler fragment: MOVLW #0xc ; MOVWF 0x0014,ACCESS ; RCALL 0x00a8ba ; MOVF 0x0014,w,ACCESS
   ; SUBWF INDF0,f,ACCESS ; RETURN 0x0 */

char mod_compare_multibyte_aa38(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  c18_tmp0 = '\f';
  mod_frame_load_ptr_arg_a8ba();
  cVar1 = c18_tmp0;
  *(char *)in_FSR0 = *(char *)in_FSR0 - c18_tmp0;
  return cVar1;
}


// ===== 0x00aa44 mod_get_c18_tmp0_aa44 =====

/* Auto: reads c18_tmp0,c18_tmp1; 3 instr */

void mod_get_c18_tmp0_aa44(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  c18_tmp0 = in_PRODL;
  c18_tmp1 = in_PRODH;
  return;
}


// ===== 0x00aa4e mod_frag_aa4e =====

/* Auto: compiler fragment: MOVLW #0xa ; MOVWF 0x0014,ACCESS ; MOVWF 0x000e,ACCESS ; RETURN 0x0 */

undefined1 mod_frag_aa4e(void)

{
  c18_tmp0 = 10;
  math_barg_hi = 10;
  return 10;
}


// ===== 0x00aa56 task_dispense =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 3 task: sequence cold/hot dispensing valves, inlet refill, hot dispense time limit */

void task_dispense(void)

{
  bool bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte bVar8;
  undefined1 uVar9;
  char cVar10;
  byte bVar11;
  bool bVar12;
  bool bVar13;
  
  do {
    while( true ) {
      bVar8 = dispense_request;
      if (dispense_request == 0) {
        dispense_task_state = 1;
        puVar2 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0;
        dispense_os_delay();
        adc_raw_lo = 0x11;
        bVar8 = OS_Yield();
        in_FSR1 = (BADSPACEBASE *)puVar2;
      }
      bVar8 = system_get_mode(bVar8);
      bVar13 = bVar8 < 3;
      bVar12 = bVar8 == 2;
      if (!bVar12) break;
      dispense_request = 0;
    }
    bVar8 = dispense_request;
    if (((dispense_request & 4) != 0) &&
       (bVar8 = dispense_request & 0xfb, (dispense_active & 1) != 0)) {
      bVar11 = dispense_request & 0x10;
      dispense_request = bVar8;
      if (bVar11 == 0) {
        uVar9 = dispense_close_inlet_after(8);
        if (bVar12) {
LAB_CODE_00aa96:
          ui_set_ui_alarm_index_4894(uVar9);
        }
        else {
          bVar13 = 1 < portion_mode;
          uVar9 = 0;
          if (portion_mode == 2) goto LAB_CODE_00aa96;
        }
        dispense_delay(2);
        adc_raw_lo = 5;
        OS_Yield();
      }
      cold_valve_close();
      uv_start_keep_cycle();
      pcVar3 = (char *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 3;
      stat_counter_save();
      in_FSR1 = (BADSPACEBASE *)(pcVar3 + -1);
      cVar10 = *pcVar3;
      *pcVar3 = cVar10;
      bVar12 = cVar10 == '\0';
      dispense_active = dispense_active & 0xfe;
      bVar8 = dispense_request;
    }
    dispense_request = bVar8;
    bVar8 = dispense_request;
    if (((dispense_request & 8) != 0) &&
       (bVar8 = dispense_request & 0xf7, (dispense_active & 2) != 0)) {
      bVar11 = dispense_request & 0x10;
      dispense_request = bVar8;
      if (bVar11 == 0) {
        uVar9 = dispense_close_inlet_after(0x21);
        if (bVar12) {
LAB_CODE_00aad8:
          ui_set_ui_alarm_index_4894(uVar9);
        }
        else {
          bVar13 = 1 < portion_mode;
          uVar9 = 0;
          if (portion_mode == 2) goto LAB_CODE_00aad8;
        }
        dispense_delay(3);
        adc_raw_lo = 8;
        OS_Yield();
      }
      hot_valve_close();
      puVar4 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 4;
      stat_counter_save();
      in_FSR1 = (BADSPACEBASE *)(puVar4 + -1);
      *puVar4 = *puVar4;
      dispense_active = dispense_active & 0xfd;
      bVar8 = dispense_request;
    }
    dispense_request = bVar8;
    bVar8 = dispense_request & 0xef;
    if (((dispense_request & 1) != 0) &&
       (dispense_request = dispense_request & 0xee, bVar8 = dispense_request,
       (dispense_active & 1) == 0)) {
      if ((dispense_active & 2) != 0) {
        dispense_request = dispense_request | 8;
      }
      cVar10 = uv_is_available();
      if (cVar10 == '\0') {
LAB_CODE_00ab1a:
        bVar11 = 0;
        bVar8 = dispense_request;
        if ((cfg_systemconfig & 8) != 0) goto LAB_CODE_00abac;
      }
      else {
        bVar12 = uv_alarm_code < '\0';
        bVar11 = uv_alarm_code << 1 | bVar13;
        bVar13 = bVar12;
        if (bVar12) goto LAB_CODE_00ab1a;
      }
      uv_start_keep_cycle(bVar11);
      dispense_uv_wait_lo = -0x18;
      dispense_uv_wait_hi = 3;
      while (((uv_status & 1) != 0 && (cVar10 = uv_is_available(uv_status & 1), cVar10 != '\0'))) {
        c18_tmp0 = dispense_uv_wait_lo;
        c18_tmp1 = dispense_uv_wait_hi;
        cVar10 = dispense_uv_wait_lo + -1;
        bVar13 = dispense_uv_wait_hi != ~(dispense_uv_wait_lo != '\0');
        bVar8 = dispense_uv_wait_hi - ~(dispense_uv_wait_lo != '\0');
        bVar12 = dispense_uv_wait_hi == 0;
        bVar1 = dispense_uv_wait_lo == '\0';
        dispense_uv_wait_lo = cVar10;
        dispense_uv_wait_hi = bVar8;
        if (bVar12 && bVar1) break;
        dispense_task_state = 4;
        puVar5 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0;
        dispense_os_delay(1);
        adc_raw_lo = 2;
        OS_Yield();
        in_FSR1 = (BADSPACEBASE *)puVar5;
      }
      if (((uv_status & 1) == 0) ||
         (cVar10 = uv_is_available(uv_status & 1), bVar8 = dispense_request, cVar10 == '\0')) {
        mod_to_dispense_read_param_afe2(7);
        cold_valve_open();
        if ((outputs_shadow & 1) == 0) {
          dispense_delay(5);
          adc_raw_lo = 3;
          OS_Yield();
          inlet_valve_open();
        }
        puVar6 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 3;
        stat_counter_inc();
        in_FSR1 = (BADSPACEBASE *)(puVar6 + -1);
        *puVar6 = *puVar6;
        if ((dispense_active & 2) != 0) {
          dispense_request = dispense_request | 0x10;
        }
        dispense_active = dispense_active | 1;
        bVar8 = dispense_request;
      }
    }
LAB_CODE_00abac:
    do {
      do {
        dispense_request = bVar8;
        if ((dispense_request & 2) == 0) goto LAB_CODE_00abf8;
        dispense_request = dispense_request & 0xfd;
        bVar8 = dispense_request;
      } while ((dispense_active & 2) != 0);
      if ((dispense_active & 1) != 0) {
        dispense_request = dispense_request | 4;
      }
      bVar8 = dispense_request;
    } while (hot_dispense_allowed == '\0');
    mod_to_dispense_read_param_afe2(0x20);
    hot_valve_open();
    if ((outputs_shadow & 1) == 0) {
      dispense_delay(6);
      adc_raw_lo = 6;
      OS_Yield();
      inlet_valve_open();
    }
    puVar7 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 4;
    stat_counter_inc();
    in_FSR1 = (BADSPACEBASE *)(puVar7 + -1);
    *puVar7 = *puVar7;
    hot_dispense_timer = dispense_read_param(0x1f);
    if ((dispense_active & 1) != 0) {
      dispense_request = dispense_request | 0x10;
    }
    dispense_active = dispense_active | 2;
LAB_CODE_00abf8:
    if ((dispense_active & 1) != 0) {
      bVar8 = inlet_valve_fault << 1 | bVar13;
      bVar13 = true;
      if (inlet_valve_fault < '\0') {
LAB_CODE_00ac08:
        dispense_request = dispense_request | 4;
      }
      else {
        bVar13 = cold_valve_fault < '\0';
        bVar8 = cold_valve_fault << 1;
        if (bVar13) goto LAB_CODE_00ac08;
      }
      mod_to_compressor_load_maxon_ea3a(bVar8);
      uv_start_keep_cycle();
    }
    if ((dispense_active & 2) != 0) {
      bVar8 = inlet_valve_fault << 1 | bVar13;
      if ((inlet_valve_fault < '\0') || (bVar8 = hot_valve_fault << 1, hot_valve_fault < '\0')) {
        dispense_request = dispense_request | 8;
      }
      mod_to_heater_load_maxon_e838(bVar8);
      heating_restart_extra_hot_timer();
    }
  } while( true );
}


// ===== 0x00ac34 dispense_init =====

/* Initialise dispensing state */

undefined1 dispense_init(void)

{
  dispense_active = 0;
  dispense_request = 0;
  hot_dispense_allowed = 1;
  hot_dispense_timer = 0;
  dispense_task_state = 0;
  portion_clear();
  return 0;
}


// ===== 0x00ac46 dispense_create_task =====

/* Create task_dispense (TCB 0x74) */

undefined1 dispense_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x00ac70 dispense_cold_request =====

/* Request cold water dispensing */

undefined1 dispense_cold_request(void)

{
  dispense_request = dispense_request & 0xfb | 1;
  return 0;
}


// ===== 0x00ac78 dispense_hot_request =====

/* Request hot water dispensing */

undefined1 dispense_hot_request(void)

{
  dispense_request = dispense_request & 0xf7 | 2;
  return 0;
}


// ===== 0x00ac80 dispense_stop_all =====

/* Request stop of all dispensing and cancel portion */

undefined1 dispense_stop_all(void)

{
  dispense_request = dispense_request & 0xec | 0xc;
  portion_clear();
  ui_set_ui_alarm_index_4894();
  return 0;
}


// ===== 0x00ac92 dispense_stop_all_b =====

/* dispense_stop_all variant */

undefined1 dispense_stop_all_b(void)

{
  dispense_stop_all();
  ui_set_ui_alarm_index_4894();
  return 0;
}


// ===== 0x00ac9a dispense_stop_all_c =====

/* dispense_stop_all variant */

undefined1 dispense_stop_all_c(void)

{
  dispense_stop_all();
  ui_set_ui_alarm_index_4894();
  return 0;
}


// ===== 0x00aca2 dispense_hot_allow =====

/* Allow hot dispensing (hot tank up to temperature) */

undefined1 dispense_hot_allow(void)

{
  hot_dispense_allowed = 1;
  return 1;
}


// ===== 0x00acaa dispense_hot_block =====

/* Block hot dispensing (hot tank too cold) */

void dispense_hot_block(void)

{
  hot_dispense_allowed = 0;
  return;
}


// ===== 0x00acb0 dispense_hot_is_allowed =====

/* Return hot-dispense-allowed flag */

undefined1 dispense_hot_is_allowed(void)

{
  return hot_dispense_allowed;
}


// ===== 0x00acb6 dispense_hot_is_active =====

/* Return hot dispensing active */

byte dispense_hot_is_active(void)

{
  return dispense_active & 2;
}


// ===== 0x00acbe dispense_cold_is_active =====

/* Return cold dispensing active */

byte dispense_cold_is_active(void)

{
  return dispense_active & 1;
}


// ===== 0x00acc6 dispense_100ms_tick =====

/* Every 100 ms: hot dispense time limit and portion countdown */

void dispense_100ms_tick(void)

{
  char cVar1;
  
  cVar1 = hot_dispense_timer;
  if (hot_dispense_timer != '\0') {
    hot_dispense_timer = hot_dispense_timer + -1;
  }
  portion_tick(cVar1);
  return;
}


// ===== 0x00acd2 portion_calc_cold_cup =====

/* Compute cold cup portion time (QTYCOLDWATER) */

void portion_calc_cold_cup(void)

{
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x3e);
  portion_calc_flow();
  mod_to_portion_scale_b04c();
  mod_set_portion_hot_lo_afd2();
  return;
}


// ===== 0x00acde dispense_cold_cup =====

/* Start a measured cold cup */

void dispense_cold_cup(void)

{
  portion_calc_cold_cup();
  portion_start_cold();
  return;
}


// ===== 0x00ace2 portion_calc_mixed =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Compute hot/cold split to reach a target temperature */

undefined1 portion_calc_mixed(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  bool bVar3;
  
  portion_cold_temp = cold_temp_read_ch5();
  bVar2 = hot_temp_read_top();
  portion_hot_temp = bVar2 - 2;
  *(undefined1 *)in_FSR1 = 1;
  if ((portion_cold_temp & 0x80) == 0) {
    bVar3 = *(byte *)in_FSR1 <= portion_cold_temp;
    bVar2 = portion_cold_temp - *(byte *)in_FSR1;
  }
  else {
    bVar3 = *(char *)in_FSR1 < '\0';
    bVar2 = *(char *)in_FSR1 << 1 | 1 < bVar2;
  }
  if (!bVar3) {
    bVar2 = 1;
    portion_cold_temp = 1;
  }
  portion_calc_flow(bVar2);
  bVar2 = portion_cold_temp;
  if ((cfg_systemconfig & 3) != 0) {
    *(byte *)in_FSR1 = portion_cold_temp;
    bVar1 = portion_hot_temp;
    if (((bVar2 ^ portion_target_temp) & 0x80) == 0) {
      bVar3 = *(byte *)in_FSR1 <= portion_target_temp;
    }
    else {
      bVar3 = *(char *)in_FSR1 < '\0';
    }
    if (bVar3) {
      *(byte *)in_FSR1 = portion_hot_temp;
      if (((bVar1 ^ portion_target_temp) & 0x80) == 0) {
        bVar3 = *(byte *)in_FSR1 < 0xfe || portion_target_temp < *(byte *)in_FSR1 + 2;
      }
      else {
        bVar3 = (char)portion_target_temp < '\0';
      }
      if (bVar3) {
        math_barg_lo = portion_hot_temp - portion_cold_temp;
        c18_tmp5 = 0;
        if ((math_barg_lo & 0x80) != 0) {
          c18_tmp5 = 0xff;
        }
        c18_tmp2 = portion_hot_temp - portion_target_temp;
        c18_tmp3 = '\0';
        if ((c18_tmp2 & 0x80) != 0) {
          c18_tmp3 = -1;
        }
        math_aarg_lo = (byte)((ushort)local3 * (ushort)c18_tmp2);
        math_aarg_hi = (char)((ushort)local3 * (ushort)c18_tmp2 >> 8) + local4 * c18_tmp2 +
                       local3 * c18_tmp3;
        math_barg_hi = c18_tmp5;
        c18_tmp0 = math_aarg_lo;
        c18_tmp1 = math_aarg_hi;
        c18_tmp4 = math_barg_lo;
        __divs16();
        c18_tmp0 = math_aarg_lo - 2;
        c18_tmp1 = math_aarg_hi - ~(1 < math_aarg_lo);
        portion_tmp1 = local3 - c18_tmp0;
        portion_tmp1_hi = (local4 - c18_tmp1) - ~(c18_tmp0 <= local3);
        portion_tmp0 = c18_tmp0;
        portion_tmp0_hi = c18_tmp1;
        portion_scale(10);
        portion_cold_lo = math_aarg_lo;
        portion_cold_hi = math_aarg_hi;
        c18_tmp0 = portion_tmp1;
        c18_tmp1 = portion_tmp1_hi;
        portion_scale(10);
        portion_hot_lo = math_aarg_lo;
        portion_hot_hi = math_aarg_hi;
        portion_cold2_lo = portion_cold_lo;
        portion_cold2_hi = portion_cold_hi;
        math_barg_lo = 2;
        math_barg_hi = 0;
        math_aarg_lo = portion_cold_lo;
        math_aarg_hi = portion_cold_hi;
        __divs16();
        portion_cold2_lo = math_aarg_lo;
        portion_cold2_hi = math_aarg_hi;
        bVar3 = math_aarg_lo <= portion_cold_lo;
        portion_cold_lo = portion_cold_lo - math_aarg_lo;
        portion_cold_hi = (portion_cold_hi - math_aarg_hi) - ~bVar3;
        if ((portion_hot_hi & 0x80) != 0 || portion_hot_hi == ~(1 < portion_hot_lo)) {
          portion_hot_lo = 2;
          portion_hot_hi = 0;
        }
        if (portion_cold_hi == 0 && portion_cold_lo == 0) {
          portion_cold_lo = 1;
          portion_cold_hi = 0;
        }
        if (math_aarg_hi == 0 && math_aarg_lo == 0) {
          portion_cold2_lo = 1;
          portion_cold2_hi = 0;
        }
        portion_mode = 1;
        dispense_cold_request();
        return 0;
      }
    }
  }
  portion_mode = 1;
  mod_to_portion_scale_b04c();
  mod_set_portion_hot_lo_afd2();
  dispense_request = dispense_request & 0xfb | 1;
  return 0;
}


// ===== 0x00ae44 portion_tick =====

/* Every 100 ms: run portion phases (cold, hot, second cold) then stop */

char portion_tick(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  
  if (portion_mode == 1) {
    bVar4 = (char)portion_cold_hi < '\0';
    if (((!bVar4) &&
        (bVar3 = ~(portion_cold_lo == '\0'), bVar4 = bVar3 != 0 || portion_cold_hi < -bVar3,
        bVar3 == 0 && portion_cold_hi >= -bVar3)) &&
       (portion_cold_lo != -1 || portion_cold_hi != 0xff)) {
      bVar4 = portion_cold_lo != '\0';
      portion_cold_lo = portion_cold_lo + -1;
      portion_cold_hi = portion_cold_hi - ~bVar4;
      return '\0';
    }
    bVar3 = portion_hot_hi << 1 | bVar4;
    if ((-1 < (char)portion_hot_hi) &&
       (bVar1 = ~(portion_hot_lo == '\0'), bVar3 = -~(portion_hot_lo == '\0') - portion_hot_hi,
       bVar1 == 0 && -bVar1 <= portion_hot_hi)) {
      portion_mode = 3;
      cVar2 = dispense_hot_request();
      return cVar2;
    }
    cVar2 = dispense_stop_all_c(bVar3);
    return cVar2;
  }
  if (portion_mode != 3) {
    cVar2 = portion_mode - 2;
    if (cVar2 != '\0') {
      portion_mode = 0;
      return cVar2;
    }
    bVar3 = portion_cold2_hi << 1 | 1 < portion_mode;
    if ((-1 < (char)portion_cold2_hi) &&
       (bVar1 = ~(portion_cold2_lo == 0), bVar3 = -~(portion_cold2_lo == 0) - portion_cold2_hi,
       bVar1 == 0 && -bVar1 <= portion_cold2_hi)) {
      bVar3 = ~portion_cold2_lo;
      bVar4 = false;
      if (bVar3 == 0) {
        bVar3 = ~portion_cold2_hi;
        bVar4 = bVar3 == 0;
      }
      if (!bVar4) {
        bVar4 = portion_cold2_lo != 0;
        portion_cold2_lo = portion_cold2_lo - 1;
        portion_cold2_hi = portion_cold2_hi - ~bVar4;
        return '\0';
      }
    }
    cVar2 = dispense_stop_all(bVar3);
    return cVar2;
  }
  bVar4 = (char)portion_hot_hi < '\0';
  if (((!bVar4) &&
      (bVar3 = ~(portion_hot_lo == '\0'), bVar4 = bVar3 != 0 || portion_hot_hi < -bVar3,
      bVar3 == 0 && portion_hot_hi >= -bVar3)) && (portion_hot_lo != -1 || portion_hot_hi != 0xff))
  {
    bVar4 = portion_hot_lo != '\0';
    portion_hot_lo = portion_hot_lo + -1;
    portion_hot_hi = portion_hot_hi - ~bVar4;
    return '\0';
  }
  bVar3 = portion_cold2_hi << 1 | bVar4;
  if ((-1 < (char)portion_cold2_hi) &&
     (bVar1 = ~(portion_cold2_lo == 0), bVar3 = -~(portion_cold2_lo == 0) - portion_cold2_hi,
     bVar1 == 0 && -bVar1 <= portion_cold2_hi)) {
    portion_mode = 2;
    cVar2 = dispense_cold_request();
    return cVar2;
  }
  cVar2 = dispense_stop_all_b(bVar3);
  return cVar2;
}


// ===== 0x00aeec dispense_cool_cup =====

/* Start a measured cool (mixed) cup: TNORMALCOOLCUTOUT, QTYCOOLWATER */

void dispense_cool_cup(void)

{
  portion_target_temp = dispense_read_param(0x32);
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x34);
  portion_calc_mixed();
  return;
}


// ===== 0x00aefa dispense_warm_cup =====

/* Start a measured warm (mixed) cup: TNORMALWARMCUTOUT, QTYWARMWATER */

void dispense_warm_cup(void)

{
  portion_target_temp = dispense_read_param(0x33);
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x35);
  portion_calc_mixed();
  return;
}


// ===== 0x00af08 portion_calc_hot_cup =====

/* Compute hot cup portion time (QTYHOTWATER) */

void portion_calc_hot_cup(void)

{
  char cVar1;
  
  cVar1 = mod_to_dispense_read_param_b060(0x42);
  if (local4 == '\0' && cVar1 == '\0') {
    mod_get_cfg_systemconfig5_afe8(0);
    mod_to_dispense_read_param_b060(0x35);
  }
  if (local4 == '\0' && local3 == '\0') {
    mod_get_cfg_systemconfig5_afe8(0);
    mod_to_dispense_read_param_b060(0x34);
  }
  mod_get_local4_b02c();
  portion_calc_flow();
  mod_to_portion_scale_b04c();
  portion_hot_lo = math_aarg_lo;
  portion_hot_hi = math_aarg_hi;
  portion_cold2_lo = 0xff;
  portion_cold2_hi = 0xff;
  return;
}


// ===== 0x00af3e dispense_hot_cup =====

/* Start a measured hot cup (0x80 if not possible) */

undefined1 dispense_hot_cup(void)

{
  portion_calc_hot_cup();
  if (portion_hot_hi == '\0' && portion_hot_lo == '\0') {
    return 0x80;
  }
  portion_mode = 3;
  dispense_request = dispense_request & 0xf7 | 2;
  return 0;
}


// ===== 0x00af54 portion_calc_jug =====

/* Compute jug portion time (QTYJUGWATER) */

void portion_calc_jug(void)

{
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x43);
  portion_calc_flow();
  mod_get_local3_affc();
  portion_scale(100);
  mod_set_portion_hot_lo_afd2();
  return;
}


// ===== 0x00af64 dispense_jug =====

/* Start a measured jug */

void dispense_jug(void)

{
  portion_calc_jug();
  portion_start_cold();
  return;
}


// ===== 0x00af68 portion_calc_flow =====

/* Flow factor from WATERFLOW (x100/60) */

void portion_calc_flow(void)

{
  byte bVar1;
  
  bVar1 = dispense_read_param(0x26);
  math_aarg_lo = (undefined1)((ushort)bVar1 * 100);
  math_aarg_hi = (undefined1)((ushort)bVar1 * 100 >> 8);
  math_barg_lo = 0x3c;
  math_barg_hi = 0;
  portion_flow_lo = math_aarg_lo;
  portion_flow_hi = math_aarg_hi;
  __divs16();
  portion_flow_lo = math_aarg_lo;
  portion_flow_hi = math_aarg_hi;
  return;
}


// ===== 0x00af9e portion_scale =====

/* Multiply/divide helper for portion timing */

void portion_scale(byte param_1)

{
  math_aarg_lo = (undefined1)((ushort)c18_tmp0 * (ushort)param_1);
  math_aarg_hi = c18_tmp1 * param_1 + (char)((ushort)c18_tmp0 * (ushort)param_1 >> 8);
  math_barg_lo = portion_flow_lo;
  math_barg_hi = portion_flow_hi;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  __divs16();
  return;
}


// ===== 0x00afc2 mod_chain_mod_to_dispense_re_mod_get_local4_afc2 =====

/* Auto: Calls mod_to_dispense_read_param, mod_get_local4; 2 instr */

void mod_chain_mod_to_dispense_re_mod_get_local4_afc2(void)

{
  mod_to_dispense_read_param_b060();
  mod_get_local4_b02c();
  return;
}


// ===== 0x00afc8 dispense_delay =====

/* Set dispense task state and delay */

void dispense_delay(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x7c) = param_1;
  dispense_os_delay(local0);
  return;
}


// ===== 0x00afd2 mod_set_portion_hot_lo_afd2 =====

/* Auto: writes portion_hot_lo,portion_hot_hi; reads math_aarg_lo,math_aarg_hi; 6 instr */

void mod_set_portion_hot_lo_afd2(void)

{
  portion_cold_lo = math_aarg_lo;
  portion_cold_hi = math_aarg_hi;
  portion_hot_lo = 0xff;
  portion_hot_hi = 0xff;
  return;
}


// ===== 0x00afe2 mod_to_dispense_read_param_afe2 =====

/* Auto: calls dispense_read_param; 3 instr */

void mod_to_dispense_read_param_afe2(void)

{
  local0 = dispense_read_param();
  return;
}


// ===== 0x00afe8 mod_get_cfg_systemconfig5_afe8 =====

/* Auto: reads cfg_systemconfig5; 10 instr */

char mod_get_cfg_systemconfig5_afe8(void)

{
  return '\x03' - ((cfg_systemconfig5 & 0x60) >> 5);
}


// ===== 0x00affc mod_get_local3_affc =====

/* Auto: reads local3,local4; 3 instr */

void mod_get_local3_affc(void)

{
  c18_tmp0 = local3;
  c18_tmp1 = local4;
  return;
}


// ===== 0x00b006 portion_clear =====

/* Clear portion timers and mode */

void portion_clear(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x80) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x81) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x82) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x83) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x84) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x85) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x7f) = 0;
  return;
}


// ===== 0x00b016 portion_start_cold =====

/* Start portion in cold mode and request cold water */

undefined1 portion_start_cold(void)

{
  portion_mode = 1;
  dispense_request = dispense_request & 0xfb | 1;
  return 0;
}


// ===== 0x00b022 dispense_read_param =====

/* eeprom_read_param wrapper for dispensing module */

void dispense_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00b02c mod_get_local4_b02c =====

/* Auto: reads local4,local3; 8 instr */

char mod_get_local4_b02c(void)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)local3;
  local3 = (char)(uVar1 * 10);
  cVar2 = (char)(uVar1 * 10 >> 8);
  local4 = local4 * '\n' + cVar2;
  return cVar2;
}


// ===== 0x00b040 dispense_os_delay =====

/* OSDelay wrapper for dispensing task */

void dispense_os_delay(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  OSDelay();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00b04c mod_to_portion_scale_b04c =====

/* Auto: calls portion_scale; 3 instr */

void mod_to_portion_scale_b04c(void)

{
  mod_get_local3_affc();
  portion_scale(10);
  return;
}


// ===== 0x00b054 dispense_close_inlet_after =====

/* Wait close delay then close inlet valve */

undefined1 dispense_close_inlet_after(void)

{
  mod_to_dispense_read_param_afe2();
  inlet_valve_close();
  return portion_mode;
}


// ===== 0x00b060 mod_to_dispense_read_param_b060 =====

/* Auto: calls dispense_read_param; 4 instr */

void mod_to_dispense_read_param_b060(void)

{
  local3 = dispense_read_param();
  local4 = 0;
  return;
}


// ===== 0x00b068 outputs_all_off =====

/* Drive all load outputs (valves, heater, compressor, fan...) to off at startup */

void outputs_all_off(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH5;
  bVar1 = PORTG;
  PORTG = bVar1 & ~RG3;
  bVar1 = PORTG;
  PORTG = bVar1 & ~RG0;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH0;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH1;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH2;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH3;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH4;
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF6;
  outputs_shadow = 0;
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF5;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB3;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH6;
  if ((cfg_systemconfig5 & 8) == 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH6;
  }
  else {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH4;
  }
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH7;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB0;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB1;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC0;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC1;
  return;
}


// ===== 0x00b0aa task_tick_10ms =====

/* Priority 1 task: every 10 ms tick; 100 ms and 1 s sub-schedules */

void task_tick_10ms(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_Z;
  
  do {
    while( true ) {
      puVar1 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0x9e;
      os_wait_sem_helper(0);
      if ((unaff_Z & 1) != 0) break;
      OS_Yield();
      in_FSR1 = (BADSPACEBASE *)puVar1;
    }
    ui_10ms_tick();
    tick_div_100ms = tick_div_100ms + '\x01';
    in_FSR1 = (BADSPACEBASE *)puVar1;
    if (tick_div_100ms == '\n') {
      dispense_100ms_tick(0);
      uv_verify_100ms_tick();
      ui_100ms_tick();
      tick_div_100ms = '\0';
      in_FSR1 = (BADSPACEBASE *)puVar1;
    }
    c18_tmp0 = tick_div_1s + 1;
    c18_tmp1 = 0;
    bVar3 = c18_tmp0 ^ 100;
    unaff_Z = bVar3 == 0;
    tick_div_1s = c18_tmp0;
    if ((bool)unaff_Z) {
      *(undefined1 *)in_FSR1 = 0xa2;
      puVar2 = (undefined1 *)((short)in_FSR1 + 2);
      *(undefined1 *)((short)in_FSR1 + 1) = 0;
      bVar3 = OSSignalSem();
      *puVar2 = *puVar2;
      in_FSR1 = (BADSPACEBASE *)(puVar2 + -2);
      puVar2[-1] = puVar2[-1];
      tick_div_1s = 0;
    }
    heater_burst_tick(bVar3);
  } while( true );
}


// ===== 0x00b104 task_second =====

/* Priority 4 task: once-per-second jobs, plus every 10 s and every 60 s jobs */

void task_second(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  byte unaff_Z;
  byte unaff_C;
  bool bVar4;
  
  do {
    do {
      while( true ) {
        pbVar1 = (byte *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0xa2;
        os_wait_sem_helper(0);
        if ((unaff_Z & 1) != 0) break;
        OS_Yield();
        in_FSR1 = (BADSPACEBASE *)pbVar1;
      }
      inlet_valve_count_usage();
      OS_Yield();
      hot_valve_count_usage();
      OS_Yield();
      cold_valve_count_usage();
      OS_Yield();
      uv_count_usage();
      OS_Yield();
      heating_boil_timer_tick();
      OS_Yield();
      cooling_pulldown_tick();
      OS_Yield();
      heater_second_tick();
      OS_Yield();
      compressor_second_tick();
      OS_Yield();
      ui_second_tick();
      OS_Yield();
      uv_second_tick();
      OS_Yield();
      *pbVar1 = 0;
      if ((standby_countdown & 0x80) == 0) {
        bVar2 = *pbVar1;
        bVar4 = bVar2 < 0xfe || standby_countdown < bVar2 + 2;
        bVar2 = (bVar2 - standby_countdown) + 2;
      }
      else {
        bVar4 = (char)standby_countdown < '\0';
        bVar2 = standby_countdown << 1 | unaff_C & 1;
      }
      in_FSR1 = (BADSPACEBASE *)pbVar1;
      if (bVar4) {
        bVar2 = standby_countdown;
        if (standby_countdown == 0) {
          system_enter_standby(0);
          bVar2 = OS_Yield();
          in_FSR1 = (BADSPACEBASE *)pbVar1;
        }
      }
      else {
        standby_countdown = standby_countdown - 1;
      }
      fan_second_tick(bVar2);
      OS_Yield();
      sec_div_10s = sec_div_10s + '\x01';
      if (sec_div_10s == '\n') {
        heating_timers_10s(0);
        OS_Yield();
        compressor_offdelay_10s_tick();
        OS_Yield();
        inlet_valve_timeout_tick();
        cold_valve_timeout_tick();
        hot_valve_timeout_tick();
        OS_Yield();
        ui_10s_tick();
        OS_Yield();
        sec_div_10s = '\0';
      }
      unaff_C = 0x3b < sec_div_60s + 1;
      cVar3 = sec_div_60s - 0x3b;
      unaff_Z = cVar3 == '\0';
      sec_div_60s = sec_div_60s + 1;
    } while (!(bool)unaff_C);
    sec_div_60s = 0;
    clock_minute_tick(cVar3);
    OS_Yield();
    heating_minute_tick();
    OS_Yield();
    compressor_minute_tick();
    OS_Yield();
    heater_maxon_minute_tick();
    OS_Yield();
    uv_minute_tick();
    OS_Yield();
    cooling_idle_minute_tick();
    OS_Yield();
    bVar2 = cfg_application();
    unaff_C = bVar2 < 4;
    if (bVar2 == 3) {
      unaff_Z = 1;
    }
    else {
      cVar3 = cfg_application();
      unaff_Z = cVar3 == '\0';
      if ((!(bool)unaff_Z) && (unaff_Z = (cfg_systemconfig2 & 1) == 0, !(bool)unaff_Z)) {
        if (heater_fault == -0x7c) {
          unaff_C = 1;
          unaff_Z = 1;
        }
        else {
          *(undefined1 *)in_FSR1 = 0;
          if ((cfg_sleep_delay & 0x80) == 0) {
            unaff_C = *(byte *)in_FSR1 < 0xfe || cfg_sleep_delay < *(byte *)in_FSR1 + 2;
          }
          else {
            unaff_C = (char)cfg_sleep_delay < '\0';
          }
          if ((bool)unaff_C == false) {
            unaff_C = sleep_check_period != '\0';
            sleep_check_period = sleep_check_period + -1;
            if (sleep_check_period == '\0') {
              unaff_C = cfg_sleep_delay != 0;
              cfg_sleep_delay = cfg_sleep_delay - 1;
              unaff_Z = cfg_sleep_delay == 0;
              sleep_check_period = '\n';
            }
            else {
              unaff_Z = 0;
            }
          }
          else {
            unaff_Z = cfg_sleep_delay == 0;
            if ((bool)unaff_Z) {
              system_enter_sleep(0);
            }
          }
        }
      }
    }
  } while( true );
}


// ===== 0x00b256 main =====

/* WARNING: Instruction at (CODE,0x00b276) overlaps instruction at (CODE,0x00b274)
    */
/* Hardware init, load SYSTEMCONFIG bytes, create Salvo tasks, run scheduler forever */

void main(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char cVar13;
  byte unaff_C;
  
  main_init_flag = 0;
  tick_div_100ms = 0;
  tick_div_1s = 0;
  sec_div_10s = 0;
  sec_div_60s = 0;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & ~nRBPU;
  cVar13 = '<';
  do {
    cVar13 = cVar13 + -1;
  } while (cVar13 != '\0');
  bVar1 = TRISB;
  TRISB = bVar1 | TRISB5;
  bVar1 = PORTB;
  factory_jumper = (bVar1 & RB5) == 0;
  bVar1 = INTCON2;
  INTCON2 = bVar1 | nRBPU;
  os_set_OScTcbP_9ad4();
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  *(undefined1 *)in_FSR1 = 0;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x9e;
  puVar2 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = 0;
  OSCreateSem();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar2[-2];
  puVar2[-3] = 0;
  puVar2[-2] = 0xa2;
  puVar2[-1] = 0;
  OSCreateSem();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar3 = puVar2 + -3;
  puVar2[-2] = puVar2[-2];
  hw_init_peripherals();
  standby_countdown = 0xff;
  sleep_countdown = 0xff;
  outputs_all_off();
  serial_init();
  params_verify();
  system_mode = 0;
  puVar4 = puVar3 + 1;
  *puVar3 = 0x23;
  cfg_sleep_delay = eeprom_read_param();
  *puVar4 = *puVar4;
  sleep_check_period = 10;
  puVar4[-1] = 0x25;
  cfg_systemconfig = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x2b;
  cfg_systemconfig2 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x2c;
  cfg_systemconfig3 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x3a;
  cfg_systemconfig4 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x41;
  cfg_systemconfig5 = eeprom_read_param();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x45;
  cfg_systemconfig6 = eeprom_read_param();
  puVar5 = puVar4 + -1;
  *puVar4 = *puVar4;
  if (factory_jumper != '\0') {
    cfg_systemconfig = cfg_systemconfig | 0xbf;
    cfg_systemconfig2 = 0x68;
    cfg_systemconfig3 = cfg_systemconfig3 & 0x46 | 0x44;
    cfg_systemconfig4 = 0xe7;
  }
  stats_load(factory_jumper);
  compressor_init();
  heater_init();
  alarm_init();
  inlet_valve_init();
  cold_valve_init();
  hot_valve_init();
  mod_set_r202_0_fca2();
  mod_set_r0ff_0_fc98();
  cooling_init();
  heating_init();
  dispense_init();
  uv_init();
  ui_init();
  fan_init();
  c18_tmp0 = beep_and_halt();
  serial_create_task(c18_tmp0 << 1 | unaff_C & 1);
  cooling_create_task();
  heating_create_task();
  dispense_create_task();
  uv_create_task();
  ui_create_task();
  fan_create_task();
  *puVar5 = 1;
  puVar5[1] = 0x86;
  puVar5[2] = 0;
  puVar5[3] = 0xaa;
  puVar6 = puVar5 + 5;
  puVar5[4] = 0xb0;
  c18_tmp0 = OSCreateTask();
  bVar1 = (byte)puVar6;
  if (bVar1 < 5) {
    puVar7 = (undefined1 *)((ushort)puVar6 & 0xff00);
    puVar6 = puVar7 + -1;
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)puVar6 >> 8),bVar1 - 5);
  *puVar8 = 4;
  puVar8[1] = 0x8c;
  puVar8[2] = 0;
  puVar8[3] = 4;
  puVar9 = puVar8 + 5;
  puVar8[4] = 0xb1;
  c18_tmp0 = OSCreateTask();
  bVar1 = (byte)puVar9;
  if (bVar1 < 5) {
    puVar10 = (undefined1 *)((ushort)puVar9 & 0xff00);
    puVar9 = puVar10 + -1;
    *puVar10 = *puVar10;
  }
  puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar9 >> 8),bVar1 - 5);
  bVar1 = INTCON;
  INTCON = bVar1 | (PEIE | GIE);
  puVar12 = puVar11 + 1;
  *puVar11 = 0x88;
  ui_get_buzzer_pattern_4850();
  *puVar12 = *puVar12;
  do {
    bVar1 = INTCON;
    INTCON = bVar1 | (PEIE | GIE);
    OSSched(0xc0);
  } while( true );
}


// ===== 0x00b480 mod_return_void_b480 =====

/* Auto: Empty function (return); 1 instr */

void mod_return_void_b480(void)

{
  return;
}


// ===== 0x00b482 os_tick =====

/* Called every Timer0 tick: OSTimer + signal tick semaphore (ECB 0x9e) */

void os_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  OSTimer();
  *(undefined1 *)in_FSR1 = 0x9e;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  OSSignalSem();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00b498 mod_to_uart2_rx_isr_b498 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: calls uart2_rx_isr; 1 instr */

char mod_to_uart2_rx_isr_b498(char param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  char cVar4;
  bool bVar5;
  undefined1 *puVar3;
  
  while (bVar1 = PIR3, (bVar1 & RC2IF) != 0) {
    uart2_rx_byte = RCREG2;
    param_1 = '\0';
    if (((uart2_rx_flags & 1) != 0) &&
       ((uart2_rx_count < 0xb || (param_1 = RCREG2 - 0xd, param_1 == '\0')))) {
      do {
        bVar1 = PIR3;
      } while ((bVar1 & TX2IF) == 0);
      TXREG2 = RCREG2;
      if (RCREG2 == 0xd) {
        uart2_rx_flags = uart2_rx_flags & 0xfe;
        serial_push_sem(0);
        param_1 = OSSignalSem();
        puVar2 = (undefined1 *)((short)in_FSR1 + -1);
        puVar3 = (undefined1 *)((short)in_FSR1 + -1);
        *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
        *puVar2 = *puVar3;
      }
      else {
        if (RCREG2 == 0x20) {
          uart2_rx_flags = uart2_rx_flags & 0xfd;
        }
        if ((uart2_rx_flags & 2) != 0) {
          *(byte *)in_FSR1 = uart2_rx_count;
          cVar4 = *(char *)in_FSR1;
          *(char *)in_FSR1 = cVar4;
          bVar1 = RCREG2;
          while (cVar4 != '\0') {
            bVar1 = bVar1 << 1;
            cVar4 = *(char *)in_FSR1 + -1;
            *(char *)in_FSR1 = cVar4;
          }
          serial_cmd_hash = bVar1 ^ serial_cmd_hash;
        }
        bVar5 = 0x93 < uart2_rx_count;
        cVar4 = uart2_rx_count + 0x6c;
        uart2_rx_byte = TXREG2;
        uart2_rx_count = uart2_rx_count + 1;
        *(byte *)CONCAT11(bVar5 + '\x01',cVar4) = TXREG2;
        param_1 = '\x01';
        *(undefined1 *)CONCAT11((0x93 < uart2_rx_count) + '\x01',uart2_rx_count + 0x6c) = 0;
      }
    }
  }
  return param_1;
}


// ===== 0x00b49c isr_low_other =====

/* Low-priority ISR fallback (empty) */

void isr_low_other(void)

{
  return;
}


// ===== 0x00b49e OSIdlingHook =====

/* Salvo idle hook */

void OSIdlingHook(void)

{
  return;
}


// ===== 0x00b4a0 system_get_mode =====

/* Return system mode: 0 normal, 1 sleep, 2 standby/off */

undefined1 system_get_mode(void)

{
  return system_mode;
}


// ===== 0x00b4a6 system_enter_sleep =====

/* Enter sleep mode (mode 1), reload sleep timers */

char system_enter_sleep(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  cVar2 = system_get_mode();
  if (cVar2 != '\0') {
    return cVar2;
  }
  system_mode = 1;
  sleep_check_period = 0x3c;
  cfg_sleep_delay = 0xff;
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x31;
  cVar2 = eeprom_read_raw();
  *puVar1 = *puVar1;
  sleep_countdown = cVar2;
  if (cVar2 == '\0') {
    sleep_countdown = -1;
  }
  cVar2 = ui_set_ui_screen_3496(cVar2);
  return cVar2;
}


// ===== 0x00b4d2 system_wake =====

/* Leave sleep/standby: mode 0, reload sleep delay from EEPROM */

char system_wake(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  puVar1 = &FramePointer10x0001;
  cfg_sleep_delay = eeprom_read_param();
  *puVar1 = *puVar1;
  sleep_check_period = 10;
  sleep_countdown = 0xff;
  cVar2 = system_get_mode();
  if (cVar2 == '\0') {
    return cVar2;
  }
  heating_flags = heating_flags | 0x10;
  system_mode = 0;
  return cVar2;
}


// ===== 0x00b4f8 system_enter_standby =====

/* Enter standby mode (mode 2) */

undefined1 system_enter_standby(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = system_get_mode();
  if (cVar1 == '\x02') {
    return 0;
  }
  cfg_sleep_delay = 0xff;
  sleep_countdown = 0xff;
  standby_countdown = 0xff;
  system_mode = 2;
  uVar2 = ui_set_ui_screen_34a2();
  return uVar2;
}


// ===== 0x00b510 system_request_wake =====

/* Set wake request flag */

undefined1 system_request_wake(void)

{
  standby_countdown = 1;
  return 1;
}


// ===== 0x00b518 mod_to_child_protect_is_active_b518 =====

/* Auto: calls child_protect_is_active; 8 instr */

void mod_to_child_protect_is_active_b518(void)

{
  char cVar1;
  
  cVar1 = child_protect_is_active();
  mod_to_param_write_b62c(cVar1 == '\0');
  child_protect_is_active();
  return;
}


// ===== 0x00b52a mod_to_mod_to_param_write_b52a =====

/* Auto: Small wrapper around mod_to_param_write; 9 instr */

void mod_to_mod_to_param_write_b52a(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_b5e8();
  mod_to_param_write_b62c(*(char *)((short)in_FSR2 + -2) != '\0');
  mod_c18_epilogue_b60a();
  return;
}


// ===== 0x00b53c is_factory_jumper =====

/* Return factory_jumper */

undefined1 is_factory_jumper(void)

{
  return factory_jumper;
}


// ===== 0x00b542 cold_temp_read =====

/* Read cold-tank NTC on given ADC channel (table 0xEA96), filtered */

void cold_temp_read(void)

{
  mod_c18_prologue_b5e8();
  adc_read_to_tmp();
  ntc_table_ptr_lo = 0x96;
  ntc_table_ptr_hi = 0xea;
  temp_filter();
  mod_c18_epilogue_b60a();
  return;
}


// ===== 0x00b554 cold_temp_read_ch5 =====

/* Cold tank sensor on AN5 */

void cold_temp_read_ch5(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  cold_temp_read();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00b55e cold_temp_read_ch4 =====

/* Cold tank sensor on AN4 (AN5 if SYSTEMCONFIG3 bit0 clear) */

void cold_temp_read_ch4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  cold_temp_read();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00b572 hot_temp_read =====

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


// ===== 0x00b592 hot_temp_read_top =====

/* Hot tank top sensor (AN0) */

void hot_temp_read_top(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  hot_temp_read();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00b59a hot_temp_read_bottom =====

/* Hot tank bottom sensor (AN1 if SYSTEMCONFIG bit6, else AN0) */

void hot_temp_read_bottom(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  hot_temp_read();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00b5ae child_protect_is_active =====

/* Return child-protection (hot water lock) state */

void child_protect_is_active(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined1 uVar5;
  
  mod_c18_prologue_b5e8();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  cVar4 = cfg_application();
  if (cVar4 == '\x03') {
LAB_CODE_00b5c0:
    uVar5 = 0;
  }
  else {
    cVar4 = cfg_application();
    if (cVar4 == '\0') goto LAB_CODE_00b5c0;
    uVar5 = 1;
  }
  *(undefined1 *)in_FSR2 = uVar5;
  if (*(char *)in_FSR2 != '\0') {
    puVar2 = puVar1 + 1;
    *puVar1 = 0x28;
    cVar4 = eeprom_read_param();
    puVar1 = puVar2 + -1;
    puVar3 = puVar2 + -1;
    *puVar2 = *puVar2;
    if (cVar4 != '\0') {
      uVar5 = 1;
      goto LAB_CODE_00b5e0;
    }
  }
  uVar5 = 0;
  puVar3 = puVar1;
LAB_CODE_00b5e0:
  *(undefined1 *)in_FSR2 = uVar5;
  uVar5 = *(undefined1 *)in_FSR2;
  *puVar3 = *puVar3;
  mod_c18_epilogue_b60a(uVar5);
  return;
}


// ===== 0x00b5e8 mod_c18_prologue_b5e8 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_b5e8(void)

{
  return;
}


// ===== 0x00b5fa cfg_application =====

/* APPLICATION setting (SYSTEMCONFIG5 bits5-6): 0 COLD ONLY, 1 HOT ONLY, 2 COLD/HOT, 3 COLD/ROOM */

byte cfg_application(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}


// ===== 0x00b60a mod_c18_epilogue_b60a =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_b60a(void)

{
  return;
}


// ===== 0x00b616 adc_read_to_tmp =====

/* adc_read() and store raw result in adc_raw */

void adc_read_to_tmp(void)

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


// ===== 0x00b62c mod_to_param_write_b62c =====

/* Auto: calls param_write; 7 instr */

void mod_to_param_write_b62c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  param_write();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00b63c os_wait_sem_helper =====

/* Wait on a semaphore; returns non-zero if task must yield */

byte os_wait_sem_helper(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  puVar1 = &FramePointer10x0001;
  bVar2 = OSWaitSem();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return bVar2 & 2;
}


// ===== 0x00b64a gfx_bitmap_check =====

/* Graphics: validate bitmap coordinates */

void gfx_bitmap_check(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar4;
  char *pcVar5;
  byte *pbVar6;
  
  mod_c18_prologue_ba28();
  bVar1 = mod_frag_bc1a();
  if (bVar1 < 0x40) {
    bVar1 = mod_get_c18_tmp0_bb80('?' - bVar1);
    if (bVar1 < 0x40) {
      mod_frame_load_ptr_arg_ba1a('?' - bVar1);
      puVar4 = (undefined1 *)((short)in_FSR0 + 1);
      *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
      if (*(byte *)((short)in_FSR0 + 1) < 0x80) {
        mod_frame_load_ptr_arg_ba1a('\x7f' - *(byte *)((short)in_FSR0 + 1));
        pcVar5 = (char *)CONCAT11((char)((ushort)puVar4 >> 8) + (0xfc < (byte)puVar4),
                                  (byte)puVar4 + 3);
        c18_tmp1 = *pcVar5;
        mod_frame_load_ptr_arg_ba1a();
        pbVar6 = (byte *)(pcVar5 + 1);
        *pcVar5 = *pcVar5;
        if ((byte)(c18_tmp1 + pcVar5[1]) < 0x80) {
          mod_ptr_add_bbce('\x7f' - (c18_tmp1 + pcVar5[1]));
          c18_tmp2 = *pbVar6;
          bVar1 = mod_frag_bc1a();
          if (bVar1 <= c18_tmp2) {
            mod_ptr_add_bbce(c18_tmp2 - bVar1);
            c18_tmp3 = *pbVar6;
            mod_frame_load_ptr_arg_ba1a();
            mod_ptr_add_baf2();
            c18_tmp4 = *pbVar6;
            cVar2 = mod_frag_bc1a();
            if (c18_tmp3 < (byte)(c18_tmp4 + cVar2)) {
              uVar3 = 0;
              goto LAB_CODE_00b6a4;
            }
          }
        }
      }
    }
  }
  uVar3 = 0x81;
LAB_CODE_00b6a4:
  mod_c18_epilogue_ba78(uVar3);
  return;
}


// ===== 0x00b6a6 gfx_bitmap_blit =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Graphics: draw bitmap at position */

void gfx_bitmap_blit(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  BADSPACEBASE *in_FSR1;
  byte bVar7;
  undefined1 uVar8;
  char cVar9;
  BADSPACEBASE *in_FSR0;
  byte unaff_C;
  
  mod_c18_prologue_ba28();
  mod_frag_bc1a();
  mod_frag_baa0();
  if ((unaff_C & 1) == 0) {
    mod_frame_load_ptr_arg_ba1a();
    *(undefined1 *)((short)in_FSR2 + -4) = *(undefined1 *)in_FSR0;
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  }
  else {
    mod_get_c18_tmp0_bb80();
    mod_frag_baa0();
    puVar2 = (undefined1 *)in_FSR2;
    if ((unaff_C & 1) != 0) {
      cVar9 = mod_get_c18_tmp0_bb80();
      *(char *)in_FSR1 = cVar9 + -1;
      puVar2 = (undefined1 *)((short)in_FSR2 + 1);
      *(undefined1 *)((short)in_FSR2 + -4) = *(undefined1 *)in_FSR1;
    }
  }
  bVar7 = mod_frag_bb9a();
  puVar3 = puVar2 + 1;
  bVar1 = puVar2[-4];
  cVar9 = bVar7 - bVar1;
  if (cVar9 == '\0') {
    uVar8 = 1;
  }
  else {
    mod_frag_bb9a(cVar9);
    mod_frag_baa0();
    if (bVar7 < bVar1) {
      puVar4 = puVar3 + 1;
      anim_frame = mod_frag_bafc(puVar3[-4]);
      mod_frag_bb9a();
      anim_end = mod_frag_bafc();
      anim_flag = 1;
      puVar2 = puVar4 + 1;
      puVar5 = puVar4 + 1;
      if ((puVar4[-4] & 7) == 0) {
        anim_pos = anim_frame;
        while( true ) {
          cVar9 = (anim_end - anim_pos) + '\x02';
          if (0xfd < anim_end && anim_end + 2 <= anim_pos) break;
          mod_get_anim_flag_bb4e(cVar9);
        }
      }
      else {
        mod_frame_access_bb66();
        *(byte *)in_FSR1 = anim_frame;
        mod_to_gfx_clip_y_bb3a();
        anim_pos = anim_frame + 1;
        while( true ) {
          cVar9 = (anim_end - anim_pos) + '\x02';
          puVar2 = puVar5;
          if (0xfd < anim_end && anim_end + 2 <= anim_pos) break;
          mod_get_anim_flag_bb4e();
        }
      }
    }
    else {
      mod_frag_bb9a();
      anim_frame = mod_frag_bafc();
      puVar6 = puVar3 + 1;
      anim_end = mod_frag_bafc(puVar3[-4]);
      anim_flag = 0;
      puVar2 = puVar6 + 1;
      if ((puVar6[-4] & 7) == 0) {
        anim_pos = anim_frame;
        puVar2 = puVar6 + 1;
        while( true ) {
          cVar9 = anim_pos - anim_end;
          if (anim_end <= anim_pos) break;
          mod_get_anim_flag_bb4e(cVar9);
        }
      }
      else {
        anim_pos = anim_frame;
        while( true ) {
          if (anim_end <= anim_pos) break;
          mod_get_anim_flag_bb4e();
        }
        mod_frame_access_bb66(anim_pos - anim_end);
        *(byte *)in_FSR1 = anim_end;
        cVar9 = mod_to_gfx_clip_y_bb3a();
      }
    }
    mod_ptr_add_bbce(cVar9);
    *(undefined1 *)in_FSR0 = puVar2[-4];
    uVar8 = 0;
  }
  mod_c18_epilogue_ba78(uVar8);
  return;
}


// ===== 0x00b772 gfx_draw_frame_left =====

/* Graphics: draw left frame/tank outline */

void gfx_draw_frame_left(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  
  mod_stack_adjust_bba2(4);
  mod_to_lcd_puts_rom_bae0();
  mod_stack_adjust_bba2(0xd);
  mod_to_lcd_puts_rom_bab0();
  while( true ) {
    if (5 < *(byte *)((ushort)unaff_BSR * 0x100 + 0x55)) break;
    mod_get_anim_pos_bb8e(5);
    mod_get_anim_pos_bb8e(0xd);
    unaff_BSR = 1;
    anim_pos = anim_pos + '\x01';
  }
  mod_set_anim_pos_bbaa(5);
  while( true ) {
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x55);
    if (6 < bVar1) break;
    if (*(char *)((ushort)unaff_BSR * 0x100 + 0x55) == '\x02') {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x3f;
    }
    mod_callw_lcd_write_data_baa6(uVar5);
    unaff_BSR = 1;
    anim_pos = anim_pos + '\x01';
  }
  mod_callw_lcd_write_data_baa6(0x1f);
  mod_get_cfg_systemconfig2_bb1a();
  if (bVar1 == 7) {
    mod_set_text_row_bb40();
    *(undefined1 *)in_FSR1 = 0x72;
    *(undefined1 *)((short)in_FSR1 + 1) = 0;
    puVar2 = (undefined1 *)((short)in_FSR1 + 3);
    *(undefined1 *)((short)in_FSR1 + 2) = 7;
    txt_set_ui_hold_counter_98fc();
    puVar3 = puVar2 + -1;
    *puVar2 = *puVar2;
  }
  else {
    puVar4 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 3;
    mod_callw_fnba5a_bc20(7);
    *puVar4 = 0xf9;
    puVar3 = puVar4 + 2;
    puVar4[1] = 0x58;
    lcd_puts_rom();
  }
  *puVar3 = *puVar3;
  puVar3[-1] = puVar3[-1];
  return;
}


// ===== 0x00b7e6 gfx_draw_frame_right =====

/* Graphics: draw right frame/tank outline */

void gfx_draw_frame_right(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  
  mod_stack_adjust_bba2(0x71);
  mod_to_lcd_puts_rom_bae0();
  mod_stack_adjust_bba2(0x7a);
  mod_to_lcd_puts_rom_bab0();
  while( true ) {
    if (5 < *(byte *)((ushort)unaff_BSR * 0x100 + 0x55)) break;
    mod_get_anim_pos_bb8e(0x72);
    mod_get_anim_pos_bb8e(0x7a);
    unaff_BSR = 1;
    anim_pos = anim_pos + '\x01';
  }
  mod_set_anim_pos_bbaa(0x72);
  while( true ) {
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x55);
    if (6 < bVar1) break;
    if (*(char *)((ushort)unaff_BSR * 0x100 + 0x55) == '\x02') {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x3f;
    }
    mod_callw_lcd_write_data_baa6(uVar5);
    unaff_BSR = 1;
    anim_pos = anim_pos + '\x01';
  }
  mod_callw_lcd_write_data_baa6(0x1f);
  mod_get_cfg_systemconfig2_bb1a();
  if (bVar1 == 7) {
    mod_set_text_row_bb40();
    *(undefined1 *)in_FSR1 = 0x74;
    *(undefined1 *)((short)in_FSR1 + 1) = 0;
    puVar2 = (undefined1 *)((short)in_FSR1 + 3);
    *(undefined1 *)((short)in_FSR1 + 2) = 8;
    txt_set_ui_hold_counter_98fc();
    puVar3 = puVar2 + -1;
    *puVar2 = *puVar2;
  }
  else {
    puVar4 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0x6e;
    mod_callw_fnba5a_bc20(7);
    *puVar4 = 0xe8;
    puVar3 = puVar4 + 2;
    puVar4[1] = 0x58;
    lcd_puts_rom();
  }
  *puVar3 = *puVar3;
  puVar3[-1] = puVar3[-1];
  return;
}


// ===== 0x00b85a gfx_anim_icon_a =====

/* Graphics: animated icon A (14 frames of 0x38 bytes) */

void gfx_anim_icon_a(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  byte unaff_C;
  bool bVar3;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = 0xe;
  cVar2 = mod_to_mod_to_lcd_draw_glyph_bbe4(0x38);
  if ((unaff_C & 1) != 0) {
    anim_pos = 0;
    while( true ) {
      cVar2 = anim_pos - 4;
      if (3 < anim_pos) break;
      mod_set_anim_index_bb58(0x38);
      while( true ) {
        if (0xd < anim_index) break;
        puVar1 = (undefined1 *)((short)in_FSR2 + 1);
        mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
        bVar3 = 0x1f < c18_tmp2;
        c18_tmp2 = c18_tmp2 - 0x20;
        c18_tmp3 = c18_tmp3 + -0x79 + bVar3;
        mod_set_anim_index_bbda(anim_pos);
        in_FSR2 = (BADSPACEBASE *)puVar1;
      }
      anim_pos = anim_pos + 1;
    }
  }
  mod_c18_epilogue_ba78(cVar2);
  return;
}


// ===== 0x00b898 gfx_anim_icon_b =====

/* Graphics: animated icon B (frames of 0x94 bytes) */

void gfx_anim_icon_b(void)

{
  BADSPACEBASE *in_FSR2;
  byte *pbVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  byte unaff_C;
  bool bVar7;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0x25;
  cVar4 = mod_to_mod_to_lcd_draw_glyph_bbe4(0x2c);
  if ((unaff_C & 1) != 0) {
    anim_pos = 0;
    while( true ) {
      cVar4 = anim_pos - 4;
      if (3 < anim_pos) break;
      mod_set_anim_index_bb58(0x2c);
      while( true ) {
        if (0x24 < anim_index) break;
        pbVar1 = (byte *)((short)in_FSR2 + 1);
        mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
        bVar7 = 7 < c18_tmp2;
        c18_tmp2 = c18_tmp2 - 8;
        c18_tmp3 = c18_tmp3 + -0x78 + bVar7;
        uVar5 = mod_get_anim_index_ba3a(anim_pos);
        *pbVar1 = uVar5;
        bVar6 = 3 - ((cfg_systemconfig5 & 0x60) >> 5);
        if (bVar6 == 0) {
          if (anim_pos == 0) {
            *pbVar1 = 0;
          }
          bVar6 = anim_pos - 1;
          if (bVar6 == 0) {
            bVar6 = *pbVar1 & 0xfc;
            *pbVar1 = bVar6;
          }
        }
        puVar3 = puVar2 + 1;
        *puVar2 = *pbVar1;
        mod_set_anim_index_bbee(bVar6);
        in_FSR2 = (BADSPACEBASE *)pbVar1;
        puVar2 = puVar3;
      }
      anim_pos = anim_pos + 1;
    }
  }
  *puVar2 = *puVar2;
  mod_c18_epilogue_ba78(cVar4);
  return;
}


// ===== 0x00b908 gfx_anim_icon_c =====

/* Graphics: animated icon C (frames of 0x50 bytes) */

void gfx_anim_icon_c(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  bool bVar2;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = 0x14;
  mod_to_lcd_draw_glyph_ba84(0x35);
  anim_pos = 0;
  while( true ) {
    if (3 < anim_pos) break;
    mod_set_anim_index_bb58(0x35);
    while( true ) {
      if (0x13 < anim_index) break;
      puVar1 = (undefined1 *)((short)in_FSR2 + 1);
      mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
      bVar2 = 0x23 < c18_tmp2;
      c18_tmp2 = c18_tmp2 - 0x24;
      c18_tmp3 = c18_tmp3 + -0x75 + bVar2;
      mod_set_anim_index_bbda(anim_pos);
      in_FSR2 = (BADSPACEBASE *)puVar1;
    }
    anim_pos = anim_pos + 1;
  }
  mod_c18_epilogue_ba78(anim_pos - 4);
  return;
}


// ===== 0x00b944 gfx_anim_icon_d =====

/* Graphics: animated icon D (frames of 0x68 bytes) */

void gfx_anim_icon_d(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  byte unaff_C;
  bool bVar3;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = 0x1a;
  cVar2 = mod_to_mod_to_lcd_draw_glyph_bbe4(0x32);
  if ((unaff_C & 1) != 0) {
    anim_pos = 0;
    while( true ) {
      cVar2 = anim_pos - 4;
      if (3 < anim_pos) break;
      mod_set_anim_index_bb58(0x32);
      while( true ) {
        if (0x19 < anim_index) break;
        puVar1 = (undefined1 *)((short)in_FSR2 + 1);
        mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
        bVar3 = 0x93 < c18_tmp2;
        c18_tmp2 = c18_tmp2 + 0x6c;
        c18_tmp3 = c18_tmp3 + -0x73 + bVar3;
        mod_set_anim_index_bbda(anim_pos);
        in_FSR2 = (BADSPACEBASE *)puVar1;
      }
      anim_pos = anim_pos + 1;
    }
  }
  mod_c18_epilogue_ba78(cVar2);
  return;
}


// ===== 0x00b982 gfx_clip_x =====

/* Graphics: clip x coordinate */

void gfx_clip_x(void)

{
  byte bVar1;
  char cVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  byte unaff_C;
  
  mod_c18_prologue_ba28();
  mod_frag_bb2a();
  if ((unaff_C & 1) == 0) {
    mod_frag_bb32();
    if ((unaff_C & 1) == 0) {
      mod_frag_baa0(0x7f);
      if ((unaff_C & 1) == 0) {
        mod_set_anim_index_bbba();
        while( true ) {
          puVar3 = (undefined1 *)((short)in_FSR2 + 1);
          bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x56);
          cVar2 = bVar1 - *(byte *)((short)in_FSR2 + -4);
          if (*(byte *)((short)in_FSR2 + -4) <= bVar1) break;
          mod_get_math_aarg_hi_bac8(cVar2);
          if (cVar2 == '\0') {
            *(undefined1 *)in_FSR1 = 0;
            in_FSR2 = (BADSPACEBASE *)puVar3;
          }
          else {
            in_FSR2 = (BADSPACEBASE *)(puVar3 + 1);
            if (puVar3[-5] == '\0') {
              uVar4 = 0;
            }
            else {
              uVar4 = 0xff;
            }
            *(undefined1 *)in_FSR1 = uVar4;
          }
          in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
          mod_set_anim_index_bbee();
        }
        uVar4 = 0;
        goto LAB_CODE_00b9bc;
      }
    }
  }
  uVar4 = 0x81;
LAB_CODE_00b9bc:
  mod_c18_epilogue_ba78(uVar4);
  return;
}


// ===== 0x00b9be gfx_clip_y =====

/* Graphics: clip y coordinate */

void gfx_clip_y(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  byte bVar5;
  byte unaff_C;
  
  mod_c18_prologue_ba28();
  mod_frag_bb2a();
  if (((((unaff_C & 1) == 0) && (mod_frag_bb32(), (unaff_C & 1) == 0)) &&
      (mod_frag_baa0(0x7f), (unaff_C & 1) == 0)) && (*(byte *)((short)in_FSR2 + -5) < 9)) {
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    if (*(char *)((short)in_FSR2 + -4) == '\0') {
      uVar4 = 1;
    }
    else {
      mod_set_anim_index_bbba(*(char *)((short)in_FSR2 + -4));
      while( true ) {
        puVar3 = puVar2 + 1;
        bVar5 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x56);
        cVar1 = bVar5 - puVar2[-4];
        if ((byte)puVar2[-4] <= bVar5) break;
        mod_get_math_aarg_hi_bac8(cVar1);
        if (cVar1 == '\0') {
          *(undefined1 *)in_FSR1 = 0;
          puVar2 = puVar3;
        }
        else {
          c18_tmp0 = 0xff;
          puVar2 = puVar3 + 1;
          bVar5 = puVar3[-5];
          *(undefined1 *)in_FSR1 = 0xff;
          for (bVar5 = bVar5 & 7; bVar5 != 0; bVar5 = bVar5 - 1) {
            *(byte *)in_FSR1 = *(byte *)in_FSR1 >> 1;
            *(byte *)in_FSR1 = *(byte *)in_FSR1 & 0x7f;
          }
          *(byte *)in_FSR1 = ~*(byte *)in_FSR1;
        }
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
        mod_set_anim_index_bbee();
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x81;
  }
  mod_c18_epilogue_ba78(uVar4);
  return;
}


// ===== 0x00ba1a mod_frame_load_ptr_arg_ba1a =====

/* Auto: Load pointer argument from stack frame into FSR0; 5 instr */

undefined1 mod_frame_load_ptr_arg_ba1a(void)

{
  return 0xfd;
}


// ===== 0x00ba28 mod_c18_prologue_ba28 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_ba28(void)

{
  return;
}


// ===== 0x00ba3a mod_get_anim_index_ba3a =====

/* Auto: reads anim_index,TBLPTRL,TBLPTRH,TABLAT; 16 instr */

undefined1 mod_get_anim_index_ba3a(void)

{
  byte bVar1;
  byte unaff_BSR;
  byte in_PRODL;
  char in_PRODH;
  undefined3 in_TBLPTR;
  
  c18_tmp0 = in_PRODL + c18_tmp2;
  c18_tmp1 = in_PRODH + c18_tmp3 + CARRY1(in_PRODL,c18_tmp2);
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x56);
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,bVar1),c18_tmp0 + bVar1));
}


// ===== 0x00ba5a mod_stack_adjust_ba5a =====

/* Auto: Software stack push/pop helper; 4 instr */

void mod_stack_adjust_ba5a(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x00ba64 mod_to_gfx_clip_x_ba64 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes anim_pos; reads anim_pos; calls gfx_clip_x; 9 instr */

void mod_to_gfx_clip_x_ba64(void)

{
  gfx_clip_x();
  mod_pop4_return_bc04();
  anim_pos = anim_pos + '\x01';
  return;
}


// ===== 0x00ba78 mod_c18_epilogue_ba78 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_ba78(void)

{
  return;
}


// ===== 0x00ba84 mod_to_lcd_draw_glyph_ba84 =====

/* Auto: calls lcd_draw_glyph; 7 instr */

void mod_to_lcd_draw_glyph_ba84(void)

{
  lcd_draw_glyph();
  mod_pop4_return_bc04();
  return;
}


// ===== 0x00ba96 mod_ptr_add_ba96 =====

/* Auto: compiler fragment: ADDWF FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ; MOVF
   INDF0,w,ACCESS ; RETURN 0x0 */

undefined1 mod_ptr_add_ba96(undefined1 param_1)

{
  BADSPACEBASE *in_FSR0;
  
  return *(undefined1 *)CONCAT11((char)((ushort)in_FSR0 >> 8),param_1);
}


// ===== 0x00baa0 mod_frag_baa0 =====

/* Auto: compiler fragment: MOVWF PRODL,ACCESS ; MOVLW #0xfb ; BRA 0x00bbfa */

void mod_frag_baa0(void)

{
  mod_frame_access_bbfa(0xfb);
  return;
}


// ===== 0x00baa6 mod_callw_lcd_write_data_baa6 =====

/* Auto: Push W as argument and call lcd_write_data; 4 instr */

void mod_callw_lcd_write_data_baa6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00bab0 mod_to_lcd_puts_rom_bab0 =====

/* Auto: writes anim_pos; calls lcd_puts_rom; 11 instr */

undefined1 mod_to_lcd_puts_rom_bab0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  lcd_puts_rom();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  anim_pos = 2;
  return 2;
}


// ===== 0x00bac8 mod_get_math_aarg_hi_bac8 =====

/* Auto: reads math_aarg_hi,anim_index; 10 instr */

char mod_get_math_aarg_hi_bac8(void)

{
  char in_FramePointer2_0000fffc;
  
  c18_tmp0 = 3;
  math_barg_hi = 3;
  math_aarg_hi = in_FramePointer2_0000fffc;
  mod_shift_multibyte_fc24();
  return anim_index - math_aarg_hi;
}


// ===== 0x00bae0 mod_to_lcd_puts_rom_bae0 =====

/* Auto: calls lcd_puts_rom; 8 instr */

void mod_to_lcd_puts_rom_bae0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  lcd_puts_rom();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00baf2 mod_ptr_add_baf2 =====

/* Auto: compiler fragment: MOVLW #0x2 ; ADDWF FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ;
   RETURN 0x0 */

undefined1 mod_ptr_add_baf2(void)

{
  return 0;
}


// ===== 0x00bafc mod_frag_bafc =====

/* Auto: compiler fragment: ANDLW #0xf8 ; RRNCF WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RRNCF
   WREG,f,ACCESS ; RETURN 0x0 */

byte mod_frag_bafc(byte param_1)

{
  return param_1 >> 3;
}


// ===== 0x00bb06 mod_to_lcd_write_data_bb06 =====

/* Auto: Small wrapper around lcd_write_data; 4 instr */

void mod_to_lcd_write_data_bb06(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00bb10 mod_get_c18_tmp2_bb10 =====

/* Auto: reads c18_tmp2,c18_tmp3; 3 instr */

void mod_get_c18_tmp2_bb10(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  c18_tmp2 = in_PRODL;
  c18_tmp3 = in_PRODH;
  return;
}


// ===== 0x00bb1a mod_get_cfg_systemconfig2_bb1a =====

/* Auto: reads cfg_systemconfig2; 8 instr */

char mod_get_cfg_systemconfig2_bb1a(void)

{
  return '\x05' - ((cfg_systemconfig2 & 0x38) >> 3);
}


// ===== 0x00bb2a mod_frag_bb2a =====

/* Auto: compiler fragment: MOVLW #0x8 ; MOVWF PRODL,ACCESS ; MOVLW #0xfd ; BRA 0x00bbfa */

void mod_frag_bb2a(void)

{
  mod_frame_access_bbfa(0xfd);
  return;
}


// ===== 0x00bb32 mod_frag_bb32 =====

/* Auto: compiler fragment: MOVLW #0x7f ; MOVWF PRODL,ACCESS ; MOVLW #0xfc ; BRA 0x00bbfa */

void mod_frag_bb32(void)

{
  mod_frame_access_bbfa(0xfc);
  return;
}


// ===== 0x00bb3a mod_to_gfx_clip_y_bb3a =====

/* Auto: calls gfx_clip_y; 2 instr */

void mod_to_gfx_clip_y_bb3a(void)

{
  gfx_clip_y();
  mod_pop4_return_bc04();
  return;
}


// ===== 0x00bb40 mod_set_text_row_bb40 =====

/* Auto: writes text_row,text_fill_width; 7 instr */

undefined1 mod_set_text_row_bb40(void)

{
  text_row = 7;
  text_fill_width = 0x16;
  return 0x16;
}


// ===== 0x00bb4e mod_get_anim_flag_bb4e =====

/* Auto: reads anim_flag; 3 instr */

void mod_get_anim_flag_bb4e(void)

{
  mod_stack_adjust_bc0e();
  mod_to_gfx_clip_x_ba64();
  return;
}


// ===== 0x00bb58 mod_set_anim_index_bb58 =====

/* Auto: writes anim_index; reads anim_pos; 7 instr */

void mod_set_anim_index_bb58(void)

{
  byte unaff_BSR;
  
  mod_callw_fnba5a_bc20(*(char *)((ushort)unaff_BSR * 0x100 + 0x55) + '\x02');
  anim_index = 0;
  return;
}


// ===== 0x00bb66 mod_frame_access_bb66 =====

/* Auto: Access stack-frame local/argument; 13 instr */

undefined1 mod_frame_access_bb66(void)

{
  undefined1 uVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR0;
  byte in_FramePointer2_0000fffc;
  
  c18_tmp0 = 8;
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x54) = '\b' - (in_FramePointer2_0000fffc & 7);
  puVar2 = &FramePointer10x0001;
  mod_stack_adjust_bc0e();
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  uVar1 = *(undefined1 *)((short)in_FSR0 + 1);
  *puVar2 = uVar1;
  return uVar1;
}


// ===== 0x00bb80 mod_get_c18_tmp0_bb80 =====

/* Auto: reads c18_tmp0; 6 instr */

char mod_get_c18_tmp0_bb80(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  mod_frame_load_ptr_arg_ba1a();
  mod_ptr_add_baf2();
  c18_tmp0 = *(char *)in_FSR0;
  cVar1 = mod_frag_bc1a();
  return c18_tmp0 + cVar1;
}


// ===== 0x00bb8e mod_get_anim_pos_bb8e =====

/* Auto: reads anim_pos; 4 instr */

void mod_get_anim_pos_bb8e(void)

{
  mod_stack_adjust_ba5a();
  mod_to_lcd_write_data_bb06();
  return;
}


// ===== 0x00bb9a mod_frag_bb9a =====

/* Auto: compiler fragment: RCALL 0x00ba1a ; MOVLW #0x4 ; GOTO 0x00ba96 */

void mod_frag_bb9a(void)

{
  mod_frame_load_ptr_arg_ba1a();
  mod_ptr_add_ba96(4);
  return;
}


// ===== 0x00bba2 mod_stack_adjust_bba2 =====

/* Auto: Software stack push/pop helper; 3 instr */

void mod_stack_adjust_bba2(void)

{
  mod_callw_fnba5a_bc20(1);
  return;
}


// ===== 0x00bbaa mod_set_anim_pos_bbaa =====

/* Auto: writes anim_pos; 8 instr */

void mod_set_anim_pos_bbaa(void)

{
  mod_callw_fnba5a_bc20(6);
  mod_callw_lcd_write_data_baa6(0x1f);
  anim_pos = 0;
  return;
}


// ===== 0x00bbba mod_set_anim_index_bbba =====

/* Auto: writes anim_index; 8 instr */

void mod_set_anim_index_bbba(void)

{
  mod_stack_adjust_ba5a();
  anim_index = 0;
  return;
}


// ===== 0x00bbce mod_ptr_add_bbce =====

/* Auto: compiler fragment: RCALL 0x00ba1a ; MOVLW #0x4 ; ADDWF FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC
   FSR0H,f,ACCESS ; RETURN 0x0 */

undefined1 mod_ptr_add_bbce(void)

{
  mod_frame_load_ptr_arg_ba1a();
  return 0;
}


// ===== 0x00bbda mod_set_anim_index_bbda =====

/* Auto: writes anim_index; 5 instr */

void mod_set_anim_index_bbda(void)

{
  mod_get_anim_index_ba3a();
  mod_callw_lcd_write_data_baa6();
  anim_index = anim_index + '\x01';
  return;
}


// ===== 0x00bbe4 mod_to_mod_to_lcd_draw_glyph_bbe4 =====

/* Auto: Small wrapper around mod_to_lcd_draw_glyph; 5 instr */

char mod_to_mod_to_lcd_draw_glyph_bbe4(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_to_lcd_draw_glyph_ba84();
  return '\x04' - *(char *)((short)in_FSR2 + -2);
}


// ===== 0x00bbee mod_set_anim_index_bbee =====

/* Auto: writes anim_index; 5 instr */

void mod_set_anim_index_bbee(void)

{
  BADSPACEBASE *in_FSR1;
  
  lcd_write_data();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  anim_index = anim_index + '\x01';
  return;
}


// ===== 0x00bbfa mod_frame_access_bbfa =====

/* Auto: Access stack-frame local/argument; 4 instr */

char mod_frame_access_bbfa(char param_1)

{
  BADSPACEBASE *in_FSR2;
  char in_PRODL;
  
  return (&FramePointer20x0001)[param_1] - in_PRODL;
}


// ===== 0x00bc04 mod_pop4_return_bc04 =====

/* Auto: Drop stack arguments and return; 5 instr */

void mod_pop4_return_bc04(void)

{
  return;
}


// ===== 0x00bc0e mod_stack_adjust_bc0e =====

/* Auto: Software stack push/pop helper; 5 instr */

void mod_stack_adjust_bc0e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  mod_frame_load_ptr_arg_ba1a();
  uVar1 = mod_ptr_add_ba96(3);
  *(undefined1 *)in_FSR1 = uVar1;
  mod_frame_load_ptr_arg_ba1a();
  return;
}


// ===== 0x00bc1a mod_frag_bc1a =====

/* Auto: compiler fragment: RCALL 0x00ba1a ; MOVF INDF0,w,ACCESS ; RETURN 0x0 */

undefined1 mod_frag_bc1a(void)

{
  BADSPACEBASE *in_FSR0;
  
  mod_frame_load_ptr_arg_ba1a();
  return *(undefined1 *)in_FSR0;
}


// ===== 0x00bc20 mod_callw_fnba5a_bc20 =====

/* Auto: Push W as argument and call 0xba5a; 2 instr */

void mod_callw_fnba5a_bc20(void)

{
  mod_stack_adjust_ba5a();
  return;
}


// ===== 0x00bc26 hw_init_peripherals =====

/* WARNING: Instruction at (CODE,0x00bc86) overlaps instruction at (CODE,0x00bc84)
    */
/* Configure EUSART2 9600 8N1, Timer0 10 ms tick, ADC, comparators off, port directions */

undefined1 hw_init_peripherals(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = TRISG;
  TRISG = bVar1 | TRISG2;
  bVar1 = TRISG;
  TRISG = bVar1 & ~TRISG1;
  TXSTA2 = (BRGH | TXEN);
  SPBRG2 = 0x19;
  RCSTA2 = (CREN | SPEN);
  bVar1 = IPR1;
  IPR1 = bVar1 | RCIP;
  bVar1 = PIE3;
  PIE3 = bVar1 & ~TX2IE;
  bVar1 = PIE3;
  PIE3 = bVar1 | RC2IE;
  tmr0_reload_lo = 0;
  tmr0_reload_hi = 0xd9;
  bVar1 = T0CON;
  T0CON = bVar1 & ~T0CS;
  bVar1 = T0CON;
  T0CON = bVar1 & ~T08BIT;
  TMR0H = 0xd9;
  TMR0L = 0;
  bVar1 = T0CON;
  T0CON = bVar1 | PSA;
  bVar1 = T0CON;
  T0CON = bVar1 | TMR0ON;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & ~TMR0IP;
  bVar1 = INTCON;
  INTCON = bVar1 | TMR0IE;
  ADCON1 = (PCFG1 | PCFG2);
  ADCON0 = 0;
  PORTA = 0;
  bVar1 = TRISA;
  TRISA = bVar1 | (TRISA0 | TRISA1 | TRISA4 | TRISA5);
  TRISF = (TRISF0 | TRISF1 | TRISF2 | TRISF3 | TRISF4 | TRISF5);
  CMCON = (CM0 | CM1 | CM2 | CIS);
  ADCON2 = (ADCS0 | ADCS2 | ADFM);
  bVar1 = PIR1;
  PIR1 = bVar1 & ~ADIF;
  bVar1 = PIE1;
  PIE1 = bVar1 & ~ADIE;
  bVar1 = ADCON0;
  ADCON0 = bVar1 | ADON;
  cVar2 = '<';
  do {
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  TRISB = (TRISB2 | TRISB5 | TRISB6 | TRISB7);
  bVar1 = INTCON2;
  INTCON2 = bVar1 & ~nRBPU;
  TRISC = (TRISC2 | TRISC3 | TRISC4 | TRISC5 | TRISC6 | TRISC7);
  TRISE = (TRISE0 | TRISE1 | TRISE2 | TRISE3 | TRISE4 | TRISE5);
  TRISH = 0;
  TRISG = (TRISG1 | TRISG2 | 0xe0);
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF6;
  outputs_shadow = 0;
  bVar1 = TRISF;
  TRISF = bVar1 & ~TRISF6;
  bVar1 = TRISJ;
  TRISJ = bVar1 | (TRISJ0 | TRISJ1);
  bVar1 = TRISC;
  TRISC = bVar1 | TRISC3;
  bVar1 = TRISJ;
  TRISJ = bVar1 | (TRISJ5 | TRISJ6 | TRISJ7);
  bVar1 = TRISJ;
  TRISJ = bVar1 | (TRISJ3 | TRISJ4);
  bVar1 = RCON;
  RCON = bVar1 | IPEN;
  adc_current_channel = 0xf;
  return 0;
}


// ===== 0x00bcc0 isr_high =====

/* High-priority ISR: save compiler temps, run EUSART2 handler */

undefined1 isr_high(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 in_WS;
  
  puVar2 = &FramePointer10x0008;
  cVar6 = '\x14';
  puVar5 = (undefined1 *)0x0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  cVar6 = '\x10';
  puVar5 = &c18_tmp0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar3 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  puVar4 = puVar2 + 1;
  *puVar2 = *puVar2;
  mod_to_uart2_rx_isr_b498();
  *puVar4 = *puVar4;
  cVar6 = '\x10';
  puVar5 = puVar4 + -1;
  puVar7 = &c18_tmp15;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  cVar6 = '\x14';
  puVar7 = &math_tmp13;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  return in_WS;
}


// ===== 0x00bd4a isr_low =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Low-priority ISR: Timer0 10 ms tick (reload TMR0, drive Salvo timer) */

undefined1 isr_low(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  bool bVar10;
  
  puVar3 = &FramePointer10x000b;
  cVar8 = '\x14';
  puVar7 = (undefined1 *)0x0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar2 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  cVar8 = '\x10';
  puVar7 = &c18_tmp0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar4 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar4 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  puVar5 = puVar3 + 1;
  puVar6 = puVar3 + 1;
  *puVar3 = *puVar3;
  bVar1 = INTCON;
  if (((bVar1 & TMR0IE) == 0) || (bVar1 = INTCON, (bVar1 & TMR0IF) == 0)) {
    isr_low_other();
    puVar7 = puVar6;
  }
  else {
    bVar1 = INTCON;
    INTCON = bVar1 & ~TMR0IF;
    bVar1 = TMR0L;
    cVar8 = TMR0H;
    tmr0_next_lo = bVar1 + tmr0_reload_lo;
    tmr0_next_hi = cVar8 + tmr0_reload_hi + CARRY1(bVar1,tmr0_reload_lo);
    TMR0H = tmr0_next_hi;
    TMR0L = tmr0_next_lo;
    if (os_tick_suppress == '\0') {
      os_tick(0);
      puVar7 = puVar5;
    }
    else {
      tick_hold_counter = tick_hold_counter + '\x01';
      puVar7 = puVar3 + 1;
      if (tick_hold_counter == 'd') {
        tick_hold_counter = '\0';
        puVar7 = puVar3 + 1;
      }
    }
  }
  *puVar7 = *puVar7;
  cVar8 = '\x10';
  puVar7 = puVar7 + -1;
  puVar9 = &c18_tmp15;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  cVar8 = '\x14';
  puVar9 = &math_tmp13;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  return puVar7[-8];
}


// ===== 0x00be3c adc_select_channel =====

/* WARNING: Instruction at (CODE,0x00be6e) overlaps instruction at (CODE,0x00be6c)
    */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Select ADC input channel (skips if already selected) and wait acquisition time */

undefined1 adc_select_channel(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  if (adc_current_channel != pcVar1[-2]) {
    adc_current_channel = pcVar1[-1];
    ADCON0 = *pcVar1 * '\x04' | 1;
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
  }
  return 0;
}


// ===== 0x00be7c adc_read =====

/* Select channel, convert, return 10-bit result; flags sensor fault near full scale */

void adc_read(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  
  mod_c18_prologue_c116();
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  adc_select_channel();
  *puVar4 = *puVar4;
  bVar1 = ADCON0;
  ADCON0 = bVar1 | GO;
  do {
    bVar1 = ADCON0;
  } while ((bVar1 & GO) != 0);
  cVar2 = ADRESL;
  bVar1 = ADRESH;
  if ((byte)~(cVar2 == '\0') < 4 && 3U - ~(cVar2 == '\0') <= bVar1) {
    fault_code = 0x87;
  }
  else {
    fault_code = 0;
  }
  uVar3 = ADRESL;
  uVar3 = ADRESH;
  mod_c18_epilogue_c138();
  return;
}


// ===== 0x00beae ntc_table_lookup =====

/* Convert raw ADC to deg C via NTC table (FF=open, FE=short, 81=out of range) */

void ntc_table_lookup(void)

{
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte in_TABLAT;
  byte *in_TBLPTR;
  bool bVar6;
  
  mod_c18_prologue_c116();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  if (adc_raw_lo == 0xff) {
    if (adc_raw_hi == 3) {
      puVar2 = (undefined1 *)((short)in_FSR1 + 2);
      cVar4 = -1;
      goto LAB_CODE_00bf8e;
    }
  }
  bVar5 = adc_raw_hi | adc_raw_lo;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  if (bVar5 == 0) {
    cVar4 = -2;
  }
  else {
    while( true ) {
      puVar2 = puVar1;
      bVar3 = mod_get_c18_tmp0_c0f4(bVar5);
      bVar5 = ~(bVar3 <= adc_raw_lo);
      if (adc_raw_hi < bVar5 || c18_tmp1 < adc_raw_hi - bVar5) break;
      cVar4 = mod_get_c18_tmp0_c0f4((adc_raw_hi - c18_tmp1) - ~(bVar3 <= adc_raw_lo));
      if (c18_tmp1 == 0 && cVar4 == '\0') {
        cVar4 = -0x7f;
        goto LAB_CODE_00bf8e;
      }
      bVar6 = 0xf5 < ntc_table_ptr_lo;
      ntc_table_ptr_lo = ntc_table_ptr_lo + 10;
      bVar5 = 0;
      ntc_table_ptr_hi = ntc_table_ptr_hi + bVar6;
      puVar1 = puVar2;
    }
    *(byte *)in_FSR2 = adc_raw_lo;
    *(byte *)((short)in_FSR2 + 1) = adc_raw_hi;
    mod_get_ntc_table_ptr_lo_c144();
    mod_get_TBLPTRL_c14e(8);
    c18_tmp12 = in_TABLAT;
    c18_tmp13 = *in_TBLPTR;
    bVar5 = c18_tmp13;
    mod_get_ntc_table_ptr_lo_c144();
    mod_get_TBLPTRL_c14e(4);
    c18_tmp10 = bVar5;
    c18_tmp11 = *in_TBLPTR;
    bVar5 = c18_tmp11;
    mod_get_ntc_table_ptr_lo_c144();
    mod_get_TBLPTRL_c14e(6);
    c18_tmp8 = bVar5;
    c18_tmp9 = *in_TBLPTR;
    mod_get_ntc_table_ptr_lo_c144();
    c18_tmp6 = *in_TBLPTR;
    c18_tmp7 = in_TBLPTR[1];
    math_aarg_lo = c18_tmp6 - *(byte *)in_FSR2;
    math_aarg_hi = (c18_tmp7 - *(byte *)((short)in_FSR2 + 1)) - ~(*(byte *)in_FSR2 <= c18_tmp6);
    math_barg_lo = c18_tmp8;
    math_barg_hi = c18_tmp9;
    c18_tmp4 = math_aarg_lo;
    c18_tmp5 = math_aarg_hi;
    __mul16();
    c18_tmp2 = math_res0;
    c18_tmp3 = math_res1;
    math_aarg_lo = math_res0;
    math_aarg_hi = math_res1;
    math_barg_lo = c18_tmp10;
    math_barg_hi = c18_tmp11;
    __divu16();
    bVar6 = CARRY1(c18_tmp12,math_aarg_lo);
    math_aarg_lo = c18_tmp12 + math_aarg_lo;
    math_aarg_hi = c18_tmp13 + math_aarg_hi + bVar6;
    math_barg_lo = 10;
    math_barg_hi = 0;
    c18_tmp0 = math_aarg_lo;
    c18_tmp1 = math_aarg_hi;
    __divu16();
    cVar4 = math_aarg_lo;
  }
LAB_CODE_00bf8e:
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  mod_c18_epilogue_c138(cVar4);
  return;
}


// ===== 0x00bf94 temp_filter =====

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


// ===== 0x00bfcc temp_read_ch6 =====

/* Temperature on AN6 (table 0xEBD6; device/ambient sensor) */

void temp_read_ch6(void)

{
  adc_read_to_tmp_b(6);
  ntc_table_ptr_lo = 0xd6;
  ntc_table_ptr_hi = 0xeb;
  temp_filter();
  return;
}


// ===== 0x00bfdc temp_read_ch7 =====

/* Temperature on AN7 (cold table) */

void temp_read_ch7(void)

{
  adc_read_to_tmp_b(7);
  ntc_table_ptr_lo = 0x96;
  ntc_table_ptr_hi = 0xea;
  temp_filter();
  return;
}


// ===== 0x00bfec mod_param_tnormalcoldcutout_bfec =====

/* Auto: reads params TNORMALCOLDCUTOUT; calls eeprom_read_raw; 5 instr */

void mod_param_tnormalcoldcutout_bfec(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00bff8 beep_and_halt =====

/* WARNING: Instruction at (CODE,0x00c020) overlaps instruction at (CODE,0x00c01e)
    */
/* WARNING: Removing unreachable block (CODE,0x00c04c) */
/* WARNING: Removing unreachable block (CODE,0x00c054) */
/* WARNING: Removing unreachable block (CODE,0x00c058) */
/* WARNING: Removing unreachable block (CODE,0x00c062) */
/* WARNING: Removing unreachable block (CODE,0x00c066) */
/* WARNING: Removing unreachable block (CODE,0x00c070) */
/* WARNING: Removing unreachable block (CODE,0x00c07a) */
/* WARNING: Removing unreachable block (CODE,0x00c07e) */
/* WARNING: Removing unreachable block (CODE,0x00c088) */
/* WARNING: Removing unreachable block (CODE,0x00c08c) */
/* WARNING: Removing unreachable block (CODE,0x00c092) */
/* WARNING: Removing unreachable block (CODE,0x00c09c) */
/* WARNING: Removing unreachable block (CODE,0x00c0b6) */
/* WARNING: Removing unreachable block (CODE,0x00c0ba) */
/* WARNING: Removing unreachable block (CODE,0x00c0cc) */
/* WARNING: Removing unreachable block (CODE,0x00c0b8) */
/* WARNING: Removing unreachable block (CODE,0x00c0d0) */
/* WARNING: Removing unreachable block (CODE,0x00c0a6) */
/* WARNING: Removing unreachable block (CODE,0x00c0a8) */
/* WARNING: Removing unreachable block (CODE,0x00c0aa) */
/* WARNING: Removing unreachable block (CODE,0x00c0ae) */
/* WARNING: Removing unreachable block (CODE,0x00c090) */
/* WARNING: Removing unreachable block (CODE,0x00c0d6) */
/* Sound buzzer (RB3) briefly then loop forever (watchdog reset) */

void beep_and_halt(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = INTCON;
  INTCON = bVar1 | (PEIE | GIE);
  bVar1 = PORTB;
  PORTB = bVar1 | RB3;
  adc_raw_hi = 0;
  for (adc_raw_lo = 0;
      (byte)~(0x99 < adc_raw_lo) <= adc_raw_hi && adc_raw_hi - ~(0x99 < adc_raw_lo) < 3;
      adc_raw_lo = adc_raw_lo + 1) {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    adc_raw_hi = adc_raw_hi + (0xfe < adc_raw_lo);
  }
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB3;
  do {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
  } while( true );
}


// ===== 0x00c0e6 mod_get_temp_new_reading_c0e6 =====

/* Auto: reads temp_new_reading; 6 instr */

void mod_get_temp_new_reading_c0e6(void)

{
  BADSPACEBASE *in_FSR0;
  
  mod_calc_array_ptr_c166();
  *(undefined1 *)in_FSR0 = 3;
  mod_calc_array_ptr_c158();
  *(undefined1 *)in_FSR0 = temp_new_reading;
  return;
}


// ===== 0x00c0f4 mod_get_c18_tmp0_c0f4 =====

/* Auto: reads c18_tmp0,TABLAT,c18_tmp1; 8 instr */

undefined1 mod_get_c18_tmp0_c0f4(void)

{
  undefined1 in_TABLAT;
  undefined1 *in_TBLPTR;
  
  mod_get_ntc_table_ptr_lo_c144();
  mod_get_TBLPTRL_c14e(2);
  c18_tmp0 = in_TABLAT;
  c18_tmp1 = *in_TBLPTR;
  return in_TABLAT;
}


// ===== 0x00c108 mod_calc_array_ptr_c108 =====

/* Auto: Compute array element address in FSR0; 7 instr */

undefined1 mod_calc_array_ptr_c108(void)

{
  return 0;
}


// ===== 0x00c116 mod_c18_prologue_c116 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_c116(void)

{
  return;
}


// ===== 0x00c128 adc_read_to_tmp_b =====

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


// ===== 0x00c138 mod_c18_epilogue_c138 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_c138(void)

{
  return;
}


// ===== 0x00c144 mod_get_ntc_table_ptr_lo_c144 =====

/* Auto: reads ntc_table_ptr_lo,TBLPTRL,ntc_table_ptr_hi,TBLPTRH; 3 instr */

void mod_get_ntc_table_ptr_lo_c144(void)

{
  return;
}


// ===== 0x00c14e mod_get_TBLPTRL_c14e =====

/* Auto: reads TBLPTRL,TBLPTRH; 5 instr */

undefined1 mod_get_TBLPTRL_c14e(void)

{
  return 0;
}


// ===== 0x00c158 mod_calc_array_ptr_c158 =====

/* Auto: Compute array element address in FSR0; 7 instr */

undefined1 mod_calc_array_ptr_c158(void)

{
  return 0xe;
}


// ===== 0x00c166 mod_calc_array_ptr_c166 =====

/* Auto: Compute array element address in FSR0; 7 instr */

undefined1 mod_calc_array_ptr_c166(void)

{
  return 0xe;
}


// ===== 0x00c174 atol =====
/* decompile failed: Exception while decompiling CODE:00c174: java.lang.IndexOutOfBoundsException: Index 0 out of bounds for length 0
 */

// ===== 0x00c226 fmt_byte =====

/* Format byte as decimal (printf helper) */

char fmt_byte(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  short sVar8;
  char in_FramePointer1_00000003;
  byte in_FramePointer1_0000fffe;
  
  puVar3 = (undefined1 *)(ushort)in_FramePointer1_0000fffe;
  puVar6 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    puVar4 = puVar3 + 1;
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x000a;
  }
  *puVar6 = *puVar6;
  puVar6[1] = puVar6[1];
  puVar6[2] = (byte)(puVar6 + 2) - 2;
  puVar6[3] = (char)((ushort)(puVar6 + 2) >> 8) + -1 + (1 < (byte)(puVar6 + 2));
  puVar6[3] = puVar6[3];
  puVar7 = puVar6 + 6;
  puVar6[4] = puVar6[-1];
  mod_stack_adjust_c2e2();
  bVar5 = (byte)puVar7;
  uVar2 = (ushort)puVar7 >> 8;
  mod_frag_c2c2();
  if ((char)uVar2 + -1 + (4 < bVar5) == '\0') {
    mod_bcd_digit_helper_c2bc();
  }
  else {
    mod_bcd_digit_helper_c2d8();
    mod_bcd_digit_helper_c2ce();
  }
  mod_bcd_digit_helper_c2d8();
  *puVar4 = 0;
  bVar5 = (byte)puVar7 - 5;
  cVar1 = (char)((ushort)puVar7 >> 8) + -1 + (4 < (byte)puVar7);
  sVar8 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  return cVar1 + -1 + (2 < bVar5);
}


// ===== 0x00c2bc mod_bcd_digit_helper_c2bc =====

/* Auto: BCD/ASCII digit helper for number formatting; 3 instr */

byte mod_bcd_digit_helper_c2bc(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 >> 4;
}


// ===== 0x00c2c2 mod_frag_c2c2 =====

/* Auto: compiler fragment: MOVF INDF0,w,ACCESS ; ANDLW #0xf ; BNZ 0x00c2cc ; MOVF POSTINC0,f,ACCESS
   ; BSF STATUS,#0x2,ACCESS ; RETURN 0x0 */

void mod_frag_c2c2(void)

{
  return;
}


// ===== 0x00c2ce mod_bcd_digit_helper_c2ce =====

/* Auto: BCD/ASCII digit helper for number formatting; 5 instr */

char mod_bcd_digit_helper_c2ce(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 >> 4) + 0x30;
}


// ===== 0x00c2d8 mod_bcd_digit_helper_c2d8 =====

/* Auto: BCD/ASCII digit helper for number formatting; 5 instr */

char mod_bcd_digit_helper_c2d8(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0xf) + 0x30;
}


// ===== 0x00c2e2 mod_stack_adjust_c2e2 =====

/* Auto: Software stack push/pop helper; 22 instr */

undefined1 mod_stack_adjust_c2e2(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar4 = (undefined1 *)CONCAT11(in_FramePointer1_00000000,in_FramePointer1_0000fffe);
  pbVar6 = puVar4 + 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  bVar7 = false;
  pcVar2 = &FramePointer10x0003;
  while( true ) {
    pcVar2[-1] = *pcVar2 << 1 | bVar7;
    pbVar5 = pbVar6 + -1;
    cVar1 = *pbVar6;
    *pbVar6 = cVar1 << 1 | *pcVar2 < '\0';
    pbVar6[-1] = pbVar6[-1] << 1 | cVar1 < '\0';
    pcVar3 = pcVar2 + 4;
    bVar7 = pcVar2[3] != '\0';
    cVar1 = pcVar2[3] + -1;
    pcVar2[2] = cVar1;
    if (cVar1 == '\0') break;
    mod_frag_c316();
    pbVar6 = pbVar5 + 1;
    *pbVar5 = *pbVar5;
    mod_frag_c316();
    pcVar2 = pcVar3;
  }
  pcVar2[4] = 0xff;
  return 0xff;
}


// ===== 0x00c316 mod_frag_c316 =====

/* Auto: compiler fragment: MOVLW #0x3 ; ADDWF INDF0,w,ACCESS ; BTFSC WREG,#0x3,ACCESS ; MOVWF
   INDF0,ACCESS ; MOVLW #0x30 ; ADDWF INDF0,w,ACCESS ; BTFSC WREG,#0x7,ACCESS ; MOVWF INDF0,ACCESS ;
   RETLW #0x0 */

undefined1 mod_frag_c316(void)

{
  return 0;
}


// ===== 0x00c328 fmt_int =====

/* Format 16-bit integer as decimal (printf helper) */

char fmt_int(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  short sVar9;
  char in_FramePointer1_00000003;
  char in_FramePointer1_00000006;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  puVar7 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    puVar4 = puVar3 + 1;
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x000a;
    if (in_FramePointer1_00000006 == -1) {
      puVar6 = &FramePointer10x000c;
    }
    puVar7 = puVar6 + 2;
    puVar6[-2] = ~puVar6[-1];
  }
  *puVar7 = *puVar7;
  puVar7[1] = puVar7[1];
  puVar7[2] = puVar7[2];
  puVar7[3] = (byte)(puVar7 + 3) - 3;
  puVar7[4] = (char)((ushort)(puVar7 + 3) >> 8) + -1 + (2 < (byte)(puVar7 + 3));
  puVar7[4] = puVar7[4];
  puVar7[5] = puVar7[-2];
  puVar8 = puVar7 + 9;
  puVar7[7] = *puVar7;
  int16_to_bcd();
  bVar5 = (byte)puVar8;
  uVar2 = (ushort)puVar8 >> 8;
  mod_frag_c3e8();
  if ((char)uVar2 + -1 + (6 < bVar5) == '\0') {
    mod_bcd_digit_helper_c3e2();
    mod_frag_c3e8();
    mod_bcd_digit_helper_c3e2();
  }
  else {
    mod_bcd_digit_helper_c3fe();
    mod_bcd_digit_helper_c3f4();
    mod_bcd_digit_helper_c3fe();
    mod_bcd_digit_helper_c3f4();
  }
  mod_bcd_digit_helper_c3fe();
  *puVar4 = 0;
  bVar5 = (byte)puVar8 - 7;
  cVar1 = (char)((ushort)puVar8 >> 8) + -1 + (6 < (byte)puVar8);
  sVar9 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar9 + 1) = *(undefined1 *)(sVar9 + 1);
  *(undefined1 *)(sVar9 + 1) = *(undefined1 *)(sVar9 + 1);
  return cVar1 + -1 + (3 < bVar5);
}


// ===== 0x00c3e2 mod_bcd_digit_helper_c3e2 =====

/* Auto: BCD/ASCII digit helper for number formatting; 3 instr */

byte mod_bcd_digit_helper_c3e2(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 >> 4;
}


// ===== 0x00c3e8 mod_frag_c3e8 =====

/* Auto: compiler fragment: MOVF INDF0,w,ACCESS ; ANDLW #0xf ; BNZ 0x00c3f2 ; MOVF POSTINC0,f,ACCESS
   ; BSF STATUS,#0x2,ACCESS ; RETURN 0x0 */

void mod_frag_c3e8(void)

{
  return;
}


// ===== 0x00c3f4 mod_bcd_digit_helper_c3f4 =====

/* Auto: BCD/ASCII digit helper for number formatting; 5 instr */

char mod_bcd_digit_helper_c3f4(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 >> 4) + 0x30;
}


// ===== 0x00c3fe mod_bcd_digit_helper_c3fe =====

/* Auto: BCD/ASCII digit helper for number formatting; 5 instr */

char mod_bcd_digit_helper_c3fe(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0xf) + 0x30;
}


// ===== 0x00c408 int16_to_bcd =====

/* Convert 16-bit binary to BCD (double dabble) */

undefined1 int16_to_bcd(void)

{
  char cVar1;
  char cVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar5 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  *puVar5 = 0;
  pbVar8 = puVar5 + 2;
  puVar5[1] = 0;
  puVar5[2] = 0;
  bVar9 = false;
  puVar3 = &FramePointer10x0003;
  while( true ) {
    puVar3[-2] = puVar3[-1] << 1 | bVar9;
    puVar3[1] = puVar3[2] << 1 | (char)puVar3[-1] < '\0';
    cVar1 = *pbVar8;
    *pbVar8 = cVar1 << 1 | (char)puVar3[2] < '\0';
    pbVar6 = pbVar8 + -2;
    cVar2 = pbVar8[-1];
    pbVar8[-1] = cVar2 << 1 | cVar1 < '\0';
    pbVar8[-2] = pbVar8[-2] << 1 | cVar2 < '\0';
    puVar4 = puVar3 + 6;
    bVar9 = puVar3[5] != '\0';
    cVar1 = puVar3[5] + -1;
    puVar3[4] = cVar1;
    if (cVar1 == '\0') break;
    mod_frag_c44a();
    puVar7 = pbVar6 + 1;
    *pbVar6 = *pbVar6;
    mod_frag_c44a();
    pbVar8 = puVar7 + 1;
    *puVar7 = *puVar7;
    mod_frag_c44a();
    puVar3 = puVar4;
  }
  puVar3[6] = 0xff;
  return 0xff;
}


// ===== 0x00c44a mod_frag_c44a =====

/* Auto: compiler fragment: MOVLW #0x3 ; ADDWF INDF0,w,ACCESS ; BTFSC WREG,#0x3,ACCESS ; MOVWF
   INDF0,ACCESS ; MOVLW #0x30 ; ADDWF INDF0,w,ACCESS ; BTFSC WREG,#0x7,ACCESS ; MOVWF INDF0,ACCESS ;
   RETLW #0x0 */

undefined1 mod_frag_c44a(void)

{
  return 0;
}


// ===== 0x00c45c ltoa =====

/* C library: long to ASCII (with sign) */

char ltoa(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  short sVar8;
  char in_FramePointer1_00000003;
  char in_FramePointer1_0000000b;
  char in_FramePointer1_0000000d;
  char in_FramePointer1_00000010;
  undefined1 in_FramePointer1_0000fffb;
  undefined1 in_FramePointer1_0000fffd;
  
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_0000fffd,in_FramePointer1_0000fffb);
  puVar6 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x0010;
    puVar4 = puVar3 + 1;
    if (((in_FramePointer1_0000000b == '\0') &&
        (puVar6 = &FramePointer10x0012, puVar4 = puVar3 + 1, in_FramePointer1_0000000d == -1)) &&
       (puVar6 = &FramePointer10x0014, puVar4 = puVar3 + 1, in_FramePointer1_00000010 == -1)) {
      puVar6 = &FramePointer10x0016;
      puVar4 = puVar3 + 1;
    }
  }
  *puVar6 = *puVar6;
  puVar6[1] = puVar6[1];
  puVar6[2] = puVar6[2];
  puVar6[3] = puVar6[3];
  puVar6[4] = puVar6[4];
  puVar6[5] = (byte)(puVar6 + 5) - 5;
  puVar6[6] = (char)((ushort)(puVar6 + 5) >> 8) + -1 + (4 < (byte)(puVar6 + 5));
  puVar6[6] = puVar6[6];
  puVar6[7] = puVar6[-4];
  puVar6[9] = puVar6[-2];
  puVar6[0xb] = *puVar6;
  puVar7 = puVar6 + 0xf;
  puVar6[0xd] = puVar6[2];
  int32_to_bcd();
  bVar5 = (byte)puVar7;
  uVar2 = (ushort)puVar7 >> 8;
  mod_bcd_digit_helper_c570();
  if ((char)uVar2 + -1 + (10 < bVar5) == '\0') {
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
  }
  else {
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
  }
  mod_bcd_digit_helper_c58c();
  *puVar4 = 0;
  bVar5 = (byte)puVar7 - 0xb;
  cVar1 = (char)((ushort)puVar7 >> 8) + -1 + (10 < (byte)puVar7);
  sVar8 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  return cVar1 + -1 + (5 < bVar5);
}


// ===== 0x00c570 mod_bcd_digit_helper_c570 =====

/* Auto: BCD/ASCII digit helper for number formatting; 3 instr */

byte mod_bcd_digit_helper_c570(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 >> 4;
}


// ===== 0x00c576 mod_frag_c576 =====

/* Auto: compiler fragment: MOVF INDF0,w,ACCESS ; ANDLW #0xf ; BNZ 0x00c580 ; MOVF POSTINC0,f,ACCESS
   ; BSF STATUS,#0x2,ACCESS ; RETURN 0x0 */

void mod_frag_c576(void)

{
  return;
}


// ===== 0x00c582 mod_bcd_digit_helper_c582 =====

/* Auto: BCD/ASCII digit helper for number formatting; 5 instr */

char mod_bcd_digit_helper_c582(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 >> 4) + 0x30;
}


// ===== 0x00c58c mod_bcd_digit_helper_c58c =====

/* Auto: BCD/ASCII digit helper for number formatting; 5 instr */

char mod_bcd_digit_helper_c58c(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0xf) + 0x30;
}


// ===== 0x00c596 int32_to_bcd =====

/* Convert 32-bit binary to BCD */

undefined1 int32_to_bcd(void)

{
  char cVar1;
  char cVar2;
  BADSPACEBASE *in_FSR1;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  bool bVar11;
  undefined1 in_FramePointer1_0000fffb;
  undefined1 in_FramePointer1_0000fffd;
  
  puVar5 = (undefined1 *)CONCAT11(in_FramePointer1_0000fffd,in_FramePointer1_0000fffb);
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0;
  pbVar10 = puVar5 + 4;
  puVar5[3] = 0;
  puVar5[4] = 0;
  bVar11 = false;
  pcVar3 = &FramePointer10x0003;
  while( true ) {
    pcVar3[-4] = pcVar3[-3] << 1 | bVar11;
    pcVar3[-1] = *pcVar3 << 1 | pcVar3[-3] < '\0';
    pcVar3[2] = pcVar3[3] << 1 | *pcVar3 < '\0';
    pcVar3[5] = pcVar3[6] << 1 | pcVar3[3] < '\0';
    cVar1 = *pbVar10;
    *pbVar10 = cVar1 << 1 | pcVar3[6] < '\0';
    cVar2 = pbVar10[-1];
    pbVar10[-1] = cVar2 << 1 | cVar1 < '\0';
    cVar1 = pbVar10[-2];
    pbVar10[-2] = cVar1 << 1 | cVar2 < '\0';
    pbVar6 = pbVar10 + -4;
    cVar2 = pbVar10[-3];
    pbVar10[-3] = cVar2 << 1 | cVar1 < '\0';
    pbVar10[-4] = pbVar10[-4] << 1 | cVar2 < '\0';
    pcVar4 = pcVar3 + 10;
    bVar11 = pcVar3[9] != '\0';
    cVar1 = pcVar3[9] + -1;
    pcVar3[8] = cVar1;
    if (cVar1 == '\0') break;
    mod_frag_c5f4();
    puVar7 = pbVar6 + 1;
    *pbVar6 = *pbVar6;
    mod_frag_c5f4();
    puVar8 = puVar7 + 1;
    *puVar7 = *puVar7;
    mod_frag_c5f4();
    puVar9 = puVar8 + 1;
    *puVar8 = *puVar8;
    mod_frag_c5f4();
    pbVar10 = puVar9 + 1;
    *puVar9 = *puVar9;
    mod_frag_c5f4();
    pcVar3 = pcVar4;
  }
  pcVar3[10] = 0xff;
  return 0xff;
}


// ===== 0x00c5f4 mod_frag_c5f4 =====

/* Auto: compiler fragment: MOVLW #0x3 ; ADDWF INDF0,w,ACCESS ; BTFSC WREG,#0x3,ACCESS ; MOVWF
   INDF0,ACCESS ; MOVLW #0x30 ; ADDWF INDF0,w,ACCESS ; BTFSC WREG,#0x7,ACCESS ; MOVWF INDF0,ACCESS ;
   RETLW #0x0 */

undefined1 mod_frag_c5f4(void)

{
  return 0;
}


// ===== 0x00c606 task_heating =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 4 task: hot tank thermostat (normal/sleep/extra-hot), boil and fault detection */

void task_heating(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char *pcVar2;
  byte *pbVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  bool bVar7;
  bool bVar8;
  
code_c0x00c606:
  do {
    while( true ) {
      local1 = heating_read_param(1);
      *(undefined1 *)in_FSR1 = 0;
      puVar1 = (undefined1 *)((short)in_FSR1 + 2);
      *(undefined1 *)((short)in_FSR1 + 1) = local1;
      OSDelay();
      *puVar1 = *puVar1;
      in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
      puVar1[-1] = puVar1[-1];
      adc_raw_lo = 9;
      OS_Yield();
      cVar4 = cfg_application_b();
      if (cVar4 == '\0') {
        bVar5 = 0;
        goto LAB_CODE_00c878;
      }
      cVar4 = cfg_application_b();
      if (cVar4 != '\x03') break;
      hot_temp_top = 0x32;
      hot_temp_bottom = 0x32;
    }
    hot_temp_bottom = hot_temp_read_bottom();
    hot_temp_top = hot_temp_read_top();
    if (heating_fault == -0x73) {
      bVar5 = 0;
      goto LAB_CODE_00c878;
    }
    if (heating_fault == -0x72) {
      bVar5 = 0;
      goto LAB_CODE_00c878;
    }
    if (heating_fault + 'q' == '\0') {
      bVar5 = 0;
      goto LAB_CODE_00c878;
    }
    cVar4 = system_get_mode(heating_fault + 'q');
    if (cVar4 == '\x02') {
      bVar5 = 0x32;
      hot_temp_bottom = 0x32;
      hot_temp_top = 0x32;
      goto LAB_CODE_00c878;
    }
    cfg_heater_type();
    cVar4 = mod_return_0x01_fca0();
  } while (cVar4 == '\0');
  local0 = hot_temp_top;
  if (fault_code < '\0') {
joined_c0x00c694:
    bVar5 = heating_fault << 1 | 1;
    if (-1 < heating_fault) {
      heating_fault = fault_code;
    }
    goto LAB_CODE_00c878;
  }
  if (hot_temp_top == 0xff) {
LAB_CODE_00c6d8:
    heating_fault = -0x73;
    heater_off();
    uVar6 = 0x8d;
LAB_CODE_00c6f4:
    pcVar2 = (char *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = uVar6;
  }
  else {
    if (hot_temp_top == 0xfe) {
LAB_CODE_00c6ea:
      heating_fault = -0x71;
      heater_off();
      uVar6 = 0x8f;
      goto LAB_CODE_00c6f4;
    }
    cVar4 = heating_read_param(0x15);
    if (local0 < cVar4 + 2U) {
      if (fault_code < '\0') goto joined_c0x00c694;
      if (hot_temp_bottom == 0xff) goto LAB_CODE_00c6d8;
      if (hot_temp_bottom == 0xfe) goto LAB_CODE_00c6ea;
      cVar4 = heating_read_param(0x15);
      if (cVar4 + 2U <= hot_temp_bottom) goto LAB_CODE_00c704;
      local3 = heating_read_param(0x13);
      if (local3 + hot_temp_top <= hot_temp_bottom) {
        heater_off();
        if (-1 < heating_fault) {
          heating_fault = -0x76;
        }
        goto code_c0x00c606;
      }
      OS_Yield(hot_temp_bottom - (local3 + hot_temp_top));
      if ((extra_hot_timer == '\0') && ((heating_flags & 1) != 0)) {
        heating_cancel_extra_hot(0);
      }
      local0 = system_get_mode();
      local4 = heating_read_param(0x1d);
      bVar7 = local0 != 0;
      if (local0 != 1) {
        bVar5 = mod_get_hot_temp_top_ca00(local4);
        if ((bVar5 & 0x80) == 0) {
          bVar8 = *(byte *)in_FSR1 <= hot_temp_top;
          bVar5 = hot_temp_top - *(byte *)in_FSR1;
        }
        else {
          bVar8 = *(char *)in_FSR1 < '\0';
          bVar5 = *(char *)in_FSR1 << 1 | bVar7;
        }
        if ((bVar8) || (cVar4 = cfg_application_b(bVar5), cVar4 == '\x03')) {
          dispense_hot_allow();
        }
        if (heater_power_level != '\0') {
          bVar5 = mod_get_hot_temp_top_ca00(0x46);
          if ((bVar5 & 0x80) == 0) {
            bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
          }
          else {
            bVar7 = *(char *)in_FSR1 < '\0';
          }
          if (((bVar7) && ((heating_flags & 0x10) != 0)) && ((heating_flags & 2) == 0)) {
            boil_timer = 0;
            heating_flags = heating_flags | 2;
          }
        }
        bVar5 = mod_get_hot_temp_top_ca00(0x50);
        if ((bVar5 & 0x80) == 0) {
          bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
        }
        else {
          bVar7 = *(char *)in_FSR1 < '\0';
        }
        if ((bVar7) && ((heating_flags & 2) != 0)) {
          stat_H78 = boil_timer;
          uDATA00d7 = 0;
          uDATA00d8 = 0;
          uDATA00d9 = 0;
          pbVar3 = (byte *)((short)in_FSR1 + 1);
          *(undefined1 *)in_FSR1 = 9;
          stat_counter_save();
          in_FSR1 = (BADSPACEBASE *)(pbVar3 + -1);
          *pbVar3 = *pbVar3;
          heating_flags = heating_flags & 0xed;
        }
        local4 = heating_read_param(0x15);
        bVar7 = local4 != 0;
        portion_flow_lo = local4;
        bVar5 = mod_get_hot_temp_top_ca00(local4 - 1);
        if ((bVar5 & 0x80) == 0) {
          bVar8 = *(byte *)in_FSR1 <= hot_temp_top;
          bVar5 = hot_temp_top - *(byte *)in_FSR1;
        }
        else {
          bVar8 = *(char *)in_FSR1 < '\0';
          bVar5 = *(char *)in_FSR1 << 1 | bVar7;
        }
        if (!bVar8) {
          *(byte *)in_FSR1 = portion_flow_lo - 1;
          if (((portion_flow_lo - 1 ^ hot_temp_bottom) & 0x80) == 0) {
            bVar7 = *(byte *)in_FSR1 <= hot_temp_bottom;
            bVar5 = hot_temp_bottom - *(byte *)in_FSR1;
          }
          else {
            bVar7 = *(char *)in_FSR1 < '\0';
            bVar5 = *(char *)in_FSR1 << 1 | portion_flow_lo != 0;
          }
          if (!bVar7) {
            if ((heating_flags & 1) == 0) {
              uVar6 = 0x16;
            }
            else {
              uVar6 = 0x1b;
            }
            cVar4 = heating_read_param_tmp(uVar6);
            local4 = local4 - cVar4;
            if ((heating_flags & 1) == 0) {
              uVar6 = 0x2f;
            }
            else {
              uVar6 = 0x2e;
            }
            cVar4 = heating_read_param_tmp(uVar6);
            portion_flow_lo = portion_flow_lo - cVar4;
            goto LAB_CODE_00c84a;
          }
        }
joined_c0x00c822:
        if ((heating_flags & 1) != 0) {
          bVar5 = heating_cancel_extra_hot(bVar5);
        }
        heating_flags = heating_flags & 0xf7;
LAB_CODE_00c878:
        heater_off(bVar5);
        goto code_c0x00c606;
      }
      bVar5 = mod_get_hot_temp_top_ca00(local4);
      if ((bVar5 & 0x80) == 0) {
        bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
        bVar5 = hot_temp_top - *(byte *)in_FSR1;
      }
      else {
        bVar7 = *(char *)in_FSR1 < '\0';
        bVar5 = *(char *)in_FSR1 << 1 | 1;
      }
      if (!bVar7) {
        dispense_hot_block(bVar5);
      }
      local4 = heating_read_param(0x14);
      portion_flow_lo = local4;
LAB_CODE_00c84a:
      bVar5 = mod_get_hot_temp_top_ca00(local4);
      if ((bVar5 & 0x80) == 0) {
        bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
      }
      else {
        bVar7 = *(char *)in_FSR1 < '\0';
      }
      if (bVar7) {
        *(byte *)in_FSR1 = portion_flow_lo;
        if (((portion_flow_lo ^ hot_temp_bottom) & 0x80) == 0) {
          bVar7 = *(byte *)in_FSR1 <= hot_temp_bottom;
          bVar5 = hot_temp_bottom - *(byte *)in_FSR1;
        }
        else {
          bVar7 = *(char *)in_FSR1 < '\0';
          bVar5 = *(char *)in_FSR1 << 1 | 1;
        }
        if (bVar7) goto joined_c0x00c822;
      }
      local3 = heating_read_param(0x1c);
      local2 = 10;
      if (((heating_flags & 9) == 0) && (heater_power_level == '\0')) {
        if (local0 == 1) {
          uVar6 = 0x17;
        }
        else {
          uVar6 = 0x18;
        }
        cVar4 = heating_read_param_tmp(uVar6);
        bVar5 = mod_get_hot_temp_top_ca00(local4 - cVar4);
        if ((bVar5 & 0x80) == 0) {
          bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
        }
        else {
          bVar7 = *(char *)in_FSR1 < '\0';
        }
        if (bVar7) {
          if (local0 == 1) {
            uVar6 = 0x19;
          }
          else {
            uVar6 = 0x1a;
          }
          cVar4 = heating_read_param_tmp(uVar6);
          *(byte *)in_FSR1 = portion_flow_lo - cVar4;
          if (((portion_flow_lo - cVar4 ^ hot_temp_bottom) & 0x80) == 0) {
            bVar7 = *(byte *)in_FSR1 <= hot_temp_bottom;
          }
          else {
            bVar7 = *(char *)in_FSR1 < '\0';
          }
          if (bVar7) goto code_c0x00c606;
        }
      }
      pcVar2 = (char *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = local2;
      heater_set_power();
      goto LAB_CODE_00c8e0;
    }
LAB_CODE_00c704:
    heating_fault = -0x72;
    heater_off();
    pcVar2 = (char *)((short)in_FSR1 + 1);
    *(char *)in_FSR1 = heating_fault;
  }
  heater_set_fault();
LAB_CODE_00c8e0:
  in_FSR1 = (BADSPACEBASE *)(pcVar2 + -1);
  *pcVar2 = *pcVar2;
  goto code_c0x00c606;
}


// ===== 0x00c8e4 heating_init =====

/* Initialise heating state */

undefined1 heating_init(void)

{
  heating_flags = 8;
  heating_fault = 0;
  heating_startup_timer = heating_read_param(0x27);
  return 0;
}


// ===== 0x00c8f6 heating_create_task =====

/* Create task_heating (TCB 0x80) */

undefined1 heating_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  mod_push_args_80_00_ca12();
  *puVar1 = 6;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xc6;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}


// ===== 0x00c91a heating_start_task =====

/* Start task_heating */

undefined1 heating_start_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_80_00_ca12();
  OSStartTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}


// ===== 0x00c926 heating_stop_task =====

/* Stop task_heating */

undefined1 heating_stop_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_80_00_ca12();
  OSStopTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}


// ===== 0x00c932 mod_to_hot_temp_read_top_c932 =====

/* Auto: calls hot_temp_read_top; 1 instr */

void mod_to_hot_temp_read_top_c932(void)

{
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  
  puVar1 = &FramePointer10x0001;
  hot_temp_read();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00c936 heating_request_extra_hot =====

/* Start extra-hot mode (if allowed); load TEMPHOTCHNGTIME */

undefined1 heating_request_extra_hot(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  byte unaff_Z;
  
  cfg_heater_type();
  if ((unaff_Z & 1) != 0) {
    return 0;
  }
  if ((heating_flags & 1) != 0) {
    return 0;
  }
  cVar2 = heater_is_ready();
  if (cVar2 == '\0') {
    return 0;
  }
  if (heating_fault != -0x73) {
    if (heating_fault != -0x72) {
      if (heating_fault != -0x71) {
        puVar1 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 5;
        stat_counter_inc();
        *puVar1 = *puVar1;
        puVar1[-1] = 5;
        stat_counter_save();
        *puVar1 = *puVar1;
        extra_hot_timer = heating_read_param(0x27);
        heating_flags = heating_flags | 1;
        return 1;
      }
    }
  }
  return 0;
}


// ===== 0x00c982 heating_is_extra_hot =====

/* Return extra-hot flag */

byte heating_is_extra_hot(void)

{
  return heating_flags & 1;
}


// ===== 0x00c98a heating_cancel_extra_hot =====

/* Clear extra-hot flag */

void heating_cancel_extra_hot(void)

{
  heating_flags = heating_flags & 0xfe;
  return;
}


// ===== 0x00c990 heating_boil_timer_tick =====

/* Per second: count boil timer while boil detection active */

void heating_boil_timer_tick(void)

{
  if ((heating_flags & 2) != 0) {
    boil_timer = boil_timer + '\x01';
  }
  return;
}


// ===== 0x00c998 heating_timers_10s =====

/* Every 10 s: count down heating timers */

char heating_timers_10s(void)

{
  char cVar1;
  
  if (heating_startup_timer != '\0') {
    heating_startup_timer = heating_startup_timer + -1;
  }
  cVar1 = -extra_hot_timer;
  if (extra_hot_timer != '\0') {
    extra_hot_timer = extra_hot_timer + -1;
  }
  return cVar1;
}


// ===== 0x00c9aa heating_minute_tick =====

/* Every minute (empty) */

void heating_minute_tick(void)

{
  return;
}


// ===== 0x00c9ac heating_restart_extra_hot_timer =====

/* Reload extra-hot timeout while extra-hot active */

void heating_restart_extra_hot_timer(void)

{
  if ((heating_flags & 1) != 0) {
    extra_hot_timer = heating_read_param(0x27);
  }
  return;
}


// ===== 0x00c9bc heating_get_state =====

/* Heating system state: 0 sleep, 1 normal, 2 extra-hot, 3 delay, 4 no heater */

undefined1 heating_get_state(void)

{
  char cVar1;
  byte unaff_Z;
  
  cfg_heater_type();
  if ((unaff_Z & 1) != 0) {
    return 4;
  }
  cVar1 = heater_get_powerup_delay();
  if (cVar1 != '\0') {
    return 3;
  }
  cVar1 = system_get_mode(0);
  if (cVar1 != '\x02') {
    cVar1 = system_get_mode();
    if (cVar1 != '\x01') {
      if ((heating_flags & 1) != 0) {
        return 2;
      }
      return 1;
    }
  }
  return 0;
}


// ===== 0x00c9e6 heating_read_param =====

/* eeprom_read_param wrapper for heating module */

void heating_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00c9f0 cfg_application_b =====

/* APPLICATION setting (copy in heating module) */

byte cfg_application_b(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}


// ===== 0x00ca00 mod_get_hot_temp_top_ca00 =====

/* Auto: reads hot_temp_top; 4 instr */

byte mod_get_hot_temp_top_ca00(byte param_1)

{
  return param_1 ^ hot_temp_top;
}


// ===== 0x00ca08 cfg_heater_type =====

/* cfg_systemconfig & 3 (0 = no heater fitted) */

byte cfg_heater_type(void)

{
  return cfg_systemconfig & 3;
}


// ===== 0x00ca12 mod_push_args_80_00_ca12 =====

/* Auto: Push constant arguments [128, 0]; 5 instr */

undefined1 mod_push_args_80_00_ca12(void)

{
  return 0;
}


// ===== 0x00ca1c heating_read_param_tmp =====

/* heating_read_param into tmp 0x27 */

undefined1 heating_read_param_tmp(void)

{
  local3 = heating_read_param();
  return local3;
}


// ===== 0x00ca24 mod_get_lcd_text_width_ca24 =====

/* Auto: reads lcd_text_width,TABLAT; 11 instr */

void mod_get_lcd_text_width_ca24(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 in_TABLAT;
  
  mod_set_lcd_text_width_cd74();
  while( true ) {
    bVar2 = mod_to_mod_get_TBLPTRH_cdec();
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
    if ((bVar2 & 0xf) <= bVar1) break;
    mod_get_c18_tmp0_cd58();
    mod_set_lcd_text_width_cdac(in_TABLAT);
  }
  *(undefined1 *)in_FSR1 = 0;
  mod_to_lcd_write_data_ce1e(bVar1 - (bVar2 & 0xf));
  return;
}


// ===== 0x00ca3a mod_get_lcd_text_width_ca3a =====

/* Auto: reads lcd_text_width,TABLAT; 11 instr */

void mod_get_lcd_text_width_ca3a(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  byte in_TABLAT;
  
  mod_set_lcd_text_width_cd74();
  while( true ) {
    bVar2 = mod_to_mod_get_TBLPTRH_cdec();
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
    if ((bVar2 & 0xf) <= bVar1) break;
    mod_get_c18_tmp0_cd58();
    mod_set_lcd_text_width_cdac(~in_TABLAT);
  }
  *(undefined1 *)in_FSR1 = 0xff;
  mod_to_lcd_write_data_ce1e(bVar1 - (bVar2 & 0xf));
  return;
}


// ===== 0x00ca50 mod_get_lcd_text_width_ca50 =====

/* Auto: reads lcd_text_width,TABLAT; 12 instr */

void mod_get_lcd_text_width_ca50(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  byte in_TABLAT;
  
  mod_set_lcd_text_width_cd74();
  while( true ) {
    mod_to_mod_get_TBLPTRH_cdec();
    bVar2 = mod_frag_cda0();
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
    if (bVar2 <= bVar1) break;
    mod_get_c18_tmp0_cd7c();
    mod_get_TBLPTRL_cdf4();
    mod_set_lcd_text_width_cdac(~in_TABLAT);
  }
  *(undefined1 *)in_FSR1 = 0xff;
  mod_to_lcd_write_data_ce1e(bVar1 - bVar2);
  return;
}


// ===== 0x00ca68 mod_set_lcd_text_flag_ca68 =====

/* WARNING: Removing unreachable block (CODE,0x00ca74) */
/* Auto: writes lcd_text_flag; 10 instr */

void mod_set_lcd_text_flag_ca68(void)

{
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    mod_get_lcd_text_flag_ccf2();
  }
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00ca7c mod_set_lcd_text_flag_ca7c =====

/* WARNING: Removing unreachable block (CODE,0x00ca88) */
/* Auto: writes lcd_text_flag; 10 instr */

void mod_set_lcd_text_flag_ca7c(void)

{
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    mod_get_lcd_text_flag_ccf2();
  }
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00ca90 mod_set_lcd_text_flag_ca90 =====

/* WARNING: Removing unreachable block (CODE,0x00ca9c) */
/* Auto: writes lcd_text_flag; 10 instr */

void mod_set_lcd_text_flag_ca90(void)

{
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    mod_get_lcd_text_flag_cde4();
  }
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00caa4 mod_set_lcd_text_flag_caa4 =====

/* WARNING: Removing unreachable block (CODE,0x00cab0) */
/* Auto: writes lcd_text_flag; 10 instr */

void mod_set_lcd_text_flag_caa4(void)

{
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    mod_get_lcd_text_flag_cde4();
  }
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00cab8 mod_set_lcd_text_flag_cab8 =====

/* Auto: writes lcd_text_flag; 14 instr */

void mod_set_lcd_text_flag_cab8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  byte unaff_Z;
  bool bVar3;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = '\0';
    bVar3 = true;
    while( true ) {
      mod_get_lcd_text_flag_ccf2();
      if (bVar3) break;
      uVar2 = mod_get_lcd_text_flag_ccf2();
      puVar1 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = uVar2;
      mod_get_lcd_text_width_ca50();
      in_FSR1 = (BADSPACEBASE *)(puVar1 + -1);
      *puVar1 = *puVar1;
      lcd_text_flag = lcd_text_flag + '\x01';
      bVar3 = lcd_text_flag == '\0';
    }
  }
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00cad4 mod_set_lcd_text_flag_cad4 =====

/* WARNING: Removing unreachable block (CODE,0x00cae6) */
/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 14 instr */

void mod_set_lcd_text_flag_cad4(void)

{
  undefined1 uVar1;
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    lcd_text_width = 0;
    mod_get_lcd_text_flag_ccf2();
    uVar1 = lcd_text_width;
  }
  else {
    uVar1 = 0;
  }
  mod_c18_epilogue_cd24(uVar1);
  return;
}


// ===== 0x00caf0 mod_set_lcd_text_flag_caf0 =====

/* WARNING: Removing unreachable block (CODE,0x00cb02) */
/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 14 instr */

void mod_set_lcd_text_flag_caf0(void)

{
  undefined1 uVar1;
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    lcd_text_width = 0;
    mod_get_lcd_text_flag_cde4();
    uVar1 = lcd_text_width;
  }
  else {
    uVar1 = 0;
  }
  mod_c18_epilogue_cd24(uVar1);
  return;
}


// ===== 0x00cb0c mod_set_lcd_text_flag_cb0c =====

/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 18 instr */

void mod_set_lcd_text_flag_cb0c(void)

{
  char cVar1;
  byte unaff_Z;
  bool bVar2;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = '\0';
    lcd_text_width = '\0';
    bVar2 = true;
    while (mod_get_lcd_text_flag_ccf2(), cVar1 = lcd_text_width, !bVar2) {
      mod_get_lcd_text_flag_ccf2();
      mod_get_TBLPTRH_cd48();
      cVar1 = mod_frag_cda0();
      lcd_text_flag = lcd_text_flag + '\x01';
      lcd_text_width = lcd_text_width + cVar1 + '\x01';
      bVar2 = lcd_text_width == '\0';
    }
  }
  else {
    cVar1 = '\0';
  }
  mod_c18_epilogue_cd24(cVar1);
  return;
}


// ===== 0x00cb30 text_copy_rom =====

/* Copy ROM text to buffer */

void text_copy_rom(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  BADSPACEBASE *in_FSR2;
  char *pcVar4;
  char *pcVar5;
  BADSPACEBASE *in_FSR1;
  byte bVar6;
  undefined1 *in_TBLPTR;
  bool bVar7;
  
  mod_c18_prologue_cdd2();
  while( true ) {
    c18_tmp0 = *(char *)((short)in_FSR2 + -7);
    bVar7 = *(char *)((short)in_FSR2 + -5) != '\0';
    *(char *)((short)in_FSR2 + -6) = *(char *)((short)in_FSR2 + -5) + -1;
    pcVar4 = (char *)((short)in_FSR2 + 4);
    c18_tmp1 = *(byte *)((short)in_FSR2 + -3);
    if (!bVar7) {
      pcVar4 = (char *)((short)in_FSR2 + 6);
      bVar7 = *(char *)((short)in_FSR2 + -1) != '\0';
      *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + -1;
    }
    bVar6 = c18_tmp1 << 1 | bVar7;
    if ((char)c18_tmp1 < '\0') break;
    bVar1 = ~(c18_tmp0 == '\0');
    bVar6 = -~(c18_tmp0 == '\0') - c18_tmp1;
    if (bVar1 != 0 || c18_tmp1 < -bVar1) break;
    pcVar4[-4] = pcVar4[-3] + '\x01';
    pcVar5 = pcVar4 + 4;
    in_TBLPTR = (undefined1 *)
                CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(pcVar4[-1],pcVar4[-5]));
    if (pcVar4[-3] == -1) {
      pcVar5 = pcVar4 + 6;
      *pcVar4 = pcVar4[1] + '\x01';
    }
    *(undefined1 *)in_FSR1 = *in_TBLPTR;
    uVar2 = pcVar5[-3];
    pcVar5[-2] = pcVar5[-1] + '\x01';
    in_FSR2 = (BADSPACEBASE *)(pcVar5 + 4);
    uVar3 = pcVar5[1];
    if (pcVar5[-1] == -1) {
      in_FSR2 = (BADSPACEBASE *)(pcVar5 + 6);
      pcVar5[2] = pcVar5[3] + '\x01';
    }
    *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)CONCAT11(uVar3,uVar2) = *(undefined1 *)in_FSR1;
  }
  mod_c18_epilogue_cd24(bVar6);
  return;
}


// ===== 0x00cb86 text_measure_width =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Measure pixel width of a text line */

void text_measure_width(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar8;
  bool bVar9;
  
  bVar8 = mod_set_lcd_text_flag_cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      mod_set_lcd_text_flag_ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = mod_get_TBLPTRH_cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        mod_get_TBLPTRH_cd48(puVar5[2]);
        bVar8 = mod_frag_cda0();
      }
      unaff_BSR = 1;
      lcd_text_width = lcd_text_width + bVar8;
LAB_CODE_00cbde:
      cVar4 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = cVar4;
      bVar9 = cVar4 == '\0';
      puVar5 = puVar6;
    }
    if (puVar5[1] == '\n') break;
    if (puVar5[1] != '\b') {
      bVar8 = 0;
      puVar6 = puVar5 + 1;
      if ((puVar5[1] != '\r') && (bVar8 = 0, puVar6 = puVar5 + 1, puVar5[1] != '\t'))
      goto LAB_CODE_00cbc6;
      goto LAB_CODE_00cbde;
    }
    bVar8 = 0xfb;
    bVar1 = puVar5[-3];
    puVar5[-3] = ~(bVar1 & 1) | bVar1 & 0xfe;
    bVar9 = true;
    puVar5 = puVar5 + 2;
  } while( true );
  if ((puVar5[-3] & 0x10) != 0) {
LAB_CODE_00cbe2:
    if (*(byte *)((ushort)unaff_BSR * 0x100 + 0xe9) < *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7)) {
      lcd_text_maxwidth = lcd_text_width;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    mod_c18_epilogue_cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    lcd_text_maxwidth = lcd_text_width;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}


// ===== 0x00cbf2 mod_set_lcd_text_maxwidth_cbf2 =====

/* Auto: writes lcd_text_maxwidth; reads lcd_text_maxwidth; 13 instr */

void mod_set_lcd_text_maxwidth_cbf2(void)

{
  undefined1 uVar1;
  char cVar2;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  char cVar3;
  byte unaff_Z;
  
  mod_set_lcd_text_flag_cd96();
  cVar3 = '\x01';
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 1;
  while( true ) {
    mod_set_lcd_text_flag_ce04(cVar3);
    if ((unaff_Z & 1) != 0) break;
    cVar3 = *(char *)in_FSR2 + -10;
    unaff_Z = 0;
    if (cVar3 == '\0') {
      cVar2 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe9) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe9) = cVar2;
      unaff_Z = cVar2 == '\0';
    }
  }
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  mod_c18_epilogue_cd24(uVar1);
  return;
}


// ===== 0x00cc0c mod_to_text_measure_width_cc0c =====

/* Auto: calls text_measure_width; 14 instr */

void mod_to_text_measure_width_cc0c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  mod_c18_prologue_cdd2();
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -4) | 0x10;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  pbVar1 = (byte *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)in_FSR2;
  text_measure_width();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00cc2c mod_set_text_x_adjust_cc2c =====

/* Auto: writes text_x_adjust; reads text_x_adjust,text_width_saved; 22 instr */

void mod_set_text_x_adjust_cc2c(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  bool bVar4;
  
  mod_c18_prologue_cdd2();
  if ((*(byte *)((short)in_FSR2 + -2) & 0x20) != 0) {
    c18_tmp0 = text_x_adjust;
    bVar1 = text_x_adjust + 1;
    bVar4 = (char)text_x_adjust < '\0';
    bVar3 = text_x_adjust << 1 | 0xfe < text_x_adjust;
    text_x_adjust = bVar1;
    if ((bVar4) || (bVar3 = bVar1 - text_width_saved, text_width_saved <= bVar1))
    goto LAB_CODE_00cc58;
  }
  if ((*(byte *)((short)in_FSR2 + -1) & 0x80) == 0) {
    *(undefined1 *)in_FSR1 = 0;
  }
  else {
    *(undefined1 *)in_FSR1 = 0xff;
  }
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  bVar3 = lcd_write_data();
  *puVar2 = *puVar2;
LAB_CODE_00cc58:
  mod_c18_epilogue_cd24(bVar3);
  return;
}


// ===== 0x00cc5a text_render_glyphs =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Render text glyphs to the LCD */

void text_render_glyphs(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  BADSPACEBASE *in_FSR1;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  char cVar10;
  byte *in_TBLPTR;
  undefined2 uVar12;
  undefined3 uVar11;
  bool bVar13;
  
  mod_c18_prologue_cdd2();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if ((*(byte *)((short)in_FSR2 + -3) & 1) == 0) {
    bVar9 = mod_to_mod_get_TBLPTRH_cdec();
    lcd_text_maxwidth = bVar9 & 0xf;
  }
  else {
    mod_to_mod_get_TBLPTRH_cdec();
    lcd_text_maxwidth = mod_frag_cda0();
    puVar2 = puVar1;
  }
  lcd_text_width = 0;
  pbVar3 = puVar2;
  do {
    uVar12 = (undefined2)((uint3)in_TBLPTR >> 8);
    if (lcd_text_maxwidth <= lcd_text_width) {
      pbVar8 = (byte *)((short)in_FSR1 + 1);
      *(byte *)in_FSR1 = pbVar3[-3];
      mod_set_text_x_adjust_cc2c();
      *pbVar8 = *pbVar8;
      mod_c18_epilogue_cd24();
      return;
    }
    if ((pbVar3[-3] & 0x20) == 0) {
LAB_CODE_00cc90:
      pbVar4 = pbVar3 + 2;
      if ((pbVar3[-2] & 1) == 0) {
        pbVar4 = pbVar3 + 3;
        bVar9 = (byte)((ushort)*pbVar3 * 5);
        c18_tmp2 = bVar9 - 0x20;
        c18_tmp3 = (char)((ushort)*pbVar3 * 5 >> 8) + 'z' + (0x1f < bVar9);
        uVar11 = CONCAT21(uVar12,c18_tmp2 + lcd_text_width);
        cVar10 = c18_tmp3 + CARRY1(c18_tmp2,lcd_text_width);
      }
      else {
        bVar9 = mod_get_c18_tmp0_cd7c();
        uVar11 = CONCAT21(uVar12,c18_tmp0 + bVar9);
        cVar10 = c18_tmp1 + CARRY1(c18_tmp0,bVar9);
      }
      in_TBLPTR = (byte *)CONCAT12((char)((uint3)uVar11 >> 0x10),CONCAT11(cVar10,(char)uVar11));
      lcd_text_flag = *in_TBLPTR;
      puVar5 = pbVar4 + 1;
      if ((pbVar4[-3] & 0x80) != 0) {
        lcd_text_flag = ~lcd_text_flag;
      }
      pbVar7 = (byte *)((short)in_FSR1 + 1);
      *(byte *)in_FSR1 = lcd_text_flag;
      lcd_write_data();
      in_FSR1 = (BADSPACEBASE *)(pbVar7 + -1);
      *pbVar7 = *pbVar7;
      pbVar6 = puVar5;
    }
    else {
      c18_tmp0 = text_x_adjust;
      bVar9 = text_x_adjust + 1;
      bVar13 = -1 < (char)text_x_adjust;
      pbVar6 = pbVar3 + 1;
      text_x_adjust = bVar9;
      if ((bVar13) && (pbVar6 = pbVar3 + 1, bVar9 < text_width_saved)) goto LAB_CODE_00cc90;
    }
    lcd_text_width = lcd_text_width + 1;
    pbVar3 = pbVar6;
  } while( true );
}


// ===== 0x00ccf2 mod_get_lcd_text_flag_ccf2 =====

/* Auto: reads lcd_text_flag,TBLPTRL,TBLPTRH,TABLAT; 13 instr */

undefined1 mod_get_lcd_text_flag_ccf2(void)

{
  byte bVar1;
  byte unaff_BSR;
  undefined3 in_TBLPTR;
  byte in_FramePointer2_0000fffd;
  char in_FramePointer2_0000ffff;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe8);
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(in_FramePointer2_0000ffff + CARRY1(in_FramePointer2_0000fffd,bVar1),
                            in_FramePointer2_0000fffd + bVar1));
}


// ===== 0x00cd10 mod_calc_array_ptr_cd10 =====

/* Auto: Compute array element address in FSR0; 10 instr */

byte mod_calc_array_ptr_cd10(void)

{
  byte in_FSR1L;
  char in_FSR1H;
  byte *pbVar1;
  
  mod_c18_prologue_cdd2();
  pbVar1 = (byte *)CONCAT11(in_FSR1H + -1 + (3 < in_FSR1L),in_FSR1L - 4);
  return pbVar1[1] | *pbVar1;
}


// ===== 0x00cd24 mod_c18_epilogue_cd24 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_cd24(void)

{
  return;
}


// ===== 0x00cd30 mod_frame_access_cd30 =====

/* Auto: Access stack-frame local/argument; 10 instr */

undefined1 mod_frame_access_cd30(void)

{
  return 0;
}


// ===== 0x00cd48 mod_get_TBLPTRH_cd48 =====

/* Auto: reads TBLPTRH,TBLPTRL,TABLAT; 8 instr */

undefined1 mod_get_TBLPTRH_cd48(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11((0x1f < param_1) + -0x7a,param_1 - 0x20));
}


// ===== 0x00cd58 mod_get_c18_tmp0_cd58 =====

/* Auto: reads c18_tmp0,c18_tmp1,lcd_text_width; 11 instr */

void mod_get_c18_tmp0_cd58(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte in_FramePointer2_0000fffe;
  
  bVar1 = (byte)((ushort)in_FramePointer2_0000fffe * 5);
  c18_tmp0 = bVar1 - 0x20;
  c18_tmp1 = (char)((ushort)in_FramePointer2_0000fffe * 5 >> 8) + 'z' + (0x1f < bVar1);
  mod_get_TBLPTRL_cdf4(*(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7));
  return;
}


// ===== 0x00cd74 mod_set_lcd_text_width_cd74 =====

/* Auto: writes lcd_text_width; 4 instr */

void mod_set_lcd_text_width_cd74(void)

{
  mod_c18_prologue_cdd2();
  lcd_text_width = 0;
  return;
}


// ===== 0x00cd7c mod_get_c18_tmp0_cd7c =====

/* Auto: reads c18_tmp0,c18_tmp1,lcd_text_width; 11 instr */

undefined1 mod_get_c18_tmp0_cd7c(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte in_FramePointer2_0000fffe;
  
  bVar1 = (byte)((ushort)in_FramePointer2_0000fffe * 7);
  c18_tmp0 = bVar1 - 0x20;
  c18_tmp1 = (char)((ushort)in_FramePointer2_0000fffe * 7 >> 8) + '\x7f' + (0x1f < bVar1);
  return *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7);
}


// ===== 0x00cd96 mod_set_lcd_text_flag_cd96 =====

/* Auto: writes lcd_text_flag; 5 instr */

void mod_set_lcd_text_flag_cd96(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_c18_prologue_cdd2();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  lcd_text_flag = 0;
  return;
}


// ===== 0x00cda0 mod_frag_cda0 =====

/* Auto: compiler fragment: ANDLW #0xf0 ; RRNCF WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RRNCF
   WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RETURN 0x0 */

byte mod_frag_cda0(byte param_1)

{
  return param_1 >> 4;
}


// ===== 0x00cdac mod_set_lcd_text_width_cdac =====

/* Auto: writes lcd_text_width; 6 instr */

void mod_set_lcd_text_width_cdac(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  lcd_text_width = lcd_text_width + '\x01';
  return;
}


// ===== 0x00cdba mod_set_lcd_text_flag_cdba =====

/* Auto: writes lcd_text_flag; 6 instr */

void mod_set_lcd_text_flag_cdba(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_get_lcd_text_width_ca24();
  *puVar1 = *puVar1;
  lcd_text_flag = lcd_text_flag + '\x01';
  return;
}


// ===== 0x00cdc6 mod_set_lcd_text_flag_cdc6 =====

/* Auto: writes lcd_text_flag; 6 instr */

void mod_set_lcd_text_flag_cdc6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_get_lcd_text_width_ca3a();
  *puVar1 = *puVar1;
  lcd_text_flag = lcd_text_flag + '\x01';
  return;
}


// ===== 0x00cdd2 mod_c18_prologue_cdd2 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_cdd2(void)

{
  return;
}


// ===== 0x00cde4 mod_get_lcd_text_flag_cde4 =====

/* Auto: reads lcd_text_flag; 4 instr */

undefined1 mod_get_lcd_text_flag_cde4(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR0;
  
  mod_frame_access_cd30(*(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe8));
  return *(undefined1 *)in_FSR0;
}


// ===== 0x00cdec mod_to_mod_get_TBLPTRH_cdec =====

/* Auto: Small wrapper around mod_get_TBLPTRH; 3 instr */

void mod_to_mod_get_TBLPTRH_cdec(void)

{
  undefined1 in_FramePointer2_0000fffe;
  
  mod_get_TBLPTRH_cd48(in_FramePointer2_0000fffe);
  return;
}


// ===== 0x00cdf4 mod_get_TBLPTRL_cdf4 =====

/* Auto: reads TBLPTRL,TBLPTRH; 8 instr */

char mod_get_TBLPTRL_cdf4(byte param_1)

{
  return c18_tmp1 + CARRY1(c18_tmp0,param_1);
}


// ===== 0x00ce04 mod_set_lcd_text_flag_ce04 =====

/* Auto: writes lcd_text_flag; reads lcd_text_flag; 6 instr */

undefined1 mod_set_lcd_text_flag_ce04(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR0;
  
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) + '\x01'
  ;
  mod_frame_access_cd30(uVar1);
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR0;
  return *(undefined1 *)in_FSR2;
}


// ===== 0x00ce12 mod_set_lcd_text_flag_ce12 =====

/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 6 instr */

void mod_set_lcd_text_flag_ce12(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  bVar1 = mod_get_TBLPTRH_cd48();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + (bVar1 & 0xf);
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) + '\x01'
  ;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01'
  ;
  return;
}


// ===== 0x00ce1e mod_to_lcd_write_data_ce1e =====

/* Auto: Small wrapper around lcd_write_data; 3 instr */

void mod_to_lcd_write_data_ce1e(void)

{
  BADSPACEBASE *in_FSR1;
  
  lcd_write_data();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  mod_c18_epilogue_cd24();
  return;
}


// ===== 0x00ce26 lcd_delay =====

/* WARNING: Instruction at (CODE,0x00ce3a) overlaps instruction at (CODE,0x00ce38)
    */
/* Short busy-wait delay for the LCD controller */

undefined1 lcd_delay(void)

{
  char cVar1;
  
  for (lcd_delay_counter = 'F'; lcd_delay_counter != '\0';
      lcd_delay_counter = lcd_delay_counter + -1) {
    cVar1 = '<';
    do {
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
  }
  return 0;
}


// ===== 0x00ce44 lcd_init =====

/* WARNING: Instruction at (CODE,0x00ce50) overlaps instruction at (CODE,0x00ce4e)
    */
/* Reset and initialise the 128x64 graphic LCD controller */

undefined1 lcd_init(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  
  bVar1 = TRISE;
  TRISE = bVar1 & (TRISE6 | TRISE7);
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE4;
  cVar5 = '\x04';
  do {
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  cVar5 = '\x04';
  do {
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  bVar1 = PORTE;
  PORTE = bVar1 | RE4;
  lcd_delay();
  bVar1 = TRISE;
  TRISE = bVar1 & (TRISE6 | TRISE7);
  TRISD = 0;
  bVar1 = PORTE;
  PORTE = bVar1 | RE5;
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE0;
  bVar1 = PORTE;
  PORTE = bVar1 | RE1;
  bVar1 = PORTE;
  PORTE = bVar1 | RE2;
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0xe2;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa3;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x2f;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x25;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x81;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x3f;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa0;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xc0;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x40;
  lcd_write_cmd();
  puVar3 = puVar2 + -1;
  *puVar2 = *puVar2;
  lcd_delay();
  lcd_delay();
  puVar4 = puVar3 + 1;
  *puVar3 = 0xa4;
  lcd_write_cmd();
  *puVar4 = *puVar4;
  puVar4[-1] = 0xaf;
  lcd_write_cmd();
  *puVar4 = *puVar4;
  return 0;
}


// ===== 0x00cece lcd_write_cmd =====

/* Write a command byte to the LCD (RE3=0) */

undefined1 lcd_write_cmd(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE3;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE5;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE2;
  uVar1 = *(undefined1 *)
           (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  PORTD = uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE2;
  bVar2 = PORTE;
  PORTE = bVar2 | RE5;
  return uVar1;
}


// ===== 0x00cefe lcd_write_data =====

/* Write a display data byte to the LCD (RE3=1) */

undefined1 lcd_write_data(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 | RE3;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE5;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE2;
  uVar1 = *(undefined1 *)
           (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  PORTD = uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE2;
  bVar2 = PORTE;
  PORTE = bVar2 | RE5;
  return uVar1;
}


// ===== 0x00cf2e lcd_puts_rom =====

/* Draw a ROM string on the LCD */

void lcd_puts_rom(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char cVar3;
  char *in_TBLPTR;
  undefined1 uVar4;
  
  mod_c18_prologue_d11e();
  do {
    *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + '\x01';
    puVar1 = (undefined1 *)((short)in_FSR2 + 4);
    uVar4 = (undefined1)((uint3)in_TBLPTR >> 0x10);
    in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(*(undefined1 *)((short)in_FSR2 + 1),
                                                *(undefined1 *)((short)in_FSR2 + -3)));
    if (*(char *)((short)in_FSR2 + -1) == -1) {
      puVar1 = (undefined1 *)((short)in_FSR2 + 6);
      *(char *)((short)in_FSR2 + 2) = *(char *)((short)in_FSR2 + 3) + '\x01';
    }
    lcd_delay_counter = *in_TBLPTR;
    if (lcd_delay_counter == '\0') {
      in_FSR2 = (BADSPACEBASE *)(puVar1 + 2);
      in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(puVar1[-1],puVar1[-3]));
      cVar3 = *in_TBLPTR;
      if (cVar3 == '\0') {
        mod_c18_epilogue_d130(0);
        return;
      }
      *(undefined1 *)in_FSR1 = 0;
    }
    else {
      *(char *)in_FSR1 = lcd_delay_counter;
      in_FSR2 = (BADSPACEBASE *)puVar1;
      cVar3 = lcd_delay_counter;
    }
    pcVar2 = (char *)((short)in_FSR1 + 1);
    lcd_write_data(cVar3);
    in_FSR1 = (BADSPACEBASE *)(pcVar2 + -1);
    *pcVar2 = *pcVar2;
  } while( true );
}


// ===== 0x00cf6e mod_set_lcd_delay_counter_cf6e =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes lcd_delay_counter; reads lcd_delay_counter; 14 instr */

void mod_set_lcd_delay_counter_cf6e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  
  mod_c18_prologue_d11e();
  lcd_delay_counter = *(char *)((short)in_FSR2 + -3);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  while( true ) {
    if (lcd_delay_counter == '\0') break;
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    puVar2 = puVar1 + 1;
    *(undefined1 *)in_FSR1 = puVar1[-2];
    lcd_delay_counter = lcd_delay_counter + -1;
    lcd_write_data();
    in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
    *puVar3 = *puVar3;
    puVar1 = puVar2;
  }
  lcd_delay_counter = lcd_delay_counter + -1;
  mod_c18_epilogue_d130(0);
  return;
}


// ===== 0x00cf8e lcd_read_data =====

/* Read a display data byte from the LCD */

undefined1 lcd_read_data(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = (TRISD0 | TRISD1 | TRISD2 | TRISD3 | TRISD4 | TRISD5 | TRISD6 | TRISD7);
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE3;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE5;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE1;
  uVar1 = PORTD;
  *(undefined1 *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) =
       uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE5;
  return uVar1;
}


// ===== 0x00cfc6 mod_to_mod_to_lcd_write_cmd_cfc6 =====

/* Auto: Small wrapper around mod_to_lcd_write_cmd; 8 instr */

void mod_to_mod_to_lcd_write_cmd_cfc6(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  bVar2 = mod_frame_access_d16c();
  mod_to_lcd_write_cmd_d15c(bVar2 | 0xb0);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  mod_to_mod_to_lcd_write_cmd_cfd8();
  *puVar1 = *puVar1;
  mod_c18_epilogue_d130();
  return;
}


// ===== 0x00cfd8 mod_to_mod_to_lcd_write_cmd_cfd8 =====

/* Auto: Small wrapper around mod_to_lcd_write_cmd; 11 instr */

void mod_to_mod_to_lcd_write_cmd_cfd8(void)

{
  BADSPACEBASE *in_FSR2;
  byte bVar1;
  
  bVar1 = mod_frame_access_d16c();
  mod_to_lcd_write_cmd_d15c(bVar1 >> 4 | 0x10);
  mod_to_lcd_write_cmd_d15c(*(byte *)((short)in_FSR2 + -2) & 0xf);
  mod_c18_epilogue_d130();
  return;
}


// ===== 0x00cfee lcd_clear =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Clear the LCD (all pages) */

void lcd_clear(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  lcd_page_counter = 0;
  while( true ) {
    if (7 < lcd_page_counter) break;
    pbVar1 = (byte *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
    *pbVar1 = lcd_page_counter;
    mod_stack_adjust_d154('\a' - lcd_page_counter);
    mod_set_lcd_page_counter_d144(0x80);
  }
  return;
}


// ===== 0x00d008 lcd_draw_glyph =====

/* Draw one font glyph column set */

void lcd_draw_glyph(void)

{
  BADSPACEBASE *in_FSR2;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  BADSPACEBASE *in_FSR1;
  char *pcVar4;
  byte bVar5;
  char cVar6;
  
  bVar5 = mod_frame_access_d16c();
  cVar6 = '\a' - bVar5;
  if (bVar5 < 8) {
    cVar6 = '\x7f' - *(byte *)((short)in_FSR2 + -4);
    if (*(byte *)((short)in_FSR2 + -4) < 0x80) {
      *(char *)in_FSR1 = *(char *)((short)in_FSR2 + -2);
      pcVar1 = (char *)((short)in_FSR2 + 3);
      cVar6 = *(char *)in_FSR2;
      *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
      if (8 < (byte)(*(char *)in_FSR1 + cVar6)) {
        *(char *)in_FSR1 = *(char *)((short)in_FSR2 + 1);
        *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = '\t' - *(char *)in_FSR1;
        pcVar1 = (char *)((short)in_FSR2 + 5);
        *(char *)((short)in_FSR2 + 1) = *(char *)in_FSR1;
      }
      *(char *)in_FSR1 = pcVar1[-5];
      pcVar3 = pcVar1 + 2;
      cVar6 = pcVar1[-3];
      *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
      if (0x7f < (byte)(*(char *)in_FSR1 + cVar6)) {
        *(char *)in_FSR1 = pcVar1[-2];
        *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = -0x7f - *(char *)in_FSR1;
        pcVar3 = pcVar1 + 4;
        pcVar1[-2] = *(undefined1 *)in_FSR1;
      }
      lcd_page_counter = 0;
      while( true ) {
        cVar6 = lcd_page_counter - pcVar3[-3];
        if ((byte)pcVar3[-3] <= lcd_page_counter) break;
        pcVar4 = (char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = pcVar3[-3];
        pcVar2 = pcVar3 + 3;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
        *pcVar4 = lcd_page_counter + *pcVar3;
        mod_stack_adjust_d154();
        pcVar3 = pcVar2 + 1;
        mod_set_lcd_page_counter_d144(pcVar2[-5] + '\x01');
      }
    }
  }
  mod_c18_epilogue_d130(cVar6);
  return;
}


// ===== 0x00d08c ui_draw_label_value =====

/* Draw a label and value line (service screens) */

void ui_draw_label_value(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  
  mod_c18_prologue_d11e();
  *(undefined1 *)in_FSR1 = 0x1e;
  puVar5 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  mod_stack_adjust_d154();
  mod_stack_adjust_d13c(3);
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    mod_to_mod_set_lcd_delay_counter_d164(7);
  }
  else {
    puVar6 = puVar5 + 1;
    *puVar5 = 0x2d;
    puVar5 = puVar5 + 2;
    *puVar6 = 0x59;
    lcd_puts_rom();
    puVar2 = puVar1;
  }
  *puVar5 = *puVar5;
  puVar7 = puVar5 + -2;
  puVar5[-1] = puVar5[-1];
  mod_stack_adjust_d13c(0x11);
  puVar4 = puVar2 + 1;
  puVar3 = puVar2 + 1;
  if (puVar2[-3] == '\0') {
    mod_to_mod_set_lcd_delay_counter_d164(0xd);
  }
  else {
    puVar8 = puVar7 + 1;
    *puVar7 = 0x1e;
    puVar7 = puVar7 + 2;
    *puVar8 = 0x59;
    lcd_puts_rom();
    puVar4 = puVar3;
  }
  *puVar7 = *puVar7;
  puVar9 = puVar7 + -2;
  puVar7[-1] = puVar7[-1];
  mod_stack_adjust_d13c(0x10);
  if (puVar4[-4] == '\0') {
    mod_to_mod_set_lcd_delay_counter_d164(10);
  }
  else {
    puVar10 = puVar9 + 1;
    *puVar9 = 0x12;
    puVar9 = puVar9 + 2;
    *puVar10 = 0x59;
    lcd_puts_rom();
  }
  *puVar9 = *puVar9;
  puVar11 = puVar9 + -2;
  puVar9[-1] = puVar9[-1];
  mod_stack_adjust_d13c(2);
  *puVar11 = 0x1f;
  puVar12 = puVar11 + 2;
  puVar11[1] = 1;
  mod_stack_adjust_d154();
  puVar13 = puVar12 + 1;
  *puVar12 = 1;
  lcd_write_data();
  *puVar13 = *puVar13;
  puVar13[-1] = 0x40;
  puVar14 = puVar13 + 1;
  *puVar13 = 3;
  mod_set_lcd_delay_counter_cf6e();
  *puVar14 = *puVar14;
  puVar14[-1] = puVar14[-1];
  puVar15 = puVar14 + -1;
  puVar14[-2] = 1;
  lcd_write_data();
  *puVar15 = *puVar15;
  mod_c18_epilogue_d130();
  return;
}


// ===== 0x00d11e mod_c18_prologue_d11e =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_d11e(void)

{
  return;
}


// ===== 0x00d130 mod_c18_epilogue_d130 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_d130(void)

{
  return;
}


// ===== 0x00d13c mod_stack_adjust_d13c =====

/* Auto: Software stack push/pop helper; 4 instr */

void mod_stack_adjust_d13c(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_to_mod_set_lcd_delay_counter_d164();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x00d144 mod_set_lcd_page_counter_d144 =====

/* Auto: writes lcd_page_counter; 8 instr */

void mod_set_lcd_page_counter_d144(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  lcd_page_counter = lcd_page_counter + '\x01';
  return;
}


// ===== 0x00d154 mod_stack_adjust_d154 =====

/* Auto: Software stack push/pop helper; 4 instr */

void mod_stack_adjust_d154(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x00d15c mod_to_lcd_write_cmd_d15c =====

/* Auto: calls lcd_write_cmd; 4 instr */

void mod_to_lcd_write_cmd_d15c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_cmd();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00d164 mod_to_mod_set_lcd_delay_counter_d164 =====

/* Auto: Small wrapper around mod_set_lcd_delay_counter; 3 instr */

void mod_to_mod_set_lcd_delay_counter_d164(void)

{
  mod_set_lcd_delay_counter_cf6e();
  return;
}


// ===== 0x00d16c mod_frame_access_d16c =====

/* Auto: Access stack-frame local/argument; 4 instr */

undefined1 mod_frame_access_d16c(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_d11e();
  return *(undefined1 *)((short)in_FSR2 + -2);
}


// ===== 0x00d174 task_cooling =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 4 task: cold tank thermostat driving the compressor, pull-down logging */

void task_cooling(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  undefined1 uVar10;
  byte bVar11;
  bool bVar12;
  
code_c0x00d174:
  do {
    local1 = cooling_read_param(1);
    *(undefined1 *)in_FSR1 = 0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = local1;
    OSDelay();
    *puVar1 = *puVar1;
    pbVar2 = puVar1 + -2;
    puVar1[-1] = puVar1[-1];
    adc_raw_lo = 0xb;
    OS_Yield();
    bVar11 = 0;
    if ((cfg_systemconfig5 & 0x60) == 0x20) goto LAB_CODE_00d22c;
    cold_temp_a = cold_temp_read_ch4();
    cold_temp_b = cold_temp_read_ch5();
    bVar11 = 0;
    if (cooling_fault == -0x73) goto LAB_CODE_00d22c;
    bVar11 = 0;
    if (cooling_fault + 'q' == '\0') goto LAB_CODE_00d22c;
    cVar9 = system_get_mode(cooling_fault + 'q');
    bVar11 = 0;
    if (cVar9 == '\x02') goto LAB_CODE_00d22c;
    cVar9 = mod_return_0x01_fcaa();
    in_FSR1 = (BADSPACEBASE *)pbVar2;
  } while (cVar9 == '\0');
  if (cold_temp_a == 0xff) {
LAB_CODE_00d1f8:
    cooling_fault = -0x73;
    compressor_stop();
    uVar10 = 0x8d;
  }
  else {
    if (cold_temp_a != 0xfe) {
      if (fault_code < '\0') {
joined_c0x00d226:
        bVar11 = cooling_fault << 1 | 1;
        if (-1 < cooling_fault) {
          cooling_fault = fault_code;
        }
LAB_CODE_00d22c:
        compressor_stop(bVar11);
        in_FSR1 = (BADSPACEBASE *)pbVar2;
        goto code_c0x00d174;
      }
      local0 = cold_temp_b;
      if (cold_temp_b == 0xff) goto LAB_CODE_00d1f8;
      if (cold_temp_b != 0xfe) {
        if (fault_code < '\0') goto joined_c0x00d226;
        OS_Yield(fault_code << 1 | 0xfd < cold_temp_b);
        *pbVar2 = cold_temp_b;
        pbVar4 = pbVar2 + 2;
        pbVar2[1] = cold_temp_a;
        uv_check_cold_abnormal();
        *pbVar4 = *pbVar4;
        in_FSR1 = (BADSPACEBASE *)(pbVar4 + -2);
        pbVar4[-1] = pbVar4[-1];
        cVar9 = system_get_mode();
        if (cVar9 == '\x01') {
          uVar10 = 2;
        }
        else {
          uVar10 = 3;
        }
        local0 = cooling_read_param(uVar10);
        *(byte *)in_FSR1 = local0;
        if (((local0 ^ cold_temp_a) & 0x80) == 0) {
          bVar12 = *(byte *)in_FSR1 < 0xfe || cold_temp_a < *(byte *)in_FSR1 + 2;
        }
        else {
          bVar12 = (char)cold_temp_a < '\0';
        }
        if (bVar12) {
          *(byte *)in_FSR1 = local0;
          if (((local0 ^ cold_temp_b) & 0x80) == 0) {
            bVar11 = *(byte *)in_FSR1;
            bVar12 = bVar11 < 0xfe || cold_temp_b < bVar11 + 2;
            bVar11 = (bVar11 - cold_temp_b) + 2;
          }
          else {
            bVar12 = (char)cold_temp_b < '\0';
            bVar11 = cold_temp_b << 1 | 1;
          }
          if (bVar12) goto LAB_CODE_00d2b2;
        }
        *(undefined1 *)in_FSR1 = 1;
        if ((cold_temp_a & 0x80) == 0) {
          bVar11 = *(byte *)in_FSR1;
          bVar12 = bVar11 < 0xfe || cold_temp_a < bVar11 + 2;
          bVar11 = (bVar11 - cold_temp_a) + 2;
        }
        else {
          bVar12 = (char)cold_temp_a < '\0';
          bVar11 = cold_temp_a << 1;
        }
        if (bVar12) {
LAB_CODE_00d2b2:
          compressor_stop(bVar11);
          if (((cooling_flags & 2) != 0) && ((cooling_flags & 1) != 0)) {
            *(byte *)in_FSR1 = local0;
            if (((local0 ^ cold_temp_a) & 0x80) == 0) {
              bVar12 = *(byte *)in_FSR1 < 0xfe || cold_temp_a < *(byte *)in_FSR1 + 2;
            }
            else {
              bVar12 = (char)cold_temp_a < '\0';
            }
            pulldown_end_temp = cold_temp_b;
            if (bVar12) {
              pulldown_end_temp = cold_temp_a;
            }
            stat_CG = pulldown_time_lo;
            DAT_DATA_00db = pulldown_time_hi;
            uDATA00dc = 0;
            uDATA00dd = 0;
            pbVar5 = (byte *)((short)in_FSR1 + 1);
            *(undefined1 *)in_FSR1 = 10;
            stat_counter_save();
            *pbVar5 = *pbVar5;
            stat_CGT = pulldown_start_temp - pulldown_end_temp;
            pbVar5[-1] = 1;
            stat_byte_save();
            puVar6 = pbVar5 + -1;
            *pbVar5 = *pbVar5;
            cooling_reset_pulldown();
            in_FSR1 = (BADSPACEBASE *)puVar6;
          }
          goto code_c0x00d174;
        }
        *(undefined1 *)in_FSR1 = 1;
        if ((cold_temp_b & 0x80) == 0) {
          bVar11 = *(byte *)in_FSR1;
          bVar12 = bVar11 < 0xfe || cold_temp_b < bVar11 + 2;
          bVar11 = (bVar11 - cold_temp_b) + 2;
        }
        else {
          bVar12 = (char)cold_temp_b < '\0';
          bVar11 = cold_temp_b << 1;
        }
        if (bVar12) goto LAB_CODE_00d2b2;
        local3 = cooling_read_param(4);
        *(byte *)in_FSR1 = local3 + local0;
        if (((local3 + local0 ^ cold_temp_a) & 0x80) == 0) {
          bVar12 = *(byte *)in_FSR1 <= cold_temp_a;
          bVar11 = cold_temp_a - *(byte *)in_FSR1;
        }
        else {
          bVar12 = *(char *)in_FSR1 < '\0';
          bVar11 = *(char *)in_FSR1 << 1 | CARRY1(local3,local0);
        }
        if (bVar12) {
          if ((outputs_shadow & 0x40) != 0) goto code_c0x00d174;
          cVar9 = compressor_start(bVar11);
          if (cVar9 != -0x7d) {
            puVar7 = (undefined1 *)((short)in_FSR1 + 1);
            *(undefined1 *)in_FSR1 = 0;
            cooling_set_demand();
            in_FSR1 = (BADSPACEBASE *)(puVar7 + -1);
            *puVar7 = *puVar7;
            if ((cooling_flags & 2) != 0) {
              cooling_flags = cooling_flags | 1;
              pulldown_start_temp = cold_temp_a;
              in_FSR1 = (BADSPACEBASE *)(puVar7 + -1);
            }
            goto code_c0x00d174;
          }
        }
        else {
          local3 = cooling_read_param(5);
          *(byte *)in_FSR1 = local3 + local0;
          if (((local3 + local0 ^ cold_temp_b) & 0x80) == 0) {
            bVar12 = *(byte *)in_FSR1 <= cold_temp_b;
            bVar11 = cold_temp_b - *(byte *)in_FSR1;
          }
          else {
            bVar12 = *(char *)in_FSR1 < '\0';
            bVar11 = *(char *)in_FSR1 << 1 | CARRY1(local3,local0);
          }
          if ((!bVar12) || ((outputs_shadow & 0x40) != 0)) goto code_c0x00d174;
          cVar9 = compressor_start(bVar11);
          if (cVar9 != -0x7d) {
            puVar8 = (undefined1 *)((short)in_FSR1 + 1);
            *(undefined1 *)in_FSR1 = 0;
            cooling_set_demand();
            in_FSR1 = (BADSPACEBASE *)(puVar8 + -1);
            *puVar8 = *puVar8;
            if ((cooling_flags & 2) != 0) {
              cooling_flags = cooling_flags | 1;
              pulldown_start_temp = cold_temp_b;
              in_FSR1 = (BADSPACEBASE *)(puVar8 + -1);
            }
            goto code_c0x00d174;
          }
        }
        puVar3 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 1;
        cooling_set_demand();
        goto LAB_CODE_00d38a;
      }
    }
    cooling_fault = -0x71;
    compressor_stop();
    uVar10 = 0x8f;
  }
  puVar3 = pbVar2 + 1;
  *pbVar2 = uVar10;
  compressor_set_fault();
LAB_CODE_00d38a:
  *puVar3 = *puVar3;
  in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
  goto code_c0x00d174;
}


// ===== 0x00d3a2 cooling_init =====

/* Initialise cooling state */

undefined1 cooling_init(void)

{
  cooling_flags = 0;
  cold_temp_a = 0;
  cold_temp_b = 0;
  cooling_fault = 0;
  cooling_reset_pulldown();
  return 0;
}


// ===== 0x00d3b0 cooling_create_task =====

/* Create task_cooling (TCB 0x68) */

undefined1 cooling_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  mod_push_args_68_00_d49a();
  *puVar1 = 0x74;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xd1;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}


// ===== 0x00d3d4 cooling_start_task =====

/* Start task_cooling */

undefined1 cooling_start_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_68_00_d49a();
  OSStartTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}


// ===== 0x00d3e0 cooling_stop_task =====

/* Stop task_cooling */

undefined1 cooling_stop_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_68_00_d49a();
  OSStopTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}


// ===== 0x00d3ec cold_temp_average =====

/* Average of the two cold tank temperatures */

byte cold_temp_average(void)

{
  portion_flow_lo = '\0';
  if ((cold_temp_b & 0x80) != 0) {
    portion_flow_lo = -1;
  }
  c18_tmp1 = '\0';
  if ((cold_temp_a & 0x80) != 0) {
    c18_tmp1 = -1;
  }
  local4 = cold_temp_b + cold_temp_a;
  portion_flow_lo = portion_flow_lo + c18_tmp1 + CARRY1(cold_temp_b,cold_temp_a);
  c18_tmp1 = portion_flow_lo >> 1;
  c18_tmp0 = cold_temp_b + cold_temp_a >> 1 | portion_flow_lo * -0x80;
  return c18_tmp0;
}


// ===== 0x00d41a cooling_pulldown_tick =====

/* Per second: count pull-down time while measuring */

undefined1 cooling_pulldown_tick(void)

{
  bool bVar1;
  
  if ((cooling_flags & 1) != 0) {
    if ((cooling_flags & 2) != 0) {
      bVar1 = 0xfe < pulldown_time_lo;
      pulldown_time_lo = pulldown_time_lo + 1;
      pulldown_time_hi = pulldown_time_hi + bVar1;
    }
  }
  return 0;
}


// ===== 0x00d430 cooling_idle_minute_tick =====

/* Per minute: count down idle time before pull-down measurement */

void cooling_idle_minute_tick(void)

{
  cooling_idle_minutes = cooling_idle_minutes + -1;
  if (cooling_idle_minutes == '\0') {
    cooling_flags = cooling_flags | 2;
  }
  return;
}


// ===== 0x00d43a cooling_get_state =====

/* Cooling system state: 0 off, 1 on, 2 delay */

undefined1 cooling_get_state(void)

{
  char cVar1;
  
  if ((outputs_shadow & 0x40) != 0) {
    return 1;
  }
  if (cooling_demand != '\0') {
    cVar1 = compressor_get_offdelay(cooling_demand);
    if (cVar1 != '\0') {
      return 2;
    }
  }
  return 0;
}


// ===== 0x00d452 cooling_set_demand =====

/* Set cooling demand/delay flag (0x208) */

undefined1 cooling_set_demand(void)

{
  BADSPACEBASE *in_FSR1;
  
  cooling_demand =
       *(undefined1 *)
        (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  return 0xfd;
}


// ===== 0x00d474 cooling_abort_pulldown =====

/* Cancel pull-down measurement (cold water drawn) */

void cooling_abort_pulldown(void)

{
  cooling_flags = cooling_flags & 0xfc;
  return;
}


// ===== 0x00d47c mod_to_cooling_reset_pulldown_d47c =====

/* Auto: calls cooling_reset_pulldown; 1 instr */

undefined1 mod_to_cooling_reset_pulldown_d47c(void)

{
  cooling_idle_minutes = 0x78;
  pulldown_time_lo = 0;
  pulldown_time_hi = 0;
  cooling_flags = cooling_flags & 0xfc;
  return 0x78;
}


// ===== 0x00d480 cooling_reset_pulldown =====

/* Reset pull-down measurement: 120 min idle wait */

undefined1 cooling_reset_pulldown(void)

{
  cooling_idle_minutes = 0x78;
  pulldown_time_lo = 0;
  pulldown_time_hi = 0;
  cooling_flags = cooling_flags & 0xfc;
  return 0x78;
}


// ===== 0x00d490 cooling_read_param =====

/* eeprom_read_param wrapper for cooling module */

void cooling_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00d49a mod_push_args_68_00_d49a =====

/* Auto: Push constant arguments [104, 0]; 5 instr */

undefined1 mod_push_args_68_00_d49a(void)

{
  return 0;
}


// ===== 0x00d4a4 params_verify =====

/* Check parameter values against EEPROM min/max at startup (inferred) */

char params_verify(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar7;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte unaff_C;
  bool bVar8;
  
  mod_push_args_32_00_01_d700();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  mod_to_eeprom_read_byte_d724();
  bVar7 = (byte)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    bVar7 = (byte)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  puVar4 = (undefined1 *)((ushort)bVar7 << 8);
  fault_code = c18_tmp0;
  if (c18_tmp0 < '\0') {
    return c18_tmp0;
  }
  if (adc_raw_lo == '\0') {
    return '\0';
  }
  for (adc_raw_hi = 1; adc_raw_hi < 0x4b; adc_raw_hi = adc_raw_hi + 1) {
    mod_get_TBLPTRL_d6a0(adc_raw_hi);
    mod_get_TBLPTRL_d6d2(3);
    mod_to_eeprom_write_byte_b_d740(adc_raw_hi);
    puVar3 = (undefined1 *)((ushort)puVar4 & 0xff00);
    puVar4 = puVar3 + -1;
    *puVar3 = *puVar3;
    mod_shift_multibyte_d75e();
  }
  adc_raw_hi = 1;
  while( true ) {
    if (0x4a < adc_raw_hi) {
      return '\0';
    }
    mod_get_TBLPTRL_d6a0(adc_raw_hi);
    mod_get_TBLPTRL_d6d2(5);
    bVar8 = 0xb4 < adc_raw_hi;
    mod_to_eeprom_write_byte_b_d740(adc_raw_hi + 0x4b);
    if (!bVar8) {
      puVar5 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar5;
    }
    mod_shift_multibyte_d75e();
    if (bVar8) break;
    mod_get_TBLPTRL_d6a0(adc_raw_hi);
    mod_get_TBLPTRL_d6d2(4);
    bVar8 = 0x69 < adc_raw_hi;
    mod_to_eeprom_write_byte_b_d740(adc_raw_hi + 0x96);
    if (!bVar8) {
      puVar6 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar6 + -1;
      *puVar6 = *puVar6;
    }
    mod_shift_multibyte_d75e();
    if (bVar8) {
      return fault_code;
    }
    adc_raw_hi = adc_raw_hi + 1;
  }
  return fault_code;
}


// ===== 0x00d530 param_find_record =====

/* Find parameter record in ROM table by id */

void param_find_record(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar3;
  undefined1 *puVar2;
  undefined1 uVar4;
  byte *pbVar5;
  undefined3 in_TBLPTR;
  undefined1 *puVar6;
  bool bVar7;
  
  mod_c18_prologue_d6b4();
  bVar7 = 4 < (byte)in_FSR1;
  bVar3 = (byte)((ushort)in_FSR1 >> 8);
  pbVar5 = (byte *)CONCAT11((bVar3 - 1) + bVar7,(byte)in_FSR1 - 5);
  bVar1 = pbVar5[1] | *pbVar5;
  uVar4 = 0;
  if ((bVar1 != 0) &&
     (uVar4 = mod_frame_access_d6f0(bVar1), !CARRY1(bVar3,bVar7) && bVar3 + bVar7 == '\0')) {
    mod_to_mod_get_TBLPTRL_d78c();
    puVar6 = (undefined1 *)
             CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                      CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfe < (byte)in_TBLPTR),
                               (byte)in_TBLPTR + 1));
    c18_tmp0 = *puVar6;
    c18_tmp1 = puVar6[1];
    c18_tmp2 = 0;
    *(undefined1 *)in_FSR1 = c18_tmp0;
    *(undefined1 *)((short)in_FSR1 + 1) = c18_tmp1;
    *(undefined1 *)((short)in_FSR1 + 2) = c18_tmp2;
    *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR2 + -4);
    puVar2 = (undefined1 *)((short)in_FSR1 + 5);
    *(undefined1 *)((short)in_FSR1 + 4) = *(undefined1 *)((short)in_FSR2 + -2);
    c18_tmp3 = strcpy_rom2ram();
    uVar4 = c18_tmp3;
    if ((byte)puVar2 < 5) {
      *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
      uVar4 = c18_tmp3;
    }
  }
  mod_c18_epilogue_d6c6(uVar4);
  return;
}


// ===== 0x00d58c param_table_lookup =====

/* Find parameter in ROM table (0xDD62) and return a field */

void param_table_lookup(void)

{
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if ((unaff_C & 1) == 0) {
    mod_chain_fnd78c_mod_get_c18_tmp0_d776();
    if ((unaff_Z & 1) != 0) {
      mod_to_mod_get_TBLPTRL_d78c();
      uVar1 = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                        CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfc < (byte)in_TBLPTR),
                                 (byte)in_TBLPTR + 3));
      goto LAB_CODE_00d5a6;
    }
  }
  uVar1 = 0;
LAB_CODE_00d5a6:
  mod_c18_epilogue_d6c6(uVar1);
  return;
}


// ===== 0x00d5a8 param_read_min =====

/* Read parameter minimum from EEPROM (address + 0x96) */

void param_read_min(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if ((unaff_C & 1) == 0) {
    mod_chain_fnd78c_mod_get_c18_tmp0_d776();
    if ((unaff_Z & 1) != 0) {
      mod_push_args_32_00_01_d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x96;
      mod_to_eeprom_read_byte_d724();
      if (bVar1 < 0x6a) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = mod_frag_d76a();
      goto LAB_CODE_00d5c8;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5c8:
  mod_c18_epilogue_d6c6(uVar3);
  return;
}


// ===== 0x00d5ca param_read_max =====

/* Read parameter maximum from EEPROM (address + 0x4B) */

void param_read_max(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if ((unaff_C & 1) == 0) {
    mod_chain_fnd78c_mod_get_c18_tmp0_d776();
    if ((unaff_Z & 1) != 0) {
      mod_push_args_32_00_01_d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x4b;
      mod_to_eeprom_read_byte_d724();
      if (bVar1 < 0xb5) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = mod_frag_d76a();
      goto LAB_CODE_00d5ea;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5ea:
  mod_c18_epilogue_d6c6(uVar3);
  return;
}


// ===== 0x00d5ec param_write =====

/* Write parameter to EEPROM; updates RAM copies of SYSTEMCONFIG2-5 */

void param_write(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if (((unaff_C & 1) == 0) && (mod_chain_fnd78c_mod_get_c18_tmp0_d776(), (unaff_Z & 1) != 0)) {
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    cVar3 = *(char *)((short)in_FSR2 + -2);
    if (cVar3 == 'A') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig5 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ':') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig4 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ',') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig3 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == '+') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig2 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    cVar3 = mod_stack_adjust_d710((char)puVar1);
    bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
    *(undefined1 *)in_FSR1 = puVar1[(short)cVar3 + 1];
    mod_to_eeprom_write_byte_d750();
    uVar4 = c18_tmp0;
    if ((unaff_C & 1) == 0) {
      *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      uVar4 = c18_tmp0;
    }
  }
  else {
    uVar4 = 0x81;
  }
  mod_c18_epilogue_d6c6(uVar4);
  return;
}


// ===== 0x00d640 param_write_max =====

/* Write parameter maximum to EEPROM (address + 0x4B) */

void param_write_max(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  bVar2 = mod_frame_access_d782();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(byte *)in_FSR1 = bVar2 + 0x4b;
  mod_to_eeprom_write_byte_d750();
  if (bVar2 < 0xb5) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_d6c6(c18_tmp0);
  return;
}


// ===== 0x00d654 param_write_min =====

/* Write parameter minimum to EEPROM (address + 0x96) */

void param_write_min(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  bVar2 = mod_frame_access_d782();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(byte *)in_FSR1 = bVar2 + 0x96;
  mod_to_eeprom_write_byte_d750();
  if (bVar2 < 0x6a) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_d6c6(c18_tmp0);
  return;
}


// ===== 0x00d668 eeprom_read_raw =====

/* Read EEPROM byte at address */

void eeprom_read_raw(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte unaff_C;
  
  mod_c18_prologue_d6b4();
  mod_push_args_32_00_01_d700();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  mod_to_eeprom_read_byte_d724();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_frag_d76a();
  mod_c18_epilogue_d6c6();
  return;
}


// ===== 0x00d67e eeprom_read_param =====

/* Read one EEPROM byte (address = parameter id - 1) */

void eeprom_read_param(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  mod_c18_prologue_d6b4();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  eeprom_read_raw();
  *puVar2 = *puVar2;
  uVar3 = adc_raw_lo;
  if (fault_code < '\0') {
    puVar2[-1] = puVar1[-2];
    uVar3 = param_table_lookup();
    *puVar2 = *puVar2;
  }
  mod_c18_epilogue_d6c6(uVar3);
  return;
}


// ===== 0x00d6a0 mod_get_TBLPTRL_d6a0 =====

/* Auto: reads TBLPTRL,TBLPTRH; 8 instr */

undefined1 mod_get_TBLPTRL_d6a0(void)

{
  return 0xdd;
}


// ===== 0x00d6b4 mod_c18_prologue_d6b4 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_d6b4(void)

{
  return;
}


// ===== 0x00d6c6 mod_c18_epilogue_d6c6 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_d6c6(void)

{
  return;
}


// ===== 0x00d6d2 mod_get_TBLPTRL_d6d2 =====

/* Auto: reads TBLPTRL,TBLPTRH,c18_tmp0,c18_tmp1; 11 instr */

undefined1 mod_get_TBLPTRL_d6d2(byte param_1)

{
  byte in_TBLPTRL;
  char in_TBLPTRH;
  
  c18_tmp0 = in_TBLPTRL + param_1;
  c18_tmp1 = in_TBLPTRH + CARRY1(in_TBLPTRL,param_1);
  return 1;
}


// ===== 0x00d6f0 mod_frame_access_d6f0 =====

/* Auto: Access stack-frame local/argument; 7 instr */

char mod_frame_access_d6f0(void)

{
  char in_FramePointer2_0000fffe;
  
  return in_FramePointer2_0000fffe + -0x4b;
}


// ===== 0x00d700 mod_push_args_32_00_01_d700 =====

/* Auto: Push constant arguments [50, 0, 1]; 8 instr */

undefined1 mod_push_args_32_00_01_d700(void)

{
  return 1;
}


// ===== 0x00d710 mod_stack_adjust_d710 =====

/* Auto: Software stack push/pop helper; 10 instr */

undefined1 mod_stack_adjust_d710(void)

{
  return 0xfd;
}


// ===== 0x00d724 mod_to_eeprom_read_byte_d724 =====

/* Auto: calls eeprom_read_byte; 6 instr */

char mod_to_eeprom_read_byte_d724(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp0 = eeprom_read_byte();
  return cVar1 + -6;
}


// ===== 0x00d732 mod_get_c18_tmp0_d732 =====

/* Auto: reads c18_tmp0,TABLAT; 6 instr */

char mod_get_c18_tmp0_d732(void)

{
  char *in_TBLPTR;
  char in_FramePointer2_0000fffe;
  
  c18_tmp0 = *in_TBLPTR;
  return *in_TBLPTR - in_FramePointer2_0000fffe;
}


// ===== 0x00d740 mod_to_eeprom_write_byte_b_d740 =====

/* Auto: calls eeprom_write_byte_b; 7 instr */

char mod_to_eeprom_write_byte_b_d740(void)

{
  char cVar1;
  
  cVar1 = '\x02';
  c18_tmp2 = eeprom_write_byte_b();
  return cVar1 + -6;
}


// ===== 0x00d750 mod_to_eeprom_write_byte_d750 =====

/* Auto: calls eeprom_write_byte; 6 instr */

char mod_to_eeprom_write_byte_d750(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp0 = eeprom_write_byte();
  return cVar1 + -6;
}


// ===== 0x00d75e mod_shift_multibyte_d75e =====

/* Auto: compiler fragment: MOVWF FSR1L,ACCESS ; MOVF 0x0016,w,ACCESS ; MOVLB #0x2 ; MOVWF
   0x1,BANKED ; RLCF 0x0016,w,ACCESS ; RETURN 0x0 */

byte mod_shift_multibyte_d75e(void)

{
  byte unaff_C;
  
  fault_code = c18_tmp2;
  return c18_tmp2 << 1 | unaff_C & 1;
}


// ===== 0x00d76a mod_frag_d76a =====

/* Auto: compiler fragment: MOVWF FSR1L,ACCESS ; MOVF 0x0014,w,ACCESS ; MOVLB #0x2 ; MOVWF
   0x1,BANKED ; MOVF 0x0032,w,ACCESS ; RETURN 0x0 */

undefined1 mod_frag_d76a(void)

{
  fault_code = c18_tmp0;
  return adc_raw_lo;
}


// ===== 0x00d776 mod_chain_fnd78c_mod_get_c18_tmp0_d776 =====

/* Auto: Calls 0xd78c, mod_get_c18_tmp0; 2 instr */

void mod_chain_fnd78c_mod_get_c18_tmp0_d776(void)

{
  mod_to_mod_get_TBLPTRL_d78c();
  mod_get_c18_tmp0_d732();
  return;
}


// ===== 0x00d77c mod_chain_fnd6b4_fnd6f0_d77c =====

/* Auto: Calls 0xd6b4, 0xd6f0; 2 instr */

void mod_chain_fnd6b4_fnd6f0_d77c(void)

{
  mod_c18_prologue_d6b4();
  mod_frame_access_d6f0();
  return;
}


// ===== 0x00d782 mod_frame_access_d782 =====

/* Auto: Access stack-frame local/argument; 5 instr */

undefined1 mod_frame_access_d782(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 in_FSR1L;
  char cVar1;
  
  mod_c18_prologue_d6b4();
  cVar1 = mod_stack_adjust_d710(in_FSR1L);
  return *(undefined1 *)((short)in_FSR2 + (short)cVar1 + 1);
}


// ===== 0x00d78c mod_to_mod_get_TBLPTRL_d78c =====

/* Auto: Small wrapper around mod_get_TBLPTRL; 3 instr */

void mod_to_mod_get_TBLPTRL_d78c(void)

{
  undefined1 in_FramePointer2_0000fffe;
  
  mod_get_TBLPTRL_d6a0(in_FramePointer2_0000fffe);
  return;
}


// ===== 0x00d794 task_fan_and_safety =====

/* Priority 4 task (500 ms): condenser fan (RH5), device sensor AN6, dryer over-temp AN7, fault
   inputs */

void task_fan_and_safety(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  bool bVar8;
  
  do {
    *(undefined1 *)in_FSR1 = 0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = 0x32;
    OSDelay();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    puVar1[-1] = puVar1[-1];
    adc_raw_lo = 0x13;
    OS_Yield();
    if ((cfg_systemconfig4 & 0x10) != 0) {
      local2 = temp_read_ch6();
      if (local2 == 0xff) {
        device_sensor_fault = 0x8d;
      }
      else if (local2 == 0xfe) {
        device_sensor_fault = 0x8f;
      }
      else {
        device_sensor_fault = 0;
      }
      if (device_sensor_fault == 0) {
        if ((outputs_shadow & 0x40) == 0) {
          local0 = fan_read_param(0x3b);
          *(byte *)in_FSR1 = local0;
          if (((local0 ^ local2) & 0x80) == 0) {
            bVar8 = *(byte *)in_FSR1 < 0xfe || local2 < *(byte *)in_FSR1 + 2;
          }
          else {
            bVar8 = (char)local2 < '\0';
          }
          if (bVar8) {
            bVar8 = (char)fan_runon_hi < '\0';
            if (!bVar8) {
              bVar8 = ~(fan_runon_lo == 0) != 0 || fan_runon_hi < (byte)-~(fan_runon_lo == 0);
            }
            if (bVar8) {
              fan_runon_lo = 0xff;
              fan_runon_hi = 0xff;
              bVar7 = PORTH;
              PORTH = bVar7 & ~RH5;
            }
          }
          local1 = fan_read_param(0x3c);
          local0 = local0 + local1;
          *(byte *)in_FSR1 = local0;
          if (((local0 ^ local2) & 0x80) == 0) {
            bVar8 = *(byte *)in_FSR1 <= local2;
          }
          else {
            bVar8 = *(char *)in_FSR1 < '\0';
          }
          if (bVar8) {
            bVar7 = PORTH;
            PORTH = bVar7 | RH5;
          }
        }
        else {
          bVar7 = PORTH;
          PORTH = bVar7 | RH5;
        }
      }
    }
    bVar7 = 0;
    if (((cfg_systemconfig4 & 0x10) == 0) || (bVar7 = device_sensor_fault, device_sensor_fault != 0)
       ) {
      if ((outputs_shadow & 0x40) == 0) {
        if (fan_runon_hi == 0 && fan_runon_lo == 0) {
          fan_runon_lo = 0xff;
          fan_runon_hi = 0xff;
          bVar7 = PORTH;
          PORTH = bVar7 & ~RH5;
        }
        if (heater_power_level == '\0') {
          bVar7 = ~fan_runon_lo;
          if ((bVar7 == 0) && (bVar7 = ~fan_runon_hi, bVar7 == 0)) {
            bVar5 = PORTH;
            PORTH = bVar5 & ~RH5;
          }
        }
        else {
          bVar7 = fan_heater_runon_hi | fan_heater_runon_lo;
          if (bVar7 == 0) {
            fan_heater_runon_lo = 0xff;
            fan_heater_runon_hi = 0xff;
            goto LAB_CODE_00d868;
          }
        }
      }
      else {
LAB_CODE_00d868:
        bVar5 = PORTH;
        PORTH = bVar5 | RH5;
      }
    }
    if ((cfg_systemconfig4 & 8) != 0) {
      local2 = temp_read_ch7(bVar7);
      if (local2 == 0xff) {
        dryer_sensor_fault = 0x8d;
      }
      else if (local2 == 0xfe) {
        dryer_sensor_fault = 0x8f;
      }
      else {
        dryer_sensor_fault = 0;
      }
      bVar7 = dryer_sensor_fault;
      if (dryer_sensor_fault == 0) {
        puVar2 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0x3f;
        bVar5 = eeprom_read_param();
        in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
        *puVar2 = *puVar2;
        bVar7 = (bVar5 - local2) + 2;
        if (0xfd < bVar5 && bVar5 + 2 <= local2) {
          puVar2[-1] = 0x2d;
          local1 = eeprom_read_param();
          pbVar3 = puVar2 + -1;
          *puVar2 = *puVar2;
          puVar2[-1] = 0xc;
          if ((local1 & 0x80) == 0) {
            bVar8 = (byte)puVar2[-1] <= local1;
            cVar6 = local1 - puVar2[-1];
          }
          else {
            bVar8 = (char)puVar2[-1] < '\0';
            cVar6 = puVar2[-1] << 1;
          }
          if (!bVar8) {
            cVar6 = '\f';
            local1 = 0xc;
          }
          compressor_stop(cVar6);
          pbVar4 = pbVar3 + 1;
          *pbVar3 = local1;
          bVar7 = fan_set_runon_minutes();
          in_FSR1 = (BADSPACEBASE *)(pbVar4 + -1);
          *pbVar4 = *pbVar4;
        }
      }
    }
    lamp_filter_presence_check(bVar7);
  } while( true );
}


// ===== 0x00d8ea fan_init =====

/* Initialise fan timers and sensor faults */

undefined1 fan_init(void)

{
  fan_runon_lo = 0xff;
  fan_runon_hi = 0xff;
  fan_heater_runon_lo = 0xff;
  fan_heater_runon_hi = 0xff;
  device_sensor_fault = 0;
  dryer_sensor_fault = 0;
  presence_flags = 0;
  return 0;
}


// ===== 0x00d8fc fan_create_task =====

/* Create task_fan_and_safety (TCB 0x92) */

undefined1 fan_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x00d926 fan_start_runon =====

/* Start fan run-on after compressor stop (TFANOPERATING minutes) */

char fan_start_runon(void)

{
  char cVar1;
  
  cVar1 = fan_read_param(0x3d);
  fan_runon_lo = cVar1 * '<';
  fan_runon_hi = 0;
  return cVar1 * '<';
}


// ===== 0x00d936 fan_start_heater_runon =====

/* Run fan 300 s after heater switches on */

undefined1 fan_start_heater_runon(void)

{
  fan_heater_runon_lo = 0x2c;
  fan_heater_runon_hi = 1;
  return 1;
}


// ===== 0x00d942 fan_second_tick =====

/* Per second: count down fan run-on timers */

byte fan_second_tick(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  
  bVar3 = (char)fan_runon_hi < '\0';
  if (!bVar3) {
    bVar2 = ~(fan_runon_lo == '\0');
    bVar3 = bVar2 != 0 || fan_runon_hi < -bVar2;
    if (bVar2 == 0 && fan_runon_hi >= -bVar2) {
      bVar4 = fan_runon_lo != '\0';
      fan_runon_lo = fan_runon_lo + -1;
      bVar3 = fan_runon_hi != ~bVar4;
      fan_runon_hi = fan_runon_hi - ~bVar4;
    }
  }
  bVar2 = fan_heater_runon_hi << 1 | bVar3;
  if (-1 < (char)fan_heater_runon_hi) {
    bVar1 = ~(fan_heater_runon_lo == '\0');
    bVar2 = -~(fan_heater_runon_lo == '\0') - fan_heater_runon_hi;
    if (bVar1 == 0 && -bVar1 <= fan_heater_runon_hi) {
      bVar3 = fan_heater_runon_lo != '\0';
      fan_heater_runon_lo = fan_heater_runon_lo + -1;
      bVar2 = 0;
      fan_heater_runon_hi = fan_heater_runon_hi - ~bVar3;
    }
  }
  return bVar2;
}


// ===== 0x00d96e fan_set_runon_minutes =====

/* Set fan run-on time in minutes */

char fan_set_runon_minutes(void)

{
  BADSPACEBASE *in_FSR1;
  
  fan_runon_lo = *(char *)(CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),
                                    (char)&FramePointer10x0002) + -2) * '<';
  fan_runon_hi = 0;
  return fan_runon_lo;
}


// ===== 0x00d998 lamp_filter_presence_check =====

/* UV lamp switch (RJ0) / filter switch (RC3): on removal stop loads, show INSERT screen; on refit
   ask NEW/OLD */

void lamp_filter_presence_check(void)

{
  byte bVar1;
  char cVar2;
  
  if ((cfg_systemconfig4 & 0x20) != 0) {
    bVar1 = PORTJ;
    if ((bVar1 & RJ0) != 0) {
      presence_flags = presence_flags | 2;
      cVar2 = ui_get_menu_mode_1122(bVar1 & RJ0);
      if ((cVar2 == '\0') || (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\x04')) {
        uv_alarm_code = 0x82;
        ui_get_ui_screen_4ae6();
        screen_uv_lamp_removed();
      }
      loads_stop_and_restart();
    }
  }
  if ((cfg_systemconfig4 & 4) != 0) {
    bVar1 = PORTC;
    if ((bVar1 & RC3) != 0) {
      presence_flags = presence_flags | 1;
      cVar2 = ui_get_menu_mode_1122(bVar1 & RC3);
      if ((cVar2 == '\0') || (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\x02')) {
        ui_get_ui_screen_4ae6();
        screen_filter_removed();
      }
      loads_stop_and_restart();
    }
  }
  if ((((presence_flags & 2) != 0) &&
      (((cfg_systemconfig4 & 0x20) == 0 || (bVar1 = PORTJ, (bVar1 & RJ0) == 0)))) &&
     ((cVar2 = ui_get_menu_mode_1122(0), cVar2 == '\x03' ||
      (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\0')))) {
    presence_flags = presence_flags & 0xfd;
    uv_alarm_code = 0;
    screen_uv_lamp_new_old();
    heating_start_task();
    cooling_start_task();
  }
  if ((((presence_flags & 1) != 0) &&
      (((cfg_systemconfig4 & 4) == 0 || (bVar1 = PORTC, (bVar1 & RC3) == 0)))) &&
     ((cVar2 = ui_get_menu_mode_1122(0), cVar2 == '\x01' ||
      (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\0')))) {
    presence_flags = presence_flags & 0xfe;
    screen_filter_new_old();
    heating_start_task();
    cooling_start_task();
  }
  return;
}


// ===== 0x00da64 loads_stop_and_restart =====

/* Stop compressor and heater, restart heating/cooling tasks, stop dispensing */

void loads_stop_and_restart(void)

{
  compressor_stop();
  cooling_stop_task();
  heater_off();
  heating_stop_task();
  dispense_stop_all();
  return;
}


// ===== 0x00da78 fan_read_param =====

/* EEPROM read wrapper for fan module */

void fan_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00da82 task_uv_lamp =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 2 task: UV sterilising lamp cycles, filament warm-up, lamp verification (RJ1) */

void task_uv_lamp(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar3;
  
code_c0x00da82:
  do {
    while( true ) {
      while( true ) {
        local0 = uv_read_param(1);
        *(undefined1 *)in_FSR1 = 0;
        puVar2 = (undefined1 *)((short)in_FSR1 + 2);
        *(char *)((short)in_FSR1 + 1) = local0;
        OSDelay();
        *puVar2 = *puVar2;
        in_FSR1 = (BADSPACEBASE *)(puVar2 + -2);
        puVar2[-1] = puVar2[-1];
        adc_raw_lo = 10;
        OS_Yield();
        if ((((cfg_systemconfig & 8) != 0) && (cVar3 = uv_cfg_application(), cVar3 != '\x03')) &&
           (cVar3 = uv_cfg_application(), cVar3 != '\x01')) break;
        uv_status = 0;
      }
      local0 = system_get_mode();
      cVar3 = uv_is_available();
      if ((cVar3 != '\0') && (local0 != '\x02')) break;
      uv_status = uv_status & 0xfd;
      dispense_stop_all_c(0);
      cold_valve_close();
      uv_lamp_off();
      uv_status = uv_status | 1;
      uv_service_off();
      uv_flags = uv_flags | 1;
      cVar3 = system_get_mode();
      if (cVar3 == '\x02') {
        uv_load_on_time(0x12);
      }
    }
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) != 0) {
      uv_status = uv_status | 1;
    }
    if (uv_service_override != '\0') {
      uv_status = uv_status | 1;
    }
    if ((((uv_flags & 1) != 0) || ((uv_flags & 8) != 0)) || (uv_verify_retries == '\0'))
    goto LAB_CODE_00db4e;
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) != 0) {
      uv_verify_retries = '\0';
      if (uv_alarm_code == -0x70) {
        uv_alarm_code = '\0';
      }
      goto LAB_CODE_00db4e;
    }
    if (uv_verify_period_timer == '\0') {
      uv_verify_retries = uv_verify_retries + -1;
      uv_verify_period_timer = uv_read_param(0x48);
    }
  } while (uv_verify_retries != '\0');
  if (-1 < uv_alarm_code) {
    uv_alarm_code = -0x70;
  }
LAB_CODE_00db4e:
  if (uv_alarm_code != -0x70) {
    if ((uv_flags & 1) == 0) {
      if ((uv_period_counter != '\0') || ((cfg_systemconfig6 & 1) == 0)) goto code_c0x00da82;
      uv_reload_period();
    }
    uv_flags = uv_flags | 1;
    if (uv_service_override != '\0') {
      uv_service_on(uv_service_override);
      uv_filament_timer = uv_read_param(0xf);
    }
    if (uv_filament_timer != '\0') goto code_c0x00da82;
    if ((outputs_shadow & 0x20) == 0) {
      uv_lamp_on(0);
      uv_reload_verify_delay();
      uv_on_timer = uv_on_time;
      uv_verify_off_timer = uv_read_param(0x47);
    }
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) == 0) {
      uv_status = 0;
      uv_reload_verify_delay();
    }
    else if (uv_verify_delay == '\0') {
      bVar1 = PORTJ;
      if ((bVar1 & RJ1) != 0) {
        uv_lamp_off(bVar1 & RJ1);
        uv_status = uv_status | 2;
        if (-1 < uv_alarm_code) {
          uv_alarm_code = -0x75;
        }
        uv_on_timer = '\0';
      }
    }
    if (uv_on_timer != '\0') goto code_c0x00da82;
  }
  uv_lamp_off(0);
  uv_flags = uv_flags & 0xfe;
  uv_load_on_time(0x12);
  uv_reload_period();
  goto code_c0x00da82;
}


// ===== 0x00dbe6 uv_init =====

/* Initialise UV lamp state */

undefined1 uv_init(void)

{
  uv_flags = 0;
  uv_filament_timer = uv_read_param(0xf);
  uv_verify_delay = 0;
  uv_on_time = 0;
  uv_verify_off_timer = 0;
  uv_verify_retries = 0;
  uv_verify_period_timer = 0;
  uv_long_verify_timer = 0;
  uv_reload_period();
  uv_on_timer = 0;
  uv_service_clear();
  return 0;
}


// ===== 0x00dc08 uv_create_task =====

/* Create task_uv_lamp (TCB 0x7a) */

undefined1 uv_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x00dc32 uv_start_keep_cycle =====

/* Start a UV cycle with TUVKEEP on-time */

undefined1 uv_start_keep_cycle(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  
  uVar1 = uv_load_on_time(0x10);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x8a) = uVar1;
  uv_verify_off_timer = uv_read_param(0x47);
  uv_flags = uv_flags | 1;
  return 0;
}


// ===== 0x00dc44 uv_check_cold_abnormal =====

/* Force UV cycle if cold water above TABNORMALCOLDHIGH */

undefined1 uv_check_cold_abnormal(void)

{
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  puVar2 = &FramePointer10x0002;
  puVar1 = (undefined1 *)
           CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  uv_cold_abnormal_limit = uv_read_param(0x4a);
  c18_tmp0 = puVar1[-2];
  if (uv_cold_abnormal_limit < 0xfe || c18_tmp0 < uv_cold_abnormal_limit + 2) {
    c18_tmp1 = puVar1[-2];
    if (uv_cold_abnormal_limit < 0xfe || c18_tmp1 < uv_cold_abnormal_limit + 2) {
      uVar3 = 0;
      goto LAB_CODE_00dc8a;
    }
  }
  uv_flags = uv_flags | 8;
  if (-1 < uv_alarm_code) {
    uv_alarm_code = -0x70;
  }
  uVar3 = 1;
LAB_CODE_00dc8a:
  *puVar2 = *puVar2;
  return uVar3;
}


// ===== 0x00dc96 uv_verify_100ms_tick =====

/* Every 100 ms: count down lamp verify delay */

char uv_verify_100ms_tick(void)

{
  char cVar1;
  
  cVar1 = -uv_verify_delay;
  if (uv_verify_delay != '\0') {
    uv_verify_delay = uv_verify_delay + -1;
  }
  return cVar1;
}


// ===== 0x00dca2 uv_second_tick =====

/* Per second: UV on-time, verify-off, filament and verify-period countdowns */

char uv_second_tick(void)

{
  char cVar1;
  
  if (uv_on_timer != '\0') {
    uv_on_timer = uv_on_timer + -1;
  }
  if (uv_verify_off_timer != '\0') {
    uv_verify_off_timer = uv_verify_off_timer + -1;
    if (uv_verify_off_timer == '\0') {
      uv_verify_retries = 3;
    }
  }
  if (uv_verify_period_timer != '\0') {
    uv_verify_period_timer = uv_verify_period_timer + -1;
  }
  cVar1 = -uv_filament_timer;
  if (uv_filament_timer != '\0') {
    uv_filament_timer = uv_filament_timer + -1;
  }
  return cVar1;
}


// ===== 0x00dcce uv_minute_tick =====

/* Per minute: UV period countdown, long-verify timer, usage counters */

char uv_minute_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  if ((((uv_flags & 1) == 0) && (uv_period_counter != '\0')) &&
     (uv_period_subcounter = uv_period_subcounter + -1, uv_period_subcounter == '\0')) {
    uv_period_counter = uv_period_counter + -1;
    uv_period_subcounter = '\n';
  }
  if (uv_long_verify_timer == '\0') {
    uv_long_verify_timer = uv_read_param(0x49);
    if (uv_verify_off_timer == '\0') {
      uv_verify_retries = 3;
    }
  }
  else {
    uv_long_verify_timer = uv_long_verify_timer + -1;
  }
  cVar2 = uv_service_override;
  if (uv_service_override == '\0') {
    puVar1 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 6;
    stat_counter_inc();
    *puVar1 = *puVar1;
    puVar1[-1] = 6;
    cVar2 = stat_counter_save();
    *puVar1 = *puVar1;
  }
  return cVar2;
}


// ===== 0x00dd1a uv_read_param =====

/* eeprom_read_param wrapper for UV module */

void uv_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00dd24 uv_cfg_application =====

/* APPLICATION setting (copy in UV module) */

byte uv_cfg_application(void)

{
  byte unaff_BSR;
  
  return (*(byte *)((ushort)unaff_BSR * 0x100 + 0x5b) & 0x60) >> 5;
}


// ===== 0x00dd34 uv_set_period =====

/* Set UV period countdown (and 10-minute sub-counter) */

undefined1 uv_set_period(undefined1 param_1)

{
  uv_period_counter = param_1;
  uv_period_subcounter = 10;
  return 10;
}


// ===== 0x00dd3e uv_reload_period =====

/* Reload UV period from TUVPERIOD_T3_26 */

void uv_reload_period(void)

{
  uv_read_param(0xe);
  uv_set_period();
  return;
}


// ===== 0x00dd46 uv_reload_verify_delay =====

/* Reload lamp verify delay from TUVOPERATING_T3_26 (x10) */

void uv_reload_verify_delay(void)

{
  char cVar1;
  
  cVar1 = uv_read_param(0x11);
  uv_verify_delay = cVar1 * '\n';
  return;
}


// ===== 0x00dd52 uv_load_on_time =====

/* Load UV on-time from given parameter */

void uv_load_on_time(void)

{
  uv_on_time = uv_read_param();
  return;
}


// ===== 0x00dfd6 eeprom_read_byte =====

/* WARNING: Removing unreachable block (CODE,0x00e004) */
/* WARNING: Removing unreachable block (CODE,0x00e02e) */
/* WARNING: Removing unreachable block (CODE,0x00e030) */
/* WARNING: Removing unreachable block (CODE,0x00e04a) */
/* WARNING: Removing unreachable block (CODE,0x00e04c) */
/* Low-level EEPROM byte read (EEADRH:EEADR) */

undefined1 eeprom_read_byte(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  c18_tmp0 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  c18_tmp1 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e060 eeprom_write_byte =====

/* WARNING: Removing unreachable block (CODE,0x00e08e) */
/* WARNING: Removing unreachable block (CODE,0x00e0a4) */
/* WARNING: Removing unreachable block (CODE,0x00e0a6) */
/* WARNING: Removing unreachable block (CODE,0x00e0da) */
/* WARNING: Removing unreachable block (CODE,0x00e0dc) */
/* WARNING: Removing unreachable block (CODE,0x00e0ec) */
/* WARNING: Removing unreachable block (CODE,0x00e0ee) */
/* WARNING: Removing unreachable block (CODE,0x00e0f0) */
/* Low-level EEPROM byte write (unlock sequence, wait for WR) */

undefined1 eeprom_write_byte(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  c18_tmp0 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  c18_tmp1 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e104 eeprom_write_byte_b =====

/* WARNING: Removing unreachable block (CODE,0x00e132) */
/* WARNING: Removing unreachable block (CODE,0x00e148) */
/* WARNING: Removing unreachable block (CODE,0x00e14a) */
/* WARNING: Removing unreachable block (CODE,0x00e180) */
/* WARNING: Removing unreachable block (CODE,0x00e182) */
/* WARNING: Removing unreachable block (CODE,0x00e192) */
/* WARNING: Removing unreachable block (CODE,0x00e194) */
/* WARNING: Removing unreachable block (CODE,0x00e196) */
/* Low-level EEPROM byte write (variant) */

undefined1 eeprom_write_byte_b(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  c18_tmp0 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  c18_tmp1 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e1aa eeprom_write_byte_c =====

/* WARNING: Removing unreachable block (CODE,0x00e1d8) */
/* WARNING: Removing unreachable block (CODE,0x00e210) */
/* WARNING: Removing unreachable block (CODE,0x00e212) */
/* WARNING: Removing unreachable block (CODE,0x00e222) */
/* WARNING: Removing unreachable block (CODE,0x00e224) */
/* WARNING: Removing unreachable block (CODE,0x00e226) */
/* Low-level EEPROM byte write (variant) */

undefined1 eeprom_write_byte_c(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  c18_tmp0 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  c18_tmp1 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e23a ui_draw_progress_segment =====

/* Draw one segment of the progress popup */

void ui_draw_progress_segment(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  bool bVar8;
  
  mod_stack_adjust_e496();
  mod_to_mod_get_c18_tmp0_e47e(popup_index * '\x05' + '\x01');
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0xff;
  lcd_write_data();
  puVar4 = puVar3 + -1;
  *puVar3 = *puVar3;
  popup_flag = 1;
  mod_get_popup_icon_e41a();
  bVar1 = *(byte *)in_FSR2;
  *(byte *)in_FSR2 = bVar1 - 6;
  bVar8 = *(byte *)((short)in_FSR2 + 1) != ~(5 < bVar1);
  *(byte *)((short)in_FSR2 + 1) = *(byte *)((short)in_FSR2 + 1) - ~(5 < bVar1);
  pbVar2 = (byte *)in_FSR2;
  puVar5 = puVar4;
  while( true ) {
    mod_get_c18_tmp0_e436();
    if ((c18_tmp1 & 0x80) != 0) break;
    puVar6 = puVar5 + 1;
    *puVar5 = 0x81;
    mod_to_lcd_write_data_e44e();
    puVar5 = puVar6;
    if (!bVar8) {
      bVar8 = pbVar2[3] != '\0';
      pbVar2[2] = pbVar2[3] + -1;
      pbVar2 = pbVar2 + 2;
    }
  }
  puVar7 = puVar5 + 1;
  *puVar5 = 0xff;
  lcd_write_data(c18_tmp1 & 0x80);
  *puVar7 = *puVar7;
  puVar7[-1] = puVar7[-1];
  puVar7[-2] = puVar7[-2];
  mod_c18_epilogue_e40e();
  return;
}


// ===== 0x00e290 mod_to_mod_get_c18_tmp0_e290 =====

/* Auto: Small wrapper around mod_get_c18_tmp0; 21 instr */

void mod_to_mod_get_c18_tmp0_e290(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  bool bVar4;
  
  mod_stack_adjust_e496();
  bVar4 = 0xfc < (byte)(popup_index * '\x05');
  mod_to_mod_get_c18_tmp0_e47e(popup_index * '\x05' + 3);
  puVar1 = (undefined1 *)in_FSR2;
  puVar2 = (undefined1 *)in_FSR1;
  while( true ) {
    mod_get_c18_tmp0_e436();
    if ((c18_tmp1 & 0x80) != 0) break;
    puVar3 = puVar2 + 1;
    *puVar2 = 0;
    mod_to_lcd_write_data_e44e();
    puVar2 = puVar3;
    if (!bVar4) {
      bVar4 = puVar1[3] != '\0';
      puVar1[2] = puVar1[3] + -1;
      puVar1 = puVar1 + 2;
    }
  }
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  mod_c18_epilogue_e40e(c18_tmp1 & 0x80);
  return;
}


// ===== 0x00e2ba mod_to_ui_draw_progress_segment_e2ba =====

/* Auto: writes popup_flag; reads popup_index,popup_arg; calls ui_draw_progress_segment; 9 instr */

void mod_to_ui_draw_progress_segment_e2ba(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_e3fc();
  popup_index = *(undefined1 *)((short)in_FSR2 + -3);
  popup_arg = *(undefined1 *)((short)in_FSR2 + -1);
  popup_flag = 0;
  ui_draw_progress_segment();
  mod_c18_epilogue_e40e();
  return;
}


// ===== 0x00e2d0 mod_get_popup_index_e2d0 =====

/* Auto: reads popup_index; 22 instr */

void mod_get_popup_index_e2d0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  mod_c18_prologue_e3fc();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(char *)in_FSR2 = popup_index * '\x05' + '\x03';
  c18_tmp0 = *(undefined1 *)in_FSR2;
  c18_tmp1 = 0;
  mod_to_mod_to___divs16_e3ec();
  puVar2 = puVar1;
  while( true ) {
    if (*(char *)in_FSR2 == '\0') break;
    puVar3 = puVar2 + 1;
    *puVar2 = 0;
    mod_to_lcd_write_data_e44e();
    puVar2 = puVar3;
  }
  *puVar2 = *puVar2;
  mod_c18_epilogue_e40e(0);
  return;
}


// ===== 0x00e2fc ui_draw_progress_popup =====

/* WARNING: Removing unreachable block (CODE,0x00e3cc) */
/* WARNING: Removing unreachable block (CODE,0x00e3da) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw progress/level popup (fill tanks, dispensing) */

void ui_draw_progress_popup(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  BADSPACEBASE *in_FSR0;
  bool bVar8;
  
  mod_stack_adjust_e496();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  puVar6 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  c18_tmp2 = popup_index;
  c18_tmp3 = 0;
  math_aarg_lo = popup_index;
  math_aarg_hi = 0;
  math_barg_lo = *(undefined1 *)((short)in_FSR2 + -3);
  puVar2 = (undefined1 *)((short)in_FSR2 + 2);
  math_barg_hi = *(undefined1 *)((short)in_FSR2 + -1);
  __mul16();
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  math_barg_lo = 100;
  math_barg_hi = 0;
  math_aarg_lo = math_res0;
  math_aarg_hi = math_res1;
  __divu16();
  puVar2[3] = math_aarg_lo;
  puVar2[5] = math_aarg_hi;
  c18_tmp0 = popup_flag;
  c18_tmp1 = 0;
  puVar3 = puVar2 + 3;
  if ((puVar2[5] != popup_flag) || (puVar3 = puVar2 + 4, puVar2[7] != '\0')) {
    c18_tmp0 = puVar3[3];
    pbVar5 = puVar3 + 2;
    puVar4 = puVar3 + 2;
    c18_tmp1 = puVar3[5];
    if (c18_tmp1 == ~(popup_flag <= c18_tmp0)) {
      ui_draw_progress_segment(c18_tmp1 - ~(popup_flag <= c18_tmp0));
      pbVar5 = puVar4;
      puVar7 = puVar6;
    }
    else {
      c18_tmp0 = popup_flag;
      c18_tmp1 = 0;
      mod_calc_array_ptr_e440();
      bVar1 = *(byte *)in_FSR0;
      *(byte *)in_FSR0 = bVar1 - c18_tmp0;
      *(byte *)((short)in_FSR0 + 1) =
           (*(byte *)((short)in_FSR0 + 1) - c18_tmp1) - ~(c18_tmp0 <= bVar1);
      puVar7 = puVar6;
    }
    c18_tmp0 = popup_index * '\x05' + 3;
    c18_tmp1 = 0;
    mod_to___divs16_e458();
    bVar8 = 0xfe < c18_tmp0;
    c18_tmp0 = c18_tmp0 + 1;
    c18_tmp1 = c18_tmp1 + bVar8;
    *pbVar5 = c18_tmp0;
    pbVar5[1] = c18_tmp1;
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + popup_flag * '\x05';
    pbVar5[1] = pbVar5[1] + CARRY1(bVar1,popup_flag * '\x05');
    puVar6 = puVar7 + 1;
    *puVar7 = *pbVar5;
    mod_get_popup_arg_e488();
    mod_calc_array_ptr_e440();
  }
  if ((byte)puVar6 < 4) {
    *(undefined1 *)((ushort)puVar6 & 0xff00) = *(undefined1 *)((ushort)puVar6 & 0xff00);
  }
  mod_c18_epilogue_e40e((byte)puVar6 - 4);
  return;
}


// ===== 0x00e3ec mod_to_mod_to___divs16_e3ec =====

/* Auto: Small wrapper around mod_to___divs16; 7 instr */

void mod_to_mod_to___divs16_e3ec(void)

{
  BADSPACEBASE *in_FSR1;
  bool bVar1;
  
  mod_to___divs16_e458();
  bVar1 = c18_tmp0 != '\0';
  c18_tmp0 = c18_tmp0 + -1;
  c18_tmp1 = c18_tmp1 - ~bVar1;
  *(char *)in_FSR1 = c18_tmp0;
  mod_get_popup_arg_e488();
  return;
}


// ===== 0x00e3fc mod_c18_prologue_e3fc =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_e3fc(void)

{
  return;
}


// ===== 0x00e40e mod_c18_epilogue_e40e =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_e40e(void)

{
  return;
}


// ===== 0x00e41a mod_get_popup_icon_e41a =====

/* Auto: reads popup_icon; 11 instr */

void mod_get_popup_icon_e41a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  puVar1[-1] = 4;
  puVar2 = puVar1 + 1;
  *puVar1 = popup_icon;
  mod_set_lcd_delay_counter_cf6e();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  return;
}


// ===== 0x00e436 mod_get_c18_tmp0_e436 =====

/* Auto: reads c18_tmp0,c18_tmp1; 3 instr */

void mod_get_c18_tmp0_e436(void)

{
  undefined1 in_FramePointer2_00000000;
  undefined1 in_FramePointer2_00000001;
  
  c18_tmp0 = in_FramePointer2_00000000;
  c18_tmp1 = in_FramePointer2_00000001;
  return;
}


// ===== 0x00e440 mod_calc_array_ptr_e440 =====

/* Auto: Compute array element address in FSR0; 7 instr */

char mod_calc_array_ptr_e440(void)

{
  byte in_FSR2L;
  char in_FSR2H;
  
  return in_FSR2H + (0xfd < in_FSR2L);
}


// ===== 0x00e44e mod_to_lcd_write_data_e44e =====

/* Auto: Small wrapper around lcd_write_data; 4 instr */

void mod_to_lcd_write_data_e44e(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  lcd_write_data();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(char *)in_FSR2 = *(char *)in_FSR2 + -1;
  return;
}


// ===== 0x00e458 mod_to___divs16_e458 =====

/* Auto: reads c18_tmp0,c18_tmp1,math_aarg_lo,math_aarg_hi; calls __divs16; 14 instr */

void mod_to___divs16_e458(void)

{
  math_aarg_lo = -0x7e - c18_tmp0;
  math_aarg_hi = '\x02' - c18_tmp1;
  math_barg_lo = 2;
  math_barg_hi = 0;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  __divs16();
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  return;
}


// ===== 0x00e47e mod_to_mod_get_c18_tmp0_e47e =====

/* Auto: Small wrapper around mod_get_c18_tmp0; 4 instr */

void mod_to_mod_get_c18_tmp0_e47e(void)

{
  mod_get_c18_tmp0_e436();
  mod_to_mod_to___divs16_e3ec();
  return;
}


// ===== 0x00e488 mod_get_popup_arg_e488 =====

/* Auto: reads popup_arg; 5 instr */

void mod_get_popup_arg_e488(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00e496 mod_stack_adjust_e496 =====

/* Auto: Software stack push/pop helper; 4 instr */

void mod_stack_adjust_e496(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_c18_prologue_e3fc();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  return;
}


// ===== 0x00e6ba heater_init =====

/* Initialise heater state; power-up delay (30 s, 120 s if TPOWERDELAY set, 0 with factory jumper)
    */

undefined1 heater_init(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  
  heater_power_level = 0;
  heater_maxon_timer = 0;
  heater_zc_counter = 0;
  heater_pattern_lo = 0;
  heater_pattern_hi = 0;
  heater_holdoff = 0;
  puVar1 = &FramePointer10x0001;
  cVar4 = eeprom_read_param();
  puVar2 = puVar1 + -1;
  *puVar1 = *puVar1;
  if (cVar4 == '\0') {
    cVar4 = is_factory_jumper();
    if (cVar4 == '\0') {
      heater_powerup_delay = 0x1e;
    }
    else {
      heater_powerup_delay = 0;
    }
  }
  else {
    heater_powerup_delay = 0x78;
    puVar2 = puVar1 + -1;
  }
  puVar3 = puVar2 + 1;
  *puVar2 = 0x22;
  heater_zc_cycle_len = eeprom_read_param();
  *puVar3 = *puVar3;
  heater_fault = 0;
  return 0;
}


// ===== 0x00e700 heater_is_ready =====

/* Return 1 when heater power-up delay has elapsed */

undefined1 heater_is_ready(void)

{
  if (heater_powerup_delay != '\0') {
    return 0;
  }
  return 1;
}


// ===== 0x00e70a heater_set_power =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Switch heater on at a power level (loads burst pattern from ROM 0xFC5C) */

void heater_set_power(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined3 in_TBLPTR;
  undefined1 uVar6;
  undefined1 *puVar5;
  
  uVar6 = (undefined1)((uint3)in_TBLPTR >> 0x10);
  mod_c18_prologue_e880();
  if (heater_powerup_delay == '\0') {
    cVar4 = heater_fault;
    if (-1 < heater_fault) {
      puVar2 = (undefined1 *)((short)in_FSR2 + 1);
      if (heater_power_level == *(char *)((short)in_FSR2 + -2)) {
        cVar4 = '\x01';
      }
      else {
        puVar3 = (undefined1 *)((short)in_FSR2 + 1);
        if (heater_power_level == '\0') {
          heater_load_maxon(0);
          puVar3 = puVar2;
        }
        bVar1 = INTCON;
        INTCON = bVar1 & ~(PEIE | GIE);
        heater_power_level = puVar3[-2];
        heater_zc_counter = 0;
        bVar1 = (heater_power_level + -1) * '\x02';
        puVar5 = (undefined1 *)
                 CONCAT12(uVar6,CONCAT11((heater_power_level + -1 < '\0') + -4 + (0xa3 < bVar1),
                                         bVar1 + 0x5c));
        heater_pattern_lo = *puVar5;
        heater_pattern_hi = puVar5[1];
        fan_start_heater_runon();
        bVar1 = INTCON;
        INTCON = bVar1 | (PEIE | GIE);
        cVar4 = '\0';
      }
    }
  }
  else {
    cVar4 = -0x7d;
  }
  mod_c18_epilogue_e8a2(cVar4);
  return;
}


// ===== 0x00e76a heater_off =====

/* Switch heater off (level 0) and log usage */

undefined1 heater_off(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if (heater_power_level == '\0') {
    return 1;
  }
  heater_power_level = 0;
  puVar1 = &FramePointer10x0001;
  stat_counter_save();
  *puVar1 = *puVar1;
  return 0;
}


// ===== 0x00e780 heater_maxon_minute_tick =====

/* Per minute: heater maximum on-time countdown; on expiry off + fault 0x84 */

byte heater_maxon_minute_tick(void)

{
  byte bVar1;
  byte unaff_C;
  
  bVar1 = 0;
  if (heater_power_level != '\0') {
    if (heater_maxon_timer != 0) {
      unaff_C = heater_maxon_timer != 0;
      heater_maxon_timer = heater_maxon_timer - 1;
    }
    bVar1 = heater_maxon_timer;
    if (heater_maxon_timer == 0) {
      heater_output_off(0);
      heater_output_enable = 0;
      heater_power_level = '\0';
      bVar1 = heater_fault << 1 | unaff_C & 1;
      if (-1 < heater_fault) {
        bVar1 = 0x84;
        heater_fault = -0x7c;
      }
    }
  }
  return bVar1;
}


// ===== 0x00e7a4 heater_second_tick =====

/* Per second: heater usage counter, hold-off and power-up delay countdowns */

char heater_second_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  if ((outputs_shadow & 0x80) != 0) {
    puVar1 = &FramePointer10x0001;
    stat_counter_inc();
    *puVar1 = *puVar1;
  }
  if (heater_holdoff != '\0') {
    heater_holdoff = heater_holdoff + -1;
  }
  cVar2 = heater_powerup_delay;
  if (heater_powerup_delay != '\0') {
    heater_powerup_delay = heater_powerup_delay + -1;
  }
  return cVar2;
}


// ===== 0x00e7c4 heater_burst_tick =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Every 10 ms: shift burst-fire pattern and drive RG0 */

byte heater_burst_tick(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_C;
  char cVar4;
  
  cVar4 = '\0';
  if ((heater_power_level != '\0') && (cVar4 = heater_holdoff, heater_holdoff == '\0')) {
    bVar3 = heater_zc_counter;
    if (heater_zc_counter != 0) {
      heater_zc_counter = heater_zc_counter - 1;
      return bVar3;
    }
    heater_zc_counter = heater_zc_cycle_len;
    bVar3 = 0;
    if (((heater_pattern_lo & 1) == 0) ||
       (bVar3 = heater_fault << 1 | unaff_C & 1, heater_fault < '\0')) {
      bVar1 = PORTG;
      PORTG = bVar1 & ~RG0;
      outputs_shadow = outputs_shadow & 0x7f;
    }
    else {
      if (heater_output_enable != '\0') {
        bVar3 = PORTG;
        PORTG = bVar3 | RG0;
        outputs_shadow = outputs_shadow | 0x80;
      }
      bVar3 = 1;
    }
    puVar2 = &FramePointer10x0001;
    ui_get_ui_heater_indicator_4bce(bVar3);
    *puVar2 = *puVar2;
    c18_tmp1 = heater_pattern_hi >> 1;
    c18_tmp0 = heater_pattern_lo >> 1 | heater_pattern_hi << 7;
    if ((heater_pattern_lo & 1) == 0) {
      c18_tmp3 = 0;
    }
    else {
      c18_tmp3 = 0x80;
    }
    c18_tmp2 = 0;
    heater_pattern_lo = c18_tmp0;
    heater_pattern_hi = c18_tmp3 | c18_tmp1;
    return heater_pattern_hi;
  }
  bVar3 = heater_output_off(cVar4);
  return bVar3;
}


// ===== 0x00e838 mod_to_heater_load_maxon_e838 =====

/* Auto: calls heater_load_maxon; 1 instr */

void mod_to_heater_load_maxon_e838(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  heater_maxon_timer = eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00e83c heater_holdoff_5s =====

/* Hold heater off for 5 s (used when compressor starts) */

void heater_holdoff_5s(void)

{
  heater_holdoff = 5;
  heater_output_off();
  return;
}


// ===== 0x00e846 heater_set_fault =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Latch heater fault code and disable heater output */

void heater_set_fault(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  char cVar2;
  
  mod_c18_prologue_e880();
  puVar1 = (undefined1 *)in_FSR2;
  if (heater_fault < '\0') {
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    cVar2 = *(char *)((short)in_FSR2 + -2);
    if (cVar2 != '\0') goto LAB_CODE_00e85e;
  }
  cVar2 = -3;
  heater_fault = puVar1[-2];
  heater_output_enable = 0;
LAB_CODE_00e85e:
  mod_c18_epilogue_e8a2(cVar2);
  return;
}


// ===== 0x00e860 heater_is_on =====

/* Return heater output state */

undefined1 heater_is_on(void)

{
  if (heater_power_level != '\0') {
    return 1;
  }
  return 0;
}


// ===== 0x00e86a heater_get_powerup_delay =====

/* Return heater power-up delay remaining */

undefined1 heater_get_powerup_delay(void)

{
  return heater_powerup_delay;
}


// ===== 0x00e870 heater_output_off =====

/* Drive RG0 low and update indicator */

void heater_output_off(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  bVar1 = PORTG;
  PORTG = bVar1 & ~RG0;
  outputs_shadow = outputs_shadow & 0x7f;
  puVar2 = &FramePointer10x0001;
  ui_get_ui_heater_indicator_4bce();
  *puVar2 = *puVar2;
  return;
}


// ===== 0x00e880 mod_c18_prologue_e880 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 5 instr */

void mod_c18_prologue_e880(void)

{
  return;
}


// ===== 0x00e892 heater_load_maxon =====

/* Load heater maximum on-time from EEPROM (THEATERMAXON) */

void heater_load_maxon(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  heater_maxon_timer = eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00e8a2 mod_c18_epilogue_e8a2 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_e8a2(void)

{
  return;
}


// ===== 0x00e8ae compressor_init =====

/* Stop compressor; set power-up restart delay (TCOMPOFFDELAY) unless factory jumper */

undefined1 compressor_init(void)

{
  byte unaff_BSR;
  char cVar1;
  byte bVar2;
  bool bVar3;
  
  compressor_stop();
  cVar1 = is_factory_jumper();
  if (cVar1 == '\0') {
    compressor_read_param(9);
    bVar2 = compressor_set_offdelay();
    if ((*(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) & 0x80) == 0) {
      bVar3 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) !=
              ~(bVar2 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0xe2));
    }
    else {
      bVar3 = false;
    }
    if (bVar3) goto LAB_CODE_00e8da;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe2) = 0xc;
  }
  else {
    unaff_BSR = 1;
    compressor_offdelay_lo = 0;
  }
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe3) = 0;
LAB_CODE_00e8da:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe4) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe5) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe6) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe1) = 0;
  return 0;
}


// ===== 0x00e8e6 compressor_start =====

/* Start compressor (returns 0x83 if restart delay still running) */

char compressor_start(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  bool bVar3;
  
  bVar3 = (char)compressor_offdelay_hi < '\0';
  if (!bVar3) {
    bVar1 = ~(compressor_offdelay_lo == '\0');
    bVar3 = bVar1 != 0 || compressor_offdelay_hi < -bVar1;
    if (bVar1 == 0 && compressor_offdelay_hi >= -bVar1) {
      return -0x7d;
    }
  }
  if (compressor_fault < '\0') {
    return compressor_fault;
  }
  if ((outputs_shadow & 0x40) != 0) {
    return '\x01';
  }
  compressor_load_maxon(compressor_fault << 1 | bVar3);
  compressor_start_flag = 0;
  heater_holdoff_5s();
  if (compressor_output_enable != '\0') {
    bVar1 = PORTG;
    PORTG = bVar1 | RG3;
    outputs_shadow = outputs_shadow | 0x40;
  }
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 1;
  ui_get_ui_compressor_indicator_4bd8();
  *puVar2 = *puVar2;
  return '\0';
}


// ===== 0x00e926 compressor_stop =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Stop compressor, start restart delay, log run time */

undefined1 compressor_stop(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte bVar4;
  bool bVar5;
  
  bVar2 = 0xe;
  if ((outputs_shadow & 0x40) == 0) {
    return 1;
  }
  bVar4 = is_factory_jumper();
  if (bVar4 == 0) {
    compressor_read_param(9);
    bVar4 = compressor_set_offdelay();
    if ((compressor_offdelay_b_hi & 0x80) == 0) {
      bVar5 = compressor_offdelay_b_hi != ~(bVar4 <= compressor_offdelay_b);
      bVar4 = compressor_offdelay_b_hi - ~(bVar4 <= compressor_offdelay_b);
    }
    else {
      bVar5 = false;
    }
    if (bVar5) goto LAB_CODE_00e956;
    bVar4 = 0xc;
    compressor_offdelay_b = 0xc;
  }
  else {
    bVar2 = 1;
    compressor_offdelay_lo = 0;
  }
  *(undefined1 *)((ushort)bVar2 * 0x100 + 0xe3) = 0;
LAB_CODE_00e956:
  bVar2 = PORTG;
  PORTG = bVar2 & ~RG3;
  outputs_shadow = outputs_shadow & 0xbf;
  fan_start_runon(bVar4);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  ui_get_ui_compressor_indicator_4bd8();
  *puVar3 = *puVar3;
  puVar3[-1] = 0xc;
  stat_counter_save();
  *puVar3 = *puVar3;
  cVar1 = stat_CMM - compressor_run_minutes;
  if (stat_CMM < compressor_run_minutes) {
    stat_CMM = compressor_run_minutes;
    puVar3[-1] = 0;
    stat_byte_save(cVar1);
    *puVar3 = *puVar3;
  }
  return 0;
}


// ===== 0x00e98a compressor_second_tick =====

/* Per second: compressor usage counter while running */

void compressor_second_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if ((outputs_shadow & 0x40) != 0) {
    puVar1 = &FramePointer10x0001;
    stat_counter_inc();
    *puVar1 = *puVar1;
  }
  return;
}


// ===== 0x00e99c compressor_offdelay_10s_tick =====

/* Every 10 s: count down restart delay */

undefined1 compressor_offdelay_10s_tick(undefined1 param_1)

{
  bool bVar1;
  
  if (((outputs_shadow & 0x40) == 0) &&
     (param_1 = 0, compressor_offdelay_hi != '\0' || compressor_offdelay_lo != '\0')) {
    bVar1 = compressor_offdelay_lo != '\0';
    compressor_offdelay_lo = compressor_offdelay_lo + -1;
    param_1 = 0;
    compressor_offdelay_hi = compressor_offdelay_hi - ~bVar1;
  }
  return param_1;
}


// ===== 0x00e9b2 compressor_minute_tick =====

/* Per minute: run time, maximum run time (TCOMPMAXON) then forced pause (TCOMPPAUSEMIN) */

byte compressor_minute_tick(byte param_1)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  
  bVar3 = compressor_run_minutes;
  if ((outputs_shadow & 0x40) == 0) {
    return param_1;
  }
  c18_tmp0 = compressor_run_minutes;
  c18_tmp1 = 0;
  bVar5 = 0xfe < compressor_run_minutes != true;
  if (!bVar5) {
    compressor_run_minutes = compressor_run_minutes + 1;
  }
  bVar5 = bVar5 || 0xfe < bVar3;
  if (compressor_maxon_hi != 0 || compressor_maxon_lo != 0) {
    bVar6 = compressor_maxon_lo != 0;
    compressor_maxon_lo = compressor_maxon_lo - 1;
    bVar5 = compressor_maxon_hi != ~bVar6;
    compressor_maxon_hi = compressor_maxon_hi - ~bVar6;
  }
  if ((compressor_maxon_hi | compressor_maxon_lo) != 0) {
    c18_tmp0 = bVar3;
    c18_tmp1 = 0;
    return compressor_maxon_hi | compressor_maxon_lo;
  }
  bVar3 = PORTG;
  PORTG = bVar3 & ~RG3;
  outputs_shadow = outputs_shadow & 0xbf;
  bVar1 = 0;
  compressor_output_enable = 0;
  bVar3 = is_factory_jumper(0);
  if (bVar3 == 0) {
    cVar4 = compressor_read_param(0x2d);
    bVar3 = compressor_set_offdelay(cVar4 * '\x06');
    if ((bDATA00e3 & 0x80) == 0) {
      bVar5 = bDATA00e3 != ~(bVar3 <= stat_CSS);
      bVar3 = bDATA00e3 - ~(bVar3 <= stat_CSS);
    }
    else {
      bVar5 = false;
    }
    if (bVar5 != false) goto LAB_CODE_00ea1c;
    bVar3 = 0xc;
    stat_CSS = 0xc;
  }
  else {
    bVar1 = 1;
    compressor_offdelay_lo = 0;
  }
  *(undefined1 *)((ushort)bVar1 * 0x100 + 0xe3) = 0;
LAB_CODE_00ea1c:
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = compressor_offdelay_lo;
  fan_set_runon_minutes(bVar3);
  *puVar2 = *puVar2;
  puVar2[-1] = 0;
  ui_get_ui_compressor_indicator_4bd8();
  *puVar2 = *puVar2;
  bVar3 = compressor_fault << 1 | bVar5;
  if (-1 < compressor_fault) {
    bVar3 = 0x84;
    compressor_fault = -0x7c;
  }
  return bVar3;
}


// ===== 0x00ea3a mod_to_compressor_load_maxon_ea3a =====

/* Auto: calls compressor_load_maxon; 1 instr */

void mod_to_compressor_load_maxon_ea3a(void)

{
  compressor_maxon_lo = compressor_read_param(10);
  compressor_maxon_hi = 0;
  return;
}


// ===== 0x00ea3e compressor_set_fault =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Latch compressor fault code and disable output */

char compressor_set_fault(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  
  puVar1 = (undefined1 *)
           CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  puVar2 = puVar1;
  if (compressor_fault < '\0') {
    puVar2 = puVar1 + 1;
    if (puVar1[-2] != '\0') {
      return puVar1[-2];
    }
  }
  compressor_output_enable = 0;
  compressor_fault = puVar2[-2];
  return -3;
}


// ===== 0x00ea70 compressor_get_offdelay =====

/* Return remaining restart delay */

undefined1 compressor_get_offdelay(void)

{
  return compressor_offdelay_lo;
}


// ===== 0x00ea76 compressor_read_param =====

/* eeprom_read_param wrapper for compressor module */

void compressor_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00ea80 compressor_set_offdelay =====

/* Set restart delay counter */

undefined1 compressor_set_offdelay(undefined1 param_1)

{
  compressor_offdelay_lo = param_1;
  compressor_offdelay_hi = 0;
  return 0xc;
}


// ===== 0x00ea8a compressor_load_maxon =====

/* Load maximum run time from EEPROM (TCOMPMAXON) */

void compressor_load_maxon(void)

{
  compressor_maxon_lo = compressor_read_param(10);
  compressor_maxon_hi = 0;
  return;
}


// ===== 0x00ec76 stats_load =====

/* Load usage counters (RAM 0xB2..) and byte statistics from EEPROM at startup */

undefined1 stats_load(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  
  puVar2 = &FramePointer10x0001;
  cVar9 = eeprom_read_raw();
  puVar4 = puVar2 + -1;
  *puVar2 = *puVar2;
  if (cVar9 != '\0') {
    puVar2[-1] = 0x42;
    *puVar2 = 0;
    puVar2[1] = 0xe4;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0;
    eeprom_write_byte_c();
    *puVar3 = *puVar3;
    puVar3[-1] = puVar3[-1];
    puVar3[-2] = puVar3[-2];
    puVar4 = puVar3 + -4;
    puVar3[-3] = puVar3[-3];
  }
  *puVar4 = 0xb2;
  puVar4[1] = 0;
  puVar4[2] = 0x40;
  puVar4[3] = 0;
  puVar4[4] = 0xe4;
  puVar5 = puVar4 + 6;
  puVar4[5] = 0;
  c18_tmp0 = eeprom_read_byte();
  bVar1 = (byte)puVar5;
  if (bVar1 < 6) {
    puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
    puVar5 = puVar6 + -1;
    *puVar6 = *puVar6;
  }
  puVar7 = (undefined1 *)CONCAT11((char)((ushort)puVar5 >> 8),bVar1 - 6);
  *puVar7 = 0xf2;
  puVar7[1] = 0;
  puVar7[2] = 2;
  puVar7[3] = 0;
  puVar7[4] = 0x24;
  puVar8 = puVar7 + 6;
  puVar7[5] = 1;
  c18_tmp0 = eeprom_read_byte();
  if ((byte)puVar8 < 6) {
    *(undefined1 *)((ushort)puVar8 & 0xff00) = *(undefined1 *)((ushort)puVar8 & 0xff00);
  }
  return 0;
}


// ===== 0x00ecee stats_read_counter_rom =====

/* Read a counter descriptor from ROM table */

void stats_read_counter_rom(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined3 in_TBLPTR;
  undefined1 uVar5;
  undefined1 *puVar4;
  
  uVar5 = (undefined1)((uint3)in_TBLPTR >> 0x10);
  bVar2 = mod_c18_prologue_edc4();
  bVar3 = (byte)((ushort)bVar2 * 6);
  puVar4 = (undefined1 *)
           CONCAT12(uVar5,CONCAT11((char)((ushort)bVar2 * 6 >> 8) + -0x21 + (0x98 < bVar3),
                                   bVar3 + 0x67));
  c18_tmp0 = *puVar4;
  c18_tmp1 = puVar4[1];
  c18_tmp2 = 0;
  mod_get_c18_tmp0_edfc();
  *(undefined1 *)in_FSR1 = c18_tmp2;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -4);
  puVar1 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR2 + -2);
  c18_tmp3 = strcpy_rom2ram();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  mod_c18_epilogue_edda(c18_tmp3);
  return;
}


// ===== 0x00ed38 stat_counter_inc =====

/* Increment 32-bit usage counter [id] in RAM */

void stat_counter_inc(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  bVar3 = mod_c18_prologue_edc4();
  bVar2 = (byte)((ushort)bVar3 * 4);
  pbVar4 = (byte *)CONCAT11((char)((ushort)bVar3 * 4 >> 8) + (0x4d < bVar2),bVar2 + 0xb2);
  bVar2 = *pbVar4;
  *pbVar4 = bVar2 + 1;
  bVar3 = pbVar4[1];
  bVar1 = CARRY1(bVar3,0xfe < bVar2);
  pbVar4[1] = bVar3 + (0xfe < bVar2);
  bVar2 = pbVar4[2];
  pbVar4[2] = bVar2 + bVar1;
  pbVar4[3] = pbVar4[3] + CARRY1(bVar2,bVar1);
  mod_c18_epilogue_edda();
  return;
}


// ===== 0x00ed58 stat_counter_save =====

/* Save 32-bit usage counter [id] to EEPROM */

void stat_counter_save(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  adc_raw_lo = mod_c18_prologue_edc4();
  bVar1 = (byte)((ushort)adc_raw_lo * 4);
  c18_tmp0 = bVar1 + 0xb2;
  c18_tmp1 = (char)((ushort)adc_raw_lo * 4 >> 8) + (0x4d < bVar1);
  mod_get_c18_tmp0_edfc();
  *(undefined1 *)in_FSR1 = 4;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  bVar2 = adc_raw_lo * '\x04';
  c18_tmp3 = 0;
  c18_tmp2 = bVar2 - 0x1c;
  stats_eeprom_write(0);
  if (bVar2 < 0x1c) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_edda(c18_tmp4);
  return;
}


// ===== 0x00ed94 stat_byte_save =====

/* Save byte statistic [id] (0xF2+id) to EEPROM */

void stat_byte_save(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  bool bVar2;
  
  adc_raw_lo = mod_c18_prologue_edc4();
  c18_tmp1 = 0xd < adc_raw_lo;
  c18_tmp0 = adc_raw_lo - 0xe;
  mod_get_c18_tmp0_edfc();
  *(undefined1 *)in_FSR1 = 1;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  c18_tmp3 = 0;
  bVar2 = adc_raw_lo < 0xdc;
  c18_tmp2 = adc_raw_lo + 0x24;
  stats_eeprom_write(1);
  if (bVar2) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_edda(c18_tmp4);
  return;
}


// ===== 0x00edc4 mod_c18_prologue_edc4 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 7 instr */

undefined1 mod_c18_prologue_edc4(void)

{
  BADSPACEBASE *in_FSR1;
  
  return *(undefined1 *)
          (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
}


// ===== 0x00edda mod_c18_epilogue_edda =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_edda(void)

{
  return;
}


// ===== 0x00ede6 stats_eeprom_write =====

/* EEPROM block write helper for statistics */

char stats_eeprom_write(char param_1)

{
  char cVar1;
  byte unaff_C;
  
  c18_tmp3 = c18_tmp3 + param_1 + (unaff_C & 1);
  cVar1 = '\x02';
  c18_tmp4 = eeprom_write_byte();
  return cVar1 + -6;
}


// ===== 0x00edfc mod_get_c18_tmp0_edfc =====

/* Auto: reads c18_tmp0,c18_tmp1; 3 instr */

void mod_get_c18_tmp0_edfc(void)

{
  return;
}


// ===== 0x00f278 lcd_draw_big_glyph =====

/* Draw large 51-byte glyphs from ROM 0x9010 on the LCD */

void lcd_draw_big_glyph(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte bVar7;
  undefined1 *in_TBLPTR;
  
  mod_c18_prologue_f394();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  puVar5 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR2 + 5) = 4;
  *(undefined1 *)((short)in_FSR2 + 5) = 0x33;
  puVar1 = (undefined1 *)((short)in_FSR2 + 3);
  math_aarg_lo = 0x82 - *(char *)((short)in_FSR2 + 6);
  math_aarg_hi = '\x02';
  math_barg_lo = 2;
  math_barg_hi = 0;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  __divs16();
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  puVar1[3] = math_aarg_lo;
  puVar1[1] = 0;
  while( true ) {
    if ((byte)puVar1[6] <= (byte)puVar1[2]) break;
    puVar2 = puVar1 + 3;
    *puVar5 = puVar1[5];
    puVar6 = puVar5 + 2;
    puVar5[1] = puVar1[3] + '\x02';
    mod_to_mod_to_lcd_write_cmd_cfc6();
    *puVar6 = *puVar6;
    puVar5 = puVar6 + -2;
    puVar6[-1] = puVar6[-1];
    puVar3 = puVar2 + 1;
    puVar2[2] = 0;
    while( true ) {
      puVar1 = puVar3 + 1;
      if ((byte)puVar3[4] <= (byte)puVar3[3]) break;
      bVar7 = (byte)((ushort)(byte)puVar3[2] * 0x33);
      c18_tmp0 = bVar7 + 0x10;
      c18_tmp1 = (char)((ushort)(byte)puVar3[2] * 0x33 >> 8) + -0x70 + (0xef < bVar7);
      puVar4 = puVar3 + 3;
      in_TBLPTR = (undefined1 *)
                  CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                           CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,puVar3[4]),c18_tmp0 + puVar3[4]));
      mod_callw_lcd_write_data_f3c4(*in_TBLPTR);
      puVar3 = puVar4 + 2;
      puVar4[2] = puVar4[3] + '\x01';
    }
    puVar3[2] = puVar3[2] + '\x01';
  }
  if ((byte)puVar5 < 5) {
    *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
  }
  mod_c18_epilogue_f3a8((byte)puVar5 - 5);
  return;
}


// ===== 0x00f334 mod_get_TBLPTRH_f334 =====

/* Auto: reads TBLPTRH,TBLPTRL,TABLAT; 24 instr */

void mod_get_TBLPTRH_f334(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  byte *pbVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  undefined1 *in_TBLPTR;
  
  mod_c18_prologue_f394();
  mod_stack_adjust_f3b4(0x73);
  pbVar2 = (byte *)in_FSR2;
  while( true ) {
    bVar1 = *pbVar2;
    if (6 < bVar1) break;
    pbVar3 = pbVar2 + 1;
    if (pbVar2[-2] == 0) {
      uVar4 = 0;
    }
    else {
      in_TBLPTR = (undefined1 *)
                  CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                           CONCAT11((0x8b < pbVar2[1]) + -0x6e,pbVar2[1] + 0x74));
      uVar4 = *in_TBLPTR;
    }
    mod_callw_lcd_write_data_f3c4(uVar4);
    *pbVar3 = *pbVar3 + '\x01';
    pbVar2 = pbVar3;
  }
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  mod_c18_epilogue_f3a8(bVar1 - 7);
  return;
}


// ===== 0x00f364 mod_get_TBLPTRH_f364 =====

/* Auto: reads TBLPTRH,TBLPTRL,TABLAT; 24 instr */

void mod_get_TBLPTRH_f364(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  byte *pbVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  undefined1 *in_TBLPTR;
  
  mod_c18_prologue_f394();
  mod_stack_adjust_f3b4(6);
  pbVar2 = (byte *)in_FSR2;
  while( true ) {
    bVar1 = *pbVar2;
    if (6 < bVar1) break;
    pbVar3 = pbVar2 + 1;
    if (pbVar2[-2] == 0) {
      uVar4 = 0;
    }
    else {
      in_TBLPTR = (undefined1 *)
                  CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                           CONCAT11((0x84 < pbVar2[1]) + -0x6e,pbVar2[1] + 0x7b));
      uVar4 = *in_TBLPTR;
    }
    mod_callw_lcd_write_data_f3c4(uVar4);
    *pbVar3 = *pbVar3 + '\x01';
    pbVar2 = pbVar3;
  }
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  mod_c18_epilogue_f3a8(bVar1 - 7);
  return;
}


// ===== 0x00f394 mod_c18_prologue_f394 =====

/* Auto: C18 function prologue: save FSR2 and set new frame pointer; 6 instr */

void mod_c18_prologue_f394(void)

{
  return;
}


// ===== 0x00f3a8 mod_c18_epilogue_f3a8 =====

/* Auto: C18 function epilogue: restore FSR2 frame pointer and return; 4 instr */

void mod_c18_epilogue_f3a8(void)

{
  return;
}


// ===== 0x00f3b4 mod_stack_adjust_f3b4 =====

/* Auto: Software stack push/pop helper; 7 instr */

void mod_stack_adjust_f3b4(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  *(undefined1 *)in_FSR2 = 0;
  return;
}


// ===== 0x00f3c4 mod_callw_lcd_write_data_f3c4 =====

/* Auto: Push W as argument and call lcd_write_data; 4 instr */

void mod_callw_lcd_write_data_f3c4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00f3ce __divs16 =====

/* WARNING: Instruction at (CODE,0x00f414) overlaps instruction at (CODE,0x00f412)
    */
/* C18 runtime: signed 16-bit divide (AARG / BARG) */

undefined1 __divs16(void)

{
  math_sign = 0;
  if ((math_barg_hi & 0x80) != 0) {
    math_barg_lo = -math_barg_lo;
    math_barg_hi = ~math_barg_hi + ('\0' < math_barg_lo);
    math_sign = 0xff;
  }
  if ((math_aarg_hi & 0x80) != 0) {
    math_aarg_lo = -math_aarg_lo;
    math_aarg_hi = ~math_aarg_hi + ('\0' < math_aarg_lo);
    math_sign = ~math_sign;
  }
  __divu16();
  if ((math_aarg_hi & 0x80) == 0) {
    if ((math_sign & 0x80) == 0) {
      return 0;
    }
  }
  else if ((math_sign & 0x80) == 0) {
    math_flags = math_flags | 0x10;
    return 0xff;
  }
  math_aarg_lo = -math_aarg_lo;
  math_aarg_hi = ~math_aarg_hi + ('\0' < math_aarg_lo);
  math_rem_lo = -math_rem_lo;
  math_rem_hi = ~math_rem_hi + ('\0' < math_rem_lo);
  return 0;
}


// ===== 0x00f41a mod_frag_f41a =====

/* WARNING: Instruction at (CODE,0x00f452) overlaps instruction at (CODE,0x00f450)
    */
/* Auto: compiler fragment: CLRF 0x0000,ACCESS ; CLRF WREG,ACCESS ; BTFSS 0x000e,#0x7,ACCESS ; GOTO
   0x00f434 */

undefined1 mod_frag_f41a(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  
  math_sign = 0;
  if ((math_barg_hi & 0x80) != 0) {
    math_aarg_b3 = -math_aarg_b3;
    bVar2 = ~math_barg_b0;
    bVar3 = ~math_barg_lo;
    bVar1 = CARRY1(bVar2,'\0' < math_aarg_b3);
    math_barg_b0 = bVar2 + ('\0' < math_aarg_b3);
    math_barg_lo = bVar3 + bVar1;
    math_barg_hi = ~math_barg_hi + CARRY1(bVar3,bVar1);
    math_sign = 0xff;
  }
  if ((math_aarg_hi & 0x80) != 0) {
    math_res0 = -math_res0;
    bVar2 = ~math_res1;
    bVar3 = ~math_aarg_lo;
    bVar1 = CARRY1(bVar2,'\0' < math_res0);
    math_res1 = bVar2 + ('\0' < math_res0);
    math_aarg_lo = bVar3 + bVar1;
    math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
    math_sign = ~math_sign;
  }
  __divu32();
  if ((math_aarg_hi & 0x80) == 0) {
    if ((math_sign & 0x80) != 0) {
      math_res0 = -math_res0;
      bVar2 = ~math_res1;
      bVar3 = ~math_aarg_lo;
      bVar1 = CARRY1(bVar2,'\0' < math_res0);
      math_res1 = bVar2 + ('\0' < math_res0);
      math_aarg_lo = bVar3 + bVar1;
      math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
      math_tmp2 = -math_tmp2;
      bVar2 = ~math_tmp3;
      bVar3 = ~math_rem_lo;
      bVar1 = CARRY1(bVar2,'\0' < math_tmp2);
      math_tmp3 = bVar2 + ('\0' < math_tmp2);
      math_rem_lo = bVar3 + bVar1;
      math_rem_hi = ~math_rem_hi + CARRY1(bVar3,bVar1);
      return 0;
    }
    return 0;
  }
  uVar4 = mod_frag_f478();
  return uVar4;
}


// ===== 0x00f424 mod_frag_f424 =====

/* WARNING: Instruction at (CODE,0x00f452) overlaps instruction at (CODE,0x00f450)
    */
/* Auto: compiler fragment: NEGF 0x000b,ACCESS ; COMF 0x000c,f,ACCESS ; COMF 0x000d,f,ACCESS ; COMF
   0x000e,f,ACCESS ; ADDWFC 0x000c,f,ACCESS ; ADDWFC 0x000d,f,ACCESS ; ADDWFC 0x000e,f,ACCESS ; COMF
   0x0000,f,ACCESS ; BTFSS 0x0009,#0x7,ACCESS ; GOTO 0x00f44a */

undefined1 mod_frag_f424(byte param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  bool bVar4;
  bool bVar5;
  
  math_aarg_b3 = -math_aarg_b3;
  bVar4 = '\0' < math_aarg_b3;
  bVar1 = ~math_barg_b0;
  bVar2 = ~math_barg_lo;
  bVar5 = CARRY1(bVar1,bVar4) || CARRY1(param_1,bVar1 + bVar4);
  math_barg_b0 = bVar1 + param_1 + bVar4;
  math_barg_lo = bVar2 + param_1 + bVar5;
  math_barg_hi = ~math_barg_hi + param_1 + (CARRY1(bVar2,bVar5) || CARRY1(param_1,bVar2 + bVar5));
  bVar1 = ~math_sign;
  if ((math_aarg_hi & 0x80) != 0) {
    math_res0 = -math_res0;
    bVar4 = '\0' < math_res0;
    bVar1 = ~math_res1;
    bVar2 = ~math_aarg_lo;
    bVar5 = CARRY1(bVar1,bVar4) || CARRY1(param_1,bVar1 + bVar4);
    math_res1 = bVar1 + param_1 + bVar4;
    math_aarg_lo = bVar2 + param_1 + bVar5;
    math_aarg_hi = ~math_aarg_hi + param_1 + (CARRY1(bVar2,bVar5) || CARRY1(param_1,bVar2 + bVar5));
    bVar1 = math_sign;
  }
  math_sign = bVar1;
  __divu32();
  if ((math_aarg_hi & 0x80) == 0) {
    if ((math_sign & 0x80) != 0) {
      math_res0 = -math_res0;
      bVar1 = ~math_res1;
      bVar2 = ~math_aarg_lo;
      bVar4 = CARRY1(bVar1,'\0' < math_res0);
      math_res1 = bVar1 + ('\0' < math_res0);
      math_aarg_lo = bVar2 + bVar4;
      math_aarg_hi = ~math_aarg_hi + CARRY1(bVar2,bVar4);
      math_tmp2 = -math_tmp2;
      bVar1 = ~math_tmp3;
      bVar2 = ~math_rem_lo;
      bVar4 = CARRY1(bVar1,'\0' < math_tmp2);
      math_tmp3 = bVar1 + ('\0' < math_tmp2);
      math_rem_lo = bVar2 + bVar4;
      math_rem_hi = ~math_rem_hi + CARRY1(bVar2,bVar4);
      return 0;
    }
    return 0;
  }
  uVar3 = mod_frag_f478();
  return uVar3;
}


// ===== 0x00f43a mod_to___divu32_f43a =====

/* WARNING: Instruction at (CODE,0x00f452) overlaps instruction at (CODE,0x00f450)
    */
/* Auto: calls __divu32; 11 instr */

undefined1 mod_to___divu32_f43a(byte param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  bool bVar4;
  bool bVar5;
  
  math_res0 = -math_res0;
  bVar4 = '\0' < math_res0;
  bVar1 = ~math_res1;
  bVar2 = ~math_aarg_lo;
  bVar5 = CARRY1(bVar1,bVar4) || CARRY1(param_1,bVar1 + bVar4);
  math_res1 = bVar1 + param_1 + bVar4;
  math_aarg_lo = bVar2 + param_1 + bVar5;
  math_aarg_hi = ~math_aarg_hi + param_1 + (CARRY1(bVar2,bVar5) || CARRY1(param_1,bVar2 + bVar5));
  math_sign = ~math_sign;
  __divu32();
  if ((math_aarg_hi & 0x80) != 0) {
    uVar3 = mod_frag_f478();
    return uVar3;
  }
  if ((math_sign & 0x80) == 0) {
    return 0;
  }
  math_res0 = -math_res0;
  bVar1 = ~math_res1;
  bVar2 = ~math_aarg_lo;
  bVar4 = CARRY1(bVar1,'\0' < math_res0);
  math_res1 = bVar1 + ('\0' < math_res0);
  math_aarg_lo = bVar2 + bVar4;
  math_aarg_hi = ~math_aarg_hi + CARRY1(bVar2,bVar4);
  math_tmp2 = -math_tmp2;
  bVar1 = ~math_tmp3;
  bVar2 = ~math_rem_lo;
  bVar4 = CARRY1(bVar1,'\0' < math_tmp2);
  math_tmp3 = bVar1 + ('\0' < math_tmp2);
  math_rem_lo = bVar2 + bVar4;
  math_rem_hi = ~math_rem_hi + CARRY1(bVar2,bVar4);
  return 0;
}


// ===== 0x00f454 mod_frag_f454 =====

/* Auto: compiler fragment: BTFSS 0x0000,#0x7,ACCESS ; RETLW #0x0 */

undefined1 mod_frag_f454(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  if ((math_sign & 0x80) == 0) {
    return 0;
  }
  math_res0 = -math_res0;
  bVar2 = ~math_res1;
  bVar3 = ~math_aarg_lo;
  bVar1 = CARRY1(bVar2,'\0' < math_res0);
  math_res1 = bVar2 + ('\0' < math_res0);
  math_aarg_lo = bVar3 + bVar1;
  math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
  math_tmp2 = -math_tmp2;
  bVar2 = ~math_tmp3;
  bVar3 = ~math_rem_lo;
  bVar1 = CARRY1(bVar2,'\0' < math_tmp2);
  math_tmp3 = bVar2 + ('\0' < math_tmp2);
  math_rem_lo = bVar3 + bVar1;
  math_rem_hi = ~math_rem_hi + CARRY1(bVar3,bVar1);
  return 0;
}


// ===== 0x00f458 mod_frag_f458 =====

/* Auto: compiler fragment: NEGF 0x0006,ACCESS ; COMF 0x0007,f,ACCESS ; COMF 0x0008,f,ACCESS ; COMF
   0x0009,f,ACCESS ; CLRF WREG,ACCESS ; ADDWFC 0x0007,f,ACCESS ; ADDWFC 0x0008,f,ACCESS ; ADDWFC
   0x0009,f,ACCESS ; NEGF 0x0002,ACCESS ; COMF 0x0003,f,ACCESS ; CO */

undefined1 mod_frag_f458(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  math_res0 = -math_res0;
  bVar2 = ~math_res1;
  bVar3 = ~math_aarg_lo;
  bVar1 = CARRY1(bVar2,'\0' < math_res0);
  math_res1 = bVar2 + ('\0' < math_res0);
  math_aarg_lo = bVar3 + bVar1;
  math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
  math_tmp2 = -math_tmp2;
  bVar2 = ~math_tmp3;
  bVar3 = ~math_rem_lo;
  bVar1 = CARRY1(bVar2,'\0' < math_tmp2);
  math_tmp3 = bVar2 + ('\0' < math_tmp2);
  math_rem_lo = bVar3 + bVar1;
  math_rem_hi = ~math_rem_hi + CARRY1(bVar3,bVar1);
  return 0;
}


// ===== 0x00f478 mod_frag_f478 =====

/* WARNING: Instruction at (CODE,0x00f47c) overlaps instruction at (CODE,0x00f47a)
    */
/* Auto: compiler fragment: BTFSC 0x0000,#0x7,ACCESS ; GOTO 0x00f458 */

undefined1 mod_frag_f478(void)

{
  undefined1 uVar1;
  
  if ((math_sign & 0x80) != 0) {
    uVar1 = mod_frag_f458();
    return uVar1;
  }
  math_flags = math_flags | 0x10;
  return 0xff;
}


// ===== 0x00f47e mod_frag_f47e =====

/* Auto: compiler fragment: BSF 0x0001,#0x4,ACCESS ; RETLW #0xff */

undefined1 mod_frag_f47e(void)

{
  math_flags = math_flags | 0x10;
  return 0xff;
}


// ===== 0x00f482 __mul16x16_32 =====

/* WARNING: Instruction at (CODE,0x00f4c4) overlaps instruction at (CODE,0x00f4c2)
    */
/* C18 runtime: 16x16 -> 32-bit multiply */

undefined1 __mul16x16_32(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  bool bVar9;
  
  bVar2 = math_aarg_hi;
  math_tmp13 = math_aarg_hi;
  math_tmp12 = math_aarg_lo;
  bVar6 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_lo >> 8);
  math_res0 = (char)((ushort)math_barg_lo * (ushort)math_aarg_lo);
  bVar3 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_hi);
  bVar4 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi);
  bVar8 = CARRY1(bVar6,bVar4);
  bVar6 = bVar6 + bVar4;
  bVar7 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi >> 8);
  bVar4 = bVar3 + bVar7 + bVar8;
  bVar5 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo);
  bVar9 = CARRY1(bVar6,bVar5);
  math_res1 = bVar6 + bVar5;
  bVar5 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo >> 8);
  bVar6 = bVar4 + bVar5 + bVar9;
  cVar1 = (char)((ushort)math_barg_hi * (ushort)math_aarg_hi >> 8) +
          (CARRY1(bVar3,bVar8) || CARRY1(bVar7,bVar3 + bVar8)) +
          (CARRY1(bVar4,bVar9) || CARRY1(bVar5,bVar4 + bVar9));
  bVar4 = bVar6;
  if ((math_barg_hi & 0x80) != 0) {
    bVar4 = bVar6 - math_aarg_lo;
    cVar1 = (cVar1 - math_aarg_hi) - ~(math_aarg_lo <= bVar6);
  }
  math_aarg_hi = cVar1;
  math_aarg_lo = bVar4;
  if ((bVar2 & 0x80) != 0) {
    bVar8 = math_barg_lo <= math_aarg_lo;
    math_aarg_lo = math_aarg_lo - math_barg_lo;
    math_aarg_hi = (math_aarg_hi - math_barg_hi) - ~bVar8;
    return 0;
  }
  return 0;
}


// ===== 0x00f4c6 mod_compare_multibyte_f4c6 =====

/* Auto: compiler fragment: MOVF 0x0012,w,ACCESS ; SUBWF 0x0008,f,ACCESS ; MOVF 0x0013,w,ACCESS ;
   SUBWFB 0x0009,f,ACCESS ; BTFSS 0x0013,#0x7,ACCESS ; RETLW #0x0 ; MOVF 0x000d,w,ACCESS ; SUBWF
   0x0008,f,ACCESS ; MOVF 0x000e,w,ACCESS ; SUBWFB 0x0009,f,ACCESS ;  */

undefined1 mod_compare_multibyte_f4c6(void)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = math_tmp12 <= math_aarg_lo;
  bVar1 = math_aarg_lo - math_tmp12;
  math_aarg_lo = bVar1;
  math_aarg_hi = (math_aarg_hi - math_tmp13) - ~bVar2;
  if ((math_tmp13 & 0x80) == 0) {
    return 0;
  }
  math_aarg_lo = bVar1 - math_barg_lo;
  math_aarg_hi = (math_aarg_hi - math_barg_hi) - ~(math_barg_lo <= bVar1);
  return 0;
}


// ===== 0x00f4dc __mul16 =====

/* C18 runtime: 16 x 16 bit multiply */

undefined1 __mul16(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  bool bVar7;
  
  math_tmp12 = math_aarg_lo;
  bVar4 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_lo >> 8);
  math_res0 = (char)((ushort)math_barg_lo * (ushort)math_aarg_lo);
  bVar1 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_hi);
  bVar2 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi);
  bVar6 = CARRY1(bVar4,bVar2);
  bVar4 = bVar4 + bVar2;
  bVar5 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi >> 8);
  bVar2 = bVar1 + bVar5 + bVar6;
  bVar3 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo);
  bVar7 = CARRY1(bVar4,bVar3);
  math_res1 = bVar4 + bVar3;
  bVar4 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo >> 8);
  math_aarg_lo = bVar2 + bVar4 + bVar7;
  math_aarg_hi = (char)((ushort)math_barg_hi * (ushort)math_aarg_hi >> 8) +
                 (CARRY1(bVar1,bVar6) || CARRY1(bVar5,bVar1 + bVar6)) +
                 (CARRY1(bVar2,bVar7) || CARRY1(bVar4,bVar2 + bVar7));
  return 0;
}


// ===== 0x00f518 memcpypgm2ram =====

/* C18 runtime: copy ROM to RAM */

undefined1 memcpypgm2ram(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_00000002;
  undefined1 in_FramePointer1_00000004;
  undefined1 in_FramePointer1_0000fffc;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar5 = (undefined1 *)
           CONCAT12(in_FramePointer1_00000000,
                    CONCAT11(in_FramePointer1_0000fffe,in_FramePointer1_0000fffc));
  puVar2 = &FramePointer10x0005;
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_00000004,in_FramePointer1_00000002);
  do {
    puVar1 = puVar2 + 1;
    if (puVar2[-6] == '\0') {
      puVar1 = puVar2 + 2;
      if (puVar2[-4] == '\0') {
        return 0;
      }
    }
    puVar2 = puVar1 + 2;
    puVar1[-6] = puVar1[-5] + -1;
    if (puVar1[-5] == '\0') {
      puVar2 = puVar1 + 4;
      puVar1[-3] = puVar1[-2] + -1;
    }
    uVar4 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar4;
    puVar3 = puVar3 + 1;
  } while( true );
}


// ===== 0x00f55e mod_frag_f55e =====

/* Auto: compiler fragment: MOVLW #0xfe ; MOVFF PLUSW1,FSR0L ; MOVLW #0xff ; MOVFF PLUSW1,FSR0H ;
   MOVFF FSR0L,PRODL ; MOVFF FSR0H,PRODH ; MOVLW #0xfb ; MOVF PLUSW1,w,ACCESS ; BNZ 0x00f57e ; MOVLW
   #0xfc ; MOVF PLUSW1,w,ACCESS ; BZ 0x00f590 ; MOVLW #0xfb ; DEC */

undefined1 mod_frag_f55e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined1 in_FramePointer1_00000001;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar1 = &FramePointer10x0002;
  puVar4 = (undefined1 *)CONCAT11(in_FramePointer1_00000001,in_FramePointer1_0000ffff);
  do {
    pcVar2 = puVar1 + 1;
    if (puVar1[-4] == '\0') {
      pcVar2 = puVar1 + 2;
      if (puVar1[-2] == '\0') {
        return 0;
      }
    }
    pcVar3 = pcVar2 + 2;
    pcVar2[-4] = pcVar2[-3] + -1;
    if (pcVar2[-3] == '\0') {
      pcVar3 = pcVar2 + 4;
      pcVar2[-1] = *pcVar2 + -1;
    }
    puVar1 = pcVar3 + 1;
    *puVar4 = pcVar3[-2];
    puVar4 = puVar4 + 1;
  } while( true );
}


// ===== 0x00f592 strcpy_rom2ram =====

/* C18 runtime: copy NUL-terminated string */

undefined1 strcpy_rom2ram(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_00000002;
  undefined1 in_FramePointer1_00000004;
  undefined1 in_FramePointer1_0000fffc;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar4 = (undefined1 *)
           CONCAT12(in_FramePointer1_00000000,
                    CONCAT11(in_FramePointer1_0000fffe,in_FramePointer1_0000fffc));
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000004,in_FramePointer1_00000002);
  do {
    uVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    *pcVar2 = uVar3;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}


// ===== 0x00f5c4 mod_frag_f5c4 =====

/* Auto: compiler fragment: MOVLW #0xfe ; MOVFF PLUSW1,FSR0L ; MOVLW #0xff ; MOVFF PLUSW1,FSR0H ;
   CLRF PRODL,ACCESS ; CLRF PRODH,ACCESS ; MOVF POSTINC0,f,ACCESS ; BZ 0x00f5de ; INFSNZ
   PRODL,f,ACCESS ; INCF PRODH,f,ACCESS ; BRA 0x00f5d4 ; RETURN 0x0 */

undefined1 mod_frag_f5c4(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 in_FramePointer1_00000001;
  undefined1 in_FramePointer1_0000ffff;
  
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000001,in_FramePointer1_0000ffff);
  do {
    cVar1 = *pcVar2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}


// ===== 0x00f5e0 memcpy =====

/* C18 runtime: copy RAM to RAM */

undefined1 memcpy(void)

{
  char cVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 in_FramePointer1_00000003;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar5 = &FramePointer10x0006;
  puVar2 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  pcVar6 = (undefined1 *)CONCAT11(in_FramePointer1_00000003,(char)((ushort)in_FSR2 >> 8));
  while ((puVar3 = puVar2, puVar4 = puVar5 + 1, puVar5[-7] != '\0' ||
         (puVar4 = puVar5 + 2, puVar5[-5] != '\0'))) {
    puVar5 = puVar4 + 2;
    puVar4[-7] = puVar4[-6] + -1;
    if (puVar4[-6] == '\0') {
      puVar5 = puVar4 + 4;
      puVar4[-4] = puVar4[-3] + -1;
    }
    *pcVar6 = *puVar3;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    puVar2 = puVar3 + 1;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') {
      puVar3[1] = puVar3[1];
      puVar2 = puVar3;
      pcVar6 = pcVar7;
    }
  }
  puVar5[3] = puVar5[3];
  puVar5[3] = puVar5[3];
  return 0xff;
}


// ===== 0x00f63c mod_frag_f63c =====

/* Auto: compiler fragment: NOP ; NOP ; RETLW #0xfc */

undefined1 mod_frag_f63c(void)

{
  return 0xfc;
}


// ===== 0x00f642 mod_return_0x0c_f642 =====

/* Auto: Return constant 0x0c; 1 instr */

undefined1 mod_return_0x0c_f642(void)

{
  return 0xc;
}


// ===== 0x00f760 inlet_valve_init =====

/* Inlet valve (RH0): clear state */

undefined1 inlet_valve_init(void)

{
  inlet_valve_timeout = 0;
  inlet_valve_fault = 0;
  return 0;
}


// ===== 0x00f76a inlet_valve_open =====

/* Inlet valve (RH0): open, load TVALVEON safety timeout */

char inlet_valve_open(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((-1 < inlet_valve_fault) && ((outputs_shadow & 1) == 0)) {
    puVar2 = &FramePointer10x0001;
    inlet_valve_timeout = eeprom_read_param();
    *puVar2 = *puVar2;
    if ((outputs_enable_mask & 1) != 0) {
      bVar1 = PORTH;
      PORTH = bVar1 | RH0;
      outputs_shadow = outputs_shadow | 1;
    }
    inlet_valve_open_flag = 1;
  }
  return inlet_valve_fault;
}


// ===== 0x00f79c inlet_valve_close =====

/* Inlet valve (RH0): close, update usage counters */

undefined1 inlet_valve_close(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((outputs_shadow & 1) != 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH0;
    outputs_shadow = outputs_shadow & 0xfe;
    bVar1 = PORTH;
    PORTH = bVar1 | RH7;
    inlet_valve_open_flag = 0;
    puVar2 = &FramePointer10x0001;
    stat_counter_save();
    *puVar2 = *puVar2;
    puVar2[-1] = 0xf;
    stat_counter_save();
    *puVar2 = *puVar2;
  }
  return inlet_valve_fault;
}


// ===== 0x00f7c6 inlet_valve_count_usage =====

/* Inlet valve: per-second usage counter update while open */

void inlet_valve_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if ((outputs_shadow & 1) != 0) {
    puVar1 = &FramePointer10x0001;
    stat_counter_inc();
    *puVar1 = *puVar1;
    puVar1[-1] = 0xf;
    stat_counter_inc();
    *puVar1 = *puVar1;
  }
  return;
}


// ===== 0x00f7e2 inlet_valve_timeout_tick =====

/* Inlet valve: 10 s safety timeout countdown; closes and latches fault 0x84 */

byte inlet_valve_timeout_tick(byte param_1)

{
  byte bVar1;
  byte unaff_C;
  
  if ((outputs_shadow & 1) != 0) {
    if (inlet_valve_timeout != 0) {
      unaff_C = inlet_valve_timeout != 0;
      inlet_valve_timeout = inlet_valve_timeout - 1;
    }
    param_1 = inlet_valve_timeout;
    if (inlet_valve_timeout == 0) {
      bVar1 = PORTH;
      PORTH = bVar1 & ~RH0;
      outputs_shadow = outputs_shadow & 0xfe;
      param_1 = inlet_valve_fault << 1 | unaff_C & 1;
      if (-1 < inlet_valve_fault) {
        param_1 = 0x84;
        inlet_valve_fault = -0x7c;
      }
    }
  }
  return param_1;
}


// ===== 0x00f806 inlet_valve_is_open =====

/* Inlet valve: return open state */

undefined1 inlet_valve_is_open(void)

{
  return inlet_valve_open_flag;
}


// ===== 0x00f80c cold_valve_init =====

/* Cold water valve (RH2): clear state */

undefined1 cold_valve_init(void)

{
  cold_valve_timeout = 0;
  cold_valve_fault = 0;
  return 0;
}


// ===== 0x00f816 cold_valve_open =====

/* Cold water valve (RH2): open, load TVALVEON safety timeout */

char cold_valve_open(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((-1 < cold_valve_fault) && ((outputs_shadow & 4) == 0)) {
    puVar2 = &FramePointer10x0001;
    cold_valve_timeout = eeprom_read_param();
    *puVar2 = *puVar2;
    if ((outputs_enable_mask & 4) != 0) {
      bVar1 = PORTH;
      PORTH = bVar1 | RH2;
      outputs_shadow = outputs_shadow | 4;
    }
    cold_valve_open_flag = 1;
    cooling_abort_pulldown();
  }
  return cold_valve_fault;
}


// ===== 0x00f84c cold_valve_close =====

/* Cold water valve (RH2): close, update usage counters */

undefined1 cold_valve_close(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((outputs_shadow & 4) != 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH2;
    outputs_shadow = outputs_shadow & 0xfb;
    cold_valve_open_flag = 0;
    puVar2 = &FramePointer10x0001;
    stat_counter_save();
    *puVar2 = *puVar2;
    mod_to_cooling_reset_pulldown_d47c();
  }
  return cold_valve_fault;
}


// ===== 0x00f86e cold_valve_count_usage =====

/* Cold water valve: per-second usage counter update while open */

undefined1 cold_valve_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((outputs_shadow & 1) != 0) {
    uVar2 = 0;
    if ((outputs_shadow & 4) != 0) {
      puVar1 = &FramePointer10x0001;
      uVar2 = stat_counter_inc();
      *puVar1 = *puVar1;
    }
  }
  return uVar2;
}


// ===== 0x00f888 cold_valve_timeout_tick =====

/* Cold water valve: 10 s safety timeout countdown; closes and latches fault 0x84 */

byte cold_valve_timeout_tick(byte param_1)

{
  byte bVar1;
  byte unaff_C;
  
  if ((outputs_shadow & 4) != 0) {
    if (cold_valve_timeout != 0) {
      unaff_C = cold_valve_timeout != 0;
      cold_valve_timeout = cold_valve_timeout - 1;
    }
    param_1 = cold_valve_timeout;
    if (cold_valve_timeout == 0) {
      bVar1 = PORTH;
      PORTH = bVar1 & ~RH2;
      outputs_shadow = outputs_shadow & 0xfb;
      param_1 = cold_valve_fault << 1 | unaff_C & 1;
      if (-1 < cold_valve_fault) {
        param_1 = 0x84;
        cold_valve_fault = -0x7c;
      }
    }
  }
  return param_1;
}


// ===== 0x00f8ac cold_valve_is_open =====

/* Cold water valve: return open state */

undefined1 cold_valve_is_open(void)

{
  return cold_valve_open_flag;
}


// ===== 0x00f8b2 alarm_init =====

/* Clear UV status and alarm code */

undefined1 alarm_init(void)

{
  uv_status = 0;
  uv_alarm_code = 0;
  return 0;
}


// ===== 0x00f8bc uv_lamp_on =====

/* Switch UV lamp on (RF6) if UV fitted */

undefined1 uv_lamp_on(void)

{
  byte bVar1;
  
  if ((outputs_shadow & 0x20) == 0) {
    if ((cfg_systemconfig & 8) != 0) {
      bVar1 = PORTF;
      PORTF = bVar1 | RF6;
      outputs_shadow = outputs_shadow | 0x20;
      return uv_alarm_code;
    }
  }
  return 0;
}


// ===== 0x00f8da uv_lamp_off =====

/* Switch UV lamp off (RF6); log usage and lamp-fail counters */

undefined1 uv_lamp_off(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (((outputs_shadow & 0x20) != 0) && ((cfg_systemconfig & 8) != 0)) {
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) == 0) {
      puVar2 = &FramePointer10x0001;
      stat_counter_inc();
      *puVar2 = *puVar2;
      puVar2[-1] = 8;
      stat_counter_save();
      in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
      *puVar2 = *puVar2;
    }
    bVar1 = PORTF;
    PORTF = bVar1 & ~RF6;
    outputs_shadow = outputs_shadow & 0xdf;
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 7;
    stat_counter_save();
    *puVar3 = *puVar3;
    return uv_alarm_code;
  }
  return 0;
}


// ===== 0x00f91a uv_is_available =====

/* UV lamp fitted, not failed and fault input not tripped */

undefined1 uv_is_available(void)

{
  byte bVar1;
  
  if (((cfg_systemconfig4 & 0x20) != 0) && (bVar1 = PORTJ, (bVar1 & RJ0) != 0)) {
    return 0;
  }
  if (((uv_status & 2) == 0) && ((cfg_systemconfig & 8) != 0)) {
    return 1;
  }
  return 0;
}


// ===== 0x00f93c uv_count_usage =====

/* Per second: UV lamp usage counter while lit */

byte uv_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  bVar2 = PORTJ;
  bVar2 = bVar2 & 2;
  if (bVar2 == 0) {
    bVar2 = 0;
    if ((cfg_systemconfig & 8) != 0) {
      puVar1 = &FramePointer10x0001;
      bVar2 = stat_counter_inc();
      *puVar1 = *puVar1;
    }
  }
  return bVar2;
}


// ===== 0x00f956 _do_cinit =====

/* C18 runtime: copy initialised data (table at ROM 0x2a) into RAM */

char _do_cinit(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int3 *piVar6;
  bool bVar7;
  
  piVar6 = (int3 *)0x2c;
  DAT_DATA_01b6 = cCODE00002b;
  cVar1 = cCODE00002b;
  for (DAT_DATA_01b5 = c18_init_table; (DAT_DATA_01b6 != '\0' || (DAT_DATA_01b5 != '\0'));
      DAT_DATA_01b5 = DAT_DATA_01b5 + -1) {
    cinit_tmp = (undefined1)*piVar6;
    DAT_DATA_01b1 = *(undefined1 *)((int3)piVar6 + 1);
    DAT_DATA_01b2 = *(undefined1 *)((int3)piVar6 + 2);
    puVar5 = (undefined1 *)*piVar6;
    puVar2 = *(undefined1 **)(piVar6 + 1);
    DAT_DATA_01b3 = (char)piVar6[2];
    DAT_DATA_01b4 = *(char *)((int3)piVar6 + 9);
    piVar6 = piVar6 + 3;
    DAT_DATA_01b7 = SUB31(piVar6,0);
    DAT_DATA_01b8 = (undefined1)((uint3)piVar6 >> 8);
    DAT_DATA_01b9 = (undefined1)((uint3)piVar6 >> 0x10);
    while ((puVar3 = puVar2, DAT_DATA_01b3 != '\0' || (DAT_DATA_01b4 != '\0'))) {
      while( true ) {
        uVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar2 = puVar3 + 1;
        *puVar3 = uVar4;
        bVar7 = DAT_DATA_01b3 != '\0';
        DAT_DATA_01b3 = DAT_DATA_01b3 + -1;
        if (bVar7) break;
        DAT_DATA_01b4 = DAT_DATA_01b4 + -1;
        puVar3 = puVar3 + 1;
      }
    }
    piVar6 = (int3 *)CONCAT12(DAT_DATA_01b9,CONCAT11(DAT_DATA_01b8,DAT_DATA_01b7));
    cVar1 = '\0';
    DAT_DATA_01b6 = DAT_DATA_01b6 - ~(DAT_DATA_01b5 != '\0');
    DAT_DATA_01b3 = 0;
  }
  return cVar1;
}


// ===== 0x00f9f4 hot_valve_init =====

/* Hot water valve (RH1): clear state */

undefined1 hot_valve_init(void)

{
  hot_valve_timeout = 0;
  hot_valve_fault = 0;
  return 0;
}


// ===== 0x00f9fe hot_valve_open =====

/* Hot water valve (RH1): open, load TVALVEON safety timeout */

char hot_valve_open(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((-1 < hot_valve_fault) && ((outputs_shadow & 2) == 0)) {
    puVar2 = &FramePointer10x0001;
    hot_valve_timeout = eeprom_read_param();
    *puVar2 = *puVar2;
    if ((outputs_enable_mask & 2) != 0) {
      bVar1 = PORTH;
      PORTH = bVar1 | RH1;
      outputs_shadow = outputs_shadow | 2;
    }
    hot_valve_open_flag = 1;
  }
  return hot_valve_fault;
}


// ===== 0x00fa30 hot_valve_close =====

/* Hot water valve (RH1): close, update usage counters */

undefined1 hot_valve_close(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((outputs_shadow & 2) != 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH1;
    outputs_shadow = outputs_shadow & 0xfd;
    hot_valve_open_flag = 0;
    puVar2 = &FramePointer10x0001;
    stat_counter_save();
    *puVar2 = *puVar2;
  }
  return hot_valve_fault;
}


// ===== 0x00fa4c hot_valve_count_usage =====

/* Hot water valve: per-second usage counter update while open */

undefined1 hot_valve_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((outputs_shadow & 1) != 0) {
    uVar2 = 0;
    if ((outputs_shadow & 2) != 0) {
      puVar1 = &FramePointer10x0001;
      uVar2 = stat_counter_inc(outputs_shadow & 2);
      *puVar1 = *puVar1;
    }
  }
  return uVar2;
}


// ===== 0x00fa64 hot_valve_timeout_tick =====

/* Hot water valve: 10 s safety timeout countdown; closes and latches fault 0x84 */

byte hot_valve_timeout_tick(byte param_1)

{
  byte bVar1;
  byte unaff_C;
  
  if ((outputs_shadow & 2) != 0) {
    if (hot_valve_timeout != 0) {
      unaff_C = hot_valve_timeout != 0;
      hot_valve_timeout = hot_valve_timeout - 1;
    }
    param_1 = hot_valve_timeout;
    if (hot_valve_timeout == 0) {
      bVar1 = PORTH;
      PORTH = bVar1 & ~RH1;
      outputs_shadow = outputs_shadow & 0xfd;
      param_1 = hot_valve_fault << 1 | unaff_C & 1;
      if (-1 < hot_valve_fault) {
        param_1 = 0x84;
        hot_valve_fault = -0x7c;
      }
    }
  }
  return param_1;
}


// ===== 0x00fa88 hot_valve_is_open =====

/* Hot water valve: return open state */

undefined1 hot_valve_is_open(void)

{
  return hot_valve_open_flag;
}


// ===== 0x00fb04 __mul32 =====

/* C18 runtime: 32-bit multiply */

char __mul32(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  bool bVar9;
  
  math_tmp2 = (char)((ushort)math_aarg_b3 * (ushort)math_res0);
  bVar7 = (byte)((ushort)math_aarg_b3 * (ushort)math_res0 >> 8);
  bVar2 = (byte)((ushort)math_barg_b0 * (ushort)math_res0);
  bVar1 = bVar7 + bVar2;
  bVar7 = (char)((ushort)math_barg_b0 * (ushort)math_res0 >> 8) + CARRY1(bVar7,bVar2);
  bVar3 = (byte)((ushort)math_barg_lo * (ushort)math_res0);
  bVar2 = bVar7 + bVar3;
  bVar4 = (byte)((ushort)math_aarg_b3 * (ushort)math_res1);
  bVar9 = CARRY1(bVar1,bVar4);
  math_tmp3 = bVar1 + bVar4;
  bVar8 = (byte)((ushort)math_aarg_b3 * (ushort)math_res1 >> 8);
  bVar4 = bVar2 + bVar8 + bVar9;
  bVar5 = (byte)((ushort)math_barg_b0 * (ushort)math_res1);
  bVar1 = bVar4 + bVar5;
  bVar6 = (byte)((ushort)math_aarg_b3 * (ushort)math_aarg_lo);
  math_rem_lo = bVar1 + bVar6;
  math_rem_hi = (char)((ushort)math_barg_lo * (ushort)math_res0 >> 8) + CARRY1(bVar7,bVar3) +
                math_barg_hi * math_res0 + (CARRY1(bVar2,bVar9) || CARRY1(bVar8,bVar2 + bVar9)) +
                (char)((ushort)math_barg_b0 * (ushort)math_res1 >> 8) + CARRY1(bVar4,bVar5) +
                math_barg_lo * math_res1 + (char)((ushort)math_aarg_b3 * (ushort)math_aarg_lo >> 8)
                + CARRY1(bVar1,bVar6) + math_barg_b0 * math_aarg_lo + math_aarg_b3 * math_aarg_hi;
  return math_aarg_b3 * math_aarg_hi;
}


// ===== 0x00fb74 __divu32 =====

/* C18 runtime: 32-bit unsigned divide */

byte __divu32(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  
  math_rem_hi = 0;
  math_rem_lo = 0;
  math_tmp3 = 0;
  math_tmp2 = 0;
  cVar6 = ' ';
  bVar3 = false;
  do {
    bVar4 = (char)math_res0 < '\0';
    math_res0 = math_res0 << 1 | bVar3;
    bVar3 = (char)math_res1 < '\0';
    math_res1 = math_res1 << 1 | bVar4;
    bVar4 = (char)math_aarg_lo < '\0';
    math_aarg_lo = math_aarg_lo << 1 | bVar3;
    bVar3 = (char)math_aarg_hi < '\0';
    math_aarg_hi = math_aarg_hi << 1 | bVar4;
    bVar4 = (char)math_tmp2 < '\0';
    math_tmp2 = math_tmp2 << 1 | bVar3;
    bVar3 = (char)math_tmp3 < '\0';
    math_tmp3 = math_tmp3 << 1 | bVar4;
    bVar4 = (char)math_rem_lo < '\0';
    math_rem_lo = math_rem_lo << 1 | bVar3;
    math_rem_hi = math_rem_hi << 1 | bVar4;
    bVar1 = ~(math_tmp3 < (byte)~(math_aarg_b3 <= math_tmp2) ||
             math_barg_b0 < math_tmp3 - ~(math_aarg_b3 <= math_tmp2));
    bVar5 = math_rem_lo < bVar1 || math_barg_lo < math_rem_lo - bVar1;
    bVar1 = ~bVar5;
    bVar4 = math_barg_hi < math_rem_hi - bVar1;
    bVar3 = math_rem_hi < bVar1 || bVar4;
    bVar2 = (math_rem_hi - math_barg_hi) - ~bVar5;
    if (math_rem_hi < bVar1 || bVar4) {
      bVar3 = math_aarg_b3 <= math_tmp2;
      math_tmp2 = math_tmp2 - math_aarg_b3;
      bVar1 = ~bVar3;
      bVar4 = math_tmp3 < bVar1 || math_barg_b0 < math_tmp3 - bVar1;
      math_tmp3 = (math_tmp3 - math_barg_b0) - ~bVar3;
      bVar1 = ~bVar4;
      bVar3 = math_rem_lo < bVar1;
      bVar1 = math_rem_lo - bVar1;
      math_rem_lo = (math_rem_lo - math_barg_lo) - ~bVar4;
      math_rem_hi = (math_rem_hi - math_barg_hi) - ~(bVar3 || math_barg_lo < bVar1);
      bVar3 = 0xfe < math_res0;
      math_res0 = math_res0 + 1;
      bVar2 = math_barg_hi;
    }
    cVar6 = cVar6 + -1;
  } while (cVar6 != '\0');
  return bVar2;
}


// ===== 0x00fbbc __divu16 =====

/* C18 runtime: unsigned 16-bit divide, remainder in math_rem */

byte __divu16(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  
  math_rem_hi = 0;
  math_rem_lo = 0;
  cVar5 = '\x10';
  bVar3 = false;
  do {
    bVar4 = (char)math_aarg_lo < '\0';
    math_aarg_lo = math_aarg_lo << 1 | bVar3;
    bVar3 = (char)math_aarg_hi < '\0';
    math_aarg_hi = math_aarg_hi << 1 | bVar4;
    bVar4 = (char)math_rem_lo < '\0';
    math_rem_lo = math_rem_lo << 1 | bVar3;
    math_rem_hi = math_rem_hi << 1 | bVar4;
    bVar1 = ~(math_barg_lo <= math_rem_lo);
    bVar4 = math_barg_hi < math_rem_hi - bVar1;
    bVar3 = math_rem_hi < bVar1 || bVar4;
    bVar2 = (math_rem_hi - math_barg_hi) - ~(math_barg_lo <= math_rem_lo);
    if (math_rem_hi < bVar1 || bVar4) {
      bVar3 = math_barg_lo <= math_rem_lo;
      math_rem_lo = math_rem_lo - math_barg_lo;
      math_rem_hi = (math_rem_hi - math_barg_hi) - ~bVar3;
      bVar3 = 0xfe < math_aarg_lo;
      math_aarg_lo = math_aarg_lo + 1;
      bVar2 = math_barg_hi;
    }
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  return bVar2;
}


// ===== 0x00fbe8 mod_frag_fbe8 =====

/* Auto: compiler fragment: MOVLW #0x0 ; MOVWF PRODL,ACCESS ; LFSR FSR0,#0x0 ; MOVLW #0xf ; RCALL
   0x00fbf6 ; RETURN 0x0 */

void mod_frag_fbe8(void)

{
  mod_frag_fbf6(0xf);
  return;
}


// ===== 0x00fbf6 mod_frag_fbf6 =====

/* Auto: compiler fragment: CPFSLT FSR0H,ACCESS ; BRA 0x00fbfe ; CLRF POSTINC0,ACCESS ; BRA 0x00fbf6
   ; MOVF PRODL,w,ACCESS ; CPFSLT FSR0L,ACCESS ; RETURN 0x0 ; CLRF POSTINC0,ACCESS ; BRA 0x00fc00 */

void mod_frag_fbf6(byte param_1)

{
  BADSPACEBASE *in_FSR0;
  byte in_PRODL;
  
  for (; (byte)((ushort)in_FSR0 >> 8) < param_1; in_FSR0 = (BADSPACEBASE *)((short)in_FSR0 + 1)) {
    *(undefined1 *)in_FSR0 = 0;
  }
  for (; (byte)in_FSR0 < in_PRODL; in_FSR0 = (BADSPACEBASE *)((short)in_FSR0 + 1)) {
    *(undefined1 *)in_FSR0 = 0;
  }
  return;
}


// ===== 0x00fc08 c018_startup =====

/* C18 startup: runs _do_cinit then loops calling main() */

void c018_startup(void)

{
  math_flags = math_flags & 0xbf;
  _do_cinit();
  do {
    user_init_hook();
    main();
  } while( true );
}


// ===== 0x00fc22 mod_return_void_fc22 =====

/* Auto: Empty function (return); 1 instr */

void mod_return_void_fc22(void)

{
  return;
}


// ===== 0x00fc24 mod_shift_multibyte_fc24 =====

/* Auto: compiler fragment: CLRF 0x0005,ACCESS ; MOVLW #0x8 ; MOVWF INDF1,ACCESS ; BCF
   STATUS,#0x0,ACCESS ; RLCF 0x0009,f,ACCESS ; RLCF 0x0005,f,ACCESS ; MOVF 0x000e,w,ACCESS ; SUBWF
   0x0005,w,ACCESS ; BNC 0x00fc3a ; MOVWF 0x0005,ACCESS ; INCF 0x0009,f,ACCESS */

byte mod_shift_multibyte_fc24(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  
  math_rem_hi = 0;
  cVar4 = '\b';
  bVar3 = false;
  do {
    bVar1 = math_aarg_hi << 1 | bVar3;
    bVar2 = math_rem_hi << 1 | (char)math_aarg_hi < '\0';
    math_rem_hi = bVar2;
    math_aarg_hi = bVar1;
    if (math_barg_hi <= bVar2) {
      math_aarg_hi = bVar1 + 1;
      math_rem_hi = bVar2 - math_barg_hi;
    }
    bVar3 = math_barg_hi <= bVar2 && 0xfe < bVar1;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return bVar2 - math_barg_hi;
}


// ===== 0x00fc40 uv_service_clear =====

/* Clear UV service override */

undefined1 uv_service_clear(void)

{
  uv_service_override = 0;
  return 0;
}


// ===== 0x00fc48 uv_service_on =====

/* Drive RF5 high (UV service/test) and clear override */

undefined1 uv_service_on(void)

{
  byte bVar1;
  
  bVar1 = PORTF;
  PORTF = bVar1 | RF5;
  uv_service_override = 0;
  return 0;
}


// ===== 0x00fc52 uv_service_off =====

/* Drive RF5 low and set override flag (0x80) */

undefined1 uv_service_off(void)

{
  byte bVar1;
  
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF5;
  uv_service_override = 0x80;
  return 0;
}


// ===== 0x00fc70 mod_jump_fnfc76_fc70 =====

/* Auto: Jump to 0xfc76; 1 instr */

undefined1 mod_jump_fnfc76_fc70(void)

{
  unused_1fd = 0;
  return 0;
}


// ===== 0x00fc72 mod_jump_fnfc76_fc72 =====

/* Auto: Jump to 0xfc76; 1 instr */

undefined1 mod_jump_fnfc76_fc72(void)

{
  unused_1fd = 0;
  return 0;
}


// ===== 0x00fc74 mod_jump_fnfc76_fc74 =====

/* Auto: Jump to 0xfc76; 1 instr */

undefined1 mod_jump_fnfc76_fc74(void)

{
  unused_1fd = 0;
  return 0;
}


// ===== 0x00fc76 mod_set_r1fd_0_fc76 =====

/* Auto: Set 0x1fd = 0; 4 instr */

undefined1 mod_set_r1fd_0_fc76(void)

{
  unused_1fd = 0;
  return 0;
}


// ===== 0x00fc7e mod_jump_fnfc84_fc7e =====

/* Auto: Jump to 0xfc84; 1 instr */

undefined1 mod_jump_fnfc84_fc7e(void)

{
  unused_203 = 0;
  return 0;
}


// ===== 0x00fc80 mod_jump_fnfc84_fc80 =====

/* Auto: Jump to 0xfc84; 1 instr */

undefined1 mod_jump_fnfc84_fc80(void)

{
  unused_203 = 0;
  return 0;
}


// ===== 0x00fc82 mod_jump_fnfc84_fc82 =====

/* Auto: Jump to 0xfc84; 1 instr */

undefined1 mod_jump_fnfc84_fc82(void)

{
  unused_203 = 0;
  return 0;
}


// ===== 0x00fc84 mod_set_r203_0_fc84 =====

/* Auto: Set 0x203 = 0; 4 instr */

undefined1 mod_set_r203_0_fc84(void)

{
  unused_203 = 0;
  return 0;
}


// ===== 0x00fc8c mod_set_r1fe_0_fc8c =====

/* Auto: Set 0x1fe = 0; 4 instr */

undefined1 mod_set_r1fe_0_fc8c(void)

{
  unused_1fe = 0;
  return 0;
}


// ===== 0x00fc94 mod_return_0x01_fc94 =====

/* Auto: Return constant 0x01; 1 instr */

undefined1 mod_return_0x01_fc94(void)

{
  return 1;
}


// ===== 0x00fc96 mod_return_0x00_fc96 =====

/* Auto: Return constant 0x00; 1 instr */

undefined1 mod_return_0x00_fc96(void)

{
  return 0;
}


// ===== 0x00fc98 mod_set_r0ff_0_fc98 =====

/* Auto: Set 0xff = 0; 4 instr */

undefined1 mod_set_r0ff_0_fc98(void)

{
  unused_0ff = 0;
  return 0;
}


// ===== 0x00fca0 mod_return_0x01_fca0 =====

/* Auto: Return constant 0x01; 1 instr */

undefined1 mod_return_0x01_fca0(void)

{
  return 1;
}


// ===== 0x00fca2 mod_set_r202_0_fca2 =====

/* Auto: Set 0x202 = 0; 4 instr */

undefined1 mod_set_r202_0_fca2(void)

{
  unused_202 = 0;
  return 0;
}


// ===== 0x00fcaa mod_return_0x01_fcaa =====

/* Auto: Return constant 0x01; 1 instr */

undefined1 mod_return_0x01_fcaa(void)

{
  return 1;
}


// ===== 0x00fcac mod_set_r200_0_fcac =====

/* Auto: Set 0x200 = 0; 4 instr */

undefined1 mod_set_r200_0_fcac(void)

{
  unused_200 = 0;
  return 0;
}


// ===== 0x00fcbc user_init_hook =====

/* Empty startup hook called before main() */

void user_init_hook(void)

{
  return;
}


