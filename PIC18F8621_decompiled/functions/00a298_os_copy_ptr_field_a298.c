// address 0x00a298  size 12 bytes
// callers: 009b64,009f7a,

/* Auto: compiler fragment: RCALL 0x00a1ee ; MOVFF POSTINC2,POSTINC0 ; MOVFF POSTDEC2,POSTDEC0 ;
   RETURN 0x0 */

void os_copy_ptr_field_a298(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  os_const_then_a2dc_a1ee();
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR2;
  *(undefined1 *)((short)in_FSR0 + 1) = *(undefined1 *)((short)in_FSR2 + 1);
  return;
}

