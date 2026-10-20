// address 0x00244a  size 10 bytes
// callers: 000e04,002a20,001848,0028aa,

/* Auto: writes ui_wake_pending,text_fill_width; 5 instr */

undefined1 ui_set_ui_wake_pending_244a(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 3) = param_1;
  text_fill_width = 0x80;
  return 0x80;
}

