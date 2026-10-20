// address 0x0025e8  size 10 bytes
// callers: 0014d6,00037c,

/* Auto: reads c18_tmp0,TABLAT; 4 instr */

char ui_get_c18_tmp0_25e8(void)

{
  char cVar1;
  char in_TABLAT;
  
  c18_tmp0 = in_TABLAT;
  cVar1 = ui_get_cfg_systemconfig2_2b2e();
  return c18_tmp0 - cVar1;
}

