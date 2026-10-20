// address 0x009e94  size 92 bytes
// callers: 009e94,

/* Salvo: dispatch current task */

byte OSDispatch(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar3;
  byte *pbVar4;
  
  OSDispatch(c18_tmp0);
  bVar1 = INTCON;
  pbVar4 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = bVar1 & (PEIE | GIE);
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  if ((*(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x70) == 0x50) {
    *(undefined1 *)((short)in_FSR1 + 1) = 0x98;
    *(undefined1 *)((short)in_FSR1 + 2) = 0;
    *(undefined1 *)((short)in_FSR1 + 3) = os_tmp_tcb_ptr;
    pbVar3 = (byte *)((short)in_FSR1 + 5);
    *(undefined1 *)((short)in_FSR1 + 4) = os_tmp_tcb_ptr_hi;
    OSInsPrioQ();
    *pbVar3 = *pbVar3;
    pbVar3[-1] = pbVar3[-1];
    pbVar3[-2] = pbVar3[-2];
    pbVar4 = pbVar3 + -4;
    pbVar3[-3] = pbVar3[-3];
  }
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar4 >> 8) - ~((char)pbVar4 != '\0'),(char)pbVar4 + -1)
  ;
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}

