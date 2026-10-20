// address 0x004f78  size 8 bytes
// callers: 003584,

/* Auto: compiler fragment: RCALL 0x004c3a ; MOVLW #0xfe ; XORWF POSTINC0,w,ACCESS ; RETURN 0x0 */

byte ui_test_value_4f78(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_calc_array_ptr_4c3a();
  return *(byte *)in_FSR0 ^ 0xfe;
}

