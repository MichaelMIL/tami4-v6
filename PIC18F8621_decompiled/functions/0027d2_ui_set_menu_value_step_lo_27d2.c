// address 0x0027d2  size 46 bytes
// callers: 000cf8,002178,

/* Auto: writes menu_value_step_lo,menu_value_step_hi; reads
   menu_value_max_hi,menu_value_max_lo,menu_value_step_hi,menu_value_step_lo; 19 instr */

char ui_set_menu_value_step_lo_27d2(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  short sVar2;
  char cVar3;
  
  uVar1 = ui_to_param_read_min_2b7a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9a) = uVar1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9b) = 0;
  menu_value_max_hi = *(char *)((ushort)unaff_BSR * 0x100 + 0x99) * '\n';
  sVar2 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x98) * 10;
  menu_value_max_lo = (undefined1)sVar2;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x99) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x99) + (char)((ushort)sVar2 >> 8);
  menu_value_step_hi = *(char *)((ushort)unaff_BSR * 0x100 + 0x9b) * '\n';
  sVar2 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x9a) * 10;
  menu_value_step_lo = (undefined1)sVar2;
  cVar3 = (char)((ushort)sVar2 >> 8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x9b) = *(char *)((ushort)unaff_BSR * 0x100 + 0x9b) + cVar3;
  *(undefined1 *)in_FSR1 = 0;
  return cVar3;
}

