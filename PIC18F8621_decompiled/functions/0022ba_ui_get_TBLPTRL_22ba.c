// address 0x0022ba  size 18 bytes
// callers: 000814,002992,00066c,0017c4,

/* Auto: reads TBLPTRL,TBLPTRH,TABLAT; 8 instr */

undefined1 ui_get_TBLPTRL_22ba(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  
  ui_get_menu_table_ptr_lo_2b3c();
  uVar1 = *(undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                    CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfe < (byte)in_TBLPTR),
                             (byte)in_TBLPTR + 1));
  *(undefined1 *)in_FSR1 = uVar1;
  return uVar1;
}

