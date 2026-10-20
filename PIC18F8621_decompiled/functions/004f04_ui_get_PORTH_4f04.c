// address 0x004f04  size 14 bytes
// callers: 002c22,004550,

/* Auto: reads PORTH,PORTB,PORTC; 7 instr */

void ui_get_PORTH_4f04(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 | RH7;
  bVar1 = PORTB;
  PORTB = bVar1 | RB0;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB1;
  bVar1 = PORTC;
  PORTC = bVar1 | RC0;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC1;
  return;
}

