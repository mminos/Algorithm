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
    scanf("%d %d %d %d",&M,&N,&x,&y);
		int MAX=lcm(M,N);

    while(1){
      if(x==n1&&y==n2){
        check++;
        break;
      }

      if(M==n1)n1=1;
      else n1++;

      if(N==n2)n2=1;
      else n2++;

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
