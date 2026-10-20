// address 0x004b32  size 154 bytes
// callers: 00a312,004550,

/* Compute days to next filter/UV replacement */

void replacement_days_left(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  bool bVar5;
  
  ui_frag_4c90();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  uVar4 = ui_to_eeprom_read_raw_4dd4(0x40);
  *(undefined1 *)in_FSR2 = uVar4;
  c18_tmp4 = *(undefined1 *)in_FSR2;
  c18_tmp5 = 0;
  ui_get_TBLPTRH_4e1a(0xfc);
  if ((c18_tmp1 & 0x80) != 0) {
    c18_tmp2 = 0xff;
    c18_tmp3 = 0xff;
  }
  if (((bDATA00ed ^ c18_tmp3) & 0x80) == 0) {
    bVar1 = ~(bDATA00eb < (byte)~(c18_tmp0 <= stat_GFI) ||
             c18_tmp1 < bDATA00eb - ~(c18_tmp0 <= stat_GFI));
    bVar1 = ~(bDATA00ec < bVar1 || c18_tmp2 < bDATA00ec - bVar1);
    bVar5 = bDATA00ed < bVar1 || c18_tmp3 < bDATA00ed - bVar1;
  }
  else {
    bVar5 = (char)c18_tmp3 < '\0';
  }
  if (bVar5) {
    puVar3 = puVar2 + 1;
    *puVar2 = 7;
    uVar4 = 0x18;
LAB_CODE_004bbe:
    ui_to_ser_to_text_draw_word_4d7a(uVar4);
    uVar4 = 1;
    puVar2 = puVar3;
  }
  else {
    if ((cfg_systemconfig4 & 0x20) != 0) {
      c18_tmp4 = *(undefined1 *)in_FSR2;
      c18_tmp5 = 0;
      ui_get_TBLPTRH_4e1a(0xfc);
      if ((c18_tmp1 & 0x80) != 0) {
        c18_tmp2 = 0xff;
        c18_tmp3 = 0xff;
      }
      if (((bDATA00e9 ^ c18_tmp3) & 0x80) == 0) {
        bVar1 = ~(bDATA00e7 < (byte)~(c18_tmp0 <= stat_GUV) ||
                 c18_tmp1 < bDATA00e7 - ~(c18_tmp0 <= stat_GUV));
        bVar1 = ~(bDATA00e8 < bVar1 || c18_tmp2 < bDATA00e8 - bVar1);
        bVar5 = bDATA00e9 < bVar1 || c18_tmp3 < bDATA00e9 - bVar1;
      }
      else {
        bVar5 = (char)c18_tmp3 < '\0';
      }
      if (bVar5) {
        puVar3 = puVar2 + 1;
        *puVar2 = 7;
        uVar4 = 0x19;
        goto LAB_CODE_004bbe;
      }
    }
    uVar4 = 0;
  }
  *puVar2 = *puVar2;
  ui_c18_epilogue_4d6e(uVar4);
  return;
}

