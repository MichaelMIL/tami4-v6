// address 0x00d530  size 92 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Find parameter record in ROM table by id */

void param_find_record(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar3;
  undefined1 *puVar2;
  undefined1 uVar4;
  byte *pbVar5;
  undefined3 in_TBLPTR;
  undefined1 *puVar6;
  bool bVar7;
  
  mod_c18_prologue_d6b4();
  bVar7 = 4 < (byte)in_FSR1;
  bVar3 = (byte)((ushort)in_FSR1 >> 8);
  pbVar5 = (byte *)CONCAT11((bVar3 - 1) + bVar7,(byte)in_FSR1 - 5);
  bVar1 = pbVar5[1] | *pbVar5;
  uVar4 = 0;
  if ((bVar1 != 0) &&
     (uVar4 = mod_frame_access_d6f0(bVar1), !CARRY1(bVar3,bVar7) && bVar3 + bVar7 == '\0')) {
    mod_to_mod_get_TBLPTRL_d78c();
    puVar6 = (undefined1 *)
             CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                      CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfe < (byte)in_TBLPTR),
                               (byte)in_TBLPTR + 1));
    c18_tmp0 = *puVar6;
    c18_tmp1 = puVar6[1];
    c18_tmp2 = 0;
    *(undefined1 *)in_FSR1 = c18_tmp0;
    *(undefined1 *)((short)in_FSR1 + 1) = c18_tmp1;
    *(undefined1 *)((short)in_FSR1 + 2) = c18_tmp2;
    *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR2 + -4);
    puVar2 = (undefined1 *)((short)in_FSR1 + 5);
    *(undefined1 *)((short)in_FSR1 + 4) = *(undefined1 *)((short)in_FSR2 + -2);
    c18_tmp3 = strcpy_rom2ram();
    uVar4 = c18_tmp3;
    if ((byte)puVar2 < 5) {
      *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
      uVar4 = c18_tmp3;
    }
  }
  mod_c18_epilogue_d6c6(uVar4);
  return;
}

