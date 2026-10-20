// address 0x00c932  size 4 bytes
// callers: 003b12,002d86,

/* Auto: calls hot_temp_read_top; 1 instr */

void mod_to_hot_temp_read_top_c932(void)

{
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  
  puVar1 = &FramePointer10x0001;
  hot_temp_read();
  *puVar1 = *puVar1;
  return;
}

