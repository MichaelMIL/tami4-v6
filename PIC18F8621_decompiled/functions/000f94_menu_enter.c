// address 0x000f94  size 124 bytes
// callers: 002d86,

/* WARNING: Removing unreachable block (CODE,0x00102c) */
/* WARNING: Removing unreachable block (CODE,0x001022) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Open the menu (table at ROM 0xE49E) and call its enter callback */

undefined1 menu_enter(void)

{
  byte bVar1;
  undefined3 in_TBLPTR;
  undefined1 uVar3;
  undefined1 *puVar2;
  
  uVar3 = (undefined1)((uint3)in_TBLPTR >> 0x10);
  if ((menu_cb_enter_hi | menu_cb_enter) == 0) {
    if ((menu_table_ptr_hi | menu_table_ptr_lo) != 0) {
      ui_get_menu_table_ptr_lo_2b3c(menu_table_ptr_hi | menu_table_ptr_lo);
      ui_get_c18_tmp2_2398(0x18);
      ui_get_menu_item_2296();
      c18_tmp2 = menu_table_ptr_lo + 0x18;
      c18_tmp3 = menu_table_ptr_hi + (0xe7 < menu_table_ptr_lo);
      bVar1 = (byte)((ushort)menu_item * 2);
      puVar2 = (undefined1 *)
               CONCAT12(uVar3,CONCAT11((char)((ushort)menu_item * 2 >> 8) + c18_tmp3 +
                                       CARRY1(bVar1,c18_tmp2),bVar1 + c18_tmp2));
      c18_tmp0 = *puVar2;
      c18_tmp1 = puVar2[1];
      ui_set_menu_item_1016();
      return 1;
    }
    menu_table_ptr_lo = 0x9e;
    menu_table_ptr_hi = 0xe4;
    menu_item = 0;
    menu_draw();
    return 0;
  }
  menu_call_enter_cb(menu_cb_enter_hi | menu_cb_enter);
  if ((menu_table_ptr_hi == 0 && menu_table_ptr_lo == 0) && (menu_mode == '\0')) {
    return 0x80;
  }
  return 1;
}

