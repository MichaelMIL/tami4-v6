// address 0x00e104  size 166 bytes
// callers: 00d740,

/* WARNING: Removing unreachable block (CODE,0x00e132) */
/* WARNING: Removing unreachable block (CODE,0x00e148) */
/* WARNING: Removing unreachable block (CODE,0x00e14a) */
/* WARNING: Removing unreachable block (CODE,0x00e180) */
/* WARNING: Removing unreachable block (CODE,0x00e182) */
/* WARNING: Removing unreachable block (CODE,0x00e192) */
/* WARNING: Removing unreachable block (CODE,0x00e194) */
/* WARNING: Removing unreachable block (CODE,0x00e196) */
/* Low-level EEPROM byte write (variant) */

undefined1 eeprom_write_byte_b(void)

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

