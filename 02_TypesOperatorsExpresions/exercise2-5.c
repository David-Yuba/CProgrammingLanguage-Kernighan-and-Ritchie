#include<stdio.h>
#include<string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_CHARACTERS 10

int any(char[], char[]);

int main(){
	char stringToSearch[MAX_STRING_LENGTH] = "This is a string the program is searching the characters in.";
	char charactersToSearch[MAX_CHARACTERS] = "fasd";
	
	//printf("Starting pointer of the string: %p\n", stringToSearch);
	printf("%s\n"
			"Characters to search: %s\n"
			"Location of the character: %d\n",
			stringToSearch, charactersToSearch, any(stringToSearch, charactersToSearch));

	return 0;
}

// Function any returns the first location in string s1
// where any characters from s2 occurs, or -1 if no characters
// are found
int any(char s1[], char s2[]){
	int foundIndex = -1;

	for(int i=0 ; s1[i]!='\0' ; i++){
		int foundFlag = 0;
		for(int j=0 ; s2[j]!= '\0' ; j++){
			if (s1[i] == s2[j]){
				foundFlag = 1;
				foundIndex = i;
				break;
			}
		}
		if (foundFlag)
			return foundIndex;
	}

	return foundIndex;
}
