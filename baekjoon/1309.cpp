#include <bits/stdc++.h>
using namespace std;

int dp[100001][3];
int Div = 9901;
int n;

int main(void)
{
        scanf("%d", &n);
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[1][0] = 1;
        
        for (int i = 2; i <= n; i++) {
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % Div;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % Div;
                dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % Div;
        }
        int res = (dp[n][0] + dp[n][1] + dp[n][2]) % Div;

        printf("%d", res);
        return 0;
}