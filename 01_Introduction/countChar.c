#include<stdio.h>

int main(){
    long nc;

    nc=0;
    while(getchar() != EOF)
        ++nc;
    printf("lld\n", nc);

    return 0;
}