#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int x,y,w,h;
  scanf("%d %d %d %d",&x,&y,&w,&h);
  int arr[4]={x,y,w-x,h-y};
  sort(arr,arr+4);
  printf("%d",arr[0]);
  return 0;
}
