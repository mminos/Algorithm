#include<stdio.h>
#include<stdlib.h>
int main(){
  int arr[10001]={0,};
  int N,M;
  int max=0,tot=0;
  scanf("%d %d",&N,&M);

  for(int i=0;i<N;i++)
    scanf("%d",&arr[i]);
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++){
        tot = arr[i]+arr[j]+arr[k];
        if(tot<=M && tot>=max)
          max=tot;
      }
    }
  }
  printf("%d",max);
  return 0;
}
