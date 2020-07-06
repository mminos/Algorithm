#include<stdio.h>
int main(){
  int arr[1000]={0};
  char tc[1000][50]={0};
  int num1;
  scanf("%d",&num1);
  for(int k=0;k<num1;k++){
    scanf("%d %s",&arr[k],tc[k]);
  }
  for(int k=0;k<num1;k++){
    int num2=0;
    while(tc[k][num2]!=0){
      for(int i=0;i<arr[k];i++){
        printf("%c",tc[k][num2]);
      }
      num2++;
    }
    printf("\n");
  }
  return 0;
}
