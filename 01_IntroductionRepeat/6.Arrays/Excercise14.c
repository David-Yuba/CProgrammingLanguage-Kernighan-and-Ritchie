#include <stdio.h>

#define NUMBEROFCHARACTERS 26

int main(){
	int charN[NUMBEROFCHARACTERS], c;

	for (int i = 0 ; i < NUMBEROFCHARACTERS ; i++)
		charN[i] = 0;

	while ((c = getchar()) != EOF){
		if (c == 26) break;	
		if (c>='a' && c<='z')
			++charN[c-'a'];
		if (c>='A' && c<='Z')
			++charN[c-'A'];
	}
	
	for (int i=0 ; i<NUMBEROFCHARACTERS ; i++)
		printf("%d", charN[i]);
	printf("\n");

	printf("Character\t Graph\n");
	for (int i=0 ; i<NUMBEROFCHARACTERS ; i++){
		printf("%c\t", i+'a');
		for (int j=charN[i] ; j>0 ; j--)
			printf("-");
		printf("\n");
	}
	return 1;
}
