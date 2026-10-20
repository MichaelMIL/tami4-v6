// address 0x007a96  size 12 bytes
// callers: 006e5c,

/* Auto: reads serial_cmd_hash; 4 instr */

void ser_get_serial_cmd_hash_7a96(void)

{
  local0 = serial_cmd_hash;
  ser_push_args_6c_01_79fe();
  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784(local0);
  return;
}

