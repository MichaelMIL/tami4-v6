// address 0x00b016  size 12 bytes
// callers: 00acde,00af64,

/* Start portion in cold mode and request cold water */

undefined1 portion_start_cold(void)

{
  portion_mode = 1;
  dispense_request = dispense_request & 0xfb | 1;
  return 0;
}

