// address 0x00c982  size 8 bytes
// callers: 003584,003b12,002d86,

/* Return extra-hot flag */

byte heating_is_extra_hot(void)

{
  return heating_flags & 1;
}

