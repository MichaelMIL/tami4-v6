// address 0x00a1aa

undefined1 FUN_CODE_00a1aa(void)

{
  undefined1 uVar1;
  byte bVar2;
  
  uVar1 = INTCON;
  bVar2 = INTCON;
  INTCON = bVar2 & ~(PEIE | GIE);
  return 0x3f;
}

