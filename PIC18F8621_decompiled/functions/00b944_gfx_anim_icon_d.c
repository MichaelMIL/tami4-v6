// address 0x00b944  size 62 bytes
// callers: 004550,003b12,

/* Graphics: animated icon D (frames of 0x68 bytes) */

void gfx_anim_icon_d(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  byte unaff_C;
  bool bVar3;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = 0x1a;
  cVar2 = mod_to_mod_to_lcd_draw_glyph_bbe4(0x32);
  if ((unaff_C & 1) != 0) {
    anim_pos = 0;
    while( true ) {
      cVar2 = anim_pos - 4;
      if (3 < anim_pos) break;
      mod_set_anim_index_bb58(0x32);
      while( true ) {
        if (0x19 < anim_index) break;
        puVar1 = (undefined1 *)((short)in_FSR2 + 1);
        mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
        bVar3 = 0x93 < c18_tmp2;
        c18_tmp2 = c18_tmp2 + 0x6c;
        c18_tmp3 = c18_tmp3 + -0x73 + bVar3;
        mod_set_anim_index_bbda(anim_pos);
        in_FSR2 = (BADSPACEBASE *)puVar1;
      }
      anim_pos = anim_pos + 1;
    }
  }
  mod_c18_epilogue_ba78(cVar2);
  return;
}

