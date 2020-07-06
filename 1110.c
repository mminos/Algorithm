#include<stdio.h>
int main(){
  int a,b,c,num,num1,num3=0;
  scanf("%d",&num);
  if(num<10)
    num*=10;
  num1=num;
  while(num!=num1||num3==0){

    a=num1/10;
    b=num1%10;
    c=(a+b)%10;
    num1=b*10+c;

    num3++;
  }
  printf("%d",num3);
  return 0;
}
