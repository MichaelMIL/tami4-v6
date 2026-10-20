// address 0x00fbf6  size 18 bytes
// callers: 00fbe8,

/* Auto: compiler fragment: CPFSLT FSR0H,ACCESS ; BRA 0x00fbfe ; CLRF POSTINC0,ACCESS ; BRA 0x00fbf6
   ; MOVF PRODL,w,ACCESS ; CPFSLT FSR0L,ACCESS ; RETURN 0x0 ; CLRF POSTINC0,ACCESS ; BRA 0x00fc00 */

void mod_frag_fbf6(byte param_1)

{
  BADSPACEBASE *in_FSR0;
  byte in_PRODL;
  
  for (; (byte)((ushort)in_FSR0 >> 8) < param_1; in_FSR0 = (BADSPACEBASE *)((short)in_FSR0 + 1)) {
    *(undefined1 *)in_FSR0 = 0;
  }
  for (; (byte)in_FSR0 < in_PRODL; in_FSR0 = (BADSPACEBASE *)((short)in_FSR0 + 1)) {
    *(undefined1 *)in_FSR0 = 0;
  }
  return;
}

