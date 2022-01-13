#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int N;

int main(void)
{
        scanf("%d", &N);
        
        for (int i = 2; i <= N; i++) {
                dp[i] = dp[i - 1] + 1;

                if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
                if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1); 
        }

        printf("%d", dp[N]);
        return 0;
}