#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int N;
  int arr[10]={0,};
  scanf("%d",&N);
  while(1){
    arr[N%10]++;
    N/=10;
    if(N==0)break;
  }
  if(arr[6]!=0||arr[9]!=0){
    int num=arr[6]+arr[9];
    if(num%2==0){
      arr[6]=num/2;
      arr[9]=num/2;
    }
    else{
      arr[6]=num/2+1;
      arr[9]=num/2+1;
    }
  }
  sort(arr,arr+10);
  printf("%d",arr[9]);

  return 0;
}
