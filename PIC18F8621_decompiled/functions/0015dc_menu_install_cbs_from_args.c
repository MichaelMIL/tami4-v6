// address 0x0015dc  size 104 bytes
// callers: 0015dc,

/* Call callback, then install enter/timeout/aux callbacks from arguments */

undefined1 menu_install_cbs_from_args(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  menu_install_cbs_from_args(c18_tmp0);
  menu_cb_aux = *(undefined1 *)((short)in_FSR2 + -6);
  menu_cb_aux_hi = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_timeout = 0x7a;
  menu_cb_timeout_hi = 0x12;
  menu_cb_enter = *(undefined1 *)((short)in_FSR2 + -6);
  menu_cb_enter_hi = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_back = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_back_hi = *(undefined1 *)((short)in_FSR2 + -2);
  menu_cb_up = *(undefined1 *)((short)in_FSR2 + -2);
  menu_cb_up_hi = *(undefined1 *)in_FSR2;
  menu_cb_down = *(undefined1 *)in_FSR2;
  menu_cb_down_hi = *(undefined1 *)((short)in_FSR2 + 2);
  menu_cb_key = *(undefined1 *)((short)in_FSR2 + 2);
  menu_cb_key_hi = *(undefined1 *)((short)in_FSR2 + 4);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return 0xf8;
}

