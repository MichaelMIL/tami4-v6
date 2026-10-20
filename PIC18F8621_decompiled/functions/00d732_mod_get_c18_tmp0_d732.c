// address 0x00d732  size 14 bytes
// callers: 00d776,

/* Auto: reads c18_tmp0,TABLAT; 6 instr */

char mod_get_c18_tmp0_d732(void)

{
  char *in_TBLPTR;
  char in_FramePointer2_0000fffe;
  
  c18_tmp0 = *in_TBLPTR;
  return *in_TBLPTR - in_FramePointer2_0000fffe;
}

