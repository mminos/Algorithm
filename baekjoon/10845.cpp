#include<iostream>
#include<cstring>
using namespace std;

int queue[10001];
int size=0,front=0,rear=-1;

void Push(int x){
  queue[++rear]=x;
  size++;
}

int Size(){
  return size;
}

int Empty(){
  if(front>rear)return 1;
  else return 0;
}

int Pop(){
  if(!Empty()){
    size--;
    return queue[front++];
  }
  else return -1;
}

int Front(){
  if(!Empty()){
    return queue[front];
  }
  else return -1;
}

int Back(){
  if(!Empty()){
    return queue[rear];
  }
  else return -1;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  while(n--){
    char str[10]={0,};
    int num;

    cin>>str;

    if(!strcmp(str,"push")){
      cin>>num;
      Push(num);
    }
    else if(!strcmp(str,"pop")){
      cout<<Pop()<<"\n";
    }
    else if(!strcmp(str,"size")){
      cout<<Size()<<"\n";
    }
    else if(!strcmp(str,"empty")){
      cout<<Empty()<<"\n";
    }
    else if(!strcmp(str,"front")){
      cout<<Front()<<"\n";
    }
    else if(!strcmp(str,"back")){
      cout<<Back()<<"\n";
    }
  }
  return 0;
}
