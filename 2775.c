#include<stdio.h>
int func1(int,int);
int main(){
  int testcase;
  scanf("%d",&testcase);
  for(int i=0;i<testcase;i++){
    int num1,num2,total=0;
    scanf("%d %d",&num1,&num2);
    total=func1(num1,num2);
    printf("%d\n",total);
  }
}
int func1(int a,int b){
  if(a==0)
    return b;
  else{
    int sum=0;
    for(int i=1;i<=b;i++){
      sum+=func1(a-1,i);
    }
    return sum;
  }
}
