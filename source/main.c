
// Точка входа в ядро.( Есть ещё одна на ассемблере, она вызывается ранее этой, и вызывает эту, находится в файле entry.asm )
void kmain(){
	char msg[] = "Hello, world!";
	char* videoBuff = (char*)(0xB8000);
	for( int i = 0; i < sizeof(msg); i++ ){
		*videoBuff++ = msg[i];
		*videoBuff++ = 0b00001111;
	}
}