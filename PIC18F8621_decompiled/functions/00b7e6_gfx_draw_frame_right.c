// address 0x00b7e6  size 116 bytes
// callers: 004c6e,

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

