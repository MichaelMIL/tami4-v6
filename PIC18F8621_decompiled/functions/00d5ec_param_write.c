// address 0x00d5ec  size 84 bytes
// callers: 006e5c,00b62c,004264,00215a,

/* Write parameter to EEPROM; updates RAM copies of SYSTEMCONFIG2-5 */

void param_write(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  byte unaff_Z;
  byte unaff_C;
  
  mod_chain_fnd6b4_fnd6f0_d77c();
  if (((unaff_C & 1) == 0) && (mod_chain_fnd78c_mod_get_c18_tmp0_d776(), (unaff_Z & 1) != 0)) {
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    cVar3 = *(char *)((short)in_FSR2 + -2);
    if (cVar3 == 'A') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig5 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ':') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig4 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ',') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig3 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == '+') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      cfg_systemconfig2 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    cVar3 = mod_stack_adjust_d710((char)puVar1);
    bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
    *(undefined1 *)in_FSR1 = puVar1[(short)cVar3 + 1];
    mod_to_eeprom_write_byte_d750();
    uVar4 = c18_tmp0;
    if ((unaff_C & 1) == 0) {
      *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      uVar4 = c18_tmp0;
    }
  }
  else {
    uVar4 = 0x81;
  }
  mod_c18_epilogue_d6c6(uVar4);
  return;
}

