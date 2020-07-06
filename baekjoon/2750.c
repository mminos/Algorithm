#include<stdio.h>
int main(){
  int arr[1001]={0,};
  int N,temp;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",&arr[i]);
  for(int i=N-1;i>0;i--){
    for(int j=0;j<i;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
  for(int i=0;i<N;i++)
    printf("%d\n",arr[i]);
  return 0;
}
