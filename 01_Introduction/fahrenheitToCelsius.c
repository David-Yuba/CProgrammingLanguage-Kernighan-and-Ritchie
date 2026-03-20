#include<stdio.h>
//Formula C=(5/9)(F-32) where C is temperature in celsius and f in fahrenheit

float FahrenheitToCelsius(int f){
    return (5.0/9.0)*(f-32);
}

int main(){

    int f[16]={1, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300};
printf("-------------------------\nThis is a heading\n-------------------------\n");
    for(int i=0; i<16; i++){
        printf("%3d\t%6.2f\n",f[i],FahrenheitToCelsius(f[i]));
    }
    
    return 1;
}