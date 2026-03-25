#define MAX_STACK_SIZE 1000
#define DATA SymbolData

typedef struct{
	int LineNumber;
	char CharValue;
}SymbolData;

typedef struct{
	DATA data;
} StackData;

typedef struct{
	int length;
	StackData *first;
	StackData *last;
} StackHead;

void addToStack(StackHead *s, DATA symbol){
	int len = s->length;
	s->first[len].data.LineNumber = symbol.LineNumber;
	s->first[len].data.CharValue = symbol.CharValue;
	s->last = &(s->first[len]);
	s->length++;
}

DATA getLastValue(StackHead *s){
	DATA value = {LineNumber: s->last->data.LineNumber, CharValue: s->last->data.CharValue};

	return value;
}

DATA popFromStack(StackHead *s){
	DATA value = getLastValue(s);
	int len = --s->length;
	s->last->data.LineNumber = 0;
	s->last->data.CharValue = 0;
	s->last = &(s->first[len-1]);

	return value;
}

StackHead* initStack(){
	StackHead *s = malloc(sizeof(StackHead));
	s->length = 0;
	s->first = malloc(sizeof(StackData) * MAX_STACK_SIZE);
	s->last = s->first;

	for (int i=0 ; i<MAX_STACK_SIZE ; i++) {
		s->first[i].data.LineNumber = 0;
		s->first[i].data.CharValue = 0;
	}
	return s;
}

void printStackHead(StackHead *stack){
	printf("-----------------StackHead--------------------\n");
	printf("Length = %d\nFirstElement = %p\nLastElement = %p\n", stack->length, stack->first, stack->last);
}

void printStackMemory(StackHead *stack){
	printf("-----------------StackMemory--------------------");
	for (int i=0 ; i<MAX_STACK_SIZE ; i++) {
		if (i % 4 == 0)
			printf("\n%p\t", stack->first + i);
	}
}

void printStackData(StackHead *stack){
	printf("------------------------------------------------\n");
	printf("Element#\tLineNumber\tCharacter\n");
	for (int i=0 ; i<stack->length ; i++){
		printf("%d\t\t", i+1);
		printf("%d\t\t", stack->first[i].data.LineNumber);
		printf("%c\n", stack->first[i].data.CharValue);
	}
}

void freeStack(StackHead *stack) {
	free(stack->first);
	free(stack);
}
