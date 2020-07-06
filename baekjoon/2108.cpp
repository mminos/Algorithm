#include<cstdio>
#include<algorithm>

int avg(int arr[],int n);
int mid(int arr[],int n);
int max(int arr[],int n);
int range(int arr[],int n);

using namespace std;

int main(){
  int arr[500000]={0,};
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++)scanf("%d",&arr[i]);
  sort(arr,arr+N);
  printf("%d\n%d\n%d\n%d",avg(arr,N),mid(arr,N),max(arr,N),range(arr,N));
  return 0;
}

int avg(int arr[], int n){
  int sum=0;
  for(int i=0;i<n;i++)sum += arr[i];
  double result = (double)sum/n;
  if(result>0)return (int)(result+0.5);
  else if(result<0)return (int)(result-0.5);
  else return 0;
}
int mid(int arr[], int n){
  int m = n/2+1;
  return arr[m-1];
}
int max(int arr[], int n){
  int counting[8001]={0,};
  int max=0,count=0,temp=0;
  for(int i=0;i<n;i++)
    counting[arr[i]+4000]++;

  for(int i=0;i<8001;i++)
    if(counting[i]>max)max=counting[i];

  for(int i=0;i<8001;i++){
    if(max==counting[i]){
      if(count==0){
        count++;
        temp=i;
      }
      else return i-4000;
    }
  }
  if(count!=0)return temp-4000;
}
int range(int arr[], int n){
  int max=-4000,min=4000;
  for(int i=0;i<n;i++){
    if(arr[i]>=max)max=arr[i];
    if(arr[i]<=min)min=arr[i];
  }
  return max-min;
}
