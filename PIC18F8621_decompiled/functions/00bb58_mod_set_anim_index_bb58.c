// address 0x00bb58  size 14 bytes
// callers: 00b908,00b85a,00b898,00b944,

/* Auto: writes anim_index; reads anim_pos; 7 instr */

void mod_set_anim_index_bb58(void)

{
  byte unaff_BSR;
  
  mod_callw_fnba5a_bc20(*(char *)((ushort)unaff_BSR * 0x100 + 0x55) + '\x02');
  anim_index = 0;
  return;
}

