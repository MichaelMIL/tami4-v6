// address 0x002296  size 20 bytes
// callers: 000f94,002020,00037c,

/* Auto: reads menu_item,TBLPTRL,TBLPTRH; 9 instr */

void ui_get_menu_item_2296(void)

{
  byte unaff_BSR;
  short sVar1;
  
  sVar1 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x27) * 2;
  ui_get_c18_tmp0_29d6((char)((ushort)sVar1 >> 8) + c18_tmp3 + CARRY1((byte)sVar1,c18_tmp2));
  return;
}

