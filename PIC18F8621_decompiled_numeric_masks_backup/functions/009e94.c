// address 0x009e94

byte FUN_CODE_009e94(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar3;
  byte *pbVar4;
  
  FUN_CODE_009e94(DAT_DATA_0014);
  bVar1 = INTCON;
  pbVar4 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = bVar1 & 0xc0;
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  if ((*(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) & 0x70) == 0x50) {
    *(undefined1 *)((short)in_FSR1 + 1) = 0x98;
    *(undefined1 *)((short)in_FSR1 + 2) = 0;
    *(undefined1 *)((short)in_FSR1 + 3) = DAT_DATA_0060;
    pbVar3 = (byte *)((short)in_FSR1 + 5);
    *(undefined1 *)((short)in_FSR1 + 4) = DAT_DATA_0061;
    FUN_CODE_009b64();
    *pbVar3 = *pbVar3;
    pbVar3[-1] = pbVar3[-1];
    pbVar3[-2] = pbVar3[-2];
    pbVar4 = pbVar3 + -4;
    pbVar3[-3] = pbVar3[-3];
  }
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar4 >> 8) - ~((char)pbVar4 != '\0'),(char)pbVar4 + -1)
  ;
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}

