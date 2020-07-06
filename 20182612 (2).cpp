#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000001
int prime[MAX];
vector<int> Vprime;
int main(){
  for(int i=0;i<MAX;i++)prime[i]=i;
  for(int i=2;i<MAX;i++){
    if(prime[i]==0)continue;
    for(int j=i+i;j<MAX;j+=i)prime[j]=0;
  }
  for(int i=2;i<MAX;i++){
    if(prime[i]!=0)
      Vprime.push_back(i);
  }

  vector<int> countPrime(Vprime.size(),0);
  vector<int> gcd(Vprime.size(),0);
  int count=0;
  int n;
  cin>>n;
  int* arr = new int[n];
  vector< vector<int> > arrPrime(n,vector<int>(Vprime.size(),0));
  for(int i=0;i<n;i++)cin>>arr[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<Vprime.size();j++){
      while(!(arr[i]%Vprime[j])){
        arrPrime[i][j]++;
        countPrime[j]++;
        arr[i]/=Vprime[j];
        if(arr[i]==1)break;
      }
      if(arr[i]==1)break;
    }
  }
  for(int j=0;j<Vprime.size();j++){
    gcd[j]=countPrime[j]/n;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<Vprime.size();j++){
      if(arrPrime[i][j]<gcd[j]){
        count+=(gcd[j]-arrPrime[i][j]);
      }
    }
  }
  int _gcd = 1;
  for(int j=0;j<Vprime.size();j++){
    if(gcd[j]!=0){
      for(int i=0;i<gcd[j];i++)_gcd*=Vprime[j];
    }
  }
  cout<<_gcd<<" "<<count;
}
