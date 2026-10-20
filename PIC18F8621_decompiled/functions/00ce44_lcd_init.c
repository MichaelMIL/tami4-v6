// address 0x00ce44  size 138 bytes
// callers: 004264,

/* WARNING: Instruction at (CODE,0x00ce50) overlaps instruction at (CODE,0x00ce4e)
    */
/* Reset and initialise the 128x64 graphic LCD controller */

undefined1 lcd_init(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  
  bVar1 = TRISE;
  TRISE = bVar1 & (TRISE6 | TRISE7);
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE4;
  cVar5 = '\x04';
  do {
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  cVar5 = '\x04';
  do {
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  bVar1 = PORTE;
  PORTE = bVar1 | RE4;
  lcd_delay();
  bVar1 = TRISE;
  TRISE = bVar1 & (TRISE6 | TRISE7);
  TRISD = 0;
  bVar1 = PORTE;
  PORTE = bVar1 | RE5;
  bVar1 = PORTE;
  PORTE = bVar1 & ~RE0;
  bVar1 = PORTE;
  PORTE = bVar1 | RE1;
  bVar1 = PORTE;
  PORTE = bVar1 | RE2;
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0xe2;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa3;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x2f;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x25;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x81;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x3f;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa0;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xc0;
  lcd_write_cmd();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x40;
  lcd_write_cmd();
  puVar3 = puVar2 + -1;
  *puVar2 = *puVar2;
  lcd_delay();
  lcd_delay();
  puVar4 = puVar3 + 1;
  *puVar3 = 0xa4;
  lcd_write_cmd();
  *puVar4 = *puVar4;
  puVar4[-1] = 0xaf;
  lcd_write_cmd();
  *puVar4 = *puVar4;
  return 0;
}

