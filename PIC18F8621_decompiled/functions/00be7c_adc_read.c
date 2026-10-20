// address 0x00be7c  size 50 bytes
// callers: 00c128,00b616,

/* Select channel, convert, return 10-bit result; flags sensor fault near full scale */

void adc_read(void)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  
  mod_c18_prologue_c116();
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  adc_select_channel();
  *puVar4 = *puVar4;
  bVar1 = ADCON0;
  ADCON0 = bVar1 | GO;
  do {
    bVar1 = ADCON0;
  } while ((bVar1 & GO) != 0);
  cVar2 = ADRESL;
  bVar1 = ADRESH;
  if ((byte)~(cVar2 == '\0') < 4 && 3U - ~(cVar2 == '\0') <= bVar1) {
    fault_code = 0x87;
  }
  else {
    fault_code = 0;
  }
  uVar3 = ADRESL;
  uVar3 = ADRESH;
  mod_c18_epilogue_c138();
  return;
}

