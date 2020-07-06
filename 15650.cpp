#include<iostream>
using namespace std;

int arr[10];
bool visited[10];
int M,N;

void back(int j,int k){
  if(k==M){
    for(int i=0;i<M;i++) cout<<arr[i]+1<<" ";
    cout<<"\n";
  }
  if(j>N)return;
  for(int i=j;i<N;i++){
    if(!visited[i]){
      arr[k]=i;
      visited[i]=1;
      back(i+1,k+1);
      visited[i]=0;
    }
  }
}

int main(){
  cin>>N>>M;
  back(0,0);
  return 0;
}
