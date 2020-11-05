#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int price[1001];
int N, res;

int main(void) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d", &price[i]);

        dp[1] = price[1];

        for (int n = 2; n <= N; n++) {
                res = 0;
                for (int i = 1; i <= n; i++) {
                        res = max(res, dp[n - i] + price[i]);
                }
                dp[n] = res;
        }

        printf("%d", dp[N]);
        return 0;
}