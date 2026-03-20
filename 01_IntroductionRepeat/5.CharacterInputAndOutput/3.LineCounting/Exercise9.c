#include<stdio.h>

/* count lines in input */
main(){
	int c, inB = 0;
		
	while((c = getchar()) != EOF){
		if( inB == 0 ) putchar(c);
		else if( c != ' '){
			putchar(c);
			inB = 0;
		}
		if( c == ' ') inB = 1;
	}
}
