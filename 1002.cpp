#include<cstdio>
#include<cmath>
#include<cstdlib>
int main(){
  int count, x1, x2, y1, y2, r1, r2, dis;
  scanf("%d",&count);
  while(count--){
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    dis = (int)pow(x1-x2,2)+(int)pow(y1-y2,2);
    if(dis==0){
      if(r1==r2)printf("-1\n");
      else printf("0\n");
    }
    else if((int)pow(r1-r2,2)<dis&&dis<(int)pow(r1+r2,2))
      printf("2\n");
    else if((int)pow(r1+r2,2)==dis||(int)pow(r1-r2,2)==dis)
      printf("1\n");
    else if((int)pow(r1+r2,2)<dis||(int)pow(r1-r2,2)>dis)
      printf("0\n");
  }
  return 0;
}
