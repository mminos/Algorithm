#include<stdio.h>
int gcd(int a, int b)
{
	int c;
	while (b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(){
  int num;
  scanf("%d",&num);

  for(int i=0;i<num;i++){
    int M,N,x,y;
    int n1=1,n2=1,count=1,check=0;
    int MAX=lcm(M,N);
    scanf("%d %d %d %d",&M,&N,&x,&y);
    while(1){
      if(x==n1&&y==n2){
        check++;
        break;
      }
      else if(x==n1)n1=1;
      else if(x!=n1)n1++;
      else if(y==n2)n2=1;
      else if(y!=n2)n2++;
      count++;
      if(count>MAX){
        printf("-1\n");
        break;
      }
    }
    if(check)printf("%d\n",count);
  }
  return 0;
}
