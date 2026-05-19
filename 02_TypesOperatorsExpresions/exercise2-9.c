#include <stdio.h>
#include "binaryPractice.c"

uint32_t bitCount(uint32_t number){
	uint32_t numberOfBits;
	for(; number!=0 ; number &= (number-1)){
		numberOfBits++;
	}
	return numberOfBits;
}
// x &= (x-1) deletes the rightmost 1-bit in x. Why?
// (x-1) decrements a number by replacing the first 1 with a zero, and if there are
// any zeroes before the 1 replaces them with 1.
// For example 1000 - 1 gives 0111. since the number has 3 zeroes before the 1, the decrementation
// borrows the 1 from each subsequent 0 until it gets to the 1, where the borrowing stops
// The &= deletes the 1s that were created by the borrowing.
// For example x = 1000, x = x & x-1, x = 1000 & 0111, x = 0000
int main(){
	uint32_t x = 5893712;
	printBinaryMemory(&x, sizeof(uint32_t));
	printf("Number of bits in %d: %d", x, bitCount(x));
	return 0;
}
