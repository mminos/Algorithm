#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int N,i=0;
  int arr[10]={0,};
  scanf("%d",&N);
  while(N>0){
    int n=N%10;
    arr[i]=n;
    i++;
    N/=10;
  }
  sort(arr,arr+i);
  for(int j=i-1;j>=0;j--)
    printf("%d",arr[j]);
  return 0;
}
