#include<stdio.h>
int main(){
  int N,X;
  int arr[10000]={0};
  scanf("%d %d",&N,&X);
  for(int k=0;k<N;k++){
    scanf("%d",&arr[k]);
  }
  for(int i=0;i<N;i++){
    if(arr[i]<X)
      printf("%d ",arr[i]);

  }
  return 0;
}
