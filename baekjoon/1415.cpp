#include<cstdio>

int N;
bool prime[500001];
int price[50];
int priceCnt[100001];
long long dp[500001], zeroCnt, sum;

void getPrime(void) {      //에라토스테네스의 채
   for (int i = 2; i <= 500000; i++)
      prime[i] = 1;
   for (int i = 2; i * i <= 500000; i++)
      if (prime[i])
         for (int j = i * i; j <= 500000; j += i)
            prime[j] = 0;
}

void algo(int idx) {
   for (int i = 0; i < idx; i++) {
      int cur = price[i];
      for (int j = 500000; j >= 0; j--) {
         for (int k = 1; k <= priceCnt[cur]; k++) {
            if (j - cur * k < 0)break;
            dp[j] += dp[j - cur * k];
         }
      }
   }
   for (int i = 2; i <= 500000; i++)
      if (prime[i])
         sum += dp[i];
   printf("%lld\n", sum * (zeroCnt + 1)); //가격 0의 경우 가격에는 영향을 미치지 않지만 사탕의 종류에는 영향을 주므로,
   return;                                //0의 개수 +1 만큼 곱해줘야함
}

int main(void) {
   int idx = 0;
   getPrime();

   scanf("%d", &N);
   for (int i = 0; i < N; i++) { //같은 금액은 같은 종류로 간주하므로 합쳐줌
      int n;
      scanf("%d", &n);
      if (n == 0) {              //가격이 0원일때 가격에 영향을 주지 못하고 사탕의 종류(경우의 수)에 영향을 주므로 개수 카운트만 하고 빼놓음
         zeroCnt++;
         continue;
      }
      if (priceCnt[n] == 0)
         price[idx++] = n;
      priceCnt[n]++;
   }
   dp[0] = 1;                    //아무것도 사지 않았을때 1회
   algo(idx);                    //순회를 통해 만들수 있는 가격의 수를 차곡차곡 dp에 쌓기
   return 0;
}
