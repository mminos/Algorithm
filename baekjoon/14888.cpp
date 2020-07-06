#include<iostream>
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3
#define MAX 1000000000+1
using namespace std;

int N;
int arr[12];
int cal[4];
int max_min[2]={-MAX,MAX};

void dfs(int i,int sum){
  if(i==N){
    max_min[0]=max(max_min[0],sum);
    max_min[1]=min(max_min[1],sum);
    return;
  }
  if(cal[PLUS]){
    cal[PLUS]--;
    dfs(i+1,sum+arr[i]);
    cal[PLUS]++;
  }
  if(cal[MINUS]){
    cal[MINUS]--;
    dfs(i+1,sum-arr[i]);
    cal[MINUS]++;
  }if(cal[MUL]){
    cal[MUL]--;
    dfs(i+1,sum*arr[i]);
    cal[MUL]++;
  }if(cal[DIV]){
    cal[DIV]--;
    dfs(i+1,sum/arr[i]);
    cal[DIV]++;
  }
}

int main(){
  int sum=0;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>arr[i];
  for(int i=0;i<4;i++)
    cin>>cal[i];
  sum=arr[0];
  dfs(1,sum);
  cout<<max_min[0]<<"\n"<<max_min[1];
  return 0;
}
