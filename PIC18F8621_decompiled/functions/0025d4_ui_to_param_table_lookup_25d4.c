// address 0x0025d4  size 20 bytes
// callers: 0001de,000200,

/* Auto: calls param_table_lookup; 7 instr */

void ui_to_param_table_lookup_25d4(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  puVar1 = &FramePointer10x0001;
  uVar2 = param_table_lookup();
  *puVar1 = *puVar1;
  *(undefined1 *)in_FSR2 = uVar2;
  return;
}

