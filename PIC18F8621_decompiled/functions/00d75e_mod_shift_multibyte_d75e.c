// address 0x00d75e  size 12 bytes
// callers: 00d4a4,

/* Auto: compiler fragment: MOVWF FSR1L,ACCESS ; MOVF 0x0016,w,ACCESS ; MOVLB #0x2 ; MOVWF
   0x1,BANKED ; RLCF 0x0016,w,ACCESS ; RETURN 0x0 */

byte mod_shift_multibyte_d75e(void)

{
  byte unaff_C;
  
  fault_code = c18_tmp2;
  return c18_tmp2 << 1 | unaff_C & 1;
}

