// address 0x007860  size 16 bytes
// callers: 006dfc,006e5c,

/* Parse numeric index argument (atol from rx buffer byte 3) into serial_cmd_hash */

undefined1 serial_parse_index_arg(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  
  uVar1 = ser_to_atol_7a3a(1);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x6b) = uVar1;
  return *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x6b);
}

