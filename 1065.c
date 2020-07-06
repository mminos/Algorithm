#include<stdio.h>
int add(int num){
  int sum=0,a,b,c,kk,kkk;
  if(num<100)
  {
    sum=num;
    return sum;
  }
  else
{
  sum=99;
  for(int k=100;k<=num;k++){
    a=k/100;
    b=(k/10)%10;
    c=k%10;
    kk=a-b;
    kkk=b-c;
    if(kk==kkk)
      sum++;
  }
  return sum;
}

}
int main(){
  int n,n1;
  scanf("%d",&n);
  n1=add(n);
  printf("%d",n1);

  return 0;
}
