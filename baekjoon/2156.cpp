#include <bits/stdc++.h>
using namespace std;

int N, dp[10001], wine[10001];

int main(void) {
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) scanf("%d", &wine[i]);
        dp[1] = wine[1];
        dp[2] = wine[1] + wine[2];

        for (int i = 3; i <= N; i++) {
                dp[i] = wine[i] + max(dp[i - 2], wine[i - 1] + dp[i - 3]);
                dp[i] = max(dp[i], dp[i - 1]);
        }

        printf("%d", dp[N]);
}