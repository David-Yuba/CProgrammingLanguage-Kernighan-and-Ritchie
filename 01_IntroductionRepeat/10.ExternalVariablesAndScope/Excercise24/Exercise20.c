// The program replaces all tabs with a fixed number of spaces
#include <stdio.h>

#define TABLENGTH 4
#define MAXLENGTH 1000

// gets input from the keyboard and stores it into a buffer input, returns number of characters including \0 at the end
// returns -1 if the length is too large
int getInput(char input[]);

// replaces \t characters with TABLENGTH number of spaces, returns new number of characters
// uses countTabs and length so it doesn't overflow the buffer
// returns -1 if the length is too large
int replaceTabs(char paragraph[], int length);

void shiftArray(char array[], int startingIndex, int amount);

int countTabs(char paragraph[]);

int main() {
	char in[MAXLENGTH];
	int length;	

	length = getInput(in); // this is an extra comment for excercise 23

	if(length != -1) length = replaceTabs(in, length);
	else printf("Too much characters");

	if(length != -1) printf("%s", in);
	else printf("Too much characters");

	return 0;
}

int getInput(char input[]){
	int c, i = 0;
	while ((c = getchar()) != EOF && i < MAXLENGTH){
		input[i] = c;
		i++;
	}
	if (i == MAXLENGTH) return -1;
	/*
	 * This is also an extra comment for excercise 23
	 */
	input[i] = '\0';
	i++;

	return i;
}

int replaceTabs(char input[], int length){
	int c, i=0;
	int tabCount = countTabs(input);
	if (tabCount*TABLENGTH+length-tabCount >= MAXLENGTH) return -1;
	while ((c = input[i]) != '\0'){
		if (c == '\t'){
			shiftArray(input, i, TABLENGTH);
			i = i+TABLENGTH-1;
		}
		i++;	
	}
	return i;
}

void shiftArray(char array[], int startingIndex, int amount){
	char temp[MAXLENGTH];
	char temp1[50] = "// this is a string for Excercise23";
	char temp2[50] = "/* this is a string for Excercise23";
	int i = startingIndex; /* Extra comment
				  that has something important
				  maybe

*/	while ((temp[i-startingIndex] = array[i]) != '\0') i++;
	temp[i] = '\0';

	for (i=startingIndex ; i<startingIndex+TABLENGTH ; i++)
		array[i] = ' ';
	
	i=0;
	while ((array[i+startingIndex+TABLENGTH] = temp[i+1]) != '\0')
		i++;
	// array[i+startingIndex+TABLENGTH] = '\0';
}

int countTabs(char paragraph[]){
	int numberOfTabs = 0, c, i=0;
	while ((c = paragraph[i]) != '\0'){
		if (c == '\t')
			numberOfTabs++;
		i++;
	}
	return numberOfTabs;
}
