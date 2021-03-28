cls
nasm -f elf32 source/entry.asm -o objectFiles/entry.o
gcc -m32 -g3 -gdwarf-2 -fvar-tracking -fvar-tracking-assignments -c -O0 -g source/main.c -o objectFiles/main.o -ffreestanding -nostdlib -nostdinc
ld -T link.ld -o objectFiles/kernel objectFiles/entry.o objectFiles/main.o -build-id=none
objcopy -O elf32-i386 objectFiles/kernel kernel.elf
objcopy --only-keep-debug  kernel.elf kernel.sym