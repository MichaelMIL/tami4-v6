// address 0x00d43a  size 24 bytes
// callers: 006e5c,

/* Cooling system state: 0 off, 1 on, 2 delay */

undefined1 cooling_get_state(void)

{
  char cVar1;
  
  if ((outputs_shadow & 0x40) != 0) {
    return 1;
  }
  if (cooling_demand != '\0') {
    cVar1 = compressor_get_offdelay(cooling_demand);
    if (cVar1 != '\0') {
      return 2;
    }
  }
  return 0;
}

