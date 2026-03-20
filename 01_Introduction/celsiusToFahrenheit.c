#include<stdio.h>

int main(){
    float cel,fahr;
    int lower, upper, step;
    
    lower=0;
    upper=300;
    step=20;

    while(lower<=upper){
        cel=lower;
        fahr=(cel*(9.0/5.0))-32.0;

        printf("%6f\t%6.2f\n", cel, fahr);
        lower+=step;
    }
    return 0;
}