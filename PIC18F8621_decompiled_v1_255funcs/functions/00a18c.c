// address 0x00a18c

byte FUN_CODE_00a18c(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  bVar1 = *(byte *)CONCAT11((char)((ushort)in_FSR1 >> 8) + '\x01',0xff);
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}

