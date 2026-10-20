// address 0x00e846  size 26 bytes
// callers: 002d86,00c606,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Latch heater fault code and disable heater output */

void heater_set_fault(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  char cVar2;
  
  mod_c18_prologue_e880();
  puVar1 = (undefined1 *)in_FSR2;
  if (heater_fault < '\0') {
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    cVar2 = *(char *)((short)in_FSR2 + -2);
    if (cVar2 != '\0') goto LAB_CODE_00e85e;
  }
  cVar2 = -3;
  heater_fault = puVar1[-2];
  heater_output_enable = 0;
LAB_CODE_00e85e:
  mod_c18_epilogue_e8a2(cVar2);
  return;
}

