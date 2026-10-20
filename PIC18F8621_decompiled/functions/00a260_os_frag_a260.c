// address 0x00a260  size 10 bytes
// callers: 00a038,00a0b6,009af0,

/* Auto: compiler fragment: MOVLW #0x8f ; ANDWF INDF0,w,ACCESS ; IORLW #0x10 ; MOVWF INDF0,ACCESS ;
   RETURN 0x0 */

byte os_frag_a260(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 & 0x8f | 0x10;
}

