// address 0x00b898  size 112 bytes
// callers: 004e66,003b12,

/* Graphics: animated icon B (frames of 0x94 bytes) */

void gfx_anim_icon_b(void)

{
  BADSPACEBASE *in_FSR2;
  byte *pbVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  byte unaff_C;
  bool bVar7;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0x25;
  cVar4 = mod_to_mod_to_lcd_draw_glyph_bbe4(0x2c);
  if ((unaff_C & 1) != 0) {
    anim_pos = 0;
    while( true ) {
      cVar4 = anim_pos - 4;
      if (3 < anim_pos) break;
      mod_set_anim_index_bb58(0x2c);
      while( true ) {
        if (0x24 < anim_index) break;
        pbVar1 = (byte *)((short)in_FSR2 + 1);
        mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
        bVar7 = 7 < c18_tmp2;
        c18_tmp2 = c18_tmp2 - 8;
        c18_tmp3 = c18_tmp3 + -0x78 + bVar7;
        uVar5 = mod_get_anim_index_ba3a(anim_pos);
        *pbVar1 = uVar5;
        bVar6 = 3 - ((cfg_systemconfig5 & 0x60) >> 5);
        if (bVar6 == 0) {
          if (anim_pos == 0) {
            *pbVar1 = 0;
          }
          bVar6 = anim_pos - 1;
          if (bVar6 == 0) {
            bVar6 = *pbVar1 & 0xfc;
            *pbVar1 = bVar6;
          }
        }
        puVar3 = puVar2 + 1;
        *puVar2 = *pbVar1;
        mod_set_anim_index_bbee(bVar6);
        in_FSR2 = (BADSPACEBASE *)pbVar1;
        puVar2 = puVar3;
      }
      anim_pos = anim_pos + 1;
    }
  }
  *puVar2 = *puVar2;
  mod_c18_epilogue_ba78(cVar4);
  return;
}

