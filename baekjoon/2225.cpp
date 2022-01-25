#include <bits/stdc++.h>
using namespace std;

long long dp[201][201];
int N, K;

int main(void)
{
        scanf("%d %d", &N, &K);
        
        for (int i = 0; i <= N; i++)
                dp[1][i] = 1;
        
        for (int i = 2; i <= K; i++) {
                for (int j = 0; j <= N; j++) {
                        for (int k = 0; k <= j; k++) {
                                dp[i][j] += dp[i - 1][k];
                                dp[i][j] %= 1000000000;
                        }
                }
        }

        printf("%lld", dp[K][N]);
}