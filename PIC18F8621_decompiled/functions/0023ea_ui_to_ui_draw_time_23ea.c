// address 0x0023ea  size 12 bytes
// callers: 000814,0007c0,0007cc,0007a0,0007a8,0007b8,000788,000794,000806,

/* Auto: calls ui_draw_time; 5 instr */

void ui_to_ui_draw_time_23ea(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_draw_time();
  *puVar1 = *puVar1;
  return;
}

