// address 0x00b64a  size 92 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Graphics: validate bitmap coordinates */

void gfx_bitmap_check(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar4;
  char *pcVar5;
  byte *pbVar6;
  
  mod_c18_prologue_ba28();
  bVar1 = mod_frag_bc1a();
  if (bVar1 < 0x40) {
    bVar1 = mod_get_c18_tmp0_bb80('?' - bVar1);
    if (bVar1 < 0x40) {
      mod_frame_load_ptr_arg_ba1a('?' - bVar1);
      puVar4 = (undefined1 *)((short)in_FSR0 + 1);
      *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
      if (*(byte *)((short)in_FSR0 + 1) < 0x80) {
        mod_frame_load_ptr_arg_ba1a('\x7f' - *(byte *)((short)in_FSR0 + 1));
        pcVar5 = (char *)CONCAT11((char)((ushort)puVar4 >> 8) + (0xfc < (byte)puVar4),
                                  (byte)puVar4 + 3);
        c18_tmp1 = *pcVar5;
        mod_frame_load_ptr_arg_ba1a();
        pbVar6 = (byte *)(pcVar5 + 1);
        *pcVar5 = *pcVar5;
        if ((byte)(c18_tmp1 + pcVar5[1]) < 0x80) {
          mod_ptr_add_bbce('\x7f' - (c18_tmp1 + pcVar5[1]));
          c18_tmp2 = *pbVar6;
          bVar1 = mod_frag_bc1a();
          if (bVar1 <= c18_tmp2) {
            mod_ptr_add_bbce(c18_tmp2 - bVar1);
            c18_tmp3 = *pbVar6;
            mod_frame_load_ptr_arg_ba1a();
            mod_ptr_add_baf2();
            c18_tmp4 = *pbVar6;
            cVar2 = mod_frag_bc1a();
            if (c18_tmp3 < (byte)(c18_tmp4 + cVar2)) {
              uVar3 = 0;
              goto LAB_CODE_00b6a4;
            }
          }
        }
      }
    }
  }
  uVar3 = 0x81;
LAB_CODE_00b6a4:
  mod_c18_epilogue_ba78(uVar3);
  return;
}

