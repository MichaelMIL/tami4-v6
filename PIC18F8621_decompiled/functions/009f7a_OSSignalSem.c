// address 0x009f7a  size 122 bytes
// callers: 00b482,00b0aa,007628,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Salvo: signal semaphore */

void OSSignalSem(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR0;
  byte *pbVar3;
  
  os_stack_adjust_a28c();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  OSDisableInts();
  os_chain_fna160_fna21c_a286();
  c18_tmp0 = *(byte *)in_FSR0;
  c18_tmp1 = 0;
  if (0xfe < c18_tmp0 == true) {
    os_chain_fna160_fna21c_a286(0);
    cVar1 = *(char *)in_FSR0;
    *(char *)in_FSR0 = cVar1 + '\x01';
    os_frame_load_ptr_arg_a160();
    os_chain_fna27c_fna26a_a2fc();
    if (cVar1 + '\x01' != '\0') {
      if ((OSeligQP_hi | OSeligQP) == 0) {
        OSeligQP = *(byte *)in_FSR2;
        OSeligQP_hi = *(byte *)((short)in_FSR2 + 1);
      }
      else {
        in_FSR0 = (BADSPACEBASE *)CONCAT11(OSeligQTail_hi,OSeligQTail);
        os_copy_ptr_field_a298(OSeligQP_hi | OSeligQP);
      }
      OSeligQTail = *(undefined1 *)in_FSR2;
      OSeligQTail_hi = *(undefined1 *)((short)in_FSR2 + 1);
      os_copy_ptr_field_a272();
      os_const_then_a2dc_a1ee();
      pbVar3 = (byte *)((short)in_FSR0 + 1);
      c18_tmp0 = *(byte *)in_FSR0;
      c18_tmp1 = *(byte *)((short)in_FSR0 + 1);
      os_frame_load_ptr_arg_a160();
      *pbVar3 = c18_tmp0;
      pbVar3[1] = c18_tmp1;
      os_copy_ptr_field_a272();
      pbVar3[4] = 0;
      pbVar3[6] = 0;
    }
    *(undefined1 *)in_FSR2 = 0;
  }
  else {
    *(undefined1 *)in_FSR2 = 4;
  }
  os_to_OSRestoreInts_a2d4();
  *puVar2 = *puVar2;
  os_c18_epilogue_a180();
  return;
}

