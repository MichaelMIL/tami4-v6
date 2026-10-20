// address 0x00a116  size 74 bytes
// callers: 00a0b6,

/* Salvo internal: remove task from eligible/delay queues */

void os_remove_from_queues(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  undefined1 uVar6;
  
  os_stack_adjust_a28c();
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)in_FSR2 = 0;
  os_frame_load_ptr_arg_a160();
  cVar5 = os_frame_access_a1f2();
  if (cVar5 == '\x02') {
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    if (*(char *)((short)in_FSR2 + -4) == '\0') goto LAB_CODE_00a158;
    *puVar3 = 0xae;
  }
  else {
    if (((cVar5 != '\x05') && (cVar5 != '\x06')) && (cVar5 != '\x04')) {
      *(undefined1 *)in_FSR2 = 1;
      puVar2 = (undefined1 *)in_FSR2;
      goto LAB_CODE_00a158;
    }
    *puVar3 = 0x98;
    puVar1 = (undefined1 *)in_FSR2;
  }
  puVar4 = puVar3 + 2;
  puVar3[1] = 0;
  os_frame_push_args_a1d8();
  os_insert_delay_queue();
  uVar6 = os_pop3_return_a2e4();
  puVar3 = puVar4 + -1;
  *puVar4 = *puVar4;
  *puVar1 = uVar6;
  puVar2 = puVar1;
LAB_CODE_00a158:
  uVar6 = *puVar2;
  *puVar3 = *puVar3;
  puVar3[-1] = puVar3[-1];
  os_c18_epilogue_a180(uVar6);
  return;
}

