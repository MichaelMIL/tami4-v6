// address 0x00c596  size 94 bytes
// callers: 00c45c,

/* Convert 32-bit binary to BCD */

undefined1 int32_to_bcd(void)

{
  char cVar1;
  char cVar2;
  BADSPACEBASE *in_FSR1;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  bool bVar11;
  undefined1 in_FramePointer1_0000fffb;
  undefined1 in_FramePointer1_0000fffd;
  
  puVar5 = (undefined1 *)CONCAT11(in_FramePointer1_0000fffd,in_FramePointer1_0000fffb);
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = 0;
  pbVar10 = puVar5 + 4;
  puVar5[3] = 0;
  puVar5[4] = 0;
  bVar11 = false;
  pcVar3 = &FramePointer10x0003;
  while( true ) {
    pcVar3[-4] = pcVar3[-3] << 1 | bVar11;
    pcVar3[-1] = *pcVar3 << 1 | pcVar3[-3] < '\0';
    pcVar3[2] = pcVar3[3] << 1 | *pcVar3 < '\0';
    pcVar3[5] = pcVar3[6] << 1 | pcVar3[3] < '\0';
    cVar1 = *pbVar10;
    *pbVar10 = cVar1 << 1 | pcVar3[6] < '\0';
    cVar2 = pbVar10[-1];
    pbVar10[-1] = cVar2 << 1 | cVar1 < '\0';
    cVar1 = pbVar10[-2];
    pbVar10[-2] = cVar1 << 1 | cVar2 < '\0';
    pbVar6 = pbVar10 + -4;
    cVar2 = pbVar10[-3];
    pbVar10[-3] = cVar2 << 1 | cVar1 < '\0';
    pbVar10[-4] = pbVar10[-4] << 1 | cVar2 < '\0';
    pcVar4 = pcVar3 + 10;
    bVar11 = pcVar3[9] != '\0';
    cVar1 = pcVar3[9] + -1;
    pcVar3[8] = cVar1;
    if (cVar1 == '\0') break;
    mod_frag_c5f4();
    puVar7 = pbVar6 + 1;
    *pbVar6 = *pbVar6;
    mod_frag_c5f4();
    puVar8 = puVar7 + 1;
    *puVar7 = *puVar7;
    mod_frag_c5f4();
    puVar9 = puVar8 + 1;
    *puVar8 = *puVar8;
    mod_frag_c5f4();
    pbVar10 = puVar9 + 1;
    *puVar9 = *puVar9;
    mod_frag_c5f4();
    pcVar3 = pcVar4;
  }
  pcVar3[10] = 0xff;
  return 0xff;
}

