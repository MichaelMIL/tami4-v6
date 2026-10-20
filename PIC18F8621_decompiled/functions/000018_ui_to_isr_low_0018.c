// address 0x000018  size 4 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: calls isr_low; 1 instr */

undefined1 ui_to_isr_low_0018(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  bool bVar10;
  
  puVar3 = &FramePointer10x000b;
  cVar8 = '\x14';
  puVar7 = (undefined1 *)0x0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar2 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  cVar8 = '\x10';
  puVar7 = &c18_tmp0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar4 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar4 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  puVar5 = puVar3 + 1;
  puVar6 = puVar3 + 1;
  *puVar3 = *puVar3;
  bVar1 = INTCON;
  if (((bVar1 & TMR0IE) == 0) || (bVar1 = INTCON, (bVar1 & TMR0IF) == 0)) {
    isr_low_other();
    puVar7 = puVar6;
  }
  else {
    bVar1 = INTCON;
    INTCON = bVar1 & ~TMR0IF;
    bVar1 = TMR0L;
    cVar8 = TMR0H;
    tmr0_next_lo = bVar1 + tmr0_reload_lo;
    tmr0_next_hi = cVar8 + tmr0_reload_hi + CARRY1(bVar1,tmr0_reload_lo);
    TMR0H = tmr0_next_hi;
    TMR0L = tmr0_next_lo;
    if (os_tick_suppress == '\0') {
      os_tick(0);
      puVar7 = puVar5;
    }
    else {
      tick_hold_counter = tick_hold_counter + '\x01';
      puVar7 = puVar3 + 1;
      if (tick_hold_counter == 'd') {
        tick_hold_counter = '\0';
        puVar7 = puVar3 + 1;
      }
    }
  }
  *puVar7 = *puVar7;
  cVar8 = '\x10';
  puVar7 = puVar7 + -1;
  puVar9 = &c18_tmp15;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  cVar8 = '\x14';
  puVar9 = &math_tmp13;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  return puVar7[-8];
}

