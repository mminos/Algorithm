#include<stdio.h>
#define PI 3.141592653589793238462643383279502884197169399375105820974944
int main(){
  int n;
  double u,t;
  scanf("%d",&n);
  u=n*n*PI;
  t=(double)n*n*2;
  printf("%.6f\n%.6f",u,t);
  return 0;
}
