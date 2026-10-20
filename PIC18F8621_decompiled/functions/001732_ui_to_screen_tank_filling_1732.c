// address 0x001732  size 54 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: calls screen_tank_filling; 25 instr */

undefined1 ui_to_screen_tank_filling_1732(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_set_menu_timer_lo_26be();
  *(undefined1 *)in_FSR1 = 0x68;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x17;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x72;
  *(undefined1 *)((short)in_FSR1 + 3) = 0x17;
  *(undefined1 *)((short)in_FSR1 + 4) = 0x70;
  *(undefined1 *)((short)in_FSR1 + 5) = 0xac;
  puVar1 = (undefined1 *)((short)in_FSR1 + 7);
  *(undefined1 *)((short)in_FSR1 + 6) = 0;
  c18_tmp0 = screen_tank_filling();
  if ((byte)puVar1 < 7) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return c18_tmp0;
}

