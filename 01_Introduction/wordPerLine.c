#include<stdio.h>

#define OUT 0
#define IN 1

int main(){
    int c, state = OUT;
    
    while((c = getchar()) != EOF){
        if((c==' ' || c=='\n' || c=='\t') && state){
           state = OUT;
           putchar('\n'); 
        }
        else{
            putchar(c);
            state = IN;
        }
    }
}