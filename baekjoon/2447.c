#include<stdio.h>

char arr[2188][2188];

void solve(int x, int y, int N);
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      arr[i][j] = ' ';
    }
  }
  solve(0,0,N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf("%c",arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}

void solve(int x, int y, int N){
  if(N==1){
    arr[x][y]='*';
    return;
  }
  int M = N/3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i==1&&j==1)continue;
      solve(x+i*M,y+j*M,M);
    }
  }
}
