#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "./stack.h"
#include "./files.h"
#include "./symbolTypes.h"

StackHead *stack;
StackHead *errorStack;

bool insideForLoopCondition = false;

bool checkForIgnoredCodeBlocks(int firstChar, BUFFER_TYPE *text, int *i, int *lineNumber){
	switch(firstChar){
		case '\'':
			while (text[(*i)] != '\''){
				(*i)++;
			}
			(*i)++;
			break;
		case '\"':
			while (text[(*i)] != '\"'){
				(*i)++;
			}
			(*i)++;
			break;
		case '/':
			if (text[(*i)] == '/'){
				while (text[(*i)] != '\n'){
					(*i)++;
				}
				(*lineNumber)++;
				(*i)++;
				return true;
			}
			else if (text[(*i)] == '*'){
				while (text[(*i)] != '*' && text[(*i)+1] != '/'){
					if (text[(*i)] == '\n')(*lineNumber)++;
					(*i)++;
				}
				(*i)++;
				return true;
			}
			break;
	}
	return false;
}

int symbolType(int symbol){
	switch(symbol){
		case '{':
		case '(':
		case '[':
			return OPENING_SYMBOL;
		case '}':
		case ')':
		case ']':
		case ';':
			return CLOSING_SYMBOL;
		default:
			return UNTRACKED_SYMBOL;
	}
}

DATA updateStack(int character){
	DATA lastSymbolOnStack = getLastValue(stack);
	switch(character) {
		case '}':
			if(lastSymbolOnStack.CharValue == '{'){
				popFromStack(stack);
				break;
			}
			else {
				DATA errorSymbol = popFromStack(stack);
				return errorSymbol;
			}
		case ')':
			if(lastSymbolOnStack.CharValue == '('){
				popFromStack(stack);
				break;
			}
			else {
				DATA errorSymbol = popFromStack(stack);
				return errorSymbol;
			}
		case ']':
			if(lastSymbolOnStack.CharValue == '['){
				popFromStack(stack);
				break;
			}
			else {
				DATA errorSymbol = popFromStack(stack);
				return errorSymbol;
			}
		case ';':
			if(lastSymbolOnStack.CharValue == '{' || insideForLoopCondition){
				break;
			}
			else {
				while (stack->length > 0){
					lastSymbolOnStack = getLastValue(stack);
					if(lastSymbolOnStack.CharValue == '{') break;
					else {
						addToStack(errorStack, lastSymbolOnStack);
						popFromStack(stack);
					}
				}
			}
	}
	DATA errorSymbol = {LineNumber: 0, CharValue: 0};
	return errorSymbol;
}

bool checkForForLoopConditionBlock (int firstChar, BUFFER_TYPE *text, int *i, int *lineNumber){
	if (firstChar == 'f' && text[*i] == 'o' && text[*i + 1] == 'r' && text[*i + 2] == ' '){
		insideForLoopCondition = true;
		(*i) = (*i) + 3;
		return true;
	}
	return false;
}

void checkForErrors(BUFFER_TYPE *text){
	int c, i = 0, lineNumber = 1;
	
	while((c=text[i++]) != 0){
		if(c == '\n') lineNumber++;
		checkForIgnoredCodeBlocks(c, text, &i, &lineNumber);
		if(checkForForLoopConditionBlock(c, text, &i, &lineNumber)) continue;
		int symType = symbolType(c);
		if(symType == OPENING_SYMBOL){
			DATA symbol = {LineNumber: lineNumber, CharValue: c};
			addToStack(stack, symbol);
		}
		else if(symType == CLOSING_SYMBOL ) {
			DATA error = updateStack(c);
			if (error.LineNumber != 0 && error.CharValue != 0) addToStack(errorStack, error);
		}
	}
}

int main(){
	BUFFER_TYPE *textBuffer = fileToBuffer("Exercise20.c");
	stack = initStack();
	errorStack = initStack();

	checkForErrors(textBuffer);

	printStackData(errorStack);

	freeStack(stack);
	free(textBuffer);
	return 0;
}
