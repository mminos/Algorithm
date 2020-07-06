#include<stdio.h>
int main(){
  int C,N,sum=0,num=0;
  double avr,per;
  int arr[1000];
  scanf("%d",&C);
  for(int k=0;k<C;k++){
    num=0,sum=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&arr[i]);
      sum+=arr[i];
    }
    avr=(double)sum/N;
    for(int i=0;i<N;i++){
      if(arr[i]>avr)
        num++;
    }
    per=(double)num/N*100;
    printf("%.3lf%%\n",per);
  }
  return 0;
}
