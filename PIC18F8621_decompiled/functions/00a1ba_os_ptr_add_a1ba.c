// address 0x00a1ba  size 16 bytes
// callers: 009b64,

/* Auto: compiler fragment: RCALL 0x00a302 ; RCALL 0x00a2a4 ; RCALL 0x00a272 ; ADDWF FSR0L,f,ACCESS
   ; MOVLW #0x0 ; ADDWFC FSR0H,f,ACCESS ; GOTO 0x00a2fc */

void os_ptr_add_a1ba(void)

{
  os_frag_a302();
  os_frame_access_a2a4();
  os_copy_ptr_field_a272();
  os_chain_fna27c_fna26a_a2fc(0);
  return;
}

