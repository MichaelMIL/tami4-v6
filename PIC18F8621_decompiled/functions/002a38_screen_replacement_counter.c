// address 0x002a38  size 16 bytes
// callers: 000db8,00246a,

/* Replacement counter screen ("TIME TO NEXT REPLACEMENT") */

undefined1 screen_replacement_counter(void)

{
  menu_replacement_on_up_b();
  menu_cb_enter = 0x42;
  menu_cb_enter_hi = 0xf;
  return 0xf;
}

