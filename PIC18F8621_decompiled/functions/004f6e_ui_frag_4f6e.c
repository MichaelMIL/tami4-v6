// address 0x004f6e  size 10 bytes
// callers: 0048b2,

/* Auto: compiler fragment: RCALL 0x004be8 ; MOVLW #0x32 ; MOVWF INDF0,ACCESS ; GOTO 0x004be8 */

void ui_frag_4f6e(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_frame_access_4be8();
  *(undefined1 *)in_FSR0 = 0x32;
  ui_frame_access_4be8();
  return;
}

