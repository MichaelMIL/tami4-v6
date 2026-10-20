// address 0x00f592  size 50 bytes
// callers: 00ecee,0048b2,00d530,009316,

/* C18 runtime: copy NUL-terminated string */

undefined1 strcpy_rom2ram(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_00000002;
  undefined1 in_FramePointer1_00000004;
  undefined1 in_FramePointer1_0000fffc;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar4 = (undefined1 *)
           CONCAT12(in_FramePointer1_00000000,
                    CONCAT11(in_FramePointer1_0000fffe,in_FramePointer1_0000fffc));
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000004,in_FramePointer1_00000002);
  do {
    uVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    *pcVar2 = uVar3;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}

