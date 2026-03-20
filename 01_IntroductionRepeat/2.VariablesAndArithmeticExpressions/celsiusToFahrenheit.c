#include<stdio.h>
int cel[20];
void genFahrValues(int u, int l, int s){
  for(int i = 0 ; i*s<=u ; i++){
    if(i==0) cel[i]=l; 
    else cel[i] = i*s;
  }
}

int main(){
  int fahr[20];
  int upper = 300, lower = 1, step = 20;
  genFahrValues(upper, lower, step);
  
  for(int i=0 ; step*i<=upper ; i++)
    fahr[i] = (int)((9./5.)*(cel[i])+32);
   
  printf("cel\tfahr\n");
  for(int i=0 ; step*i<=upper ; i++)
    printf("%3d\t%3d\n",cel[i],fahr[i]);
}
