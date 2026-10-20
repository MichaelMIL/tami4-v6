// address 0x000c32  size 48 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_install_boiling_temp(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_C;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  puVar1 = &FramePointer10x0001;
  ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992();
  menu_value_max_lo = 100;
  menu_value_max_hi = 0;
  ui_param_tboil_28e2(0x58);
  bVar3 = (byte)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    bVar3 = (byte)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  ui_to_ui_get_menu_value_step_lo_290e();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar3 << 8) = *(undefined1 *)((ushort)bVar3 << 8);
  }
  ui_to_menu_set_cbs_down_hi_2826();
  return;
}

