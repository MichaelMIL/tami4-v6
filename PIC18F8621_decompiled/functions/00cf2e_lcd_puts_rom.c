// address 0x00cf2e  size 64 bytes
// callers: 00a414,0023f6,00bab0,00b7e6,00bae0,00d08c,00b772,

/* Draw a ROM string on the LCD */

void lcd_puts_rom(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char cVar3;
  char *in_TBLPTR;
  undefined1 uVar4;
  
  mod_c18_prologue_d11e();
  do {
    *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + '\x01';
    puVar1 = (undefined1 *)((short)in_FSR2 + 4);
    uVar4 = (undefined1)((uint3)in_TBLPTR >> 0x10);
    in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(*(undefined1 *)((short)in_FSR2 + 1),
                                                *(undefined1 *)((short)in_FSR2 + -3)));
    if (*(char *)((short)in_FSR2 + -1) == -1) {
      puVar1 = (undefined1 *)((short)in_FSR2 + 6);
      *(char *)((short)in_FSR2 + 2) = *(char *)((short)in_FSR2 + 3) + '\x01';
    }
    lcd_delay_counter = *in_TBLPTR;
    if (lcd_delay_counter == '\0') {
      in_FSR2 = (BADSPACEBASE *)(puVar1 + 2);
      in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(puVar1[-1],puVar1[-3]));
      cVar3 = *in_TBLPTR;
      if (cVar3 == '\0') {
        mod_c18_epilogue_d130(0);
        return;
      }
      *(undefined1 *)in_FSR1 = 0;
    }
    else {
      *(char *)in_FSR1 = lcd_delay_counter;
      in_FSR2 = (BADSPACEBASE *)puVar1;
      cVar3 = lcd_delay_counter;
    }
    pcVar2 = (char *)((short)in_FSR1 + 1);
    lcd_write_data(cVar3);
    in_FSR1 = (BADSPACEBASE *)(pcVar2 + -1);
    *pcVar2 = *pcVar2;
  } while( true );
}

