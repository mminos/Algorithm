#include<iostream>
using namespace std;

char _star[3][6]={"  *  "," * * ","*****"};
char star_table[4000][8000];
void star(int n, int row, int col){
  if(n==1){
    for(int i=0;i<3;i++){
      for(int j=0;j<5;j++)
        star_table[row+i][col+j]=_star[i][j];
    }
  }
  else{
    star(n/2,row,col+n/2*3);
    star(n/2,row+n/2*3,col);
    star(n/2,row+n/2*3,col+n*3);
  }
}

int main(){
  int N;
  cin>>N;
  star(N/3,0,0);
  for(int i=0;i<N;i++){
    for(int j=0;j<2*N;j++){
      if(star_table[i][j]=='*')cout<<"*";
      else cout<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
