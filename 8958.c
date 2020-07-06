#include<stdio.h>
int main(){
  char arr[100]={0};
  int num,scr=0,sum=0,bonus=1;
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    sum=0;
    scanf("%s",arr);
    for(int k=0;arr[k]!='\0';k++){
      if(arr[k]=='O')
      {
        scr=0;
        for(bonus=1,k;arr[k]=='O';k++)
        {
          scr+=bonus;
          bonus++;
        }
        sum+=scr;
      }
      else;
    }
    printf("%d\n",sum);
    for(int k=0;arr[k]!='\0';k++)
      arr[k]='\0';
  }
  return 0;
}
