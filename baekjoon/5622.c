#include<stdio.h>
int main(){
  char arr[8][5]={"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
  int total=0;
  char ary[16]={0};

  scanf("%s",ary);
  int i=0;
  while(ary[i]!=NULL){
    int find=0;
    for(int k=0;k<8;k++){

      for(int j=0;arr[k][j]!=NULL;j++){
        if(ary[i]==arr[k][j]){
          find++;
          total+=(k+3);
          break;
        }
      }
      if(find>0)
        break;
    }
    i++;
  }
  printf("%d",total);
  return 0;
}
