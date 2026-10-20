// address 0x00d452  size 34 bytes
// callers: 00d174,

/* Set cooling demand/delay flag (0x208) */

undefined1 cooling_set_demand(void)

{
  BADSPACEBASE *in_FSR1;
  
  cooling_demand =
       *(undefined1 *)
        (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  return 0xfd;
}

