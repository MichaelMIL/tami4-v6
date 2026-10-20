// address 0x00cfee

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cfee(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  DAT_DATA_01f2 = 0;
  while( true ) {
    if (7 < DAT_DATA_01f2) break;
    pbVar1 = (byte *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
    *pbVar1 = DAT_DATA_01f2;
    FUN_CODE_00d154('\a' - DAT_DATA_01f2);
    FUN_CODE_00d144(0x80);
  }
  return;
}

