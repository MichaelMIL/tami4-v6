// address 0x00c45c  size 276 bytes
// callers: 0078ce,004daa,

/* C library: long to ASCII (with sign) */

char ltoa(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  short sVar8;
  char in_FramePointer1_00000003;
  char in_FramePointer1_0000000b;
  char in_FramePointer1_0000000d;
  char in_FramePointer1_00000010;
  undefined1 in_FramePointer1_0000fffb;
  undefined1 in_FramePointer1_0000fffd;
  
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_0000fffd,in_FramePointer1_0000fffb);
  puVar6 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x0010;
    puVar4 = puVar3 + 1;
    if (((in_FramePointer1_0000000b == '\0') &&
        (puVar6 = &FramePointer10x0012, puVar4 = puVar3 + 1, in_FramePointer1_0000000d == -1)) &&
       (puVar6 = &FramePointer10x0014, puVar4 = puVar3 + 1, in_FramePointer1_00000010 == -1)) {
      puVar6 = &FramePointer10x0016;
      puVar4 = puVar3 + 1;
    }
  }
  *puVar6 = *puVar6;
  puVar6[1] = puVar6[1];
  puVar6[2] = puVar6[2];
  puVar6[3] = puVar6[3];
  puVar6[4] = puVar6[4];
  puVar6[5] = (byte)(puVar6 + 5) - 5;
  puVar6[6] = (char)((ushort)(puVar6 + 5) >> 8) + -1 + (4 < (byte)(puVar6 + 5));
  puVar6[6] = puVar6[6];
  puVar6[7] = puVar6[-4];
  puVar6[9] = puVar6[-2];
  puVar6[0xb] = *puVar6;
  puVar7 = puVar6 + 0xf;
  puVar6[0xd] = puVar6[2];
  int32_to_bcd();
  bVar5 = (byte)puVar7;
  uVar2 = (ushort)puVar7 >> 8;
  mod_bcd_digit_helper_c570();
  if ((char)uVar2 + -1 + (10 < bVar5) == '\0') {
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
    mod_frag_c576();
    mod_bcd_digit_helper_c570();
  }
  else {
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
    mod_bcd_digit_helper_c58c();
    mod_bcd_digit_helper_c582();
  }
  mod_bcd_digit_helper_c58c();
  *puVar4 = 0;
  bVar5 = (byte)puVar7 - 0xb;
  cVar1 = (char)((ushort)puVar7 >> 8) + -1 + (10 < (byte)puVar7);
  sVar8 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  return cVar1 + -1 + (5 < bVar5);
}

