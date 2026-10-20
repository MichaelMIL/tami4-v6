// address 0x002a58  size 12 bytes
// callers: 0017a2,0013ce,

/* Auto: calls system_wake; 3 instr */

void ui_to_system_wake_2a58(void)

{
  ui_to_lcd_clear_21fc();
  system_wake();
  ui_to_heating_start_task_3470();
  return;
}

