// address 0x00b982  size 60 bytes
// callers: 00ba64,

/* Graphics: clip x coordinate */

void gfx_clip_x(void)

{
  byte bVar1;
  char cVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  byte unaff_C;
  
  mod_c18_prologue_ba28();
  mod_frag_bb2a();
  if ((unaff_C & 1) == 0) {
    mod_frag_bb32();
    if ((unaff_C & 1) == 0) {
      mod_frag_baa0(0x7f);
      if ((unaff_C & 1) == 0) {
        mod_set_anim_index_bbba();
        while( true ) {
          puVar3 = (undefined1 *)((short)in_FSR2 + 1);
          bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x56);
          cVar2 = bVar1 - *(byte *)((short)in_FSR2 + -4);
          if (*(byte *)((short)in_FSR2 + -4) <= bVar1) break;
          mod_get_math_aarg_hi_bac8(cVar2);
          if (cVar2 == '\0') {
            *(undefined1 *)in_FSR1 = 0;
            in_FSR2 = (BADSPACEBASE *)puVar3;
          }
          else {
            in_FSR2 = (BADSPACEBASE *)(puVar3 + 1);
            if (puVar3[-5] == '\0') {
              uVar4 = 0;
            }
            else {
              uVar4 = 0xff;
            }
            *(undefined1 *)in_FSR1 = uVar4;
          }
          in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
          mod_set_anim_index_bbee();
        }
        uVar4 = 0;
        goto LAB_CODE_00b9bc;
      }
    }
  }
  uVar4 = 0x81;
LAB_CODE_00b9bc:
  mod_c18_epilogue_ba78(uVar4);
  return;
}

