// address 0x00215a  size 12 bytes
// callers: 00205a,0017a2,0001de,002964,002a28,0004a0,0014a6,00279e,00285a,000200,000da0,001410,000b18,001458,

/* Auto: calls param_write; 5 instr */

void ui_to_param_write_215a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  param_write();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

