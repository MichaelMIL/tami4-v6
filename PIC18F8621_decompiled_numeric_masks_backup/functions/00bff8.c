// address 0x00bff8

/* WARNING: Instruction at (CODE,0x00c020) overlaps instruction at (CODE,0x00c01e)
    */
/* WARNING: Removing unreachable block (CODE,0x00c04c) */
/* WARNING: Removing unreachable block (CODE,0x00c054) */
/* WARNING: Removing unreachable block (CODE,0x00c058) */
/* WARNING: Removing unreachable block (CODE,0x00c062) */
/* WARNING: Removing unreachable block (CODE,0x00c066) */
/* WARNING: Removing unreachable block (CODE,0x00c070) */
/* WARNING: Removing unreachable block (CODE,0x00c07a) */
/* WARNING: Removing unreachable block (CODE,0x00c07e) */
/* WARNING: Removing unreachable block (CODE,0x00c088) */
/* WARNING: Removing unreachable block (CODE,0x00c08c) */
/* WARNING: Removing unreachable block (CODE,0x00c092) */
/* WARNING: Removing unreachable block (CODE,0x00c09c) */
/* WARNING: Removing unreachable block (CODE,0x00c0b6) */
/* WARNING: Removing unreachable block (CODE,0x00c0ba) */
/* WARNING: Removing unreachable block (CODE,0x00c0cc) */
/* WARNING: Removing unreachable block (CODE,0x00c0b8) */
/* WARNING: Removing unreachable block (CODE,0x00c0d0) */
/* WARNING: Removing unreachable block (CODE,0x00c0a6) */
/* WARNING: Removing unreachable block (CODE,0x00c0a8) */
/* WARNING: Removing unreachable block (CODE,0x00c0aa) */
/* WARNING: Removing unreachable block (CODE,0x00c0ae) */
/* WARNING: Removing unreachable block (CODE,0x00c090) */
/* WARNING: Removing unreachable block (CODE,0x00c0d6) */

void FUN_CODE_00bff8(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = INTCON;
  INTCON = bVar1 | 0xc0;
  bVar1 = PORTB;
  PORTB = bVar1 | 8;
  DAT_DATA_0033 = 0;
  for (DAT_DATA_0032 = 0;
      (byte)~(0x99 < DAT_DATA_0032) <= DAT_DATA_0033 && DAT_DATA_0033 - ~(0x99 < DAT_DATA_0032) < 3;
      DAT_DATA_0032 = DAT_DATA_0032 + 1) {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_DATA_0033 = DAT_DATA_0033 + (0xfe < DAT_DATA_0032);
  }
  bVar1 = PORTB;
  PORTB = bVar1 & 0xf7;
  do {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
  } while( true );
}

