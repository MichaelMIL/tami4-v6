// address 0x00c98a  size 6 bytes
// callers: 006e5c,00c606,

/* Clear extra-hot flag */

void heating_cancel_extra_hot(void)

{
  heating_flags = heating_flags & 0xfe;
  return;
}

