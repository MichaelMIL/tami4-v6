// address 0x005022  size 12 bytes
// callers: 0048b2,004be8,

/* Auto: compiler fragment: ADDWF FSR2L,w,ACCESS ; MOVWF FSR0L,ACCESS ; MOVLW #0x0 ; ADDWFC
   FSR2H,w,ACCESS ; MOVWF FSR0H,ACCESS ; RETURN 0x0 */

char ser_ptr_add_5022(byte param_1)

{
  byte in_FSR2L;
  char in_FSR2H;
  
  return in_FSR2H + CARRY1(in_FSR2L,param_1);
}

