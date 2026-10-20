// address 0x00c328  size 186 bytes
// callers: 004eaa,0095f2,

/* Format 16-bit integer as decimal (printf helper) */

char fmt_int(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  short sVar9;
  char in_FramePointer1_00000003;
  char in_FramePointer1_00000006;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  puVar7 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    puVar4 = puVar3 + 1;
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x000a;
    if (in_FramePointer1_00000006 == -1) {
      puVar6 = &FramePointer10x000c;
    }
    puVar7 = puVar6 + 2;
    puVar6[-2] = ~puVar6[-1];
  }
  *puVar7 = *puVar7;
  puVar7[1] = puVar7[1];
  puVar7[2] = puVar7[2];
  puVar7[3] = (byte)(puVar7 + 3) - 3;
  puVar7[4] = (char)((ushort)(puVar7 + 3) >> 8) + -1 + (2 < (byte)(puVar7 + 3));
  puVar7[4] = puVar7[4];
  puVar7[5] = puVar7[-2];
  puVar8 = puVar7 + 9;
  puVar7[7] = *puVar7;
  int16_to_bcd();
  bVar5 = (byte)puVar8;
  uVar2 = (ushort)puVar8 >> 8;
  mod_frag_c3e8();
  if ((char)uVar2 + -1 + (6 < bVar5) == '\0') {
    mod_bcd_digit_helper_c3e2();
    mod_frag_c3e8();
    mod_bcd_digit_helper_c3e2();
  }
  else {
    mod_bcd_digit_helper_c3fe();
    mod_bcd_digit_helper_c3f4();
    mod_bcd_digit_helper_c3fe();
    mod_bcd_digit_helper_c3f4();
  }
  mod_bcd_digit_helper_c3fe();
  *puVar4 = 0;
  bVar5 = (byte)puVar8 - 7;
  cVar1 = (char)((ushort)puVar8 >> 8) + -1 + (6 < (byte)puVar8);
  sVar9 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar9 + 1) = *(undefined1 *)(sVar9 + 1);
  *(undefined1 *)(sVar9 + 1) = *(undefined1 *)(sVar9 + 1);
  return cVar1 + -1 + (3 < bVar5);
}

