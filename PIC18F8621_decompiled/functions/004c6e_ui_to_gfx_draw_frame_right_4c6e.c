// address 0x004c6e  size 34 bytes
// callers: 003b12,

/* Auto: calls gfx_draw_frame_right,gfx_draw_frame_left; 14 instr */

void ui_to_gfx_draw_frame_right_4c6e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  gfx_draw_frame_right();
  *(undefined1 *)in_FSR1 = 0x40;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0x47;
  ui_to_gfx_bitmap_blit_4fa0(1);
  gfx_draw_frame_left();
  *puVar1 = 0x40;
  puVar1[1] = 0x42;
  ui_to_gfx_bitmap_blit_4fa0(1);
  return;
}

