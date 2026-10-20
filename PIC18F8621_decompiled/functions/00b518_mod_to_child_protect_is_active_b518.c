// address 0x00b518  size 18 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: calls child_protect_is_active; 8 instr */

void mod_to_child_protect_is_active_b518(void)

{
  char cVar1;
  
  cVar1 = child_protect_is_active();
  mod_to_param_write_b62c(cVar1 == '\0');
  child_protect_is_active();
  return;
}

