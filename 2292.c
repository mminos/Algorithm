#include<stdio.h>
int main(){
  int num1=0,num2=0,res=1;
  scanf("%d",&num1);
  while(1){
    if(num1>res){
      num2++;
      res+=6*num2;
    }
    else
      break;
  }
  printf("%d",num2+1);
  return 0;
}
