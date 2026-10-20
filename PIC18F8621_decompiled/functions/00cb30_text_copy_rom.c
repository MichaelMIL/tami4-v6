// address 0x00cb30  size 86 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Copy ROM text to buffer */

void text_copy_rom(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  BADSPACEBASE *in_FSR2;
  char *pcVar4;
  char *pcVar5;
  BADSPACEBASE *in_FSR1;
  byte bVar6;
  undefined1 *in_TBLPTR;
  bool bVar7;
  
  mod_c18_prologue_cdd2();
  while( true ) {
    c18_tmp0 = *(char *)((short)in_FSR2 + -7);
    bVar7 = *(char *)((short)in_FSR2 + -5) != '\0';
    *(char *)((short)in_FSR2 + -6) = *(char *)((short)in_FSR2 + -5) + -1;
    pcVar4 = (char *)((short)in_FSR2 + 4);
    c18_tmp1 = *(byte *)((short)in_FSR2 + -3);
    if (!bVar7) {
      pcVar4 = (char *)((short)in_FSR2 + 6);
      bVar7 = *(char *)((short)in_FSR2 + -1) != '\0';
      *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + -1;
    }
    bVar6 = c18_tmp1 << 1 | bVar7;
    if ((char)c18_tmp1 < '\0') break;
    bVar1 = ~(c18_tmp0 == '\0');
    bVar6 = -~(c18_tmp0 == '\0') - c18_tmp1;
    if (bVar1 != 0 || c18_tmp1 < -bVar1) break;
    pcVar4[-4] = pcVar4[-3] + '\x01';
    pcVar5 = pcVar4 + 4;
    in_TBLPTR = (undefined1 *)
                CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(pcVar4[-1],pcVar4[-5]));
    if (pcVar4[-3] == -1) {
      pcVar5 = pcVar4 + 6;
      *pcVar4 = pcVar4[1] + '\x01';
    }
    *(undefined1 *)in_FSR1 = *in_TBLPTR;
    uVar2 = pcVar5[-3];
    pcVar5[-2] = pcVar5[-1] + '\x01';
    in_FSR2 = (BADSPACEBASE *)(pcVar5 + 4);
    uVar3 = pcVar5[1];
    if (pcVar5[-1] == -1) {
      in_FSR2 = (BADSPACEBASE *)(pcVar5 + 6);
      pcVar5[2] = pcVar5[3] + '\x01';
    }
    *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)CONCAT11(uVar3,uVar2) = *(undefined1 *)in_FSR1;
  }
  mod_c18_epilogue_cd24(bVar6);
  return;
}

