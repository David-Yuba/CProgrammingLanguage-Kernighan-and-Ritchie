#include<stdio.h>

#define MAX_CHAR_NUMBER 60000
#define MAX_LINE_CHAR_COUNT 35

void initArray (int array[], int length, int undefindSymbol){
	for (int i=0 ; i<length ; i++)
		array[i] = undefindSymbol;
}

void printBuffer (int array[], int length){
	for (int i=0, lineNumber=1, lineCharCount = MAX_LINE_CHAR_COUNT ; i<length ; i++){
		if (i == 0) printf("%4d ", lineNumber);
		int c = array[i];

		printf("%c", array[i]);
		lineCharCount--;
		if (c == '\n') {
			printf("%4d ",++lineNumber);
			lineCharCount = MAX_LINE_CHAR_COUNT;
		}
		else if (lineCharCount <= 1 && (c == ' ' || c == '\t')) {
			printf("\n     ");
			lineCharCount = MAX_LINE_CHAR_COUNT;
		}
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

int main(){
	FILE* f = fopen("./Excercise20.c", "r");
	int buffer[MAX_CHAR_NUMBER];
	initArray (buffer, MAX_CHAR_NUMBER, '\0');
	int length = 0;

	length = loadFileToBuffer (f, buffer, MAX_CHAR_NUMBER);
	fclose(f);

	printBuffer (buffer, length);

	return 0;
}
