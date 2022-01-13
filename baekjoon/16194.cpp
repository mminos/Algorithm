#include <bits/stdc++.h>
using namespace std;

int P[1001];
int dp[1001];
int N;

int main(void)
{
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
                scanf("%d", &P[i]);
        
        dp[1] = P[1];

        for (int i = 2; i <= N; i++) {
                dp[i] = INT_MAX;
                for (int j = 1; j < i; j++) {
                        int tmp = min(dp[i - j] + P[j], P[i]);
                        dp[i] = min(tmp, dp[i]);
                }
        }

        printf("%d", dp[N]);
        return 0;
}