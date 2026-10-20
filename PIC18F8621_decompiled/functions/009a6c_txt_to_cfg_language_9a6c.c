// address 0x009a6c  size 20 bytes
// callers: 00999c,009ac8,

/* Auto: calls cfg_language,word_lookup_a; 8 instr */

void txt_to_cfg_language_9a6c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = cfg_language();
  *(undefined1 *)in_FSR1 = uVar2;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  word_lookup_a();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

