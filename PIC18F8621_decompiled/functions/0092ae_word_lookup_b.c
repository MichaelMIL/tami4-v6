// address 0x0092ae  size 44 bytes
// callers: 0096c0,

/* Word table lookup (group B dictionary: 0xF22E EN, 0xF0A8 RU, 0xEF20 HE) */

void word_lookup_b(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = txt_frame_access_99c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      txt_get_TBLPTRH_998e();
      uVar2 = 0xef;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092d8;
      txt_get_TBLPTRH_998e();
      uVar2 = 0xf2;
    }
  }
  else {
    txt_get_TBLPTRH_998e();
    uVar2 = 0xf0;
  }
  txt_get_TBLPTRH_99ca(uVar2);
LAB_CODE_0092d8:
  txt_c18_epilogue_9972();
  return;
}

