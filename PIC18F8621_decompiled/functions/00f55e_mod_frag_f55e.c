// address 0x00f55e  size 52 bytes
// callers: 0048b2,

/* Auto: compiler fragment: MOVLW #0xfe ; MOVFF PLUSW1,FSR0L ; MOVLW #0xff ; MOVFF PLUSW1,FSR0H ;
   MOVFF FSR0L,PRODL ; MOVFF FSR0H,PRODH ; MOVLW #0xfb ; MOVF PLUSW1,w,ACCESS ; BNZ 0x00f57e ; MOVLW
   #0xfc ; MOVF PLUSW1,w,ACCESS ; BZ 0x00f590 ; MOVLW #0xfb ; DEC */

undefined1 mod_frag_f55e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined1 in_FramePointer1_00000001;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar1 = &FramePointer10x0002;
  puVar4 = (undefined1 *)CONCAT11(in_FramePointer1_00000001,in_FramePointer1_0000ffff);
  do {
    pcVar2 = puVar1 + 1;
    if (puVar1[-4] == '\0') {
      pcVar2 = puVar1 + 2;
      if (puVar1[-2] == '\0') {
        return 0;
      }
    }
    pcVar3 = pcVar2 + 2;
    pcVar2[-4] = pcVar2[-3] + -1;
    if (pcVar2[-3] == '\0') {
      pcVar3 = pcVar2 + 4;
      pcVar2[-1] = *pcVar2 + -1;
    }
    puVar1 = pcVar3 + 1;
    *puVar4 = pcVar3[-2];
    puVar4 = puVar4 + 1;
  } while( true );
}

