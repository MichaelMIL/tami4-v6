// address 0x000000  size 4 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: calls c018_startup; 1 instr */

void ui_to_c018_startup_0000(void)

{
  math_flags = math_flags & 0xbf;
  _do_cinit();
  do {
    user_init_hook();
    main();
  } while( true );
}

