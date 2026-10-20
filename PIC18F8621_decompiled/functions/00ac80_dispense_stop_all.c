// address 0x00ac80  size 18 bytes
// callers: 006e5c,004f30,0012d0,001644,00ac9a,002d86,00da64,001334,00ae44,001684,00ac92,00323c,

/* Request stop of all dispensing and cancel portion */

undefined1 dispense_stop_all(void)

{
  dispense_request = dispense_request & 0xec | 0xc;
  portion_clear();
  ui_set_ui_alarm_index_4894();
  return 0;
}

