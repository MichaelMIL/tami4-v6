// address 0x00cece

undefined1 FUN_CODE_00cece(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xf7;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xdf;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xfb;
  uVar1 = *(undefined1 *)
           (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  PORTD = uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | 4;
  bVar2 = PORTE;
  PORTE = bVar2 | 0x20;
  return uVar1;
}

