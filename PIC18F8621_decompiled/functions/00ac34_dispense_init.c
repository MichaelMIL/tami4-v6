// address 0x00ac34  size 18 bytes
// callers: 00b256,

/* Initialise dispensing state */

undefined1 dispense_init(void)

{
  dispense_active = 0;
  dispense_request = 0;
  hot_dispense_allowed = 1;
  hot_dispense_timer = 0;
  dispense_task_state = 0;
  portion_clear();
  return 0;
}

