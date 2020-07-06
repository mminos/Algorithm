#include<stdio.h>
#include<string.h>

int main(){
  int num=0;
  char word[101]={0};
  scanf("%s",word);
  num=strlen(word);
  for(int k=0;k<num;k++){
    if (k%10==9)
      printf("%c\n",word[k]);
    else
      printf("%c",word[k]);
  }

  return 0;
}
