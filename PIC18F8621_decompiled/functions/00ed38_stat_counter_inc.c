// address 0x00ed38  size 32 bytes
// callers: 00f8da,00f86e,00f7c6,00dcce,00a588,00f93c,00e98a,00c936,00e7a4,00aa56,00fa4c,

/* Increment 32-bit usage counter [id] in RAM */

void stat_counter_inc(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  bVar3 = mod_c18_prologue_edc4();
  bVar2 = (byte)((ushort)bVar3 * 4);
  pbVar4 = (byte *)CONCAT11((char)((ushort)bVar3 * 4 >> 8) + (0x4d < bVar2),bVar2 + 0xb2);
  bVar2 = *pbVar4;
  *pbVar4 = bVar2 + 1;
  bVar3 = pbVar4[1];
  bVar1 = CARRY1(bVar3,0xfe < bVar2);
  pbVar4[1] = bVar3 + (0xfe < bVar2);
  bVar2 = pbVar4[2];
  pbVar4[2] = bVar2 + bVar1;
  pbVar4[3] = pbVar4[3] + CARRY1(bVar2,bVar1);
  mod_c18_epilogue_edda();
  return;
}

