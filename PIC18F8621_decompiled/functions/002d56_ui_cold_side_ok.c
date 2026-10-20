// address 0x002d56  size 48 bytes
// callers: 002d86,

/* Check cold-side faults (cooling, alarm, cold valve, inlet, compressor) */

void ui_cold_side_ok(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  local0 = cooling_fault | uv_alarm_code | cold_valve_fault | inlet_valve_fault;
  if (*(char *)((short)in_FSR2 + -2) != '\0') {
    local0 = local0 | compressor_fault;
  }
  ui_c18_epilogue_4d6e(-1 < (char)local0);
  return;
}

