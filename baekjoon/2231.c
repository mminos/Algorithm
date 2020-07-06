#include<stdio.h>
int main(){
  int N,temp,M=0;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    int j=i;
    temp=i;
    while(j!=0){
      temp+=(j%10);
      j=j/10;
    }
    if(temp==N){
      M=i;break;
    }
  }
  printf("%d",M);
  return 0;
}
