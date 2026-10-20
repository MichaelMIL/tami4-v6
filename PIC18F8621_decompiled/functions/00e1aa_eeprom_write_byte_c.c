// address 0x00e1aa  size 144 bytes
// callers: 00ec76,

/* WARNING: Removing unreachable block (CODE,0x00e1d8) */
/* WARNING: Removing unreachable block (CODE,0x00e210) */
/* WARNING: Removing unreachable block (CODE,0x00e212) */
/* WARNING: Removing unreachable block (CODE,0x00e222) */
/* WARNING: Removing unreachable block (CODE,0x00e224) */
/* WARNING: Removing unreachable block (CODE,0x00e226) */
/* Low-level EEPROM byte write (variant) */

undefined1 eeprom_write_byte_c(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  c18_tmp0 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  c18_tmp1 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}

