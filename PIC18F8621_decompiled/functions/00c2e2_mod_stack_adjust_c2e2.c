// address 0x00c2e2  size 52 bytes
// callers: 00c226,

/* Auto: Software stack push/pop helper; 22 instr */

undefined1 mod_stack_adjust_c2e2(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar4 = (undefined1 *)CONCAT11(in_FramePointer1_00000000,in_FramePointer1_0000fffe);
  pbVar6 = puVar4 + 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  bVar7 = false;
  pcVar2 = &FramePointer10x0003;
  while( true ) {
    pcVar2[-1] = *pcVar2 << 1 | bVar7;
    pbVar5 = pbVar6 + -1;
    cVar1 = *pbVar6;
    *pbVar6 = cVar1 << 1 | *pcVar2 < '\0';
    pbVar6[-1] = pbVar6[-1] << 1 | cVar1 < '\0';
    pcVar3 = pcVar2 + 4;
    bVar7 = pcVar2[3] != '\0';
    cVar1 = pcVar2[3] + -1;
    pcVar2[2] = cVar1;
    if (cVar1 == '\0') break;
    mod_frag_c316();
    pbVar6 = pbVar5 + 1;
    *pbVar5 = *pbVar5;
    mod_frag_c316();
    pcVar2 = pcVar3;
  }
  pcVar2[4] = 0xff;
  return 0xff;
}

