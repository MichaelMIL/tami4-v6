// address 0x00bc26

/* WARNING: Instruction at (CODE,0x00bc86) overlaps instruction at (CODE,0x00bc84)
    */

undefined1 FUN_CODE_00bc26(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = TRISG;
  TRISG = bVar1 | TRISG2;
  bVar1 = TRISG;
  TRISG = bVar1 & ~TRISG1;
  TXSTA2 = (BRGH | TXEN);
  SPBRG2 = 0x19;
  RCSTA2 = (CREN | SPEN);
  bVar1 = IPR1;
  IPR1 = bVar1 | RCIP;
  bVar1 = PIE3;
  PIE3 = bVar1 & ~TX2IE;
  bVar1 = PIE3;
  PIE3 = bVar1 | RC2IE;
  DAT_DATA_0eda = 0;
  DAT_DATA_0edb = 0xd9;
  bVar1 = T0CON;
  T0CON = bVar1 & ~T0CS;
  bVar1 = T0CON;
  T0CON = bVar1 & ~T08BIT;
  TMR0H = 0xd9;
  TMR0L = 0;
  bVar1 = T0CON;
  T0CON = bVar1 | PSA;
  bVar1 = T0CON;
  T0CON = bVar1 | TMR0ON;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & ~TMR0IP;
  bVar1 = INTCON;
  INTCON = bVar1 | TMR0IE;
  ADCON1 = (PCFG1 | PCFG2);
  ADCON0 = 0;
  PORTA = 0;
  bVar1 = TRISA;
  TRISA = bVar1 | (TRISA0 | TRISA1 | TRISA4 | TRISA5);
  TRISF = (TRISF0 | TRISF1 | TRISF2 | TRISF3 | TRISF4 | TRISF5);
  CMCON = (CM0 | CM1 | CM2 | CIS);
  ADCON2 = (ADCS0 | ADCS2 | ADFM);
  bVar1 = PIR1;
  PIR1 = bVar1 & ~ADIF;
  bVar1 = PIE1;
  PIE1 = bVar1 & ~ADIE;
  bVar1 = ADCON0;
  ADCON0 = bVar1 | ADON;
  cVar2 = '<';
  do {
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  TRISB = (TRISB2 | TRISB5 | TRISB6 | TRISB7);
  bVar1 = INTCON2;
  INTCON2 = bVar1 & ~nRBPU;
  TRISC = (TRISC2 | TRISC3 | TRISC4 | TRISC5 | TRISC6 | TRISC7);
  TRISE = (TRISE0 | TRISE1 | TRISE2 | TRISE3 | TRISE4 | TRISE5);
  TRISH = 0;
  TRISG = (TRISG1 | TRISG2 | 0xe0);
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF6;
  DAT_DATA_0ee0 = 0;
  bVar1 = TRISF;
  TRISF = bVar1 & ~TRISF6;
  bVar1 = TRISJ;
  TRISJ = bVar1 | (TRISJ0 | TRISJ1);
  bVar1 = TRISC;
  TRISC = bVar1 | TRISC3;
  bVar1 = TRISJ;
  TRISJ = bVar1 | (TRISJ5 | TRISJ6 | TRISJ7);
  bVar1 = TRISJ;
  TRISJ = bVar1 | (TRISJ3 | TRISJ4);
  bVar1 = RCON;
  RCON = bVar1 | IPEN;
  DAT_DATA_0ee1 = 0xf;
  return 0;
}

