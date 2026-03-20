#include <stdio.h>

#define MAXLENGTH 1000

int getInput (char buffer[], int tab);

int main(){
	int n = 10; // tabStop size

	char in[MAXLENGTH];
	int length = getInput(in, n-1);

	printf("%s", in);

	return 0;
}
/*
	Loop that gets the input
	from the user
*/
int getInput (char buffer[], int tab){	
	int c, i = 0, t = tab;

	while ((c=getchar()) != EOF){
		if (c == '\t'){
			for (int j=t ; j >= 0 ; j--) buffer[i+j] = ' ';
			i = i+t;
			t = tab;
		}
		else {
			buffer[i] = c;
			t--;
			if (t == -1) t = tab;
		}
		if (c == '\n') t = tab;
		i++;
	}
}
