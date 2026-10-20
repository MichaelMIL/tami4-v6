// address 0x004f12  size 10 bytes
// callers: 002c22,004550,003b12,

/* Auto: reads PORTH,PORTB,PORTC; 5 instr */

void ui_get_PORTH_4f12(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 & ~RH7;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB0;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB1;
  bVar1 = PORTC;
  PORTC = bVar1 & ~RC0;
  return;
}

