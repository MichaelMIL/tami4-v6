// address 0x00c9ac  size 16 bytes
// callers: 00aa56,

/* Reload extra-hot timeout while extra-hot active */

void heating_restart_extra_hot_timer(void)

{
  if ((heating_flags & 1) != 0) {
    extra_hot_timer = heating_read_param(0x27);
  }
  return;
}

