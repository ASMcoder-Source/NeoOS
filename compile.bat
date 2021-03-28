cls
nasm -f elf32 source/entry.asm -o objectFiles/entry.o
nasm -f elf32 source/kernel_end.asm -o objectFiles/kernel_end.o
nasm -f elf32 source/memory.asm -o objectFiles/memory.asm.o
gcc -fpack-struct -m32 -g3 -gdwarf-2 -fvar-tracking -fvar-tracking-assignments -c -O0 -g source/main.c -o objectFiles/main.o -ffreestanding -nostdlib -nostdinc
gcc -fpack-struct -m32 -g3 -gdwarf-2 -fvar-tracking -fvar-tracking-assignments -c -O0 -g source/memory.c -o objectFiles/memory.o -ffreestanding -nostdlib -nostdinc
ld -T link.ld -o objectFiles/kernel objectFiles/entry.o objectFiles/main.o objectFiles/memory.asm.o objectFiles/memory.o objectFiles/kernel_end.o -build-id=none
objcopy -O elf32-i386 objectFiles/kernel kernel.elf
objcopy --only-keep-debug  kernel.elf kernel.sym

