#include<stdio.h>
int main(){
  int num1,num2,n1,n2;
  scanf("%d %d",&num1,&num2);
  n1=((num1%100)%10)*100+((num1%100)-(num1%100)%10)+num1/100;
  n2=((num2%100)%10)*100+((num2%100)-(num2%100)%10)+num2/100;
  if(n1>n2)
    printf("%d",n1);
  else
    printf("%d",n2);
  return 0;
}
