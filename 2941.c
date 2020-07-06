#include<stdio.h>
int main(){
  char ary[101]={0};
  scanf("%s",ary);
  int i=0,count=0;
  while(ary[i]!='\0'){
    switch(ary[i]){
      case 'c':
        if(ary[i+1]=='='){
          count++; i+=2; break;
        }
        else if(ary[i+1]=='-'){
          count++; i+=2; break;
        }
        else{
          count++; i++; break;
        }
      case 'd':
        if(ary[i+1]=='z'&&ary[i+2]=='='){
          count++; i+=3; break;
        }
        else if(ary[i+1]=='-'){
          count++; i+=2; break;
        }
        else{
          count++; i++; break;
        }
      case 'l':
        if(ary[i+1]=='j'){
          count++; i+=2; break;
        }
        else{
          count++; i++; break;
        }
      case 'n':
        if(ary[i+1]=='j'){
          count++; i+=2; break;
        }
        else{
          count++; i++; break;
        }
      case 's':
        if(ary[i+1]=='='){
          count++; i+=2; break;
        }
        else{
          count++; i++; break;
        }
      case 'z':
        if(ary[i+1]=='='){
          count++; i+=2; break;
        }
        else{
          count++; i++; break;
        }
      default : count++;i++;break;
    }
  }
  printf("%d",count);
  return 0;
}
