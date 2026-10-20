// address 0x00acbe  size 8 bytes
// callers: 003b12,

/* Return cold dispensing active */

byte dispense_cold_is_active(void)

{
  return dispense_active & 1;
}

