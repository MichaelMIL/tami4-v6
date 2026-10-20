// address 0x00bff8  size 238 bytes
// callers: 00b256,

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
/* Sound buzzer (RB3) briefly then loop forever (watchdog reset) */

void beep_and_halt(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = INTCON;
  INTCON = bVar1 | (PEIE | GIE);
  bVar1 = PORTB;
  PORTB = bVar1 | RB3;
  adc_raw_hi = 0;
  for (adc_raw_lo = 0;
      (byte)~(0x99 < adc_raw_lo) <= adc_raw_hi && adc_raw_hi - ~(0x99 < adc_raw_lo) < 3;
      adc_raw_lo = adc_raw_lo + 1) {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    adc_raw_hi = adc_raw_hi + (0xfe < adc_raw_lo);
  }
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB3;
  do {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
  } while( true );
}

