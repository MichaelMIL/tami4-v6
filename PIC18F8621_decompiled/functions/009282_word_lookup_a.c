// address 0x009282  size 44 bytes
// callers: 00a312,002b90,009a6c,0048b2,

/* Word table lookup (group A: 0xF114 EN, 0xEF8E RU, 0xEE06 HE) */

void word_lookup_a(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = txt_frame_access_99c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      txt_get_TBLPTRH_998e();
      uVar2 = 0xee;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092ac;
      txt_get_TBLPTRH_998e();
      uVar2 = 0xf1;
    }
  }
  else {
    txt_get_TBLPTRH_998e();
    uVar2 = 0xef;
  }
  txt_get_TBLPTRH_99ca(uVar2);
LAB_CODE_0092ac:
  txt_c18_epilogue_9972();
  return;
}

