// address 0x00cece  size 48 bytes
// callers: 00d15c,00ce44,

/* Write a command byte to the LCD (RE3=0) */

undefined1 lcd_write_cmd(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE3;
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

