#include "memory.h"

void kernel_getMemorySize( MemoryState *ptr_kernel_memory_state){
    unsigned long access_addr = 0x300000;
    do{
        access_addr += 0x100000;
        *(unsigned long*)access_addr = 0xF0F0F0F0;
    }while(*(unsigned long*)access_addr == 0xF0F0F0F0);
    while( *(unsigned long*)access_addr != 0xF0F0F0F0 ){
        access_addr -= 0x100;
        *(unsigned long*)access_addr = 0xF0F0F0F0;       
    }
    do{
        access_addr += 0x1;
        *(unsigned long*)access_addr = 0xF0F0F0F0;
    }while(*(unsigned long*)access_addr == 0xF0F0F0F0);
    ptr_kernel_memory_state->memory_size = access_addr;
}

void kernel_setMemoryListFromToBy( MemoryState* ptr_kernel_memory_state, unsigned long start_addr, unsigned long end_addr, unsigned long ID ){
    unsigned long count_of_sites = (end_addr - start_addr) / 0x1000;
    if( (end_addr - start_addr) % 0x1000 )
        count_of_sites++;
    unsigned long start_site = start_addr / 0x1000;
    for( int i = 0; i < count_of_sites; i++ )
        ptr_kernel_memory_state->sites_map[i] = ID;
}

void kernel_initKernelMemory( MemoryState* ptr_kernel_memory_state){
    kernel_memset((unsigned char*)ptr_kernel_memory_state, 0x00, sizeof(MemoryState));
    ptr_kernel_memory_state->kernel_size = ((unsigned long)end_addr - 0x100000); // get kernel size, by offset from 0x100000 to addr of _end_addr, in file kernel_end.asm
	setGDTR(&generalGDTR); // set new GDT table, by using table from asm file "memory.asm"
    kernel_getMemorySize(ptr_kernel_memory_state); // get memory capacity
    kernel_setMemoryListFromToBy(ptr_kernel_memory_state, 0x0, 0x100000 + ptr_kernel_memory_state->kernel_size + 0x1000, 1); // set taked by kernel
}



void kernel_memset( unsigned char* dest, unsigned char value, unsigned long size ){
    for( int i = 0; i < size; i++ ){
        dest[i] = value;
    }
}