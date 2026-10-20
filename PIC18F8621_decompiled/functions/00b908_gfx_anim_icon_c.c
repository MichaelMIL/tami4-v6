// address 0x00b908  size 60 bytes
// callers: 004550,003b12,

/* Graphics: animated icon C (frames of 0x50 bytes) */

void gfx_anim_icon_c(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  bool bVar2;
  
  mod_c18_prologue_ba28();
  *(undefined1 *)in_FSR1 = 0x14;
  mod_to_lcd_draw_glyph_ba84(0x35);
  anim_pos = 0;
  while( true ) {
    if (3 < anim_pos) break;
    mod_set_anim_index_bb58(0x35);
    while( true ) {
      if (0x13 < anim_index) break;
      puVar1 = (undefined1 *)((short)in_FSR2 + 1);
      mod_get_c18_tmp2_bb10(*(undefined1 *)((short)in_FSR2 + -2));
      bVar2 = 0x23 < c18_tmp2;
      c18_tmp2 = c18_tmp2 - 0x24;
      c18_tmp3 = c18_tmp3 + -0x75 + bVar2;
      mod_set_anim_index_bbda(anim_pos);
      in_FSR2 = (BADSPACEBASE *)puVar1;
    }
    anim_pos = anim_pos + 1;
  }
  mod_c18_epilogue_ba78(anim_pos - 4);
  return;
}

