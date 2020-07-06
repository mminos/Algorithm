#include<cstdio>
using namespace std;

int main(){
  int prime[100001]={0,};
  for(int i=2;i<100001;i++){
    prime[i]=i;
  }
  for(int i=2;i<100001;i++){
    if(prime[i]==0)continue;
    for(int j=i+i; j<100001;j+=i)prime[j]=0;
  }
  int M,N;
  scanf("%d",&M);
  scanf("%d",&N);
  for(int i=M;i<=N;i++){
    if(prime[i]!=0)printf("%d\n",i);
  }
  return 0;
}
