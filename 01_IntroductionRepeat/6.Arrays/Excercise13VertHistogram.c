#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
	int wordLength[20], c, state = OUT, wordSize=0;

	for (int i = 0 ; i < 20 ; i++)
		wordLength[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == 26) break;	
		if (c != ' ' && c != '\t' && c != '\n')
			state = IN;
		if (c != ' ' && c != '\t' && c != '\n' && state == IN){
			++wordSize;
			state = IN;
		} 
		else if (state == IN){
			++wordLength[wordSize];
			wordSize = 0;
			state = OUT;
		}
	}
	
	if (state == IN){
			++wordLength[wordSize];
			wordSize = 0;
			state = OUT;
	}
	
	int maxHeight=0;
	for (int i=0 ; i<20 ; i++)
		if (maxHeight < wordLength[i]) maxHeight = wordLength[i];

	while (maxHeight != 0){
		printf("%d\t", maxHeight);
		for (int i=0 ; i<20 ; i++){
			if (wordLength[i] == maxHeight) printf("--  ");
			else if (wordLength[i] > maxHeight && wordLength[i] != 0) printf("||  ");	
			else printf("    ");
		}	
		printf("\n");
		--maxHeight;
	}
	
	printf("Length\t");
	for (int i=0 ; i<20 ; i++)
		printf("%2d  ",i);

	return 1;
}
