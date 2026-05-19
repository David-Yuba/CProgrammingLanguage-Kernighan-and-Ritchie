#include<stdio.h>
#include<string.h>
#include<inttypes.h>

#define BIT_1 1
#define BIT_2 2
#define BIT_3 4
#define BIT_4 8
#define BIT_5 16
#define BIT_6 32
#define BIT_7 64
#define BIT_8 128

void printBinaryMemory(void *memory, int size){
	uint8_t mem[size];
	memcpy(mem, memory, size);
	// printf("--------------------------------- Hexadecimal ---------------------------------\n");
	// for (int i=0 ; i<size ; i++){
	// 	if(i != size - 1) printf("%x-", mem[i]);
	// 	else printf("%x\n", mem[i]);
	//
	// }
	// printf("--------------------------------- Binary ---------------------------------\n");
	for (int i=size-1 ; i>=0 ; i--){
		if((mem[i] & BIT_8) == BIT_8) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_7) == BIT_7) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_6) == BIT_6) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_5) == BIT_5) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_4) == BIT_4) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_3) == BIT_3) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_2) == BIT_2) putc('1', stdout);
		else putc('0', stdout);
		if((mem[i] & BIT_1) == BIT_1) putc('1', stdout);
		else putc('0', stdout);
		if(i != 0) putc('-', stdout);
		else putc('\n', stdout);
	}
}

// int main(){
// 	int n = 5000;
// 	printBinaryMemory(&n, sizeof(int));
// 	//n = n & 0177;
// 	n = n >> 8;
// 	printBinaryMemory(&n, sizeof(int));
//
//	return 0;
//}
