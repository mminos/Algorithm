#include<stdio.h>
int main(){
  int num,a,b;
  scanf("%d",&num);
  for(int k=0;k<num;k++){
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
  }
  return 0;
}
