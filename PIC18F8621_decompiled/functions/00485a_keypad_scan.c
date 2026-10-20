// address 0x00485a  size 58 bytes
// callers: 002c22,004264,

/* Scan 3x3 key matrix (rows RB4/RE6/RE7, columns RB5-RB7); returns 7-bit key mask */

byte keypad_scan(void)

{
  byte bVar1;
  
  local0 = 0;
  bVar1 = TRISB;
  TRISB = bVar1 & ~TRISB4;
  bVar1 = PORTB;
  PORTB = bVar1 & ~RB4;
  bVar1 = PORTB;
  if ((bVar1 & RB7) == 0) {
    local0 = 2;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB5) == 0) {
    local0 = local0 | 1;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB6) == 0) {
    local0 = local0 | 4;
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
    local0 = local0 | 0x40;
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
    local0 = local0 | 0x20;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB7) == 0) {
    local0 = local0 | 8;
  }
  bVar1 = PORTB;
  if ((bVar1 & RB5) == 0) {
    local0 = local0 | 0x10;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | TRISE7;
  bVar1 = PORTE;
  PORTE = bVar1 | RE7;
  return local0;
}

