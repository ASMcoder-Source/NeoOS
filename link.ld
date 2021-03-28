OUTPUT_FORMAT(pei-i386)    
ENTRY(entry)

SECTIONS
 {
   . = 0x100000;
   .text : { *(.text) }
   .data : { *(.data) }
   .bss  : { *(.bss)  }
   .test :{objectFiles/kernel_end.o(.test)}
 }