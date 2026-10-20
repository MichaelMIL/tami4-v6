// address 0x0079c2  size 12 bytes
// callers: 006e5c,

/* Auto: reads serial_cmd_hash; calls param_table_lookup; 4 instr */

void ser_to_param_table_lookup_79c2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  param_table_lookup();
  *puVar1 = *puVar1;
  return;
}

