// address 0x0021e4  size 16 bytes
// callers: 0001de,000200,

/* Auto: calls param_table_lookup; 6 instr */

void ui_to_param_table_lookup_21e4(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  puVar1 = &FramePointer10x0001;
  uVar2 = param_table_lookup();
  *puVar1 = *puVar1;
  *(undefined1 *)in_FSR2 = uVar2;
  puVar1[-1] = *(undefined1 *)in_FSR2;
  return;
}

