// address 0x00ea3e  size 50 bytes
// callers: 002d86,00d174,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Latch compressor fault code and disable output */

char compressor_set_fault(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  
  puVar1 = (undefined1 *)
           CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  puVar2 = puVar1;
  if (compressor_fault < '\0') {
    puVar2 = puVar1 + 1;
    if (puVar1[-2] != '\0') {
      return puVar1[-2];
    }
  }
  compressor_output_enable = 0;
  compressor_fault = puVar2[-2];
  return -3;
}

