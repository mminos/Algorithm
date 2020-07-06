#include<stdio.h>
#include<string.h>
int main(){

  int num1;
  scanf("%d",&num1);
  char arr[100][101]={0};


  for(int i=0;i<num1;i++)
    scanf("%s",arr[i]);
  int check=num1;
  for(int i=0;i<num1;i++){
    int arr2[26]={0};
    for(int k=0;k<strlen(arr[i]);k++){
  
      int snum=arr[i][k]-97;
      if(arr2[snum]==0){
        arr2[snum]++;
        continue;
      }
      else{
        if(arr[i][k]==arr[i][k-1])
          continue;
        else{
          check--;
          break;
        }
      }
    }
  }
  printf("%d",check);
  return 0;
}
