#include<stdio.h>

#define MAX_CHARACTERS 10

int main(){
	char s[MAX_CHARACTERS];

	int i=0;
	for (i=0 ; i<MAX_CHARACTERS-1 ; i++){
		int c = getchar();
		if(c == '\n') break;
		if(c == EOF) break;
		s[i] = c;
	}
	s[++i] = '\0';

	printf("\n%s\n",s);
	return 0;
}
