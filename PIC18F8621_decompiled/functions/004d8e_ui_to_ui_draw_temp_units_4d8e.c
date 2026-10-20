// address 0x004d8e  size 28 bytes
// callers: 004550,

/* Auto: reads c18_tmp0,c18_tmp1; calls ui_draw_temp_units; 9 instr */

char ui_to_ui_draw_temp_units_4d8e(void)

{
  char cVar1;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  cVar1 = '\x02';
  c18_tmp0 = in_PRODL;
  c18_tmp1 = in_PRODH;
  c18_tmp2 = ui_draw_temp_units();
  return cVar1 + -5;
}

