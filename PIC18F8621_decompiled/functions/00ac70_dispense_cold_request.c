// address 0x00ac70  size 8 bytes
// callers: 006e5c,00ace2,00331e,00ae44,00122e,

/* Request cold water dispensing */

undefined1 dispense_cold_request(void)

{
  dispense_request = dispense_request & 0xfb | 1;
  return 0;
}

