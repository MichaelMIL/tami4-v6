// address 0x000008  size 4 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: calls isr_high; 1 instr */

undefined1 ui_to_isr_high_0008(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 in_WS;
  
  puVar2 = &FramePointer10x0008;
  cVar6 = '\x14';
  puVar5 = (undefined1 *)0x0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  cVar6 = '\x10';
  puVar5 = &c18_tmp0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar3 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  puVar4 = puVar2 + 1;
  *puVar2 = *puVar2;
  mod_to_uart2_rx_isr_b498();
  *puVar4 = *puVar4;
  cVar6 = '\x10';
  puVar5 = puVar4 + -1;
  puVar7 = &c18_tmp15;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  cVar6 = '\x14';
  puVar7 = &math_tmp13;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  return in_WS;
}

