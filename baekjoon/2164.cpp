#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N,count=0;
  cin>>N;
  while(N>2){
    N/=2;
    count++;
  }
  if(N==2){
    cout<< pow(2,count+1);
  }
  else{
    cout<< pow(2,count);
  }
  return 0;
}
