#include<stdio.h>
int main(){
  int x,y,sum=0,sum2=0,num;
  int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  char day[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
  scanf("%d %d",&x,&y);
  for(int k=0;k<x;k++)
    sum+=month[k];
  sum2=sum+y;
  num=sum2%7;
  switch (num){
    case 0 : printf("%s",day[0]); break;
    case 1 : printf("%s",day[1]); break;
    case 2 : printf("%s",day[2]); break;
    case 3 : printf("%s",day[3]); break;
    case 4 : printf("%s",day[4]); break;
    case 5 : printf("%s",day[5]); break;
    case 6 : printf("%s",day[6]); break;
  }
  return 0;
}
