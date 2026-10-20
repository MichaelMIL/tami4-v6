// address 0x00e8ae  size 56 bytes
// callers: 00b256,

/* Stop compressor; set power-up restart delay (TCOMPOFFDELAY) unless factory jumper */

undefined1 compressor_init(void)

{
  byte unaff_BSR;
  char cVar1;
  byte bVar2;
  bool bVar3;
  
  compressor_stop();
  cVar1 = is_factory_jumper();
  if (cVar1 == '\0') {
    compressor_read_param(9);
    bVar2 = compressor_set_offdelay();
    if ((*(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) & 0x80) == 0) {
      bVar3 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) !=
              ~(bVar2 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0xe2));
    }
    else {
      bVar3 = false;
    }
    if (bVar3) goto LAB_CODE_00e8da;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe2) = 0xc;
  }
  else {
    unaff_BSR = 1;
    compressor_offdelay_lo = 0;
  }
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe3) = 0;
LAB_CODE_00e8da:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe4) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe5) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe6) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe1) = 0;
  return 0;
}

