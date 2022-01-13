#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int T, n;
int Div = 1000000009;

int main(void)
{
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= 1000000; i++)
                for (int j = 1; j <= 3; j++) {
                        dp[i] += dp[i - j];
                        dp[i] = dp[i] % Div;
                }
        
        scanf("%d", &T);
        
        while (T--) {
                scanf("%d", &n);
                printf("%d\n", dp[n] % Div);
        }
        return 0;
}