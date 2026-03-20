#include <stdio.h>

#define MAXLINELENGTH 100
#define MAXPARLENGTH 1000

int getLine (char line[], int maxLength);
int addLineToPara(char line[], char paragraph[], int paraLength);
void reverse (char s[], char reversedLine[], int length);

int main() {
	char line[MAXLINELENGTH], reversedLine[MAXLINELENGTH], paragraph[MAXPARLENGTH];
	int lineLength, paragraphLength=0;	

	while ((lineLength = getLine(line, MAXLINELENGTH)) > 0){
		reverse(line, reversedLine, lineLength);
		paragraphLength = addLineToPara(reversedLine, paragraph, paragraphLength);
	}
	
	int i = 0;
	while (i < paragraphLength){
		putchar(paragraph[i]);	
		i++;
	}

	return 0;
}

int getLine (char line[], int maxLength){
	int length=0;	
	int c;

	while ((c = getchar()) != '\n'  && length < maxLength){
	  if (c == EOF) return 0;
		line[length] = c;	
		length++;
	}
	line[length] = '\n';
	return length;
}	

int addLineToPara(char line[], char paragraph[], int paraLength){
	int cursor=0, c;
	
	while ((c = line[cursor]) != '\n' && ((paraLength+cursor) < MAXPARLENGTH)){
		paragraph[paraLength+cursor] = c;	
		cursor++;
	}
	paragraph[paraLength+cursor] = '\n';

	return cursor + paraLength + 1;
}

void reverse (char s[], char reversedLine[], int length){
	int i = length-1;

	while (i != -1){
		reversedLine[length-i-1] = s[i];	
		i--;
	}
	reversedLine[length] = '\n';
}
