// address 0x00b068

void FUN_CODE_00b068(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 & 0xdf;
  bVar1 = PORTG;
  PORTG = bVar1 & 0xf7;
  bVar1 = PORTG;
  PORTG = bVar1 & 0xfe;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xfe;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xfd;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xfb;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xf7;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xef;
  bVar1 = PORTF;
  PORTF = bVar1 & 0xbf;
  DAT_DATA_0ee0 = 0;
  bVar1 = PORTF;
  PORTF = bVar1 & 0xdf;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xf7;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xbf;
  if ((DAT_DATA_015b & 8) == 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & 0xbf;
  }
  else {
    bVar1 = PORTH;
    PORTH = bVar1 & 0xef;
  }
  bVar1 = PORTH;
  PORTH = bVar1 & 0x7f;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xfe;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xfd;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xfe;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xfd;
  return;
}

