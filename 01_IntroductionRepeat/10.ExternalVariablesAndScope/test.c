#include "stringManip.h"

int main(){
	int line[MAXLINELENGTH];
	int text[MAXTEXTLENGTH];
	
	int lineLength = 0, textLength = 0;	
	while ((lineLength = getLine(line)) != 0){
		textLength = appendLine(line, text, lineLength, textLength);
	}

	printf("Input:\n");
	printText(text);
	printf("Input length = %d\n", textLength);

	return 0;
}
