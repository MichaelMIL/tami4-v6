// address 0x003470  size 38 bytes
// callers: 002a58,00a588,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes ui_screen; reads ui_screen; calls heating_start_task,cooling_start_task; 15 instr */

void ui_to_heating_start_task_3470(void)

{
  char cVar1;
  
  if (ui_screen != '\x02') {
    cVar1 = ui_screen + -3;
    if (cVar1 != '\0') {
      ui_screen = '\0';
      ui_return_screen = 0;
      goto LAB_CODE_00348a;
    }
  }
  cVar1 = '\x19';
  ui_screen = '\x19';
LAB_CODE_00348a:
  ui_set_heater_output_enable_4f1c(cVar1);
  heating_start_task();
  cooling_start_task();
  return;
}

