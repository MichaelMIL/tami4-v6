// address 0x00f5c4  size 28 bytes
// callers: 0095f2,

/* Auto: compiler fragment: MOVLW #0xfe ; MOVFF PLUSW1,FSR0L ; MOVLW #0xff ; MOVFF PLUSW1,FSR0H ;
   CLRF PRODL,ACCESS ; CLRF PRODH,ACCESS ; MOVF POSTINC0,f,ACCESS ; BZ 0x00f5de ; INFSNZ
   PRODL,f,ACCESS ; INCF PRODH,f,ACCESS ; BRA 0x00f5d4 ; RETURN 0x0 */

undefined1 mod_frag_f5c4(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 in_FramePointer1_00000001;
  undefined1 in_FramePointer1_0000ffff;
  
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000001,in_FramePointer1_0000ffff);
  do {
    cVar1 = *pcVar2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}

