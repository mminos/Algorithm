#include <bits/stdc++.h>
using namespace std;

int dp[301][2];
int stair[301];
int n;

int main(void) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
                scanf("%d", &stair[i]);
        
        dp[1][0] = dp[1][1] = stair[1];

        for (int i = 2; i <= n; i++) {
                dp[i][0] = dp[i - 1][1] + stair[i];
                dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + stair[i];
        }

        printf("%d", max(dp[n][1], dp[n][0]));
        return 0;
}