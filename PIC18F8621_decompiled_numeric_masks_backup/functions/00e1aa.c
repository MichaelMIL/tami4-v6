// address 0x00e1aa

/* WARNING: Removing unreachable block (CODE,0x00e1d8) */
/* WARNING: Removing unreachable block (CODE,0x00e210) */
/* WARNING: Removing unreachable block (CODE,0x00e212) */
/* WARNING: Removing unreachable block (CODE,0x00e222) */
/* WARNING: Removing unreachable block (CODE,0x00e224) */
/* WARNING: Removing unreachable block (CODE,0x00e226) */

undefined1 FUN_CODE_00e1aa(void)

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

