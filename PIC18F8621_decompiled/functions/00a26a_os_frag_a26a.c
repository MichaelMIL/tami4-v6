// address 0x00a26a  size 8 bytes
// callers: 00a2fc,009b64,009c40,

/* Auto: compiler fragment: RCALL 0x00a302 ; MOVF POSTINC0,w,ACCESS ; IORWF POSTDEC0,w,ACCESS ;
   RETURN 0x0 */

byte os_frag_a26a(void)

{
  BADSPACEBASE *in_FSR0;
  
  os_frag_a302();
  return *(byte *)((short)in_FSR0 + 1) | *(byte *)in_FSR0;
}

