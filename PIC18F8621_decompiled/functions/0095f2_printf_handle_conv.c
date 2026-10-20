// address 0x0095f2  size 206 bytes
// callers: 0096c0,

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

