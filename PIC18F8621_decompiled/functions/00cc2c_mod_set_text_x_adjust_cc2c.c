// address 0x00cc2c  size 46 bytes
// callers: 00cc5a,0094d8,

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

