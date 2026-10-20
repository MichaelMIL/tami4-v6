// address 0x00a18c  size 16 bytes
// callers: 009f30,00a038,009f46,00a2d4,009af0,00a09a,

/* Salvo helper: restore saved GIE/PEIE state */

byte OSRestoreInts(void)

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

