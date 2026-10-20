// address 0x00f956  size 158 bytes
// callers: 00fc08,

/* C18 runtime: copy initialised data (table at ROM 0x2a) into RAM */

char _do_cinit(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  int3 *piVar6;
  bool bVar7;
  
  piVar6 = (int3 *)0x2c;
  DAT_DATA_01b6 = cCODE00002b;
  cVar1 = cCODE00002b;
  for (DAT_DATA_01b5 = c18_init_table; (DAT_DATA_01b6 != '\0' || (DAT_DATA_01b5 != '\0'));
      DAT_DATA_01b5 = DAT_DATA_01b5 + -1) {
    cinit_tmp = (undefined1)*piVar6;
    DAT_DATA_01b1 = *(undefined1 *)((int3)piVar6 + 1);
    DAT_DATA_01b2 = *(undefined1 *)((int3)piVar6 + 2);
    puVar5 = (undefined1 *)*piVar6;
    puVar2 = *(undefined1 **)(piVar6 + 1);
    DAT_DATA_01b3 = (char)piVar6[2];
    DAT_DATA_01b4 = *(char *)((int3)piVar6 + 9);
    piVar6 = piVar6 + 3;
    DAT_DATA_01b7 = SUB31(piVar6,0);
    DAT_DATA_01b8 = (undefined1)((uint3)piVar6 >> 8);
    DAT_DATA_01b9 = (undefined1)((uint3)piVar6 >> 0x10);
    while ((puVar3 = puVar2, DAT_DATA_01b3 != '\0' || (DAT_DATA_01b4 != '\0'))) {
      while( true ) {
        uVar4 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar2 = puVar3 + 1;
        *puVar3 = uVar4;
        bVar7 = DAT_DATA_01b3 != '\0';
        DAT_DATA_01b3 = DAT_DATA_01b3 + -1;
        if (bVar7) break;
        DAT_DATA_01b4 = DAT_DATA_01b4 + -1;
        puVar3 = puVar3 + 1;
      }
    }
    piVar6 = (int3 *)CONCAT12(DAT_DATA_01b9,CONCAT11(DAT_DATA_01b8,DAT_DATA_01b7));
    cVar1 = '\0';
    DAT_DATA_01b6 = DAT_DATA_01b6 - ~(DAT_DATA_01b5 != '\0');
    DAT_DATA_01b3 = 0;
  }
  return cVar1;
}

