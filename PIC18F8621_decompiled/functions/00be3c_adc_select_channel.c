// address 0x00be3c  size 64 bytes
// callers: 00be7c,

/* WARNING: Instruction at (CODE,0x00be6e) overlaps instruction at (CODE,0x00be6c)
    */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Select ADC input channel (skips if already selected) and wait acquisition time */

undefined1 adc_select_channel(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  char cVar2;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  if (adc_current_channel != pcVar1[-2]) {
    adc_current_channel = pcVar1[-1];
    ADCON0 = *pcVar1 * '\x04' | 1;
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
  }
  return 0;
}

