#include<iostream>
using namespace std;

int arr[10];
bool visited[10];
int M,N;

void back(int j,int k){
  if(k==M){
    for(int i=0;i<M;i++) cout<<arr[i]+1<<" ";
    cout<<"\n";
    return;
  }
  for(int i=j;i<N;i++){
    arr[k]=i;
    back(i,k+1);
  }
}

int main(){
  cin>>N>>M;
  back(0,0);
  return 0;
}
