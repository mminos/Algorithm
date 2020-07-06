#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  scanf("%d",&n);
  int *arr = new int[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  sort(arr,arr+n);
  for(int i=0;i<n;i++)cout<<arr[i];
  return 0;
}
