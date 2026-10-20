// address 0x00a892  size 40 bytes
// callers: 00a312,00a414,

/* Auto: reads c18_tmp2,c18_tmp3; 17 instr */

void mod_get_c18_tmp2_a892(byte param_1)

{
  byte bVar1;
  
  bVar1 = (byte)((ushort)param_1 * 0x1c);
  c18_tmp2 = bVar1 + 0x3c;
  c18_tmp3 = (char)((ushort)param_1 * 0x1c >> 8) + -10 + (0xc3 < bVar1);
  bVar1 = (byte)((ushort)local0 * 0xe);
  c18_tmp0 = bVar1 + c18_tmp2;
  c18_tmp1 = (char)((ushort)local0 * 0xe >> 8) + c18_tmp3 + CARRY1(bVar1,c18_tmp2);
  mod_get_TBLPTRL_a9e2();
  mod_callw_lcd_write_data_a9f6();
  return;
}

