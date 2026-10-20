// address 0x00acb6  size 8 bytes
// callers: 003b12,

/* Return hot dispensing active */

byte dispense_hot_is_active(void)

{
  return dispense_active & 2;
}

