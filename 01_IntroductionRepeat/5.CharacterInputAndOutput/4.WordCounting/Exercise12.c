#include<stdio.h>

#define IN 1
#define OUT 0

main(){
	int c, state = OUT;

	while ((c = getchar()) != EOF){
		if ((c == ' ' || c == '\t' || c == '\n') && state == IN){
			putchar('\n');
			state = OUT;
		}
		else if (state == OUT && c != ' ' && c != '\t' && c != '\n'){ 
			state = IN;
		}
		if (state == IN)
			putchar(c);
	}
}
