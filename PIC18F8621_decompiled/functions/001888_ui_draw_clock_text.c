// address 0x001888  size 128 bytes
// callers: 001908,001974,

/* WARNING: Removing unreachable block (CODE,0x00189e) */
/* Draw clock text "%02b:%02b %s" */

void ui_draw_clock_text(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  bool bVar5;
  
  ui_c18_prologue_2166();
  if (menu_page == '\x02') {
    ui_get_menu_tmp_a_2aa2(0);
    ui_stack_adjust_2b26(0x80);
    puVar1 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0xa9;
    c18_tmp0 = ui_callw_txt_set_ui_hold_counter_2b10(0x58);
    uVar4 = c18_tmp0;
    if ((byte)puVar1 < 6) {
      *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
      uVar4 = c18_tmp0;
    }
  }
  else {
    bVar5 = menu_page != '\0';
    if (bVar5) {
      c18_tmp0 = 0xc1;
    }
    else {
      c18_tmp0 = 0xc4;
    }
    c18_tmp1 = 0x58;
    *(undefined1 *)in_FSR1 = c18_tmp0;
    puVar2 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = 0x58;
    ui_get_menu_tmp_a_2aa2();
    if (bVar5) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x80;
    }
    ui_stack_adjust_2b26(uVar4);
    puVar3 = puVar2 + 1;
    *puVar2 = 0x9c;
    c18_tmp2 = ui_callw_txt_set_ui_hold_counter_2b10(0x58);
    uVar4 = c18_tmp2;
    if ((byte)puVar3 < 8) {
      *(undefined1 *)((ushort)puVar3 & 0xff00) = *(undefined1 *)((ushort)puVar3 & 0xff00);
      uVar4 = c18_tmp2;
    }
  }
  ui_c18_epilogue_21d8(uVar4);
  return;
}

