#include "memory.h"

// Just for debug printing
char tempBuff[25];
unsigned int addr = 0; 

// Just for debug printing
void empy_tempBuff(){
	for( int i = 0; i < 25; i++ )
		tempBuff[i] = 0;
}

// Just for debug printing
void putChar(char symblol){
	addr = addr % 2048;
    char* videoBuff = (char*)(0xB8000);
    videoBuff[addr+0] = symblol;
    videoBuff[addr+1] = 0b00001111;
    addr += 2;
}

// Just for debug printing
void putDecUI( unsigned int number ){
	if( number == 0 ){
		putChar('0');
		return;
	}
	empy_tempBuff();
	int i = 24;
	while( number != 0 ){
	tempBuff[i--] = (char)((number%10)+0x30);
	number = number - ( number%10);
	number /= 10;
	}
	for( int i1 = i; i1 < 25; i1++ )
		if( tempBuff[i1] != 0 )
			putChar(tempBuff[i1]);
	return;
}

// Just for debug printing
void putLine(char* ptrLine){ 
	while( *ptrLine != 0 ){
		putChar(*ptrLine);
		ptrLine++;
	}
}

void kmain(){
	kernel_initKernelMemory(&kernel_memory_state);
	putLine("Hello, World! ");
	putLine(" | Memory size: "); putDecUI(kernel_memory_state.memory_size / 1024); putLine(" Kb");
	putLine(" | Kernel size: "); putDecUI(kernel_memory_state.kernel_size / 1024); putLine(" Kb");
}