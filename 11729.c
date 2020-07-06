#include<stdio.h>
#include<math.h>
void hanoi(int from, int N, int target){
  if(N==1){
    printf("%d %d\n",from,target);
    return;
  }
  int check[3]={0,};
  int non;
  check[from-1]++;
  check[target-1]++;
  for(int i=0;i<3;i++){
    if(check[i]==0)non=i+1;
  }

  hanoi(from,N-1,non);
  hanoi(from,1,target);
  hanoi(non,N-1,target);
}
int main(){
    int N;
    scanf("%d",&N);
    printf("%.0f\n",pow(2.0,N)-1);
    hanoi(1,N,3);
    return 0;
}
