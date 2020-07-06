#include<stdio.h>

#include<algorithm>
using namespace std;

int bin_search(int* arr,int target,int size){
  int first=0;
  int last=size-1;
  int mid=0;
  while(first<=last){
    mid=(first+last)/2;

    if(target==arr[mid])return 1;

    else{
      if(arr[mid]>target) last=mid-1;
      else first=mid+1;
    }
  }
  return 0;
}

int main(){

  int num;
  scanf("%d",&num);
  int *arr=new int[num];

  for(int i=0;i<num;i++){
    scanf("%d",&arr[i]);
  }

  sort(arr,arr+num);

  int num2;
  scanf("%d",&num2);
  int *arr2= new int[num2];

  for(int i=0;i<num2;i++){
    scanf("%d",&arr2[i]);
  }
  for(int i=0;i<num2;i++){
    int n=bin_search(arr,arr2[i],num);
    printf("%d\n",n);
  }
  return 0;
}
