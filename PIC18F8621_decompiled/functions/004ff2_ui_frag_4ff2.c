// address 0x004ff2  size 10 bytes
// callers: 0048b2,

/* Auto: compiler fragment: RCALL 0x004be8 ; MOVLW #0x31 ; MOVWF INDF0,ACCESS ; GOTO 0x004be8 */

void ui_frag_4ff2(void)

{
  BADSPACEBASE *in_FSR0;
  
  ui_frame_access_4be8();
  *(undefined1 *)in_FSR0 = 0x31;
  ui_frame_access_4be8();
  return;
}

