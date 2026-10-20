// address 0x00f364  size 48 bytes
// callers: 0034ae,

/* Auto: reads TBLPTRH,TBLPTRL,TABLAT; 24 instr */

void mod_get_TBLPTRH_f364(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  byte *pbVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar4;
  undefined1 *in_TBLPTR;
  
  mod_c18_prologue_f394();
  mod_stack_adjust_f3b4(6);
  pbVar2 = (byte *)in_FSR2;
  while( true ) {
    bVar1 = *pbVar2;
    if (6 < bVar1) break;
    pbVar3 = pbVar2 + 1;
    if (pbVar2[-2] == 0) {
      uVar4 = 0;
    }
    else {
      in_TBLPTR = (undefined1 *)
                  CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                           CONCAT11((0x84 < pbVar2[1]) + -0x6e,pbVar2[1] + 0x7b));
      uVar4 = *in_TBLPTR;
    }
    mod_callw_lcd_write_data_f3c4(uVar4);
    *pbVar3 = *pbVar3 + '\x01';
    pbVar2 = pbVar3;
  }
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  mod_c18_epilogue_f3a8(bVar1 - 7);
  return;
}

