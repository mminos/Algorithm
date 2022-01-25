#include <bits/stdc++.h>
using namespace std;

int arr[2][100001];
int dp[2][100001];
int t, n;

int main(void) {
        scanf("%d", &t);

        while (t--) {
                scanf("%d", &n);
                memset(dp, 0, sizeof(dp));
                
                for (int i = 0; i < 2; i++)
                        for (int j = 0; j < n; j++)
                                scanf("%d", &arr[i][j]);
                
                if (n == 1) {
                        printf("%d\n", max(arr[0][0], arr[1][0]));
                        continue;
                }

                dp[0][0] = arr[0][0];
                dp[1][0] = arr[1][0];
                dp[0][1] = dp[1][0] + arr[0][1];
                dp[1][1] = dp[0][0] + arr[1][1];

                for (int i = 2; i < n; i++) {
                        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
                        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
                }

                sort(dp[0], dp[0] + n);
                sort(dp[1], dp[1] + n);

                printf("%d\n", max(dp[0][n - 1], dp[1][n - 1]));
        }

        return 0;
}