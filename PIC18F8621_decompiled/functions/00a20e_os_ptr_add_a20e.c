// address 0x00a20e  size 14 bytes
// callers: 009b64,009c40,

/* Auto: compiler fragment: MOVWF FSR0L,ACCESS ; MOVLW #0x0 ; ADDWFC FSR2H,w,ACCESS ; MOVWF
   FSR0H,ACCESS ; MOVF POSTINC0,w,ACCESS ; IORWF POSTDEC0,w,ACCESS ; RETURN 0x0 */

byte os_ptr_add_a20e(undefined1 param_1)

{
  char in_FSR2H;
  byte *pbVar1;
  byte unaff_C;
  
  pbVar1 = (byte *)CONCAT11(in_FSR2H + (unaff_C & 1),param_1);
  return pbVar1[1] | *pbVar1;
}

