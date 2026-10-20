// address 0x00485a

byte FUN_CODE_00485a(void)

{
  byte bVar1;
  
  DAT_DATA_0024 = 0;
  bVar1 = TRISB;
  TRISB = bVar1 & ~TRISB4;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB4;
  bVar1 = PORTB;
  if ((bVar1 & RB7) == 0) {
    DAT_DATA_0024 = 2;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB5) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 1;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 4;
  }
  bVar1 = TRISB;
  TRISB = bVar1 | TRISB4;
  bVar1 = PORTB;
  PORTB = bVar1 | RB4;
  bVar1 = TRISE;
  TRISE = bVar1 & ~TRISE6;
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE6;
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 0x40;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | TRISE6;
  bVar1 = PORTE;
  PORTE = bVar1 | RE6;
  bVar1 = TRISE;
  TRISE = bVar1 & ~TRISE7;
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE7;
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 0x20;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB7) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 8;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB5) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 0x10;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | TRISE7;
  bVar1 = PORTE;
  PORTE = bVar1 | RE7;
  return DAT_DATA_0024;
}

