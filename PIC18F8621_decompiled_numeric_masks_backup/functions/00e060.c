// address 0x00e060

/* WARNING: Removing unreachable block (CODE,0x00e08e) */
/* WARNING: Removing unreachable block (CODE,0x00e0a4) */
/* WARNING: Removing unreachable block (CODE,0x00e0a6) */
/* WARNING: Removing unreachable block (CODE,0x00e0da) */
/* WARNING: Removing unreachable block (CODE,0x00e0dc) */
/* WARNING: Removing unreachable block (CODE,0x00e0ec) */
/* WARNING: Removing unreachable block (CODE,0x00e0ee) */
/* WARNING: Removing unreachable block (CODE,0x00e0f0) */

undefined1 FUN_CODE_00e060(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  DAT_DATA_0014 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  DAT_DATA_0015 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}

