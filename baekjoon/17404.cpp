#include <bits/stdc++.h>
using namespace std;

int dp[1010][3];
int rgb[1010][3];
int n, res = INT_MAX;

int main(void)
{
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
                for (int j = 0; j < 3; j++)
                        scanf("%d", &rgb[i][j]);
                
        for (int idx = 0; idx < 3; idx++) {
                for (int i = 0; i < 3; i++) {
                        if (i == idx) dp[1][i] = rgb[1][i];
                        else dp[1][i] = 2000;
                }

                for (int i = 2; i <= n; i++) {
                        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
                        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
                        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
                }

                for (int i = 0; i < 3; i++) {
                        if (i == idx) continue;
                        else {
                                res = min(res, dp[n][i]);
                        }
                }
        }
        printf("%d", res);
        return 0;
}