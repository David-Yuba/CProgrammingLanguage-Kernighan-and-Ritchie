#include<stdio.h>
#include<stdbool.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_LINE_LENGTH 100
#define TAB_LENGTH 8

#define CHAR_NOT_HANDLED 0
#define CHAR_TYPE_LETTER 1
#define CHAR_TYPE_SPACE 2

void initArray (int array[], int length, int undefindSymbol){
	for (int i=0 ; i<length ; i++)
		array[i] = undefindSymbol;
}

void outputString (int array[], int length){
	for (int i=0 ; i<length ; i++){
		if (array[i] == '\t') printf("0");
		else printf("%c", array[i]);
	}
}

int inputLine (int inputBuffer[], int bufferLength){
	int lineLength = 0;

	for (int i=0 ; i<bufferLength ; i++){
		int c = getchar();
		inputBuffer[i] = c;

		if (c == '\n') {
			lineLength = i;
			break;
		}
	}

	return lineLength;
}

int appendLine (int destination[], int line[], int lineLength, int textLength){

	for (int i=0 ; i<=lineLength ; i++){
		destination[textLength + i] = line[i];
	}
	return textLength + lineLength + 1;
}

int charType (int c){
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return CHAR_TYPE_LETTER;
	if (c == ' ')
		return CHAR_TYPE_SPACE;
	
	return CHAR_NOT_HANDLED;
}

int entab (int text[], int length){
	int buffer[length + 1];
	initArray(buffer, length, '\0');
	int j = 0;	
	
	for (int i=0, currentTabstop=1, numOfSpaces = 0, lastCharPos=0, inSpaces = false ; i<length ; i++){
		if (i > currentTabstop * TAB_LENGTH) currentTabstop++;
		int c = text[i];

		switch (charType(c)){
			case CHAR_TYPE_LETTER:
				while ((numOfSpaces > 0)) {
						buffer[j++] = ' ';		
						numOfSpaces--;
				}
				lastCharPos = i;
				buffer[j++] = c;	
				break;
			case CHAR_TYPE_SPACE:
				if ((numOfSpaces + 1 + lastCharPos) == currentTabstop * TAB_LENGTH - 1){
					lastCharPos = currentTabstop * TAB_LENGTH - 1;
					currentTabstop++;
					if (numOfSpaces != 0)	buffer[j++] = '\t';
					else {
						buffer[j++] = ' ';
					}
					numOfSpaces = 0;
				}
				else numOfSpaces++;
				break;
		}
	}

	initArray (text, length + 1, '\0');

	for (int i=0 ; i<j ; i++)
		text[i] = buffer[i];

	return j;
}

int main(){
	int text[MAX_TEXT_LENGTH], inputBuffer[MAX_LINE_LENGTH];
	int textLength = 0;
	initArray(text, MAX_TEXT_LENGTH, '\0');
	initArray(inputBuffer, MAX_LINE_LENGTH, '\0');
	

	printf("&-------&-------&-------&-------&-------&-------&-------&-------&-------&--------&-------&-------&-------&-------&-------&-------\n");
	while (true){
		int lineLength = inputLine(inputBuffer, MAX_LINE_LENGTH);
		printf("%d\n", lineLength);
		
		if (lineLength > 0) {
			textLength = appendLine(text, inputBuffer, lineLength, textLength);
			initArray(inputBuffer, lineLength, '\0');
		}
		if (lineLength == 0) break;
	}

	textLength = entab(text, textLength);
	
	printf("\n\n------------ Text output------------\n\n");
	outputString(text, MAX_TEXT_LENGTH);
	return 0;
}
