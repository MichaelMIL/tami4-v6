// address 0x00cfee  size 26 bytes
// callers: 004828,001038,00135c,000304,002ae8,004264,00137a,0029ac,0017c4,002d86,00009a,002370,002c22,0026ae,000318,00261a,0021fc,00233c,000342,002220,003b12,00331e,002bf2,000360,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Clear the LCD (all pages) */

void lcd_clear(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  lcd_page_counter = 0;
  while( true ) {
    if (7 < lcd_page_counter) break;
    pbVar1 = (byte *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
    *pbVar1 = lcd_page_counter;
    mod_stack_adjust_d154('\a' - lcd_page_counter);
    mod_set_lcd_page_counter_d144(0x80);
  }
  return;
}

