#include <stdio.h>
#include "binaryPractice.c"

uint32_t invert(uint32_t x, uint32_t p, uint32_t n){
	uint32_t temp;
	uint32_t mask=0;
	for(int i=0 ; i<n ; i++) mask += 1 << i;

	mask = mask << (p - n);
	temp = ~x & mask;

	x = x & ~mask;

	x = x | temp;
	return x;
}

int main(){
	uint32_t x = 895;
	printBinaryMemory(&x, sizeof(uint32_t));
	x = invert(x, 19, 9);
	printBinaryMemory(&x, sizeof(uint32_t));
	return 0;
}
