// address 0x00a538  size 80 bytes
// callers: 004550,

/* Toggle colon blink and redraw clock */

char clock_blink_update(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  char cVar4;
  
  clock_colon_blink = clock_colon_blink == '\0';
  if (clock_display_on == '\0') {
    return '\0';
  }
  if ((cfg_systemconfig3 & 0x80) == 0) {
    cVar4 = clock_display_blocked;
    if (clock_display_blocked == '\0') {
      cVar4 = mod_get_clock_colon_blink_a880(0);
    }
  }
  else {
    puVar1 = (undefined1 *)in_FSR1;
    for (local0 = 0; cVar4 = local0 - 2, local0 < 2; local0 = local0 + 1) {
      puVar2 = puVar1 + 1;
      *puVar1 = 0x3c;
      mod_frag_a982(3);
      local1 = 0;
      while (local1 < 6) {
        if (clock_colon_blink == '\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = mod_to_mod_get_c18_tmp0_a92e(clock_colon_blink);
        }
        mod_callw_lcd_write_data_a9f6(uVar3);
      }
      puVar1 = puVar2;
    }
  }
  return cVar4;
}

