#include<iostream>
using namespace std;

char quad[64][64];

void divide(int n, int y, int x){
  int check=1;
  char num=quad[y][x];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(num!=quad[y+i][x+j]){
        check=0;
        break;
      }
    }
  }
  if(check==1){
    cout<<num;
    return;
  }
  else{
    cout<<'(';
    divide(n/2,y,x);
    divide(n/2,y,x+n/2);
    divide(n/2,y+n/2,x);
    divide(n/2,y+n/2,x+n/2);
    cout<<')';
  }

}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>quad[i][j];
  divide(N,0,0);
  return 0;
}
