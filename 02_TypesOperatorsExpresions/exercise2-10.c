#include<stdio.h>

#define MAX_LENGTH 100

void lower(char s[]){
	char p;
	for(int i=0 ; i<MAX_LENGTH && (p=s[i])!='\0' ; i++){
		s[i] = (s[i]>='A' && s[i]<='Z')? s[i] + 32 : s[i];
	}
}

int main(){
	char string[MAX_LENGTH] = "This STring Will BEEE LoweReD.";
	printf("%s\n", string);

	lower(string);
	printf("%s\n", string);
	return 0;
}
