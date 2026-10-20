// address 0x009b64  size 220 bytes
// callers: 009ce6,00a1e6,009e94,

/* Salvo: insert TCB into priority queue */

void OSInsPrioQ(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  BADSPACEBASE *in_FSR1;
  byte *pbVar9;
  char cVar10;
  undefined1 uVar11;
  BADSPACEBASE *in_FSR0;
  
  os_stack_adjust_a28c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  pbVar9 = (byte *)((short)in_FSR1 + 4);
  cVar10 = *(char *)((short)in_FSR1 + 3);
  *(char *)((short)in_FSR1 + 3) = cVar10;
  os_frame_load_ptr_arg_a19c();
  os_chain_fna27c_fna26a_a2fc();
  if (cVar10 == '\0') {
    os_frame_load_ptr_arg_a19c();
    os_frame_access_a200();
    os_frame_load_ptr_arg_a160();
    *(undefined1 *)((short)in_FSR0 + 4) = 0;
    *(undefined1 *)((short)in_FSR0 + 6) = 0;
    c18_tmp0 = 0;
  }
  else {
    *(undefined1 *)((short)in_FSR2 + 3) = 0;
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + 5) = 0;
    os_get_c18_tmp0_a232();
    if (c18_tmp1 == '\0') {
      cVar10 = os_chain_fna272_fna292_a2ec(0);
      puVar2[(short)cVar10 + 1] = *(undefined1 *)in_FSR0;
      while( true ) {
        puVar4 = puVar2 + 1;
        os_frame_load_ptr_arg_a160();
        os_const_then_a2dc_a1ca();
        c18_tmp0 = *(byte *)in_FSR0;
        puVar5 = puVar4 + 1;
        cVar10 = c18_tmp0 - puVar4[5];
        puVar6 = puVar4 + 1;
        if ((c18_tmp0 < (byte)puVar4[5]) ||
           (os_ptr_add_a1ba(cVar10), puVar6 = puVar5, cVar10 == '\0')) break;
        cVar10 = os_chain_fna272_fna292_a2ec();
        puVar2 = puVar5 + 1;
        *pbVar9 = puVar5[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 + *(char *)in_FSR0;
        puVar5[6] = *pbVar9;
      }
      os_frag_a26a();
      puVar7 = puVar6;
      if (cVar10 != '\0') {
        cVar10 = os_chain_fna272_fna292_a2ec();
        *pbVar9 = puVar6[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 - *(char *)in_FSR0;
        puVar7 = puVar6 + 2;
        puVar6[6] = *pbVar9;
      }
      os_frame_load_ptr_arg_a160();
      cVar10 = os_frag_a292();
      puVar8 = puVar7 + 1;
      cVar1 = puVar7[(short)cVar10 + 1];
      cVar10 = *(char *)in_FSR0;
      *(char *)in_FSR0 = cVar10 - cVar1;
      os_frag_a26a();
      puVar6 = puVar8;
      if (cVar10 - cVar1 != '\0') {
        os_frame_access_a2f2();
        cVar10 = os_chain_fna272_fna292_a2ec();
        *(char *)in_FSR0 = *(char *)in_FSR0 - puVar8[(short)cVar10 + 1];
        puVar6 = puVar8 + 1;
      }
    }
    else {
      os_frame_load_ptr_arg_a160();
      *pbVar9 = *(byte *)in_FSR0 & 0xf;
      puVar2[5] = *pbVar9;
      puVar7 = puVar2 + 1;
      do {
        os_copy_ptr_field_a272();
        puVar3 = puVar7 + 1;
        cVar10 = puVar7[5] - (*(byte *)in_FSR0 & 0xf);
        puVar6 = puVar7 + 1;
        if ((byte)puVar7[5] < (*(byte *)in_FSR0 & 0xf)) break;
        os_ptr_add_a1ba(cVar10);
        puVar6 = puVar3;
        puVar7 = puVar3;
      } while (cVar10 != '\0');
    }
    os_ptr_add_a20e();
    if ((char)puVar6 == -2) {
      uVar11 = os_frame_load_ptr_arg_a19c();
    }
    else {
      os_frame_load_ptr_arg_a252();
      uVar11 = 0;
    }
    os_frame_access_a200(uVar11);
    os_frame_load_ptr_arg_a160();
    c18_tmp0 = os_copy_ptr_field_a298();
  }
  if ((byte)pbVar9 < 5) {
    *(undefined1 *)((ushort)pbVar9 & 0xff00) = *(undefined1 *)((ushort)pbVar9 & 0xff00);
  }
  os_c18_epilogue_a180(c18_tmp0);
  return;
}

