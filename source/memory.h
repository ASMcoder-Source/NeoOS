typedef union{
	struct u16_bytes{
	unsigned char byte1;
	unsigned char byte2;
	} bytes;
	unsigned short number;
} u16;

typedef union{
	struct u32_bytes{
	unsigned char byte1;
	unsigned char byte2;
	unsigned char byte3;
	unsigned char byte4;
	} bytes;
	unsigned long number;
} u32;

typedef struct{
    unsigned short limit0;
	u32 addr;
} GDTR;


typedef struct{
	unsigned char limit_low_low;
	unsigned char limit_low_hi;
	unsigned char address_low_low;
	unsigned char address_low_hi;
	unsigned char address_middle;		
	unsigned char access_rights;		
	unsigned char limit_hi_and_flags;
	unsigned char address_hi;	
} SegmentDescription;

typedef struct{
	unsigned long kernel_size;
    unsigned long memory_size;
    unsigned long sites_map[0xFFFFF];
} MemoryState;


// Global kernel variables, about memory
MemoryState kernel_memory_state;
// Global kernel extern variables, about memory
extern GDTR generalGDTR;
extern MemoryState kernel_memory_state;
//


int end_addr();
void getGDTR(GDTR* ptrGDTR );
void setGDTR(GDTR* ptrGDTR );
void kernel_getMemorySize( MemoryState* ptr_kernel_memory_state);
void kernel_initKernelMemory( MemoryState* ptr_kernel_memory_state);
void kernel_memset( unsigned char* dest, unsigned char value, unsigned long size );
void kernel_setMemoryListFromToBy( MemoryState* ptr_kernel_memory_state, unsigned long start_addr, unsigned long end_addr, unsigned long ID );