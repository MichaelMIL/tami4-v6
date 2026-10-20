// address 0x00fc08  size 26 bytes
// callers: (none: entry point, task, or reached via pointer)

/* C18 startup: runs _do_cinit then loops calling main() */

void c018_startup(void)

{
  math_flags = math_flags & 0xbf;
  _do_cinit();
  do {
    user_init_hook();
    main();
  } while( true );
}

