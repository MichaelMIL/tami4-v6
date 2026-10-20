// address 0x007774  size 206 bytes
// callers: 006e5c,

/* Print number in hex/decimal on serial console */

void serial_print_number(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar3;
  BADSPACEBASE *in_FSR0;
  bool bVar4;
  bool bVar5;
  
  ser_c18_prologue_78fe();
  ser_stack_adjust_784e(1);
  ser_frame_load_ptr_arg_7a72();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
  c18_tmp0 = serial_hex_digit();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  c18_tmp1 = 0;
  c18_tmp2 = 0;
  c18_tmp3 = 0;
  cVar3 = '\x18';
  do {
    bVar4 = (char)c18_tmp0 < '\0';
    c18_tmp0 = c18_tmp0 << 1;
    bVar5 = (char)c18_tmp1 < '\0';
    c18_tmp1 = c18_tmp1 << 1 | bVar4;
    bVar4 = (char)c18_tmp2 < '\0';
    c18_tmp2 = c18_tmp2 << 1 | bVar5;
    c18_tmp3 = c18_tmp3 << 1 | bVar4;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  ser_get_c18_tmp3_7a88();
  ser_stack_adjust_784e(3);
  c18_tmp4 = ser_chain_fn784e_ser_to_serial_hex__7a90(2);
  c18_tmp5 = 0;
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  cVar3 = '\x10';
  do {
    bVar4 = (char)c18_tmp4 < '\0';
    c18_tmp4 = c18_tmp4 * '\x02';
    bVar5 = (char)c18_tmp5 < '\0';
    c18_tmp5 = c18_tmp5 << 1 | bVar4;
    bVar4 = (char)c18_tmp6 < '\0';
    c18_tmp6 = c18_tmp6 << 1 | bVar5;
    c18_tmp7 = c18_tmp7 << 1 | bVar4;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  bVar4 = CARRY1(c18_tmp0,c18_tmp4);
  c18_tmp0 = c18_tmp0 + c18_tmp4;
  bVar5 = CARRY1(c18_tmp1,bVar4) || CARRY1(c18_tmp5,c18_tmp1 + bVar4);
  c18_tmp1 = c18_tmp1 + c18_tmp5 + bVar4;
  bVar4 = CARRY1(c18_tmp2,bVar5);
  bVar1 = c18_tmp2 + bVar5;
  c18_tmp2 = c18_tmp2 + c18_tmp6 + bVar5;
  c18_tmp3 = c18_tmp3 + c18_tmp7 + (bVar4 || CARRY1(c18_tmp6,bVar1));
  ser_get_c18_tmp3_7a88();
  ser_stack_adjust_784e(5);
  c18_tmp8 = ser_chain_fn784e_ser_to_serial_hex__7a90(4);
  c18_tmp9 = 0;
  c18_tmp10 = 0;
  c18_tmp11 = 0;
  cVar3 = '\b';
  do {
    bVar4 = (char)c18_tmp8 < '\0';
    c18_tmp8 = c18_tmp8 * '\x02';
    bVar5 = (char)c18_tmp9 < '\0';
    c18_tmp9 = c18_tmp9 << 1 | bVar4;
    bVar4 = (char)c18_tmp10 < '\0';
    c18_tmp10 = c18_tmp10 << 1 | bVar5;
    c18_tmp11 = c18_tmp11 << 1 | bVar4;
    cVar3 = cVar3 + -1;
  } while (cVar3 != '\0');
  bVar4 = CARRY1(c18_tmp0,c18_tmp8);
  c18_tmp0 = c18_tmp0 + c18_tmp8;
  bVar5 = CARRY1(c18_tmp1,bVar4) || CARRY1(c18_tmp9,c18_tmp1 + bVar4);
  c18_tmp1 = c18_tmp1 + c18_tmp9 + bVar4;
  bVar4 = CARRY1(c18_tmp2,bVar5);
  bVar1 = c18_tmp2 + bVar5;
  c18_tmp2 = c18_tmp2 + c18_tmp10 + bVar5;
  c18_tmp3 = c18_tmp3 + c18_tmp11 + (bVar4 || CARRY1(c18_tmp10,bVar1));
  ser_get_c18_tmp3_7a88();
  ser_stack_adjust_784e(7);
  c18_tmp12 = ser_chain_fn784e_ser_to_serial_hex__7a90(6);
  c18_tmp13 = 0;
  c18_tmp14 = 0;
  c18_tmp15 = 0;
  math_res0 = c18_tmp0 + c18_tmp12;
  bVar4 = CARRY1(c18_tmp1,CARRY1(c18_tmp0,c18_tmp12));
  math_res1 = c18_tmp1 + CARRY1(c18_tmp0,c18_tmp12);
  math_aarg_lo = c18_tmp2 + bVar4;
  math_aarg_hi = c18_tmp3 + CARRY1(c18_tmp2,bVar4);
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  c18_tmp2 = math_aarg_lo;
  c18_tmp3 = math_aarg_hi;
  ser_c18_epilogue_794a();
  return;
}

