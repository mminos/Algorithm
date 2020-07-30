#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
int a[501][501];
int res = -1;

int main(void) {
        int n;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) 
                        scanf("%d", &a[i][j]);
        }

        dp[0][0] = a[0][0];
        for (int i = 1; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                        if (j == 0) dp[i][j] = dp[i - 1][j] + a[i][j];
                        else if (j == i) dp[i][j] = dp[i - 1][j - 1] + a[i][j];
                        else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
                }
        }
        sort(dp[n - 1], dp[n - 1] + n);
        printf("%d", dp[n - 1][n - 1]);
}