#include<stdio.h>

int main(){
  int counting[10000]={0,};
  int N,num,count=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&num);
    counting[num-1]++;
  }
  for(int i=0;i<10000;i++){
    for(int j=0;j<counting[i];j++){
      printf("%d\n",i+1);
      count++;
    }
    if(count==N)break;
  }
  return 0;
}
