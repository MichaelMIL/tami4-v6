// address 0x00ce26  size 30 bytes
// callers: 00ce44,

/* WARNING: Instruction at (CODE,0x00ce3a) overlaps instruction at (CODE,0x00ce38)
    */
/* Short busy-wait delay for the LCD controller */

undefined1 lcd_delay(void)

{
  char cVar1;
  
  for (lcd_delay_counter = 'F'; lcd_delay_counter != '\0';
      lcd_delay_counter = lcd_delay_counter + -1) {
    cVar1 = '<';
    do {
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
  }
  return 0;
}

