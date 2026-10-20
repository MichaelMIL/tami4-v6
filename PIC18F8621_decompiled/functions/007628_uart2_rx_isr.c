// address 0x007628  size 132 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* EUSART2 receive: echo, collect line (max 11 chars), hash command word, signal task on CR */

char uart2_rx_isr(char param_1)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar4;
  bool bVar5;
  undefined1 *puVar3;
  
  while (bVar1 = PIR3, (bVar1 & RC2IF) != 0) {
    uart2_rx_byte = RCREG2;
    param_1 = '\0';
    if (((uart2_rx_flags & 1) != 0) &&
       ((uart2_rx_count < 0xb || (param_1 = RCREG2 - 0xd, param_1 == '\0')))) {
      do {
        bVar1 = PIR3;
      } while ((bVar1 & TX2IF) == 0);
      TXREG2 = RCREG2;
      if (RCREG2 == 0xd) {
        uart2_rx_flags = uart2_rx_flags & 0xfe;
        serial_push_sem(0);
        param_1 = OSSignalSem();
        puVar2 = (undefined1 *)((short)in_FSR1 + -1);
        puVar3 = (undefined1 *)((short)in_FSR1 + -1);
        *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
        *puVar2 = *puVar3;
      }
      else {
        if (RCREG2 == 0x20) {
          uart2_rx_flags = uart2_rx_flags & 0xfd;
        }
        if ((uart2_rx_flags & 2) != 0) {
          *(byte *)in_FSR1 = uart2_rx_count;
          cVar4 = *(char *)in_FSR1;
          *(char *)in_FSR1 = cVar4;
          bVar1 = RCREG2;
          while (cVar4 != '\0') {
            bVar1 = bVar1 << 1;
            cVar4 = *(char *)in_FSR1 + -1;
            *(char *)in_FSR1 = cVar4;
          }
          serial_cmd_hash = bVar1 ^ serial_cmd_hash;
        }
        bVar5 = 0x93 < uart2_rx_count;
        cVar4 = uart2_rx_count + 0x6c;
        uart2_rx_byte = TXREG2;
        uart2_rx_count = uart2_rx_count + 1;
        *(byte *)CONCAT11(bVar5 + '\x01',cVar4) = TXREG2;
        param_1 = '\x01';
        *(undefined1 *)CONCAT11((0x93 < uart2_rx_count) + '\x01',uart2_rx_count + 0x6c) = 0;
      }
    }
  }
  return param_1;
}

