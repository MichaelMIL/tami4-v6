// address 0x00f956

undefined1 FUN_CODE_00f956(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int3 *piVar5;
  bool bVar6;
  
  piVar5 = (int3 *)&UNK_CODE_00002c;
  DAT_DATA_01b6 = '\0';
  for (DAT_DATA_01b5 = '\t'; (DAT_DATA_01b6 != '\0' || (DAT_DATA_01b5 != '\0'));
      DAT_DATA_01b5 = DAT_DATA_01b5 + -1) {
    DAT_DATA_01b0 = (undefined1)*piVar5;
    DAT_DATA_01b1 = *(undefined *)((int3)piVar5 + 1);
    DAT_DATA_01b2 = *(undefined *)((int3)piVar5 + 2);
    puVar4 = (undefined1 *)*piVar5;
    puVar1 = *(undefined1 **)(piVar5 + 1);
    DAT_DATA_01b3 = (char)piVar5[2];
    DAT_DATA_01b4 = *(char *)((int3)piVar5 + 9);
    piVar5 = piVar5 + 3;
    DAT_DATA_01b7 = SUB31(piVar5,0);
    DAT_DATA_01b8 = (undefined1)((uint3)piVar5 >> 8);
    DAT_DATA_01b9 = (undefined1)((uint3)piVar5 >> 0x10);
    while ((puVar2 = puVar1, DAT_DATA_01b3 != '\0' || (DAT_DATA_01b4 != '\0'))) {
      while( true ) {
        uVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar2 + 1;
        *puVar2 = uVar3;
        bVar6 = DAT_DATA_01b3 != '\0';
        DAT_DATA_01b3 = DAT_DATA_01b3 + -1;
        if (bVar6) break;
        DAT_DATA_01b4 = DAT_DATA_01b4 + -1;
        puVar2 = puVar2 + 1;
      }
    }
    piVar5 = (int3 *)CONCAT12(DAT_DATA_01b9,CONCAT11(DAT_DATA_01b8,DAT_DATA_01b7));
    DAT_DATA_01b6 = DAT_DATA_01b6 - ~(DAT_DATA_01b5 != '\0');
    DAT_DATA_01b3 = 0;
  }
  return 0;
}

