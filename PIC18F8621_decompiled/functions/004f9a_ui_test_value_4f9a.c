// address 0x004f9a  size 6 bytes
// callers: 004550,003b12,

/* Auto: compiler fragment: RCALL 0x004c34 ; SUBLW #0x3 ; RETURN 0x0 */

char ui_test_value_4f9a(void)

{
  char cVar1;
  
  cVar1 = ui_bank1_ui_get_cfg_systemconfig5_4c34();
  return '\x03' - cVar1;
}

