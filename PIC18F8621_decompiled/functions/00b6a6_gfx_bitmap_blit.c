// address 0x00b6a6  size 204 bytes
// callers: 0020e8,004fa0,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Graphics: draw bitmap at position */

void gfx_bitmap_blit(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  BADSPACEBASE *in_FSR1;
  byte bVar7;
  undefined1 uVar8;
  char cVar9;
  BADSPACEBASE *in_FSR0;
  byte unaff_C;
  
  mod_c18_prologue_ba28();
  mod_frag_bc1a();
  mod_frag_baa0();
  if ((unaff_C & 1) == 0) {
    mod_frame_load_ptr_arg_ba1a();
    *(undefined1 *)((short)in_FSR2 + -4) = *(undefined1 *)in_FSR0;
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  }
  else {
    mod_get_c18_tmp0_bb80();
    mod_frag_baa0();
    puVar2 = (undefined1 *)in_FSR2;
    if ((unaff_C & 1) != 0) {
      cVar9 = mod_get_c18_tmp0_bb80();
      *(char *)in_FSR1 = cVar9 + -1;
      puVar2 = (undefined1 *)((short)in_FSR2 + 1);
      *(undefined1 *)((short)in_FSR2 + -4) = *(undefined1 *)in_FSR1;
    }
  }
  bVar7 = mod_frag_bb9a();
  puVar3 = puVar2 + 1;
  bVar1 = puVar2[-4];
  cVar9 = bVar7 - bVar1;
  if (cVar9 == '\0') {
    uVar8 = 1;
  }
  else {
    mod_frag_bb9a(cVar9);
    mod_frag_baa0();
    if (bVar7 < bVar1) {
      puVar4 = puVar3 + 1;
      anim_frame = mod_frag_bafc(puVar3[-4]);
      mod_frag_bb9a();
      anim_end = mod_frag_bafc();
      anim_flag = 1;
      puVar2 = puVar4 + 1;
      puVar5 = puVar4 + 1;
      if ((puVar4[-4] & 7) == 0) {
        anim_pos = anim_frame;
        while( true ) {
          cVar9 = (anim_end - anim_pos) + '\x02';
          if (0xfd < anim_end && anim_end + 2 <= anim_pos) break;
          mod_get_anim_flag_bb4e(cVar9);
        }
      }
      else {
        mod_frame_access_bb66();
        *(byte *)in_FSR1 = anim_frame;
        mod_to_gfx_clip_y_bb3a();
        anim_pos = anim_frame + 1;
        while( true ) {
          cVar9 = (anim_end - anim_pos) + '\x02';
          puVar2 = puVar5;
          if (0xfd < anim_end && anim_end + 2 <= anim_pos) break;
          mod_get_anim_flag_bb4e();
        }
      }
    }
    else {
      mod_frag_bb9a();
      anim_frame = mod_frag_bafc();
      puVar6 = puVar3 + 1;
      anim_end = mod_frag_bafc(puVar3[-4]);
      anim_flag = 0;
      puVar2 = puVar6 + 1;
      if ((puVar6[-4] & 7) == 0) {
        anim_pos = anim_frame;
        puVar2 = puVar6 + 1;
        while( true ) {
          cVar9 = anim_pos - anim_end;
          if (anim_end <= anim_pos) break;
          mod_get_anim_flag_bb4e(cVar9);
        }
      }
      else {
        anim_pos = anim_frame;
        while( true ) {
          if (anim_end <= anim_pos) break;
          mod_get_anim_flag_bb4e();
        }
        mod_frame_access_bb66(anim_pos - anim_end);
        *(byte *)in_FSR1 = anim_end;
        cVar9 = mod_to_gfx_clip_y_bb3a();
      }
    }
    mod_ptr_add_bbce(cVar9);
    *(undefined1 *)in_FSR0 = puVar2[-4];
    uVar8 = 0;
  }
  mod_c18_epilogue_ba78(uVar8);
  return;
}

