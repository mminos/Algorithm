#include<stack>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(true){
    bool balance=true;
    string str;
    getline(cin,str);
    stack<char> s;
    if(str.length()==1&&str[0]=='.')break;

    for(int i=0;i<str.length();i++){
      if(str[i]=='(')s.push(str[i]);
      else if(str[i]=='[')s.push(str[i]);
      else if(str[i]==')'){
        if(!s.empty()&&s.top()=='(')s.pop();
        else{
          balance=false;
          break;
        }
      }
      else if(str[i]==']'){
        if(!s.empty()&&s.top()=='[')s.pop();
        else{
          balance=false;
          break;
        }
      }
    }
    if(s.empty()&&balance==true)printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
