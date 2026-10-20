// address 0x004f1c  size 10 bytes
// callers: 003470,002d86,

/* Auto: writes heater_output_enable; reads TRISG; 5 instr */

undefined1 ui_set_heater_output_enable_4f1c(void)

{
  byte bVar1;
  
  bVar1 = TRISG;
  TRISG = bVar1 & ~TRISG0;
  heater_output_enable = 1;
  return 1;
}

