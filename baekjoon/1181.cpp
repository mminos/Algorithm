#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool Comp(string a, string b){
  if(a.length()!=b.length()){
    return a.length()<b.length();
  }
  else{
    return a<b;
  }
}

int main(){
  string str[20001];
  int num;
  cin>>num;
  cin.ignore();
  for(int i=0;i<num;i++){
    getline(cin,str[i]);
  }
  sort(str,str+num,Comp);
  for(int i=0;i<num;i++){
    if(i>0&&str[i]==str[i-1])continue;
    else cout<<str[i]<<"\n";
  }
  return 0;
}
