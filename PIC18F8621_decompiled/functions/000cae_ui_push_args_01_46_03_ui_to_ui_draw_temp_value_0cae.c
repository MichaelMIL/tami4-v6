// address 0x000cae  size 30 bytes
// callers: 00290e,000c9e,000ca6,

/* Auto: Push constant arguments [1, 70, 3] then call ui_to_ui_draw_temp_value; 13 instr */

undefined1 ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte unaff_C;
  
  puVar1 = &FramePointer10x0001;
  ui_get_menu_value_lo_2ace();
  bVar2 = (byte)((ushort)(puVar1 + 1) >> 8);
  *puVar1 = 0x46;
  ui_to_ui_draw_temp_value_2356(3);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
  }
  return c18_tmp0;
}

