#include<cstdio>

int N;
bool prime[500001];
int price[50];
int priceCnt[100001];
long long dp[500001], zeroCnt, sum;

void getPrime(void) {      //�����佺�׳׽��� ä
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
   printf("%lld\n", sum * (zeroCnt + 1)); //���� 0�� ��� ���ݿ��� ������ ��ġ�� ������ ������ �������� ������ �ֹǷ�,
   return;                                //0�� ���� +1 ��ŭ ���������
}

int main(void) {
   int idx = 0;
   getPrime();

   scanf("%d", &N);
   for (int i = 0; i < N; i++) { //���� �ݾ��� ���� ������ �����ϹǷ� ������
      int n;
      scanf("%d", &n);
      if (n == 0) {              //������ 0���϶� ���ݿ� ������ ���� ���ϰ� ������ ����(����� ��)�� ������ �ֹǷ� ���� ī��Ʈ�� �ϰ� ������
         zeroCnt++;
         continue;
      }
      if (priceCnt[n] == 0)
         price[idx++] = n;
      priceCnt[n]++;
   }
   dp[0] = 1;                    //�ƹ��͵� ���� �ʾ����� 1ȸ
   algo(idx);                    //��ȸ�� ���� ����� �ִ� ������ ���� �������� dp�� �ױ�
   return 0;
}
