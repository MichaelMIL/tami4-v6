// address 0x002690  size 12 bytes
// callers: 001f12,001f6a,001e3e,

/* Auto: writes progress_bar_value; reads progress_bar_x,progress_bar_y; 6 instr */

void ui_set_progress_bar_value_2690(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x4f) = param_1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x50) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x4e) + *(char *)((ushort)unaff_BSR * 0x100 + 0x4c) +
       -1;
  return;
}

