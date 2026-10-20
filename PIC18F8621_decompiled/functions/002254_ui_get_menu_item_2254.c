// address 0x002254  size 28 bytes
// callers: 000f94,002020,00037c,

/* Auto: reads menu_item,TBLPTRL,TBLPTRH; 12 instr */

void ui_get_menu_item_2254(void)

{
  byte unaff_BSR;
  short sVar1;
  
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_c18_tmp0_2b52(10);
  sVar1 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x27) * 2;
  ui_get_menu_table_ptr_lo_2a64
            ((char)((ushort)sVar1 >> 8) + c18_tmp1 + CARRY1((byte)sVar1,c18_tmp0));
  return;
}

