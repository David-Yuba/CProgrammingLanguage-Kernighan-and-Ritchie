#include<stdio.h>

/* count lines in input */
main(){
	int c, nl = 0, nt = 0, nb = 0;
	
	while((c = getchar()) != EOF){
		if(c == '\n') ++nl;
		else if(c == '\t') ++nt;
		else if(c == ' ') ++nb;
	}
	printf("Number of newlines is %d\nNumber of tabs is %d\nNumber of blanks is %d\n", nl, nt, nb);
}
