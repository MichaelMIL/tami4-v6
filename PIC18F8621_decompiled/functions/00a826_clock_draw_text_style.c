// address 0x00a826  size 90 bytes
// callers: 00a312,00a588,

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

