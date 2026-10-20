// address 0x00f278  size 188 bytes
// callers: 004264,00a312,

/* Draw large 51-byte glyphs from ROM 0x9010 on the LCD */

void lcd_draw_big_glyph(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte bVar7;
  undefined1 *in_TBLPTR;
  
  mod_c18_prologue_f394();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  puVar5 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR2 + 5) = 4;
  *(undefined1 *)((short)in_FSR2 + 5) = 0x33;
  puVar1 = (undefined1 *)((short)in_FSR2 + 3);
  math_aarg_lo = 0x82 - *(char *)((short)in_FSR2 + 6);
  math_aarg_hi = '\x02';
  math_barg_lo = 2;
  math_barg_hi = 0;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  __divs16();
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  puVar1[3] = math_aarg_lo;
  puVar1[1] = 0;
  while( true ) {
    if ((byte)puVar1[6] <= (byte)puVar1[2]) break;
    puVar2 = puVar1 + 3;
    *puVar5 = puVar1[5];
    puVar6 = puVar5 + 2;
    puVar5[1] = puVar1[3] + '\x02';
    mod_to_mod_to_lcd_write_cmd_cfc6();
    *puVar6 = *puVar6;
    puVar5 = puVar6 + -2;
    puVar6[-1] = puVar6[-1];
    puVar3 = puVar2 + 1;
    puVar2[2] = 0;
    while( true ) {
      puVar1 = puVar3 + 1;
      if ((byte)puVar3[4] <= (byte)puVar3[3]) break;
      bVar7 = (byte)((ushort)(byte)puVar3[2] * 0x33);
      c18_tmp0 = bVar7 + 0x10;
      c18_tmp1 = (char)((ushort)(byte)puVar3[2] * 0x33 >> 8) + -0x70 + (0xef < bVar7);
      puVar4 = puVar3 + 3;
      in_TBLPTR = (undefined1 *)
                  CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                           CONCAT11(c18_tmp1 + CARRY1(c18_tmp0,puVar3[4]),c18_tmp0 + puVar3[4]));
      mod_callw_lcd_write_data_f3c4(*in_TBLPTR);
      puVar3 = puVar4 + 2;
      puVar4[2] = puVar4[3] + '\x01';
    }
    puVar3[2] = puVar3[2] + '\x01';
  }
  if ((byte)puVar5 < 5) {
    *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
  }
  mod_c18_epilogue_f3a8((byte)puVar5 - 5);
  return;
}

