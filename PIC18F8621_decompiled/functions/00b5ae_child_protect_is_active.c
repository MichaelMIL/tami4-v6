// address 0x00b5ae  size 58 bytes
// callers: 006e5c,00011e,004f40,004d80,00b518,

/* Return child-protection (hot water lock) state */

void child_protect_is_active(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined1 uVar5;
  
  mod_c18_prologue_b5e8();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  cVar4 = cfg_application();
  if (cVar4 == '\x03') {
LAB_CODE_00b5c0:
    uVar5 = 0;
  }
  else {
    cVar4 = cfg_application();
    if (cVar4 == '\0') goto LAB_CODE_00b5c0;
    uVar5 = 1;
  }
  *(undefined1 *)in_FSR2 = uVar5;
  if (*(char *)in_FSR2 != '\0') {
    puVar2 = puVar1 + 1;
    *puVar1 = 0x28;
    cVar4 = eeprom_read_param();
    puVar1 = puVar2 + -1;
    puVar3 = puVar2 + -1;
    *puVar2 = *puVar2;
    if (cVar4 != '\0') {
      uVar5 = 1;
      goto LAB_CODE_00b5e0;
    }
  }
  uVar5 = 0;
  puVar3 = puVar1;
LAB_CODE_00b5e0:
  *(undefined1 *)in_FSR2 = uVar5;
  uVar5 = *(undefined1 *)in_FSR2;
  *puVar3 = *puVar3;
  mod_c18_epilogue_b60a(uVar5);
  return;
}

