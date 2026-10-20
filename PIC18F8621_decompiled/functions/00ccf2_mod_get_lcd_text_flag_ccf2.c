// address 0x00ccf2  size 30 bytes
// callers: 00cab8,00ca68,00ca7c,00cad4,00cb0c,

/* Auto: reads lcd_text_flag,TBLPTRL,TBLPTRH,TABLAT; 13 instr */

undefined1 mod_get_lcd_text_flag_ccf2(void)

{
  byte bVar1;
  byte unaff_BSR;
  undefined3 in_TBLPTR;
  byte in_FramePointer2_0000fffd;
  char in_FramePointer2_0000ffff;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe8);
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11(in_FramePointer2_0000ffff + CARRY1(in_FramePointer2_0000fffd,bVar1),
                            in_FramePointer2_0000fffd + bVar1));
}

