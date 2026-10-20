// address 0x00aa38  size 12 bytes
// callers: 00a79e,00a7ee,

/* Auto: compiler fragment: MOVLW #0xc ; MOVWF 0x0014,ACCESS ; RCALL 0x00a8ba ; MOVF 0x0014,w,ACCESS
   ; SUBWF INDF0,f,ACCESS ; RETURN 0x0 */

char mod_compare_multibyte_aa38(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  c18_tmp0 = '\f';
  mod_frame_load_ptr_arg_a8ba();
  cVar1 = c18_tmp0;
  *(char *)in_FSR0 = *(char *)in_FSR0 - c18_tmp0;
  return cVar1;
}

