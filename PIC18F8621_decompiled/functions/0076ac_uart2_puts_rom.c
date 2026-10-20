// address 0x0076ac  size 44 bytes
// callers: 007914,007ab2,007910,006e5c,

/* Send NUL-terminated ROM string on EUSART2 */

void uart2_puts_rom(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char *in_TBLPTR;
  
  ser_c18_prologue_78fe();
  puVar2 = (undefined1 *)in_FSR2;
  while( true ) {
    puVar2[-2] = puVar2[-1] + '\x01';
    puVar3 = puVar2 + 4;
    in_TBLPTR = (char *)CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(puVar2[1],puVar2[-3]));
    if (puVar2[-1] == -1) {
      puVar3 = puVar2 + 6;
      puVar2[2] = puVar2[3] + '\x01';
    }
    uart2_tx_char = *in_TBLPTR;
    if (uart2_tx_char == '\0') break;
    do {
      bVar1 = PIR3;
      TXREG2 = uart2_tx_char;
      puVar2 = puVar3;
    } while ((bVar1 & TX2IF) == 0);
  }
  ser_c18_epilogue_794a(0);
  return;
}

