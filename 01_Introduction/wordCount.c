#include<stdio.h>

#define IN 1
#define OUT 0

int main(){
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    state = OUT;

    while((c = getchar()) != EOF){
        if(c == '\n'){
            ++nl;
            if(state){
                ++nw;
                state = OUT;
            }
        }
        else if((c == ' ' || c == '\t') && state){
            state = OUT;
            ++nw;
        }
        else state = IN;
        ++nc;
    }
   printf("%4d\t%4d\t%4d\n", nl, nw, nc);
    return 0;
}