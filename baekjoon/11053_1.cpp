#include <bits/stdc++.h>
using namespace std;

int a[1001];
int dp[1001];
int n, res = 1;

int main(void)
{
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
                scanf("%d", &a[i]);
        
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
                dp[i] = 1;

                for (int j = 1; j < i; j++) {
                        if (a[i] > a[j])
                                dp[i] = max(dp[i], dp[j] + 1);
                }
                res = max(res, dp[i]);
        }
        printf("%d", res);
        return 0;
}