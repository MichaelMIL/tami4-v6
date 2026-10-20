// address 0x001ae2  size 104 bytes
// callers: 0020de,004264,003584,0029ac,0017c4,002ba4,002986,0001a8,0013e8,0022dc,

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

