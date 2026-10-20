// address 0x00e870  size 16 bytes
// callers: 00e780,00e83c,00e7c4,

/* Drive RG0 low and update indicator */

void heater_output_off(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  bVar1 = PORTG;
  PORTG = bVar1 & ~RG0;
  outputs_shadow = outputs_shadow & 0x7f;
  puVar2 = &FramePointer10x0001;
  ui_get_ui_heater_indicator_4bce();
  *puVar2 = *puVar2;
  return;
}

