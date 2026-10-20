// address 0x00cefe  size 48 bytes
// callers: 00bb06,00f3c4,00a9f6,00cc2c,00cf6e,00e23a,0028be,009a3e,00cf2e,00bbee,00d08c,00e41a,00293a,00cc5a,00e44e,00baa6,00ce1e,0093ee,00cdac,

/* Write a display data byte to the LCD (RE3=1) */

undefined1 lcd_write_data(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 | RE3;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE5;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE2;
  uVar1 = *(undefined1 *)
           (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  PORTD = uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE2;
  bVar2 = PORTE;
  PORTE = bVar2 | RE5;
  return uVar1;
}

