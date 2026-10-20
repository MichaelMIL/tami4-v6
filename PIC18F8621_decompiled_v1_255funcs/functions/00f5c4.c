// address 0x00f5c4

undefined1 FUN_CODE_00f5c4(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 in_FramePointer1_00000001;
  undefined1 in_FramePointer1_0000ffff;
  
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000001,in_FramePointer1_0000ffff);
  do {
    cVar1 = *pcVar2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}

