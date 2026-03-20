#include<stdio.h>
#include<stdbool.h>

#define MAX_CHAR_NUMBER 60000
#define MAX_LINE_CHAR_COUNT 35

#define LINE_COMMENT 1
#define BLOCK_COMMENT 2
#define EXIT_COMMENT 0

void initArray (int array[], int length, int undefindSymbol){
	for (int i=0 ; i<length ; i++)
		array[i] = undefindSymbol;
}

void printBuffer (int array[], int length){
	for (int i=0, lineNumber=1 ; i<length ; i++){
		if (i == 0) printf("%4d ", lineNumber);
		int c = array[i];

		printf("%c", array[i]);
		if (c == '\n')
			printf("%4d ",++lineNumber);
	}
}

int loadFileToBuffer (FILE* f, int buffer[], int maxLength) {
	int i;

	for (i=0 ; i<maxLength ; i++) {
		int c = fgetc(f);
		
		if (c == EOF) return i;
		buffer[i] = c;
	}

	return i;
}

void copyToStr (int str[], int buff[], int buffLength) {
	initArray (str, MAX_CHAR_NUMBER, '\0');
	for (int i=0 ; i<buffLength ; i++)
		str[i] = buff[i];
}

int inComment (int arr[], int i, int current) {
	switch (arr[i+1]) {
		case '/':
			if (arr[i] == '/') return LINE_COMMENT;
			else return current;
		case '*':
			if (arr[i] == '/') return BLOCK_COMMENT;
			else return current;
		default:
			return current;
	}
}
int exitCom (int arr[], int i, int current) {
	switch (arr[i+1]) {
		case '/':
			if (arr[i] == '*') return EXIT_COMMENT;
			else return current;
		case '\n':
			if (current == LINE_COMMENT) return EXIT_COMMENT; 
			else return current;
		default:
			return current;
	}
}
bool inString (int arr[], int i, bool current){
	if (arr[i] == '"') return !current;
	else return current;
}

int deComment (int buffer[], int length) {
	int uncommentedBuf[length], newLength = 0;

	bool inStr = false;
	for (int i=0, inCom=0 ; i<length ; i++) {
		inStr = inString(buffer, i, inStr);
		if (!inStr) {
			inCom = inComment(buffer, i, inCom);
			if (inCom == LINE_COMMENT || inCom == BLOCK_COMMENT) {
				inCom = exitCom(buffer, i, inCom);
				if ( inCom == EXIT_COMMENT) i++;
			}
			else {
				uncommentedBuf[newLength++] = buffer[i];
			}
		}
		else {
			uncommentedBuf[newLength++] = buffer[i];
			inStr = inString (buffer, i+1, inStr);
			if (!inStr) {
				i++;
				uncommentedBuf[newLength++] = buffer[i];
			}
		}
	}
	
	copyToStr (buffer, uncommentedBuf, newLength);

	return newLength;
}

int main(){
	FILE* f = fopen("./Excercise20.c", "r");
	int buffer[MAX_CHAR_NUMBER];
	initArray (buffer, MAX_CHAR_NUMBER, '\0');
	int length = 0;

	length = loadFileToBuffer (f, buffer, MAX_CHAR_NUMBER);
	fclose(f);

	length = deComment (buffer, length);

	printBuffer (buffer, length);

	return 0;
}
