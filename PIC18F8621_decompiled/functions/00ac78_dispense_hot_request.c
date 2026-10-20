// address 0x00ac78  size 8 bytes
// callers: 004ebc,006e5c,00ae44,

/* Request hot water dispensing */

undefined1 dispense_hot_request(void)

{
  dispense_request = dispense_request & 0xf7 | 2;
  return 0;
}

