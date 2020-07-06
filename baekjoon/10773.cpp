#include<cstdio>
#include<cstring>
using namespace std;

int stack[100001], top=-1;

void push(int x){
  stack[++top]=x;
}
bool isEmpty(){
  if(top==-1)return true;
  else return false;
}
int pop(){
  if(!isEmpty())return stack[top--];
}

int main(){
  int K,sum=0;
  scanf("%d",&K);
  while(K--){
    int n;
    scanf("%d",&n);
    if(n==0){
      if(!isEmpty()) pop();
    }
    else push(n);
  }
  while(!isEmpty()){
    sum+=pop();
  }
  printf("%d\n",sum);
  return 0;
}
