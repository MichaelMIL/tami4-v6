// address 0x00ba96  size 10 bytes
// callers: 00bc0e,00bb9a,

/* Auto: compiler fragment: ADDWF FSR0L,f,ACCESS ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ; MOVF
   INDF0,w,ACCESS ; RETURN 0x0 */

undefined1 mod_ptr_add_ba96(undefined1 param_1)

{
  BADSPACEBASE *in_FSR0;
  
  return *(undefined1 *)CONCAT11((char)((ushort)in_FSR0 >> 8),param_1);
}

