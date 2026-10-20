// address 0x00d3b0

undefined1 FUN_CODE_00d3b0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00d49a();
  *puVar1 = 0x74;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xd1;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}

