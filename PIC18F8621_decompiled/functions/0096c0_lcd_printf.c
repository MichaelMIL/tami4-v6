// address 0x0096c0  size 540 bytes
// callers: 0098dc,009936,

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

