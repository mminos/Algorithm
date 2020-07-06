#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N;

bool Comp(pair<int,string> a, pair<int, string> b){
  if(a.first<b.first)return true;

  else if (a.first==b.first)return false;
  return false;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin>>N;
  vector<pair<int,string>> v;
  v.resize(N);
  for(int i=0;i<N;i++)
    cin>>v[i].first>>v[i].second;
  stable_sort(v.begin(),v.end(),Comp);
  for(int i=0;i<N;i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
  return 0;
}
