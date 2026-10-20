// address 0x007aa8  size 10 bytes
// callers: 007914,007842,006e5c,

/* Auto: Small wrapper around ser_get_TBLPTRL; 5 instr */

void ser_to_ser_get_TBLPTRL_7aa8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10xfffe;
  ser_get_TBLPTRL_79f4();
  *puVar1 = *puVar1;
  return;
}

