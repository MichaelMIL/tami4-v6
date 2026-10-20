// address 0x00acde  size 4 bytes
// callers: 002d86,

/* Start a measured cold cup */

void dispense_cold_cup(void)

{
  portion_calc_cold_cup();
  portion_start_cold();
  return;
}

