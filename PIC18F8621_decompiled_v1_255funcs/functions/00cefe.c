// address 0x00cefe

undefined1 FUN_CODE_00cefe(void)

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

