// address 0x009ff4  size 68 bytes
// callers: 009f5a,

/* Salvo internal: event wait handling */

void os_wait_event_internal(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  BADSPACEBASE *in_FSR0;
  
  os_c18_prologue_a16e();
  if (*(char *)((short)in_FSR2 + -4) == '\0') {
    os_get_os_tmp_tcb_ptr_a1ce(0);
    *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x8f | 0x30;
    os_get_os_tmp_tcb_ptr_a1ce();
    *(byte *)in_FSR0 = *(byte *)in_FSR0 | 0x80;
    os_frame_load_ptr_arg_a160();
    c18_tmp0 = SUB21(in_FSR0,0);
    c18_tmp1 = (char)((ushort)in_FSR0 >> 8);
    *(undefined1 *)in_FSR1 = c18_tmp0;
    *(char *)((short)in_FSR1 + 1) = (char)((ushort)in_FSR0 >> 8);
    os_get_os_tmp_tcb_ptr_a2ba();
  }
  else {
    os_get_os_tmp_tcb_ptr_a1ce(*(char *)((short)in_FSR2 + -4));
    if ((*(byte *)in_FSR0 & 0x80) != 0) {
      os_get_os_tmp_tcb_ptr_a1ce();
      *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x7f;
      uVar1 = 9;
      goto LAB_CODE_00a036;
    }
    os_get_os_tmp_tcb_ptr_a1ce();
    *(byte *)in_FSR0 = *(byte *)in_FSR0 | 0x80;
  }
  uVar1 = 2;
LAB_CODE_00a036:
  os_c18_epilogue_a180(uVar1);
  return;
}

