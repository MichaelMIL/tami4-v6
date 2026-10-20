// address 0x00ecee  size 74 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Read a counter descriptor from ROM table */

void stats_read_counter_rom(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined3 in_TBLPTR;
  undefined1 uVar5;
  undefined1 *puVar4;
  
  uVar5 = (undefined1)((uint3)in_TBLPTR >> 0x10);
  bVar2 = mod_c18_prologue_edc4();
  bVar3 = (byte)((ushort)bVar2 * 6);
  puVar4 = (undefined1 *)
           CONCAT12(uVar5,CONCAT11((char)((ushort)bVar2 * 6 >> 8) + -0x21 + (0x98 < bVar3),
                                   bVar3 + 0x67));
  c18_tmp0 = *puVar4;
  c18_tmp1 = puVar4[1];
  c18_tmp2 = 0;
  mod_get_c18_tmp0_edfc();
  *(undefined1 *)in_FSR1 = c18_tmp2;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -4);
  puVar1 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR2 + -2);
  c18_tmp3 = strcpy_rom2ram();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  mod_c18_epilogue_edda(c18_tmp3);
  return;
}

