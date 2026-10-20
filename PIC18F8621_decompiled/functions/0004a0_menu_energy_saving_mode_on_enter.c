// address 0x0004a0  size 44 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 in_PRODL;
  byte unaff_Z;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) == 0) {
    cfg_systemconfig2 = cfg_systemconfig2 | 1;
    ui_get_menu_value_hi_23d8(3);
    pbVar1 = (byte *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = in_PRODL;
    ui_to_param_write_215a(0x23);
  }
  else {
    cfg_systemconfig2 = cfg_systemconfig2 & 0xfe;
    pbVar1 = (byte *)in_FSR1;
  }
  *pbVar1 = cfg_systemconfig2;
  ui_to_menu_default_back_279e(0x2b);
  return;
}

