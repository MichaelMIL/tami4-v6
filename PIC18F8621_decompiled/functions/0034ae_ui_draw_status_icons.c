// address 0x0034ae  size 214 bytes
// callers: 003b12,

/* Draw heater/compressor indicators and smoothed tank temperatures */

undefined1 ui_draw_status_icons(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  if (((ui_screen != '\x04') && (uVar4 = 0, ui_screen != '\x05')) &&
     (uVar4 = 0, ui_screen != '\x14')) {
    if (ui_screen + -0x1f == '\0') {
      return 0;
    }
    puVar1 = &FramePointer10x0001;
    mod_get_TBLPTRH_f334(ui_screen + -0x1f);
    *puVar1 = *puVar1;
    puVar1[-1] = ui_heater_indicator;
    mod_get_TBLPTRH_f364();
    puVar2 = puVar1 + -1;
    *puVar1 = *puVar1;
    ui_temp_scratch = hot_temp_read_top();
    if (ui_temp_scratch < ui_disp_hot_top) {
      ui_temp_scratch = ui_disp_hot_top;
    }
    if (0xfd < ui_disp_hot_bottom && ui_disp_hot_bottom + 2 <= ui_temp_scratch) {
      ui_temp_scratch = ui_disp_hot_bottom;
    }
    c18_tmp10 = ui_layout_0;
    c18_tmp11 = 0;
    c18_tmp8 = ui_disp_hot_bottom - ui_disp_hot_top;
    c18_tmp9 = 0;
    c18_tmp4 = ui_disp_hot_bottom - ui_temp_scratch;
    c18_tmp5 = 0;
    ui_scale_mul(ui_layout_2);
    puVar3 = puVar2 + 1;
    *puVar2 = 0x42;
    ui_to_gfx_bitmap_blit_4fa0(1);
    ui_temp_scratch = cold_temp_read_ch5();
    if (ui_temp_scratch < ui_disp_cold_a) {
      ui_temp_scratch = ui_disp_cold_a;
    }
    if (0xfd < ui_disp_cold_b && ui_disp_cold_b + 2 <= ui_temp_scratch) {
      ui_temp_scratch = ui_disp_cold_b;
    }
    c18_tmp10 = ui_layout_5;
    c18_tmp11 = 0;
    c18_tmp8 = ui_disp_cold_b - ui_disp_cold_a;
    c18_tmp9 = 0;
    c18_tmp4 = ui_temp_scratch - ui_disp_cold_a;
    c18_tmp5 = 0;
    ui_scale_mul(ui_layout_7);
    *puVar3 = 0x47;
    uVar4 = ui_to_gfx_bitmap_blit_4fa0(1);
  }
  return uVar4;
}

