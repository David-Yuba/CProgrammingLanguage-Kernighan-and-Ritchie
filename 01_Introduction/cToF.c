#include<stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(){
    int cel;
    for(cel = UPPER; cel >= LOWER; cel = cel - STEP){
        printf("%6d\t%6.2f\n", cel, (9.0/5.0)*cel-32.0);
    }

    return 0;
}