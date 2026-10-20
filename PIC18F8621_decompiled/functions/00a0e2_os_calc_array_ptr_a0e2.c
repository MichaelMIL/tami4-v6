// address 0x00a0e2  size 52 bytes
// callers: 00a0b6,

/* Auto: Compute array element address in FSR0; 26 instr */

void os_calc_array_ptr_a0e2(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  
  os_stack_adjust_a28c();
  puVar5 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  pbVar7 = (byte *)CONCAT11((char)((ushort)in_FSR2 >> 8) + -1 + (3 < (byte)in_FSR2),
                            (byte)in_FSR2 - 4);
  bVar2 = pbVar7[1] | *pbVar7;
  puVar3 = (undefined1 *)in_FSR2;
  puVar6 = (undefined1 *)((short)in_FSR1 + 1);
  if (bVar2 != 0) {
    os_frame_load_ptr_arg_a160(bVar2);
    os_frame_access_a1f2();
    puVar3 = (undefined1 *)((short)in_FSR2 + 1);
    puVar4 = (undefined1 *)((short)in_FSR2 + 1);
    puVar6 = puVar5;
    if (*(char *)((short)in_FSR2 + 2) != '\a') {
      *(undefined1 *)((short)in_FSR2 + 1) = 1;
      goto LAB_CODE_00a10e;
    }
  }
  *puVar3 = 0;
  puVar4 = puVar3;
  puVar5 = puVar6;
LAB_CODE_00a10e:
  uVar1 = *puVar4;
  *puVar5 = *puVar5;
  puVar5[-1] = puVar5[-1];
  os_c18_epilogue_a180(uVar1);
  return;
}

