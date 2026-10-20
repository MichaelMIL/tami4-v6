// address 0x002904  size 10 bytes
// callers: 0022fa,00247a,

/* Auto: calls stat_counter_save; 4 instr */

void ui_to_stat_counter_save_2904(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  stat_counter_save();
  *puVar1 = *puVar1;
  return;
}

