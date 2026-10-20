// address 0x006d6a  size 86 bytes
// callers: 006e5c,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Print a parameter's name, value, maximum and minimum */

void serial_report_param(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar6;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined1 uVar7;
  byte bVar8;
  byte bVar9;
  bool bVar10;
  
  puVar2 = &FramePointer10x0002;
  bVar8 = (byte)((ushort)serial_cmd_hash * 7);
  bVar9 = (byte)((ushort)serial_cmd_hash * 7 >> 8);
  bVar10 = 0xa5 < bVar8;
  c18_tmp0 = bVar8 + 0x5a;
  c18_tmp1 = (bVar9 - 0x23) + bVar10;
  c18_tmp2 = 0;
  ser_get_c18_tmp0_791a();
  puVar3 = puVar2 + 1;
  *puVar2 = 0x32;
  uVar7 = ser_to_memcpypgm2ram_79ce(0);
  uVar6 = (undefined1)((ushort)puVar3 >> 8);
  if (!CARRY1(bVar9,bVar10) && bVar9 + bVar10 < 0x23) {
    puVar4 = (undefined1 *)((ushort)puVar3 & 0xff00);
    uVar6 = (undefined1)((ushort)(puVar4 + -1) >> 8);
    *puVar4 = *puVar4;
  }
  uVar1 = c18_tmp3;
  pbVar5 = (byte *)CONCAT11(uVar6,uVar7) + 1;
  *(byte *)CONCAT11(uVar6,uVar7) = serial_cmd_hash;
  temp_channel = param_read_max(uVar1);
  *pbVar5 = *pbVar5;
  pbVar5[-1] = serial_cmd_hash;
  temp_new_reading = param_read_min();
  *pbVar5 = *pbVar5;
  ntc_table_ptr_hi = ser_to_eeprom_read_raw_79b6();
  return;
}

