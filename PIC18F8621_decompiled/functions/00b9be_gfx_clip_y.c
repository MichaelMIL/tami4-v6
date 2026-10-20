// address 0x00b9be  size 92 bytes
// callers: 00bb3a,

/* Graphics: clip y coordinate */

void gfx_clip_y(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  byte bVar5;
  byte unaff_C;
  
  mod_c18_prologue_ba28();
  mod_frag_bb2a();
  if (((((unaff_C & 1) == 0) && (mod_frag_bb32(), (unaff_C & 1) == 0)) &&
      (mod_frag_baa0(0x7f), (unaff_C & 1) == 0)) && (*(byte *)((short)in_FSR2 + -5) < 9)) {
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    if (*(char *)((short)in_FSR2 + -4) == '\0') {
      uVar4 = 1;
    }
    else {
      mod_set_anim_index_bbba(*(char *)((short)in_FSR2 + -4));
      while( true ) {
        puVar3 = puVar2 + 1;
        bVar5 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x56);
        cVar1 = bVar5 - puVar2[-4];
        if ((byte)puVar2[-4] <= bVar5) break;
        mod_get_math_aarg_hi_bac8(cVar1);
        if (cVar1 == '\0') {
          *(undefined1 *)in_FSR1 = 0;
          puVar2 = puVar3;
        }
        else {
          c18_tmp0 = 0xff;
          puVar2 = puVar3 + 1;
          bVar5 = puVar3[-5];
          *(undefined1 *)in_FSR1 = 0xff;
          for (bVar5 = bVar5 & 7; bVar5 != 0; bVar5 = bVar5 - 1) {
            *(byte *)in_FSR1 = *(byte *)in_FSR1 >> 1;
            *(byte *)in_FSR1 = *(byte *)in_FSR1 & 0x7f;
          }
          *(byte *)in_FSR1 = ~*(byte *)in_FSR1;
        }
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
        mod_set_anim_index_bbee();
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0x81;
  }
  mod_c18_epilogue_ba78(uVar4);
  return;
}

