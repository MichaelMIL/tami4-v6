// address 0x0076d8  size 42 bytes
// callers: 007aa2,

/* Send NUL-terminated RAM string on EUSART2 */

void uart2_puts_ram(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  ser_c18_prologue_78fe();
  puVar2 = (undefined1 *)in_FSR2;
  while( true ) {
    puVar2[-2] = puVar2[-1] + '\x01';
    puVar3 = puVar2 + 4;
    if (puVar2[-1] == -1) {
      puVar3 = puVar2 + 6;
      puVar2[2] = puVar2[3] + '\x01';
    }
    uart2_tx_char = *(char *)CONCAT11(puVar2[1],puVar2[-3]);
    if (*(char *)CONCAT11(puVar2[1],puVar2[-3]) == '\0') break;
    do {
      bVar1 = PIR3;
      TXREG2 = uart2_tx_char;
      puVar2 = puVar3;
    } while ((bVar1 & TX2IF) == 0);
  }
  ser_c18_epilogue_794a(0);
  return;
}

