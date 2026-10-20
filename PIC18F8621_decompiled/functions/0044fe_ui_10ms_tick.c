// address 0x0044fe  size 82 bytes
// callers: 00b0aa,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Every 10 ms: key hold timers */

byte ui_10ms_tick(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_C;
  bool bVar3;
  
  if ((((keys_current & 1) != 0) && (unaff_C = (char)key_cold_hold_hi < '\0', !(bool)unaff_C)) &&
     (bVar2 = ~(key_cold_hold_lo == 0), unaff_C = bVar2 != 0 || key_cold_hold_hi < -bVar2,
     bVar2 == 0 && key_cold_hold_hi >= -bVar2)) {
    c18_tmp0 = ~key_cold_hold_lo;
    c18_tmp1 = ~key_cold_hold_hi;
    if (c18_tmp1 != 0 || c18_tmp0 != 0) {
      bVar3 = key_cold_hold_lo != 0;
      key_cold_hold_lo = key_cold_hold_lo - 1;
      unaff_C = key_cold_hold_hi != ~bVar3;
      key_cold_hold_hi = key_cold_hold_hi - ~bVar3;
    }
  }
  bVar2 = 0;
  if ((((keys_current & 2) != 0) && (bVar2 = 0, (cfg_systemconfig5 & 4) != 0)) &&
     ((bVar2 = key_hot_hold_hi << 1 | unaff_C & 1, -1 < (char)key_hot_hold_hi &&
      (bVar1 = ~(key_hot_hold_lo == '\0'), bVar2 = -~(key_hot_hold_lo == '\0') - key_hot_hold_hi,
      bVar1 == 0 && -bVar1 <= key_hot_hold_hi)))) {
    bVar3 = key_hot_hold_lo != '\0';
    key_hot_hold_lo = key_hot_hold_lo + -1;
    bVar2 = 0;
    key_hot_hold_hi = key_hot_hold_hi - ~bVar3;
  }
  return bVar2;
}

