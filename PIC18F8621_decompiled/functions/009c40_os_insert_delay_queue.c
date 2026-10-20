// address 0x009c40  size 166 bytes
// callers: 00a116,

/* Salvo internal: insert task into delay queue */

void os_insert_delay_queue(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  BADSPACEBASE *in_FSR0;
  bool bVar10;
  
  os_c18_prologue_a16e();
  bVar6 = (byte)in_FSR1;
  if (0xf9 < bVar6) {
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),0xff);
    in_FSR1 = (BADSPACEBASE *)(puVar7 + 1);
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),bVar6 + 6);
  os_frame_load_ptr_arg_a19c();
  os_copy_ptr_field_a27c();
  *(undefined1 *)((short)in_FSR2 + 5) = 0;
  puVar1 = (undefined1 *)((short)in_FSR2 + 2);
  *(undefined1 *)((short)in_FSR2 + 7) = 0;
  bVar10 = true;
  os_frame_load_ptr_arg_a160();
  os_const_then_a2dc_a1ee();
  os_frame_access_a2a4();
  do {
    os_frag_a26a();
    if (bVar10) {
      c18_tmp0 = 1;
LAB_CODE_009cd4:
      if ((byte)puVar8 < 6) {
        *(undefined1 *)((ushort)puVar8 & 0xff00) = *(undefined1 *)((ushort)puVar8 & 0xff00);
      }
      os_c18_epilogue_a180(c18_tmp0);
      return;
    }
    puVar5 = puVar1 + 1;
    bVar6 = puVar1[-3] ^ puVar1[1];
    if (bVar6 == 0) {
      puVar1[2] = puVar1[2];
      puVar5 = puVar1 + 2;
      puVar2 = puVar1 + 2;
      bVar6 = puVar1[-1] ^ puVar1[3];
      if (bVar6 == 0) {
        os_ptr_add_a20e();
        if ((char)(puVar1 + 2) != -4) {
          puVar3 = puVar2 + 2;
          in_FSR0 = (BADSPACEBASE *)CONCAT11(puVar2[7],puVar2[5]);
          os_const_then_a2dc_a1ee();
        }
        else {
          os_frame_load_ptr_arg_a19c();
          puVar3 = puVar2;
        }
        *(undefined1 *)in_FSR0 = puVar3[3];
        puVar4 = puVar3 + 2;
        *(undefined1 *)((short)in_FSR0 + 1) = puVar3[5];
        os_get_c18_tmp0_a232();
        if ((char)(puVar1 + 2) == -4) {
          if (c18_tmp1 == '\0') {
            cVar9 = (char)puVar4;
            os_ptr_add_a20e();
            if (cVar9 != -2) {
              os_frame_access_a2f2();
              os_frame_load_ptr_arg_a252();
              cVar9 = os_frag_a292();
              *(char *)in_FSR0 = *(char *)in_FSR0 + puVar4[(short)cVar9 + 1];
            }
          }
        }
        c18_tmp0 = 0;
        goto LAB_CODE_009cd4;
      }
    }
    bVar10 = false;
    os_frag_a302(bVar6);
    puVar5[5] = *(undefined1 *)in_FSR0;
    puVar1 = puVar5 + 2;
    puVar5[7] = *(undefined1 *)((short)in_FSR0 + 1);
    os_copy_ptr_field_a272();
    os_const_then_a2dc_a1ee();
    os_copy_ptr_field_a27c();
  } while( true );
}

