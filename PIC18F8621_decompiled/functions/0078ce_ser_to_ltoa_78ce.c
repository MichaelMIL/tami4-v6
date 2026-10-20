// address 0x0078ce  size 30 bytes
// callers: 006e5c,

/* Auto: calls ltoa; 10 instr */

char ser_to_ltoa_78ce(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  ser_get_serial_ptr_lo_7abc();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR0 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR0 + 2);
  cVar1 = (char)(undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR0 + 3);
  c18_tmp0 = ltoa();
  return cVar1 + -6;
}

