#include <bits/stdc++.h>
using namespace std;

int a[1001];
int dp[1001][2];
int n, res = 1;

int main(void)
{
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
                dp[i][0] = 1;

                for (int j = 1; j < i; j++) {
                        if (a[i] > a[j]) 
                                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                }
        }

        dp[n][1] = 1;
        for (int i = n - 1; i >= 1; i--) {
                dp[i][1] = 1;

                for (int j = n; j > i; j--) {
                        if (a[i] > a[j])
                                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
                }
        }

        for (int i = 1; i <= n; i++) {
                int sum = dp[i][0] + dp[i][1] - 1;
                res = max(res, sum);
        }

        printf("%d", res);
        return 0;
}