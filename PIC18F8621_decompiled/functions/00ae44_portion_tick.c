// address 0x00ae44  size 168 bytes
// callers: 00acc6,

/* Every 100 ms: run portion phases (cold, hot, second cold) then stop */

char portion_tick(void)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  
  if (portion_mode == 1) {
    bVar4 = (char)portion_cold_hi < '\0';
    if (((!bVar4) &&
        (bVar3 = ~(portion_cold_lo == '\0'), bVar4 = bVar3 != 0 || portion_cold_hi < -bVar3,
        bVar3 == 0 && portion_cold_hi >= -bVar3)) &&
       (portion_cold_lo != -1 || portion_cold_hi != 0xff)) {
      bVar4 = portion_cold_lo != '\0';
      portion_cold_lo = portion_cold_lo + -1;
      portion_cold_hi = portion_cold_hi - ~bVar4;
      return '\0';
    }
    bVar3 = portion_hot_hi << 1 | bVar4;
    if ((-1 < (char)portion_hot_hi) &&
       (bVar1 = ~(portion_hot_lo == '\0'), bVar3 = -~(portion_hot_lo == '\0') - portion_hot_hi,
       bVar1 == 0 && -bVar1 <= portion_hot_hi)) {
      portion_mode = 3;
      cVar2 = dispense_hot_request();
      return cVar2;
    }
    cVar2 = dispense_stop_all_c(bVar3);
    return cVar2;
  }
  if (portion_mode != 3) {
    cVar2 = portion_mode - 2;
    if (cVar2 != '\0') {
      portion_mode = 0;
      return cVar2;
    }
    bVar3 = portion_cold2_hi << 1 | 1 < portion_mode;
    if ((-1 < (char)portion_cold2_hi) &&
       (bVar1 = ~(portion_cold2_lo == 0), bVar3 = -~(portion_cold2_lo == 0) - portion_cold2_hi,
       bVar1 == 0 && -bVar1 <= portion_cold2_hi)) {
      bVar3 = ~portion_cold2_lo;
      bVar4 = false;
      if (bVar3 == 0) {
        bVar3 = ~portion_cold2_hi;
        bVar4 = bVar3 == 0;
      }
      if (!bVar4) {
        bVar4 = portion_cold2_lo != 0;
        portion_cold2_lo = portion_cold2_lo - 1;
        portion_cold2_hi = portion_cold2_hi - ~bVar4;
        return '\0';
      }
    }
    cVar2 = dispense_stop_all(bVar3);
    return cVar2;
  }
  bVar4 = (char)portion_hot_hi < '\0';
  if (((!bVar4) &&
      (bVar3 = ~(portion_hot_lo == '\0'), bVar4 = bVar3 != 0 || portion_hot_hi < -bVar3,
      bVar3 == 0 && portion_hot_hi >= -bVar3)) && (portion_hot_lo != -1 || portion_hot_hi != 0xff))
  {
    bVar4 = portion_hot_lo != '\0';
    portion_hot_lo = portion_hot_lo + -1;
    portion_hot_hi = portion_hot_hi - ~bVar4;
    return '\0';
  }
  bVar3 = portion_cold2_hi << 1 | bVar4;
  if ((-1 < (char)portion_cold2_hi) &&
     (bVar1 = ~(portion_cold2_lo == 0), bVar3 = -~(portion_cold2_lo == 0) - portion_cold2_hi,
     bVar1 == 0 && -bVar1 <= portion_cold2_hi)) {
    portion_mode = 2;
    cVar2 = dispense_cold_request();
    return cVar2;
  }
  cVar2 = dispense_stop_all_b(bVar3);
  return cVar2;
}

