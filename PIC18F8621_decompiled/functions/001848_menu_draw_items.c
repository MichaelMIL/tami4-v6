// address 0x001848  size 64 bytes
// callers: 001848,

/* Draw menu item list with highlight on selected item */

void menu_draw_items(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar3;
  undefined1 *in_TBLPTR;
  
  uVar3 = c18_tmp0;
  do {
    menu_draw_items(uVar3);
    while( true ) {
      puVar2 = (undefined1 *)((short)in_FSR1 + -1);
      *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
      *(char *)in_FSR2 = *(char *)in_FSR2 + '\x01';
      cVar1 = *(byte *)in_FSR2 - menu_item_count;
      if (menu_item_count <= *(byte *)in_FSR2) {
        *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
        ui_c18_epilogue_21d8(cVar1);
        return;
      }
      ui_get_menu_table_ptr_lo_2b3c();
      ui_get_TBLPTRL_2c14(0x24);
      ui_get_c18_tmp0_29d6();
      if (cVar1 != '\0') break;
      ui_set_ui_wake_pending_244a(*(char *)in_FSR2 + '\x02');
      if (*(char *)in_FSR2 == menu_item) {
        uVar3 = 0x80;
      }
      else {
        uVar3 = 0;
      }
      ui_to_ui_get_menu_table_ptr_lo_29cc(uVar3);
      uVar3 = ui_get_TBLPTRL_29e8(*(undefined1 *)in_FSR2);
      in_FSR1 = (BADSPACEBASE *)(puVar2 + 1);
      *puVar2 = uVar3;
      ui_to_txt_set_ui_hold_counter_28b4();
    }
    uVar3 = 0;
    in_TBLPTR = (undefined1 *)
                CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                         CONCAT11(menu_table_ptr_hi + (0xdb < menu_table_ptr_lo),
                                  menu_table_ptr_lo + 0x24));
    c18_tmp0 = *in_TBLPTR;
    in_TBLPTR = in_TBLPTR + 1;
    c18_tmp1 = *in_TBLPTR;
    in_FSR1 = (BADSPACEBASE *)(puVar2 + 1);
    *puVar2 = *(undefined1 *)in_FSR2;
  } while( true );
}

