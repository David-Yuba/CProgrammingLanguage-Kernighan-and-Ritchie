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

	for (int i=0 ; i<20 ; i++)
		printf("%d", wordLength[i]);
	printf("\n");

	printf("Length\t Graph\n");
	for (int i=0 ; i<20 ; i++){
		printf("%d\t", i);
		for (int j=wordLength[i] ; j>0 ; j--)
			printf("-");
		printf("\n");
	}
	return 1;
}
