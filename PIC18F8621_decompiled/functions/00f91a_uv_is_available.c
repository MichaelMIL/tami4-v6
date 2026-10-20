// address 0x00f91a  size 34 bytes
// callers: 00da82,00aa56,

/* UV lamp fitted, not failed and fault input not tripped */

undefined1 uv_is_available(void)

{
  byte bVar1;
  
  if (((cfg_systemconfig4 & 0x20) != 0) && (bVar1 = PORTJ, (bVar1 & RJ0) != 0)) {
    return 0;
  }
  if (((uv_status & 2) == 0) && ((cfg_systemconfig & 8) != 0)) {
    return 1;
  }
  return 0;
}

