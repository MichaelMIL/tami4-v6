// address 0x00ce44

/* WARNING: Instruction at (CODE,0x00ce50) overlaps instruction at (CODE,0x00ce4e)
    */

undefined1 FUN_CODE_00ce44(void)

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
  FUN_CODE_00ce26();
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
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa3;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x2f;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x25;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x81;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x3f;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa0;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xc0;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x40;
  FUN_CODE_00cece();
  puVar3 = puVar2 + -1;
  *puVar2 = *puVar2;
  FUN_CODE_00ce26();
  FUN_CODE_00ce26();
  puVar4 = puVar3 + 1;
  *puVar3 = 0xa4;
  FUN_CODE_00cece();
  *puVar4 = *puVar4;
  puVar4[-1] = 0xaf;
  FUN_CODE_00cece();
  *puVar4 = *puVar4;
  return 0;
}

