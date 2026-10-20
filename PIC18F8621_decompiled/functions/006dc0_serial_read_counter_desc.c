// address 0x006dc0  size 56 bytes
// callers: 007a80,006e5c,

/* Read usage-counter descriptor (name) from ROM table */

undefined1 serial_read_counter_desc(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  
  puVar1 = &FramePointer10x0002;
  bVar2 = (byte)((ushort)serial_cmd_hash * 6);
  bVar3 = (byte)((ushort)serial_cmd_hash * 6 >> 8);
  bVar4 = 0x98 < bVar2;
  c18_tmp0 = bVar2 + 0x67;
  c18_tmp1 = (bVar3 - 0x21) + bVar4;
  c18_tmp2 = 0;
  ser_get_c18_tmp0_791a();
  bVar2 = (byte)((ushort)(puVar1 + 1) >> 8);
  *puVar1 = 0x39;
  ser_to_memcpypgm2ram_79ce(0);
  if (!CARRY1(bVar3,bVar4) && bVar3 + bVar4 < 0x21) {
    *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
  }
  return c18_tmp3;
}

