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
  int T;
  scanf("%d",&T);
  while(T--){
    int num,M,N;
    scanf("%d",&num);
    for(int i=2;i<=num/2;i++){
      if(prime[num-prime[i]]!=0){
        M=i;N=num-i;
      }
    }
    printf("%d %d\n",M,N);
  }


  return 0;
}
