// address 0x00af3e  size 22 bytes
// callers: 002d86,00323c,

/* Start a measured hot cup (0x80 if not possible) */

undefined1 dispense_hot_cup(void)

{
  portion_calc_hot_cup();
  if (portion_hot_hi == '\0' && portion_hot_lo == '\0') {
    return 0x80;
  }
  portion_mode = 3;
  dispense_request = dispense_request & 0xf7 | 2;
  return 0;
}

