#include<stdio.h>
int main(){
  int testcase;
  scanf("%d",&testcase);

  for(int i=0;i<testcase;i++){
      int a=0,b=0,num=0,a1=0,b1=0;
      scanf("%d %d %d",&a,&b,&num);

      if(num%a==0){
        a1=a;
        b1=num/a;
      }
      else{
      a1=num%a;
      b1=num/a+1;
    }
      printf("%d%02d\n",a1,b1);
      }
  return 0;
}
