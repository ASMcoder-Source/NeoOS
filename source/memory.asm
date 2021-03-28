bits 32

section .text
global _generalGDTR

global _getGDTR
_getGDTR:
mov eax,[esp+4]
sgdt [eax]
ret

global _setGDTR
_setGDTR:
mov eax, [esp+4]
lgdt [_generalGDTR]
JMP 0x08:.reload_CS ; 0x08 points at the new code selector
.reload_CS:
MOV   AX, 0x10 ; 0x10 points at the new data selector
MOV   DS, AX
MOV   ES, AX
MOV   FS, AX
MOV   GS, AX
MOV   SS, AX
ret

section .data
align 8   
;;------------------ Descriptor table. ----------------------;-
GDT:                                                         ;-
NULL_descr  db 8 dup(0)                                      ;-
CODE_descr  db 0FFh,0FFh,00h,00h,00h,10011010b,11001111b,00h ;-
DATA_descr  db 0FFh,0FFh,00h,00h,00h,10010010b,11001111b,00h ;-
VIDEO_descr db 0FFh,0FFh,00h,80h,0Bh,10010010b,01000000b,00h ;-
;;-----------------------------------------------------------;-     
GDT_size equ $-GDT                                           

_generalGDTR:
dw GDT_size-1
dd GDT 