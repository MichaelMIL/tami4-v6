// address 0x00af64  size 4 bytes
// callers: 002d86,

/* Start a measured jug */

void dispense_jug(void)

{
  portion_calc_jug();
  portion_start_cold();
  return;
}

