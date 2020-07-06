#include<stdio.h>
int main(){
  int num_a=0,num_d=0,k=0;
  int arr[8]={0};
  for(int i=0;i<8;i++)
    scanf("%d",&arr[i]);

  for(k;k<8;k++){
    if(arr[k+1]-arr[k]==1)
      num_a++;
    else if(arr[k+1]-arr[k]==-1)
      num_d++;
    else
      break;
  }

  if(num_a==7)
    printf("ascending");
  else if(num_d==7)
    printf("descending");
  else
    printf("mixed");
  return 0;
}
