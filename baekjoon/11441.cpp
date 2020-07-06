#include<cstdio>
int sum(int *,int,int);
int main(){
  int N,M;
  int x,y;
  scanf("%d",&N);
  int* intArr=new int[N];
  int* sumArr=new int[N];
  for(int i=0;i<N;i++)scanf("%d",&intArr[i]);
  for(int i=0;i<N;i++){
    if(i==0)sumArr[i]=intArr[i];
    else{
      sumArr[i]=intArr[i]+sumArr[i-1];
    }
  }
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    scanf("%d %d",&x,&y);
    printf("%d\n",sum(sumArr,x,y));
  }
  return 0;
}

int sum(int* sumArr,int x,int y){
  int result;
  if(x==1){
    result=sumArr[y-1];
  }
  else{
    result=sumArr[y-1]-sumArr[x-2];
  }
  return result;
}
