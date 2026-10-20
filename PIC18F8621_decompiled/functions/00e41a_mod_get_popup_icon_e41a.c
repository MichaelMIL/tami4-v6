// address 0x00e41a  size 28 bytes
// callers: 00e23a,00e2fc,

/* Auto: reads popup_icon; 11 instr */

void mod_get_popup_icon_e41a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  puVar1[-1] = 4;
  puVar2 = puVar1 + 1;
  *puVar1 = popup_icon;
  mod_set_lcd_delay_counter_cf6e();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  return;
}

