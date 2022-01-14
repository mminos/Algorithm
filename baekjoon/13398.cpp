#include <bits/stdc++.h>
using namespace std;

int arr[100001];
int dp[100001][2];
int n, res;

int main(void)
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        dp[0][0] = arr[0];
        dp[0][1] = 0;
        res = dp[0][0];

        for (int i = 1; i < n; i++) {
                dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
                dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
                res = max(res, max(dp[i][0], dp[i][1]));
        }

        printf("%d", res);
        return 0;
}