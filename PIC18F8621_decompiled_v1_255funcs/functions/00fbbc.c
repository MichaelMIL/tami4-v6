// address 0x00fbbc

byte FUN_CODE_00fbbc(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  
  DAT_DATA_0005 = 0;
  DAT_DATA_0004 = 0;
  cVar5 = '\x10';
  bVar3 = false;
  do {
    bVar4 = (char)DAT_DATA_0008 < '\0';
    DAT_DATA_0008 = DAT_DATA_0008 << 1 | bVar3;
    bVar3 = (char)DAT_DATA_0009 < '\0';
    DAT_DATA_0009 = DAT_DATA_0009 << 1 | bVar4;
    bVar4 = (char)DAT_DATA_0004 < '\0';
    DAT_DATA_0004 = DAT_DATA_0004 << 1 | bVar3;
    DAT_DATA_0005 = DAT_DATA_0005 << 1 | bVar4;
    bVar1 = ~(DAT_DATA_000d <= DAT_DATA_0004);
    bVar4 = DAT_DATA_000e < DAT_DATA_0005 - bVar1;
    bVar3 = DAT_DATA_0005 < bVar1 || bVar4;
    bVar2 = (DAT_DATA_0005 - DAT_DATA_000e) - ~(DAT_DATA_000d <= DAT_DATA_0004);
    if (DAT_DATA_0005 < bVar1 || bVar4) {
      bVar3 = DAT_DATA_000d <= DAT_DATA_0004;
      DAT_DATA_0004 = DAT_DATA_0004 - DAT_DATA_000d;
      DAT_DATA_0005 = (DAT_DATA_0005 - DAT_DATA_000e) - ~bVar3;
      bVar3 = 0xfe < DAT_DATA_0008;
      DAT_DATA_0008 = DAT_DATA_0008 + 1;
      bVar2 = DAT_DATA_000e;
    }
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  return bVar2;
}

