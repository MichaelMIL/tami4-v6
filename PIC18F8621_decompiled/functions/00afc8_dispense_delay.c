// address 0x00afc8  size 10 bytes
// callers: 00aa56,

/* Set dispense task state and delay */

void dispense_delay(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x7c) = param_1;
  dispense_os_delay(local0);
  return;
}

