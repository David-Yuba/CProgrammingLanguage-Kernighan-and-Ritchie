#include<stdio.h>

int main(){
    int c;
    int blank = 0;

    while((c = getchar()) != EOF){
        if(c != ' '){
            putchar(c);
            blank = 0;
        }
        else if(c == ' ' && blank == 0){
            putchar(c);
            blank = 1;
        }
    
    }


    return 0;
}