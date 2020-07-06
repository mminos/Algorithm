#include<iostream>
using namespace std;

int N,M;
bool visited[10];
int arr[10];

void back(int k){
  if(k==M){
    for(int i=0;i<M;i++)
      cout<<arr[i]+1<<" ";
    cout<<"\n";
    return;
  }
  for(int i=0;i<N;i++){
    arr[k]=i;
    visited[i]=1;
    back(k+1);
    visited[i]=0;
  }
}

int main(){
  cin>>N>>M;
  back(0);
  return 0;
}
