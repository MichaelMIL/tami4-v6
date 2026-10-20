// address 0x000200  size 250 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Restore factory settings: rewrite SYSTEMCONFIG2 language bits and user parameters */

void restore_factory_apply(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  byte in_PRODL;
  
  c18_tmp0 = (*(byte *)((ushort)unaff_BSR * 0x100 + 0x58) & 0x38) >> 3;
  pbVar4 = (byte *)in_FSR2;
  bVar3 = ui_frag_25a6(c18_tmp0);
  *pbVar4 = in_PRODL | *pbVar4 & bVar3;
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR2;
  ui_to_param_write_215a(0x2b);
  ui_to_param_table_lookup_21e4(0x31);
  ui_to_param_write_215a(0x31);
  ui_to_param_table_lookup_21e4(0x37);
  ui_to_param_write_215a(0x37);
  ui_to_param_table_lookup_21e4(0x36);
  ui_to_param_write_215a(0x36);
  ui_to_param_table_lookup_21e4(0x39);
  ui_to_param_write_215a(0x39);
  ui_to_param_table_lookup_21e4(0x38);
  ui_to_param_write_215a(0x38);
  ui_to_param_table_lookup_21e4(0x2c);
  ui_to_param_write_215a(0x2c);
  ui_to_param_table_lookup_25d4(0x25);
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  if ((*pbVar4 & 0x80) != 0) {
    cfg_systemconfig = cfg_systemconfig | 0x80;
  }
  pbVar2 = pbVar1 + 1;
  *pbVar1 = cfg_systemconfig;
  ui_to_param_write_215a(0x25);
  ui_to_param_table_lookup_21e4(3);
  ui_to_param_write_215a(3);
  ui_to_param_table_lookup_21e4(0x32);
  ui_to_param_write_215a(0x32);
  ui_to_param_table_lookup_21e4(0x33);
  ui_to_param_write_215a(0x33);
  ui_to_param_table_lookup_21e4(0x3e);
  ui_to_param_write_215a(0x3e);
  ui_to_param_table_lookup_21e4(0x34);
  ui_to_param_write_215a(0x34);
  ui_to_param_table_lookup_21e4(0x35);
  ui_to_param_write_215a(0x35);
  ui_to_param_table_lookup_21e4(0x42);
  ui_to_param_write_215a(0x42);
  ui_to_param_table_lookup_21e4(0x28);
  ui_to_param_write_215a(0x28);
  menu_default_back();
  *pbVar2 = *pbVar2;
  ui_c18_epilogue_21d8();
  return;
}

