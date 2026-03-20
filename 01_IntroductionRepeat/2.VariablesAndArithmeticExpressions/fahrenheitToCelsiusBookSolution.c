#include<stdio.h>

/* Print Fahrenheit-Celsius table
 * for fahr = 0,20, ..., 300*/

int main(){
  float fahr,cel;
  float upper = 300, lower = 0, step = 20;
  fahr = lower;

  while(fahr <= upper){
     cel = 5*(fahr-32.)/9;
     printf("%3.0f\t%6.0f\n",fahr,cel);
     fahr += step;
  }
}
