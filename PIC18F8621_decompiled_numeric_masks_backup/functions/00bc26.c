// address 0x00bc26

/* WARNING: Instruction at (CODE,0x00bc86) overlaps instruction at (CODE,0x00bc84)
    */

undefined1 FUN_CODE_00bc26(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = TRISG;
  TRISG = bVar1 | 4;
  bVar1 = TRISG;
  TRISG = bVar1 & 0xfd;
  TXSTA2 = 0x24;
  SPBRG2 = 0x19;
  RCSTA2 = 0x90;
  bVar1 = IPR1;
  IPR1 = bVar1 | 0x20;
  bVar1 = PIE3;
  PIE3 = bVar1 & 0xef;
  bVar1 = PIE3;
  PIE3 = bVar1 | 0x20;
  DAT_DATA_0eda = 0;
  DAT_DATA_0edb = 0xd9;
  bVar1 = T0CON;
  T0CON = bVar1 & 0xdf;
  bVar1 = T0CON;
  T0CON = bVar1 & 0xbf;
  TMR0H = 0xd9;
  TMR0L = 0;
  bVar1 = T0CON;
  T0CON = bVar1 | 8;
  bVar1 = T0CON;
  T0CON = bVar1 | 0x80;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & 0xfb;
  bVar1 = INTCON;
  INTCON = bVar1 | 0x20;
  ADCON1 = 6;
  ADCON0 = 0;
  PORTA = 0;
  bVar1 = TRISA;
  TRISA = bVar1 | 0x33;
  TRISF = 0x3f;
  CMCON = 0xf;
  ADCON2 = 0x85;
  bVar1 = PIR1;
  PIR1 = bVar1 & 0xbf;
  bVar1 = PIE1;
  PIE1 = bVar1 & 0xbf;
  bVar1 = ADCON0;
  ADCON0 = bVar1 | 1;
  cVar2 = '<';
  do {
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  TRISB = 0xe4;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & 0x7f;
  TRISC = 0xfc;
  TRISE = 0x3f;
  TRISH = 0;
  TRISG = 0xe6;
  bVar1 = PORTF;
  PORTF = bVar1 & 0xbf;
  DAT_DATA_0ee0 = 0;
  bVar1 = TRISF;
  TRISF = bVar1 & 0xbf;
  bVar1 = TRISJ;
  TRISJ = bVar1 | 3;
  bVar1 = TRISC;
  TRISC = bVar1 | 8;
  bVar1 = TRISJ;
  TRISJ = bVar1 | 0xe0;
  bVar1 = TRISJ;
  TRISJ = bVar1 | 0x18;
  bVar1 = RCON;
  RCON = bVar1 | 0x80;
  DAT_DATA_0ee1 = 0xf;
  return 0;
}

