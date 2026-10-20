// address 0x00dc44  size 82 bytes
// callers: 00d174,

/* Force UV cycle if cold water above TABNORMALCOLDHIGH */

undefined1 uv_check_cold_abnormal(void)

{
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  puVar2 = &FramePointer10x0002;
  puVar1 = (undefined1 *)
           CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  uv_cold_abnormal_limit = uv_read_param(0x4a);
  c18_tmp0 = puVar1[-2];
  if (uv_cold_abnormal_limit < 0xfe || c18_tmp0 < uv_cold_abnormal_limit + 2) {
    c18_tmp1 = puVar1[-2];
    if (uv_cold_abnormal_limit < 0xfe || c18_tmp1 < uv_cold_abnormal_limit + 2) {
      uVar3 = 0;
      goto LAB_CODE_00dc8a;
    }
  }
  uv_flags = uv_flags | 8;
  if (-1 < uv_alarm_code) {
    uv_alarm_code = -0x70;
  }
  uVar3 = 1;
LAB_CODE_00dc8a:
  *puVar2 = *puVar2;
  return uVar3;
}

