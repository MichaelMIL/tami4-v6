// address 0x00a2c6  size 14 bytes
// callers: 00a1f2,00a09a,

/* Auto: compiler fragment: MOVF INDF0,w,ACCESS ; ANDLW #0x70 ; RRNCF WREG,f,ACCESS ; RRNCF
   WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RRNCF WREG,f,ACCESS ; RETURN 0x0 */

byte os_tcb_get_state_a2c6(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0x70) >> 4;
}

