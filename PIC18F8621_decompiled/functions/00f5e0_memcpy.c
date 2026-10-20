// address 0x00f5e0  size 92 bytes
// callers: 007986,

/* C18 runtime: copy RAM to RAM */

undefined1 memcpy(void)

{
  char cVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 in_FramePointer1_00000003;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar5 = &FramePointer10x0006;
  puVar2 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  pcVar6 = (undefined1 *)CONCAT11(in_FramePointer1_00000003,(char)((ushort)in_FSR2 >> 8));
  while ((puVar3 = puVar2, puVar4 = puVar5 + 1, puVar5[-7] != '\0' ||
         (puVar4 = puVar5 + 2, puVar5[-5] != '\0'))) {
    puVar5 = puVar4 + 2;
    puVar4[-7] = puVar4[-6] + -1;
    if (puVar4[-6] == '\0') {
      puVar5 = puVar4 + 4;
      puVar4[-4] = puVar4[-3] + -1;
    }
    *pcVar6 = *puVar3;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    puVar2 = puVar3 + 1;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') {
      puVar3[1] = puVar3[1];
      puVar2 = puVar3;
      pcVar6 = pcVar7;
    }
  }
  puVar5[3] = puVar5[3];
  puVar5[3] = puVar5[3];
  return 0xff;
}

