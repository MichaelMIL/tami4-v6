// address 0x0003f6  size 90 bytes
// callers: 002b86,

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

