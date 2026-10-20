// address 0x007702  size 114 bytes
// callers: 0078ae,007774,

/* Convert nibble to ASCII hex digit */

void serial_hex_digit(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ser_c18_prologue_78fe();
  if (*(byte *)((short)in_FSR2 + -2) < 0x41) {
    c18_tmp0 = '0';
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -1);
    *(char *)in_FSR1 = *(char *)in_FSR1 - c18_tmp0;
  }
  else {
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -1) - 0x37;
  }
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR1;
  if (*(byte *)in_FSR2 < 0x41) {
    c18_tmp0 = '0';
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + 1);
    *(char *)in_FSR1 = *(char *)in_FSR1 - c18_tmp0;
  }
  else {
    *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + 1) - 0x37;
  }
  *(byte *)((short)in_FSR2 + 2) = *(byte *)in_FSR1;
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + 3);
  bVar1 = *(byte *)((short)in_FSR2 + 5);
  *(byte *)((short)in_FSR1 + 1) = *(byte *)((short)in_FSR1 + 1);
  ser_c18_epilogue_794a(*(char *)in_FSR1 + bVar1 * '\x10');
  return;
}

