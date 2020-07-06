#include<stdio.h>
int main(){
  int temp;
  int n=0;
  int m;
  double avr,sum=0;
  int arr[1000]={0};
  double scr[1000]={0};

  scanf("%d",&n);

  for(int k=0;k<n;k++){
    scanf("%d",&arr[k]);
  }

  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
  m=arr[n-1];
  for(int a=0;a<n;a++){
    scr[a]=(double)arr[a]/m*100;
    sum+=scr[a];
  }
  avr=sum/n;
  printf("%.2lf",avr);

  return 0;
}
