#include<cstdio>

int main(){
  int num;
  scanf("%d",&num);

  for(int i=0;i<num;i++){
    char arr[51];
    scanf("%s",arr);
    int n=0;
    int num1=0, num2=0, check=0;
    while(arr[n]!='\0'){

      if(arr[n]=='(') num1++;
      else if(arr[n]==')') num2++;

      if(num1<num2){
        check++;
        break;
      }
      n++;
    }
    if(check!=0) printf("NO\n");
    else if(num1!=num2) printf("NO\n");
    else printf("YES\n");
  }
  return 0;
}
