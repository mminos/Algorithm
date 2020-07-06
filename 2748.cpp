#include<iostream>
using namespace std;

unsigned long long memo[100];

unsigned long long fibo(int n){
  if(n<2)return n;
  if(memo[n]!=0)
    return memo[n];
  memo[n]=fibo(n-1)+fibo(n-2);
  return memo[n];
}

int main(){
  int N;
  cin>>N;
  unsigned long long fib = fibo(N);
  cout<<fib;
  return 0;
}
