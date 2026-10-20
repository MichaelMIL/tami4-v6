// address 0x001582  size 90 bytes
// callers: 001732,0016d2,

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

