#include<stdio.h>

int pac(int n){
  if(n==0)return 1;
  else if(n==1)return 1;
  else return n*pac(n-1);
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%d",pac(n));
  return 0;
}
