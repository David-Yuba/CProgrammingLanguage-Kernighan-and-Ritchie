#include <stdio.h>
#include "binaryPractice.c"

uint32_t rightrot(uint32_t x, uint32_t n){
	uint32_t temp = x >> (n);
	x = x & (~0 >> (sizeof(uint32_t)*8 - n));
	printBinaryMemory(&temp, sizeof(uint32_t));
	x = x << (sizeof(uint32_t)*8 - n);
	return x | temp;
}

int main(){
	uint32_t x = 589385982;
	printBinaryMemory(&x, sizeof(uint32_t));
	x = rightrot(x, 9);
	printBinaryMemory(&x, sizeof(uint32_t));
	return 0;
}
