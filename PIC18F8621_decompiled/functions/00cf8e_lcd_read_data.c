// address 0x00cf8e  size 56 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Read a display data byte from the LCD */

undefined1 lcd_read_data(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = (TRISD0 | TRISD1 | TRISD2 | TRISD3 | TRISD4 | TRISD5 | TRISD6 | TRISD7);
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE3;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE5;
  bVar2 = PORTE;
  PORTE = bVar2 & ~RE1;
  uVar1 = PORTD;
  *(undefined1 *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) =
       uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE1;
  bVar2 = PORTE;
  PORTE = bVar2 | RE5;
  return uVar1;
}

