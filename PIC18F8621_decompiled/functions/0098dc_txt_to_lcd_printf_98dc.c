// address 0x0098dc  size 32 bytes
// callers: 009a9c,

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

