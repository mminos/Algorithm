#include<stdio.h>
int main(){
  char arr[100];
  char arr2[26]={0};
  int k=97;

  for(int i=0;i<26;i++){
    arr2[i]=k;
    k++;
  }
  scanf("%s",arr);
  for(int i=0;i<26;i++){
    int num=0;
    while(1)
    {
      if(arr[num]==arr2[i]){
        printf("%d ",num);
        break;
      }
      else{
        num++;
      }
      if(arr[num]==0)
      {
        printf("-1 ");
        break;
      }
    }
  }
  return 0;
}
