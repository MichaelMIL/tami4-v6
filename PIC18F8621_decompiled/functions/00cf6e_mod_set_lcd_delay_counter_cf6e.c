// address 0x00cf6e  size 32 bytes
// callers: 00d164,002a10,00a9a4,00d08c,00d144,00e41a,00a940,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes lcd_delay_counter; reads lcd_delay_counter; 14 instr */

void mod_set_lcd_delay_counter_cf6e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  
  mod_c18_prologue_d11e();
  lcd_delay_counter = *(char *)((short)in_FSR2 + -3);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  while( true ) {
    if (lcd_delay_counter == '\0') break;
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    puVar2 = puVar1 + 1;
    *(undefined1 *)in_FSR1 = puVar1[-2];
    lcd_delay_counter = lcd_delay_counter + -1;
    lcd_write_data();
    in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
    *puVar3 = *puVar3;
    puVar1 = puVar2;
  }
  lcd_delay_counter = lcd_delay_counter + -1;
  mod_c18_epilogue_d130(0);
  return;
}

