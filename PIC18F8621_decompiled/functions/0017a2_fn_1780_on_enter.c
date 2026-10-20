// address 0x0017a2  size 34 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void fn_1780_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  cfg_systemconfig4 = cfg_systemconfig4 & 0xfe;
  puVar1 = &FramePointer10x0001;
  ui_to_param_write_215a(0x3a);
  puVar2 = puVar1 + 1;
  *puVar1 = 0x25;
  cfg_systemconfig = eeprom_read_param();
  *puVar2 = *puVar2;
  ui_to_system_wake_2a58();
  return;
}

