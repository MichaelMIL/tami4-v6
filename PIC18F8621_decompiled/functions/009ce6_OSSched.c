// address 0x009ce6  size 430 bytes
// callers: 00b256,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Salvo RTOS scheduler (runs eligible tasks, processes delay queue) */

byte OSSched(void)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  short sVar15;
  char *pcVar16;
  byte *pbVar17;
  byte *pbVar18;
  undefined1 *puVar19;
  
  clearWatchDogTimer();
  uVar2 = INTCON;
  pbVar7 = &FramePointer10x0001;
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  while (OSeligQP_hi != '\0' || OSeligQP != 0) {
    os_tmp_tcb_ptr = OSeligQP;
    os_tmp_tcb_ptr_hi = OSeligQP_hi;
    pbVar14 = (byte *)CONCAT11(OSeligQP_hi + (0xfc < OSeligQP),OSeligQP + 3);
    sVar15 = CONCAT11(OSeligQP_hi,OSeligQP);
    OSeligQP = *pbVar14;
    OSeligQP_hi = pbVar14[1];
    *(undefined1 *)(sVar15 + 4) = 0;
    *(undefined1 *)(sVar15 + 6) = 0;
    *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) =
         *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x8f | 0x50;
    *pbVar7 = 0x98;
    pbVar7[1] = 0;
    pbVar7[2] = os_tmp_tcb_ptr;
    puVar5 = pbVar7 + 4;
    pbVar7[3] = os_tmp_tcb_ptr_hi;
    OSInsPrioQ();
    *puVar5 = *puVar5;
    puVar5[-1] = puVar5[-1];
    puVar5[-2] = puVar5[-2];
    puVar5[-3] = puVar5[-3];
    if (OSeligQP_hi == '\0' && OSeligQP == 0) {
      OSeligQTail = 0;
      OSeligQTail_hi = 0;
    }
    pbVar6 = (byte *)CONCAT11((char)((ushort)(puVar5 + -4) >> 8) - ~((char)(puVar5 + -4) != '\0'),
                              (char)(puVar5 + -4) + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 | *pbVar6;
    bVar1 = INTCON;
    pbVar7 = pbVar6 + 1;
    *pbVar6 = bVar1 & (PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
  }
  while (OSlostTicks != '\0') {
    OSlostTicks = OSlostTicks + -1;
    os_tmp_tcb_ptr = OSdelayQP;
    os_tmp_tcb_ptr_hi = OSdelayQP_hi;
    if (OSdelayQP_hi != '\0' || OSdelayQP != 0) {
      pcVar16 = (char *)CONCAT11(OSdelayQP_hi + (0xfa < OSdelayQP),OSdelayQP + 5);
      *pcVar16 = *pcVar16 + -1;
    }
    while ((os_tmp_tcb_ptr_hi != '\0' || os_tmp_tcb_ptr != 0 &&
           (*(char *)CONCAT11(os_tmp_tcb_ptr_hi + (0xfa < os_tmp_tcb_ptr),os_tmp_tcb_ptr + 5) ==
            '\0'))) {
      pbVar17 = (byte *)CONCAT11(os_tmp_tcb_ptr_hi + (0xfc < os_tmp_tcb_ptr),os_tmp_tcb_ptr + 3);
      OSdelayQP = *pbVar17;
      OSdelayQP_hi = pbVar17[1];
      *(undefined1 *)CONCAT11(os_tmp_tcb_ptr_hi + (0xfa < os_tmp_tcb_ptr),os_tmp_tcb_ptr + 5) =
           OStimerTicks;
      *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) =
           *(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x8f | 0x50;
      *pbVar7 = 0x98;
      pbVar7[1] = 0;
      pbVar7[2] = os_tmp_tcb_ptr;
      puVar8 = pbVar7 + 4;
      pbVar7[3] = os_tmp_tcb_ptr_hi;
      OSInsPrioQ();
      *puVar8 = *puVar8;
      puVar8[-1] = puVar8[-1];
      puVar8[-2] = puVar8[-2];
      puVar8[-3] = puVar8[-3];
      os_tmp_tcb_ptr = OSdelayQP;
      os_tmp_tcb_ptr_hi = OSdelayQP_hi;
      pbVar9 = (byte *)CONCAT11((char)((ushort)(puVar8 + -4) >> 8) - ~((char)(puVar8 + -4) != '\0'),
                                (char)(puVar8 + -4) + -1);
      bVar1 = INTCON;
      INTCON = bVar1 & ~(PEIE | GIE);
      bVar1 = INTCON;
      INTCON = bVar1 | *pbVar9;
      bVar1 = INTCON;
      pbVar7 = pbVar9 + 1;
      *pbVar9 = bVar1 & (PEIE | GIE);
      bVar1 = INTCON;
      INTCON = bVar1 & ~(PEIE | GIE);
    }
  }
  os_tmp_tcb_ptr = OScTcbP;
  os_tmp_tcb_ptr_hi = OScTcbP_hi;
  cVar4 = (char)pbVar7;
  if (OScTcbP_hi == '\0' && OScTcbP == 0) {
    pbVar13 = (byte *)CONCAT11((char)((ushort)pbVar7 >> 8) - ~(cVar4 != '\0'),cVar4 + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 | *pbVar13;
    OSIdlingHook(*pbVar13);
    bVar1 = INTCON;
    pbVar12 = pbVar13 + 1;
    *pbVar13 = bVar1 & (PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
  }
  else {
    pbVar18 = (byte *)CONCAT11(OScTcbP_hi + (0xfc < OScTcbP),OScTcbP + 3);
    pbVar10 = (byte *)CONCAT11((char)((ushort)pbVar7 >> 8) - ~(cVar4 != '\0'),cVar4 + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    bVar1 = *pbVar10;
    bVar3 = INTCON;
    INTCON = bVar3 | bVar1;
    puVar19 = (undefined1 *)CONCAT11(OScTcbP_hi,OScTcbP);
    OScTcbP = *pbVar18;
    OScTcbP_hi = pbVar18[1];
    *puVar19 = *puVar19;
    c18_tmp0 = puVar19[1];
    c18_tmp1 = puVar19[2];
    OSDispatch(bVar1);
    bVar1 = INTCON;
    pbVar12 = pbVar10 + 1;
    *pbVar10 = bVar1 & (PEIE | GIE);
    bVar1 = INTCON;
    INTCON = bVar1 & ~(PEIE | GIE);
    if ((*(byte *)CONCAT11(os_tmp_tcb_ptr_hi,os_tmp_tcb_ptr) & 0x70) == 0x50) {
      pbVar10[1] = 0x98;
      pbVar10[2] = 0;
      pbVar10[3] = os_tmp_tcb_ptr;
      pbVar11 = pbVar10 + 5;
      pbVar10[4] = os_tmp_tcb_ptr_hi;
      OSInsPrioQ();
      *pbVar11 = *pbVar11;
      pbVar11[-1] = pbVar11[-1];
      pbVar11[-2] = pbVar11[-2];
      pbVar12 = pbVar11 + -4;
      pbVar11[-3] = pbVar11[-3];
    }
  }
  bVar1 = INTCON;
  INTCON = bVar1 & ~(PEIE | GIE);
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar12 >> 8) - ~((char)pbVar12 != '\0'),
                            (char)pbVar12 + -1);
  bVar3 = INTCON;
  INTCON = bVar3 | bVar1;
  return bVar1;
}

