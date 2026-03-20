#include<stdio.h>
int fahr[20];
void genFahrValues(int u, int l, int s){
  for(int i = 0 ; i*s<=u ; i++){
    if(i==0) fahr[i]=l; 
    else fahr[i] = i*s;
  }
}

int main(){
  int cel[20];
  int upper = 300, lower = 1, step = 20;
  genFahrValues(upper, lower, step);
  
  for(int i=0 ; step*i<=upper ; i++)
    cel[i] = (int)((5./9.)*(fahr[i]-32));
   
  printf("fahr\tcel\n");
  for(int i=0 ; step*i<=upper ; i++)
    printf("%d\t%d\n",fahr[i],cel[i]);
}
