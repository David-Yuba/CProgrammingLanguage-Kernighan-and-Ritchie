// Check a C program for rudimentary syntax errors like un,atched parentheses, brackets and braces.
// Don't forget about quotes, both single and double, escape sequences, and comments.
#include<stdio.h>
#include<stdbool.h>

#define MAX_TEXT_LENGTH 10000

void initBuffer (char buf[], int maxLength) {
	for (int i=0 ; i<maxLength ; i++)
		buf[i] = '\0';
}

int loadFileToBuffer(FILE* f, char buffer[], int maxLength) {
	int length;
	
	length = fread(buffer, 1, maxLength, f);

	return length;
}

void printToStdout (char buffer[], int bufLength) {
	fputs(buffer, stdout);
}

void printBinaryToStdout (char buffer[], int bufLength) {
	for (int i=0 ; i<100 ; i++) {
		if ((i % 4) == 0) printf("\n%X\t", buffer + i);
		for (int j=0 ; j<8 ; j++){
			char temp = (buffer[i] >> (7 - j)) << 7;
			if (temp) putchar('1');
			else putchar('0');
		}
		putchar ('\t');
	}
}

int main(){
	FILE* f = fopen("./Excercise20WithErrors.c", "r");
	char buf[MAX_TEXT_LENGTH];
	int textLength = 0;
	initBuffer (buf, MAX_TEXT_LENGTH);

	textLength = loadFileToBuffer (f, buf, MAX_TEXT_LENGTH);

	printBinaryToStdout(buf, textLength);
	// printToStdout (buf, textLength);

	return 0;
}
