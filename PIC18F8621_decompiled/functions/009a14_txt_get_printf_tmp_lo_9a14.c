// address 0x009a14  size 18 bytes
// callers: 0096c0,

/* Auto: reads printf_tmp_lo,TBLPTRL,printf_tmp_hi,TBLPTRH,text_char,TABLAT; 6 instr */

undefined1 txt_get_printf_tmp_lo_9a14(void)

{
  undefined3 in_TBLPTR;
  
  text_char = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(printf_tmp_hi,printf_tmp_lo));
  return text_char;
}

