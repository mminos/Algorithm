#include<stdio.h>
#include<string.h>
int main(){
  char word[1000000]={0};
  int alph[26]={0};
  int alph2[26]={0};
  int temp;
  int num=0;
  scanf("%s",word);
  num=strlen(word);
  for(int i=0;i<num;i++){
    if(word[i]<='Z')
      alph[word[i]-65]++;
    else
      alph[word[i]-97]++;
  }
  for(int i=0;i<26;i++){
    alph2[i]=alph[i];
  }
  for(int i=25;i>=0;i--){
    for(int k=0;k<i;k++){
      if(alph[k]<=alph[k+1])
      {
        temp=alph[k+1];
        alph[k+1]=alph[k];
        alph[k]=temp;
      }
    }
  }
  if(alph[0]==alph[1])
    printf("?");
  else
  {
    for(int i=0;i<26;i++){
      if(alph2[i]==alph[0])
      {
        printf("%c",i+65);
      }
    }
  }

  return 0;
}
