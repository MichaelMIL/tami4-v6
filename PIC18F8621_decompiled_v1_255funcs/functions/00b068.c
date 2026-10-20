// address 0x00b068

void FUN_CODE_00b068(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH5;
  bVar1 = PORTG;
  PORTG = bVar1 & ~RG3;
  bVar1 = PORTG;
  PORTG = bVar1 & ~RG0;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH0;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH1;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH2;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH3;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH4;
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF6;
  DAT_DATA_0ee0 = 0;
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF5;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB3;
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH6;
  if ((DAT_DATA_015b & 8) == 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH6;
  }
  else {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH4;
  }
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH7;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB0;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB1;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC0;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC1;
  return;
}

