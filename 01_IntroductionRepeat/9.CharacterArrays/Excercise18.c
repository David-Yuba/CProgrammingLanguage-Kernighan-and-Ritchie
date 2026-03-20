#include <stdio.h>

#define MAXPLENGTH 1000
#define MAXLLENGTH 100

int appendLineToParagraph(char paragraph[], char line[], int paragraphLength);
int getLine( char line[], int maxLength);

int main(){
	char paragraph[MAXPLENGTH]; // Paragraph buffer
	char line[MAXLLENGTH]; // Line buffer
	int lineLength; 
	int paragraphLength=0; 

	while ((lineLength = getLine(line,MAXLLENGTH)) > 0){
		if (paragraphLength + lineLength < MAXPLENGTH)
			paragraphLength = appendLineToParagraph(paragraph, line, paragraphLength);
		else {
			printf("Paragraph length exceded");
			break;
		}
	}
	
	for (int i=0 ; i<paragraphLength ; i++)
		putchar(paragraph[i]);
				

	return 0;
}

// reads line and puts it into the line buffer, returns length of line
int getLine (char line[], int maxLength){
	int lineLength = 0;
	int inWord = 0;
	int c;

	while ((c=getchar()) != EOF && lineLength < maxLength){
		if (c == '\n'){
			if ( line[lineLength-1] == ' ' || line[lineLength-1] == '\t') line[lineLength-1] = c;
			else line[lineLength] = c;
			lineLength--;
			break;
		}
		
		if (c != ' ' && c != '\t'){
			line[lineLength] = c;
			inWord = 1;
			lineLength++;
		}
		else {
			if (inWord == 0);
			else { 
				if (c == 32) line[lineLength] = ' ';
				line[lineLength] == c;
				lineLength++;
				inWord = 0;
			}
		}
	}
	return lineLength;
}

// takes the line and appends it to paragraph buffer, returns new paragraph length
int appendLineToParagraph(char paragraph[], char line[], int paragraphLength){
	int cursor=0;	

	while (line[cursor] != '\n'){
		paragraph[paragraphLength+cursor] = line[cursor];
		cursor++;
	}
	paragraph[paragraphLength+cursor] = line[cursor];
	cursor++;
	
	return cursor + paragraphLength;
}
