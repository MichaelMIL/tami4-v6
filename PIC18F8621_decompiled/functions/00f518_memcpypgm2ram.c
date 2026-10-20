// address 0x00f518  size 70 bytes
// callers: 0079ce,

/* C18 runtime: copy ROM to RAM */

undefined1 memcpypgm2ram(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_00000002;
  undefined1 in_FramePointer1_00000004;
  undefined1 in_FramePointer1_0000fffc;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar5 = (undefined1 *)
           CONCAT12(in_FramePointer1_00000000,
                    CONCAT11(in_FramePointer1_0000fffe,in_FramePointer1_0000fffc));
  puVar2 = &FramePointer10x0005;
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_00000004,in_FramePointer1_00000002);
  do {
    puVar1 = puVar2 + 1;
    if (puVar2[-6] == '\0') {
      puVar1 = puVar2 + 2;
      if (puVar2[-4] == '\0') {
        return 0;
      }
    }
    puVar2 = puVar1 + 2;
    puVar1[-6] = puVar1[-5] + -1;
    if (puVar1[-5] == '\0') {
      puVar2 = puVar1 + 4;
      puVar1[-3] = puVar1[-2] + -1;
    }
    uVar4 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar3 = uVar4;
    puVar3 = puVar3 + 1;
  } while( true );
}

