// address 0x0050aa  size 8 bytes
// callers: 004f5a,003584,

/* Auto: compiler fragment: RCALL 0x004c3a ; MOVLW #0xff ; XORWF POSTINC0,w,ACCESS ; RETURN 0x0 */

byte ser_test_value_50aa(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_calc_array_ptr_4c3a();
  return *(byte *)in_FSR0 ^ 0xff;
}

