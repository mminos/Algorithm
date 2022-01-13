#include <bits/stdc++.h>
using namespace std;

int square[1000];
int dp[100001];
int idx, n;

int main(void)
{
        scanf("%d", &n);

        for (int i = 1; i * i < 100000; i++)
                square[idx++] = i * i;

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
                dp[i] = INT_MAX;
                for (int j = 0; i >= square[j]; j++) {
                        dp[i] = min(dp[i], dp[i - square[j]] + 1);
                } 
        }

        printf("%d", dp[n]);
        return 0;
}