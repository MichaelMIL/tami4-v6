// address 0x00b02c  size 20 bytes
// callers: 00af08,00afc2,

/* Auto: reads local4,local3; 8 instr */

char mod_get_local4_b02c(void)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)local3;
  local3 = (char)(uVar1 * 10);
  cVar2 = (char)(uVar1 * 10 >> 8);
  local4 = local4 * '\n' + cVar2;
  return cVar2;
}

