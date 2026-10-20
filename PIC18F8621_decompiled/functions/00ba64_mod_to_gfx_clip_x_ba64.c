// address 0x00ba64  size 20 bytes
// callers: 00bb4e,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes anim_pos; reads anim_pos; calls gfx_clip_x; 9 instr */

void mod_to_gfx_clip_x_ba64(void)

{
  gfx_clip_x();
  mod_pop4_return_bc04();
  anim_pos = anim_pos + '\x01';
  return;
}

