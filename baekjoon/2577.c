#include<stdio.h>
int main(){
  int a,b,c,num,num1,i=0;
  int arr[10]={0};
  scanf("%d %d %d",&a,&b,&c);
  num=a*b*c;
  while(1){
    num1=num%10;
    num/=10;
    arr[num1]++;
    if(num==0)
      break;
  }
  for(i;i<10;i++)
    printf("%d\n",arr[i]);
  return 0;
}
