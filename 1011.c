#include<stdio.h>
int main(){
  int tcase;
  long long x,y;
  long long length=0,num=1;
  scanf("%d",&tcase);
  for(int i=0;i<tcase;i++){
    length=0,num=0;
    scanf("%lld %lld",&x,&y);
    length=y-x;
    if(length==0) printf("0\n");
    else if(length==1) printf("1\n");
    else if(length==2) printf("2\n");
    else{
      while(length>num*num)
        num++;
        if(length<=num*num-num)
          printf("%lld\n",2*num-2);
        else
          printf("%lld\n",2*num-1);
    }
  }
  return 0;
}
