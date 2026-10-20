// address 0x002d3c  size 26 bytes
// callers: 002d86,

/* Return 1 if no hot-side faults (heating, hot valve, inlet, heater) */

undefined1 ui_hot_side_ok(void)

{
  local0 = heating_fault | hot_valve_fault | inlet_valve_fault | heater_fault;
  if ((char)local0 < '\0') {
    return 0;
  }
  return 1;
}

