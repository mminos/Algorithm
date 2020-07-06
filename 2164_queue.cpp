#include<iostream>
#include<queue>
using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  queue<int> q;
  int N;
  cin>>N;
  if(N==1)cout<<1;
  else if(N==2)cout<<2;
  else{
    for(int i=1;i<=N;i++){
      q.push(i);
    }
    while(q.size()>2){
      q.pop();
      int n=q.front();
      q.pop();
      q.push(n);
    }
    if(q.size()==2){
      q.pop();
      cout<<q.front();
    }
    else cout<<q.front();
  }
  return 0;
}
