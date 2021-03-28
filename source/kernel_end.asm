bits 32         ;nasm directive - 32 bit
global _end_addr

section .test
_end_addr: 
mov eax, 10;
ret
