#include<stdio.h>
int main(){
  int comp,num1=1,num2=1,num3,num4=1;
  scanf("%d",&comp);
  while(1){
    if(comp>num1){
      num2++;
      num1+=num2;
    }
    else
      break;
  }
  num1-=num2;
  num1++;
  num3=num2;

  for(num1;num1<comp;num1++){
    num4++;
    num3--;
  }
  if(num2%2==0)
    printf("%d/%d",num4,num3);
  else
    printf("%d/%d",num3,num4);
  return 0;
}
