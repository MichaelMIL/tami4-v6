// address 0x00127a  size 86 bytes
// callers: (none: entry point, task, or reached via pointer)

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

