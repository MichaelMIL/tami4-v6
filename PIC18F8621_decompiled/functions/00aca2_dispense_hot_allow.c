// address 0x00aca2  size 8 bytes
// callers: 005002,00c606,

/* Allow hot dispensing (hot tank up to temperature) */

undefined1 dispense_hot_allow(void)

{
  hot_dispense_allowed = 1;
  return 1;
}

