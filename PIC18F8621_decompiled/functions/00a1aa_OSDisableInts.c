// address 0x00a1aa  size 16 bytes
// callers: 009f30,009f7a,00a2b2,00a30c,009af0,

/* Salvo helper: save and clear GIE/PEIE */

undefined1 OSDisableInts(void)

{
  undefined1 uVar1;
  byte bVar2;
  
  uVar1 = INTCON;
  bVar2 = INTCON;
  INTCON = bVar2 & ~(PEIE | GIE);
  return 0x3f;
}

