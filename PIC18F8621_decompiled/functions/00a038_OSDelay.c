// address 0x00a038  size 98 bytes
// callers: 00b040,002c22,00c606,00d174,00d794,00da82,006e5c,

/* Salvo: delay current task for N ticks */

void OSDelay(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  char *pcVar3;
  char *pcVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  char cVar6;
  BADSPACEBASE *in_FSR0;
  
  mod_to_OSDisableInts_a30c();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    os_get_os_tmp_tcb_ptr_a1ce(0);
    os_frag_a260();
  }
  else {
    os_get_os_tmp_tcb_ptr_a1ce(*(char *)((short)in_FSR2 + -2));
    *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x8f | 0x20;
    if (puVar2[-3] == '\0') {
      pcVar4 = puVar2 + 2;
      cVar6 = puVar2[-1];
      puVar2[2] = cVar6;
    }
    else {
      pcVar3 = puVar2 + 2;
      puVar2[2] = puVar2[-1];
      os_get_os_tmp_tcb_ptr_a1ce();
      os_const_then_a2dc_a1ca();
      *pcVar3 = *pcVar3 + *(char *)in_FSR0;
      *pcVar3 = *pcVar3 - OStimerTicks;
      pcVar4 = pcVar3 + 1;
      bVar1 = pcVar3[-2];
      cVar6 = (bVar1 - pcVar3[1]) + '\x02';
      if (0xfd < bVar1 && bVar1 + 2 <= (byte)pcVar3[1]) {
        pcVar4 = pcVar3 + 2;
        cVar6 = pcVar3[-1];
        pcVar3[2] = pcVar3[2] + cVar6;
      }
    }
    os_get_os_tmp_tcb_ptr_a1ce(cVar6);
    os_const_then_a2dc_a1ca();
    *(char *)in_FSR0 = *pcVar4;
    puVar5 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0xae;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
    *puVar5 = 0;
    os_get_os_tmp_tcb_ptr_a2ba();
  }
  OSRestoreInts();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  os_c18_epilogue_a180();
  return;
}

