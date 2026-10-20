// address 0x004e66  size 18 bytes
// callers: 004550,

/* Auto: writes ui_dispense_state; reads ui_dispense_state; calls gfx_anim_icon_b; 8 instr */

undefined1 ui_to_gfx_anim_icon_b_4e66(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) = *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + '\x01';
  puVar1 = &FramePointer10x0001;
  gfx_anim_icon_b();
  *puVar1 = *puVar1;
  return ui_dispense_state;
}

