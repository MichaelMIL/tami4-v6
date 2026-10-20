// address 0x0078ae  size 32 bytes
// callers: 007a90,

/* Auto: reads c18_tmp3,c18_tmp2,c18_tmp1,c18_tmp0; calls serial_hex_digit; 12 instr */

void ser_to_serial_hex_digit_78ae(void)

{
  BADSPACEBASE *in_FSR1;
  
  serial_hex_digit();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)((short)in_FSR1 + -2) = *(undefined1 *)((short)in_FSR1 + -2);
  c18_tmp3 = *(undefined1 *)((short)in_FSR1 + -3);
  *(undefined1 *)((short)in_FSR1 + -3) = *(undefined1 *)((short)in_FSR1 + -3);
  c18_tmp2 = *(undefined1 *)((short)in_FSR1 + -4);
  *(undefined1 *)((short)in_FSR1 + -4) = *(undefined1 *)((short)in_FSR1 + -4);
  c18_tmp1 = *(undefined1 *)((short)in_FSR1 + -5);
  *(undefined1 *)((short)in_FSR1 + -5) = *(undefined1 *)((short)in_FSR1 + -5);
  c18_tmp0 = *(undefined1 *)((short)in_FSR1 + -6);
  return;
}

