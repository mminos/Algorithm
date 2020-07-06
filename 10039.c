#include<stdio.h>
int main(){
  int arr[5]={0};
  int sum=0;
  for(int k=0;k<5;k++){
    scanf("%d",&arr[k]);
    if(arr[k]<40)
      arr[k]=40;
    sum+=arr[k];
  }
  printf("%d",sum/5);
  return 0;
}
