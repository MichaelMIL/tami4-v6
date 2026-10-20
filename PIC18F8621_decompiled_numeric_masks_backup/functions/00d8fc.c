// address 0x00d8fc

undefined1 FUN_CODE_00d8fc(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}

