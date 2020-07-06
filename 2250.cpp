#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 10001
int N,x;
pair<int,int> Tree[MAX];
int node_check[MAX];
vector<int> breadth[MAX];

void dfs(int i,int lev){
  if(Tree[i].first>0)
    dfs(Tree[i].first,lev+1);
  breadth[lev].push_back(++x);
  if(Tree[i].second>0)
    dfs(Tree[i].second,lev+1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>N;
  int nodeNum,left,right;
  for(int i=0;i<N;i++){
    cin>>nodeNum>>left>>right;
    node_check[nodeNum]++;
    if(left!=-1)
      node_check[left]++;
    Tree[nodeNum].first=left;
    if(right!=-1)
      node_check[right]++;
    Tree[nodeNum].second=right;
  }

  int root=0;
  for(int i=0;i<=N;i++)
    if(node_check[i]==1)
      root = i;

  dfs(root,0);
  int max=-1,lev=0;
  for(int i=0;i<N;i++){
    if(breadth[i].empty())continue;
    int tmp=breadth[i].back()-breadth[i].front()+1;
    if(max<tmp){
      lev=i+1;
      max=tmp;
    }
  }
  cout<<lev<<" "<<max;
  return 0;
}
