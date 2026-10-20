// address 0x00da64  size 20 bytes
// callers: 00d998,

/* Stop compressor and heater, restart heating/cooling tasks, stop dispensing */

void loads_stop_and_restart(void)

{
  compressor_stop();
  cooling_stop_task();
  heater_off();
  heating_stop_task();
  dispense_stop_all();
  return;
}

