#include<stdio.h>

#define MAX_LENGTH 100

void squeeze(char[], char[]);

int main(){
	char squeezedString[MAX_LENGTH] = "This is a string to be squeezed", 
		 charactersToSqueeze[MAX_LENGTH] = "hsav";

	printf("%s\n"
			"Characters to remove are: %s\n", 
			squeezedString, charactersToSqueeze);
	squeeze(squeezedString, charactersToSqueeze);

	printf("%s\n", squeezedString);
	return 0;
}

void squeeze(char squeezedString[], char charactersToSqueeze[]){
	int i, j;

	for(i=j=0 ; squeezedString[i] != '\0' ; i++){
		char foundCharacterFlag = 0;
		for(int k=0 ; charactersToSqueeze[k] != '\0' ; k++){
			if(squeezedString[i] == charactersToSqueeze[k]){
				foundCharacterFlag = 1;
				break;
			}
		}
		if(!foundCharacterFlag)
			squeezedString[j++] = squeezedString[i];
	}
	squeezedString[j] = '\0';
}
