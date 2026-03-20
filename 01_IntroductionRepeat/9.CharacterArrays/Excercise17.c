#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define LINEPRINT 10
int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main(){
	int len; /* current line lenght */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > LINEPRINT){
			for (int i=0 ; i<len ; i++)
				putchar(line[i]);	
			}

	return 0;
	}

	/* getline: read a line into s, return length */
	int getline(char s[], int lim){
		int c, i;

		for (i=0 ; (c=getchar())!=EOF && c!='\n' ; ++i){
			if (c == 26){
				break;
			}
			s[i] = c;
		}
		if (i < MAXLINE){
			if (c == '\n' || c == 26){
				s[i] = '\n';
				++i;
			}
			s[i] = '\0';
		}
		return i;
	}
