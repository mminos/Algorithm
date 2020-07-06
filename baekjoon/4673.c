#include<stdio.h>
int add(int num){
  int num1,j,k,sum=0;
  num1=num;
  while(1){
    j=num1/10;
    k=num1%10;
    sum+=k;
    num1=j;
    if(num1/10==0)
    {
      sum+=num1;
      break;
    }
  }
  return num+sum;
}
int main(){
  int n,n1,n2=0;
  int arr[10001]={0};
  for(n=1;n<=10000;n++){
    n1=0;
    n1=add(n);
    arr[n]=n1;
  }
  for(int k=1;k<10001;k++){
    n2=0;
    for(int j=1;j<10001;j++){
      if(k==arr[j])
        n2++;
    }
    if(n2==0)
      printf("%d\n",k);
  }
  return 0;
}
