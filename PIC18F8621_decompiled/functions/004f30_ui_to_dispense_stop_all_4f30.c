// address 0x004f30  size 8 bytes
// callers: 003b12,

/* Auto: calls dispense_stop_all,inlet_valve_close; 2 instr */

void ui_to_dispense_stop_all_4f30(void)

{
  dispense_stop_all();
  inlet_valve_close();
  return;
}

