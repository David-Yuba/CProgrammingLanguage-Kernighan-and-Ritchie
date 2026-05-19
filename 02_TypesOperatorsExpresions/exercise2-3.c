#include<stdio.h>
#include<math.h>

#define MAX_LENGTH 100

long long int htoi(char[]);
int getIntegerValueFromChar(char);

int main(){
	char s[MAX_LENGTH] = "0x1Aa024561";
	long long int result;
	result = htoi(s);

	printf("%s = %lld\n", s, result);
	return 0;
}

long long int htoi(char s[]){
	long long int result = 0;
	int skip = 0;
	if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		skip=2;
	}

	int i = 0;
	while(s[i+skip] != '\0' && s[i+skip] != '\n'){
		i++;
	}
	int length = i;

	for(int i=0; i<length ; i++){
		long long int value = getIntegerValueFromChar(s[i+skip]);
		if (value == -1) return -1;

		result += value * pow(16, length -1 - i);
	}

	return result;
}

int getIntegerValueFromChar(char character){
	switch(character){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;

		case 'a':
		case 'A': return 10;
		case 'b':
		case 'B': return 11;
		case 'c':
		case 'C': return 12;
		case 'd':
		case 'D': return 13;
		case 'e':
		case 'E': return 14;
		case 'f':
		case 'F': return 15;
		default: return -1;
	}
}
