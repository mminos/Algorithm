#include<stdio.h>
int main(){
  int weight[50] = {0,};
  int height[50] = {0,};
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d %d",&weight[i],&height[i]);
  for(int i=0;i<N;i++){
    int count=1;
    for(int j=0;j<N;j++){
      if(i==j)continue;
      int check=0;
      if(weight[i]<weight[j])check++;
      else check--;
      if(height[i]<height[j])check++;
      else check--;

      if(check>0)count++;
    }
    printf("%d ",count);
  }
  return 0;
}
