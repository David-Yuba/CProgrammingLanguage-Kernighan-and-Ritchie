#define MAX_BUFFER_SIZE 10000
#define BUFFER_TYPE char

BUFFER_TYPE *initBuffer(){
	BUFFER_TYPE *buf = malloc(sizeof(BUFFER_TYPE)*MAX_BUFFER_SIZE);
	for(int i=0 ; i<MAX_BUFFER_SIZE ; i++){
		buf[i] = 0;
	}
	return buf;
}

void printBufferMemory(BUFFER_TYPE *buf){
	printf("------------------Buffer Memory---------------------");
	for(int i=0 ; i<MAX_BUFFER_SIZE ; i++){
		if(i % 4 == 0) printf("\n%p\t", buf + i);
		printf("%X\t",buf[i]);
	}
}

void printBufferText(BUFFER_TYPE *buf){
	int i = 0;
	int c = -1;
	while((c=buf[i++]) != 0)
		putchar(c);
}

BUFFER_TYPE *fileToBuffer(char fileName[]){
	BUFFER_TYPE *textBuffer = initBuffer();
	FILE *f = fopen(fileName, "r");

	int currentChar = 0;

	int i = 0;
	while((currentChar=fgetc(f)) != EOF){
		textBuffer[i++] = currentChar;
	}


	return textBuffer;
}


