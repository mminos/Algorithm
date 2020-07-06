#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int,int>&a,const pair<int,int>&b){
  if(a.second==b.second)return a.first<b.first;
  return a.second<b.second;
}

int main(){
  int N,j,k;
  scanf("%d",&N);
  vector<pair<int,int>> pv;
  for(int i=0;i<N;i++){
    scanf("%d %d",&j,&k);
    pv.push_back(make_pair(j,k));
  }
  sort(pv.begin(),pv.end(),compare);
  for(int i=0;i<N;i++){
    printf("%d %d\n",pv[i].first,pv[i].second);
  }
  return 0;
}
