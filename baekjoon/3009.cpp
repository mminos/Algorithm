#include<cstdio>
int main(){
  int arr[1001]={0,};
  int a,b,c,d,e,f;
  scanf("%d %d",&a,&b);
  scanf("%d %d",&c,&d);
  scanf("%d %d",&e,&f);

  arr[a]++;
  arr[c]++;
  arr[e]++;
  for(int i=1;i<1001;i++){
    if(arr[i]==1)printf("%d ",i);
  }
  for(int i=1;i<1001;i++)arr[i]=0;
  arr[b]++;
  arr[d]++;
  arr[f]++;
  for(int i=1;i<1001;i++){
    if(arr[i]==1)printf("%d\n",i);
  }

  return 0;
}
