#include<stdio.h>
#include<string.h>
#include<inttypes.h>
#include "binaryPractice.c"

uint32_t setBits(unsigned x, int p, int n, unsigned y){
	uint32_t result = x;
	uint32_t mask = 0;
	for (int i=0 ; i<n ; i++) mask += (1 << i);
	mask = ~(mask << (p - n));
	// printBinaryMemory(&mask, sizeof(int));
	result = result & mask;
	// printBinaryMemory(&result, sizeof(int));
	y = y << (p-n);
	y = y & (~mask);
	result = result | y;
	return result;
}

int main(){
	int x = 274;
	int y = 323;
	printBinaryMemory(&x, sizeof(int));
	printBinaryMemory(&y, sizeof(int));
	x = setBits(x, 14, 8, y);
	printBinaryMemory(&x, sizeof(int));
	return 0;
}
