// address 0x0017c4  size 132 bytes
// callers: 001096,001038,001524,0014d6,00037c,0003e2,0003cc,000f94,00106e,0013d8,001bf2,002020,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw current menu (title and items) */

void menu_draw(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  byte in_TABLAT;
  byte *in_TBLPTR;
  bool bVar6;
  
  ui_stack_adjust_2af8();
  bVar2 = in_TABLAT;
  ui_to_ui_get_menu_table_ptr_lo_2628();
  c18_tmp0 = bVar2;
  c18_tmp1 = 0;
  if ((c18_tmp0 ^ 0xff) == 0) {
    menu_item_count = 0;
    while( true ) {
      ui_get_menu_table_ptr_lo_2b3c();
      ui_get_c18_tmp0_2b52(4);
      bVar6 = menu_item_count == 0;
      ui_get_TBLPTRL_2b68(menu_item_count);
      if (bVar6) break;
      menu_item_count = menu_item_count + 1;
    }
  }
  else {
    bVar2 = c18_tmp0;
    ui_to_ui_get_menu_table_ptr_lo_2628(c18_tmp0 ^ 0xff);
    menu_item_count = bVar2;
  }
  lcd_clear();
  ui_get_TBLPTRL_22ba();
  ui_draw_title();
  puVar3 = (undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)in_FSR2 = 0;
  while( true ) {
    cVar1 = *(byte *)in_FSR2 - menu_item_count;
    if (menu_item_count <= *(byte *)in_FSR2) break;
    ui_get_menu_table_ptr_lo_2b3c();
    ui_get_TBLPTRL_2c14(0x24);
    ui_get_c18_tmp0_29d6();
    if (cVar1 == '\0') {
      ui_set_ui_wake_pending_244a(*(char *)in_FSR2 + '\x02');
      if (*(char *)in_FSR2 == menu_item) {
        uVar5 = 0x80;
      }
      else {
        uVar5 = 0;
      }
      ui_to_ui_get_menu_table_ptr_lo_29cc(uVar5);
      uVar5 = ui_get_TBLPTRL_29e8(*(undefined1 *)in_FSR2);
      puVar4 = puVar3 + 1;
      *puVar3 = uVar5;
      ui_to_txt_set_ui_hold_counter_28b4();
    }
    else {
      in_TBLPTR = (byte *)CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                                   CONCAT11(menu_table_ptr_hi + (0xdb < menu_table_ptr_lo),
                                            menu_table_ptr_lo + 0x24));
      c18_tmp0 = *in_TBLPTR;
      in_TBLPTR = in_TBLPTR + 1;
      c18_tmp1 = *in_TBLPTR;
      puVar4 = puVar3 + 1;
      *puVar3 = *(undefined1 *)in_FSR2;
      menu_draw_items();
    }
    puVar3 = puVar4 + -1;
    *puVar4 = *puVar4;
    *(char *)in_FSR2 = *(char *)in_FSR2 + '\x01';
  }
  *puVar3 = *puVar3;
  ui_c18_epilogue_21d8(cVar1);
  return;
}

