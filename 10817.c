#include<stdio.h>
int main(){
  int temp;
  int arr[3]={0};
  scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
  for(int i=0;i<2;i++){
    if(arr[i]>=arr[i+1]){
      temp=arr[i];
      arr[i]=arr[i+1];
      arr[i+1]=temp;
    }
  }
  if(arr[0]>=arr[1]){
    temp=arr[0];
    arr[0]=arr[1];
    arr[1]=temp;
  }
  printf("%d",arr[1]);
  return 0;
}
